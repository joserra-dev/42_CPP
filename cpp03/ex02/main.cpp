/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joserra <joserra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:57:27 by joserra           #+#    #+#             */
/*   Updated: 2025/06/30 16:57:30 by joserra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap fragTrap1("fragTrap_1");
	FragTrap fragTrap2("fragTrap_2");

	fragTrap2.attack(fragTrap1.getName());
	fragTrap1.takeDamage(fragTrap2.getAttackDamage());
	while (fragTrap1.getHitPoints() > 0)
	{
		fragTrap1.takeDamage(5);
	}
	fragTrap1.beRepaired(1);
	fragTrap2.attack(fragTrap1.getName());
	fragTrap1.takeDamage(fragTrap2.getAttackDamage());
	while (fragTrap2.getEnergyPoints() > 0)
	{
		fragTrap2.beRepaired(10);
	}
	fragTrap2.attack(fragTrap1.getName());
	fragTrap2.takeDamage(99999);
	fragTrap2.beRepaired(1);
	
	FragTrap scavTrap1Copy(fragTrap1);
	fragTrap1.highFiveGuys();
	FragTrap scavTrap2Copy;
	scavTrap2Copy = fragTrap2;
	scavTrap2Copy.highFiveGuys();
	return (0);
}
