/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:15:13 by aait-bab          #+#    #+#             */
/*   Updated: 2025/07/17 11:28:46 by aait-bab         ###   ########.fr       */
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
        std::vector<int> data;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& span);
        ~Span();
        Span& operator=(const Span& span);

        template<typename It>
        void addRange(It begin, It end);
        
        int shortestSpan() const;
        int longestSpan() const;
        
        void addNumber(int num);
};

#endif