/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:27:50 by mbiagi            #+#    #+#             */
/*   Updated: 2025/07/22 11:04:07 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*zom = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		zom[i].setName(name);
		zom[i].announce();
	}
	return (zom);
}
