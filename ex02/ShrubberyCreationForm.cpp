#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm",145,137), _target(target) {
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &origin) : AForm(origin), _target(origin.getTarget()) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm &origin){
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	if(this == &origin)
		return *this;
	_isSingned = origin.getIsSingned();
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	try {
		if ( _executeGrade < executor.getGrade()) {
			throw  ShrubberyCreationForm::GradeTooLowException();
		} else if ( _isSingned == false) {
			throw ShrubberyCreationForm::NoSignatureException();
		} else {
			std::ofstream outFile((_target + "_shrubbery").c_str());
			if (!outFile) {
				std::cerr << "Failed to open the file." << std::endl;
			}
			outFile << "     ^     " << "     ^     " << "     ^     " << std::endl;
			outFile << "    ^^^    " << "    ^^^    " << "    ^^^    " << std::endl;
			outFile << "   ^^^^^   " << "   ^^^^^   " << "   ^^^^^   " << std::endl;
			outFile << "  ^^^^^^^  " << "  ^^^^^^^  " << "  ^^^^^^^  " << std::endl;
			outFile << " ^^^^^^^^^ " << " ^^^^^^^^^ " << " ^^^^^^^^^ " << std::endl;
			outFile << "    |||    " << "    |||    " << "    |||    " << std::endl;
			outFile << "    |||    " << "    |||    " << "    |||    " << std::endl;
		    outFile.close();
		}
	} catch (const ShrubberyCreationForm::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	} catch (const ShrubberyCreationForm::NoSignatureException& e) {
		std::cerr << e.what() << std::endl;
	}
}

std::string ShrubberyCreationForm::getTarget() const {
	return _target;
}