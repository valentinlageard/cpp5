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

	void beSigned(Bureaucrat const & signatory);

	class GradeTooHighException: public std::runtime_error {
	public:
		GradeTooHighException();
	};

	class GradeTooLowException: public std::runtime_error {
	public:
		GradeTooLowException();
	};

private:
	std::string const _name;
	bool _signed;
	int const _sign_grade;
	int const _execution_grade;
};

std::ostream & operator<<(std::ostream & out, Form const & rhs);

#endif
