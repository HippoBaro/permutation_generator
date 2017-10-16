//
// Created by Hippolyte Barraud on 15/10/2017.
//

#ifndef PERMUTATION_GENERATOR_STD_PERMUTATION_HPP
#define PERMUTATION_GENERATOR_STD_PERMUTATION_HPP

#include "permutations.hpp"

namespace hippobaro {
    class log_permutation {

    public:
        typedef stateless_algorithm         statefulness;
        typedef char                        container_type;
        typedef char                        container_iterator;

        template<typename RandomIterator>
        constexpr static bool next_permutation(RandomIterator const &first, RandomIterator const &last) {
            auto i = last;
            if (first == last || first == --i)
                return false;
            while (true) {
                auto ip1 = i;
                if (*--i < *ip1) {
                    auto j = last;
                    while (!(*i < *--j));
                    std::iter_swap(i, j);
                    std::reverse(ip1, last);
                    return true;
                }
                if (i == first) {
                    std::reverse(first, last);
                    return false;
                }
            }
        }
    };
}

#endif //PERMUTATION_GENERATOR_STD_PERMUTATION_HPP
