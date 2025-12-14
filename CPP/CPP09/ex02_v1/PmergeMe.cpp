#include "PmergeMe.hpp"

int check(std::string s)
{
    if(!s.length())
        return 1;
    for(int i = 0; s[i]; i++)
    {
        if(!isdigit(s[i]))
            return 1;
    }
    return 0;
}

bool check_input(int arc, char** arv) {

    (void)arc;
    for(int i = 1; arv[i]; i++)
    {
        if(check(arv[i]))
            return 0;
        double  d = std::atof(arv[i]);
        if(d > 2147483647)
            return 0;
    }
    return true;
}

std::vector<int> sort_vector(std::vector<int>& container, std::vector<std::pair<int, int> >& pair, int Unpaired) {

    build_pairs(container, pair);

    mergeSortRecursive(pair, 0, pair.size() - 1);

    std::vector<int> m_chain, p_chain;
    make_chains(pair, m_chain, p_chain);

    std::vector<int> JacobList = GenerateJacobstalNumbers<std::vector<int> >(p_chain.size());

    insertion_sort(m_chain, p_chain, JacobList, Unpaired);

    return m_chain;
}

std::deque<int> sort_deque(std::deque<int>& container, std::deque<std::pair<int, int> >& pair, int Unpaired) {

    build_pairs(container, pair);

    mergeSortRecursive(pair, 0, pair.size() - 1);

    std::deque<int> m_chain, p_chain;

    make_chains(pair, m_chain, p_chain);

    std::deque<int> JacobList = GenerateJacobstalNumbers<std::deque<int> >(p_chain.size());

    insertion_sort(m_chain, p_chain, JacobList, Unpaired);

    return m_chain;
}

void print_elements(int arc, char** arv)
{
    for (int i = 1; i < arc; i++)
    {
        std::cout << " " << arv[i];
    }
        std::cout << " \n";
}