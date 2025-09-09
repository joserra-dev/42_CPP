#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
	try
	{
		Bureaucrat b1("Alice", 50);
		Bureaucrat b2("Bob", 120);

		Form f1("Topsecret", 100, 50);
		Form f2("MinorForm", 140, 130);
		
		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;

		std::cout << "\n== intentando firmar == " << std::endl;

		b1.signForm(f1); //deberia firmar
		b2.signForm(f1); //demasiado bajo -> excepcion

		b2.signForm(f2); //deberia firmar
			
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception:" << e.what() << std::endl;'\n';
	}
	
	return 0;
}