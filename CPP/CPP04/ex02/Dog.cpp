/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:43:24 by aait-bab          #+#    #+#             */
/*   Updated: 2024/11/21 18:03:19 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog default constractor is called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
}

Dog::Dog(std::string &type)
{
    std::cout << "Dog parametric constractor is called" << std::endl;
    this->type = type;
}

Dog::Dog(Dog &dog)
{
    std::cout << "Animal copy constractor is called" << std::endl;
    *this = dog;
}

Dog& Dog::operator = (Dog &dog)
{
    std::cout << "Dog = operator is called" << std::endl;
    if (this != &dog)
    {
        this->type = dog.type;
    }
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog deconstractor is called" << std::endl;
    delete this->brain;
}

void Dog::makeSound() const
{
    std::cout << "Woof" << std::endl;
}