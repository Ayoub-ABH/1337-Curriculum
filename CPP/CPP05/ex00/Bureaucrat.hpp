/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 21:49:02 by aait-bab          #+#    #+#             */
/*   Updated: 2025/07/01 15:57:02 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP

#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
    private:
        const std::string   name;
        int                 grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat& bureaucrat);
        ~Bureaucrat();
        
		Bureaucrat&         operator=(const Bureaucrat& bureaucrat);
        const std::string&  getName() const;
        int                 getGrade() const;
        void                incrementGrade();
        void                decrementGrade();

        class GradeTooHighException : public std::exception{
            private:
                const char *msg;
            public:
                GradeTooHighException(const char *msg) throw();
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception{
            private:
                const char *msg;
            public:
                GradeTooLowException(const char *msg) throw();
                const char* what() const throw();
        };
};

std::ostream&	operator<<(std::ostream &out, const Bureaucrat& bureaucrat);

#endif