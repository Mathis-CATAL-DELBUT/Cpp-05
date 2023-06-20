/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:04:04 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/06/20 14:33:49 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
    this->grade = grade;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

const std::string Bureaucrat::getName(void) const
{return this->name;}

int Bureaucrat::getGrade(void) const
{return this->grade;}

void  Bureaucrat::incrementation(void)
{
    if (this->grade == 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade--;
}


void Bureaucrat::decrementation(void)
{
    if (this->grade == 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return("Grade Too High Exception");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return("Grade Too Low Exception");
}

std::ostream &operator<<( std::ostream &out, const Bureaucrat &src )
{
    out << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
    return (out);
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &src)
{
    this->grade = src.getGrade();
    return (*this);
}

void Bureaucrat::signForm(Form& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signs " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->getName() << " cannot sign " << form.getName() <<
        " because " << e.what() << std::endl;
    }
}
