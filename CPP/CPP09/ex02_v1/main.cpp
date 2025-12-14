
#include "PmergeMe.hpp"

int main(int arc, char** arv) {

    if (arc < 2 || !check_input(arc, arv)) {
        std::cerr << "Invalid Args !!" << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::deque<int> deq;
    
    std::vector<std::pair<int, int> > v_pair;
    std::deque<std::pair<int, int> > d_pair;

    int unpaired_v = push_to_container(arc, vec, arv);
    int unpaired_d = push_to_container(arc, deq, arv);

    std::cout << "Before : ";
    print_elements(arc, arv);

    clock_t start, end;

    start = clock();
    std::vector<int> v_chain = (vec.size() > 1) ? sort_vector(vec, v_pair, unpaired_v) : vec;
    end = clock();
    double time_vec = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;

    start = clock();
    std::deque<int> d_chain = (deq.size() > 1) ? sort_deque(deq, d_pair, unpaired_d) : deq;
    end = clock();
    double time_deq = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;

    std::cout << "After  : ";
    last_print(v_chain);

    std::cout << "Time to process a range of " << v_chain.size() << " elements with std::vector : " << time_vec << " us\n";
    std::cout << "Time to process a range of " << d_chain.size() << " elements with std::deque  : " << time_deq << " us\n";

    return 0;
}