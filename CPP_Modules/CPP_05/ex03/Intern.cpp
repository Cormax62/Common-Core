#include "Intern.hpp"

// --------------- CONSTRUCTORS AND DESTRUCTOR ---------------

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
	(void) other;
}

Intern::~Intern()
{
}

// --------------- OPERATOR ---------------

const Intern& Intern::operator=(const Intern& other)
{
	if (this == &other)
		return( *this);
	return( *this);
}

// --------------- FUNCTION ---------------

AForm* Intern::makeForm(std::string name, std::string target)
{
	AForm *doc;

	if (name != "robotomy request" && name != "presidential pardon" && name != "shrubbery creation")
		throw Intern::BadName();
	switch (name.length())
	{
	case 16:
		doc = new RobotomyRequestForm(target);
		return (doc);
		break;
	case 18:
		doc = new ShrubberyCreationForm(target);
		return (doc);
		break;
	case 19:
		doc = new PresidentialPardonForm(target);
		return (doc);
		break;
	}
	return(NULL);
}
