#include "PresidentialPardonForm.hpp"

// --------------- CONSTRUCTORS AND DESTRUCTOR ---------------

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon", 25, 5)
{
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm("Presidential Pardon", 25, 5)
{
	this->target = other.target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

// --------------- OPERTATOR ---------------

const PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this == &other)
		return(*this);
	this->target = other.target;
	return(*this);
}

// --------------- FUNCTION ---------------

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (this->getSign() == false)
		throw PresidentialPardonForm::FormNotSiged();
	else if (executor.GetGrade() > this->getForExecute())
		throw AForm::GradeTooLowException();
	else
		std::cout<<this->target<<" has been pardoned by Zaphod Beeblebrox."<<std::endl;
}
