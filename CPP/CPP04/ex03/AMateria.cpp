/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:27:28 by aait-bab          #+#    #+#             */
/*   Updated: 2024/11/22 12:01:28 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
    std::cout << "AMateria default constractor is called" << std::endl;
    this->type = "type AMateria";
}

AMateria& AMateria::operator = (AMateria& amateria)
{
    std::cout << "AMateria = operator is called" << std::endl;
    if (this != &amateria)
        this->type = amateria.type;
    return (*this);
}

AMateria::AMateria(AMateria& amateria)
{
    std::cout << "AMateria copy constractor is called" << std::endl;
    *this = amateria;
}

AMateria::AMateria(std::string const & type)
{
    std::cout << "AMateria parametric constractor is called" << std::endl;
    this->type = type;
}

AMateria::~AMateria()
{
    std::cout << "AMateria  deconstractor is called" << std::endl;    
}

std::string const & AMateria::getType() const
{
    return (this->type);
}

void AMateria::use(ICharacter& target)
{
    std::cout << "" << std::endl;
}