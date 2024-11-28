/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:36:33 by aait-bab          #+#    #+#             */
/*   Updated: 2024/11/23 08:55:17 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <Contact.hpp>

class PhoneBook
{
    private:
        Contact contacts[8];
        int isPhoneNumber(std::string number);
    public:
        PhoneBook();
        PhoneBook(Contact contacts[8]);
        ~PhoneBook();
        void addContact();
        void searchContact();
};

#endif