/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:10:59 by mbiagi            #+#    #+#             */
/*   Updated: 2025/07/21 10:07:54 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.h"

Phonebook::Phonebook()
{
	this->n = 0;
	return ;
}

Phonebook::~Phonebook()
{
	return ;
}

std::string	CheckLenght(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0,9) + '.');
	return (str);
}

int IsAllSpace(std::string str)
{
	int	i = 0;

	while (str[i])
	{
		if (std::isspace(str[i]) == 0)
			return (false);
		i++;
	}
	return (true);
}

int	HasNonPrintable(std::string str)
{
	int i = 0;

	while (str[i])
	{
		if (std::isprint(str[i]) == 0)
			return (true);
		i++;
	}
	return (false);
}

int	HasAlpha(std::string str)
{
	int i = 0;

	while (str[i])
	{
		if (std::isalpha(str[i]))
			return (true);
		i++;
	}
	return (false);
}

int Phonebook::search()
{
	std::string str;
	int			i = 0;
	int			n;

	std::cout<<"Which contact are looking for?"<<std::endl;
	str = contacts[i].GetFirstName();
	while (str.empty() == 0)
	{
		std::cout<<std::right<<std::setw(10)<<i + 1<<"|";
		std::cout<<std::right<<std::setw(10)<<CheckLenght(contacts[i].GetFirstName())<<"|";
		std::cout<<std::right<<std::setw(10)<<CheckLenght(contacts[i].GetLastName())<<"|";
		std::cout<<std::right<<std::setw(10)<<CheckLenght(contacts[i].GetNickName())<<"|"<<std::endl;
		i++;
		if (i == 8)
			break;
		str = contacts[i].GetFirstName();
	}
	std::getline(std::cin, str);
	n = std::atoi(str.c_str());
	if (n > this->n || n <= 0)
		return (std::cout<<"WRONG INDEX MATE"<<std::endl, 1);
	std::cout<<std::right<<std::setw(10)<<n<<std::endl;
	std::cout<<std::right<<std::setw(10)<<CheckLenght(contacts[n - 1].GetFirstName())<<std::endl;
	std::cout<<std::right<<std::setw(10)<<CheckLenght(contacts[n - 1].GetLastName())<<std::endl;
	std::cout<<std::right<<std::setw(10)<<CheckLenght(contacts[n - 1].GetNickName())<<std::endl;
	std::cout<<std::right<<std::setw(10)<<CheckLenght(contacts[n - 1].GetPhoneNumber())<<std::endl;
	std::cout<<std::right<<std::setw(10)<<CheckLenght(contacts[n - 1].GetDarckestSecret())<<std::endl;
	return (0);
}

int	Phonebook::add()
{
	std::string str;

	if (this->n == 8)
		this->n = 0;
	std::cout <<"please enter first name:"<<std::endl;
	std::getline(std::cin, str);
	if (str.empty() || IsAllSpace(str) || HasNonPrintable(str))
		return (std::cout<<"NOT CORRECT FIRST NAME"<<std::endl, 0);
	contacts[this->n].SetFirstName(str);
	std::cout <<"please enter last name:"<<std::endl;
	std::getline(std::cin, str);
	if (str.empty() || IsAllSpace(str) || HasNonPrintable(str))
		return (std::cout<<"NOT CORRECT LAST NAME"<<std::endl, 0);
	contacts[this->n].SetLastName(str);
	std::cout <<"please enter nickname:"<<std::endl;
	std::getline(std::cin, str);
	if (str.empty() || IsAllSpace(str) || HasNonPrintable(str))
		return (std::cout<<"NOT CORRECT NICKNAME"<<std::endl, 0);
	contacts[this->n].SetNickName(str);
	std::cout <<"please enter phone number:"<<std::endl;
	std::getline(std::cin, str);
	if (str.empty() || IsAllSpace(str) || HasAlpha(str))
		return (std::cout<<"NOT CORRECT PHONE NUMBER"<<std::endl, 0);
	contacts[this->n].SetPhoneNumber(str);
	std::cout <<"please enter darkest secrets:"<<std::endl;
	std::getline(std::cin, str);
	if (str.empty() || IsAllSpace(str) || HasNonPrintable(str))
		return (std::cout<<"NOT CORRECT DARKEST SECRET"<<std::endl, 0);
	contacts[this->n].SetDarckestSecret(str);
	return(this->n++);
}

int	main(void)
{
	std::string str;
	Contact cont[8];
	Phonebook phone;

	while (1)
	{
		std::cout<<"Please enter a command (add, search, exit):"<<std::endl;
		std::getline(std::cin, str);
		if (str == "ADD")
			phone.add();
		else if (str == "SEARCH")
			phone.search();
		else if (str == "EXIT")
		{
			std::cout<<"VA BENE~, VA' PURE VIA...TANTO NESSUNO VUOLE PARLARE CON TE B-B-BAKA~"<<std::endl;
			return (0);
		}
	}
	return (0);
}
