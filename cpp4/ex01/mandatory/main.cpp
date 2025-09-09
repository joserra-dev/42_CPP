/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jllarena <jllarena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:37:12 by jllarena          #+#    #+#             */
/*   Updated: 2025/02/03 14:47:23 by jllarena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/Brain.hpp"

int	main(void)
{
	std::cout << "--------> NO ARRAY <--------------" << std::endl;
	const Animal*	Javi = new Dog();
	const Animal*	Jose = new Cat();
	
	delete	Javi;
	delete	Jose;

	std::cout << "--------> BASIC <--------------" << std::endl;
	Dog basic;
	{
		Dog tmp = basic;
	}

	std::cout << "--------> ARRAY <--------------" << std::endl;
	const Animal*	zoo[6] = {new Dog(), new Dog(), new Dog(), new Cat(), new Cat(), new Cat()};

	size_t	i = 0;
	while (i < 6)
	{
		delete zoo[i];
		i++;
	}
	return (0);
}

