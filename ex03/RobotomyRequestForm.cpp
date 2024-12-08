#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm",145,137), _target(target) {
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &origin) : AForm(origin), _target(origin.getTarget()) {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm &origin){
	std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	if(this == &origin)
		return *this;
	_isSingned = origin.getIsSingned();
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	try {
		if ( _executeGrade < executor.getGrade()) {
			throw  RobotomyRequestForm::GradeTooLowException();
		} else if ( _isSingned == false) {
			throw RobotomyRequestForm::NoSignatureException();
		} else {
			std::cout << "bzzz-bzzzzzzzzz..." << std::endl;
			std::srand(std::time(0));
			int random_number = std::rand() % 2; 
			if (random_number == 0) {
				std::cout << _target << "'s robotomy was successful" << std::endl;
			} else {
				std::cout << _target << "'s robotomy faced complications" << std::endl;
			}
		}
	} catch (const RobotomyRequestForm::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	} catch (const RobotomyRequestForm::NoSignatureException& e) {
		std::cerr << e.what() << std::endl;
	}
}

std::string  RobotomyRequestForm::getTarget() const {
	return _target;
}