/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:55:45 by aait-bab          #+#    #+#             */
/*   Updated: 2025/07/07 15:16:41 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : gradeToSign(1),gradeToExecute(1)
{
    this->isSigned = false;
}

Form::Form(const std::string& name,const int gradeToSign,const int gradeToExecute):
name(name),
gradeToSign(gradeToSign),
gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException("Error: grade too High!");
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException("Error: grade too low!");
    this->isSigned = false;
}

Form::Form(const Form& form): name(form.getName()), gradeToSign(form.getGradeToSign()), gradeToExecute(form.getGradeToExecute())
{
    this->isSigned = form.getIsSigned();
}

Form::~Form(){}

const std::string& Form::getName() const
{
    return this->name;
}

bool Form::getIsSigned() const
{
    return this->isSigned;
}

const int& Form::getGradeToSign() const
{
    return this->gradeToSign;        
}

const int& Form::getGradeToExecute() const
{
    return this->gradeToExecute;     
}

void Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() <= this->gradeToSign)
        this->isSigned = true;
    else
        throw Form::GradeTooLowException("Error: Grade too low to sign this form!");
}

Form::GradeTooHighException::GradeTooHighException(const char *msg) throw() : msg(msg)
{
}

Form::GradeTooLowException::GradeTooLowException(const char *msg) throw() : msg(msg)
{
}

const char* Form::GradeTooLowException::what() const throw()
{
    return this->msg;   
}

const char* Form::GradeTooHighException::what() const throw()
{
    return this->msg;
}

Form&	Form::operator=(const Form& form)
{
	if (this != &form)
		this->isSigned = form.getIsSigned();
	return (*this);
}

std::ostream&	operator<<(std::ostream &out, const Form& form)
{
    out << "Form name :" << form.getName() << "\nGrade to sign it:" << form.getGradeToSign()
    << "\nGrade to execute it:" << form.getGradeToExecute() << "\nSigned? " << form.getIsSigned();
    return out; 
}

