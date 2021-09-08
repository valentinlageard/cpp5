#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>
# include "Form.hpp"

class RobotomyRequestForm: public Form {

public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string const target);
	RobotomyRequestForm(RobotomyRequestForm const & original);
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);

	virtual void execute (Bureaucrat const & executor) const;

private:
	std::string const _target;
};

#endif
