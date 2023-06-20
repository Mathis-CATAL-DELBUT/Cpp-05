/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:52:35 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/06/20 14:11:25 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

class AForm;

class Intern
{
    public:
        Intern();
        ~Intern();
        Intern(Intern const & src);
        
        Intern & operator=(Intern const & src);

        AForm * makeForm(std::string const & formName, std::string const & target);
        AForm * makeRobotomyRequestForm(std::string const & target);
        AForm * makePresidentialPardonForm(std::string const & target);
        AForm * makeShrubberyCreationForm(std::string const & target);
        typedef AForm * (Intern::*makeFormPtr)(std::string const & target);
        class FormNotFoundException : public std::exception
        {
            public:
                virtual const char * what() const throw();
        };
};

#endif