/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:48:57 by mbiagi            #+#    #+#             */
/*   Updated: 2025/08/19 10:52:16 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCRAVTRAP_HPP
# define SCRAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
private:
	
public:
	ScavTrap();
	ScavTrap(ScavTrap &other);
	ScavTrap(std::string);
	~ScavTrap();

	const ScavTrap &operator=(const ScavTrap &other);

	virtual void	attack(const std::string& target);
	void 			guardGate();
};

#endif