/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:00:47 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/06/19 10:49:57 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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

// int main()
// {
//     try
//     {   
//         // Bureaucrat trop_bas ("bab", 151); //rang trop bas
//         // Bureaucrat trop_haut("bob", 0); //rang trop haut

//         //rang 1 + incrementation
//         {
//             // Bureaucrat Bureaucrat("Boss", 1);
//             // std::cout << Bureaucrat;
//             // Bureaucrat.incrementation();
//         }

//         //rang 150 + decrementation
//         {
//             // Bureaucrat Bureaucrat("Worker", 150);
//             // std::cout << Bureaucrat;
//             // Bureaucrat.decrementation();
//         }

//         //situation Normal
//         {
//             // Bureaucrat Bureaucrat("Boss", 1);
//             // std::cout << Bureaucrat;
//             // Bureaucrat.decrementation();
//             // std::cout << Bureaucrat;
//             // Bureaucrat.incrementation();
//             // std::cout << Bureaucrat;
//         }
//     }
//     catch (std::exception& e)
//     {
//         std::cout << e.what() << std::endl; 
//     }
// }

#include "Form.hpp"

int main()
{
    try 
    //situation normal
    {
        {
            // Form form("contrat", 10, 10);
            // Bureaucrat Boss("Boss", 1);
            // std::cout << RED << form << GREEN;
            // Boss.signForm(form);
            // std::cout << BLUE << form << RESET;
        }
        {
        // l'employe n'a pas le grade necessaire
            // Bureaucrat Worker("Worker", 150);
            // Form form("contrat", 10, 10);
            // std::cout << RED << form << MAGENTA;
            // Worker.signForm(form);
            // std::cout << RED << form << RESET;
        }
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}