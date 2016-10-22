// Author: Dmitry Kukovinets (d1021976@gmail.com), 22.10.2016, 21:18

// Дополнительные заголовочные файлы, нужные для функций/классов/... ниже
#include <algorithm>
#include <regex>


namespace {	// Анонимное пространство имён


// Вспомогательные функции/классы/..., нужные только в этом .cpp
void
helper_f()
{
	// ...
}


};	// namespace



// Вариант 1: NAMESPACES::CLASS_NAME::FUNCTION_NAME

// Static, non-inline/constexpr/template => .cpp
// static
void
ns1::ns2::f1()
{
	// ...
}



// Вариант 2: CLASS_NAME::FUNCTION_NAME in NAMESPACES

namespace ns1 {
namespace ns2 {


// ...


};	// namespace ns2
};	// namespace ns1
