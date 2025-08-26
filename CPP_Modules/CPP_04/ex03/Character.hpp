#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character: public ICharacter
{
private:
	std::string name;
	AMateria	*slot[4];
	AMateria	*floor[4];
public:
	Character(std::string name);
	Character(const Character &other);
	~Character();

	const Character &operator=(const Character &other);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif