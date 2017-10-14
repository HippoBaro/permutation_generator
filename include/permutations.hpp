//
// Created by Hippolyte Barraud on 14/10/2017.
//

#ifndef PERMUTATION_GENERATOR_PERMUTATION_HPP
#define PERMUTATION_GENERATOR_PERMUTATION_HPP

#include <algorithm>

namespace hippobaro {

    template<typename InnerItType, typename Algo>
    class permutation_iterator : public InnerItType::iterator {

    public:
        typedef typename InnerItType::iterator InnerIt;
        typedef typename Algo::container AlgoConatiner;
        using InnerIt::InnerIt;

        AlgoConatiner _container;

        explicit permutation_iterator(typename InnerItType::iterator iterator) : InnerItType::iterator(iterator) {}
    };

    template<typename BidirIt, typename Algo>
    bool next_permutation(permutation_iterator<BidirIt, Algo> &first, permutation_iterator<BidirIt, Algo> &last) {
        return Algo::next_permutation(first, last);
    }
}

#endif //PERMUTATION_GENERATOR_PERMUTATION_HPP
