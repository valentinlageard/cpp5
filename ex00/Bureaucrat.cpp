#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():
	_name("dummy"),
	_grade(1)
{}

Bureaucrat::Bureaucrat(std::string const & name, int grade):
	_name(name),
	_grade(grade)
{
	if (_grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	if (_grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const & original):
	_name(original._name),
	_grade(original._grade)
{}

Bureaucrat::~Bureaucrat() {}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs) {
	if (this == &rhs) {
		return *this;
	}
	_grade = rhs._grade;
	return *this;
}

Bureaucrat Bureaucrat::operator++() {
	if (_grade == 1) {
		throw Bureaucrat::GradeTooHighException();
	} else {
		--_grade;
	}
	return Bureaucrat(*this);
}

Bureaucrat Bureaucrat::operator++(int) {
	Bureaucrat tmp(*this);
	if (_grade == 1) {
		throw Bureaucrat::GradeTooHighException();
	} else {
		--_grade;
	}
	return tmp;
}

Bureaucrat Bureaucrat::operator--() {
	if (_grade == 150) {
		throw Bureaucrat::GradeTooLowException();
	} else {
		++_grade;
	}
	return *this;
}

Bureaucrat Bureaucrat::operator--(int) {
	Bureaucrat tmp(*this);
	if (_grade == 150) {
		throw Bureaucrat::GradeTooLowException();
	} else {
		++_grade;
	}
	return tmp;
}

std::ostream & operator<<(std::ostream & out, const Bureaucrat & rhs) {
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return out;
}


std::string const & Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

Bureaucrat::GradeTooHighException::GradeTooHighException():
	std::runtime_error("Grade too high !")
{}

Bureaucrat::GradeTooLowException::GradeTooLowException():
	std::runtime_error("Grade too low !")
{}
