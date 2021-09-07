#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Form god_form = Form("god form", 0, 0);
	}
	catch (std::exception & e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try {
		Form ant_form = Form("and form", 151, 151);
	}
	catch (std::exception & e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	Form a_stupid_form = Form("28A-293", 28, 28);
	Bureaucrat hermes_conrad = Bureaucrat("Hermes Conrad", 36);
	Bureaucrat morgan_proctor = Bureaucrat("Morgan Proctor", 19);

	hermes_conrad.signForm(a_stupid_form);
	std::cout << a_stupid_form << std::endl;
	morgan_proctor.signForm(a_stupid_form);
	std::cout << a_stupid_form << std::endl;

	return 0;
}
