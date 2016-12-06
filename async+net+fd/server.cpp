// Dmitry Kukovinets <d1021976@gmail.com>, 06.12.2016, 16:27

#include <iostream>
#include <vector>
#include <cstring>
#include <cerrno>
#include <cstdint>

#include <unistd.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/types.h>
#include <netdb.h>
#include <fcntl.h>



int
main()
{
	// Create socket
	int accept_socket = socket(PF_INET, SOCK_STREAM, getprotobyname("tcp")->p_proto);
	if (accept_socket < 0) {
		std::clog << "Can't create accept_socket." << std::endl;
		return 1;
	}
	
	
	// Bind socket to IP
	{
		struct sockaddr_in addr;
		std::memset(&addr, 0, sizeof(addr));
		addr.sin_family      = AF_INET;
		addr.sin_port        = htons(8080);
		addr.sin_addr.s_addr = htonl(INADDR_ANY);
		
		if (bind(accept_socket, (const struct sockaddr *)&addr, sizeof(addr)) < 0) {
			std::clog << "Can't bind accept_socket to the address: " << std::strerror(errno) << '.' << std::endl;
			close(accept_socket);
			return 1;
		}
	}
	
	
	// Start listening
	if (listen(accept_socket, 128) < 0) {	// 128 -- client queue size
		std::clog << "Can't listen to accept_socket: " << std::strerror(errno) << '.' << std::endl;
		close(accept_socket);
		return 1;
	}
	
	
	// Server work...
	std::vector<int> clients;	// Clients' sockets' fds
	const auto close_all =
		[&]
		{
			close(accept_socket);
			for (const auto s: clients)
				close(s);
		};
	
	int max_fd = 0;
	fd_set read_set, error_set;
	
	
	while (true) {
		// Add all sockets to sets
		{
			FD_ZERO(&read_set);
			FD_ZERO(&error_set);
			
			FD_SET(0, &read_set);
			FD_SET(0, &error_set);
			max_fd = 0;
			
			FD_SET(accept_socket, &read_set);
			FD_SET(accept_socket, &error_set);
			max_fd = std::max(max_fd, accept_socket);
			
			for (const auto client: clients) {
				FD_SET(client, &read_set);
				FD_SET(client, &error_set);
				max_fd = std::max(max_fd, client);
			}
			
			++max_fd;
		}
		// Add all sockets to sets
		
		
		
		// Waiting for events on sockets
		//                                            write_set            timeout
		int sockets_count = select(max_fd, &read_set, nullptr, &error_set, nullptr);
		if (sockets_count < 0) {
			std::clog << "select() error: " << std::strerror(errno) << '.' << std::endl;
			close_all();
			return 1;
		}
		std::clog << "Selected: " << sockets_count << "..." << std::endl;
		
		
		
		// Any action on std::cin => stop
		if (FD_ISSET(0, &read_set) || FD_ISSET(0, &error_set)) {
			std::clog << "Shutting down..." << std::endl;
			close_all();
			return 0;
		}
		
		
		
		// accept_socket
		{
			// Errors
			if (FD_ISSET(accept_socket, &error_set)) {
				std::clog << "Error on accept_socket: " << std::strerror(errno) << '.' << std::endl;
				close_all();
				return 1;
			}
			
			
			// New client
			if (FD_ISSET(accept_socket, &read_set)) {
				int new_client = accept(accept_socket, nullptr, nullptr);
				if (new_client < 0)
					std::clog << "Can't accept new client: " << std::strerror(errno) << '.' << std::endl;
				else {
					fcntl(new_client, F_SETFL, O_NONBLOCK);
					clients.push_back(new_client);
					std::clog << "Accepted new client." << std::endl;
				}
			}
		}
		// accept_socket
		
		
		
		// Clients
		{
			std::vector<std::vector<int>::iterator> clients_to_erase;
			
			for (auto client_it = clients.begin(); client_it < clients.end(); ++client_it) {
				if (FD_ISSET(*client_it, &error_set)) {			// Errors
					std::clog << "Error with client: " << std::strerror(errno) << '.' << std::endl;
					close(*client_it);
					clients_to_erase.push_back(client_it);
				} else if (FD_ISSET(*client_it, &read_set)) {	// Something recieved...
					char message_buf[10];
					
					while (true) {
						ssize_t read_status = read(*client_it, &message_buf, sizeof(message_buf));
						
						if (read_status > 0) {
							std::cout.write(message_buf, read_status);
							if (read_status < sizeof(message_buf))
								break;
						} else {
							if (read_status < 0)
								std::clog << "Reading error: " << std::strerror(errno) << '.' << std::endl;
							else
								std::clog << "Close..." << std::endl;
							close(*client_it);
							clients_to_erase.push_back(client_it);
							break;
						}
					}
				}
			}
			
			// Cleanup
			for (const auto client_it: clients_to_erase)
				clients.erase(client_it);
		}
		// Clients
	}
	
	
	return 0;
}
