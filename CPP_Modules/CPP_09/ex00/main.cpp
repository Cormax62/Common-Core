#include "BitcoinExchange.hpp"

int main(int ac, char** av)
{
    BitcoinExchange calc;

    if (ac != 2)
    {
        std::cout<<"you might need a cxsv file for this to work"<<std::endl;
        return 0;
    }
    calc.fillVector(av[1]);
    for (std::vector<std::string>::iterator it = calc.line.begin(); it != calc.line.end(); it++)
    {
        
    }
}