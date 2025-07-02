/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 21:49:02 by aait-bab          #+#    #+#             */
/*   Updated: 2025/07/02 13:32:45 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;
    
    AForm* rrf;
    rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
}