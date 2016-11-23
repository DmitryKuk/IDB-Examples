#include <iostream>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <boost/function_output_iterator.hpp>


class iterator
{
public:
	using value_type = int;
	// using iterator_category = std::random_iterator_tag;
	
	
	iterator(int *ptr):
		ptr_(ptr)
	{}
	
	
	int & operator*()
	{
		return *ptr_;
	}
	
	iterator & operator++()
	{
		++ptr_;
		return *this;
	}
	
	iterator operator++(int)
	{
		auto tmp = *this;
		++ptr_;
		return tmp;
	}
	
	iterator & operator--()
	{
		--ptr_;
		return *this;
	}
	
	iterator operator--(int)
	{
		auto tmp = *this;
		--ptr_;
		return tmp;
	}
	
	
	int *ptr_;
};


bool operator<(iterator a, iterator b)
{
	return a.ptr_ < b.ptr_;
}


iterator operator+(iterator a, int n)
{
	return iterator(a.ptr_ + n);
}


int main()
{
	int array1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	// int *ptr = new int[10];
	
	// for (int x: range(it1, it2))
		// std::cout << x << ' ';
	// std::cout << std::endl;
	
	// std::vector<int> v;
	// v.begin() == std::begin(v);
	
	// std::begin(array1) == array1;
	// std::end(array1) == array1 + 10;
	
	
	for (auto it = std::begin(array1), end = std::end(array1); it != end; ++it) {
		int x = *it;
		
		std::cout << x << ' ';
	}
	
	
	// auto f =
	// 	[]() -> int
	// 	{
	// 		// std::cout << "Got: " << x << std::endl;
	// 		return 100500;
	// 	};
	
	// // auto f_it = boost::make_function_output_iterator(f);
	// auto f_it = boost::make_function_input_iterator(f);
	
	// std::copy(
	// 	array1, array1 + 10,
	// 	f_it
	// );
	// *f_it = *array_it;
	
	
	// int i = 1;
	// std::for_each(array1, array1 + 10, [&](int &x) { x = i; ++i; });
	
	// std::iota(array1, array1 + 10, 1);
	
	// auto f =
	// 	[](int a, int b)
	// 	{
	// 		return a + b;
	// 	};
	
	// f(f(f(0, 1), 2), 3) ...
	
	// int sum =
	// 	std::accumulate(
	// 		array1, array1 + 10,
	// 		0,
			
	// 		f
	// 	);
	
	// std::cout << sum << std::endl;
	
	// int array2[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	
	// int sum[10];
	
	// std::transform(
	// 	array1, array1 + 10,
	// 	array2,
	// 	sum,
		
	// 	[](int a, int b)
	// 	{
	// 		return a + b;
	// 	}
	// );
	
	// std::copy(sum, sum + 10, std::ostream_iterator<int>(std::cout, ", "));
	// std::cout << std::endl;
	
	// iterator it = array, end = array + 10;
	
	// for (; it < end; ++it)
	// 	std::cout << *it << ' ';
	
	// iterator it1 = it + 5;
	
	// std::cout << *it1 << std::endl;
	
	
	// for (std::istream_iterator<int> it(std::cin), end; it != end; ++it)
	// 	std::cout << *it << ' ';
	// std::cout << std::endl;
	
	// std::ostream_iterator<int> out_it(std::cout, ", ");
	// for (int *it = array, *end = array + 10; it != end; ++it, ++out_it)
		// std::cout << *it << ' ';
	// 	*out_it = *it;
	// std::cout << std::endl;
	
	// std::for_each(
	// 	array,
	// 	array + 10,
		
	// 	[](int x)
	// 	{
	// 		std::cout << x << ' ';
	// 	}
	// );
	
	return 0;
}
