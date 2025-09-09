/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jllarena <jllarena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:43:57 by jllarena          #+#    #+#             */
/*   Updated: 2025/02/03 13:03:13 by jllarena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default Constructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain Copy Constructor called" << std::endl;
	*this = other;
}

Brain::~Brain()
{
	std::cout << "Brain Deconstructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain Assignation operator called" << std::endl;
    if (this != &other)
    {
        size_t	i = 0;
        while (i < 100)
        {
            this->_ideas[i] = other._ideas[i];
            i++;
        }
    }
    return (*this);
}