//
// Created by Hippolyte Barraud on 15/10/2017.
//

#ifndef PERMUTATION_GENERATOR_SJT_PERMUTATION_HPP
#define PERMUTATION_GENERATOR_SJT_PERMUTATION_HPP

#include <vector>
#include <experimental/optional>
#include "permutations.hpp"

namespace hippobaro {
    class sjt_permutation {

        enum class direction {
            left = -1,
            right = 1
        };

    public:
        typedef stateful_algorithm          statefulness;
        typedef std::vector<direction>      container_type;
        typedef container_type::iterator    container_iterator;

        template<typename RandomIterator>
        static std::unique_ptr<container_type> make_permutation_container(RandomIterator const& begin, RandomIterator const& end) noexcept {
            auto count = std::distance(begin, end);
            auto cnt = std::make_unique<container_type>(count);
            for (auto &&item : *cnt) {
                item = direction::left;
            }
            return cnt;
        }

        template<typename RandomIterator>
        static bool inline next_permutation(permutation_iterator<RandomIterator, sjt_permutation, container_iterator> const &first,
                                     permutation_iterator <RandomIterator, sjt_permutation, container_iterator> const &last) {
            auto largest_mobile = [&] (auto iterator) {
                std::experimental::optional<decltype(iterator)> ret = {};
                for (;iterator != last; ++iterator) {
                    auto dir = *iterator.container_item;
                    auto adj = iterator + (int)dir;
                    if ((dir == direction::left && iterator == first)
                        || (dir == direction::right && adj == last))
                        continue;
                    if (*iterator > *adj)
                        if (!ret || *iterator > **ret)
                            ret = iterator;
                }
                return ret;
            };

            if (auto lmob = largest_mobile(first)) {
                auto adj = *lmob + (int)*(*lmob).container_item;

                std::iter_swap(lmob->container_item, adj.container_item);
                std::iter_swap(*lmob, adj);

                for(auto i = first; i != last; ++i) {
                    if (i == adj)
                        continue;
                    auto i1 = *i;
                    if (i1 > *adj) {
                        switch (*i.container_item) {
                            case direction::left:
                                *i.container_item = direction::right;
                                break;
                            case direction::right:
                                *i.container_item = direction::left;
                                break;
                        }
                    }
                }
                return true;
            }
            return false;
        }
    };
}
#endif //PERMUTATION_GENERATOR_SJT_PERMUTATION_HPP
