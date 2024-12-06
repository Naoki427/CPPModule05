#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string _name;
	bool	_isSingned;
	const int	_signGrade;
	const int	_executeGrade;
	Form( void );
public:
	Form(std::string name, int sign_grade,int execute_grade);
	Form(const Form &origin);
	virtual ~Form();
	Form& operator = (const Form &origin);
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw ();
	} ;
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw ();
	} ;
	const std::string getName() const;
	bool		getIsSingned() const;
	int	getSignGrade() const;
	int	getExecuteGrade() const;
	void		beSinged(Bureaucrat &bureaucrat);
};
std::ostream& operator <<(std::ostream& os, const Form& obj);