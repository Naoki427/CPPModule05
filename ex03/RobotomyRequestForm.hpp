#pragma once
#include <iostream>
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>  

class RobotomyRequestForm :  public AForm
{
private:
	const std::string _target;
	RobotomyRequestForm( void );
public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &origin);
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm& operator = (const RobotomyRequestForm &origin);
	virtual void execute(Bureaucrat const & executor) const;
	std::string  getTarget() const;
};