/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 22:09:12 by aait-bab          #+#    #+#             */
/*   Updated: 2024/10/19 22:25:40 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int N = 5;
    std::string name = "Zombie";
    Zombie* zombies = zombieHorde(N, name);
    for (int i = 0; i < N; i++)
    {
        zombies[i].announce();
    }
    delete [] zombies;
    return (0);
}