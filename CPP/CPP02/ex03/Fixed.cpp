/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:47:21 by aait-bab          #+#    #+#             */
/*   Updated: 2024/11/12 11:11:29 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fract = 8;

Fixed::Fixed()
{
    this->value = 0;
}

Fixed::Fixed(const Fixed& fixed)
{
    if (this != &fixed)
        *this = fixed;
}

Fixed::Fixed(const int i_num)
{
    this->value = i_num  * (1 << Fixed::fract);
}

Fixed::Fixed(float const f_num)
{
    this->value = roundf(f_num * (1 << Fixed::fract));
}

Fixed::~Fixed()
{
} 


float Fixed::toFloat( void ) const
{
    return (this->value / float(1 << Fixed::fract));
}

int   Fixed::toInt( void ) const
{
    return (this->value / (1 << Fixed::fract));
}

int Fixed::getRawBits(void) const
{
    return (this->value);
}

void Fixed::setRawBits(const int raw)
{
    this->value = raw;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{    
    if (this != &fixed)
        this->value = fixed.value;
    return (*this);
}

std::ostream& operator<< (std::ostream&  out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return (out);
}

bool Fixed::operator>(const Fixed& fixed)
{
    return this->value > fixed.value;
}

bool Fixed::operator<(const Fixed& fixed)
{
    return this->value  < fixed.value;
}

bool Fixed::operator<=(const Fixed& fixed)
{
    return this->value <= fixed.value;
}

bool Fixed::operator>=(const Fixed& fixed)
{
    return this->value >= fixed.value;
}

bool Fixed::operator==(const Fixed& fixed)
{
    return this->value == fixed.value;
}

bool Fixed::operator!=(const Fixed& fixed)
{
    return this->value != fixed.value;
}

Fixed Fixed::operator+(const Fixed& fixed)
{
    return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed& fixed)
{
    return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed& fixed)
{
    return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed& fixed)
{
    return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed& Fixed::operator++()
{
    ++this->value;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    this->value++;
    return (temp);
}

Fixed& Fixed::operator--()
{
    --this->value;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    this->value--;
    return (tmp);
}

Fixed& Fixed::min(Fixed& f1, Fixed& f2)
{
    return (f1.value < f2.value ? f1 : f2);
}
const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2)
{
    return (f1.value < f2.value ? f1 : f2);
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2)
{
    return (f1.value > f2.value ? f1 : f2);
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2)
{
    return (f1.value > f2.value ? f1 : f2);
}