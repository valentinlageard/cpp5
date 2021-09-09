#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern const & original) {
	(void)original;
}

Intern::~Intern() {}

Intern & Intern::operator=(Intern const & rhs) {
	if (this == &rhs) {
		return *this;
	}
	return *this;
}

Form * Intern::makeForm(std::string const & form_name, std::string const & form_target) {
	Form * tmp;

	for (int i=0; i < 3; i++) {
		if (form_name == _form_names[i]) {
			tmp = (this->*(_form_constructors[i]))(form_target);
			std::cout << "Intern creates " << *tmp << std::endl;
			return tmp;
		}
	}
	std::cout << "Intern cannot create " << form_name << std::endl;
	return NULL;
}

Form * Intern::_newShrubberyCreationForm(std::string target) {
	return new ShrubberyCreationForm(target);
}

Form * Intern::_newRobotomyRequestForm(std::string target) {
	return new RobotomyRequestForm(target);
}

Form * Intern::_newPresidentialPardonForm(std::string target) {
	return new PresidentialPardonForm(target);
}

Intern::FormConstructor Intern::_form_constructors[3] = {
	&Intern::_newShrubberyCreationForm,
	&Intern::_newRobotomyRequestForm,
	&Intern::_newPresidentialPardonForm
};

std::string Intern::_form_names[3] = {
	"shrubbery creation",
	"robotomy request",
	"presidential pardon"
};
