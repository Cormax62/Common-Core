/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:31:37 by mbiagi            #+#    #+#             */
/*   Updated: 2025/07/22 15:21:56 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"

Weapon::Weapon(std::string type)
{
	this->type = type;
	return;
}

Weapon::~Weapon()
{
	return;
}

void	Weapon::setType(const std::string &type)
{
	this->type = type;
	return;
}
std::string	Weapon::getType()
{
	return(this->type);
}
