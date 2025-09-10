#include <fstream>
#include "ShrubberyCreationForm.hpp"

// --------------- CONSTRUCTORS AND DESTRUCTOR ---------------

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation", 145, 137)
{
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm("Shrubbery Creation", 145, 137)
{
	this->target = other.target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

// --------------- OPERATOR ---------------

const ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this == &other)
		return(*this);
	this->target = other.target;
	return(*this);
}

// --------------- FUNCTION ---------------

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	std::fstream file;
	const char *R = "( _______\n /  _-_  \\ \n/~~      ~~\\ \n/~~       ~~\\ \n{           }  \n \\  _- _  /  \n   ~\\ //~   \n    | |     \n    | |     \n   // \\    \n \n)";

	if (this->getSign() == false)
		throw ShrubberyCreationForm::FormNotSiged();
	else if (executor.GetGrade() > this->getForExecute())
		throw AForm::GradeTooLowException();
	else
	{
		file.open((this->target + "_shrubbery").c_str(), std::ios::out);
		if (!file)
			throw ShrubberyCreationForm::FileNotCreated();
		file<<R<<std::endl;
		file.close();
	}
}
