/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:48:08 by aait-bab          #+#    #+#             */
/*   Updated: 2024/10/18 10:03:40 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// default constructor
Contact::Contact()
{
    this->firstName = "";
    this->lastName = "";
    this->nickName = "";
    this->phoneNumber = "";
    this->darkestSecret = "";
}
// parameterized constructor
Contact::Contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->nickName = nickName;
    this->phoneNumber = phoneNumber;
    this->darkestSecret = darkestSecret;
}
// destructor
Contact::~Contact()
{
}

// Setters
void Contact::setFirstName(std::string name)
{
    this->firstName = name;
}
void Contact::setLastName(std::string name)
{
    this->lastName = name;
}
void Contact::setNickName(std::string name)
{
    this->nickName = name;
}
void Contact::setPhoneNumber(std::string number)
{
    this->phoneNumber = number;
}
void Contact::setDarkestSecret(std::string secret)
{
    this->darkestSecret = secret;
}

// Getters
std::string Contact::getFirstName()
{
    return this->firstName;
}
std::string Contact::getLastName()
{
    return this->lastName;
}
std::string Contact::getNickName()
{
    return this->nickName;
}
std::string Contact::getPhoneNumber()
{
    return this->phoneNumber;
}
std::string Contact::getDarkestSecret()
{
    return this->darkestSecret;
}


