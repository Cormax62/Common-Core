#ifndef PRESIDENTiALPARDONFORM_HPP
# define PRESIDENTiALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string	target;
public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	~PresidentialPardonForm();

	const PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

	void	execute(const Bureaucrat &executor) const;

	class FormNotSiged : public std::exception
	{
	public:
		const char *what() const throw(){
			return ("form not signed yet");
		}
	};
};

#endif