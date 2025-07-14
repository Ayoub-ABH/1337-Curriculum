/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:01:03 by aait-bab          #+#    #+#             */
/*   Updated: 2025/07/13 18:06:59 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data dt;
    dt.boolean = true;
    dt.caracter = 'a';
    dt.doubleNumber = 482367572346.01;
    dt.floatNumber = 324.042;
    dt.intNumber = 22;
    dt.longNumber = 24857246;

    uintptr_t s_ptr = Serializer::serialize(&dt);
    std::cout << s_ptr << std::endl;
    
    Data *d_dt = Serializer::deserialize(s_ptr);
    std::cout << d_dt->boolean << std::endl;
    std::cout << d_dt->caracter << std::endl;
    std::cout << d_dt->doubleNumber << std::endl;
    std::cout << d_dt->floatNumber << std::endl;
    std::cout << d_dt->intNumber << std::endl;
    std::cout << d_dt->longNumber << std::endl;
    
}