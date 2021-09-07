#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "Form.hpp"

class Form;

class Bureaucrat {

public:
	Bureaucrat();
	Bureaucrat(std::string const & name, int grade);
	Bureaucrat(Bureaucrat const & original);
	virtual ~Bureaucrat();
	Bureaucrat & operator=(Bureaucrat const & rhs);

	Bureaucrat operator++();
	Bureaucrat operator++(int);
	Bureaucrat operator--();
	Bureaucrat operator--(int);

	std::string const & getName() const;
	int getGrade() const;

	void signForm(Form & form);

	class GradeTooHighException: public std::runtime_error {
	public:
		GradeTooHighException();
	};

	class GradeTooLowException: public std::runtime_error {
	public:
		GradeTooLowException();
	};

private:
	const std::string _name;
	int _grade;
};

std::ostream & operator<<(std::ostream & out, Bureaucrat const & rhs);

#endif
