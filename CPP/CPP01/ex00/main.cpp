/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:38:55 by aait-bab          #+#    #+#             */
/*   Updated: 2024/10/19 22:10:03 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie* z1 = newZombie("Zombie1");
    z1->announce();
    randomChump("Zombie2");
    delete z1;
    return 0;
}