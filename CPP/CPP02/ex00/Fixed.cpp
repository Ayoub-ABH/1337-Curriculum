/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:09:31 by aait-bab          #+#    #+#             */
/*   Updated: 2024/11/06 12:38:03 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

int const Fixed::fract = 8;

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

Fixed::Fixed(const Fixed& fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    if (this != &fixed)
        *this = fixed;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
} 

Fixed& Fixed::operator= (const Fixed& fixed)
{    
    std::cout << "Copy assignment operator called" << std::endl;
    
    if (this != &fixed)
        this->value = fixed.getRawBits();

    return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->value);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}