/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:42:35 by mbiagi            #+#    #+#             */
/*   Updated: 2025/08/05 12:41:58 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.h"

HumanB::HumanB(std::string name) : name(name)
{
	weapon = NULL;
}

HumanB::~HumanB()
{
	return;
}

void	HumanB::attack()
{
	std::cout<<name<<" attack with their "<<weapon->getType()<<std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
