// Dmitry Kukovinets <d1021976@gmail.com>, 11.10.2016, 13:52

#include <iostream>
#include <tuple>


// Общая версия
template<class... Ts>
void print(Ts &&... args)	// Переменное количество аргументов (которые являются универсальными ссылками)
{}


// Тоже общая версия (перегрузка, не специализация),
// которая тоже шаблонная, и тоже со списком аргументов переменной длины.
// Важное отличие: первый аргумент у этой версии точно есть (т.к. объявлен явно) => эта версия предпочтительна
// при вызове, когда есть хотя бы один аргумент. Если аргументов нет ("print()"), то будет вызвана версия выше.
template<class T1, class... Ts>
void print(T1 &&arg1, Ts &&... args)
{
	std::cout << ' ' << arg1;
	
	// Да, так можно. Запомните формат записи!
	print(std::forward<Ts>(args)...);
	// Эквивалентно записи:
	// print(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c));
	// Если под "Ts.." скрываются типы A, B, C, а под "args..." -- значения a, b, c.
	// По std::forward и ссылкам см. пример "references".
	
	// P.S. Тупое разворачивание списка аргументов args тоже бы сработало:
	// print(args...);
	// Но это не всегда хорошо -- см. пример по ссылкам!
}



// Может ли у функции быть несколько списков шаблонных параметров переменной длины?
// -- Да, если типы аргументов функции позволяют вывести все шаблонные параметры!
template<class... Ts1, class... Ts2>
void f(const std::tuple<Ts1...> &tuple1, const std::tuple<Ts2...> &tuple2)
{}


// Работает ли то же для классов (ведь у них нет аргументов, из которых всё можно вывести)?
// И нет, и да. Есть нюансы:

// ОК
// template<class... Ts>
// class c;

// Не ОК! (Поэтому не работает)
// template<class... Ts1, class... Ts2>
// class c;


// Эпизод IV: Новая надежда...
// Решение-трюк:
// Всё ОК, тут вообще нет списка аргументов переменно длины
// template<class T1, class T2>
// class c;

// [Частичная специализация] Всё ОК, класс c по прежнему -- ровно от двух шаблонных параметров
// template<class... Ts1, class... Ts2>
// class c<std::tuple<Ts1...>, std::tuple<Ts2...>>
// {
	// Теперь здесь доступны списки шаблонных параметров Ts1 и Ts2! Бесплатно, без смс! Невероятно!
// };

// Это можно использовать так:
// c<std::tuple<int, int, int>, std::tuple<int, int, double, long>>	// Такой тип скомпилируется и будет работать


int
main()
{
	std::cout << std::endl << "Output from file: " << __FILE__ << std::endl << std::endl;
	
	
	print(1, 2, 3, "hello", 10.5);
	std::cout << std::endl;
	
	
	std::tuple<int, char, double> t1;
	std::tuple<long, std::tuple<int, float>> t2;
	f(t1, t2);
	// => "Ts1" разворачивается в: int, char, double
	// => "Ts2" разворачивается в: long, std::tuple<int, float>
	
	
	std::cout << std::endl << "End of output from file: " << __FILE__ << std::endl;
	
	return 1;
}
