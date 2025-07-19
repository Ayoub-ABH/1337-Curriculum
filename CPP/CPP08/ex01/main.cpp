/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:15:06 by aait-bab          #+#    #+#             */
/*   Updated: 2025/07/19 11:28:01 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    try {
        Span sp = Span(5);
        int nbrOfElements = 100000;
        Span sp2 = Span(nbrOfElements);
        std::vector<int> data;
        
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        
        
        std::srand(time(NULL));
        for (int i = 0; i < nbrOfElements ;i++)
            data.push_back(std::rand() % nbrOfElements);
            
        sp2.addRange(data.begin(), data.end());
        
        std::cout << sp2.shortestSpan() << std::endl;
        std::cout << sp2.longestSpan() << std::endl;  
    } catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}