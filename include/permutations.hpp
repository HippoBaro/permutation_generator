//
// Created by Hippolyte Barraud on 14/10/2017.
//

#ifndef PERMUTATION_GENERATOR_PERMUTATION_HPP
#define PERMUTATION_GENERATOR_PERMUTATION_HPP

#include <algorithm>
#include <experimental/any>

namespace hippobaro {

    template<typename InnerIt>
    class permutation_iterator : public InnerIt {

    public:
        using InnerIt::InnerIt;

        std::shared_ptr<std::experimental::any> container;

        template<typename Algo>
        permutation_iterator(InnerIt iterator,
                             std::shared_ptr<typename Algo::container> &container) noexcept :
                InnerIt(iterator), container(container) {}

        template<typename Algo>
        permutation_iterator(InnerIt iterator,
                             std::shared_ptr<typename Algo::container> container = nullptr) noexcept :
                InnerIt(iterator), container(container) {}

        explicit operator InnerIt() const { return *this; }

    };

    template<typename BidirIt, typename Algo>
    bool next_permutation(permutation_iterator<BidirIt> &first, permutation_iterator<BidirIt> &last) {
        return Algo::next_permutation(first, last);
    }
}

#endif //PERMUTATION_GENERATOR_PERMUTATION_HPP
