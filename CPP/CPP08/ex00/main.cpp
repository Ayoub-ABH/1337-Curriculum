/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:21:57 by aait-bab          #+#    #+#             */
/*   Updated: 2025/07/19 11:52:02 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>


int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(3);

    std::list<int> l;
    l.push_back(4);
    l.push_back(5);
    l.push_back(5);
    l.push_back(6);

    std::deque<int> d;
    d.push_back(7);
    d.push_back(8);
    d.push_back(8);
    d.push_back(9);

    try
    {
        easyfind(v, 30);   
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        easyfind(l, 5);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        easyfind(d, 8);    
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }    
    return 0;
}