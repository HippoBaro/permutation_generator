#include <iostream>
#include <vector>
#include "permutations.hpp"
#include "algorithms/std_permutation.hpp"

template<typename Algo, typename Container>
void output_all_permutation(Container& container) {
    auto its = hippobaro::create_permutation_iterators<Algo>(container);
    std::sort<typename Container::iterator>(its.first, its.second);

    do {
        for (auto &&item : container) {
            std::cout << item;
        }
        std::cout << std::endl;

    } while(hippobaro::next_permutation(its.first, its.second));
}

int main()
{
    //STRING
    std::string s = "aba";
    output_all_permutation<hippobaro::std_permutation>(s);

    //VECTOR
    std::cout << std::endl;

    std::vector<char> s2 = { 'a', 'b', 'a' };
    output_all_permutation<hippobaro::std_permutation>(s2);
}