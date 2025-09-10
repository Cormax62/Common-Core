#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <ostream>
# include <string.h>
# include <stdexcept>
# include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	const std::string	name;
	int					grade;
public:
	Bureaucrat(const std::string name, const int grade);
	Bureaucrat(const Bureaucrat &other);
	~Bureaucrat();

	const Bureaucrat &operator=(const Bureaucrat &other);

	std::string GetName() const;
	int			GetGrade() const;

	void		incrementGrade();
	void		decrementGrade();
	void		signForm(Form doc);

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw(){
			return ("grade too high");
		}
	};
	
	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw(){
			return ("grade too low");
		}
	};
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat obj);

#endif