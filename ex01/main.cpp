#include "Form.hpp"

int main() {
	std::cout << "\033[33m----------Normal form----------\033[0m" << std::endl;
	Form form_a("Form A",50,30);
	std::cout << form_a;
	std::cout << std::endl;
	std::cout << "\033[33m----------Invalid form[high sign grade]----------\033[0m" << std::endl;
	Form form_b("Form B",0,30);
	std::cout << form_b;
	std::cout << std::endl;
	std::cout << "\033[33m----------Invalid form[low sign grade]----------\033[0m" << std::endl;
	Form form_c("Form C",151,30);
	std::cout << form_c;
	std::cout << std::endl;
	std::cout << "\033[33m----------Invalid form[high execute grade]----------\033[0m" << std::endl;
	Form form_d("Form D",50,0);
	std::cout << form_d;
	std::cout << std::endl;
	std::cout << "\033[33m----------Invalid form[low execute grade]----------\033[0m" << std::endl;
	Form form_e("Form B",50,151);
	std::cout << form_e;
	std::cout << std::endl;
	std::cout << "\033[33m----------Sign form[invalid]----------\033[0m" << std::endl;
	Bureaucrat yoshimi("Yoshimi",150);
	std::cout << yoshimi;
	form_a.beSinged(yoshimi);
	std::cout << form_a;
	std::cout << std::endl;
	std::cout << "\033[33m----------Sign form[valid]----------\033[0m" << std::endl;
	Bureaucrat ishiba("Ishiba",1);
	std::cout << ishiba;
	form_a.beSinged(ishiba);
	std::cout << form_a;
	std::cout << std::endl;
	return 0;
}