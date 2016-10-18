// Dmitry Kukovinets <d1021976@gmail.com>, 12.10.2016, 13:00

#include <iostream>
#include <utility>
#include <string>


class test
{
public:
	test(std::string &&s):
		str(std::move(s))
	{
		std::cout << "Constructed " << static_cast<const void *>(this->str.c_str()) << std::endl;
	}
	
	
	// Copy constructor
	test(const test &other):
		str(other.str)
	{
		std::cout << "Copy-constructed: " << static_cast<const void *>(this->str.c_str()) << std::endl;
	}
	
	// Move-constructor
	test(test &&other) noexcept:
		str(std::move(other.str))
	{
		std::cout << "Move-constructed: " << static_cast<const void *>(this->str.c_str()) << std::endl;
	}
	
	
	// Copy assignment
	test & operator=(const test &other)
	{
		this->str = other.str;
		std::cout << "Copy-assigned: " << static_cast<const void *>(this->str.c_str()) << std::endl;
		return *this;
	}
	
	// Move assignment
	test & operator=(test &&other) noexcept
	{
		this->str = std::move(other.str);
		std::cout << "Move-assigned: " << static_cast<const void *>(this->str.c_str()) << std::endl;
		return *this;
	}
	
	
	// Reference qualifiers for methods
	void print() &
	{
		std::cout << "print1" << std::endl;
	}
	
	void print() &&
	{
		std::cout << "print2" << std::endl;
	}
	
	void print() const &
	{
		std::cout << "const print1" << std::endl;
	}
	
	void print() const &&
	{
		std::cout << "const print2" << std::endl;
	}
	
	
	std::string str;
};



int
main()
{
	std::cout << std::endl << "Output from file: " << __FILE__ << std::endl;
	
	
	std::cout << std::endl << "Copy/move constructors/assignments:" << std::endl << std::endl;
	
	std::string str = "hello111111111111111111111111111111111111                ";
	test t1(std::move(str));
	
	
	test t2(std::move(t1));
	test t3(t1);
	
	t3 = std::move(t2);
	t2 = t3;
	
	
	std::cout << std::endl << std::endl << "Ref-qualified member functions:" << std::endl << std::endl;
	
	const test t4 = t3;
	std::move(t1).print();
	std::move(t4).print();
	
	
	std::cout << std::endl << "End of output from file: " << __FILE__ << std::endl;
	
	return 1;
}
