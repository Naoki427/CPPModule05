#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &origin) {
	std::cout << "Intern copy constructor called" << std::endl;
	*this = origin;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

Intern& Intern::operator= (const Intern &origin){
	std::cout << "Intern copy assignment operator called" << std::endl;
	if(this == &origin)
		return *this;
	return *this;
}

AForm *Intern::getShrubberyCreationForm(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm *Intern::getRobotomyRequestForm(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm *Intern::getPresidentialPardonForm(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm * Intern::makeForm(std::string form_name,std::string target) {
	AForm *(Intern::*funcarr[])(std::string target) = {&Intern::getShrubberyCreationForm,&Intern::getRobotomyRequestForm,&Intern::getPresidentialPardonForm};
	std::string form[3] = {"shrubbery creation","robotomy request","presidential pardon"};
	for(int i = 0; i < 3; i++) {
		if (form_name == form[i]) {
			return (this->*funcarr[i])(target);
		}
	}
	return NULL;
}