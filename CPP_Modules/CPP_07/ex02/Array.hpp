#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
private:
	T				*a;
	unsigned int	len;
public:
	Array();
	Array(const Array& other);
	Array(unsigned int n);
	~Array();

	const Array& operator=(const Array& other);
	// operator[]

	int 	size(void) const;
	T&	operator[](const int n);

	class OutOfBounds : public std::exception
	{
	public:
		const char *what() const throw(){
			return ("grade too high");
		}
	};
	
};

# include "Array.tpp"

#endif