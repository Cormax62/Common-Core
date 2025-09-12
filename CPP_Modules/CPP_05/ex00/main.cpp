#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat gino("gino", 200);

		std::cout<<"everything is good!"<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat gino("gino", -200);

		std::cout<<"everything is good!"<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}try
	{
		Bureaucrat gino("gino", 150);
		std::cout<<"everything is good!"<<std::endl;
		gino.decrementGrade();

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat gino("gino", 1);
		std::cout<<"everything is good!"<<std::endl;
		gino.incrementGrade();

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
