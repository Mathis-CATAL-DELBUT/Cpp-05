/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:08:41 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/06/19 10:43:21 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// Form::Form(){}

Form::~Form(){}

Form::Form(std::string name, const int sign, const int exec) : 
name(name), grade_sign(sign), grade_exec(exec)
{
    if (sign < 1 || exec < 1)
        throw Form::GradeTooHighException();
    else if (sign > 150 || exec > 150)
        throw Form::GradeTooLowException();
    else
        this->signature = false;
}

std::string Form::getName(void) const
{return this->name;}

bool Form::getSignature(void) const
{return this->signature;}

int Form::getGrade_sign(void) const
{return this->grade_sign;}

int Form::getGrade_exec(void) const
{return this->grade_exec;}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
    out << "Form " << form.getName() << " is ";
    if (form.getSignature())
        out << "signed";
    else
        out << "not signed";
    out << " and requires a grade " << form.getGrade_sign() << " to be signed and a grade " << form.getGrade_exec() << " to be executed." << std::endl;
    return out;
}

const char* Form::GradeTooHighException::what() const throw()
{return "Grade too high";}

const char* Form::GradeTooLowException::what() const throw()
{return "Grade too low";}

void Form::beSigned(Bureaucrat& bureaucrat)
{
   if (bureaucrat.getGrade() <= this->getGrade_sign())
        this->signature = true;
    else
    {
        throw Form::GradeTooLowException();
    }
}