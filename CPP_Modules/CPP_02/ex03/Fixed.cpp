/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:30:33 by mbiagi            #+#    #+#             */
/*   Updated: 2025/08/18 11:35:41 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"

//----------------- Constructors and Destructors -----------------

Fixed::Fixed()
{
	// std::cout<<"Default constructor called"<<std::endl;
	this->value = 0;
}

Fixed::Fixed(const int n)
{
	// std::cout<<"Int constructor called"<<std::endl;
	this->setRawBits(n << bits);
}

Fixed::Fixed(const float n)
{
	// std::cout<<"Float constructor called"<<std::endl;
	this->setRawBits((int)roundf(n * (1 << bits)));
}

Fixed::Fixed(const Fixed &other)
{
	// std::cout<<"Copy constructor called"<<std::endl;
	this->value = other.value;
}

Fixed::~Fixed()
{
	// std::cout<<"Destructor called"<<std::endl;
}

//----------------- Implemented Functions -----------------

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

Fixed&	Fixed::min(Fixed &num1, Fixed &num2)
{
	if (num1.value < num2.value)
		return(num1);
	else
		return(num2);
}
const Fixed&	Fixed::min(const Fixed &num1, const Fixed &num2)
{
	if (num1.value < num2.value)
		return(num1);
	else
		return(num2);
}

Fixed&	Fixed::max(Fixed &num1, Fixed &num2)
{
	if (num1.value > num2.value)
		return(num1);
	else
		return(num2);
}

const Fixed&	Fixed::max(const Fixed &num1, const Fixed &num2)
{
	if (num1.value > num2.value)
		return(num1);
	else
		return(num2);
}


//----------------- Operators -----------------

const Fixed& Fixed::operator=(const Fixed &other)
{
	
	// std::cout<<"Copy assigment operator called"<<std::endl;
	if (this == &other)
		return(*this);
	this->value = other.getRawBits();
	return(*this);
}

bool Fixed::operator>(const Fixed &other)
{
	if (this->toFloat() > other.toFloat())
		return(true);
	else
		return(false);
}

bool Fixed::operator<(const Fixed &other)
{
	if (this->toFloat() < other.toFloat())
		return(true);
	else
		return(false);
}

bool Fixed::operator>=(const Fixed &other)
{
	if (this->toFloat() >= other.toFloat())
		return(true);
	else
		return(false);
}

bool Fixed::operator<=(const Fixed &other)
{
	if (this->toFloat() <= other.toFloat())
		return(true);
	else
		return(false);
}

bool Fixed::operator==(const Fixed &other)
{
	if (this->toFloat() == other.toFloat())
		return(true);
	else
		return(false);
}

bool Fixed::operator!=(const Fixed &other)
{
	if (this->toFloat() != other.toFloat())
		return(true);
	else
		return(false);
}

Fixed Fixed::operator+(const Fixed &other)
{
	Fixed	sum;

	sum.value = this->value + other.value;
	return(sum);
}

Fixed Fixed::operator-(const Fixed &other)
{
	Fixed	sum;

	sum.value = this->value - other.value;
	return(sum);
}

Fixed Fixed::operator*(const Fixed &other)
{
	return((const Fixed)Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other)
{
	return((const Fixed)Fixed(this->toFloat() / other.toFloat()));
}

Fixed& Fixed::operator++()
{
	this->value++;
	return(*this);
}

Fixed& Fixed::operator--()
{
	this->value--;
	return(*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	temp = *this;

	this->value++;
	return(temp);
}

Fixed Fixed::operator--(int)
{
	Fixed	temp = *this;

	this->value--;
	return(temp);
}

std::ostream& operator<<(std::ostream &out, const Fixed &c)
{
    std::cout << c.toFloat();
    return out;
}

//----------------- Getters and Setters -----------------

int		Fixed::getRawBits(void) const
{
	// std::cout<<"getRawBits member function called"<<std::endl;
	return(this->value);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}
