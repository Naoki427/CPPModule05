#include "Form.hpp"

Form::Form(std::string name, int sign_grade,int execute_grade) : _name(name), _isSingned(false),
	_signGrade(sign_grade > 0 && sign_grade < 151 ? sign_grade : 1),
	_executeGrade(execute_grade > 0 && execute_grade < 151 ? execute_grade : 1) {
	std::cout << "Form constructor called" << std::endl;
try {
		if (sign_grade < 1)
		{
			std::cout << "\033[31m[Grade to sign]\033[0m";
			throw Form::GradeTooHighException();
			
		}
		else if (sign_grade > 150)
		{
			std::cout << "\033[31m[Grade to sign]\033[0m";
			throw Form::GradeTooLowException();
		}
	} catch (const Form::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	} catch (const Form::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
try {
		if (execute_grade < 1)
		{
			std::cout << "\033[31m[Grade to execute]\033[0m";
			throw Form::GradeTooHighException();
		}
		else if (execute_grade > 150)
		{
			std::cout << "\033[31m[Grade to execute]\033[0m";
			throw Form::GradeTooLowException();
		}
	} catch (const Form::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	} catch (const Form::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
}

Form::Form(const Form &origin): _name(origin.getName()), _isSingned(origin.getIsSingned()), _signGrade(origin.getSignGrade()),_executeGrade(origin.getExecuteGrade()){
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
}

Form& Form::operator= (const Form &origin){
	std::cout << "Form copy assignment operator called" << std::endl;
	if(this == &origin)
		return *this;
	_isSingned = origin.getIsSingned();
	return *this;
}

const char* Form::GradeTooHighException::what() const throw () {
	return "\033[31mGrade too high\033[0m";
}

const char* Form::GradeTooLowException::what() const throw () {
	return "\033[31mGrade too low\033[0m";
}

const std::string Form::getName() const{
	return _name;
}

bool		Form::getIsSingned() const {
	return _isSingned;
}

int	Form::getSignGrade() const {
	return _signGrade;
}

int	Form::getExecuteGrade() const {
	return _executeGrade;
}

void		Form::beSinged(Bureaucrat &bureaucrat) {
	if(bureaucrat.getGrade() <= _signGrade) {
		_isSingned = true;
		std::cout << bureaucrat.getName() << " signed " << _name <<std::endl;
	} else {
		std::cout << bureaucrat.getName() << " couldn't sign " << _name << " because the required grade was not met." << std::endl;
	}
}

std::ostream& operator <<(std::ostream& os, const Form& obj) {
	os << obj.getName();
	if (obj.getIsSingned()) {
		os << " is signed; the grade to sign is ";
	} else {
		os << " isn't signed; the grade to sign is ";
	}
	os << obj.getSignGrade() << ", the grade to execute is " << obj.getExecuteGrade() << "." << std::endl;
	return os;
}