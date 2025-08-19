/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:30:46 by mbiagi            #+#    #+#             */
/*   Updated: 2025/08/18 12:33:29 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"

int main()
{
	ClapTrap	player("franci");

	player.attack("mavi");
	player.takeDamage(3);
	player.beRepaired(2);
	return(0);
}
