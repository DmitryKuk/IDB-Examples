// Author: Dmitry Kukovinets (d1021976@gmail.com), 23.10.2016, 21:52

#include <iostream>

// Чудо! Подключение заголовочного файла из net!
#include <get.hpp>


int
main()
{
	net::loaded l;
	
	std::cout << "It works! Status: " << l.status() << std::endl;
	
	return 0;
}
