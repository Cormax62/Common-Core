#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	name;
	bool				sign;
	const int			forSigned;
	const int			forExecute;
public:
	AForm(std::string name, int toSign, int toEx);
	AForm(const AForm &other);
	virtual ~AForm();

	const AForm 	&operator=(const AForm &other);

	std::string		getName() const;
	bool			getSign() const;
	int				getForSigned() const;
	int				getForExecute() const;

	void			beSigned(const Bureaucrat Jo);
	virtual void	execute(const Bureaucrat &executor) const = 0;

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