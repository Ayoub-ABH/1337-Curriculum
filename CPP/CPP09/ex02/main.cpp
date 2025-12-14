/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 01:00:46 by aait-bab          #+#    #+#             */
/*   Updated: 2025/12/14 01:28:47 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char** av) {

    if (ac < 2) {
        std::cerr << "Error: Not enough arguments." << std::endl;
        return 1;
    }

    if (!isValidInput(av)) {
        std::cerr << "Error: Invalid argument" << std::endl;
        return 1;
    }

    std::cout << "Before : ";
    for (int i = 1; av[i]; i++)
        std::cout << av[i] << " ";
    std::cout << std::endl;

    clock_t start, end;

    start = clock();
    PmergeMe< std::vector<int> > vectorSorter(av, ac);
    vectorSorter.sort();
    end = clock();

    double time_vec = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;

    start = clock();
    PmergeMe< std::deque<int> > dequeSorter(av, ac);
    dequeSorter.sort();
    end = clock();

    double time_deq = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;

    std::cout << "After  : ";
    const std::vector<int>& sortedVector = vectorSorter.getResult();
    for (size_t i = 0; i < sortedVector.size(); i++)
        std::cout << sortedVector[i] << " ";
    std::cout << std::endl;
    

    std::cout << "Time to process a range of " << sortedVector.size() << " elements with std::vector : " << time_vec << " us\n";
    std::cout << "Time to process a range of " << sortedVector.size() << " elements with std::deque  : " << time_deq << " us\n";
    return 0;
}