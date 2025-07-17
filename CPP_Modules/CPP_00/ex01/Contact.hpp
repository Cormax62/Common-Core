/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:12:37 by mbiagi            #+#    #+#             */
/*   Updated: 2025/07/16 15:13:08 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
private:
	std::string FirstName;
	std::string LastName;
	std::string NickName;
	std::string	DarkestSecrets;
	std::string	PhoneNumber;
public:
	Contact();
	~Contact();

	void		SetFirstName(std::string str);
	void		SetLastName(std::string str);
	void		SetNickName(std::string str);
	void		SetPhoneNumber(std::string str);
	void		SetDarckestSecret(std::string str);

	std::string	GetFirstName();
	std::string	GetLastName();
	std::string	GetNickName();
	std::string	GetPhoneNumber();
	std::string	GetDarckestSecret();
};

#endif