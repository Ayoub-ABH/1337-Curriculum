/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:15:09 by aait-bab          #+#    #+#             */
/*   Updated: 2025/07/19 11:26:59 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
    
}

Span::Span(unsigned int N)
{
   this->maxSize = N;
}

Span::Span(const Span& span)
{
    *this = span;
}

Span::~Span()
{
    
}

Span& Span::operator=(const Span& span)
{
   if (this != &span)
   {
        this->maxSize = span.maxSize;
        this->data.clear();
        for (size_t i = 0; i < span.data.size(); i++)
            this->data.push_back(span.data[i]);
   }
   return *this;
}


int Span::shortestSpan() 
{
    if (this->data.size() < 2)
        throw std::runtime_error("Not enough elements to compute shortest span.");
    int minSpan = INT_MAX;
    std::sort(this->data.begin(), this->data.end());
    for (size_t i = 1; i < this->data.size(); i++)
        minSpan = std::min(minSpan, data[i] - data[i - 1]);
    return minSpan;
}

int Span::longestSpan() 
{
    if (this->data.size() < 2)
        throw std::runtime_error("Not enough elements to compute shortest span.");
    std::vector<int>::const_iterator minIt = std::min_element(this->data.begin(), this->data.end());
    std::vector<int>::const_iterator maxIt = std::max_element(this->data.begin(), this->data.end());
    return (*maxIt - *minIt);
}

void Span::addNumber(int num)
{
    if (this->data.size() >= this->maxSize)
        throw std::out_of_range("You rich the limit of elments you can add");
    this->data.push_back(num);
}
