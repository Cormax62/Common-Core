/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:08:02 by mbiagi            #+#    #+#             */
/*   Updated: 2025/08/19 11:32:58 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"

//----------- CONSTRUCTOR AND DESTRUCTOR -----------

ClapTrap::ClapTrap()
{
	this->name = "franci";
	this->attckDamage = 20;
	this->energyPoint = 30;
	this->hitPoint = 100;
	std::cout<<"claptrap constructing "<<name<<std::endl;
}

ClapTrap::ClapTrap(ClapTrap &other)
{
	this->attckDamage = other.attckDamage;
	this->energyPoint = other.energyPoint;
	this->hitPoint = other.hitPoint;
	this->name = other.name;
	std::cout<<"claptrap constructing "<<name<<std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->attckDamage = 20;
	this->energyPoint = 30;
	this->hitPoint = 100;
	std::cout<<"claptrap constructing "<<name<<std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout<<"claptrap destroing "<<name<<std::endl;
}

//----------- OPERATOR -----------

const ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	if (this == &other)
		return (*this);
	this->attckDamage = other.attckDamage;
	this->energyPoint = other.energyPoint;
	this->hitPoint = other.hitPoint;
	this->name = other.name;
	return(*this);
}

//----------- FUNCTIONS -----------

void	ClapTrap::attack(const std::string& target)
{
	if (this->energyPoint > 0)
	{
		std::cout<<this->name<<" punched "<<target<<" so hard it caused "
		<<this->attckDamage<<" points of damage"<<std::endl;
		this->energyPoint--;
	}
	else
		std::cout<<this->name<<" is too tired to do anything, maybe he'll collapse right here on the spot"
		<<std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoint <= 0)
	{
		std::cout<<this->name<<" is already dead"<<std::endl;
		return;
	}
	this->hitPoint -= amount;
	if (this->hitPoint > 0)
		std::cout<<this->name<<" took "<<amount<<" of danage, but he survived"<<std::endl;
	else
		std::cout<<this->name<<" just died..."<<std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoint <= 0)
	{
		std::cout<<this->name<<" is already dead"<<std::endl;
		return;
	}
	this->hitPoint += amount;
	std::cout<<this->name<<" regained "<<amount<<" hit point"<<std::endl;
}

//----------- GETTERS AND SETTERS -----------

std::string	ClapTrap::getName() const
{
	return(this->name);
}

int			ClapTrap::getHitPoint() const
{
	return(this->hitPoint);
}

int			ClapTrap::getEnergyPoint() const
{
	return(this->energyPoint);
}

int			ClapTrap::getAttckDamage() const
{
	return(this->attckDamage);
}

void	ClapTrap::setName(std::string name)
{
	this->name = name;
}

void	ClapTrap::setHitPoint(int n)
{
	this->hitPoint = n;
}

void	ClapTrap::setEnergyPoint(int n)
{
	this->energyPoint = n;
}

void	ClapTrap::setAttckDamage(int n)
{
	this->attckDamage = n;
}
