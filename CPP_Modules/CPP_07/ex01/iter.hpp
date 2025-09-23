#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void func(T &array)
{
	std::cout<<" "<<array;
}

template <typename T, typename F>
void	iter(T array[], int lenght, F function)
{
	for (int i = 0; i < lenght; i++)
	{
		function(array[i]);
	}
}

#endif