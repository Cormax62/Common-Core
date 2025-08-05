/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 10:00:13 by mbiagi            #+#    #+#             */
/*   Updated: 2025/08/05 13:55:41 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::error(void)
{
	std::cout<<"This is unacceptable! I want to speak to the manager now"<<std::endl;
}

void	Harl::warning(void)
{
	std::cout<<"I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month"<<std::endl;
}

void	Harl::info(void)
{
	std::cout<<"I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"<<std::endl;
}

void	Harl::debug(void)
{
	std::cout<<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"<<std::endl;
}

void Harl::complain(std::string level)
{
	int 		i = 0;
	Harl		karen;
	void		(Harl::*ptrDebug)() = &Harl::debug;
	void		(Harl::*ptrInfo)() = &Harl::info;
	void		(Harl::*ptrWarning)() = &Harl::warning;
	void		(Harl::*ptrError)() = &Harl::error;
	std::string	levels[4];

	levels[0] = "debug";
	levels[1] = "info";
	levels[2] = "warning";
	levels[3] = "error";
	while (i < 4)
	{
		if (level == levels[i])
			break;
		i++;
	}
	switch(i)
	{
		case 0:
			(karen.*ptrDebug)();
			break;
		case 1:
			(karen.*ptrInfo)();
			break;
		case 2:
			(karen.*ptrWarning)();
			break;
		case 3:
			(karen.*ptrError)();
			break;
	}
}
