/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jllarena <jllarena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:37:12 by jllarena          #+#    #+#             */
/*   Updated: 2025/02/03 14:45:33 by jllarena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int	main(void)
{
	std::cout << "------------- Animal ----------------" << std::endl;
	
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
	
	std::cout << "------------- WrongAnimal ----------------" << std::endl;
	
	const WrongAnimal*	beta = new WrongAnimal();
	const WrongAnimal*	a = new WrongCat();
	const WrongCat*		b = new WrongCat();
	
	std::cout << beta->getType() << std::endl;
	std::cout << a->getType() << std::endl;
	std::cout << b->getType() << std::endl;
	beta->makeSound();
	a->makeSound();
	b->makeSound();
	delete beta;
	delete a;
	delete b;
	return (0);
}