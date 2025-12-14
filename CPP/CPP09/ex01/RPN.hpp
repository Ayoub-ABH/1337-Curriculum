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
    std::stack<float> rpnStack;
    
    bool isOperator(char c) const;
    void processDigit(const std::string &input, size_t index);
    void processOperator(char op);
    float performOperation(float operand1, float operand2, char op) const;

public:
    RPN();
    RPN(const RPN& rpn);
    RPN& operator=(const RPN& rpn);
    ~RPN();

    void calculate(const std::string &input);
};

#endif