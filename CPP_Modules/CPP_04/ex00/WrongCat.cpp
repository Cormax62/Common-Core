#include "WrongCat.hpp"

//------------ CONSTRUCTORS AND DESTRUCTOR ------------

WrongCat::WrongCat(): WrongAnimal()
{
    type = "cat";
    std::cout<<"WrongCat constructor called"<<std::endl;
}

WrongCat::WrongCat(const WrongCat &other): WrongAnimal()
{
    this->type = other.type;
    std::cout<<"WrongCat copy constructor called"<<std::endl;
}

WrongCat::~WrongCat()
{
    std::cout<<"WrongCat destructor called"<<std::endl;
}

//------------ OPERATOR ------------

const WrongCat& WrongCat::operator=(const WrongCat &other)
{
    if (this == &other)
        return (*this);
    this->type = other.type;
    return (*this);
}

void WrongCat::makeSound() const
{
    std::cout<<"hiss hiss"<<std::endl;
}
