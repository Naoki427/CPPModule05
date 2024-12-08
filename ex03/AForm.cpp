#include "AForm.hpp"

AForm::AForm(std::string name, int sign_grade,int execute_grade) : _name(name), _isSingned(false),
	_signGrade(sign_grade > 0 && sign_grade < 151 ? sign_grade : 1),
	_executeGrade(execute_grade > 0 && execute_grade < 151 ? execute_grade : 1) {
	std::cout << "AForm constructor called" << std::endl;
try {
		if (sign_grade < 1)
		{
			std::cerr << "\033[31m[Grade to sign]\033[0m";
			throw AForm::GradeTooHighException();
			
		}
		else if (sign_grade > 150)
		{
			std::cerr << "\033[31m[Grade to sign]\033[0m";
			throw AForm::GradeTooLowException();
		}
	} catch (const AForm::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	} catch (const AForm::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}
try {
		if (execute_grade < 1)
		{
			std::cerr << "\033[31m[Grade to execute]\033[0m";
			throw AForm::GradeTooHighException();
		}
		else if (execute_grade > 150)
		{
			std::cerr << "\033[31m[Grade to execute]\033[0m";
			throw AForm::GradeTooLowException();
		}
	} catch (const AForm::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	} catch (const AForm::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}
}

AForm::AForm(const AForm &origin): _name(origin.getName()), _isSingned(origin.getIsSingned()), _signGrade(origin.getSignGrade()),_executeGrade(origin.getExecuteGrade()){
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm() {
	std::cout << "AForm destructor called" << std::endl;
}

AForm& AForm::operator= (const AForm &origin){
	std::cout << "AForm copy assignment operator called" << std::endl;
	if(this == &origin)
		return *this;
	_isSingned = origin.getIsSingned();
	return *this;
}

const char* AForm::GradeTooHighException::what() const throw () {
	return "\033[31mGrade too high\033[0m";
}

const char* AForm::GradeTooLowException::what() const throw () {
	return "\033[31mGrade too low\033[0m";
}

const char* AForm::NoSignatureException::what() const throw () {
	return "\033[31mNo signature found\033[0m";
}

const std::string AForm::getName() const{
	return _name;
}

bool		AForm::getIsSingned() const {
	return _isSingned;
}

int	AForm::getSignGrade() const {
	return _signGrade;
}

int	AForm::getExecuteGrade() const {
	return _executeGrade;
}

void		AForm::beSinged(Bureaucrat &bureaucrat) {
	if(bureaucrat.getGrade() <= _signGrade) {
		_isSingned = true;
		std::cout << bureaucrat.getName() << " signed " << _name <<std::endl;
	} else {
		std::cout << bureaucrat.getName() << " couldn't sign " << _name << " because the required grade was not met." << std::endl;
	}
}

std::ostream& operator <<(std::ostream& os, const AForm& obj) {
	os << obj.getName();
	if (obj.getIsSingned()) {
		os << " is signed; the grade to sign is ";
	} else {
		os << " isn't signed; the grade to sign is ";
	}
	os << obj.getSignGrade() << ", the grade to execute is " << obj.getExecuteGrade() << "." << std::endl;
	return os;
}