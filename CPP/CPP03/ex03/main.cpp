/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 09:19:40 by aait-bab          #+#    #+#             */
/*   Updated: 2024/11/20 11:26:56 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap *dt = new DiamondTrap("gladeator");
    DiamondTrap dt1("sool");

    dt->attack("sool");
    dt1.takeDamage(30);
}