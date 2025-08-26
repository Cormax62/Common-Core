#include "Brain.hpp"

//------------ CONSTRUCTORS AND DESTRUCTOR ------------

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = i;
	}
}

Brain::Brain(const Brain &other)
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = other.ideas[i];
	}
}

Brain::~Brain()
{
}

//------------ OPERATOR ------------

const Brain& Brain::operator=(const Brain &other)
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = other.ideas[i];
	}
	return (*this);
}