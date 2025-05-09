#ifndef SCALARCONVERTER
#define SCALARCONVERTER

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <climits>

class ScalarConverter{

	ScalarConverter();
	ScalarConverter(const ScalarConverter &copy);
	ScalarConverter operator=(const ScalarConverter &copy);
	~ScalarConverter();

	public :
		static void convert(std::string str);
};

bool is_char(const std::string&);
bool is_int(const std::string&);
bool is_float(const std::string&);
bool is_double(const std::string&);

#endif

