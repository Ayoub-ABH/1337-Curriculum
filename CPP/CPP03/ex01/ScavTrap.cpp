/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:27:32 by aait-bab          #+#    #+#             */
/*   Updated: 2024/11/17 08:54:48 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
    std::cout << "ScavTrap default constractor called" << std::endl;
    
}

ScavTrap::ScavTrap(std::string name)
{
    this->setName(name);
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
    std::cout << "ScavTrap parametric constractor called" << std::endl;
}

ScavTrap& ScavTrap::operator = (ScavTrap& st)
{
    if (this != &st)
    {
        this->setName(st.getName());
        this->setHitPoints(st.getHitPoints());
        this->setEnergyPoints(st.getEnergyPoints());
        this->setAttackDamage(st.getAttackDamage());       
        std::cout << "ScavTrap = operator called" << std::endl;
    }
    return (*this);
}


ScavTrap::ScavTrap(ScavTrap& st)
{
    *this = st;
    std::cout << "ScavTrap copy constractor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap deconstractor called" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;    
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0)
	{
		this->setEnergyPoints(this->getEnergyPoints() - 1);
		std::cout << "ScavTrap " << this->getName() <<  " attacks " << target << " causing points of damage\n";
	}
	else
		std::cout << "ScavTrap has no more energy points" << std::endl;
}