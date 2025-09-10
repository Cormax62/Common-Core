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
	gino.signForm(doc);
	return(0);
}