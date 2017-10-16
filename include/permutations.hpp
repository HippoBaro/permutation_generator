//
// Created by Hippolyte Barraud on 14/10/2017.
//

#ifndef PERMUTATION_GENERATOR_PERMUTATION_HPP
#define PERMUTATION_GENERATOR_PERMUTATION_HPP

#include <iterator>
#include <algorithm>
#include <experimental/any>
#include <experimental/type_traits>

namespace hippobaro {

    struct stateful_algorithm {};
    struct stateless_algorithm {};

    template<typename InnerType, typename Algo, typename ContainerIterator = char>
    class permutation_iterator {

    private:
        InnerType _it;

    public:

        typedef InnerType                                                       iterator_type;
        typedef typename std::iterator_traits<iterator_type>::iterator_category iterator_category;
        typedef typename std::iterator_traits<iterator_type>::value_type        value_type;
        typedef typename std::iterator_traits<iterator_type>::difference_type   difference_type;
        typedef typename std::iterator_traits<iterator_type>::pointer           pointer;
        typedef typename std::iterator_traits<iterator_type>::reference         reference;

        ContainerIterator container_item;

        explicit permutation_iterator(InnerType iterator, typename Algo::container_iterator container_item) noexcept :
                _it(iterator), container_item(container_item) {}

        explicit permutation_iterator(InnerType iterator) noexcept :
                _it(iterator), container_item() {}

        operator iterator_type() const { return _it; }

        bool operator==( permutation_iterator const& rhs) const {
            return _it == rhs._it;
        }

        bool operator!=(permutation_iterator const& rhs) const {
            return !(rhs == *this);
        }

        bool operator<(permutation_iterator const& rhs) const {
            return _it < rhs._it;
        }

        bool operator>(permutation_iterator const& rhs) const {
            return rhs < *this;
        }

        bool operator<=(permutation_iterator const& rhs) const {
            return !(rhs < *this);
        }

        bool operator>=(permutation_iterator const& rhs) const {
            return !(*this < rhs);
        }

        permutation_iterator &operator--() {
            --container_item;
            --_it;
            return *this;
        }

        permutation_iterator &operator++() {
            ++container_item;
            ++_it;
            return *this;
        }

        permutation_iterator operator-(int rhs) const {
            return permutation_iterator(_it - rhs, container_item - rhs);
        }

        permutation_iterator operator+(int rhs) const {
            return permutation_iterator(_it + rhs, container_item + rhs);
        }

        reference operator*() const {
            return *_it;
        }
    };

    template<typename InnerType, typename Algo, typename ContainerIterator = char>
    struct permutation_iterator_container {
        permutation_iterator<InnerType, Algo, ContainerIterator> begin;
        permutation_iterator<InnerType, Algo, ContainerIterator> end;
    };

    template<typename InnerType, typename Algo, typename ContainerIterator>
    struct permutation_stateful_iterator_container : public permutation_iterator_container<InnerType, Algo, ContainerIterator> {
        std::unique_ptr<typename Algo::container_type> container;
    };

    template<typename Algo, typename RandomIterator>
    static auto create_permutation_iterators(RandomIterator const& begin, RandomIterator const& end) noexcept {
        if constexpr (std::is_same<typename Algo::statefulness, stateful_algorithm>::value) {
            auto state_container = Algo::make_permutation_container(begin, end);
            permutation_stateful_iterator_container<RandomIterator, Algo, typename Algo::container_iterator> cnt { { permutation_iterator<RandomIterator, Algo, typename Algo::container_iterator>(begin, state_container->begin()),
                                                                                                                   permutation_iterator<RandomIterator, Algo, typename Algo::container_iterator>(end, state_container->end()) },
                                                                                                                   std::move(state_container) };
            return cnt;
        }
        else {
            permutation_iterator_container<RandomIterator, Algo> cnt {permutation_iterator<RandomIterator, Algo>(begin), permutation_iterator<RandomIterator, Algo>(end)};
            return cnt;
        }
    }

    template<typename Algo, typename RandomIterator>
    constexpr bool next_permutation(permutation_iterator<RandomIterator, Algo, typename Algo::container_iterator> const &first,
                                    permutation_iterator<RandomIterator, Algo, typename Algo::container_iterator> const &last) {
        if constexpr (std::is_pointer<RandomIterator>::value) {
            return Algo::template next_permutation<RandomIterator>(first, last);
        }
        else {
            return Algo::next_permutation(first, last);
        }

    }
}

#endif //PERMUTATION_GENERATOR_PERMUTATION_HPP
