/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:30:46 by mbiagi            #+#    #+#             */
/*   Updated: 2025/08/19 14:10:18 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	ClapTrap	franci("franci");
	ScavTrap	mavi;
	FragTrap	marco("marco");
	DiamondTrap	diamante("diamante");

	marco.attack(mavi.getName());
	mavi.takeDamage(marco.getAttckDamage());
	marco.attack(mavi.getName());
	mavi.takeDamage(marco.getAttckDamage());
	marco.attack(mavi.getName());
	mavi.takeDamage(marco.getAttckDamage());
	marco.attack(mavi.getName());
	mavi.takeDamage(marco.getAttckDamage());
	franci.takeDamage(marco.getAttckDamage());
	marco.attack(franci.getName());
	franci.takeDamage(marco.getAttckDamage());
	marco.attack(franci.getName());
	franci.takeDamage(marco.getAttckDamage());
	marco.attack(franci.getName());
	franci.takeDamage(marco.getAttckDamage());
	marco.attack(franci.getName());
	franci.takeDamage(marco.getAttckDamage());
	diamante.whoAmI();
	return(0);
}
