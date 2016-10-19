// Dmitry Kukovinets <d1021976@gmail.com>, 11.10.2016, 13:52

#include <iostream>
#include <vector>
#include <list>


template<
	template<class...>	// Да, здесь тоже может быть список шаблонный параметров переменной длины
	class Container
>
Container<int>
save_data_to_container()
{
	return Container<int>{1, 2, 3};
}


int
main()
{
	std::cout << std::endl << "Output from file: " << __FILE__ << std::endl << std::endl;
	
	std::vector<int> v = save_data_to_container<std::vector>();
	
	std::cout << "Data in v:";
	for (int x: v)
		std::cout << ' ' << x;
	std::cout << std::endl;
	
	
	std::list<int>   l = save_data_to_container<std::list>();
	
	std::cout << "Data in l:";
	for (int x: l)
		std::cout << ' ' << x;
	std::cout << std::endl;
	
	
	std::cout << std::endl << "End of output from file: " << __FILE__ << std::endl;
	
	return 1;
}
