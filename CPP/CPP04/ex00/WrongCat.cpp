/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:57:24 by aait-bab          #+#    #+#             */
/*   Updated: 2025/04/20 13:21:45 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
    this->type = "WrongCat";
    std::cout << "WrongCat default constructor is called" << std::endl;
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat destructor is called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& WrongCat)
{
    std::cout << "WrongCat copy constructor is called" << std::endl;
    *this = WrongCat;
}

WrongCat& WrongCat::operator=(const WrongCat& WrongCat)
{
    std::cout << "WrongCat copy constructor is called" << std::endl;
    if (this != &WrongCat)
        this->type = WrongCat.type;
    return *this;
}

void    WrongCat::makeSound(void) const
{
    std::cout << "Meaooooo" << std::endl;
}
