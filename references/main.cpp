// Dmitry Kukovinets <d1021976@gmail.com>, 11.10.2016, 19:24

#include <iostream>
#include <string>
#include <utility>	// std::move, std::forward

#include "helper_macros.hpp"


void print(std::string & /* str */)
{
	std::cout << "Got lvalue." << std::endl;
}


// void print(const std::string & /* str */)
// {
// 	std::cout << "Got const lvalue." << std::endl;
// }


void print(std::string && /* str */)
{
	std::cout << "Got rvalue." << std::endl;
}


// void print(const std::string && /* str */)
// {
// 	std::cout << "Got const rvalue." << std::endl;
// }



template<class T>
void without_forward(T &&str)	// Bad!
{
	print(str);					// str given as lvalue to print()
}


template<class T>
void stupid_move(T &&str)		// Bad!
{
	print(std::move(str));		// Troubles with const lvalues (can not cast to rvalue)!
}


template<class T>
void with_forward(T &&str)		// Correct forwarding!
{
	print(std::forward<T>(str));
}



int main()
{
	std::string str = "hello";
	
	
	std::cout << std::endl << "Print directly:" << std::endl;
	PRINT(print(str));
	PRINT(print(std::move(str)));
	
	
	std::cout << std::endl << "Print forwarded:" << std::endl;
	PRINT(print(std::forward<std::string>(str)));
	PRINT(print(std::forward<std::string &>(str)));
	PRINT(print(std::forward<std::string &&>(str)));
	
	
	std::cout << std::endl << "Print moved and forwarded:" << std::endl;
	PRINT(print(std::forward<std::string>(std::move(str))));
	PRINT(print(std::forward<std::string &&>(std::move(str))));
	// PRINT(print(std::forward<std::string &>(std::move(str))));	// Error: Can not forward an rvalue as an lvalue.
	
	
	std::cout << std::endl << "[Bad] Version without forward:" << std::endl;
	PRINT(without_forward(str));
	PRINT(without_forward(std::move(str)));
	
	
	std::cout << std::endl << "[Bad] Version with move instead of forward:" << std::endl;
	PRINT(stupid_move(str));
	PRINT(stupid_move(std::move(str)));
	
	// {
	// 	const std::string const_str = "hello!";
		
	// 	// Error, if print() has not 'const std::strint &' or 'const std::string &&' overloads!
	// 	PRINT(stupid_move(const_str));
	// }
	
	
	std::cout << std::endl << "[Correct] Version with forward:" << std::endl;
	PRINT(with_forward(str));
	PRINT(with_forward(std::move(str)));
	
	
	return 1;	// 1 => test failed
}
