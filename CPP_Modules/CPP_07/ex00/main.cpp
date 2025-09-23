#include "whatever.hpp"

int	main()
{
	int a = 6;
	int b = 3;

	std::cout<<"min :"<<min(a, b)<<std::endl;
	std::cout<<"max :"<<max(a, b)<<std::endl;
	std::cout<<"non swapped: a="<<a<<" ,b="<<b<<std::endl;
	swap(a, b);
	std::cout<<"swapped: a="<<a<<" ,b="<<b<<std::endl;
}