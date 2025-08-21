#include "WrongAnimal.hpp"

//------------ CONSTRUCTORS AND DESTRUCTOR ------------

WrongAnimal::WrongAnimal()
{
    type = "Wronganimal";
    std::cout<<"WrongAnimal constructor called"<<std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    this->type = other.type;
    std::cout<<"WrongAnimal copy constructor called"<<std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout<<"WrongAnimal destructor called"<<std::endl;
}

//------------ OPERATOR ------------

const WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
    if (this == &other)
        return (*this);
    this->type = other.type;
    return (*this);
}

//------------ FUNCTION ------------

void    WrongAnimal::makeSound() const
{
    std::cout<<"'indistint wrong noise'"<<std::endl;
}

std::string WrongAnimal::getType() const
{
    return(this->type);
}
