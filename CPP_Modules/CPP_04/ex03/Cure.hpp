#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure: public AMateria
{
private:
	
public:
	Cure();
	Cure(const Cure &other);
	~Cure();

	const Cure	&operator=(const Cure &other);
	void		use(ICharacter& target);
	AMateria*	clone() const;
};

#endif