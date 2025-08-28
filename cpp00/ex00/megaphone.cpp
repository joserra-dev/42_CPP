/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joserra <joserra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 00:28:33 by joserra           #+#    #+#             */
/*   Updated: 2025/06/06 00:44:50 by joserra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	int i = 1;
	int j = 0;
	char temp;
	
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNVEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		while(i < argc)
		{
			while(argv[i][j])
			{
				if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
				{
					temp = toupper(argv[i][j]);
					std::cout << temp;
				}
				else
					std::cout << argv[i][j];
				j++;
			}
			j = 0;
			i++;
		}
		std::cout <<std::endl;
	}
	return 0;
}
