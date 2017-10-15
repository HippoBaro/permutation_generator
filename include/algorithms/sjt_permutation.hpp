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

        struct container {
            std::vector<direction> directions;
            bool reverse;

            explicit container(size_t set_size) noexcept : directions(set_size), reverse(false) {
                directions.reserve(set_size);
                for (auto &&item : directions) {
                    item = direction::left;
                }
            }
        };

    public:
        using container = container;

        template<typename InnerType>
        static std::shared_ptr<container> make_permutation_container(InnerType &set) noexcept {
            return std::make_shared<container>(set.size());
        }

        template<typename BidirIt>
        static bool next_permutation(permutation_iterator<BidirIt, sjt_permutation> &first,
                                     permutation_iterator <BidirIt, sjt_permutation> &last) {

            auto container = first.container.get();
            auto direction_for = [&] (BidirIt &item) {
                if (container->reverse) {
                    switch (container->directions[std::distance((BidirIt)first, item)]){
                        case direction::left:
                            return direction::right;
                        case direction::right:
                            return direction::left;
                    }
                }
                auto distance = std::distance((BidirIt)first, item);
                return container->directions[distance];
            };

            auto adjacent = [&] (BidirIt &item) {
                return item + (int)direction_for(item);
            };

            auto swap = [&] (BidirIt one, BidirIt two) {
                std::iter_swap(container->directions.begin() + std::distance((BidirIt)first, one),
                               container->directions.begin() + std::distance((BidirIt)first, two));
                std::iter_swap(one, two);
            };

            auto largest_mobile = [&] (BidirIt iterator) -> std::experimental::optional<BidirIt> {
                std::experimental::optional<BidirIt> ret = {};
                for (;iterator != (BidirIt)last; ++iterator) {
                    auto dir = direction_for(iterator);
                    if ((dir == direction::left && iterator == first)
                        || (dir == direction::right && adjacent(iterator) == last))
                        continue;
                    if (*iterator > *adjacent(iterator))
                        if (!ret || *iterator > **ret)
                            ret = iterator;
                }
                return ret;
            };

            if (auto lmob = largest_mobile(first)) {
                auto adj = adjacent(*lmob);
                swap(*lmob, adj);

                for(auto i = first; i != (BidirIt)last; ++i) {
                    if (i == adj)
                        continue;
                    auto i1 = *i;
                    if (i1 > *adj) {
                        auto index = std::distance(first, i);
                        switch (container->directions[index]) {
                            case direction::left:
                                container->directions[index] = direction::right;
                                break;
                            case direction::right:
                                container->directions[index] = direction::left;
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
