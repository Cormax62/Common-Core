#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* animal = new Animal();
	const Animal* Dog = new Dog();
	const Animal* Cat = new Cat();
	const WrongAnimal* wronganimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << Dog->getType() << " " << std::endl;
	std::cout << Cat->getType() << " " << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;
	Cat->makeSound();
	Dog->makeSound();
	animal->makeSound();
	wrongCat->makeSound();
	wronganimal->makeSound();
	delete(animal);
	delete(Dog);
	delete(Cat);
	delete(wronganimal);
	delete(wrongCat);
	return 0;
}
