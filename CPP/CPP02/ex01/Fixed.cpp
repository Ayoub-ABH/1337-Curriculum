/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:09:31 by aait-bab          #+#    #+#             */
/*   Updated: 2025/03/23 22:25:02 by aait-bab         ###   ########.fr       */
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
    *this = fixed;
}

Fixed::Fixed(const int i_num)
{
    std::cout << "Int constructor called" << std::endl;
    this->value = i_num  << Fixed::fract;
}

Fixed::Fixed(const float f_num)
{
    std::cout << "Float constructor called" << std::endl;
    this->value = roundf(f_num * (1 << Fixed::fract));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
} 

Fixed& Fixed::operator=(const Fixed& fixed)
{    
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
        this->value = fixed.value;
    return (*this);
}

std::ostream& operator<< (std::ostream&  out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return (out);
}

float Fixed::toFloat( void ) const
{
    return (this->value / float(1 << Fixed::fract));
}

int   Fixed::toInt( void ) const
{
    return (this->value >> Fixed::fract);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->value);
}

void Fixed::setRawBits(const int raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}
