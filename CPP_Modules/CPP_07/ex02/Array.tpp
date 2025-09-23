#include "Array.hpp"

// ----------------- CONSTRUCTORS AND DESTRUCTOR -----------------

template <typename T>
Array<T>::Array() : a(NULL)
{
}

template <typename T>
Array<T>::Array(const Array<T>& other)
{
	this->len = other.len;
	this->a = new T[other.size()];
	for (int i = 0; i < other.size(); i++)
	{
		a[i] = other.a[i];
	}
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->a = new T[n];
	this->len = n;
}

template <typename T>
Array<T>::~Array()
{
	delete[] (a);
}
//  ----------------- OPERATORS -----------------

template <typename T>
T& Array<T>::operator[](const int n)
{
	if (n > this->size())
		throw Array::OutOfBounds();
	return((this->a[n]));
}

template <typename T>
const Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if (this == &other)
		return(*this);
	delete[] (this->a);
	this->a = new T[other.size()];
	this->len = other.len;
	for (int i = 0; i < other.size(); i++)
	{
		a[i] = other.a[i];
	}
	return(*this);
}

// ----------------- FUNCTION -----------------

template <typename T>
int Array<T>::size(void) const
{
	return(this->len);
}
