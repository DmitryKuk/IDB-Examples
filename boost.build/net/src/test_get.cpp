// Author: Dmitry Kukovinets (d1021976@gmail.com), 23.10.2016, 21:52

#include <iostream>

#include "get.hpp"


int
main()
{
	auto l = net::get("http://google.com/");
	
	if (l.status() == 200) {
		return 0;
	} else {
		std::cout << "Get error!" << std::endl;
		return 1;
	}
}
