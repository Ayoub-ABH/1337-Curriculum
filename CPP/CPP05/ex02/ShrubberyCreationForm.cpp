/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:51:43 by aait-bab          #+#    #+#             */
/*   Updated: 2025/07/07 16:35:03 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137)
{
    this->target = "target";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& SCForm): AForm(SCForm)
{
   this->target = SCForm.getTarget();
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string otherTarget) : AForm("ShrubberyCreationForm", 145, 137)
{
    this->target = otherTarget;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    
}

const std::string& ShrubberyCreationForm::getTarget() const
{
    return this->target;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > this->getGradeToExecute())
		throw (AForm::GradeTooLowException("Error: grade too low to execute this form!"));
    
	if (!this->getIsSigned())
    {
        std::string msg = "The form " + this->target + " is not signed yet!";
        throw (AForm::FormIsNotSignedException(msg.c_str()));
    }
		
    
    std::ofstream outFile;
    std::string file = this->target + "_shrubbery";
    
    outFile.open(file.c_str());
    if (!outFile) {
        throw std::runtime_error("Failed to create file: " + file);
    }
    
    outFile << "       *       " << std::endl;
    outFile << "      ***      " << std::endl;
    outFile << "     *****     " << std::endl;
    outFile << "    *******    " << std::endl;
    outFile << "   *********   " << std::endl;
    outFile << "  ***********  " << std::endl;
    outFile << "      |||      " << std::endl;
    outFile << "      |||      " << std::endl;
    outFile << "===============" << std::endl;
    
    outFile.close();
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& shrubberyCreationForm)
{
    if (this != &shrubberyCreationForm)
    {
        this->target = shrubberyCreationForm.target;
        this->setIsSigned(shrubberyCreationForm.getIsSigned());
    }
    return *this;
}