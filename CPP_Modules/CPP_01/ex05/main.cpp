/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 10:55:55 by mbiagi            #+#    #+#             */
/*   Updated: 2025/08/05 11:43:32 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Harl.hpp"

int	main(void)
{
	Harl		karen;
	std::string	str;

	while (std::getline(std::cin, str))
	{
		if (str == "finish")
			return(0);
		karen.complain(str);
	}
	return(0);
}
