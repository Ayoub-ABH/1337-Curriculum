/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 21:49:02 by aait-bab          #+#    #+#             */
/*   Updated: 2025/07/07 15:09:29 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat b1("ayoub", 1);
    Form f1("contrat",1,1);

    b1.signForm(f1);

    std::cout<< b1 << std::endl;
    std::cout<< f1 << std::endl;

    Bureaucrat b2("yassine", 1);
    Form f2("contrat2",1,1);

    f2.beSigned(b2);

    std::cout<< b2 << std::endl;
    std::cout<< f2 << std::endl;
    
}