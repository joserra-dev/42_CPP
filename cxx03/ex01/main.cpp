/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joserra <joserra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:56:01 by joserra           #+#    #+#             */
/*   Updated: 2025/06/30 16:56:03 by joserra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap scavTrap1("scavTrap_1");
	ScavTrap scavTrap2("scavTrap_2");

	scavTrap2.attack(scavTrap1.getName());
	scavTrap1.takeDamage(scavTrap2.getAttackDamage());
	while (scavTrap1.getHitPoints() > 0)
	{
		scavTrap1.takeDamage(5);
	}
	scavTrap1.beRepaired(1);
	scavTrap2.attack(scavTrap1.getName());
	scavTrap1.takeDamage(scavTrap2.getAttackDamage());
	while (scavTrap2.getEnergyPoints() > 0)
	{
		scavTrap2.beRepaired(10);
	}
	scavTrap2.attack(scavTrap1.getName());
	scavTrap2.takeDamage(99999);
	scavTrap2.beRepaired(1);
	
	ScavTrap scavTrap1Copy(scavTrap1);
	scavTrap1.guardGate();
	ScavTrap scavTrap2Copy;
	scavTrap2Copy = scavTrap2;
	scavTrap2Copy.guardGate();
	return (0);
}
