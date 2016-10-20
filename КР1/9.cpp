// Dmitry Kukovinets <d1021976@gmail.com>, 19.10.2016, 13:01

#include <iostream>
#include <iterator>		// std::ostream_iterator
#include <algorithm>	// std::copy
#include <type_traits>	// std::is_same


template<class T, T... Vs>
class ct_array
{
public:
	using value_type = T;
	
	static constexpr size_t     size     = sizeof...(Vs);
	static constexpr value_type values[] = { Vs... };
	
	
	static inline void print()
	{
		std::copy(std::begin(values), std::end(values), std::ostream_iterator<value_type>(std::cout, " "));
		std::cout << std::endl;
	}
};


template<class T, T... Vs>
// static
constexpr size_t
	ct_array<T, Vs...>::size;

template<class T, T... Vs>
// static
constexpr typename ct_array<T, Vs...>::value_type
	ct_array<T, Vs...>::values[];



template<class T>
constexpr
size_t
size() noexcept
{
	return T::size;
}


template<class T, size_t I>
constexpr
typename T::value_type
get() noexcept
{
	static_assert(I < size<T>(), "Out of range!");
	return T::values[I];
}



template<class T1, class T2>
class ct_cat;


template<class T1, T1... Vs1, class T2, T2... Vs2>
class ct_cat<
	ct_array<T1, Vs1...>,
	ct_array<T2, Vs2...>
>
{
	static_assert(std::is_same<T1, T2>::value, "Can not catenate arrays of different types!");
public:
	using type = ct_array<T1, Vs1..., Vs2...>;
};



int main()
{
	using a = ct_array<int, 1, 2, 3>;
	using b = ct_array<int, 4, 5, 6, 7>;
	using c = ct_array<char, 'a', 'b', 'c'>;
	
	
	// (1) Получение значения и размера
	std::cout << size<c>() << std::endl;	// "3"
	std::cout << get<c, 0>() << std::endl;	// "a"
	// std::cout << get<c, 5>() << std::endl;	// Compilation error
	
	
	// (2) Конкатенация, ct_array<int, ...>, ct_array<int, ...>
	using ab = typename ct_cat<a, b>::type;
	static_assert(
		std::is_same<
			ab,
			ct_array<int, 1, 2, 3, 4, 5, 6, 7>
		>::value,
		
		"Types not match!"
	);
	
	// Конкатенация, ct_array<T1, ...>, ct_array<T2, ...>, T1 != T2
	// using ac = typename ct_cat<a, c>::type;	// Compilation error
	
	
	// (3) Печать
	// Либо с использованием статических функций
	a::print();	// Печатает в std::cout: "1 2 3"
	c::print();	// Печатает в std::cout: "a b c"
	
	// Либо с использованием внешних функций -- как удобнее
	// print<a>();	// Печатает в std::cout: "1 2 3"
	// print<c>();	// Печатает в std::cout: "a b c"
	
	return 0;
}
