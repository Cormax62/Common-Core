#include "MateriaSource.hpp"

//------------ CONSTRUCTORS AND DESTRUCTOR ------------

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		slot[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int i = 0; i < 4; i++)
	{
		delete(this->slot[i]);
		this->slot[i] = other.slot[i];
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (slot[i])
		{
			delete(this->slot[i]);
			slot[i] = NULL;
		}
	}
}

//------------ OPERATOR ------------

const MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
	if (this == &other)
		return(*this);
	for (int i = 0; i < 4; i++)
	{
		if (this->slot[i])
			delete(this->slot[i]);
		this->slot[i] = other.slot[i];
	}
	return(*this);
}

//------------ FUNCTION ------------

void MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0; i < 4; i++)
	{
		if(slot[i] == NULL)
		{
			slot[i] = materia;
			return;
		}
	}
	return;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if(slot[i]->getType() == type)
		{
			return(slot[i]);
		}
	}
	return(0);
}