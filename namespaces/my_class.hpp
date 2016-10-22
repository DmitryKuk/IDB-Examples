// Author: Dmitry Kukovinets (d1021976@gmail.com), 22.10.2016, 21:18

#ifndef PATH_TO_MY_CLASS_HPP
#define PATH_TO_MY_CLASS_HPP

// Заголовочные файлы, необходимые только для объявлений!
#include <iostream>
#include <vector>


namespace ns1 {
namespace ns2 {


class my_class
{
public:
	// Static, non-inline/constexpr/template => .cpp
	static void static_f1();
	
	// Static, inline => _impl.hpp
	static inline void static_f2();
	
	// Static, template => _impl.hpp
	template<class T>
	static void static_f3();
	
	
	
	// Non-inline/constexpr/template => .cpp
	void f1();
	
	// Constexpr (=> inline) => _impl.hpp
	constexpr void f2();
	
	// Template => _impl.hpp
	template<class... Ts>
	void f3(Ts &&... args);
};	// class my_class


};	// namespace ns2
};	// namespace ns1


#include "my_class_impl.hpp"

#endif	// PATH_TO_MY_CLASS_HPP
