/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:42:39 by mbiagi            #+#    #+#             */
/*   Updated: 2025/07/17 15:31:48 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"
# include "Phonebook.h"

class Phonebook
{
private:
	int			n;
	Contact	contacts[8];
public:
	Phonebook();
	~Phonebook();

	int	add();
	int	search();
};

#endif