/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:55:34 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/06/20 14:33:25 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Form.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

class Form;

class Bureaucrat
{
    private :
        const std::string name;
        int grade;
        Bureaucrat();
        Bureaucrat &operator=(const Bureaucrat &copy);
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
        void signForm(Form& form);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& src);

#endif