/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jllarena <jllarena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:43:44 by jllarena          #+#    #+#             */
/*   Updated: 2025/02/03 13:02:32 by jllarena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"

class Brain
{
private:
    std::string _ideas[100];
public:
    Brain();
    ~Brain();
    Brain(const Brain& other);
	Brain& operator=(const Brain& other);
};

#endif