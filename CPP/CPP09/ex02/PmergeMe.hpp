/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 00:57:41 by aait-bab          #+#    #+#             */
/*   Updated: 2025/12/14 14:09:09 by aait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cstdlib>


template <typename Container>
class PmergeMe {
private:
    Container numbers;
    Container mainChain;
    Container pendingChain;
    std::vector< std::pair<int,int> > pairs;
    int unpaired;

public:
    PmergeMe(char** av, int ac);

    void sort();
    const Container& getResult() const;

private:
    void createPairs();
    void mergeSortPairs(int left, int right);
    void mergePairs(int left, int mid, int right);
    void buildChains();
    void insertPending();
};

bool isValidInput(char** av);

template <typename C>
PmergeMe<C>::PmergeMe(char** av, int ac) : unpaired(-1)
{
    for (int i = 1; i < ac; i++)
        numbers.push_back(std::atoi(av[i]));

    if (numbers.size() % 2 != 0) {
        unpaired = numbers.back();
        numbers.pop_back();
    }
}


template <typename C>
void PmergeMe<C>::createPairs()
{
    for (size_t i = 0; i < numbers.size(); i += 2) {
        int p1 = numbers[i];
        int p2 = numbers[i + 1];

        if (p1 < p2)
            std::swap(p1, p2);

        pairs.push_back(std::make_pair(p1, p2));
    }
}


template <typename C>
void PmergeMe<C>::mergePairs(int left, int mid, int right)
{
    std::vector< std::pair<int,int> > leftPart;
    std::vector< std::pair<int,int> > rightPart;

    for (int i = left; i <= mid; i++)
        leftPart.push_back(pairs[i]);

    for (int i = mid + 1; i <= right; i++)
        rightPart.push_back(pairs[i]);

    int i = 0, j = 0, k = left;

    while (i < (int)leftPart.size() && j < (int)rightPart.size()) {
        if (leftPart[i].first <= rightPart[j].first)
            pairs[k++] = leftPart[i++];
        else
            pairs[k++] = rightPart[j++];
    }

    while (i < (int)leftPart.size())
        pairs[k++] = leftPart[i++];

    while (j < (int)rightPart.size())
        pairs[k++] = rightPart[j++];
}

template <typename C>
void PmergeMe<C>::mergeSortPairs(int left, int right)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    mergeSortPairs(left, mid);
    mergeSortPairs(mid + 1, right);
    mergePairs(left, mid, right);
}

template <typename C>
void PmergeMe<C>::buildChains()
{
    for (size_t i = 0; i < pairs.size(); i++) {
        mainChain.push_back(pairs[i].first);
        pendingChain.push_back(pairs[i].second);
    }

    mainChain.insert(mainChain.begin(), pendingChain.front());
    pendingChain.erase(pendingChain.begin());
}

template <typename C>
void PmergeMe<C>::insertPending()
{
    for (size_t i = 0; i < pendingChain.size(); i++) {
        typename C::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(),pendingChain[i]);
        mainChain.insert(pos, pendingChain[i]);
    }

    if (unpaired != -1) {
        typename C::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), unpaired);
        mainChain.insert(pos, unpaired);
    }
}

template <typename C>
void PmergeMe<C>::sort()
{
    if (numbers.size() <= 1) {
        mainChain.push_back(unpaired);
        return;
    }
    createPairs();
    mergeSortPairs(0, pairs.size() - 1);
    buildChains();
    insertPending();
}

template <typename C>
const C& PmergeMe<C>::getResult() const {
    return mainChain;
}

#endif