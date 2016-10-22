// Author: Dmitry Kukovinets (d1021976@gmail.com), 22.10.2016, 21:18

// Дополнительные заголовочные файлы, нужные для функций/классов/... ниже
#include <list>
#include <boost/asio.hpp>


// Вариант 1: NAMESPACES::CLASS_NAME::FUNCTION_NAME

// Static, inline => _impl.hpp
// static
inline
void
ns1::ns2::my_class::static_f2()
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



// Static, template => _impl.hpp
template<class T>
// static
void
my_class::static_f3()
{
	// ...
}



// Constexpr (=> inline) => _impl.hpp
constexpr
void
my_class::f2()
{
	// ...
}


// Template => _impl.hpp
template<class... Ts>
void
my_class::f3(Ts &&... args)
{
	// ...
}


};	// namespace ns2
};	// namespace ns1
