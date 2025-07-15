/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 08:00:47 by aait-bab          #+#    #+#             */
/*   Updated: 2025/07/15 10:05:37 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP

#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
    private:
        T* array;
        unsigned int n;
    public:
        Array()
        {
            this->n = 0;
            this->array = new T[0];
        }   
        
        Array(unsigned int n)
        {
            this->n = n;
            this->array = new T[n];
        }
        
        Array& operator=(const Array& arr)
        {
            if (this != &arr) {
                if (this->array)
                    delete[] this->array;
                this->n = arr.n;
                this->array = new T[arr.n];
                for (unsigned int i = 0; i < n; ++i)
                    this->array[i] = arr.array[i];
            }
            return (*this);
        }
        
        Array(const Array& arr)
        {
            this->array = NULL;
            *this = arr;
        }
        
        T& operator[](unsigned int idx) const
        {
            if (idx >= this->n)
			    throw std::out_of_range("Index out of bounds");
            return (this->array[idx]);
        }

        ~Array()
        {
            if (this->array)
                delete[] array;
        }  

        unsigned int size(void) const
        {
            return (this->n);
        }  
         
};


#endif

