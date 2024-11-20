/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:56:00 by aait-bab          #+#    #+#             */
/*   Updated: 2024/11/16 11:44:05 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default constructor called" << std::endl;
    this->name = "";
    this->attackDamage = 0;
    this->energyPoints = 10;
    this->hitPoints = 10;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "Parametric constructor called" << std::endl;
    this->name = name;
    this->attackDamage = 0;
    this->energyPoints = 10;
    this->hitPoints = 10;
}

ClapTrap& ClapTrap::operator=(ClapTrap& ct)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &ct)
    {
        this->name = ct.name;
        this->hitPoints = ct.hitPoints;
        this->attackDamage = ct.attackDamage;
        this->energyPoints = ct.energyPoints;
    }
    return (*this);
}


ClapTrap::ClapTrap(ClapTrap& ct)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = ct;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Copy constructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->hitPoints > 0 && this->energyPoints > 0)
    {
        this->energyPoints--;
        std::cout << "ClapTrap" << this->name << " attacks " << target << ", causing "<< 1 << " points of damage!" << std::endl;
        std::cout << "energyPoint : " << this->energyPoints << " ; hitPoint : " \
		<< this->hitPoints << " ; attakdamage : " << this->attackDamage << std::endl;
    }
    else
        std::cout << "Can't Attack no (hit or Energy) points left" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints >= amount)
    {
        this->hitPoints -= amount;
        std::cout << "ClapTrap " << this->name << " take " << amount << " points of damage!" << std::endl;
        std::cout << "energyPoint : " << this->energyPoints << " ; hitPoint : " \
		<< this->hitPoints << " ; attakdamage : " << this->attackDamage << std::endl;
    }
    else
        std::cout << "Can't Take damage no enough hit points" << std::endl;        
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energyPoints > 0)
    {
        this->hitPoints += amount;
        std::cout << "ClapTrap " << this->name << "get repaired by" << amount << " points!" << std::endl;
        this->energyPoints--;
        std::cout << "energyPoint : " << this->energyPoints << " ; hitPoint : " \
		<< this->hitPoints << " ; attakdamage : " << this->attackDamage << std::endl;
    }
    else
        std::cout << "Can't get repaired no energy points left" << std::endl;   
}
