/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:07:20 by aait-bab          #+#    #+#             */
/*   Updated: 2025/07/18 15:39:49 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void print(const T& element)
{
    std::cout << element << std::endl;
}

int main()
{
    int tab[] = {1,2,3};
    const int tab1[] = {1,2,3};
    
    try {
        iter(tab, 3, &print<int>);
        iter(tab1, 3, &print<int>);
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

}