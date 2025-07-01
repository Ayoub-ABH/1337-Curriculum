/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:45:25 by aait-bab          #+#    #+#             */
/*   Updated: 2025/05/17 16:21:15 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP

# define FORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class Form {
    private :
        const std::string   name;
        const int           gradeToSign;
        const int           gradeToExecute;
        bool                isSigned;
    public:
        Form();
        Form(const std::string& name, int gradeToSign, int gradeToExecute);
        Form(const Form& form);
        ~Form();

        Form&         operator=(const Form& form);

        const std::string& getName() const;
        bool  getIsSigned() const;
        const int& getGradeToSign() const;
        const int& getGradeToExecute() const;

        void beSigned(const Bureaucrat& b);
        
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

std::ostream&	operator<<(std::ostream &out, const Form& form);

#endif