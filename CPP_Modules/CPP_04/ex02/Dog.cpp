#include "Dog.hpp"

//------------ CONSTRUCTORS AND DESTRUCTOR ------------

Dog::Dog(): Animal()
{
    brain = new Brain;
    type = "dog";
    std::cout<<"Dog constructor called"<<std::endl;
}

Dog::Dog(const Dog &other): Animal()
{
    this->type = other.type;
    this->brain = new Brain(*other.brain);
    std::cout<<"Dog copy constructor called"<<std::endl;
}

Dog::~Dog()
{
    std::cout<<"Dog destructor called"<<std::endl;
    delete (brain);
}

//------------ OPERATOR ------------

const Dog& Dog::operator=(const Dog &other)
{
    if (this == &other)
        return (*this);
    this->type = other.type;
    this->brain = other.brain;
    return (*this);
}

void Dog::makeSound() const
{
    std::cout<<"bau bau"<<std::endl;
}
