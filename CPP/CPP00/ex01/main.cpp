/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:06:05 by aait-bab          #+#    #+#             */
/*   Updated: 2024/10/20 13:54:33 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

int main()
{
    PhoneBook phonebook;
    std::string command;
    
    std::cout << "PhoneBook Assisstant \n\tType ADD    : to add a contact\n\tType SEARCH : to find a contact\n\tType EXIT   : to finish" << std::endl;
    while (true)
    {
        std::cout << "Assistant ~>";
        if (!(std::cin >> command) || command == "EXIT")
            break;
        if (command == "ADD")
            phonebook.addContact();
        if (command == "SEARCH")
            phonebook.searchContact();
    }
    return (0);
}
