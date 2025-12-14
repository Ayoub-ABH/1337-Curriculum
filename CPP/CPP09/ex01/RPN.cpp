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
    for (size_t i = 0; i < input.size(); i++)
    {
        char c = input[i];

        if (c == ' ')
            continue;

        if (isdigit(c))
            processDigit(input, i);
        else if (isOperator(c))
            processOperator(c);
        else
            throw std::runtime_error("Error");
    }

    if (rpnStack.size() != 1)
        throw std::runtime_error("Error");
    
    std::cout << rpnStack.top() << std::endl;
}


bool RPN::isOperator(char c) const
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void RPN::processDigit(const std::string &input, size_t index)
{
    if (index + 1 < input.size() && isdigit(input[index + 1]))
        throw std::runtime_error("Error");
    
    rpnStack.push(input[index] - '0');
}

void RPN::processOperator(char op)
{
    if (rpnStack.size() < 2)
        throw std::runtime_error("Error");
    
    float operand2 = rpnStack.top(); rpnStack.pop();
    float operand1 = rpnStack.top(); rpnStack.pop();
    
    float result = performOperation(operand1, operand2, op);
    rpnStack.push(result);
}

float RPN::performOperation(float operand1, float operand2, char op) const
{
    switch (op)
    {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/':
            if (operand2 == 0)
                throw std::runtime_error("Error: Division by zero");
            return operand1 / operand2;
        default:
            throw std::runtime_error("Error");
    }
}
    
RPN::~RPN()
{
}