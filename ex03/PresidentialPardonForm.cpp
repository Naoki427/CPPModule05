#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm",25,5), _target(target) {
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &origin) : AForm(origin), _target(origin.getTarget()) {
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm &origin){
	std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
	if(this == &origin)
		return *this;
	_isSingned = origin.getIsSingned();
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	try {
		if ( _executeGrade < executor.getGrade()) {
			throw  PresidentialPardonForm::GradeTooLowException();
		} else if ( _isSingned == false) {
			throw PresidentialPardonForm::NoSignatureException();
		} else {
			std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
		}
	} catch (const PresidentialPardonForm::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	} catch (const PresidentialPardonForm::NoSignatureException& e) {
		std::cerr << e.what() << std::endl;
	}
}

std::string  PresidentialPardonForm::getTarget() const {
	return _target;
}