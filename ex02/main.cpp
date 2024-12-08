#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	Bureaucrat ishiba("Ishiba",1);
	std::cout << "\033[33m----------ShrubberyCreationForm----------\033[0m" << std::endl;
	AForm *formA = new ShrubberyCreationForm("home");
	formA->beSinged(ishiba);
	ishiba.executeForm(*formA);
	std::cout << std::endl;

	std::cout << "\033[33m----------RobotomyRequestForm----------\033[0m" << std::endl;
	AForm *formB = new RobotomyRequestForm("Darvish");
	formB->beSinged(ishiba);
	ishiba.executeForm(*formB);
	std::cout << std::endl;
	
	std::cout << "\033[33m----------PresidentialPardonForm----------\033[0m" << std::endl;
	AForm *formC= new PresidentialPardonForm("Arthur");
	formC->beSinged(ishiba);
	ishiba.executeForm(*formC);
	std::cout << std::endl;

	delete formA;
	delete formB;
	delete formC;
	return 0;
}