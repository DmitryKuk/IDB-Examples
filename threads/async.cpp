// Author: Dmitry Kukovinets (d1021976@gmail.com), 18.10.2016, 20:12

#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <chrono>
#include <future>


void thread_safe_print(const std::string &message)
{
	static std::mutex m;	// Protecting std::cout
	
	
	std::lock_guard<std::mutex> l(m);	// Will auto-lock/unlock mutex m
	
	std::cout << "Message from thread: " << std::this_thread::get_id() << ": " << message << std::endl;
}


int f(int x, int y, int sleep_time)
{
	auto message = "f(" + std::to_string(x) + ", " + std::to_string(y) + ")";
	
	using namespace std::literals;	// For 's' suffix
	thread_safe_print(message + "... ("s + std::to_string(sleep_time) + " seconds)...");
	
	std::this_thread::sleep_for(std::chrono::seconds(sleep_time));
	
	auto result = x + y;	// :)
	
	thread_safe_print(message + " = " + std::to_string(result));
	
	return result;
}


int
main()
{
	std::cout << std::endl << "Output from file: " << __FILE__ << std::endl << std::endl;
	
	
	thread_safe_print("Starting calculations...");
	
	
	std::future<int>
		a = std::async(f, 1, 2, 3),							// Auto policy (== launch::async | launch::deferred)
		b = std::async(std::launch::async, f, 3, 4, 5),		// Launch now!
		c = std::async(std::launch::deferred, f, 5, 6, 2),	// Launch on "c.get();" or "c.wait();"
		
		d = std::async(std::launch::deferred, f, 100500, 100500, 100500);
	
	
	thread_safe_print("Calculations started...");
	
	
	thread_safe_print("c.get() == " + std::to_string(c.get()));
	
	// Ignore d results => will be not called
	
	thread_safe_print("At the end of main...");
	
	
	using namespace std::literals;
	std::this_thread::sleep_for(3s);
	
	std::cout << std::endl << "End of output from file: " << __FILE__ << std::endl;
	
	return 1;
}
