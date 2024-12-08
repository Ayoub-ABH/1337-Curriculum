/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:36:33 by aait-bab          #+#    #+#             */
/*   Updated: 2024/12/08 13:13:25 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
        int isValidAttr(std::string attr);
        int isValidIndex(std::string index);
    public:
        PhoneBook();
        PhoneBook(Contact contacts[8]);
        ~PhoneBook();
        void addContact();
        void searchContact();
};

#endif