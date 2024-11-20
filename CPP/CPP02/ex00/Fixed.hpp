/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:24:26 by aait-bab          #+#    #+#             */
/*   Updated: 2024/11/06 12:38:31 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    public:
        Fixed();
        Fixed(const Fixed& fixed);
        ~Fixed();
        Fixed&  operator= (const Fixed& fixed);
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
    private:
        static int const    fract;
        int                 value;
};

#endif