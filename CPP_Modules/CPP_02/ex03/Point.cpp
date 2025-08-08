/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:28:55 by mbiagi            #+#    #+#             */
/*   Updated: 2025/08/08 11:27:40 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//----------------- Constructors and Destructors -----------------

Point::Point(): x(0), y(0)
{
}

Point::Point(const Point &other)
{
	*this = other;
}

Point::Point(const float x, const float y)
{
	this->x.setRawBits(x * (1 << this->bits));
	this->y.setRawBits(y * (1 << this->bits));
}

Point::~Point()
{
}

//----------------- Operators -----------------

const Point& Point::operator=(const Point &other)
{
	if (this != &other)
	{
		this->x = other.x;
		this->y = other.y;
	}
	return (*this);
}

//----------------- Getters -----------------

Fixed Point::getX(void) const
{
	return (this->x);
}

Fixed Point::getY(void) const
{
	return (this->y);
}
