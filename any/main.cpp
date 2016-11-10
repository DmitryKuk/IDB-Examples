// Dmitry Kukovinets <d1021976@gmail.com>, 10.11.2016, 21:06

#include <iostream>
#include <string>

#include "any.hpp"


int main()
{
	any a;
	std::cout << a << std::endl;
	
	a = 5;
	std::cout << a << std::endl;
	
	a = 5.0;
	std::cout << a << std::endl;
	
	a = "hello";
	std::cout << a << std::endl;
	
	a = std::string{"hello"};
	std::cout << a << std::endl;
	
	auto &str = any_cast<std::string>(a);
	std::cout << "Got: " << str << std::endl;
	str = "FFFFFUUUUUU";
	std::cout << a << std::endl;
	
	try {
		std::cout << any_cast<int>(a) << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}
