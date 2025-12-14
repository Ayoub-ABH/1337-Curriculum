/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamqari <klamqari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 04:28:03 by klamqari          #+#    #+#             */
/*   Updated: 2025/02/20 07:01:54 by klamqari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <vector>
#include <deque>
#include <exception>
#include <sstream>
#include <ctime>
#include <sys/time.h>

template <typename T>
class PmergeMe
{
    private:
        double start_time;
        struct timeval tv;

    public :
        PmergeMe();
        PmergeMe(const PmergeMe & cpy);
        PmergeMe & operator=(const PmergeMe & cpy);
        ~PmergeMe();
    
        void sort(T & array, T & main_chain, T & pend_chain, T & jacobstathal_seq);
        
        void set_start_time();
    
        double get_process_time( );

};


void check_is_digits(const std::string & element);
int str_to_int(const std::string & str);
long jacob_number(int i);

template <typename T>
PmergeMe<T>::PmergeMe()
{
}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe & cpy)
{
    (void)cpy;
}

template <typename T>
PmergeMe<T> & PmergeMe<T>::operator=(const PmergeMe & cpy)
{
    (void)cpy;
    return *this;
}

template <typename T>
PmergeMe<T>::~PmergeMe()
{
}

template <typename T>
void PmergeMe<T>::set_start_time()
{
    gettimeofday(&(this->tv), NULL);
    this->start_time = tv.tv_usec + (tv.tv_sec * 1000000);
}

template <typename T>
double  PmergeMe<T>::get_process_time()
{
    gettimeofday(&(this->tv), NULL);
    return static_cast<double>(tv.tv_usec + (tv.tv_sec * 1000000)) - this->start_time;
}


template <typename T>
void print(T & array)
{
    typename T::iterator it = array.begin();
    typename T::iterator end = array.end();

    for (; it != end; ++it)
    {
        std::cout << *it << " " ;
    }

    std::cout << std::endl;
}




template <typename T>
void parse(T & array, char **av, int ac)
{
    if (ac < 2)
        throw std::invalid_argument("Error: no numbers provided");

    av++;
    ac--;
    
    for (int i = 0; i < ac; ++i)
    {
        check_is_digits(av[i]);
        array.push_back(str_to_int(av[i]));
    }
}

template <typename T>
void swap(T & array, int i, int j)
{
    int tmp;

    tmp   = array[i];
    array[i] = array[j];
    array[j] = tmp;

}

template <typename T>
void swap_pairs(T & array, int i, int j)
{
    int tmp;

    tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;

    tmp   = array[i + 1];
    array[i + 1] = array[j + 1];
    array[j + 1] = tmp;
}

template <typename T>
void sort_pair(T & array)
{
    int size = array.size();

    size = size - (size % 2);

    for (int i = 0; i < size; i += 2)
    {
        if (array[i] < array[i + 1])
        {
            swap(array, i, i + 1);
        }
    }
}

template <typename T>
void sort_pair_of_pair(T & array) // sort pairs using insertion sort algorithm
{
    int size = array.size();
    int tmp;
    int tmp1;
    int j;
    
    size = size - (size % 2);

    for (int i = 2; i < size; i += 2)
    {
        tmp = array[i];
        tmp1 = array[i + 1];
        
        j = i - 2;
        
        while (j >= 0 && tmp < array[j])
        {
            swap_pairs(array, j + 2, j);
            j -= 2;
        }
        array[j + 2] = tmp;
        array[j + 3] = tmp1;
    }
}

template <typename T>
int binary_search(T & arr, int target)
{
    int size = arr.size(), mid;
    int left = 0, right = size - 1;

    while (left <= right)
    {
        mid =  (right + left) / 2;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return left;
}

template <typename T>
void fill_chain(T & array, T & main_chain, int start)
{
    int size = array.size();

    size = size - (size % 2);

    for (int i = start; i < size; i += 2)
    {
        main_chain.push_back(array[i]);
    }
}



template <typename T>
void fill_jacobsthal_array(T & array, size_t n)
{
    int privious = 1, current, j = 3;

    if (n <= 0) return ;

    array.push_back(0);
    if (n == 1) return ;

    array.push_back(1);

    while (array.size() < n)
    {
        current = jacob_number(j);

        for (int i = current; i > privious; i--)
        {
            array.push_back(i);
        }
        privious = current;
        j++;
    }
}

template <typename T>
void insert_pend_to_main(T & jacobstathal_seq, T & pend_chain, T & main_chain)
{
    int pos;

    for (size_t i = 0; i < jacobstathal_seq.size(); i++)
    {
        if (static_cast<unsigned long>(jacobstathal_seq[i]) > pend_chain.size() - 1)
        {
            continue;
        }

        pos = binary_search(main_chain, pend_chain[jacobstathal_seq[i]]);
        main_chain.insert(main_chain.begin() + pos, pend_chain[jacobstathal_seq[i]]);
    }
}

template <typename T>
void insert_last_odd_element(T & array, T & main_chain)
{
    int pos;
    
    if (array.size() % 2 == 1)
    {
        pos = binary_search(main_chain, array.back());
        main_chain.insert(main_chain.begin() + pos, array.back());
    }
}

template <typename T>
void PmergeMe<T>::sort(T & array, T & main_chain, T & pend_chain, T & jacobstathal_seq)
{
    

    if (array.size() == 1) return ;

    sort_pair(array);

    sort_pair_of_pair(array);

    fill_chain(array, main_chain, 0);

    fill_chain(array, pend_chain, 1);

    fill_jacobsthal_array(jacobstathal_seq, pend_chain.size());

    insert_pend_to_main(jacobstathal_seq, pend_chain, main_chain);

    insert_last_odd_element(array, main_chain);
    
    array = main_chain;
}

#endif