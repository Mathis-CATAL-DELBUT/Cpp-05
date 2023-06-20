/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:00:47 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/06/20 14:16:48 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"
#define GREY    "\033[90m"
#define BOLD    "\033[1m"
#define UNDERLINE   "\033[4m"

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try {
		Intern someRandomIntern;
		Bureaucrat Boss("Boss", 1);
		AForm* rrf;
		AForm* ppf;
		AForm* scf;
		
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
		scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		
		Boss.signForm(*rrf);
		Boss.signForm(*ppf);
		Boss.signForm(*scf);
		Boss.executeForm(*scf);
		Boss.executeForm(*ppf);
		Boss.executeForm(*rrf);
		
		delete rrf;
		delete ppf;
		delete scf;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	// try {
	// 	Intern someRandomIntern;
	// 	AForm* rrf;
	// 	rrf = someRandomIntern.makeForm("inexistant form", "Bender");	
	// }
	// catch (std::exception& e) {
	// 	std::cout << e.what() << std::endl;
	// }
}