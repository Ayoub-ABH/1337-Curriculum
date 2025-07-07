/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 21:49:02 by aait-bab          #+#    #+#             */
/*   Updated: 2025/07/07 14:55:31 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat b1("ayoub", 1);
        b1.incrementGrade();
        std::cout << b1 << std::endl;
    } 
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("abdesslam", 150);
        b2.decrementGrade();
        std::cout << b2 << std::endl;
    } 
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}