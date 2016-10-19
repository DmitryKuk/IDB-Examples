// Dmitry Kukovinets <d1021976@gmail.com>, 11.10.2016, 13:52

#include <iostream>


class c1
{
public:
	template<class T>
	static inline void static_f()
	{}
	
	
	template<class T>
	inline void f1(T arg)
	{}
	
	
	template<class T1, int I, class T2>
	inline void f2(T2 arg)
	{}
	
	
	template<class T1, int I, class T2>
	inline void f3(T2 arg);
};


// Пример определения такой функции вне класса
template<class T1, int I, class T2>
inline
void
c1::f3(T2 arg)
{}



// То же, но теперь сам класс тоже шаблонный
template<class ClassT>
class c2
{
public:
	template<class T>
	static inline void static_f()
	{}
	
	
	template<class T>
	inline void f1(T arg)
	{}
	
	
	template<class T1, int I, class T2>
	inline void f2(T2 arg)
	{}
	
	
	template<class T1, int I, class T2>
	inline void f3(T2 arg);
};


// Пример определения такой функции вне класса
template<class ClassT>
template<class T1, int I, class T2>
inline
void
c2<ClassT>::f3(T2 arg)
{}



int main()
{
	std::cout << std::endl << "Output from file: " << __FILE__ << std::endl;
	
	
	// Зачем писать ключевое слово "template" при вызове шаблонных методов класса?
	// Затем, что иногда компилятору это необходимо.
	// Иногда всё работает без него, но иногда, например, clang подсказывает, что его нужно написать.
	
	// Если вызываете шаблонную функцию-член класса (статическую или нет), все шаблонные параметры
	// выводятся из типов аргументов, и вы не пишете угловые скобочки с шаблонными параметрами вручную,
	// то "template" писать не нужно.
	
	
	c1 a;
	a.f1(5);						// ОК, T1 = int
	a.template f2<double, 100>(5);	// ОК, но пишем "template", потому что компилятор [иногда] это требует
	// f3 аналогично f2, поэтому примера нет
	
	c1::template static_f<int>();	// Пример со статической функцией-членом класса
	
	
	// Всё аналогично нешаблонному классу c1
	c2<float> b;
	b.f1(5);
	b.template f2<double, 100>(5);
	
	c2<float>::template static_f<int>();	// Пример со статической функцией-членом класса
	
	
	std::cout << std::endl << "End of output from file: " << __FILE__ << std::endl;
	
	return 1;
}
