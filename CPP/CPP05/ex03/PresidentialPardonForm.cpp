/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:48:07 by aait-bab          #+#    #+#             */
/*   Updated: 2025/07/07 15:31:36 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5)
{
    this->target = "target";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& PPForm): AForm(PPForm)
{
   this->target = PPForm.getTarget();
}

PresidentialPardonForm::PresidentialPardonForm(std::string otherTarget) : AForm("PresidentialPardonForm", 25, 5)
{
    this->target = otherTarget;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    
}

const std::string& PresidentialPardonForm::getTarget() const
{
    return this->target;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > this->getGradeToExecute())
		throw (AForm::GradeTooLowException("Error: grade too low to execute this form!"));
	if (!this->getIsSigned())
    {
        std::string msg = "The form " + this->target + " is not signed yet!";
        throw (AForm::FormIsNotSignedException(msg.c_str()));
    }
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
