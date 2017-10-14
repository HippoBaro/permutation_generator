//
// Created by Hippolyte Barraud on 14/10/2017.
//

#ifndef PERMUTATION_GENERATOR_PERMUTATION_HPP
#define PERMUTATION_GENERATOR_PERMUTATION_HPP

#include <algorithm>
#include <experimental/any>
#include <experimental/type_traits>

namespace hippobaro {

    template<typename InnerIt, typename Algo>
    class permutation_iterator : public InnerIt {

    public:
        using InnerIt::InnerIt;

        std::shared_ptr<typename Algo::container> container;

        explicit permutation_iterator(InnerIt iterator,
                             std::shared_ptr<typename Algo::container> container = nullptr) noexcept :
                InnerIt(iterator), container(container) {}

        explicit operator InnerIt() const { return *this; }

    };

    template<typename Algo, typename InnerType>
    static auto create_permutation_iterators(InnerType &set) noexcept {
        return std::make_pair(permutation_iterator<decltype(set.begin()), Algo>(set.begin(), nullptr),
                              permutation_iterator<decltype(set.end()), Algo>(set.end(), nullptr));
    }

    template<typename Algo, typename BidirIt>
    bool next_permutation(permutation_iterator<BidirIt, Algo> &first, permutation_iterator<BidirIt, Algo> &last) {
        return Algo::next_permutation(first, last);
    }
}

#endif //PERMUTATION_GENERATOR_PERMUTATION_HPP
