// Dmitry Kukovinets <d1021976@gmail.com>, 06.12.2016, 20:00

#include <iostream>
#include <thread>
#include <mutex>
#include <functional>
#include <memory>
#include <utility>
#include <cstring>

#include <boost/asio.hpp>
using namespace boost::asio;


std::mutex cout_mutex;



void
do_work(io_service &service)
{
	io_service::work work{service};
	
	service.run();
}



void
start_async_receive(std::shared_ptr<std::pair<ip::tcp::socket, std::vector<char>>> socket_buf_ptr);


void
on_received(
	const boost::system::error_code &error,
	size_t bytes_transferred,
	std::shared_ptr<std::pair<ip::tcp::socket, std::vector<char>>> socket_buf_ptr
)
{
	if (error) {
		std::lock_guard<std::mutex> l{cout_mutex};
		std::cout << "Recieve failed: " << error.message() << '.' << std::endl;
		return;
	}
	
	// Print received block
	{
		std::lock_guard<std::mutex> l{cout_mutex};
		std::cout.write(socket_buf_ptr->second.data(), bytes_transferred);
	}
	
	// Start next receive operation
	start_async_receive(socket_buf_ptr);
}


void
start_async_receive(std::shared_ptr<std::pair<ip::tcp::socket, std::vector<char>>> socket_buf_ptr)
{
	using namespace std::placeholders;
	socket_buf_ptr->first.async_receive(
		buffer(socket_buf_ptr->second),	// Save data to current buffer
		std::bind(on_received, _1, _2, socket_buf_ptr)
	);
}



void
start_async_accept(std::shared_ptr<ip::tcp::acceptor> acceptor_ptr);


void
on_accepted(
	const boost::system::error_code &error,
	std::shared_ptr<std::pair<ip::tcp::socket, std::vector<char>>> socket_buf_ptr,
	std::shared_ptr<ip::tcp::acceptor> acceptor_ptr
)
{
	if (error) {
		std::lock_guard<std::mutex> l{cout_mutex};
		std::cout << "Accept failed: " << error.message() << '.' << std::endl;
		return;
	}
	
	
	{
		std::lock_guard<std::mutex> l{cout_mutex};
		std::cout
			<< "Accepted client: " << socket_buf_ptr->first.remote_endpoint()
			<< " in thread: " << std::this_thread::get_id() << std::endl;
	}
	
	
	socket_buf_ptr->second.resize(1024);	// Prepare 1 KB buffer
	start_async_receive(socket_buf_ptr);	// Start first receive operation
	
	start_async_accept(acceptor_ptr);
}


void
start_async_accept(std::shared_ptr<ip::tcp::acceptor> acceptor_ptr)
{
	auto socket_buf_ptr =
		std::make_shared<std::pair<ip::tcp::socket, std::vector<char>>>(
			ip::tcp::socket{acceptor_ptr->get_io_service()},
			std::vector<char>()
		);
	
	using namespace std::placeholders;
	acceptor_ptr->async_accept(
		socket_buf_ptr->first,	// Accept to current socket
		std::bind(on_accepted, _1, socket_buf_ptr, acceptor_ptr)
	);
}



int
main()
{
	io_service service;
	std::vector<std::thread> workers;
	
	for (unsigned int i = 0; i < 4; ++i)
		workers.emplace_back(do_work, std::ref(service));
	
	
	// Start accept
	{
		ip::tcp::endpoint local_endpoint{ip::address_v4::from_string("127.0.0.1"), 8080};
		auto acceptor_ptr = std::make_shared<ip::tcp::acceptor>(service, local_endpoint);
		start_async_accept(acceptor_ptr);
	}
	
	
	// Wait for any key...
	std::cin.get();
	
	
	// Join all workers
	service.stop();
	for (auto &worker_thread: workers)
		worker_thread.join();
	
	return 0;
}
