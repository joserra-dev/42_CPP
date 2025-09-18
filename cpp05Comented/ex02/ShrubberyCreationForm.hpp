#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream> // para escribir en archivos

class ShrubberyCreationForm :public AForm {
private:
	std::string target;

public:
	// Constructores y destructor
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();

	// Metodo especifico
	void execute(Bureaucrat const & executor) const;
};

#endif