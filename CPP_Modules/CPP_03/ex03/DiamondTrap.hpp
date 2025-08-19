/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:57:33 by mbiagi            #+#    #+#             */
/*   Updated: 2025/08/19 14:23:43 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "./FragTrap.hpp"

class DiamondTrap: public virtual ScavTrap, public virtual FragTrap
{
private:
	std::string name;
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(DiamondTrap &other);
	~DiamondTrap();

	const DiamondTrap &operator=(const DiamondTrap &other);

	virtual void	attack(const std::string &target);
	void			whoAmI() const;
};

#endif