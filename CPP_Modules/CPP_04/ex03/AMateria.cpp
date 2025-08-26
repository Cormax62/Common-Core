#include "AMateria.hpp"

//------------ CONSTRUCTORS AND DESTRUCTOR ------------

AMateria::AMateria()
{
}

AMateria::AMateria(std::string const &type)
{
	this->type = type;
}

AMateria::AMateria(const AMateria &other)
{
	this->type = other.type;
}

AMateria::~AMateria()
{
}

//------------ OPERATOR ------------

const AMateria& AMateria::operator=(const AMateria &other)
{
	if (this == &other)
		return (*this);
	this->type = other.type;
	return(*this);
}

//------------ GETTER ------------

const std::string&	AMateria::getType() const
{
	return(this->type);
}

//------------ FUNCTION ------------

void AMateria::use(ICharacter& target)
{
	(void)target;
}