/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:53:39 by aait-bab          #+#    #+#             */
/*   Updated: 2024/12/08 13:25:44 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::PhoneBook(Contact contacts[8])
{
    for (int i = 0; i < 8; i++)
        this->contacts[i] = contacts[i];
}

PhoneBook::~PhoneBook()
{
}


int PhoneBook::isValidAttr(std::string attr)
{
    size_t count = 0;
    
    if (attr.empty())
        return 0;
    for (size_t i = 0; i < attr.length(); i++)
    {
        if (!std::isprint(attr[i]))
            return 0;
        if (std::isspace(attr[i]))
            count++;
    }
    if (count == attr.length())
        return 0;
    return 1;
}

int PhoneBook::isValidIndex(std::string s_index)
{
    if (s_index.empty() || s_index.length() > 1)
        return 0;
    for (size_t i = 0; i < s_index.length(); i++)
    {
        if (!std::isdigit(s_index[i]))
            return 0;
    }
    if (std::stoi(s_index) < 1 || std::stoi(s_index) > 8)
        return 0;
    return 1;
}

void PhoneBook::addContact()
{
    system("clear");
    for (int i = 0; i <= 8; i++)
    {
        if (this->contacts[i].getFirstName() == "" || i == 7)
        {
            std::string firstName, lastName, nickName, phoneNumber, darkestSecret;
            while (isValidAttr(firstName) == 0)
            {
                std::cout << "Enter the first name: ";
                std::getline(std::cin, firstName);
                if (std::cin.eof())
                    return;
            }
            while (isValidAttr(lastName) == 0)
            {
                std::cout << "Enter the last name: ";
                std::getline(std::cin, lastName);
                if (std::cin.eof())
                    return;
            }
            while (isValidAttr(nickName) == 0)
            {
                std::cout << "Enter the nick name: ";
                std::getline(std::cin, nickName);
                if (std::cin.eof())
                    return;
            }
            while (isValidAttr(phoneNumber) == 0)
            {
                std::cout << "Enter the phone number: ";
                std::getline(std::cin, phoneNumber);
                if (std::cin.eof())
                    return;
            }
            while (isValidAttr(darkestSecret) == 0)
            {
                std::cout << "Enter the darkest secret: ";
                std::getline(std::cin, darkestSecret);
                if (std::cin.eof())
                    return;
            }
            if (i == 7 && this->contacts[i].getFirstName() != "")
                this->contacts[0] = Contact(firstName, lastName, nickName, phoneNumber, darkestSecret);
            else
                this->contacts[i] = Contact(firstName, lastName, nickName, phoneNumber, darkestSecret);
            break;
        }
    }
    
}

void PhoneBook::searchContact()
{
    int size;
    std::string s_index;

    size = 0;
    system("clear");
    for (int i = 0; i < 8; i++)
    {
        if (i == 0)
        {
            std::cout << "|     Index|First name| Last name| Nick name|"<< std::endl;
            std::cout << "---------------------------------------------"<< std::endl;
        }
        std::cout << "|         "<< i + 1 ;
        size = 10 - this->contacts[i].getFirstName().size();
        if (size <= 0)
            std::cout << "|" << this->contacts[i].getFirstName().substr(0, 9) << ".|";
        else
        {
            std::cout << "|";
            for (int i = 0; i < size; i++)
                std::cout << " ";
            std::cout << this->contacts[i].getFirstName();
            std::cout << "|";
        }

        size = 10 - this->contacts[i].getLastName().size();
        if (size <= 0)
            std::cout << this->contacts[i].getLastName().substr(0, 9) << ".|";
        else
        {
            for (int i = 0; i < size; i++)
                std::cout << " ";
            std::cout << this->contacts[i].getLastName();
            std::cout << "|";
        }

        size = 10 - this->contacts[i].getNickName().size();
        if (size <= 0)
            std::cout << this->contacts[i].getNickName().substr(0, 9) << ".|" << std::endl;
        else
        {
            for (int i = 0; i < size; i++)
                std::cout << " ";
            std::cout << this->contacts[i].getNickName();
            std::cout << "|" << std::endl;
        }
    }
    std::cout << "Enter the index of the contact: ";
    std::getline(std::cin, s_index);
    if (std::cin.eof())
        return;
    if (isValidIndex(s_index) == 0)
    {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    else
    {
        int index = std::stoi(s_index);
        index--;
        if (this->contacts[index].getFirstName() == "")
        {
            std::cout << "No contact found" << std::endl;
            return;
        }
        std::cout << "First name: " << this->contacts[index].getFirstName() << std::endl;
        std::cout << "Last name: " << this->contacts[index].getLastName() << std::endl;
        std::cout << "Nick name: " << this->contacts[index].getNickName() << std::endl;
        std::cout << "Phone number: " << this->contacts[index].getPhoneNumber() << std::endl;
        std::cout << "Darkest secret: " << this->contacts[index].getDarkestSecret() << std::endl;
    }
}