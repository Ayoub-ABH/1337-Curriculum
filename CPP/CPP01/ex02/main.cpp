/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 22:34:36 by aait-bab          #+#    #+#             */
/*   Updated: 2024/12/11 14:05:55 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string str2 = "HI THIS IS BRAIN";
    std::string* stringPtr = &str;
    std::string& stringRef = str;

    std::cout << "The memory address of the string variable: " << &str << std::endl;
    std::cout << "The memory address held by stringPTR: " << stringPtr << std::endl;
    std::cout << "The memory address held by stringRef: " << &stringRef << std::endl;
    std::cout << "The value of the string variable: " << str << std::endl;
    std::cout << "The value pointed to by stringPTR: " << *stringPtr << std::endl;
    std::cout << "The value pointed to by stringRef: " << stringRef << std::endl;
}
