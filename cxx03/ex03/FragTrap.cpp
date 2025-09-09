/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joserra <joserra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:58:42 by joserra           #+#    #+#             */
/*   Updated: 2025/06/30 16:58:43 by joserra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "Created a new FragTrap with default constructor." << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Created a new FragTrap with name constructor." << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &fragTrap) : ClapTrap(fragTrap)
{
	std::cout << "Created a new FragTrap with copy constructor." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap)
{
	std::cout << "Called FragTrap assignment operator." << std::endl;
	ClapTrap::operator=(fragTrap);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "Destroyed FragTrap." << std::endl;
}

void FragTrap::highFiveGuys()
{
	std::cout << "Hey! Hey! High five guys!." << std::endl;
}
