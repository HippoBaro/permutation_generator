//
// Created by Hippolyte Barraud on 15/10/2017.
//

#ifndef PERMUTATION_GENERATOR_STD_PERMUTATION_HPP
#define PERMUTATION_GENERATOR_STD_PERMUTATION_HPP

#include "permutations.hpp"

namespace hippobaro {
    class std_permutation {

        class container { };

    public:
        using container = container;

        template<typename InnerType>
        static auto create_permutation_iterator(InnerType &set) noexcept {
            return std::make_pair(permutation_iterator<decltype(set.begin())>(set.begin(), nullptr),
                                  permutation_iterator<decltype(set.end())>(set.end(), nullptr));
        }

        template<typename BidirIt>
        static bool next_permutation(permutation_iterator<BidirIt> &first,
                                     permutation_iterator <BidirIt> &last) {
            if (first == last) return false;
            auto i = last;
            if (first == --i) return false;

            while (true) {
                permutation_iterator <BidirIt> i1, i2;

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
