#include "Bureaucrat.hpp"

int main() {
	std::cout << "\033[33m----------normal----------\033[0m" << std::endl;
	Bureaucrat ishiba("Ishiba",1);
	std::cout << ishiba << std::endl;
	std::cout << std::endl;

	std::cout << "\033[33m----------too high----------\033[0m" << std::endl;
	Bureaucrat kishida("Kishida",0);
	std::cout << kishida << std::endl;
	std::cout << std::endl;

	std::cout << "\033[33m----------too low----------\033[0m" << std::endl;
	Bureaucrat yoshimi("Yoshimi",3000);
	std::cout << yoshimi << std::endl;
	std::cout << std::endl;

	std::cout << "\033[33m----------invalid increment----------\033[0m" << std::endl;
	ishiba.incrementGrade();
	std::cout << ishiba << std::endl;
	std::cout << std::endl;

	std::cout << "\033[33m----------invalid decrement----------\033[0m" << std::endl;
	yoshimi.decrementGrade();
	std::cout << yoshimi << std::endl;
	std::cout << std::endl;

	std::cout << "\033[33m----------valid increment----------\033[0m" << std::endl;
	yoshimi.incrementGrade();
	std::cout << yoshimi << std::endl;
	std::cout << std::endl;

	std::cout << "\033[33m----------invalid decrement----------\033[0m" << std::endl;
	ishiba.decrementGrade();
	std::cout << ishiba << std::endl;
	std::cout << std::endl;
	return 0;
}