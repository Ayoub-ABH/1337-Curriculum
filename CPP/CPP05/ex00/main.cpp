/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 21:49:02 by aait-bab          #+#    #+#             */
/*   Updated: 2025/05/12 21:43:02 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat b1("ayoub", 1);
        b1.incrementGrade();
    } 
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}