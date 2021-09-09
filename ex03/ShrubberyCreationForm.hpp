#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "Form.hpp"

class ShrubberyCreationForm: public Form {

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string const target);
	ShrubberyCreationForm(ShrubberyCreationForm const & original);
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);

	virtual void execute (Bureaucrat const & executor) const;

private:
	std::string const _target;
	static const std::string _ascii_tree;
};

#endif
