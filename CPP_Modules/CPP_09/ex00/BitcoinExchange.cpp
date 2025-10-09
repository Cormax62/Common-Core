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

std::string* splitLine(std::string str)
{
	std::string* array;

	if (str.size() < 14)
	{
		array = NULL;
		return array;
	}
	array = new std::string[4];
	array[0] = str.substr(0, 4);
	array[1] = str.substr(5, 2);
	array[2] = str.substr(8, 2);
	array[3] = str.substr(13, str.size() - 13);
	return array;
}

bool parseYear(std::string* str)
{
	int n = std::atoi(str[0].c_str());

	if (n < 2009)
		return false;
	return true;
}

bool parseMonth(std::string* str)
{
	int n = std::atoi(str[1].c_str());

	if (n < 1 || n > 12)
		return false;
	return true;
}

bool parseDay(std::string* str)
{
	int d = std::atoi(str[2].c_str());
	int m = std::atoi(str[1].c_str());
	int y = std::atoi(str[0].c_str());

	if ((m == 2 && (y % 4) == 0) && (d < 1 || d > 29))
		return false;
	else if ((m == 2 && (y % 4) != 0) && (d < 1 || d > 28))
		return false;
	else if ((m == 11 || m == 4 || m == 6 || m == 9) && (d < 1 || d > 30))
		return false;
	else if (d < 1 || d > 31)
		return false;
	return true;
}

bool parseValue(std::string* str)
{
	float n = std::atof(str[3].c_str());

	if (n < 0 || n > 1000)
		return false;
	return true;
}


std::string parseLine(std::string str)
{
	std::string*	array;
	std::string		ret;

	std::string pippo = str.substr(0, 7);
	array = splitLine(str);
	if (array == NULL)
		return "ERROR: wrong format = " + str;
	if (parseYear(array) == false)
	{
		delete[] (array);
		return "ERROR: wrong year = " + str;
	}
	if (parseMonth(array) == false)
	{
		delete[] (array);
		return "ERROR: wrong month = " + str;
	}
	if (parseDay(array) == false)
	{
		delete[] (array);
		return "ERROR: wrong day = " + str;
	}
	if (parseValue(array) == false)
	{
		delete[] (array);
		return "ERROR: wrong value = " + str;
	}
	if (str[4] != '-' || str[7] != '-' || str[11] != '|')
	{
		delete[] (array);
		return "ERROR: wrong format = " + str;
	}
	ret = array[0]+"-"+array[1]+"-"+array[2]+" => "+array[3];
	delete[] (array);
	return ret;
}

float getValue(std::map<std::string, float> database, std::string str)
{
	float amount = atof(str.substr(13, str.size() - 13).c_str());

	for (std::map<std::string, float>::iterator it = database.begin(); it != database.end(); it++)
	{
		if (it->first == str.substr(0, 10))
			return (amount * it->second);
		else if (it->first > str.substr(0, 10))
		{
			it--;
			return (amount * it->second);
		}
	}
	return 0;
}

void BitcoinExchange::fillMap(std::map<std::string, float> database, const char* file)
{
	std::ifstream	ifstream;
	std::string		line;
	std::string		str;

	(void)database;
	ifstream.open(file, std::ios::in);
	if (ifstream.is_open() == false)
		throw std::ios_base::failure(std::string("Failed to open file: ") + file);
	std::getline(ifstream, line);
	while (std::getline(ifstream, line))
	{
		str = parseLine(line);
		std::cout<<str;
		if (str.substr(0, 5) != "ERROR")
			std::cout<<" = "<<getValue(database, str);
		std::cout<<std::endl;
	}
	ifstream.close();
}
