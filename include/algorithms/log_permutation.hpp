//
// Created by Hippolyte Barraud on 15/10/2017.
//

#ifndef PERMUTATION_GENERATOR_STD_PERMUTATION_HPP
#define PERMUTATION_GENERATOR_STD_PERMUTATION_HPP

#include "permutations.hpp"

namespace hippobaro {
    class log_permutation {

        struct container { };

    public:
        using container = container;

        template<typename InnerType>
        static std::shared_ptr<container> make_permutation_container(InnerType &) noexcept {
            return nullptr;
        }

        template<typename BidirIt>
        static bool next_permutation(permutation_iterator<BidirIt, log_permutation> &first,
                                     permutation_iterator <BidirIt, log_permutation> &last) {
            if (first == last) return false;
            auto i = last;
            if (first == --i) return false;
            while (true) {
                permutation_iterator <BidirIt, log_permutation> i1, i2;

                i1 = i;
                if (*--i < *i1) {
                    i2 = last;
                    while (!(*i < *--i2));
                    std::iter_swap(i, i2);
                    std::reverse(i1, last);
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
