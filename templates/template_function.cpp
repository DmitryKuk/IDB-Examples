// Dmitry Kukovinets <d1021976@gmail.com>, 11.10.2016, 13:52

#include <iostream>


// Общая версия
template<class T>
inline T f(T a, T b)
{
	return a + b;
}


// Полная специализация (частичная специализация для функций запрещена! [см. std::enable_if, если сильно нужно])
template<>
inline int f(int a, int b)
{
	std::cout << "surprise from int version! ";
	return a * b;
}


// Перегрузка (т.к. другое количество аргументов), причём тоже шаблонная, но не имеет никакого отношения к f выше
template<class T>
inline T f(T a, T b, int c)
{
	std::cout << "surprize from overloaded (3 args) version! ";
	return a + b + c;
}


// Тоже перегрузка
inline int f(int a, int b, int c, int d)
{
	std::cout << "surprize from overloaded (4 args) version! ";
	return a * b * c * d;
}



// Пример шаблонной функции, где не все шаблонные параметры определяются из типов аргументов
// (а один из параметров -- вообще не тип -- это тоже работает)
template<class T1, int I, class T2>
inline void g(T2 arg)
{}



int main()
{
	std::cout << std::endl << "Output from file: " << __FILE__ << std::endl;
	
	std::cout << "f(3.0, 3.0) = " << f(3.0, 3.0) << std::endl;
	std::cout << "f(3, 3) = " << f(3, 3) << std::endl;
	
	std::cout << "f(3.0, 3.0, 3) = " << f(3.0, 3.0, 3) << std::endl;
	std::cout << "f(3, 3, 3, 3) = " << f(3, 3, 3, 3) << std::endl;
	
	
	// Пример вызова шаблонной функции g
	// Шаблонные параметры-типы, которые невозможно вычистить из типов аргументов, необходимо указывать вручную
	// (тип T2 можно не указывать, т.к. он выводится из типа аргумента)
	std::string str;
	g<double, 100500>(str);	// => T1 = double, I = 100500, T2 = std::string
	
	
	std::cout << std::endl << "End of output from file: " << __FILE__ << std::endl;
	
	return 1;
}
