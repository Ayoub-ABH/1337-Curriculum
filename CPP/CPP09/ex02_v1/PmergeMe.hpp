
#include <iostream>
#include <vector>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <cmath>
#include <utility> 
#include <cstdlib> 

bool is_valid_number(const std::string& s);
bool check_input(int arc, char** arv) ;


template <typename Container>
int push_to_container(int arc, Container& container, char** arv) {

    int Unpaired = -1;
    if ((arc - 1) % 2 == 0) {

        for (int i = 1; i < arc; i++)
            container.push_back(std::atoi(arv[i]));

    } else if ((arc - 1) % 2 != 0 && arc > 2){

        for (int i = 1; i < arc - 1; i++)
            container.push_back(std::atoi(arv[i]));
        Unpaired = std::atoi(arv[arc - 1]);

    }
    else
        container.push_back(std::atoi(arv[arc -1]));

    return Unpaired;
}

template <typename Container, typename PairContainer>
void build_pairs(Container& container, PairContainer& pair) {

    typename Container::iterator it = container.begin();

    while (it != container.end()) {
        int first = *it++;
        int second = -1;
        if (it != container.end())
            second = *it++;
        else
            second = 0;
        pair.push_back(std::make_pair(first, second));
    }

    for (typename PairContainer::iterator it = pair.begin(); it != pair.end(); ++it) {
        if (it->first < it->second) 
            std::swap(it->first, it->second);
    }
}

template <typename Container>
void merge(Container& v, size_t left, size_t mid, size_t right) {

    size_t n1 = mid - left + 1;
    size_t n2 = right - mid;
    Container leftArr, rightArr;

    for (size_t i = 0; i < n1; i++)
        leftArr.push_back(v[left + i]);

    for (size_t j = 0; j < n2; j++)
        rightArr.push_back(v[mid + 1 + j]);
        
    size_t i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i].first <= rightArr[j].first)
            v[k++] = leftArr[i++];
        else
            v[k++] = rightArr[j++];
    }

    while (i < n1)
        v[k++] = leftArr[i++];

    while (j < n2)
        v[k++] = rightArr[j++];
}

template <typename Container>
void mergeSortRecursive(Container& v, size_t left, size_t right) {
    if (left < right) {
        size_t mid = left + (right - left) / 2;
        mergeSortRecursive(v, left, mid);
        mergeSortRecursive(v, mid + 1, right);
        merge(v, left, mid, right);
    }
}

template <typename PairContainer, typename Container>
void make_chains(PairContainer& pair, Container& m_chain, Container& p_chain) {

    for (typename PairContainer::iterator it = pair.begin(); it != pair.end(); ++it) {
        m_chain.push_back(it->first);
        p_chain.push_back(it->second);
    }

    m_chain.insert(m_chain.begin(), p_chain.front());
    p_chain.erase(p_chain.begin());
}

template <typename Container>
Container GenerateJacobstalNumbers(int size)
{
    Container jacobstalNumbers;
    Container combn;
    jacobstalNumbers.push_back(0);
    jacobstalNumbers.push_back(1);
    jacobstalNumbers.push_back(3);

    int next = 0;
    for(int i = 3;i < size && next < size; i++)
    {
        next = jacobstalNumbers[i - 1] + (2 * jacobstalNumbers[i - 2]);
        jacobstalNumbers.push_back(next);
    }

    for(int i = 0; i < (int)jacobstalNumbers.size() ;i++)
    {
        int start = jacobstalNumbers[i];
        int end = jacobstalNumbers[i + 1];

        combn.push_back(start);
        if ((end - start) > 1) {
            for (int j = end - 1; j > start; --j)
                combn.push_back(j);
        }
    }
    combn.push_back(jacobstalNumbers.back()); 
    return combn;
}

template <typename Container>
void insertion_sort(Container& m_chain, Container& p_chain, const Container& combn, int Unpaired) {

    int y = 0;
    for(int i = 0; y < (int)p_chain.size(); i++)
    {
        if (combn[i] >= (int)p_chain.size())
            continue;
        typename Container::iterator pos = std::lower_bound(m_chain.begin(), m_chain.end(), p_chain[combn[i]]);
        m_chain.insert(pos,p_chain[combn[i]]);
        y++;
    }

    if (Unpaired != -1) {
        typename Container::iterator pos = std::lower_bound(m_chain.begin(), m_chain.end(), Unpaired);
        m_chain.insert(pos, Unpaired);
    }
}

std::vector<int> sort_vector(std::vector<int>& container, std::vector<std::pair<int, int> >& pair, int Unpaired);
std::deque<int> sort_deque(std::deque<int>& container, std::deque<std::pair<int, int> >& pair, int Unpaired) ;
void print_elements(int arc, char** arv);

template <typename Container>
void last_print(Container& container)
{
    for (typename Container::iterator it = container.begin(); it != container.end(); it++)
    {
        std::cout << " " << *it;
    }
        std::cout << " \n";
}