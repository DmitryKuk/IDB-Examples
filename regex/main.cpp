// Dmitry Kukovinets <d1021976@gmail.com>, 17.10.2016, 18:49

#include <iostream>
#include <regex>
#include <string>


int main()
{
	constexpr auto r_str = "(-?[0-9a-f]+|[XVI]+)";
	const std::regex r{r_str};
	
	const std::string
		strings[] = {
			"1a2b3c",
			"-abc",
			"XV",
			"-IV",
			"123V",
			"+XII"
		};
	
	
	std::cout << std::endl << "Regex: \"" << r_str << "\":" << std::endl;
	
	std::smatch m;	// Will contain results after each std::regex_match call
	unsigned int i = 0;
	for (const auto &str: strings) {
		bool matched = std::regex_match(str, m, r);
		std::cout << ++i << ": \"" << str << "\": " << std::boolalpha << matched << std::endl;
		
		// Get matched groups
		if (matched) {
			std::cout << "    Groups: " << m.size() << ':' << std::endl;
			
			for (const auto &group: m)
				std::cout << "        \"" << group << '\"' << std::endl;
		}
	}
	
	std::cout << std::endl;
	
	return 1;	// For b2
}
