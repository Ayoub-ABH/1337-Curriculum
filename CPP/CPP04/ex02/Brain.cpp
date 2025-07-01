/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:15:58 by aait-bab          #+#    #+#             */
/*   Updated: 2025/04/20 15:35:21 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constractor is called" << std::endl;    
}

Brain& Brain::operator = (const Brain& brain)
{
    std::cout << "Brain the = operator is called" << std::endl;    
    if (this != &brain)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = brain.ideas[i];
    }
    return (*this);
}

Brain::Brain(const Brain& brain)
{
    std::cout << "Brain copy constractor is called" << std::endl;    
    *this = brain;
}

Brain::~Brain()
{
    std::cout << "Brain deconstractor is called" << std::endl;
}