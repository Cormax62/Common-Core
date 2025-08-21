#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
private:
    
public:
    WrongCat();
    WrongCat(const WrongCat &other);
    ~WrongCat();

    const WrongCat &operator=(const WrongCat &other);
    void virtual    makeSound() const;
};

#endif