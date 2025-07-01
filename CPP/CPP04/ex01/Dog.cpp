/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:43:24 by aait-bab          #+#    #+#             */
/*   Updated: 2025/04/20 15:45:39 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog default constractor is called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
}

Dog::Dog(const Dog &dog)
{
    std::cout << "Dog copy constractor is called" << std::endl;
    this->type = dog.type;
    this->brain = new Brain(*dog.brain);
}

Dog& Dog::operator = (const Dog &dog)
{
    
    std::cout << "Dog = operator is called" << std::endl;
    if (this != &dog)
    {
        this->type = dog.type;
        delete this->brain;
        this->brain = new Brain(*dog.brain);
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