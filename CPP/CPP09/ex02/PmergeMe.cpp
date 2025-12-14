/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 01:01:38 by aait-bab          #+#    #+#             */
/*   Updated: 2025/12/14 01:33:01 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool isValidInput(char** av) {
    for(int i = 1; av[i]; i++) {
        std::string arg(av[i]);
        
        if (arg.empty())
            return false;
            
        for(size_t j = 0; j < arg.length(); j++) {
            if(!isdigit(arg[j]))
                return false;
        }
        
        double  d = std::atof(av[i]);
        if(d > 2147483647)
            return false;
    }
    return true;
}

