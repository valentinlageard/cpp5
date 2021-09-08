#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
	Form("Presidential pardon form", 25, 5),
	_target("dummy")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string const target):
	Form("Presidential pardon form", 25, 5),
	_target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & original):
	Form("Presidential pardon form", 25, 5),
	_target(original._target)
{}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs) {
	if (this == &rhs) {
		return *this;
	}
	// TODO : Assign values
	return *this;
}

void PresidentialPardonForm::execute (Bureaucrat const & executor) const {
	try {
		checkExecutability(executor);
		std::cout << "Zaphod Beeblebrox pardonned " << _target << std::endl;
	}
	catch (const std::exception & e) {
		throw;
	}
}
