// Author: Dmitry Kukovinets (d1021976@gmail.com), 22.10.2016, 21:18

// Дополнительные заголовочные файлы, нужные для функций/классов/... ниже
#include <list>
#include <boost/asio.hpp>


// Вариант 1: NAMESPACES::CLASS_NAME::FUNCTION_NAME

// Constexpr (=> inline) => _impl.hpp
constexpr
void
f2()
{
	// ...
}



// Вариант 2: CLASS_NAME::FUNCTION_NAME in NAMESPACES

namespace ns1 {
namespace ns2 {


// Анонимные пространства имён в заголовочных файлах не так уж анонимны!
namespace my_class_impl {


// Вспомотаельные функции классы, нужные только в этом файле (только inline/constexpr/template!!!)
inline
void
helper_f()
{
	// ...
}


};	// namespace my_class_impl



// Template => _impl.hpp
template<class... Ts>
void
f3(Ts &&... args)
{
	// ...
}


};	// namespace ns2
};	// namespace ns1
