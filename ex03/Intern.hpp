#pragma once
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
public:
	Intern();
	Intern(const Intern &origin);
	virtual ~Intern();
	Intern& operator = (const Intern &origin);
	AForm *getShrubberyCreationForm(std::string target);
	AForm *getRobotomyRequestForm(std::string target);
	AForm *getPresidentialPardonForm(std::string target);
	AForm *makeForm(std::string form_name,std::string target);
};

