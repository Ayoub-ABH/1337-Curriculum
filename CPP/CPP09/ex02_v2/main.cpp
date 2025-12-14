/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamqari <klamqari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 04:28:14 by klamqari          #+#    #+#             */
/*   Updated: 2025/02/20 07:02:44 by klamqari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename T>
void print(T & array);

template <typename T>
void parse(T & array, char **av, int ac);



int main(int ac, char **av)
{

    double time_to_process_dq = 0.0, time_to_process_vc = 0.0;

    try
    {
        {
            
            PmergeMe<std::vector<int> > merge_insert;
    
            std::vector<int> array, main_chain, pend_chain, jacobstathal_seq;
            
            parse(array, av, ac);
            std::cout << "Before:   " ;

            print(array);
            
            merge_insert.set_start_time();
            merge_insert.sort(array, main_chain, pend_chain, jacobstathal_seq);
            time_to_process_vc = merge_insert.get_process_time();
            
        }
        {

            PmergeMe<std::deque<int> > merge_insert;
    
            std::deque<int> array, main_chain, pend_chain, jacobstathal_seq;
            parse(array, av, ac);
            
            merge_insert.set_start_time();
            merge_insert.sort(array, main_chain, pend_chain, jacobstathal_seq);
            time_to_process_dq = merge_insert.get_process_time();
        
            std::cout << "After:    ";
            print(array);
        }
    
        std::cout << "Time to process a range of 5 elements with std::vector : " << time_to_process_vc << std::endl;
        std::cout << "Time to process a range of 5 elements with std::deque  : " << time_to_process_dq << std::endl;
    
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}