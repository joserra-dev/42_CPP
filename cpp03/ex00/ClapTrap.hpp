/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joserra <joserra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:54:52 by joserra           #+#    #+#             */
/*   Updated: 2025/06/30 16:54:54 by joserra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <string>

class ClapTrap
{
	private:
		std::string name;
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int attackDamage;

		bool hasHitPoints() const;
		bool hasEnergyPoints() const;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &clapTrap);
		ClapTrap &operator=(const ClapTrap &clapTrap);
		~ClapTrap();

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string getName() const;
		unsigned int getHitPoints() const;
		unsigned int getEnergyPoints() const;
		unsigned int getAttackDamage() const;
};

#endif
