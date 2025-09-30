#include "easyfind.hpp"

template <typename T>
int easyfind(T container, int num)
{
	typename T::iterator i;

	// for (i = container.begin(); i != container.end(); i++)
	// {
	// 	if (*i == num)
	// 		return *i;
	// }
	// throw NoOccurrence();
	// return false;
	i = std::find(container.begin(), container.end(), num);
	if (i == container.end())
		throw NoOccurrence();
	return *i;
}