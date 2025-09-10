#include "Bureaucrat.hpp"

// --------------- CONSTRUCTORS AND DESTRUCTOR ---------------

Bureaucrat::Bureaucrat(const std::string name, const int grade) : name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name)
{
	if (other.grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (other.grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = other.grade;
}

Bureaucrat::~Bureaucrat()
{
}

// --------------- OPERATORS ---------------

const Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this == &other)
		return(*this);
	this->grade = other.grade;
	return(*this);
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat obj)
{
	os<<obj.GetName()<<", bureaucrat grade "<<obj.GetGrade();
	return(os);
}

// --------------- GETTERS ---------------

std::string Bureaucrat::GetName() const
{
	return(this->name);
}

int Bureaucrat::GetGrade() const
{
	return(this->grade);
}

// --------------- FUNCTION ---------------

void Bureaucrat::incrementGrade()
{
	this->grade--;
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
	this->grade++;
	if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}
