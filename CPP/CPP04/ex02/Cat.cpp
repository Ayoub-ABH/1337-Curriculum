/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:33:46 by aait-bab          #+#    #+#             */
/*   Updated: 2025/04/20 15:56:24 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat default constractor is called" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
}

Cat::Cat(const Cat &cat)
{
    std::cout << "Animal copy constractor is called" << std::endl;
    this->type = cat.type;
    this->brain = new Brain(*cat.brain);
}

Cat& Cat::operator = (const Cat &cat)
{
    std::cout << "Cat = operator is called" << std::endl;
    if (this != &cat)
    {
        this->type = cat.type;
        delete this->brain;
        this->brain = new Brain(*cat.brain);
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