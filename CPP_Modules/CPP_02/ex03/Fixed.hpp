/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:57:43 by mbiagi            #+#    #+#             */
/*   Updated: 2025/08/08 13:56:34 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int					value;
	static const int	bits = 8;
public:
	Fixed();
	Fixed(const int n);
	Fixed(const float n);
	Fixed(const Fixed &other);
	~Fixed();
	
	float				toFloat( void ) const;
	int					toInt( void ) const;
	int					getRawBits(void) const;
	void				setRawBits(int const raw);

	static Fixed		&min(Fixed &num1, Fixed &num2);
	static Fixed		&max(Fixed &num1, Fixed &num2);
	static const Fixed	&min(const Fixed &num1, const Fixed &num2);
	static const Fixed	&max(const Fixed &num1, const Fixed &num2);
	
	const Fixed 		&operator=(const Fixed &other);
	bool 				operator<(const Fixed &other);
	bool 				operator>(const Fixed &other);
	bool 				operator>=(const Fixed &other);
	bool 				operator<=(const Fixed &other);
	bool 				operator==(const Fixed &other);
	bool 				operator!=(const Fixed &other);
	Fixed		 		operator+(const Fixed &other);
	Fixed		 		operator-(const Fixed &other);
	Fixed		 		operator*(const Fixed &other);
	Fixed		 		operator/(const Fixed &other);
	Fixed				&operator++();
	Fixed				&operator--();
	Fixed				operator++(int);
	Fixed				operator--(int);
};

std::ostream	&operator<<(std::ostream &out, const Fixed &c);

#endif