/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:47:26 by aait-bab          #+#    #+#             */
/*   Updated: 2024/11/12 10:19:20 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    public:
        Fixed();
        Fixed(const Fixed&  fixed);
        Fixed(const int i_num);
        Fixed(const float f_num);
        ~Fixed();
        Fixed&          operator =(const Fixed& fixed);
        
        bool            operator >(const Fixed& fixed);
        bool            operator <(const Fixed& fixed);
        bool            operator <=(const Fixed& fixed);
        bool            operator >=(const Fixed& fixed);
        bool            operator ==(const Fixed& fixed);
        bool            operator !=(const Fixed& fixed);
        
        Fixed           operator +(const Fixed& fixed);
        Fixed           operator *(const Fixed& fixed);
        Fixed           operator -(const Fixed& fixed);
        Fixed           operator /(const Fixed& fixed);

        Fixed&          operator ++();
        Fixed           operator ++(int);
        Fixed&          operator --();
        Fixed           operator --(int);
        
        float           toFloat( void ) const;
        int             toInt( void ) const;
        int             getRawBits( void ) const;
        void            setRawBits( int const raw );

        static Fixed&   min(Fixed& f1, Fixed& f2);
        static const Fixed&   min(const Fixed& f1, const Fixed& f2);
        static Fixed&   max(Fixed& f1, Fixed& f2);
        static const Fixed&   max(const Fixed& f1, const Fixed& f2);
        
    private:
        static const int    fract;
        int                 value;
};

std::ostream& operator<< (std::ostream&  out, const Fixed& fixed);


#endif