#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat	gino("gino", 146);
	Bureaucrat	luigi("luigi", 1);
	AForm *doc1 = new ShrubberyCreationForm("pio");
	AForm *doc2 = new RobotomyRequestForm("sio");
	AForm *doc3 = new PresidentialPardonForm("tio");
	try
	{
		Bureaucrat	mimmo("mimmo", 151);
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat	leo("leo", -5);
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		gino.signForm(*doc1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		gino.signForm(*doc2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		gino.signForm(*doc3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		luigi.signForm(*doc1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		luigi.signForm(*doc2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		luigi.signForm(*doc3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		gino.executeForm(*doc1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		gino.executeForm(*doc2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		gino.executeForm(*doc3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		luigi.executeForm(*doc1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		luigi.executeForm(*doc2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		luigi.executeForm(*doc3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete(doc1);
	delete(doc2);
	delete(doc3);
	return(0);
}