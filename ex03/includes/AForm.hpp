/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:43:47 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/06/20 14:10:43 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat;

class AForm
{
    private:
        std::string name;
        bool signature;
        const int grade_sign;
        const int grade_exec;

    private:
        AForm();
        
        

    public:
        virtual ~AForm();
        AForm(std::string const name, int sign, int exec, const std::string& target);
        AForm(const AForm& copy);
        
    public :
        AForm& operator=(const AForm& copy);

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
        class NotSignedException : public std::exception
        {
            virtual const char* what() const throw();
        };

    public:
        virtual void action() const = 0;  
    
    public:
        std::string getName(void) const;
        const std::string target;
        bool getSignature(void) const;
        int getGrade_sign(void) const;
        int getGrade_exec(void) const;
        std::string getTarget(void) const;
        void beSigned(Bureaucrat& bureaucrat);
        void execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& out, const AForm& src);

#endif