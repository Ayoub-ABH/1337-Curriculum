/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:24:26 by aait-bab          #+#    #+#             */
/*   Updated: 2025/03/23 22:19:28 by aait-bab         ###   ########.fr       */
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
        Fixed&          operator=(const Fixed& fixed);
        float           toFloat( void ) const;
        int             toInt( void ) const;
        int             getRawBits( void ) const;
        void            setRawBits( int const raw );
    private:
        static int const    fract;
        int                 value;
};

std::ostream& operator<< (std::ostream&  out, const Fixed& fixed);

#endif