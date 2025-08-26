#include "Ice.hpp"

//------------ CONSTRUCTORS AND DESTRUCTOR ------------

Ice::Ice(): AMateria("ice")
{
}

Ice::Ice(const Ice &other)
{
	this->type = other.type;
}

Ice::~Ice()
{
}

//------------ OPERATOR ------------

const Ice& Ice::operator=(const Ice &other)
{
	if (this == &other)
		return(*this);
	this->type = other.type;
	return(*this);
}

//------------ FUNCTION ------------

void Ice::use(ICharacter& target)
{
	std::cout<<"* shoots an ice bolt at "<<target.getName()<<" *"<<std::endl;
}

AMateria*	Ice::clone() const
{
	return(new Ice(*this));
}