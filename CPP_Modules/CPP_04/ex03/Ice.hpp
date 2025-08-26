#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice: public AMateria
{
private:
	
public:
	Ice();
	Ice(const Ice &other);
	~Ice();

	const Ice	&operator=(const Ice &other);
	void		use(ICharacter& target);
	AMateria*	clone() const;
};

#endif