/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 21:56:28 by aait-bab          #+#    #+#             */
/*   Updated: 2025/07/07 14:57:15 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException("Error: The grade is too high");
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException("Error: The grade is too low");
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat) : name(bureaucrat.name)
{
    this->grade = bureaucrat.getGrade();
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bureaucrat)
{
    if (this != &bureaucrat)
        this->grade = bureaucrat.grade;
    return *this;   
}


std::ostream&	operator<<(std::ostream &out, const Bureaucrat& bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}


const std::string&  Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
    
}

void Bureaucrat::incrementGrade()
{
    if (this->grade < 2)
        throw Bureaucrat::GradeTooHighException("Error: you can't increment the grade, its too hight");
    this->grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->grade > 149)
        throw Bureaucrat::GradeTooLowException("Error: you can't decrement the grade, its too low");
    this->grade++;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const char *msg) throw() : msg(msg)
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const char *msg) throw() : msg(msg)
{
}


const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return this->msg;   
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return this->msg;
}