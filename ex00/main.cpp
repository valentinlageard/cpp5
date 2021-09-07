#include <iostream>
#include "Bureaucrat.hpp"

int main() {

	Bureaucrat hermes_conrad = Bureaucrat("Hermes Conrad", 36);
	Bureaucrat morgan_proctor = Bureaucrat("Morgan Proctor", 19);

	std::cout << hermes_conrad << std::endl;

	for (int i=0; i < 40; i++) {
		try {
			hermes_conrad++;
		}
		catch (std::exception & e) {
			std::cout << "Exception what : " << e.what() << std::endl;
		}
		std::cout << hermes_conrad << std::endl;
	}

	std::cout << morgan_proctor << std::endl;

	for (int i=0; i < 140; i++) {
		try {
			morgan_proctor--;
		}
		catch (std::exception & e) {
			std::cout << "Exception what : " << e.what() << std::endl;
		}
		std::cout << morgan_proctor << std::endl;
	}

	return 0;
}
