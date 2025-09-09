/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joserra <joserra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:58:05 by joserra           #+#    #+#             */
/*   Updated: 2025/06/30 16:58:07 by joserra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() :
	ClapTrap("Default_DiamondTrap_name_clap_name"),
	ScavTrap(),
	FragTrap()
{
	std::cout << "Created a new DiamondTrap with default constructor." << std::endl;
	this->name = "Default_DiamondTrap_name";
	this->energyPoints = 50;
}

DiamondTrap::DiamondTrap(std::string name) :
	ClapTrap(name + "_clap_name"),
	ScavTrap(),
	FragTrap()
{
	std::cout << "Created a new DiamondTrap with name constructor." << std::endl;
	this->name = name;
	this->energyPoints = 50;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap) :
	ClapTrap(diamondTrap),
	ScavTrap(diamondTrap),
	FragTrap(diamondTrap)
{
	std::cout << "Created a new DiamondTrap with copy constructor." << std::endl;
	this->name = diamondTrap.name;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondTrap)
{
	std::cout << "Called DiamondTrap assignment operator." << std::endl;
	if (this != &diamondTrap)
	{
		this->name = diamondTrap.name;
		ClapTrap::operator=(diamondTrap);
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destroyed DiamondTrap." << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAnI()
{
	std::cout << "DiamondTrap name: " << this->name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}
