#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat gino("gino", 30);
	Form doc("doc", 30, 10);

	try
	{
		Bureaucrat luis("gino", 300);
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form dos("doc", 300, 10);
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form dos("doc", -5, 10);
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form dos("doc", 1, 1);
		gino.signForm(dos);
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << doc << std::endl;
	gino.signForm(doc);
	std::cout << doc << std::endl;

	return(0);
}
