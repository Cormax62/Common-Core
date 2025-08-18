/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:30:33 by mbiagi            #+#    #+#             */
/*   Updated: 2025/08/18 11:32:17 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"

Fixed::Fixed()
{
	std::cout<<"Default constructor called"<<std::endl;
	this->value = 0;
}

Fixed::Fixed(const int n)
{
	std::cout<<"Int constructor called"<<std::endl;
	this->setRawBits(n << bits);
}

Fixed::Fixed(const float n)
{
	std::cout<<"Float constructor called"<<std::endl;
	this->setRawBits((int)roundf(n * (1 << bits)));
}

Fixed::Fixed(const Fixed &other)
{
	std::cout<<"Copy constructor called"<<std::endl;
	this->value = other.value;
}

Fixed::~Fixed()
{
	std::cout<<"Destructor called"<<std::endl;
}

float	Fixed::toFloat(void) const
{
	float	ret = value >> bits;

	ret += (value % (1 * (1 << bits)) * (1.0 / (1 << bits)));
	return(ret);
}

int		Fixed::toInt(void) const
{
	return(value >> bits);
}

const Fixed& Fixed::operator=(const Fixed &other)
{
	
	std::cout<<"Copy assigment operator called"<<std::endl;
	if (this == &other)
		return(*this);
	this->value = other.getRawBits();
	return(*this);
}

std::ostream& operator<<(std::ostream &out, const Fixed &c)
{
    std::cout << c.toFloat();
    return out;
}

int		Fixed::getRawBits(void) const
{
	std::cout<<"getRawBits member function called"<<std::endl;
	return(this->value);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}
