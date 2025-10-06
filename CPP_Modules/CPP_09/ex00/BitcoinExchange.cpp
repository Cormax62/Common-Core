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
	std::string* array = new std::string;

	if (str.size() < 14)
		return NULL;
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

	if ((m == 2 && (y % 4) == 2) && (d < 1 || d > 29))
		return false;
	else if ((m == 2 && (y % 4) != 2) && (d < 1 || d > 28))
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
	{
		delete (array);
		return "ERROR: wrong format";
	}
	// if (parseYear(array) == false || parseMonth(array) == false || parseDay(array) == false || parseValue(array) == false)
	// 	return NULL;
	if (parseYear(array) == false )
		return "ERROR: wrong year";
	if (parseMonth(array) == false )
		return "ERROR: wrong month";
	if (parseDay(array) == false )
		return "ERROR: wrong day";
	if (parseValue(array) == false )
		return "ERROR: wrong valpue";
	ret = array[0]+"-"+array[1]+"-"+array[2]+" => "+array[3];
	std::cout<<ret<<std::endl;
	delete (array);
	return ret;
}

void BitcoinExchange::fillMap(std::map<std::string, float> map, const char* file)
{
	// std::map<std::string, float>::iterator	it = map.begin();
	std::ifstream							ifstream;
	std::string								line;
	std::string								str;

	(void)map;
	ifstream.open(file, std::ios::in);
	std::getline(ifstream, line);
	while (std::getline(ifstream, line))
	{
		std::cout<<line<<" "<<line.size()<<std::endl;
		str = parseLine(line);
	}
	ifstream.close();
}
