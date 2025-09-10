#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	name;
	bool				sign;
	const int			forSigned;
	const int			forExecute;
public:
	Form(std::string name, int toSign, int toEx);
	Form(const Form &other);
	~Form();

	const Form &operator=(const Form &other);

	std::string	getName() const;
	bool		getSign() const;
	int			getForSigned() const;
	int			getForExecute() const;

	void		beSigned(const Bureaucrat Jo);

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

#endif