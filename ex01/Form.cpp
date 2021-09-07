#include "Form.hpp"

Form::Form():
	_name("dummy"),
	_signed(false),
	_sign_grade(1),
	_execution_grade(1)
{}

Form::Form(std::string name, int sign_grade, int execution_grade):
	_name(name),
	_signed(false),
	_sign_grade(sign_grade),
	_execution_grade(execution_grade)
{
	if (sign_grade < 1) {
		throw Form::GradeTooHighException();
	}
	if (sign_grade > 150) {
		throw Form::GradeTooLowException();
	}
}

Form::Form(Form const & original):
	_name(original._name),
	_signed(original._signed),
	_sign_grade(original._sign_grade),
	_execution_grade(original._execution_grade)
{}

Form::~Form() {}

Form & Form::operator=(Form const & rhs) {
	if (this == &rhs) {
		return *this;
	}
	_signed = rhs._signed;
	return *this;
}

std::ostream & operator<<(std::ostream & out, const Form & rhs) {
	out << "Form " << rhs.getName();
	out << ", signed: " << (rhs.isSigned() ? "yes" : "no");
	out << " with minimum sign grade: " << rhs.getSignGrade();
	out << " and minimum execution grade: " << rhs.getExecutionGrade();
	return out;
}

std::string const & Form::getName() const {
	return _name;
}

bool Form::isSigned() const {
	return _signed;
}

int Form::getSignGrade() const {
	return _sign_grade;
}

int Form::getExecutionGrade() const {
	return _execution_grade;
}

void Form::beSigned(Bureaucrat const & signatory) {
	if (signatory.getGrade() > _sign_grade) {
		throw Form::GradeTooLowException();
	} else {
		_signed = true;
	}
}

Form::GradeTooHighException::GradeTooHighException():
	std::runtime_error("Grade too high !")
{}

Form::GradeTooLowException::GradeTooLowException():
	std::runtime_error("Grade too low !")
{}
