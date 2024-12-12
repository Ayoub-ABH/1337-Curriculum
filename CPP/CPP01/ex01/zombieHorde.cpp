/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 22:06:48 by aait-bab          #+#    #+#             */
/*   Updated: 2024/12/10 13:07:03 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    if (N < 0)
        return (NULL);
    Zombie* zombies = new Zombie[N];
    
    for (int i = 0; i < N; i++)
    {
        zombies[i].setName(name);
    }
    return (zombies);
}