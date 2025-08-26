#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat: public Animal
{
private:
    
public:
    Cat();
    Cat(const Cat &other);
    ~Cat();

    const Cat &operator=(const Cat &other);
    void    makeSound() const;
};

#endif