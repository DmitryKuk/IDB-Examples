#include <iostream>
#include <memory>


class c
{
public:
	c * operator&()
	{
		return nullptr;
	}
};


int main()
{
	c c1;
	c *p1 = std::addressof(c1);
	
	std::cout << "p1: " << static_cast<const void *>(p1) << std::endl;
	
	return 0;
}
