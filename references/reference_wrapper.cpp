// Dmitry Kukovinets <d1021976@gmail.com>, 18.10.2016, 19:59

#include <iostream>
#include <functional>


void print(int &x)
{
	std::cout << x << std::endl;
}


int main()
{
	std::cout << std::endl << "Output from file: " << __FILE__ << std::endl;
	
	
	int x = 10;
	int y = 100500;
	
	std::reference_wrapper<int> ref = std::ref(x);	// See also: std::cref
	int &r = ref;
	r = y;
	
	print(std::ref(x));
	
	std::cout << r << std::endl;
	std::cout << x << ' ' << y << std::endl;
	
	
	std::cout << std::endl << "End of output from file: " << __FILE__ << std::endl;
	
	return 1;
}
