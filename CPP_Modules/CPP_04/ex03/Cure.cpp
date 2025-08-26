#include "Cure.hpp"

//------------ CONSTRUCTORS AND DESTRUCTOR ------------

Cure::Cure(): AMateria("cure")
{
}

Cure::Cure(const Cure &other)
{
	this->type = other.type;
}

Cure::~Cure()
{
}

//------------ OPERATOR ------------

const Cure& Cure::operator=(const Cure &other)
{
	if (this == &other)
		return(*this);
	this->type = other.type;
	return(*this);
}

//------------ FUNCTIONS ------------

void Cure::use(ICharacter& target)
{
	std::cout<<"* heals "<<target.getName()<<" *"<<std::endl;
}

AMateria*	Cure::clone() const
{
	return(new Cure(*this));
}