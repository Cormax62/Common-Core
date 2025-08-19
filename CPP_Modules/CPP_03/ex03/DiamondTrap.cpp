/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:00:25 by mbiagi            #+#    #+#             */
/*   Updated: 2025/08/19 14:23:50 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

//----------- CONSTRUCTOR AND DESTRUCTOR -----------

DiamondTrap::DiamondTrap(): ClapTrap("diamante"), ScavTrap("diamante"), FragTrap("diamante")
{
	this->name = "diamante";
	ClapTrap::setName(name + "_clap_trap");
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	this->name = name;
	ClapTrap::setName(name + "_clap_trap");
}

DiamondTrap::DiamondTrap(DiamondTrap &other): ClapTrap(other.name), ScavTrap(other.name), FragTrap(other.name)
{
	ClapTrap::setName(name + "_clap_trap");
}

DiamondTrap::~DiamondTrap()
{
}

//----------- OPERATOR -----------

const DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this == &other)
		return (*this);
	this->name = other.name;
	this->setName(other.getName());
	this->setEnergyPoint(other.getEnergyPoint());
	this->setHitPoint(other.getHitPoint());
	this->setAttckDamage(other.getAttckDamage());
	return(*this);
}

//----------- FUNCTIONS -----------

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI() const
{
	std::cout<<"name: "<<name<<std::endl;
	std::cout<<"ClapTrap name: "<<ClapTrap::getName()<<std::endl;
}
