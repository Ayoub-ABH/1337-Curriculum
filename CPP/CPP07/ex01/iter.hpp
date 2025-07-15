/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:07:38 by aait-bab          #+#    #+#             */
/*   Updated: 2025/07/15 07:54:11 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP

# define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T* tab, std::size_t size, F func)
{
    for (std::size_t i=0; i < size; i++)
        func(tab[i]);
}

#endif



