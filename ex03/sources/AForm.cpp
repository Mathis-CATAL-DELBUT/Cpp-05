/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:08:41 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/06/20 14:13:57 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Form::Form(){}

AForm::~AForm() {}

AForm::AForm(const std::string name, int sign, int exec, const std::string& target) : 
name(name), grade_sign(sign), grade_exec(exec), target(target)
{
    if (sign < 1 || exec < 1)
        throw AForm::GradeTooHighException();
    else if (sign > 150 || exec > 150)
        throw AForm::GradeTooLowException();
    else
        this->signature = false;
}

AForm::AForm(const AForm& copy) :
name(copy.name), signature(copy.signature), grade_sign(copy.grade_sign), 
grade_exec(copy.grade_exec), target(copy.target) {}

std::string AForm::getName(void) const
{return this->name;}

bool AForm::getSignature(void) const
{return this->signature;}

int AForm::getGrade_sign(void) const
{return this->grade_sign;}

int AForm::getGrade_exec(void) const
{return this->grade_exec;}

std::string AForm::getTarget(void) const
{return this->target;}

std::ostream& operator<<(std::ostream& out, const AForm& Aform)
{
    out << "AForm " << Aform.getName() << " is ";
    if (Aform.getSignature())
        out << "signed";
    else
        out << "not signed";
    out << " and requires a grade " << Aform.getGrade_sign() << " to be signed and a grade " << Aform.getGrade_exec() << " to be executed.";
    return out;
}

AForm& AForm::operator=(const AForm& copy)
{
    if (this != &copy)
        this->signature = copy.signature;
    return *this;
}


void AForm::beSigned(Bureaucrat& bureaucrat)
{
   if (bureaucrat.getGrade() <= this->getGrade_sign())
        this->signature = true;
    else
    {
        throw AForm::GradeTooLowException();
    }
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > this->getGrade_exec())
        throw AForm::GradeTooLowException();
    else if (!this->getSignature())
        throw AForm::NotSignedException();
    else
    {
        std::cout << executor.getName() << " executes " << this->getName() << std::endl;
        this->action();
    }
}

const char* AForm::NotSignedException::what() const throw()
{return "Form not signed";}

const char* AForm::GradeTooHighException::what() const throw()
{return "Grade too high";}

const char* AForm::GradeTooLowException::what() const throw()
{return "Grade too low";}