#include <iostream>


void f()
{
	std::cout << "hello!" << std::endl;
}


int main()
{
	std::cout
		<< reinterpret_cast<const void *>( &f) << std::endl
		<< reinterpret_cast<const void *>(  f) << std::endl
		<< reinterpret_cast<const void *>( *f) << std::endl
		<< reinterpret_cast<const void *>(**f) << std::endl;
	
	(*********&f)();
	(&f)();
	f();
	
	return 0;
}
