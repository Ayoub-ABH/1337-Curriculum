/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 08:57:33 by aait-bab          #+#    #+#             */
/*   Updated: 2024/11/17 09:12:48 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    this->setHitPoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
    std::cout << "FragTrap default constractor called" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
    this->setName(name);
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
    std::cout << "FragTrap parametric constractor called" << std::endl;
}

FragTrap& FragTrap::operator = (FragTrap& ft)
{
    if (this != &ft)
    {
        this->setName(ft.getName());
        this->setHitPoints(ft.getHitPoints());
        this->setEnergyPoints(ft.getEnergyPoints());
        this->setAttackDamage(ft.getAttackDamage());       
        std::cout << "FragTrap = operator called" << std::endl;
    }
    return (*this);
}

FragTrap::FragTrap(FragTrap& ft)
{
    *this = ft;
    std::cout << "FragTrap copy constractor called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap deconstractor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap says: ✋ High fives, anyone? Let's celebrate positivity! 🙌" << std::endl;
}