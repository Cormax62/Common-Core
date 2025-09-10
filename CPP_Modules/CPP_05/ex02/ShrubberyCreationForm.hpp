#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string target;
public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();

	const ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

	void	execute(const Bureaucrat &executor) const;

	class FormNotSiged : public std::exception
	{
	public:
		const char *what() const throw(){
			return ("form not signed yet");
		}
	};

	class FileNotCreated : public std::exception
	{
	public:
		const char *what() const throw(){
			return ("form not signed yet");
		}
	};
};

#endif