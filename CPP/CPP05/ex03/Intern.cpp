/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:08:52 by aait-bab          #+#    #+#             */
/*   Updated: 2025/07/07 15:30:41 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{
}

Intern::~Intern(void)
{
}

Intern::Intern(const Intern& intern)
{
	(void)intern;
}

Intern&	Intern::operator=(const Intern& intern)
{
	(void)intern;
	return *this;
}

AForm *Intern::newRRForm(std::string name)
{
	return new RobotomyRequestForm(name);
}

AForm *Intern::newSCForm(std::string name)
{
	return new ShrubberyCreationForm(name);
}

AForm *Intern::newPPForm(std::string name)
{
	return new PresidentialPardonForm(name);
}

AForm	*Intern::makeForm(std::string formName, std::string target)
{
	AForm *(Intern::*f[3])(std::string target) = {&Intern::newRRForm, &Intern::newSCForm, &Intern::newPPForm};
	std::string forms[] = {"RobotomyRequestForm", "ShrubberyCreationForm", "PresidentialPardonForm"};
	for (int i = 0; i < 3; i++)
	{
        if (forms[i] == formName)
		{
			std::cout << "Intern creates " << formName << " form" << std::endl;
    	    return (this->*f[i])(target);
		}
    }
	std::cout << "The form " << formName << " does not exist" << std::endl;
	return (NULL);
}