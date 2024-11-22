/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:19:17 by aait-bab          #+#    #+#             */
/*   Updated: 2024/11/20 14:53:53 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal default constractor is called" << std::endl;
    this->type = "Animal"; 
}

Animal::Animal(std::string &type)
{
    std::cout << "Animal parametric constractor is called" << std::endl;
    this->type = type;
}

Animal& Animal::operator = (Animal &animal)
{
    std::cout << "Animal = operator is called" << std::endl;
    if (this != &animal)
        this->type = animal.type;
    return (*this);
}

Animal::Animal(Animal &animal)
{
    std::cout << "Animal copy constractor is called" << std::endl;
    *this = animal;
}

Animal::~Animal()
{
    std::cout << "Animal deconstractor is called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Animal makes a sound" << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}
