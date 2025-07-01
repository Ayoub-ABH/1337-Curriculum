/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 21:49:02 by aait-bab          #+#    #+#             */
/*   Updated: 2025/05/17 16:26:48 by aait-bab         ###   ########.fr       */
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
    
}