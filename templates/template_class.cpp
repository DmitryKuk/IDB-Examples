// Dmitry Kukovinets <d1021976@gmail.com>, 11.10.2016, 13:52

#include <iostream>


template<class T1>
class c1
{
public:
	static void print()
	{
		std::cout << "c1: common version" << std::endl;
	}
};


template<>		// Должно быть даже с пустыми скобками, т.к. специализация
class c1<int>	// <- в угловых скобках указываются все шаблонные параметры, включая специализированные
{
public:
	static void print()
	{
		std::cout << "c1: version for int" << std::endl;
	}
};



// Да, шаблонные параметры могут быть не только типами, но и целочисленными значениями
template<class T1, unsigned int I>
class c2
{
public:
	static void print()
	{
		std::cout << "c2: common version, I = " << I << std::endl;
	}
};


// Частичная специализация
template<unsigned int I>	// Указываем те шаблонные параметры, которые потребуются в строчке ниже
class c2<int, I>			// <- в угловых скобках указываются все шаблонные параметры, включая специализированные
{
public:
	static void print()
	{
		std::cout << "c2: version for int, I = " << I << std::endl;
	}
};


// Полная специализация
template<>
class c2<int, 50>	// <- в угловых скобках указываются все шаблонные параметры, включая специализированные
{
public:
	static void print()
	{
		std::cout << "c2: version for int, 50" << std::endl;
	}
};



int main()
{
	std::cout << std::endl << "Output from file: " << __FILE__ << std::endl;
	
	
	std::cout << std::endl << "c2:" << std::endl << std::endl;
	
	c1<double>::print();
	c1<long>::print();
	c1<int>::print();
	
	
	std::cout << std::endl << "c2:" << std::endl << std::endl;
	
	c2<double, 10>::print();	// Common
	c2<int, 1>::print();		// Partial specialization
	c2<int, 50>::print();		// Full specialization
	
	
	std::cout << std::endl << "End of output from file: " << __FILE__ << std::endl;
	
	return 1;
}
