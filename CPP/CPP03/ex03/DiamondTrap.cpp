/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 09:20:18 by aait-bab          #+#    #+#             */
/*   Updated: 2024/11/20 10:13:36 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    std::cout << "DiamondTrap default constructor called" << std::endl;
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(30);
}

DiamondTrap::DiamondTrap(std::string name)
{
    std::cout << "DiamondTrap parametric constractor called" << std::endl;
    this->setName(name);
    ClapTrap::setName(name + "_clap_name");
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(30);
}

DiamondTrap& DiamondTrap::operator = (DiamondTrap& dt)
{
	std::cout << "DiamondTrap copy assignement operator is called" << std::endl;
    if (this != &dt)
    {
        this->setName(dt.getName());
        this->setHitPoints(dt.getHitPoints());
        this->setAttackDamage(dt.getAttackDamage());
        this->setEnergyPoints(dt.getEnergyPoints());
    }
    return (*this);
}

DiamondTrap::DiamondTrap(DiamondTrap& dt)
{
	std::cout << "DiamondTrap copy constractor is called" << std::endl;
    *this = dt;   
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Constractor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name : " << this->getName() << "Claptrap name : " << this->ClapTrap::getName() << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    this->ScavTrap::attack(target);
}