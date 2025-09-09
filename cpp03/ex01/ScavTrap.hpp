/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joserra <joserra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:56:28 by joserra           #+#    #+#             */
/*   Updated: 2025/06/30 16:56:31 by joserra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &scavTrap);
		ScavTrap &operator=(const ScavTrap &scavTrap);
		~ScavTrap();

		void attack(const std::string &target);
		void guardGate() const;
};

#endif
