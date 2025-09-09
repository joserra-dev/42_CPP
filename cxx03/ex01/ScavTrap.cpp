/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joserra <joserra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:56:19 by joserra           #+#    #+#             */
/*   Updated: 2025/06/30 16:56:22 by joserra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "Created a new ScavTrap with default constructor." << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Created a new ScavTrap with name constructor." << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) : ClapTrap(scavTrap)
{
	std::cout << "Created a new ScavTrap with copy constructor." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap)
{
	std::cout << "Created a new ScavTrap with assignment operator." << std::endl;
	ClapTrap::operator=(scavTrap);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destroyed ScavTrap." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (!ClapTrap::hasHitPoints() || !ClapTrap::hasEnergyPoints())
		return;
	this->energyPoints--;
	std::cout
		<< "ScavTrap " << this->name
		<< " attacks " << target
		<< ", causing " << this->attackDamage
		<< " points of damage!" << std::endl;
}

void ScavTrap::guardGate() const
{
	std::cout
		<< "ScavTrap " << this->name
		<< " is now in gatekeeper mode." << std::endl;
}
