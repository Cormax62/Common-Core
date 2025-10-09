#include "BitcoinExchange.hpp"

int main(int ac, char** av)
{
    try
    {
    	std::string						line;
    	std::ifstream					ifstream;
    	BitcoinExchange             	calc;
    	std::map<std::string, float>	database;

    	if (ac != 2)
    	{
    	    std::cout<<"you need an input file for this to work"<<std::endl;
    	    return 0;
    	}
		ifstream.open("data.csv", std::ios::in);
		if (ifstream.is_open() == false)
			throw std::ios_base::failure(std::string("Wrong or unexsting database file"));
		std::getline(ifstream, line);
		while (std::getline(ifstream, line))
			database[line.substr(0, 10)] = atof(line.substr(11, line.size() - 11).c_str());
    	// for (std::map<std::string, float>::iterator it = database.begin(); it != database.end(); it++)
		// {
		// 	std::cout<<it->first<<", "<<it->second<<std::endl;
		// }
		ifstream.close();
    	calc.fillMap(database, av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
