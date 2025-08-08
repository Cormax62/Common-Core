/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:30:59 by mbiagi            #+#    #+#             */
/*   Updated: 2025/08/08 13:49:51 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a(10.10f);
	Fixed b(2);
	Fixed c(a);

	// + - / *
	std::cout << "a + b: " << a + b << std::endl;
	std::cout << "a - b: " << a - b << std::endl;
	std::cout << "a / b: " << a / b << std::endl;
	std::cout << "a * b: " << a * b << std::endl << std::endl;
	
	// < > <= >= == !=
	std::cout << "a < b: " << (a < b ? "true" : "false") << std::endl;
	std::cout << "a > b: " << (a > b ? "true" : "false") << std::endl;
	std::cout << "a <= b: " << (a <= b ? "true" : "false") << std::endl;
	std::cout << "a >= b: " << (a >= b ? "true" : "false") << std::endl;
	std::cout << "a == b: " << (a == b ? "true" : "false") << std::endl;
	std::cout << "a != b: " << (a != b ? "true" : "false") << std::endl << std::endl;

	// ++var e var++
	std::cout << "a: " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl << std::endl;
	
	// --var e var--
	std::cout << "a: " << a << std::endl;
	std::cout << "--a: " << --a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a--: " << a-- << std::endl;
	std::cout << "a: " << a << std::endl << std::endl;

	std::cout << "min: " << Fixed::min(a, b) << std::endl;
	std::cout << "max: " << Fixed::max(a, b) << std::endl;
	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << Fixed::max( a, b ) << std::endl
	return 0;
}