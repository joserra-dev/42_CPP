/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joserra <joserra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:57:43 by joserra           #+#    #+#             */
/*   Updated: 2025/06/30 16:57:46 by joserra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "Created a new ClapTrap with default constructor." << std::endl;
}

ClapTrap::ClapTrap(std::string name) :
	name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "Created a new ClapTrap with name constructor." << std::endl;
}
	
ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
	std::cout << "Created a new ClapTrap with copy constructor." << std::endl;
	*this = clapTrap;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
{
	std::cout << "Called ClapTrap assignment operator." << std::endl;
	if (this != &clapTrap)
	{
		this->name = clapTrap.getName();
		this->hitPoints = clapTrap.getHitPoints();
		this->energyPoints = clapTrap.getEnergyPoints();
		this->attackDamage = clapTrap.getAttackDamage();
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destroyed ClapTrap." << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (!this->hasHitPoints() || !this->hasEnergyPoints())
		return;
	this->energyPoints--;
	std::cout
		<< "ClapTrap " << this->name
		<< " attacks " << target
		<< ", causing " << this->attackDamage
		<< " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->hasHitPoints())
		return;
	if (amount > this->hitPoints)
		amount = this->hitPoints;
	this->hitPoints -= amount;
	std::cout
		<< "ClapTrap " << this->name
		<< " took " << amount
		<< " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->hasHitPoints() || !this->hasEnergyPoints())
		return;
	this->energyPoints--;
	if (static_cast<long>(amount + this->hitPoints) > std::numeric_limits<unsigned int>::max())
		amount = std::numeric_limits<unsigned int>::max() - this->hitPoints;
	this->hitPoints += amount;
	std::cout
		<< "ClapTrap " << this->name
		<< " got repaired by " << amount
		<< " hit points!" << std::endl;
}

bool ClapTrap::hasHitPoints() const
{
	if (this->hitPoints <= 0)
	{
		std::cout 
			<< this->name 
			<< " is dead, it can\'t perform any action or receive any more damage."
			<< std::endl;
		return false;
	}
	return true;
}

bool ClapTrap::hasEnergyPoints() const
{
	if (this->energyPoints <= 0)
	{
		std::cout 
			<< this->name 
			<< " has run out of energy, it can\'t perform any action."
			<< std::endl;
		return false;
	}
	return true;
}

std::string ClapTrap::getName() const
{
	return (this->name);
}

unsigned int ClapTrap::getHitPoints() const
{
	return (this->hitPoints);
}

unsigned int ClapTrap::getEnergyPoints() const
{
	return (this->energyPoints);
}

unsigned int ClapTrap::getAttackDamage() const
{
	return (this->attackDamage);
}
