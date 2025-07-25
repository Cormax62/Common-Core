/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:09:49 by mbiagi            #+#    #+#             */
/*   Updated: 2025/07/22 14:28:27 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout<<"address: "<<&string<<", valore: "<<string<<std::endl;
	std::cout<<"address: "<<stringPTR<<", valore: "<<*stringPTR<<std::endl;
	std::cout<<"address: "<<&stringREF<<", valore: "<<stringREF<<std::endl;
}
