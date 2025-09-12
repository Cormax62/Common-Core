#include "RobotomyRequestForm.hpp"

// --------------- CONSTRUCTORS AND DESTRUCTOR ---------------

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", 72, 45)
{
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm("Robotomy Request", 72, 45)
{
	this->target = other.target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

// --------------- OPERATOR ---------------

const RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this == &other)
		return(*this);
	this->target = other.target;
	return(*this);
}

// --------------- FUNCTION ---------------

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (this->getSign() == false)
		throw RobotomyRequestForm::FormNotSiged();
	else if (executor.GetGrade() > this->getForSigned())
		throw RobotomyRequestForm::GradeTooLowException();
	else
		std::cout<<this->target<<" has beet robotomized succesfully 50% of the time."<<std::endl;
}
