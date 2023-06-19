/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:43:47 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/06/19 23:58:22 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat;

class Form
{
    private:
        std::string name;
        bool signature;
        const int grade_sign;
        const int grade_exec;

    private:
        Form();
        
        

    public:
        ~Form();
        Form(std::string name, const int sign, int exec);

    public:
        class GradeTooHighException : public std::exception
        {
            virtual const char* what() const throw();
        };

    public:
        class GradeTooLowException : public std::exception
        {
            virtual const char* what() const throw();
        };
    
    public:
        class AlreadySignedException : public std::exception
        {
            virtual const char* what() const throw();
        };
    
    public:
        class NotSignedException : public std::exception
        {
            virtual const char* what() const throw();
        };

    public:
        virtual void action() const = 0;  
    
    public:
        std::string getName(void) const;
        bool getSignature(void) const;
        int getGrade_sign(void) const;
        int getGrade_exec(void) const;
        void beSigned(Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& out, const Form& src);

#endif