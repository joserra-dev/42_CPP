/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jllarena <jllarena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:37:35 by jllarena          #+#    #+#             */
/*   Updated: 2025/02/03 13:58:09 by jllarena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout << "Cat Default Constructor called" << std::endl;
	this->_type = "Cat";
	this->_catIdeas = new Brain();
	if (this->_catIdeas == NULL)
	{
		perror("Cat Brain allocation failed");
		std::cerr << "Exiting the process now." << std::endl;
		exit(1);
	}
}

Cat::Cat(const Cat &copy): Animal()
{
	std::cout << "Cat Copy Constructor called" << std::endl;
	*this = copy;
}

Cat::~Cat()
{
	delete(this->_catIdeas);
	std::cout << "Cat Deconstructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat Assignation operator called" << std::endl;
	if (this != &other)
	{
		_type = other._type;
		_catIdeas = new Brain (*other._catIdeas);
	}
	return (*this);
}

void	Cat::makeSound(void)const
{
	std::cout << this->getType() << " ***MIAUU***" << std::endl;
}

