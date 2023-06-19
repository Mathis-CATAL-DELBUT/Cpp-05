/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:00:47 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/06/18 13:42:14 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {   
        // Bureaucrat trop_bas ("bab", 151); //rang trop bas
        // Bureaucrat trop_haut("bob", 0); //rang trop haut

        //rang 1 + incrementation
        {
            // Bureaucrat Bureaucrat("Boss", 1);
            // std::cout << Bureaucrat;
            // Bureaucrat.incrementation();
        }

        //rang 150 + decrementation
        {
            // Bureaucrat Bureaucrat("Worker", 150);
            // std::cout << Bureaucrat;
            // Bureaucrat.decrementation();
        }

        //situation Normal
        {
            // Bureaucrat Bureaucrat("Boss", 1);
            // std::cout << Bureaucrat;
            // Bureaucrat.decrementation();
            // std::cout << Bureaucrat;
            // Bureaucrat.incrementation();
            // std::cout << Bureaucrat;
        }
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl; 
    }
}