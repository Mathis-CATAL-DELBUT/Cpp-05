/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:22:44 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/06/20 11:31:36 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : 
AForm("RobotomyRequestForm", 72, 45, "") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
AForm("RobotomyRequestForm", 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) :
AForm(copy) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
    AForm::operator=(copy);
    return (*this);
}

void RobotomyRequestForm::action() const
{
    static int i = 0;
    if (i == 0)
    {
        i = 1;
        std::cout << getTarget() << " has been robotomized successfully" << std::endl;  
    }
    else
    {
        i = 0;
        std::cout << getTarget() << " robotomization failed" << std::endl;
    }
}