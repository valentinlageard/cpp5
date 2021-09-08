#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {

	Form * a_shrubbery_form = NULL;

	try {
		a_shrubbery_form = new ShrubberyCreationForm("ewe");
		Bureaucrat hermes_conrad = Bureaucrat("Hermes Conrad", 36);
		Bureaucrat boloss = Bureaucrat("Boloss", 150);
		hermes_conrad.executeForm(*a_shrubbery_form);
		hermes_conrad.signForm(*a_shrubbery_form);
		boloss.executeForm(*a_shrubbery_form);
		hermes_conrad.executeForm(*a_shrubbery_form);
	}
	catch (const std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	delete a_shrubbery_form;

	return 0;
}
