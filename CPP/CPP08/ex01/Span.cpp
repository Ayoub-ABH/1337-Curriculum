/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:15:09 by aait-bab          #+#    #+#             */
/*   Updated: 2025/07/17 11:32:21 by aait-bab         ###   ########.fr       */
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
        for (size_t i; i < span.data.size(); i++)
            this->data.push_back(span.data[i]);
   }
   return *this;
}

// template<typename It>
// void Span::addRange(It begin, It end);

int Span::shortestSpan() const
{
    
}

int Span::longestSpan() const
{
    std::sort(this->data.begin(), this->data.begin());
    return (this->data.back() - this->data.front());
}

void Span::addNumber(int num)
{
    
}
