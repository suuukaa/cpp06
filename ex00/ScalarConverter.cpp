#include "ScalarConverter.hpp"

bool is_char(const std::string& str){
	return str.size() == 1 && isalpha(str[0]);
}


bool is_int(const std::string& str){
    size_t i = 0;
    bool negative = false;

    if (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            negative = true;
        i++;
    }
    if (i == str.size())
        return false;
	
    for (; i < str.size(); i++) {
        if(!std::isdigit(str[i]))
            return false;
    }
        std::stringstream ss(str);
        long long num;
        ss >> num;
        
        if (negative) {
            if (num < INT_MIN)
                return false;
        } else if (num > INT_MAX)
                return false;
    return true;
}

bool is_float(const std::string& str){

	char *add = NULL;
	std::strtof(str.c_str(), &add);
	return add && static_cast<std::string>(add) == "f";
}

bool is_double(const std::string& str){
	char *add = NULL;
	std::strtod(str.c_str(), &add);
	return add && *add == '\0';
}

void ScalarConverter::convert(std::string str){

	std::stringstream s;
	char*	store = NULL;
	char	c;
	int		i;
	float	f;
	double	d;
	
	s << str;
	if (is_char(str)){
		char c = str[0];
		std::cout << "char: '" << c << "'"<< std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << std::fixed << std::setprecision(1) <<
		 "float: " << static_cast<float>(c) << "f" << std::endl
		<< "double: " << static_cast<double>(c) << std::endl;
	}
	else if (is_int(str)){
		s >> i;
		c = static_cast<char>(i);
		if (i < 0 || i > 127)
			std::cout << "char: impossible" << std::endl;
		else if (!std::isprint(c))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << c << "'"<< std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << std::fixed << std::setprecision(1) <<
		 "float: " << static_cast<float>(i) << "f" << std::endl
		<< "double: " << static_cast<double>(i) << std::endl;
	}
	else if (is_float(str)) {
		f = std::strtof(str.c_str(), &store);
		c = static_cast<char>(f);
		i = static_cast<int>(f);
		if (i < 0 || i > 127)
			std::cout << "char: impossible" << std::endl;
		else if (!std::isprint(c))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << c << "'" << std::endl;
		if (!is_int(str))
			std::cout << "int: impossible" << std::endl;
		else 
			std::cout << "int: " << i << std::endl;
		std::cout << std::fixed << std::setprecision(1)
			<< "float: " << f << "f" << std::endl
			<< "double: " << static_cast<double>(f) << std::endl;
	}
	else if(is_double(str)){
		d = std::strtof(str.c_str(), &store);
		c = static_cast<char>(d);
		i = static_cast<int>(d);
		if (i < 0 || i > 127)
			std::cout << "char: impossible" << std::endl;
		else
			std::cout << "char: '" << c << "'" << std::endl;
		if (d > INT_MAX || d < INT_MIN)
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << i << std::endl;
		std::cout << std::fixed << std::setprecision(1)
			<< "float: " << static_cast<float>(d) << "f" << std::endl
			<< "double: " << d << std::endl;
	}
	else
		std::cout << "oops type error" << std::endl;
}
