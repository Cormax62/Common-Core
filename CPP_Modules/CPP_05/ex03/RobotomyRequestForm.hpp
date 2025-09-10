#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string target;
public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	~RobotomyRequestForm();

	const RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

	void	execute(const Bureaucrat &executor) const;

	class FormNotSiged : public std::exception
	{
	public:
		const char *what() const throw(){
			return ("form not signed yet");
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw(){
			return ("robotomy failed");
		}
	};
};

#endif