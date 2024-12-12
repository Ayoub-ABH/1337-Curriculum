/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 22:09:12 by aait-bab          #+#    #+#             */
/*   Updated: 2024/12/11 14:05:16 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int N = 5;
    std::string name = "Zombie";
    Zombie* zombies = zombieHorde(N, name);
    if (!zombies)
        return (1);
    for (int i = 0; i < N; i++)
    {
        zombies[i].announce();
    }
    delete [] zombies;
    return (0);
}
