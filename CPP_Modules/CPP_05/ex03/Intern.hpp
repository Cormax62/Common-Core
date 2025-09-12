#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern
{
private:
	
public:
	Intern();
	Intern(const Intern &other);
	~Intern();

	const Intern &operator=(const Intern &other);

	AForm *makeForm(std::string name, std::string target);

	class BadName : public std::exception
	{
	public:
		const char *what() const throw(){
			return ("unexisting form name");
		}
	};
};

#endif