#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
protected:
    std::string type;
public:
    Animal();
    Animal(const Animal &other);
    virtual ~Animal();

    const Animal &operator=(const Animal &other);
    
    void virtual        makeSound() const;
    std::string         getType() const;
};

#endif