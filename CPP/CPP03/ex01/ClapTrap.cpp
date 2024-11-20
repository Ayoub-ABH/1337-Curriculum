/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:56:00 by aait-bab          #+#    #+#             */
/*   Updated: 2024/11/17 08:53:40 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap Default constructor called" << std::endl;
    this->name = "";
    this->attackDamage = 0;
    this->energyPoints = 10;
    this->hitPoints = 10;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "ClapTrap Parametric constructor called" << std::endl;
    this->name = name;
    this->attackDamage = 0;
    this->energyPoints = 10;
    this->hitPoints = 10;
}

ClapTrap& ClapTrap::operator=(ClapTrap& ct)
{
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
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
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    *this = ct;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap deconstructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->hitPoints > 0 && this->energyPoints > 0)
    {
        this->energyPoints--;
        std::cout << "ClapTrap" << this->name << " attacks " << target << ", causing points of damage!" << std::endl;
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

std::string ClapTrap::getName() const
{
    return this->name;
}

int ClapTrap::getHitPoints() const
{
    return this->hitPoints;
}

int ClapTrap::getEnergyPoints() const
{
    return this->energyPoints;
}

int ClapTrap::getAttackDamage() const
{
    return this->attackDamage;    
}

void ClapTrap::setName(std::string name)
{
    this->name = name;
}

void ClapTrap::setHitPoints(int hitPoints)
{
    this->hitPoints = hitPoints; 
}

void ClapTrap::setEnergyPoints(int energyPoints)
{
    this->energyPoints = energyPoints;  
}

void ClapTrap::setAttackDamage(int attackDamage)
{
    this->attackDamage = attackDamage;   
}
