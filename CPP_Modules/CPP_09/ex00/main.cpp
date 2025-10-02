#include "BitcoinExchange.hpp"

int main(int ac, char** av)
{
    BitcoinExchange 			calc;
    std::vector<std::string>	v;

    if (ac != 2)
    {
        std::cout<<"you might need a cxsv file for this to work"<<std::endl;
        return 0;
    }
    calc.fillVector(v, av[1]);
    for (std::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
    {
        std::cout<<*it<<std::endl;
    }
}