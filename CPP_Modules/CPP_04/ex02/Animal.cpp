#include "Animal.hpp"

//------------ CONSTRUCTORS AND DESTRUCTOR ------------

Animal::Animal()
{
    type = "animal";
    std::cout<<"Animal constructor called"<<std::endl;
}

Animal::Animal(const Animal &other)
{
    this->type = other.type;
    std::cout<<"Animal copy constructor called"<<std::endl;
}

Animal::~Animal()
{
    std::cout<<"Animal destructor called"<<std::endl;
}

//------------ OPERATOR ------------

const Animal& Animal::operator=(const Animal &other)
{
    if (this == &other)
        return (*this);
    this->type = other.type;
    return (*this);
}

//------------ FUNCTION ------------

// void    Animal::makeSound() const
// {
//     std::cout<<"'indistint noise'"<<std::endl;
// }

std::string Animal::getType() const
{
    return(this->type);
}
