// Dmitry Kukovinets <d1021976@gmail.com>, 06.12.2016, 20:00

#include <iostream>
#include <cstring>

#include <boost/asio.hpp>


int
main(int argc, char **argv)
{
	using namespace boost::asio;
	
	
	io_service service;
	
	ip::tcp::endpoint endpoint{ip::address_v4::from_string("127.0.0.1"), 8080};
	ip::tcp::socket socket{service};
	socket.connect(endpoint);
	
	
	for (int i = 1; i < argc; ++i) {
		char space = ' ';
		socket.send(buffer(&space, sizeof(space)));
		
		socket.send(buffer(argv[i], std::strlen(argv[i])));
	}
	
	char newline = '\n';
	socket.send(buffer(&newline, sizeof(newline)));
	
	
	// socket.shutdown(ip::tcp::socket::shutdown_both);
	// socket.close();
	
	return 0;
}
