#include "iter.hpp"

int main()
{
	{	const int array[] = {1, 3, 6, 8, 13, 56};

		std::cout<<"conntent of the array";
		iter(array, 6, func<const int>);
		std::cout<<std::endl;
	}
	{	std::string array[] = {"kind", "genrous", "and other good things"};

		std::cout<<"u r";
		iter(array, 3, func<std::string>);
		std::cout<<std::endl;
	}
	{	char array[] = {67, 95, 82, 115, 78};

		std::cout<<"conntent of the array";
		iter(array, 5, func<char>);
		std::cout<<std::endl;
	}
	return 0;
}