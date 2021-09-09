#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():
	Form("shrubbery creation", 145, 137),
	_target("dummy")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target):
	Form("shrubbery creation", 145, 137),
	_target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & original):
	Form("shrubbery creation", 145, 137),
	_target(original._target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs) {
	if (this == &rhs) {
		return *this;
	}
	Form::operator=(rhs);
	return *this;
}

void ShrubberyCreationForm::execute (Bureaucrat const & executor) const {
	try {
		checkExecutability(executor);
		std::ofstream file;
		std::string filename = _target + "_shrubbery";
		file.open(filename.c_str());
		file.exceptions(std::ofstream::badbit | std::ofstream::failbit);
		try {
			file << _ascii_tree << std::endl;
			file.close();
		}
		catch (const std::exception & e) {
			file.close();
			throw;
		}
	}
	catch (const std::exception & e) {
		throw;
	}
}

std::string const ShrubberyCreationForm::_ascii_tree =
"           \\/ |    |/\n"
"        \\/ / \\||/  /_/___/_\n"
"         \\/   |/ \\/\n"
"    _\\__\\_\\   |  /_____/_\n"
"           \\  | /          /\n"
"  __ _-----`  |{,-----------~\n"
"            \\ }{\n"
"             }{{\n"
"             }}{\n"
"             {{}\n"
"       , -=-~{ .-^- _";
