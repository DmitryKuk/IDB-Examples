// Dmitry Kukovinets <d1021976@gmail.com>, 22.11.2016, 22:31

#include <iostream>


class c
{
public:
	c()
	{
		std::cout << "constructor called" << std::endl;
	}
	
	
	~c()
	{
		std::cout << "destructor called" << std::endl;
	}
};	// class c



int main()
{
	unsigned char data[sizeof(c)];
	
	c *p = new(data) c;
	
	// operator delete(p, p);	// does nothing
	
	std::cout << "ok, call destructor manually: ";
	p->~c();
	
	return 0;
}
