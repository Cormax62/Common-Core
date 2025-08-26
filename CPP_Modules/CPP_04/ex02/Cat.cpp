#include "Cat.hpp"

//------------ CONSTRUCTORS AND DESTRUCTOR ------------

Cat::Cat(): Animal()
{
    brain = new Brain;
    type = "cat";
    std::cout<<"Cat constructor called"<<std::endl;
}

Cat::Cat(const Cat &other): Animal()
{
    this->type = other.type;
    this->brain = new Brain(*other.brain);
    std::cout<<"Cat copy constructor called"<<std::endl;
}

Cat::~Cat()
{
    std::cout<<"Cat destructor called"<<std::endl;
    delete (brain);
}

//------------ OPERATOR ------------

const Cat& Cat::operator=(const Cat &other)
{
    if (this == &other)
        return (*this);
    this->type = other.type;
    this->brain = other.brain;
    return (*this);
}

void Cat::makeSound() const
{
    std::cout<<"meow meow"<<std::endl;
}