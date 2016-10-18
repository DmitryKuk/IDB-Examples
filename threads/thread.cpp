// Author: Dmitry Kukovinets (d1021976@gmail.com), 18.10.2016, 20:12

#include <iostream>
#include <thread>
#include <chrono>


void print1(int x, int y)
{
	using namespace std::literals;
	std::this_thread::sleep_for(3s);	// Sleep for 3 seconds
	
	std::cout << "print1: " << x << ' ' << y << std::endl;
}


void print2()
{
	using namespace std::literals;
	std::this_thread::sleep_for(1s);
	
	std::cout << "print2 done" << std::endl;
}



int
main()
{
	std::cout << std::endl << "Output from file: " << __FILE__ << std::endl << std::endl;
	
	
	std::thread
		th1(print1, 1, 2),	// With arguments
		th2(print2);
	
	th1.join();
	th2.join();
	
	
	std::cout << std::endl << "End of output from file: " << __FILE__ << std::endl;
	
	return 1;
}
