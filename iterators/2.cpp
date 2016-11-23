#include <iostream>
#include <iterator>
#include <algorithm>
#include <numeric>

#include <boost/function_output_iterator.hpp>
#include <boost/iterator/function_input_iterator.hpp>


// class iterator
// {
// public:
// 	using iterator_category = std::forward_iterator_tag;
	
	
// 	int *p;
	
	
// 	iterator(int *p):
// 		p{p}
// 	{}
	
	
// 	iterator & operator=(const iterator &other)
// 	{
// 		p = other.p;
// 		return *this;
// 	}
	
	
// 	int & operator*()
// 	{
// 		return *p;
// 	}
	
	
// 	iterator & operator++()
// 	{
// 		++p;
// 		return *this;
// 	}
	
	
// 	iterator & operator--()
// 	{
// 		--p;
// 		return *this;
// 	}
// };


// bool operator==(const iterator &a, const iterator &b)
// {
// 	return (a.p == b.p);
// }

// bool operator!=(const iterator &a, const iterator &b)
// {
// 	return !(a == b);
// }


int
main()
{
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	
	// for (iterator it(arr), end(arr + 10); it != end; ++it)
	// 	std::cout << *it << std::endl;
	
	
	// int *p = arr;
	// for (std::istream_iterator<int> it{std::cin}, end; it != end; ++it, ++p)
	// 	*p = *it;
	
	// for (auto x: arr)
	// 	std::cout << x << ' ';
	
	
	// std::copy(arr, arr + 10, std::ostream_iterator<int>{std::cout, ", "});
	
	// std::for_each(
	// 	arr, arr + 10,
		
	// 	[](int x)
	// 	{
	// 		std::cout << x << ' ';
	// 	}
	// );
	
	// int i = 0;
	// std::generate(arr, arr + 10, [&] { ++i; return i; });
	
	// std::iota(arr, arr + 10, 100);
	
	
	// auto f =
	// 	[](int x)
	// 	{
	// 		std::cout << x << ' ';
	// 	};
	
	
	// std::copy(
	// 	arr, arr + 10,
		
	// 	boost::make_function_output_iterator(
	// 		f
	// 	)
	// );
	
	
	// struct generator {
	// 	using result_type = int;
		
	// 	result_type operator() () const
	// 	{
	// 		// std::cout << "hi there" << std::endl;
	// 		return 100500;
	// 	}
	// };
	
	// generator f;
	
	// std::copy(
	// 	boost::make_function_input_iterator(f, 0), boost::make_function_input_iterator(f, 10),
	// 	arr
	// );
	
	
	for (auto x: arr)
		std::cout << x << ' ';
	
	for (auto it = std::begin(arr), end = std::end(arr); it != end; ++it) {
		auto x = *it;
		
		std::cout << x << ' ';
	}
	
	std::cout << std::endl;
	
	return 0;
}
