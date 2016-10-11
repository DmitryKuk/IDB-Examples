// Dmitry Kukovinets <d1021976@gmail.com>, 11.10.2016, 19:24

#ifndef HELPER_MACROS_HPP
#define HELPER_MACROS_HPP

#include <iostream>
#include <iomanip>


#define PRINT(x)							\
	do {									\
		std::cout							\
			<< "    "						\
			<< std::setw(55) << std::left	\
			<< #x << "  =>  ";				\
		x;									\
	} while (0);


#endif	// HELPER_MACROS_HPP
