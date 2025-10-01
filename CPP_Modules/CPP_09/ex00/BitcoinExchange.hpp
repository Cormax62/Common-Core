#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <vector>
# include <ostream>

class BitcoinExchange
{
private:
	std::vector<std::string> line;
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    ~BitcoinExchange();

    const BitcoinExchange& operator=(const BitcoinExchange& other);

    void	fillVector(const char* file);
};

#endif