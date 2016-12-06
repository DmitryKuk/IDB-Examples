// Dmitry Kukovinets <d1021976@gmail.com>, 06.12.2016, 20:00

#include <iostream>

#include <boost/asio.hpp>



int
main(int argc, char **argv)
{
	using namespace boost::asio;
	
	
	ip::tcp::endpoint remote_endpoint{ip::address_v4::from_string("127.0.0.1"), 8080};
	ip::tcp::iostream stream{remote_endpoint};
	
	if (!stream) {
		std::cerr << stream.error().message() << std::endl;
		return 1;
	}
	
	stream << "hello, man!" << std::endl;
	for (int i = 1; i < argc; ++i)
		stream << ' ' << argv[i];
	stream << std::endl;
	stream.flush();
	
	return 0;
}
