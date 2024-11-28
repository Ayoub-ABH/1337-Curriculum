/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:53:39 by aait-bab          #+#    #+#             */
/*   Updated: 2024/11/23 15:13:32 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// Constructor
PhoneBook::PhoneBook()
{
}
// Constructor with parameter
PhoneBook::PhoneBook(Contact contacts[8])
{
    for (int i = 0; i < 8; i++)
        this->contacts[i] = contacts[i];
}
// Destructor
PhoneBook::~PhoneBook()
{
}

// Check if the phone number is valid
int PhoneBook::isPhoneNumber(std::string number)
{
    if (number.empty() || number.size() != 10)
        return 0;
    for (int i = 0; i < 10; i++)
    {
        if (!std::isdigit(number[i]))
            return 0;
    }
    return 1;
}

// Add a contact to the phonebook
void PhoneBook::addContact()
{
    system("clear");
    for (int i = 0; i < 8; i++)
    {
        if (this->contacts[i].getFirstName() == "" || i == 7)
        {
            std::string firstName, lastName, nickName, phoneNumber, darkestSecret;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            while (firstName.empty())
            {
                std::cout << "Enter the first name: ";
                std::getline(std::cin, firstName);
                if (std::cin.eof())
                    return;
                
            }
            while (lastName.empty())
            {
                std::cout << "Enter the last name: ";
                std::getline(std::cin, lastName);
                if (std::cin.eof())
                    return;
            }
            while (nickName.empty())
            {
                std::cout << "Enter the nick name: ";
                std::getline(std::cin, nickName);
                if (std::cin.eof())
                    return;
            }
            while (phoneNumber.empty() )
            {
                std::cout << "Enter the phone number: ";
                std::getline(std::cin, phoneNumber);
                if (std::cin.eof())
                    return;
            }
            while (darkestSecret.empty())
            {
                std::cout << "Enter the darkest secret: ";
                std::getline(std::cin, darkestSecret);
                if (std::cin.eof())
                    return;
            }
            this->contacts[i] = Contact(firstName, lastName, nickName, phoneNumber, darkestSecret);
            break;
        }
    }
    
}

// 
void PhoneBook::searchContact()
{
    int size;
    int index;

    size = 0;
    system("clear");
    for (int i = 0; i < 8; i++)
    {
        if (i == 0)
        {
            std::cout << "|Index     |First name|Last name |Nick name |"<< std::endl;
            std::cout << "---------------------------------------------"<< std::endl;
        }
        std::cout << "|" << i + 1 << "         ";
        size = 10 - this->contacts[i].getFirstName().size();
        if (size <= 0)
            std::cout << "|" << this->contacts[i].getFirstName().substr(0, 9) << ".|";
        else
        {
            std::cout << "|" << this->contacts[i].getFirstName();
            for (int i = 0; i < size; i++)
                std::cout << " ";
            std::cout << "|";
        }

        size = 10 - this->contacts[i].getLastName().size();
        if (size <= 0)
            std::cout << this->contacts[i].getLastName().substr(0, 9) << ".|";
        else
        {
            std::cout << this->contacts[i].getLastName();
            for (int i = 0; i < size; i++)
                std::cout << " ";
            std::cout << "|";
        }

        size = 10 - this->contacts[i].getNickName().size();
        if (size <= 0)
            std::cout << this->contacts[i].getNickName().substr(0, 9) << ".|" << std::endl;
        else
        {
            std::cout << this->contacts[i].getNickName();
            for (int i = 0; i < size; i++)
                std::cout << " ";
            std::cout << "|" << std::endl;
        }
    }
    std::cout << "Enter the index of the contact: ";
    if (!(std::cin >> index) || index < 1 || index > 8)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid index" << std::endl;
        return;
    }
    else
    {
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