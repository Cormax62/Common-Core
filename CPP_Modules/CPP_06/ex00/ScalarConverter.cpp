#include "ScalarConverter.hpp"

// ------------- CONSTRUCTORS AND DESTRUCTOR -------------

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter::~ScalarConverter()
{
}

// ------------- OPERATOR -------------

const ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	if (this == &other)
		return(*this);
	return(*this);
}

// ------------- FUNCTION -------------

bool is_float(std::string literal)
{
	bool	point = false;

	for (int i = 0; i < static_cast<int>(literal.length()) - 1; i++)
	{
		if (i == 0 && !std::isdigit(literal.c_str()[0]))
		{
			if (literal.c_str()[0] != '-' && literal.c_str()[0] != '+')
				return (false);
			i++;
		}
		if (i != 0 && literal.c_str()[i] == '.')
		{
			if (point == false)
				point = true;
			else
				return (false);
			i++;
		}
		if (!std::isdigit(literal[i]))
			return (false);
	}
	// if (literal[literal.length() - 1] != 'f')
	// 	return (false);
	std::cout<<"Float: "<<static_cast<float>(atof(literal.c_str()))<<std::endl;
	return (true);
}

bool is_double(std::string literal)
{
	bool	point = false;

	for (int i = 0; i < static_cast<int>(literal.length()); i++)
	{
		if (i == 0 && !std::isdigit(literal.c_str()[0]))
		{
			if (literal.c_str()[0] != '-' && literal.c_str()[0] != '+')
				return (false);
			i++;
		}
		if (i != 0 && literal.c_str()[i] == '.')
		{
			if (point == false)
				point = true;
			else
				return (false);
			i++;
		}
		if (!std::isdigit(literal[i]))
			return (false);
	}
	// if (point == false)
	// 	return (false);
	std::cout<<"Double: "<<static_cast<double>(atof(literal.c_str()))<<std::endl;
	return (true);
}

bool is_int(std::string literal)
{
	for (int i = 0; i < static_cast<int>(literal.length()); i++)
	{
		if (i == 0 && (literal.c_str()[0] == '-' || literal.c_str()[0] == '+'))
			i++;
		if (i != 0 && literal.c_str()[i] == '.')
			i++;
		if (!std::isdigit(literal[i]))
			return (false);
	}
	std::cout<<"Int: "<<static_cast<int>(atoi(literal.c_str()))<<std::endl;
	return (true);
}

bool is_char(std::string literal)
{
	if (literal.length() == 1)
		std::cout<<"Char: "<< static_cast<char>(literal.c_str()[0])<<std::endl;
	else
	{
		std::cout<<"Char: ";
		int n = atoi(literal.c_str());
		if (std::isprint(n))
			std::cout<< static_cast<char>(n)<<std::endl;
		else
			std::cout<<"not displayable"<<std::endl;
	}
	return (true);
}

void ScalarConverter::convert(std::string literal)
{
	if (literal == "+inf")
	{
		std::cout<<"Char: impossible"<<std::endl;
		std::cout<<"Int: impossible"<<std::endl;
		std::cout<<"Float: +inf"<<std::endl;
		std::cout<<"Double: +inf"<<std::endl;
		return ;
	}
	else if (literal == "-inf")
	{
		std::cout<<"Char: impossible"<<std::endl;
		std::cout<<"Int: impossible"<<std::endl;
		std::cout<<"Float: -inf"<<std::endl;
		std::cout<<"Double: -inf"<<std::endl;
		return ;
	}
	else if (literal == "nan")
	{
		std::cout<<"Char: impossible"<<std::endl;
		std::cout<<"Int: impossible"<<std::endl;
		std::cout<<"Float: nan"<<std::endl;
		std::cout<<"Double: nan"<<std::endl;
		return ;
	}
	is_char(literal);
	is_int(literal);
	is_float(literal);
	is_double(literal);
}
