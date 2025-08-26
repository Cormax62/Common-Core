# include "Character.hpp"

//------------ CONSTRUCTORS AND DESTRUCTOR ------------

Character::Character(std::string name)
{
	this->name = name;
	for (int i = 0; i < 4; i++)
	{
		slot[i] = NULL;
		floor[i] = NULL;
	}
}

Character::Character(const Character &other)
{
	this->name = other.name;
	for (int i = 0; i < 4; i++)
	{
		if(slot[i])
		{
			delete(slot[i]);
			slot[i] = NULL;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		this->slot[i] = other.slot[i]->clone();
		this->floor[i] = other.floor[i]->clone();
	}
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if(slot[i])
		{
			delete(slot[i]);
			slot[i] = NULL;
		}
		if(floor[i])
		{
			delete(floor[i]);
			floor[i] = NULL;
		}
	}
}

//------------ OPERATOR ------------

const Character& Character::operator=(const Character &other)
{
	if (this == &other)
		return(*this);
	this->name = other.name;
	for (int i = 0; i < 4; i++)
	{
		if(slot[i])
		{
			delete(slot[i]);
			slot[i] = NULL;
		}
		if(floor[i])
		{
			delete(floor[i]);
			floor[i] = NULL;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		this->slot[i] = other.slot[i]->clone();
		this->floor[i] = other.floor[i]->clone();
	}
	return(*this);
}

//------------ FUNCTIONS ------------

std::string const & Character::getName() const
{
	return(this->name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (slot[i] == NULL)
		{
			slot[i] = m->clone();
			return;
		}
	}
	return;
}

void Character::unequip(int idx)
{
	for (int i = 0; i < 4; i++)
	{
		if (floor[i])
		{
			floor[i] = slot[idx]->clone();
			delete(slot[idx]);
			slot[idx] = NULL;
			return;
		}
	}
	return;
}

void Character::use(int idx, ICharacter& target)
{
	slot[idx]->use(target);
}
