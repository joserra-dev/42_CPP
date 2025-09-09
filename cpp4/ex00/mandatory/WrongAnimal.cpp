/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jllarena <jllarena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:37:08 by jllarena          #+#    #+#             */
/*   Updated: 2025/01/28 11:51:02 by jllarena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal():_type("WrongAnimal")
{
	std::cout << "WrongAnimal Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "WrongAnimal Copy Constructor called" << std::endl;
	*this = other;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Deconstructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "WrongAnimal Assignation operator called" << std::endl;
	if (this == &other)
    {
	    this->_type = other._type;
    }
	return *this;
}

void WrongAnimal::makeSound(void)const
{
	std::cout << this->getType() << " ***WrongAnimal sounds***" << std::endl;
}

std::string	WrongAnimal::getType(void)const
{
	return (this->_type);
}