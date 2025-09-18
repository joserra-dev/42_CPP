/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joserra <joserra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 01:00:07 by joserra           #+#    #+#             */
/*   Updated: 2025/06/30 16:22:21 by joserra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
	: _name(name), _hitPoints(10), _energyPoits(10), _attackDamage(0){
		std::cout << "ClapTrap " << _name << " has been constructed.\n";
	}

ClapTrap::ClapTrap(const ClapTrap& other)
	: _name(other._name), _hitPoints(other._hitPoints),
	_energyPoits(other._energyPoits), _attackDamage(other._attackDamage) {
		std::cout <<"ClapTrap" << _name << " has been copy-constructed.\n";
	}

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
	if(this != &other) {
		_name =other._name;
		_hitPoints = other._hitPoints;
		_energyPoits =other._energyPoits;
		_attackDamage= other._attackDamage;
	}
	std::cout << "Claptrap " << _name << " has been assigned.\n";
	return *this;
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap " << _name << " has been destroyed. \n";
}

void ClapTrap::attack(const std::string& target) {
	if (_hitPoints <= 0 || _energyPoits <= 0) {
		std::cout << "ClapTrap " << _name << " Can`t attack: No hits points ";
		return;
	}
	_energyPoits--;
	std::cout << "ClapTrap " << _name << " attacks " << target
		<< ", causing " << _attackDamage << " points of damage! \n";
}
void ClapTrap::takeDamage(unsigned int amount){
	_hitPoints  -= amount;
	if(_hitPoints < 0){
		
		_hitPoints = 0;
		std::cout << _name << " has run out of energy, it can't perform any action.\n";

		std::cout << "ClapTrap " << _name << " takes " << amount
		<< " points of damage: Remaining HP: " << _hitPoints << "\n";
	}
 }
 
void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints <= 0 || _energyPoits <= 0) {
		std::cout << "ClapTrap " << _name << " repairs itself for " << amount
				  << " hit points: New HP: " << _hitPoints <<"\n";
 	}
}
