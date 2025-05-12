#include "ScalarConverter.hpp"

int main(int ac, char **av){
	if (ac == 2){
		ScalarConverter::convert(static_cast<std::string>(av[1]));
	}
	else
		std::cout << "ERROR" << std::endl;
	return 0;
}

