#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <stdlib.h>
# include <string>
# include <fstream>
# include <map>
# include <ostream>

class BitcoinExchange
{
private:
	
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    ~BitcoinExchange();

    const BitcoinExchange& operator=(const BitcoinExchange& other);

    void	fillMap(std::map<std::string, float> v, const char* file);
};

#endif