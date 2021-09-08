#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class PresidentialPardonForm: public Form {

public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string const target);
	PresidentialPardonForm(PresidentialPardonForm const & original);
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);

	virtual void execute (Bureaucrat const & executor) const;

private:
	std::string const _target;
};

#endif
