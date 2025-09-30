#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <list>
# include <algorithm>

template <typename T>
int easyfind(T container, int num);

class NoOccurrence : public std::exception
{
public:
	const char *what() const throw() {
		return("No occurrence was found");
	}
};

# include "easyfind.tpp"

#endif