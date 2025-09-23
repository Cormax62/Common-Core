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

void ScalarConverter::convert(std::string literal)
{
	if (literal == "+inff" || literal == "+inf" || literal == "inff" || literal == "inf")
	{
		std::cout<<"Char: impossible"<<std::endl;
		std::cout<<"Int: impossible"<<std::endl;
		std::cout<<"Double: +inf"<<std::endl;
		std::cout<<"Float: +inff"<<std::endl;
		return ;
	}
	else if (literal == "-inff" || literal == "-inf")
	{
		std::cout<<"Char: impossible"<<std::endl;
		std::cout<<"Int: impossible"<<std::endl;
		std::cout<<"Double: -inf"<<std::endl;
		std::cout<<"Float: -inff"<<std::endl;
		return ;
	}
	else if (literal == "nanf" || literal == "nan")
	{
		std::cout<<"Char: impossible"<<std::endl;
		std::cout<<"Int: impossible"<<std::endl;
		std::cout<<"Double: nan"<<std::endl;
		std::cout<<"Float: nanf"<<std::endl;
		return ;
	}

	int 	i;
	float	f;

	for(i = 0; i < static_cast<int>(literal.length()); i++)
	{
		if (!std::isalpha(literal[i]))
			break;
	}
	if ((i == static_cast<int>(literal.length()) - 1 || std::isalpha(literal[0])) && static_cast<int>(literal.length()) != 1)
		return ;
	if (static_cast<int>(literal.length()) == 1 && std::isalpha(literal[0]))
		f = static_cast<float>(literal.c_str()[0]);
	else
		f = static_cast<float>(atof(literal.c_str()));
	if (f > 2147483647.0f || f < -2147483648.0f || !std::isprint(static_cast<int>(f)))
		std::cout<<"Char: not printable"<<std::endl;
	else if /* (std::isalpha(static_cast<int>(f))) */ /* 54354 */ ((static_cast<int>(f) >= 32) && (static_cast<int>(f) <= 126))
		std::cout<<"Char: "<<static_cast<char>(f)<<std::endl;
	else
		std::cout<<"Char: not printable"<<std::endl;
	if (f > 2147483647.0f)
		std::cout<<"Int: 2147483647"<<std::endl;
	else if (f < -2147483648.0f)
		std::cout<<"Int: -2147483648"<<std::endl;
	else
		std::cout<<"Int: "<<static_cast<int>(f)<<std::endl;
	std::cout<<"Double: "<<static_cast<double>(f);
	if (static_cast<float>(static_cast<int>(f)) != f)
		std::cout<<std::endl;
	else
		std::cout<<".0"<<std::endl;
	std::cout<<"Float: "<<f;
	if (static_cast<float>(static_cast<int>(f)) != f)
		std::cout<<"f"<<std::endl;
	else
		std::cout<<".0f"<<std::endl;
}
