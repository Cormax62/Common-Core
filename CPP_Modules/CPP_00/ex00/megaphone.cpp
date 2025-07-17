/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:21:53 by mbiagi            #+#    #+#             */
/*   Updated: 2025/07/16 10:47:02 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	int i = 0;
	int j = 1;

	if (ac < 2)
		return (std::cout <<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl , 1);
	while (av[j])
	{
		i = 0;
		while (av[j][i])
		{
			if (av[j][i] <= 122 && av[j][i] >= 97)
				av[j][i] -= 32;
			i++;
		}
		j++;
	}
	j = 1;
	while (av[j])
	{
		std::cout <<av[j];
		j++;
	}
	std::cout <<std::endl; 
}
