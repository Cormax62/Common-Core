/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:27:18 by mbiagi            #+#    #+#             */
/*   Updated: 2025/08/18 10:31:23 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "./Fixed.hpp"

class Point
{
private:
	const Fixed			x;
	const Fixed			y;
	static const int	bits = 8;
public:
	Point();
	Point(const Point &other);
	Point(const float x, const float y);
	~Point();

	Fixed	getX(void) const;
	Fixed	getY(void) const;
	
	const Point	&operator=(const Point &other);
	
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif