/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 10:26:51 by mbiagi            #+#    #+#             */
/*   Updated: 2025/08/08 11:32:46 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

bool bsp( const Point a, const Point b, const Point c, const Point point)
{
	float	Tarea;
	float	A1;
	float	A2;
	float	A3;

	Tarea = 0.5 * std::abs(a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())
			+ b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())
			+ c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()));

	A1 = 0.5 * std::abs(point.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())
			+ b.getX().toFloat() * (c.getY().toFloat() - point.getY().toFloat())
			+ c.getX().toFloat() * (point.getY().toFloat() - b.getY().toFloat()));

	A2 = 0.5 * std::abs(a.getX().toFloat() * (point.getY().toFloat() - c.getY().toFloat())
			+ point.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())
			+ c.getX().toFloat() * (a.getY().toFloat() - point.getY().toFloat()));

	A3 = 0.5 * std::abs(a.getX().toFloat() * (b.getY().toFloat() - point.getY().toFloat())
			+ b.getX().toFloat() * (point.getY().toFloat() - a.getY().toFloat())
			+ point.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()));

	return (A1 + A2 + A3 == Tarea);
}
