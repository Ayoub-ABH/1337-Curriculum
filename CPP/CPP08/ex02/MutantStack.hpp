/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 09:22:08 by aait-bab          #+#    #+#             */
/*   Updated: 2025/07/19 11:01:52 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK

#define MUTANT_STACK

#include <iostream>
#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    public:
        typedef typename Container::iterator iterator;
        typedef typename Container::const_iterator citerator;
        typedef typename Container::reverse_iterator riterator;
        typedef typename Container::const_reverse_iterator criterator;

        MutantStack() {}
        MutantStack(const MutantStack &mutantStack)
        {
            *this = mutantStack;
        }
        ~MutantStack() {}

        MutantStack &operator=(const MutantStack &mutantstack)
        {
            if (this != &mutantstack)
            {
                this->c.clear();
                iterator it = mutantstack.c.begin();
                while (it != mutantstack.c.end())
                    this->c.push_back(*it++);
            }
            return (mutantstack);
        }

        iterator begin(void) 
        {
            return this->c.begin();
        }
        iterator end(void)
        {
            return this->c.end();
        }
        riterator rbegin(void)
        {
            return this->c.rbegin();
        }
        riterator rend(void)
        {
            return this->c.rend();
        }
        citerator cbegin(void)
        {
            return this->c.cbegin();
        }
        citerator cend(void)
        {
            return this->c.cend();
        }
        criterator crbegin(void)
        {
            return this->c.crbegin();
        }
        criterator crend(void)
        {
            return this->c.crend();
        }
};

#endif