#ifndef Intern_HPP
# define Intern_HPP

# include <iostream>
# include <string>
# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

class Form;

class Intern {

public:
	Intern();
	Intern(Intern const & original);
	virtual ~Intern();
	Intern & operator=(Intern const & rhs);

	Form * makeForm(std::string const & form_name, std::string const & form_target);

	typedef Form * (Intern::*FormConstructor)(std::string);

private:
	Form * _newShrubberyCreationForm(std::string target);
	Form * _newRobotomyRequestForm(std::string target);
	Form * _newPresidentialPardonForm(std::string target);

	static FormConstructor _form_constructors[3];
	static std::string _form_names[3];
};

#endif
