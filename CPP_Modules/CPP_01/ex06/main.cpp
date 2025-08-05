/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 10:55:55 by mbiagi            #+#    #+#             */
/*   Updated: 2025/08/05 12:28:28 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Harl.hpp"

int	main(int ac, char **av)
{
	Harl		karen;
	std::string	str[4];
	bool		filter = true;

	str[0] = "debug";
	str[1] = "info";
	str[2] = "warning";
	str[3] = "error";
	if (ac != 2)
		return(std::cout<<"Wrong argument number"<<std::endl, 0);
	for (int i = 0; i < 4; i++)
	{
		if (str[i] == av[1])
			filter = false;
		if (filter == false)
			karen.complain(str[i]);
	}
	return(0);
}
