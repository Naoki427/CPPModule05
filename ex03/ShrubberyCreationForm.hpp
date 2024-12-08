#pragma once
#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm :  public AForm
{
private:
	const std::string _target;
	ShrubberyCreationForm( void );
public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &origin);
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm& operator = (const ShrubberyCreationForm &origin);
	virtual void execute(Bureaucrat const & executor) const;
	std::string  getTarget() const;
};