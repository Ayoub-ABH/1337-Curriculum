/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:15:13 by aait-bab          #+#    #+#             */
/*   Updated: 2025/07/19 09:15:57 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP

# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
    private:
        unsigned int maxSize;
    public:
        std::vector<int> data;
        Span();
        Span(unsigned int N);
        Span(const Span& span);
        ~Span();
        Span& operator=(const Span& span);

        template<typename It>
        void addRange(It begin, It end)
        {
            std::size_t distance = std::distance(begin, end);
            if (this->data.size() + distance > this->maxSize)
                throw std::runtime_error("Adding this range would exceed Span capacity.");
            while (begin != end)
            {
                this->data.push_back(*begin);
                ++begin;
            }
        }
        
        int shortestSpan();
        int longestSpan();
        
        void addNumber(int num);
};

#endif