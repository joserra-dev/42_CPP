/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jllarena <jllarena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:37:20 by jllarena          #+#    #+#             */
/*   Updated: 2025/01/28 11:42:23 by jllarena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog(): Animal()
{
	this->_type = "Dog";
	std::cout << "Dog Default Constructor called" << std::endl;
}

Dog::Dog(const Dog &other): Animal()
{
	std::cout << "Dog Copy Constructor called" << std::endl;
	*this = other;
}

Dog::~Dog()
{
	std::cout << "Dog Deconstructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog Assignation operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return *this;
}

void	Dog::makeSound(void)const
{
	std::cout << this->getType() << " ***GUAUU***" << std::endl;
}