/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:57:43 by mbiagi            #+#    #+#             */
/*   Updated: 2025/08/07 11:00:19 by mbiagi           ###   ########.fr       */
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
	
	float			toFloat( void ) const;
	int				toInt( void ) const;
	int				getRawBits(void) const;
	void			setRawBits(int const raw);
	const Fixed 	&operator=(const Fixed &other);
};

std::ostream	&operator<<(std::ostream &out, const Fixed &c);

#endif