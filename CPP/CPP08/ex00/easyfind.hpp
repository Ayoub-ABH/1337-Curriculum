/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 09:34:20 by aait-bab          #+#    #+#             */
/*   Updated: 2025/07/17 10:05:56 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_FIND

# define EASY_FIND


#include <algorithm>
#include <iostream>

template<typename T>
void easyfind(T container, int number)
{
    typename T::iterator it = std::find(container.begin(),container.end(), number);
    if (it != container.end())
        std::cout << "Element " << *it <<" found in the container"  << std::endl;
    else
        throw std::runtime_error("Element not found the container");
}

#endif