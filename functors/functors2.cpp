#include <iostream>
#include <utility>
#include <functional>


// template<class T>
// T f(T x)
// {
// 	std::cout << x << std::endl;
// 	return x;
// }


// template<class Fn, class... Args>
// void call(Fn fn, Args &&... args)
// {
// 	fn(std::forward<Args>(args)...);
// }


// using f_type = int (*)(int);
// void call(f_type fn, int x)
// {
// 	fn(x);
// }


void f(int x, double y)
{
	std::cout << x << ' ' << y << std::endl;
}


class C
{
	int i_;
public:
	C(int i): i_(i) {}
	
	
	void print(int x)
	{
		std::cout << "i = " << i_ << "; x = " << x << std::endl;
	}
};


int main()
{
	// f(5);
	
	// call(f<int>, 10);
	
	
	// 1
	// using f_type = void (*)(int, double);
	// f_type g = f;
	
	// 2
	// void (*g)(int, double) = f;
	
	
	// auto g = reinterpret_cast<void (*)(double, int)>(f);
	// g(2.5, 1);
	
	
	// auto g =
	// 	[](double y, int x)
	// 	{
	// 		return f(x, y);
	// 	};
	
	
	using namespace std::placeholders;
	// auto g = std::bind(f, _2, _1);
	
	// g(2.5, 1);
	
	// g(2.5, 1);
	
	
	C c1{1}, c2{2};
	
	// c1.print(10);
	
	// auto func =
	// 	[](C &obj, int x)
	// 	{
	// 		obj.print(x);
	// 	};
	
	// auto func = std::bind(&C::print, c1, _2);
	
	// func(10, 11);
	
	
	auto func =
		[](auto fn, auto &obj)
		{
			(obj.*fn)(10);
		};
	
	func(&C::print, c1);
	
	return 0;
}
