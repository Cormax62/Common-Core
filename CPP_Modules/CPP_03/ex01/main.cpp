/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:30:46 by mbiagi            #+#    #+#             */
/*   Updated: 2025/08/19 11:40:37 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScavTrap.hpp"

int main()
{
	ClapTrap	franci("franci");
	ScavTrap	mavi;

	franci.attack(mavi.getName());
	mavi.takeDamage(franci.getAttckDamage());
	franci.attack(mavi.getName());
	mavi.takeDamage(franci.getAttckDamage());
	franci.attack(mavi.getName());
	mavi.takeDamage(franci.getAttckDamage());
	franci.attack(mavi.getName());
	mavi.takeDamage(franci.getAttckDamage());
	franci.attack(mavi.getName());
	mavi.takeDamage(franci.getAttckDamage());
	franci.attack(mavi.getName());
	mavi.takeDamage(franci.getAttckDamage());
	franci.attack(mavi.getName());
	mavi.takeDamage(franci.getAttckDamage());
	return(0);
}
