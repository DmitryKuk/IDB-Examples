// Author: Dmitry Kukovinets (d1021976@gmail.com), 22.10.2016, 21:18

// Дополнительные заголовочные файлы, нужные для функций/классов/... ниже
#include <list>
#include <boost/asio.hpp>


// Вариант 1: NAMESPACES::CLASS_NAME::FUNCTION_NAME

template<class T1, class T2>
// static
void
ns1::ns2::my_template_class<T1, T2>::static_f1();
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



template<class T1, class T2>
template<class T>
// static
void
my_template_class<T1, T2>::static_f3()
{
	// ...
}


template<class T1, class T2>
void
my_template_class<T1, T2>::f1()
{
	// ...
}


template<class T1, class T2>
template<class... Ts>
void
my_template_class<T1, T2>::f3(Ts &&... args)
{
	// ...
}


};	// namespace ns2
};	// namespace ns1
