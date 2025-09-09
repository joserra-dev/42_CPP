#include "Intern.hpp"

Intern::Intern() {}
Intern::Intern(const Intern& other) { (void)other; }
Intern& Intern::operator=(const Intern& other) { (void)other; return *this; }
Intern::~Intern() {}

AForm* Intern::createShrubbery(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPardon(const std::string& target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request", 
		"presidential pardon"
	};

	AForm* (Intern::*formCreators[3])(const std::string&) = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPardon
	};

	for (int i = 0; i < 3; i++){
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*formCreators[i])(target);
		}
	}

	std::cerr << "Error: Intern cannot create form \"" << formName << "" << std::endl;
	return NULL;
}