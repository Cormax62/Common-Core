#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <vector>
# include <ostream>

class BitcoinExchange
{
private:
	
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    ~BitcoinExchange();

    const BitcoinExchange& operator=(const BitcoinExchange& other);

    void	fillVector(std::vector<std::string> v, const char* file);
};

#endif