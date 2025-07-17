/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:08:17 by mbiagi            #+#    #+#             */
/*   Updated: 2025/07/17 15:12:23 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.h"

Contact::Contact()
{
	return ;
}

Contact::~Contact()
{
	return ;
}

void	Contact::SetFirstName(std::string str)
{
	this->FirstName = str;
}

void	Contact::SetLastName(std::string str)
{
	this->LastName = str;
}

void	Contact::SetNickName(std::string str)
{
	this->NickName = str;
}

void	Contact::SetPhoneNumber(std::string str)
{
	this->PhoneNumber = str;
}

void	Contact::SetDarckestSecret(std::string str)
{
	this->DarkestSecrets = str;
}

std::string	Contact::GetFirstName()
{
	return(this->FirstName);
}

std::string	Contact::GetLastName()
{
	return(this->LastName);
}

std::string	Contact::GetNickName()
{
	return(this->NickName);
}

std::string	Contact::GetPhoneNumber()
{
	return(this->PhoneNumber);
}

std::string	Contact::GetDarckestSecret()
{
	return(this->DarkestSecrets);
}
