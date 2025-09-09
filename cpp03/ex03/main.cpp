/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joserra <joserra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:04:25 by joserra           #+#    #+#             */
/*   Updated: 2025/06/30 17:04:27 by joserra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

static void testDiamondTrap(DiamondTrap &diamondTrap);

int main()
{
	DiamondTrap diamondTrap("diamondTrapName");
	testDiamondTrap(diamondTrap);
	DiamondTrap copy(diamondTrap);
	testDiamondTrap(copy);
	return (0);
}

static void testDiamondTrap(DiamondTrap &diamondTrap)
{
	std::cout << "Attack damage: " << diamondTrap.getAttackDamage() << std::endl;
	std::cout << "Energy points: " << diamondTrap.getEnergyPoints() << std::endl;
	std::cout << "Hit points: " << diamondTrap.getHitPoints() << std::endl;
	diamondTrap.whoAnI();
	diamondTrap.attack("some villain");
	diamondTrap.guardGate();
	diamondTrap.highFiveGuys();
	std::cout << std::endl;
}
