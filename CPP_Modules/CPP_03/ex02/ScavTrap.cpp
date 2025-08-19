/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:53:08 by mbiagi            #+#    #+#             */
/*   Updated: 2025/08/19 14:18:11 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//----------- CONSTRUCTOR AND DESTRUCTOR -----------

ScavTrap::ScavTrap(): ClapTrap("mavi")
{
	this->setEnergyPoint(50);
	this->setHitPoint(100);
	this->setAttckDamage(20);
	std::cout<<"scavtrap constructing "<<getName()<<std::endl;
}

ScavTrap::ScavTrap(ScavTrap &other): ClapTrap(other.getName())
{
	this->setEnergyPoint(other.getEnergyPoint());
	this->setHitPoint(other.getHitPoint());
	this->setAttckDamage(other.getAttckDamage());
	std::cout<<"scavtrap constructing "<<getName()<<std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->setEnergyPoint(50);
	this->setHitPoint(100);
	this->setAttckDamage(20);
	std::cout<<"scavtrap constructing "<<getName()<<std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout<<"scavtrap destroing "<<getName()<<std::endl;
}

//----------- OPERATOR -----------

const ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	if (this == &other)
		return (*this);
	this->setName(other.getName());
	this->setEnergyPoint(other.getEnergyPoint());
	this->setHitPoint(other.getHitPoint());
	this->setAttckDamage(other.getAttckDamage());
	return(*this);
}

//----------- FUNCTIONS -----------

void ScavTrap::attack(const std::string& target)
{
	if (getEnergyPoint() > 0)
	{
		std::cout<<getName()<<" punched "<<target<<" so hard it caused "
		<<getAttckDamage()<<" points of damage"<<std::endl;
		setEnergyPoint(getEnergyPoint() - 1);
	}
	else
		std::cout<<getName()<<" is too tired to do anything, maybe he'll collapse right here on the spot"
		<<std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout<<getName()<<" is now in gatekeeping mode"<<std::endl;
}
