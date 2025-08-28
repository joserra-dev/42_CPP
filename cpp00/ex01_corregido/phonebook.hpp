/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joscastr <joscastr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:29:41 by joscastr          #+#    #+#             */
/*   Updated: 2025/06/10 13:30:02 by joscastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

void set_homepage();
int is_number(std::string str);

class PhoneBook
{
	public:
	
		PhoneBook();
		int addContact();
		int searchContact();
		int showContact(int index);
		
	private:
		Contact user[8];
		int nb_Contact;
};
