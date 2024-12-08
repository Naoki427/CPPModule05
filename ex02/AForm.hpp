#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
protected:
	const std::string _name;
	bool	_isSingned;
	const int	_signGrade;
	const int	_executeGrade;
	AForm( void );
public:
	AForm(std::string name, int sign_grade,int execute_grade);
	AForm(const AForm &origin);
	virtual ~AForm();
	AForm& operator = (const AForm &origin);
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
	class NoSignatureException : public std::exception
	{
		public:
			virtual const char* what() const throw ();
	} ;
	const std::string getName() const;
	bool		getIsSingned() const;
	int	getSignGrade() const;
	int	getExecuteGrade() const;
	void		beSinged(Bureaucrat &bureaucrat);
	virtual void execute(Bureaucrat const & executor) const = 0;
};
std::ostream& operator <<(std::ostream& os, const AForm& obj);