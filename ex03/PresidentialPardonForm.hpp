#pragma once
#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm :  public AForm
{
private:
	const std::string _target;
	PresidentialPardonForm( void );
public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &origin);
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm& operator = (const PresidentialPardonForm &origin);
	virtual void execute(Bureaucrat const & executor) const;
	std::string  getTarget() const;
};