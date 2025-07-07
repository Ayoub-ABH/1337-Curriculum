/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 22:34:08 by aait-bab          #+#    #+#             */
/*   Updated: 2025/07/07 15:23:36 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): gradeToSign(1), gradeToExecute(1)
{
    this->isSigned = false;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute): name(name),gradeToSign(gradeToSign),gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException("Error: grade too High!");
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException("Error: grade too low!");
    this->isSigned = false;
}

AForm::AForm(const AForm& form): name(form.getName()), gradeToSign(form.getGradeToSign()), gradeToExecute(form.getGradeToExecute())
{
    this->isSigned = form.getIsSigned();
}

AForm::~AForm()
{
    
}

AForm&  AForm::operator=(const AForm& form)
{
    if (this != &form)
        this->isSigned = form.getIsSigned();
    return *this;   
}

const std::string& AForm::getName() const
{
    return this->name;
}

bool AForm::getIsSigned() const
{
    return this->isSigned;
}

void AForm::setIsSigned(bool otherIsSigned)
{
    this->isSigned = otherIsSigned;
}

const int& AForm::getGradeToSign() const
{
    return this->gradeToSign;        
}

const int& AForm::getGradeToExecute() const
{
    return this->gradeToExecute;     
}

void AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() <= this->gradeToSign)
        this->isSigned = true;
    else
        throw AForm::GradeTooLowException("Error: Grade too low to sign this form!");
}

AForm::GradeTooHighException::GradeTooHighException(const char *msg) throw() : msg(msg)
{
}

AForm::GradeTooLowException::GradeTooLowException(const char *msg) throw() : msg(msg)
{
}

AForm::FormIsNotSignedException::FormIsNotSignedException(const char *msg) throw() : msg(msg)
{
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return this->msg;   
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return this->msg;
}

const char* AForm::FormIsNotSignedException::what() const throw()
{
    return this->msg;   
}

std::ostream&	operator<<(std::ostream &out, const AForm& form)
{
    out << "Form name :" << form.getName() << "\nGrade to sign it:" << form.getGradeToSign()
    << "\nGrade to execute it:" << form.getGradeToExecute() << "\nSigned? " << form.getIsSigned();
    return out; 
}