/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:06:49 by aait-bab          #+#    #+#             */
/*   Updated: 2025/12/03 18:24:16 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN& rpn)
{
    *this = rpn;
}

RPN& RPN::operator=(const RPN& rpn)
{
    if (this == &rpn)
        return *this;
    this->rpnStack = rpn.rpnStack;
    return *this;
}

void RPN::calculate(const std::string &input)
{
    std::stringstream ss(input);
    std::string token;

    while (ss >> token)
    {
        if (std::isdigit(token[0]))
        {
            rpnStack.push(std::stoi(token));
        }
        else
        {
            int operand2 = rpnStack.top(); rpnStack.pop();
            int operand1 = rpnStack.top(); rpnStack.pop();
            if (token == "+")
                rpnStack.push(operand1 + operand2);
            else if (token == "-")
                rpnStack.push(operand1 - operand2);
            else if (token == "*")
                rpnStack.push(operand1 * operand2);
            else if (token == "/")
                rpnStack.push(operand1 / operand2);
        }
    }
    std::cout << rpnStack.top() << std::endl;
}
    
RPN::~RPN()
{
}