#include "Cat.hpp"

//------------ CONSTRUCTORS AND DESTRUCTOR ------------

Cat::Cat(): Animal()
{
    type = "Cat";
    std::cout<<"Cat constructor called"<<std::endl;
}

Cat::Cat(const Cat &other): Animal()
{
    this->type = other.type;
    std::cout<<"Cat copy constructor called"<<std::endl;
}

Cat::~Cat()
{
    std::cout<<"Cat destructor called"<<std::endl;
}

//------------ OPERATOR ------------

const Cat& Cat::operator=(const Cat &other)
{
    if (this == &other)
        return (*this);
    this->type = other.type;
    return (*this);
}

void Cat::makeSound() const
{
    std::cout<<"meow meow"<<std::endl;
}