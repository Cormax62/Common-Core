#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
const Animal animal;
const Dog dog;
const Cat cat;

std::cout << dog.getType() << " " << std::endl;
std::cout << cat.getType() << " " << std::endl;
cat.makeSound();
dog.makeSound();
animal.makeSound();
return 0;
}
