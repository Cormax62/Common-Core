/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:02:06 by mbiagi            #+#    #+#             */
/*   Updated: 2025/08/19 10:51:22 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
private:
	std::string name;
	int			hitPoint;
	int			energyPoint;
	int			attckDamage;
public:
	ClapTrap();
	ClapTrap(ClapTrap &other);
	ClapTrap(std::string name);
	~ClapTrap();

	const ClapTrap &operator=(const ClapTrap &other);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	std::string	getName() const;
	int			getHitPoint() const;
	int			getEnergyPoint() const;
	int			getAttckDamage() const;
	void		setName(std::string name);
	void		setHitPoint(int n);
	void		setEnergyPoint(int n);
	void		setAttckDamage(int n);
};

#endif