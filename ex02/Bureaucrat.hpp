#pragma once
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;
	Bureaucrat( void );
public:
	Bureaucrat(const std::string name,int grade);
	Bureaucrat(const Bureaucrat &origin);
	virtual ~Bureaucrat();
	Bureaucrat& operator = (const Bureaucrat &origin);
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
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void setGrade(int grade);
	void executeForm(AForm const & form);
};
std::ostream& operator <<(std::ostream& os, const Bureaucrat& obj);