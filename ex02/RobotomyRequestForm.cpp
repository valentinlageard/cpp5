#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():
	Form("robotomy request", 72, 45),
	_target("dummy")
{
	std::srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target):
	Form("robotomy request", 72, 45),
	_target(target)
{
	std::srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & original):
	Form("robotomy request", 72, 45),
	_target(original._target)
{
	std::srand(std::time(NULL));
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs) {
	if (this == &rhs) {
		return *this;
	}
	Form::operator=(rhs);
	return *this;
}

void RobotomyRequestForm::execute (Bureaucrat const & executor) const {
	try {
		checkExecutability(executor);
		std::cout << "BZZZZZZZ BZZZ BZZZZZB ZZZZZZ !" << std::endl;
		std::cout << _target;
		if (std::rand() % 2) {
			std::cout << " was successfully robotomized." << std::endl;
		} else {
			std::cout << " was not successfully robotomized." << std::endl;
		}
	}
	catch (const std::exception & e) {
		throw;
	}
}
