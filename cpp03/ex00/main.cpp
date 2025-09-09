/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joserra <joserra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:55:10 by joserra           #+#    #+#             */
/*   Updated: 2025/06/30 16:55:17 by joserra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clapTrap1("clapTrap_1");
	ClapTrap clapTrap2("clapTrap_2");

	clapTrap2.attack(clapTrap1.getName());
	while (clapTrap1.getHitPoints() > 0)
	{
		clapTrap1.takeDamage(1);
	}
	clapTrap1.beRepaired(1);
	clapTrap2.attack(clapTrap1.getName());
	while (clapTrap2.getEnergyPoints() > 0)
	{
		clapTrap2.beRepaired(1);
	}
	clapTrap2.attack(clapTrap1.getName());
	clapTrap2.takeDamage(99999);
	clapTrap2.beRepaired(1);
	return (0);
}
