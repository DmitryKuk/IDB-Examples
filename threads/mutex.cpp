// Author: Dmitry Kukovinets (d1021976@gmail.com), 18.10.2016, 20:12

#include <iostream>
#include <thread>
#include <mutex>
#include <functional>


void stupid_print(std::mutex &m1, std::mutex &m2)	// Very bad function!
{
	// Stupid lock! Don't do this!!1
	m1.lock();
	m2.lock();
	
	std::cout << "stupid_print" << std::endl;
	
	// Don't forget to unlock (best is reverse order)!
	m2.unlock();
	m1.unlock();
}


void best_print(std::mutex &m1, std::mutex &m2)
{
	// Best variant!
	// NOTE: If stupid_print is not using std::lock(), deadlock may happens...
	std::lock(m2, m1);	// Locks mutexes in correct order
	
	std::lock_guard<std::mutex>
		l1{m1, std::adopt_lock},	// Will auto-unlock mutex m1 in destructor
		l2{m2, std::adopt_lock};	// Will auto-unlock mutex m2 in destructor
	
	std::cout << "best_print" << std::endl;
}



int
main()
{
	std::cout << std::endl << "Output from file: " << __FILE__ << std::endl << std::endl;
	
	
	std::mutex m1, m2;	// Correct passing mutexes as parameters
	
	std::thread
		th1(stupid_print, std::ref(m1), std::ref(m2)),	// Don't work without std::ref()
		th2(best_print, std::ref(m1), std::ref(m2));
	
	th1.join();
	th2.join();
	
	
	std::cout << std::endl << "End of output from file: " << __FILE__ << std::endl;
	
	return 1;
}
