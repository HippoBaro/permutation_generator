#include <iostream>
#include <vector>
#include "permutations.hpp"
#include "algorithms/std_permutation.hpp"

int main()
{
    std::string s = "aba";

    auto its = hippobaro::std_permutation::create_permutation_iterator(s);
    std::sort<decltype(s)::iterator>(its.first, its.second);

    do {
        std::cout << s << std::endl;
    } while(next_permutation(its.first, its.second));

    //VECTOR

    std::cout << std::endl;

    std::vector<char> s2 = { 'a', 'b', 'a' };

    auto its2 = hippobaro::std_permutation::create_permutation_iterator(s2);
    std::sort<decltype(s2)::iterator>(its2.first, its2.second);

    do {
        for (auto &&item : s2)
            std::cout << item;
        std::cout << std::endl;
    } while(next_permutation(its2.first, its2.second));
}