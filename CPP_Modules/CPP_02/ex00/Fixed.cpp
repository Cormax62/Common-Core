/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:30:33 by mbiagi            #+#    #+#             */
/*   Updated: 2025/08/06 15:03:47 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"

Fixed::Fixed()
{
	std::cout<<"Default constructor called"<<std::endl;
	this->value = 0;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout<<"Copy constructor called"<<std::endl;
	*this = other;
}

Fixed::~Fixed()
{
	std::cout<<"Destructor called"<<std::endl;
}

const Fixed& Fixed::operator=(const Fixed &other)
{
	
	std::cout<<"Copy assigment operator called"<<std::endl;
	if (this == &other)
		return(*this);
	this->value = other.getRawBits();
	return(*this);
}

int		Fixed::getRawBits(void) const
{
	std::cout<<"getRawBits member function called"<<std::endl;
	return(this->value);
}

void	Fixed::setRawBits(int const raw)
{	
	std::cout<<"setRawBits member function called"<<std::endl;
	this->value = raw;
}
