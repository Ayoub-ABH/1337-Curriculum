/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamqari <klamqari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 04:28:07 by klamqari          #+#    #+#             */
/*   Updated: 2025/02/20 07:01:20 by klamqari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

long jacob_number(int i)
{
    return ((pow(2, i) - pow((-1), i)) / 3);
}

int str_to_int(const std::string & str)
{
    int x;

    std::stringstream strm(str);
    strm >> x;

    if (strm.fail())
        throw std::runtime_error("Error: invalid argument: \"" + str + "\" positive int requerd , 0 < N < MAX_INT");

    return x;
}


void check_is_digits(const std::string & element)
{
    int i = 0;
    if (element == "")
        throw std::invalid_argument("Error: invalid argument , empty argument");

    while (element[i])
    {
        if (!isdigit(element[i]))
        {
            std::string msg = "Error: invalid argument not a number : ";
            msg += element;
            throw std::invalid_argument(msg);
        }
        i++;
    }
}
