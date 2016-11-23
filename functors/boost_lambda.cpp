#include <iostream>
#include <vector>

#include <boost/lambda/lambda.hpp>
#include <boost/lambda/if.hpp>


int
main()
{
	using namespace boost::lambda;
	
	const auto f =
		if_then_else(
			_1 < 5,
			std::cout << _1 << '\n',
			std::cout << _2 << '\n'
		);
	
	f(1, 5);
	f(10, "hello");
	
	return 0;
}
