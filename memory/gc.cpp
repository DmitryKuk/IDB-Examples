// Dmitry Kukovinets <d1021976@gmail.com>, 22.11.2016, 23:12

#include <iostream>

#include <boost/pool/object_pool.hpp>


class c
{
public:
	c()
	{
		std::cout << "constructor called for: " << static_cast<const void *>(this) << std::endl;
	}
	
	
	~c()
	{
		std::cout << "destructor called for: " << static_cast<const void *>(this) << std::endl;
	}
};	// class c



int main()
{
	{
		boost::object_pool<c> pool;
		
		{
			c *p1 = pool.construct();
			std::cout << "Work with p1: " << static_cast<const void *>(p1) << std::endl;
			pool.destroy(p1);
			std::cout << "Freed p1" << std::endl;
		}
		
		
		c *p2 = pool.malloc();
		std::cout << "Work with p2: " << static_cast<const void *>(p2) << std::endl;
		
		
		for (auto i = 0; i < 5; ++i) {
			c *p = pool.malloc();
			std::cout << "Allcated #" << i << ": " << static_cast<const void *>(p) << std::endl;
		}
	}
	
	std::cout << "Pool destructed" << std::endl;
	
	return 0;
}
