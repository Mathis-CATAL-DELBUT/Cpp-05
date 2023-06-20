/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:55:34 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/06/20 14:40:07 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

class AForm;

class Bureaucrat
{
    private :
        const std::string name;
        int grade;
        Bureaucrat();
    public:
        class GradeTooHighException: public std::exception 
        {
            public:
                virtual const char* what() const throw();   
        };
        
    public:
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
    
    public:
        ~Bureaucrat();
        Bureaucrat(const std::string name, int grade);
    
    public:
        int getGrade(void) const;
        const std::string getName(void) const;      
        void  incrementation(void);
        void decrementation(void);
        void signForm(AForm& form);
        void executeForm(AForm const & form);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& src);

#endif