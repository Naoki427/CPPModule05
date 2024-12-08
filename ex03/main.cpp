#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
	Bureaucrat ishiba("Ishiba",1);
	Intern yoshimi;
	std::cout << "\033[33m----------ShrubberyCreationForm----------\033[0m" << std::endl;
	AForm *formA = yoshimi.makeForm("shrubbery creation", "Bender");
	if(formA) {
		formA->beSinged(ishiba);
		ishiba.executeForm(*formA);
	}
	std::cout << std::endl;

	std::cout << "\033[33m----------RobotomyRequestForm----------\033[0m" << std::endl;
	AForm *formB = yoshimi.makeForm("robotomy request", "Bender");
	if(formB) {
		formB->beSinged(ishiba);
		ishiba.executeForm(*formB);
	}
	std::cout << std::endl;
	
	std::cout << "\033[33m----------PresidentialPardonForm----------\033[0m" << std::endl;
	AForm *formC = yoshimi.makeForm("presidential pardon", "Bender");
	if(formC){
		formC->beSinged(ishiba);
		ishiba.executeForm(*formC);
	}
	std::cout << std::endl;

	delete formA;
	delete formB;
	delete formC;
	return 0;
}