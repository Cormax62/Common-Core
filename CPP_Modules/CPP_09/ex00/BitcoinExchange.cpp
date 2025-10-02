#include "BitcoinExchange.hpp"

// ------------------ CONSTRUCTORS AND DESCTRUCTORS ------------------

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {(void)other;}

BitcoinExchange::~BitcoinExchange() {}

// ------------------ OPERATOR ------------------

const BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this == &other)
		return (*this);
	return (*this);
}

// ------------------ FUNCTION ------------------

void BitcoinExchange::fillVector(std::vector<std::string> v, const char* file)
{

}