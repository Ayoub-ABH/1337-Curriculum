/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 21:49:02 by aait-bab          #+#    #+#             */
/*   Updated: 2025/07/07 16:33:26 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{

    try
    {
        Bureaucrat b1("Ayoub", 1);
        Bureaucrat b2("3sso", 45);
        Bureaucrat b3("brahim", 120);

        PresidentialPardonForm PPForm("PPForm");
        b1.signForm(PPForm);
        b1.executeForm(PPForm);

        std::cout << "------------------------------" << std::endl;
        RobotomyRequestForm RRForm("RRForm");
        b2.signForm(RRForm);
        b2.executeForm(RRForm);

        std::cout << "------------------------------" << std::endl;
        ShrubberyCreationForm SCForm("SCForm");
        b3.signForm(SCForm);
        b3.executeForm(SCForm);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}