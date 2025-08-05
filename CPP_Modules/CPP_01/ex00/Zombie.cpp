/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:43:33 by mbiagi            #+#    #+#             */
/*   Updated: 2025/08/05 12:39:25 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie::Zombie(std::string name)
{
	this->name = name;
	return;
}

Zombie::~Zombie()
{
	std::cout<<name<<std::endl;
	return;
}

void Zombie::announce() const
{
	std::cout<<name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}
