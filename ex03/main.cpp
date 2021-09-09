#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {

	Form * a_shrubbery_form = NULL;
	Form * a_robotomy_form = NULL;
	Form * a_presidential_form = NULL;
	Form * a_non_existing_form = NULL;
	Intern an_intern = Intern();

	try {
		a_shrubbery_form = an_intern.makeForm("shrubbery creation", "home");
		a_robotomy_form = an_intern.makeForm("robotomy request", "Bender");
		a_presidential_form = an_intern.makeForm("presidential pardon", "Bender");
		a_non_existing_form = an_intern.makeForm("does not exist", "at all");

		Bureaucrat number_1 = Bureaucrat("Number 1", 1);
		Bureaucrat hermes_conrad = Bureaucrat("Hermes Conrad", 36);
		Bureaucrat boloss = Bureaucrat("Boloss", 150);

		hermes_conrad.executeForm(*a_shrubbery_form);
		hermes_conrad.signForm(*a_shrubbery_form);
		boloss.executeForm(*a_shrubbery_form);
		hermes_conrad.executeForm(*a_shrubbery_form);

		hermes_conrad.executeForm(*a_robotomy_form);
		hermes_conrad.signForm(*a_robotomy_form);
		boloss.executeForm(*a_robotomy_form);
		hermes_conrad.executeForm(*a_robotomy_form);
		hermes_conrad.executeForm(*a_robotomy_form);
		hermes_conrad.executeForm(*a_robotomy_form);

		number_1.executeForm(*a_presidential_form);
		hermes_conrad.signForm(*a_presidential_form);
		number_1.signForm(*a_presidential_form);
		hermes_conrad.executeForm(*a_presidential_form);
		number_1.executeForm(*a_presidential_form);
	}
	catch (const std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	delete a_shrubbery_form;
	delete a_robotomy_form;
	delete a_presidential_form;

	return 0;
}
