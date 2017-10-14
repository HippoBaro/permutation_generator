#include <iostream>
#include "permutations.hpp"
#include "algorithms/std_permutation.hpp"

int main()
{
    using hippobaro::std_permutation;

    std::string s = "aba";

    auto its = std_permutation::create_permutation_iterator(s);

    do {
        std::cout << s << std::endl;
    } while(hippobaro::next_permutation(its.first, its.second));
}