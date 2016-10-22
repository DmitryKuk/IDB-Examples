// Author: Dmitry Kukovinets (d1021976@gmail.com), 22.10.2016, 21:18

#ifndef PATH_TO_MY_TEMPLATE_CLASS_HPP
#define PATH_TO_MY_TEMPLATE_CLASS_HPP

// Заголовочные файлы, необходимые только для объявлений!
#include <iostream>
#include <vector>


namespace ns1 {
namespace ns2 {


// Template class => _impl.hpp
template<class T1, class T2>
class my_template_class
{
public:
	static void static_f1();
	
	template<class T>
	static void static_f3();
	
	
	
	void f1();
	
	template<class... Ts>
	void f3(Ts &&... args);
};	// class my_template_class


};	// namespace ns2
};	// namespace ns1


#include "my_template_class_impl.hpp"

#endif	// PATH_TO_MY_TEMPLATE_CLASS_HPP
