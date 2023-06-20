/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:00:47 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/06/20 14:21:05 by mcatal-d         ###   ########.fr       */
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
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try 
    {
        // Pesident
        {
            // Bureaucrat b("Ted", 150);
		    // PresidentialPardonForm f("PRESIDENT FORM");
            // std::cout << f << std::endl;
            // b.signForm(f);
		    // std::cout << f << std::endl;
		    // b.executeForm(f);
        }
        // Robot
        {
            // Bureaucrat b("Ted", 1);
		    // RobotomyRequestForm f("ROBOT FORM");
            // std::cout << f << std::endl;
            // b.signForm(f);
		    // std::cout << f << std::endl;
		    // b.executeForm(f);
        }
        //Arbre ASCII
        {
            Bureaucrat b("Ted", 1);
		    ShrubberyCreationForm f("TREE FORM");
            std::cout << f << std::endl;
            b.signForm(f);
		    std::cout << f << std::endl;
		    b.executeForm(f);
        }
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}