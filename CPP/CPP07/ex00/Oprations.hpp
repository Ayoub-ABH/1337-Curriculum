/* ************************************************************************** */
/*                                                                            */
/*                                                        :      ::::::::   */
/*   oprations.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:48:01 by aait-bab          #+#    #+#             */
/*   Updated: 2025/07/14 10:02:25 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPRATIONS_HPP
 
#define OPRATIONS_HPP

#include <iostream>

template <typename T>
void swap(T& var1, T& var2)
{
    T tmp;

    tmp = var1;
	var1 = var2;
	var2 = tmp;
}

template <typename T>
T max(T& var1, T& var2)
{
    return (var1 > var2) ? var1 : var2; 
}

template <typename T>
T min(T& var1, T& var2)
{
     return (var1 < var2) ? var1 : var2; 
}

#endif