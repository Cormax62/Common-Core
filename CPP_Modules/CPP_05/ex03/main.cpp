#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Bureaucrat	gino("gino", 146);
	Bureaucrat	luigi("luigi", 1);
	Intern		mario;
	AForm *doc1 = mario.makeForm("robotomy request", "tio");
	AForm *doc2 = mario.makeForm("shrubbery creation", "sio");
	AForm *doc3 = mario.makeForm("presidential pardon", "vio");
	AForm *doc4;
	try
	{
		doc4 = mario.makeForm("robotomy form", "tio");
	}
	catch(const Intern::BadName& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		doc4 = mario.makeForm("urlo del siummmm", "tio");
	}
	catch(const Intern::BadName& e)
	{
		std::cerr << e.what() << '\n';
	}
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