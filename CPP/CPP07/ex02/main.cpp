/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 08:00:17 by aait-bab          #+#    #+#             */
/*   Updated: 2025/07/15 10:09:52 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Array.hpp"

int main()
{
    Array<int> a(4);
    for (unsigned int i = 0; i < a.size(); ++i)
        a[i] = i * 10;

    Array<int> b(a);

    for (unsigned int i = 0; i < b.size(); ++i)
        std::cout << b[i] << std::endl;

    try 
    {
        std::cout << b[100] << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}