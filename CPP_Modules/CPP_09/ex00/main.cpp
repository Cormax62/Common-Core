#include "BitcoinExchange.hpp"

int main(int ac, char** av)
{
    BitcoinExchange 		calc;
    std::map<std::string, float> map;

    if (ac != 2)
    {
        std::cout<<"you might need a cxsv file for this to work"<<std::endl;
        return 0;
    }
    calc.fillMap(map, av[1]);
}

// int main(int ac, char** av)
// {
//     std::ifstream							ifstream;
// 	std::string								line;
// 	char**								    str;

// 	ifstream.open(av[1], std::ios::in);
// 	std::getline(ifstream, line);
//     str = 
// 	ifstream.close();
// }