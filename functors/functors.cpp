#include <iostream>
// #include <typeinfo>
#include <functional>


// template<class T1, class T2 = int>
// int f(T1 x) noexcept
// {
// 	// std::cout << x << std::endl;
// 	return 0;
// }


// class c
// {
// public:
// 	int operator()(int x, int y) const
// 	{
// 		return 0;
// 	}
	
// 	void operator()(int x) const
// 	{
// 		this->i = 10;
// 	}
	
	
// 	template<class T = int>
// 	void operator()() const
// 	{
// 		T x;
// 		std::cout << "got type: " << typeid(x).name() << std::endl;
// 	}
// private:
// 	mutable int i = 0;
// };


// auto get_f()
// {
// 	int i = 0;
	
// 	auto f =
// 		[&](int x) mutable noexcept
// 		{
// 			++i;
			
// 			std::cout << x << ": " << i << std::endl;
// 		};
	
// 	f(1000);
	
// 	i = 1000;
	
// 	f(10);
	
// 	// return f;
// }


template<class T = int>
int f(int x, double y)
{
	std::cout << x << ", " << y << std::endl;
	return x;
}


int main()
{
	f(1, 1.5);
	
	// using namespace std::placeholders;
	// auto g = std::bind(f<int>, _2, _1);
	
	auto g = [](double y, int x) { return f(x, y); };
	
	g(2.5, 2);
	
	// 1
	// using f_type = int (*)(double, int);
	// f_type g = reinterpret_cast<f_type>(f);
	
	// 2
	// int (*g)(int, double) = f<int>;
	
	// g(2.5, 2);
	
	// std::function<int (int, double)> fn = f;
	
	
	// c f;
	// f(5);
	// f(1, 2);
	// f();
	// f.operator()<double>();
	
	
	// int i = 0;
	
	// auto f =
	// 	[=](int x) mutable noexcept -> std::string
	// 	{
	// 		i = 10;
			
	// 		std::cout << x << std::endl;
	// 		return std::string{"hello"};
	// 	};
	
	
	// f(10);
	
	
	// auto f = get_f();
	
	// f(10);
	// f(15);
	// get_f();
	
	
	// std::vector<int> v{1, 2, 3, 4, 5};
	
	// std::for_each(
	// 	v.begin(), v.end(),
	// 	[](int x) { std::cout << "hello: " << x << std::endl; }
	// );
	
	return 0;
}
