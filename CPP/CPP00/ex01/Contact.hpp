/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:39:16 by aait-bab          #+#    #+#             */
/*   Updated: 2024/12/08 13:37:43 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;
    public:
        Contact();
        Contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret);
        ~Contact();
        void setFirstName(std::string name);
        void setLastName(std::string name);
        void setNickName(std::string name);
        void setPhoneNumber(std::string number);
        void setDarkestSecret(std::string secret);
        std::string getFirstName();
        std::string getLastName();
        std::string getNickName();
        std::string getPhoneNumber();
        std::string getDarkestSecret();
};

#endif