// Author: Dmitry Kukovinets (d1021976@gmail.com), 22.10.2016, 21:18

#ifndef PATH_TO_MY_FUNCS_HPP
#define PATH_TO_MY_FUNCS_HPP

// Заголовочные файлы, необходимые только для объявлений!
#include <iostream>
#include <vector>


namespace ns1 {
namespace ns2 {


// Non-inline/constexpr/template => .cpp
void f1();

// Constexpr (=> inline) => _impl.hpp
constexpr void f2();

// Template => _impl.hpp
template<class... Ts>
void f3(Ts &&... args);


};	// namespace ns2
};	// namespace ns1


#include "my_funcs_impl.hpp"

#endif	// PATH_TO_MY_FUNCS_HPP
