/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:30:59 by mbiagi            #+#    #+#             */
/*   Updated: 2025/08/08 13:59:55 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
	{
		const Point a;
		const Point b(10, 0);
		const Point c(0, 10);
		const Point point(1, 1);

		if (bsp(a, b, c, point) == true)
			std::cout << "TRUE" << std::endl;
		else
			std::cout << "FALSE" << std::endl;
	}
	{
		Point a(-1.5, 3);
		Point b(2.5, 2.5);
		Point c(-1, -2);
		Point point(2.45, 2.4);
		if (bsp(a, b, c, point) == true)
			std::cout << "TRUE" << std::endl;
		else
			std::cout << "FALSE" << std::endl;
	}
	return (0);
}