/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:52:23 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/06/20 14:11:01 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){}

Intern::~Intern(){}

Intern::Intern(Intern const & src)
{
    *this = src;
}

Intern & Intern::operator=(Intern const & src)
{
    (void)src;
    return (*this);
}

const char * Intern::FormNotFoundException::what() const throw()
{
    return ("Form not found");
}

AForm * Intern::makeRobotomyRequestForm(std::string const & target)
{
    return (new RobotomyRequestForm(target));
}

AForm * Intern::makePresidentialPardonForm(std::string const & target)
{
    return (new PresidentialPardonForm(target));
}

AForm * Intern::makeShrubberyCreationForm(std::string const & target)
{
    return (new ShrubberyCreationForm(target));
}

AForm * Intern::makeForm(std::string const & formName, std::string const & target)
{
    makeFormPtr makeForm[3];
    std::string formNames[3];
    formNames[0] = "robotomy request";
    formNames[1] = "presidential pardon";
    formNames[2] = "shrubbery creation";

    makeForm[0] = &Intern::makeRobotomyRequestForm;
    makeForm[1] = &Intern::makePresidentialPardonForm;
    makeForm[2] = &Intern::makeShrubberyCreationForm;

    for (int i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return ((this->*makeForm[i])(target));
        }
    }
    throw FormNotFoundException();
}