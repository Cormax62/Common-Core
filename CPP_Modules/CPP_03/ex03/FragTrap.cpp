/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:59:07 by mbiagi            #+#    #+#             */
/*   Updated: 2025/08/19 14:24:13 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//----------- CONSTRUCTOR AND DESTRUCTOR -----------

FragTrap::FragTrap(): ClapTrap("marco")
{
	this->setEnergyPoint(100);
	this->setHitPoint(100);
	this->setAttckDamage(30);
	std::cout<<"fragtrap constructing "<<getName()<<" 'il dio dell'arena'"<<std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->setEnergyPoint(100);
	this->setHitPoint(100);
	this->setAttckDamage(30);
	std::cout<<"fragtrap constructing "<<getName()<<" 'il dio dell'arena'"<<std::endl;
}

FragTrap::FragTrap(FragTrap &other): ClapTrap(other.getName())
{
	this->setEnergyPoint(other.getEnergyPoint());
	this->setHitPoint(other.getHitPoint());
	this->setAttckDamage(other.getAttckDamage());
	std::cout<<"fragtrap constructing "<<getName()<<" 'il dio dell'arena'"<<std::endl;
}

FragTrap::~FragTrap()
{
	std::cout<<"fragtrap destroing "<<getName()<<" 'il dio dell'arena'"<<std::endl;
}

//----------- OPERATOR -----------

const FragTrap& FragTrap::operator=(const FragTrap &other)
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

void	FragTrap::highFiveGuys() const
{
	std::cout<<getName()<<" highfived those two losers"<<std::endl;
}
