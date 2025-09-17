#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <stdlib.h>

class ScalarConverter
{
private:	
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	~ScalarConverter();
public:
	const ScalarConverter& operator=(const ScalarConverter& other);
	static void convert(std::string literal);
};

#endif