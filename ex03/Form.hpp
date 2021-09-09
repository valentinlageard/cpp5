#ifndef Form_HPP
# define Form_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

public:
	Form();
	Form(std::string name, int sign_grade, int execution_grade);
	Form(Form const & original);
	virtual ~Form();
	Form & operator=(Form const & rhs);

	std::string const & getName() const;
	bool isSigned() const;
	int getSignGrade() const;
	int getExecutionGrade() const;

	void checkExecutability(Bureaucrat const & executor) const;

	void beSigned(Bureaucrat const & signatory);
	virtual void execute (Bureaucrat const & executor) const = 0;

	class GradeTooHighException: public std::runtime_error {
	public:
		GradeTooHighException();
	};

	class GradeTooLowException: public std::runtime_error {
	public:
		GradeTooLowException();
	};

	class FormAlreadySigned: public std::runtime_error {
	public:
		FormAlreadySigned();
	};

	class FormNotSigned: public std::runtime_error {
	public:
		FormNotSigned();
	};

private:
	std::string const _name;
	bool _signed;
	int const _sign_grade;
	int const _execution_grade;
};

std::ostream & operator<<(std::ostream & out, Form const & rhs);

#endif
