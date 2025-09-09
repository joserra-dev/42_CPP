/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jllarena <jllarena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:37:45 by jllarena          #+#    #+#             */
/*   Updated: 2025/01/28 12:11:26 by jllarena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal()
{
    _type = "Default";
    std::cout << "Animal Default constructor called" << std::endl;
}
Animal::Animal(const Animal &other)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal &other)
{
    std::cout << "Animal Assignation operator called" << std::endl;
    if (this != &other)
    {
        this->_type = other._type;
    }
    return *this;
}
Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Animal doesn`t make any sound" << std::endl;
}

std::string Animal::getType() const
{
    return _type;
}