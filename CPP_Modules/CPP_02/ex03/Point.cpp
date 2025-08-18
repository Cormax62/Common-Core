/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:28:55 by mbiagi            #+#    #+#             */
/*   Updated: 2025/08/18 11:05:16 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//----------------- Constructors and Destructors -----------------

Point::Point(): x(0), y(0)
{
}

Point::Point(const Point &other): x(other.x), y(other.y)
{
}

Point::Point(const float x, const float y): x(x), y(y)
{
}

Point::~Point()
{
}

//----------------- Operators -----------------

const Point& Point::operator=(const Point &other)
{
	if (this != &other)
	{
		return (*this);
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
