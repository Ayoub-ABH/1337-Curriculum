/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 21:49:02 by aait-bab          #+#    #+#             */
/*   Updated: 2025/07/02 13:23:49 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    AForm *form; 
    Bureaucrat b1("Ayoub",1);
    Bureaucrat b2("3sso",50);
    Bureaucrat b3("brahim",140);

    try {
        PresidentialPardonForm PPForm("PPFormClone");
        b2.signForm(PPForm);
        b2.executeForm(PPForm);
    } catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;   
    }
    
    try {
        form = new PresidentialPardonForm("PPForm");
        form->beSigned(b1);
        form->execute(b1);
    } catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;   
    }
    std::cout << "------------------------------" << std::endl;
    try {
        form = new RobotomyRequestForm("RRForm");
        form->beSigned(b2);
        form->execute(b2);
    } catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;   
    }
    std::cout << "------------------------------" << std::endl;
    try {
        form = new ShrubberyCreationForm("SCForm");
        form->beSigned(b3);
        form->execute(b3);
    } catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    delete form;
}