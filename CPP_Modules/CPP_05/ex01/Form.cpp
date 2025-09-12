#include "Form.hpp"

// --------------- CONSTRUCTORS AND DESTRUCTOR ---------------

Form::Form(std::string name, int toSign, int toEx) : name(name), forSigned(toSign), forExecute(toEx)
{
	if (this->getForExecute() < 1 || this->getForSigned() < 1)
		throw Form::GradeTooHighException();
	if (this->getForExecute() > 150 || this->getForSigned() > 150)
		throw Form::GradeTooLowException();
	this->sign = false;
}

Form::Form(const Form &other) : name(other.name), forSigned(other.forSigned), forExecute(other.forExecute)
{
	if (this->getForExecute() < 1 || this->getForSigned() < 1)
		throw Form::GradeTooHighException();
	if (this->getForExecute() > 150 || this->getForSigned() > 150)
		throw Form::GradeTooLowException();
	this->sign = other.sign;
}

Form::~Form()
{
}

// --------------- OPERATORS ---------------

std::ostream& operator<<(std::ostream &os, const Form obj)
{
	os<<obj.getForExecute()<<" and "<<obj.getForSigned()<<" and "<<obj.getName()<<" and "<<obj.getSign();
	return(os);
}

const Form& Form::operator=(const Form &other)
{
	if (this == &other)
		return(*this);
	this->sign = other.sign;
	return(*this);
}

// --------------- GETTERS ---------------

std::string Form::getName() const
{
	return(this->name);
}

bool Form::getSign() const
{
	return(this->sign);
}

int	Form::getForSigned() const
{
	return(this->forSigned);
}

int	Form::getForExecute() const
{
	return(this->forExecute);
}

// --------------- FUNCTIONS ---------------

void	Form::beSigned(Bureaucrat Jo)
{
	if (Jo.GetGrade() <= this->forSigned)
		this->sign = true;
	else
		throw Form::GradeTooLowException();
}
