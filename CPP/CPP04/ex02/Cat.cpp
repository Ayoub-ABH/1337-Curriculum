/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:33:46 by aait-bab          #+#    #+#             */
/*   Updated: 2024/11/22 10:39:08 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat default constractor is called" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
}

Cat::Cat(std::string &type)
{
    std::cout << "Cat parametric constractor is called" << std::endl;
    this->type = type;
}

Cat::Cat(Cat &cat)
{
    std::cout << "Animal copy constractor is called" << std::endl;
    *this = cat;
}

Cat& Cat::operator = (Cat &cat)
{
    std::cout << "Cat = operator is called" << std::endl;
    if (this != &cat)
    {
        this->type = cat.type;
    }
    return (*this);
}


Cat::~Cat()
{
    std::cout << "Cat deconstractor is called" << std::endl;
    delete this->brain;
}

void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}