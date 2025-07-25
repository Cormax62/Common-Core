/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 09:47:35 by mbiagi            #+#    #+#             */
/*   Updated: 2025/07/25 16:04:39 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

std::string	replaceString(std::string str, std::string s1, std::string s2)
{
	std::string	temp;
	size_t		i;
	
	i = str.find(s1);
	if (i == std::string::npos)
		return (str);
	temp.insert(0, str, 0, i);
	s2.append(&str[i + s1.length()]);
	return(temp.append(s2));
}

int	main(int ac, char** av)
{
	std::ifstream	ifstream;
	std::ofstream	ofstream;
	std::string		infile;
	std::string		outfile;
	std::string		s1;
	std::string		s2;
	std::string		str;

	if (ac != 4)
		return(std::cout<<"WRONG ARGUMENTS NUMBER"<<std::endl, 1);
	infile = av[1];
	outfile = infile.append(".replace");
	s1 = av[2];
	s2 = av[3];
	if (s1.empty())
		return(std::cout<<"FIRST STRING EMPTY", 1);
	ifstream.open(av[1], std::ios::in);
	ofstream.open(outfile.c_str(), ofstream.out);
	while (std::getline(ifstream, str))
	{
		str = replaceString(str, s1, s2);
		ofstream<<str<<std::endl;
	}
	ifstream.close();
	ofstream.close();
	return(0);
}
