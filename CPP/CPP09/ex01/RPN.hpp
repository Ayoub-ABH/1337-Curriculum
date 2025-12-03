/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:04:39 by aait-bab          #+#    #+#             */
/*   Updated: 2025/12/03 18:11:54 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP

#define RPN_HPP


#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <string>
#include <cctype>
#include <cstdlib>

class RPN
{
private:
    std::stack<int>    rpnStack;
public:
    RPN();
    RPN(const RPN& rpn);
    RPN& operator=(const RPN& rpn);

    void calculate(const std::string &input);
    
    ~RPN();
};

#endif