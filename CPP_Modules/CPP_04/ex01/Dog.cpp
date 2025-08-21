#include "Dog.hpp"

//------------ CONSTRUCTORS AND DESTRUCTOR ------------

Dog::Dog(): Animal()
{
    type = "dog";
    std::cout<<"Dog constructor called"<<std::endl;
}

Dog::Dog(const Dog &other): Animal()
{
    this->type = other.type;
    std::cout<<"Dog copy constructor called"<<std::endl;
}

Dog::~Dog()
{
    std::cout<<"Dog destructor called"<<std::endl;
}

//------------ OPERATOR ------------

const Dog& Dog::operator=(const Dog &other)
{
    if (this == &other)
        return (*this);
    this->type = other.type;
    return (*this);
}

void Dog::makeSound() const
{
    std::cout<<"bau bau"<<std::endl;
}
