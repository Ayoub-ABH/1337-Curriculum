/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 09:16:09 by aait-bab          #+#    #+#             */
/*   Updated: 2025/07/02 13:28:35 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45)
{
    this->target = "target";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& RTRForm): AForm(RTRForm)
{
   this->target = RTRForm.getTarget();
}

RobotomyRequestForm::RobotomyRequestForm(std::string otherTarget) : AForm("RobotomyRequestForm", 72, 45)
{
    this->target = otherTarget;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    
}

const std::string& RobotomyRequestForm::getTarget() const
{
    return this->target;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > this->getGradeToExecute())
		throw (AForm::GradeTooLowException("Error: grade too low to sign this form!"));
    
	if (!this->getIsSigned())
    {
        std::string msg = "The form " + this->target + " is not signed yet!";
        throw (AForm::FormIsNotSignedException(msg.c_str()));
    }
	
    std::cout << "Bzzzzzzzzzzzz....." << std::endl;
    std::srand(std::time(NULL));
    if (std::rand() % 2 == 0) {
        std::cout << this->target << " has been robotomized successfully" << std::endl;
    } else {
        throw std::runtime_error(std::string("Robotomy failed on ") + this->target);
    }
}
