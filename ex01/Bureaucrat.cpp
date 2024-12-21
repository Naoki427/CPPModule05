#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) :_name(name){
	std::cout << "Bureaucrat constructor called" << std::endl;
	setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &origin) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = origin;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator= (const Bureaucrat &origin){
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if(this == &origin)
		return *this;
	setGrade(origin.getGrade());
	return *this;
}

const char* Bureaucrat::GradeTooHighException::what() const throw () {
	return "\033[31mGrade too high\033[0m";
}

const char* Bureaucrat::GradeTooLowException::what() const throw () {
	return "\033[31mGrade too low\033[0m";
}

const std::string Bureaucrat::getName() const{
	return _name;
}

int Bureaucrat::getGrade() const{
	return _grade;
}

void Bureaucrat::incrementGrade() {
	std::cout << "incrementGrade called" << std::endl;
	setGrade(_grade - 1);
}

void Bureaucrat::decrementGrade() {
	std::cout << "decrementGrade called" << std::endl;
	setGrade(_grade + 1);
}

void Bureaucrat::setGrade(int grade) {
	try {
		if (grade < 1) {
			throw Bureaucrat::GradeTooHighException();
		} else if (grade > 150 ) {
			throw Bureaucrat::GradeTooLowException();
		} else {
			_grade = grade;
		}	
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl;
		if (_grade < 1 || _grade > 150)
		_grade = 150;
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
		if (_grade < 1 || _grade > 150)
		_grade = 150;
	}
}

std::ostream& operator <<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." <<  std::endl;
	return os;
}

