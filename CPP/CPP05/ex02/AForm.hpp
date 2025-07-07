/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:58:06 by aait-bab          #+#    #+#             */
/*   Updated: 2025/07/07 15:52:24 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm {
    private :
        const std::string   name;
        const int           gradeToSign;
        const int           gradeToExecute;
        bool                isSigned;
    public:
        AForm();
        AForm(const std::string& name, int gradeToSign, int gradeToExecute);
        AForm(const AForm& AForm);
        virtual ~AForm();

        AForm&         operator=(const AForm& form);

        const std::string& getName() const;
        bool  getIsSigned() const;
        const int& getGradeToSign() const;
        const int& getGradeToExecute() const;

        void setIsSigned(bool otherIsSigned);
        
        virtual void beSigned(const Bureaucrat& b);
        virtual void execute(const Bureaucrat& executor) const = 0;
        
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
        class FormIsNotSignedException : public std::exception{
            private:
                const char *msg;
            public:
                FormIsNotSignedException(const char *msg) throw();
                const char* what() const throw();
        };
};

std::ostream&	operator<<(std::ostream &out, const AForm& form);

#endif
