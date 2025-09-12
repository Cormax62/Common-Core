#include "AForm.hpp"

// --------------- CONSTRUCTORS AND DESTRUCTOR ---------------

AForm::AForm(std::string name, int toSign, int toEx) : name(name), forSigned(toSign), forExecute(toEx)
{
	if (this->getForExecute() < 1 || this->getForSigned() < 1)
		throw AForm::GradeTooHighException();
	if (this->getForExecute() > 150 || this->getForSigned() > 150)
		throw AForm::GradeTooLowException();
	this->sign = false;
}

AForm::AForm(const AForm &other) : name(other.name), forSigned(other.forSigned), forExecute(other.forExecute)
{
	if (this->getForExecute() < 1 || this->getForSigned() < 1)
		throw AForm::GradeTooHighException();
	if (this->getForExecute() > 150 || this->getForSigned() > 150)
		throw AForm::GradeTooLowException();
	this->sign = other.sign;
}

AForm::~AForm()
{
}

// --------------- OPERATORS ---------------

std::ostream& operator<<(std::ostream &os, const AForm *obj)
{
	os<<obj->getForExecute()<<" and "<<obj->getForSigned()<<" and "<<obj->getName()<<" and "<<obj->getSign();
	return(os);
}

const AForm& AForm::operator=(const AForm &other)
{
	if (this == &other)
		return(*this);
	this->sign = other.sign;
	return(*this);
}

// --------------- GETTERS ---------------

std::string AForm::getName() const
{
	return(this->name);
}

bool AForm::getSign() const
{
	return(this->sign);
}

int	AForm::getForSigned() const
{
	return(this->forSigned);
}

int	AForm::getForExecute() const
{
	return(this->forExecute);
}

// --------------- FUNCTIONS ---------------

void	AForm::beSigned(Bureaucrat Jo)
{
	if (Jo.GetGrade() <= this->forSigned)
		this->sign = true;
	else
		throw AForm::GradeTooLowException();
}
