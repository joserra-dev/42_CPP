/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joscastr <joscastr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:29:14 by joscastr          #+#    #+#             */
/*   Updated: 2025/06/10 13:29:17 by joscastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream>
# include <iomanip>

void print_Contact(std::string str);

class Contact
{
	// Methods(funciones)

	public:
	void setFname(std::string str);
	void setLname(std::string str);
	void setNname(std::string str);
	void setnumber(std::string str);
	void setsecrets(std::string str);
	void setid(int nb);
	std::string get_secrets() const;
	std::string get_pnumber() const;
	std::string get_nname() const;
	std::string get_lname() const;
	std::string get_fname() const;
	int get_id() const;
	
	//Atributes (datos)

	private:

	int m_id;
	std::string m_fname;
	std::string m_lname;
	std::string m_nname;
	std::string m_pnumber;
	std::string m_secrets;
};