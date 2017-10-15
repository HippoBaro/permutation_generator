#include <iostream>
#include <vector>
#include <algorithms/sjt_permutation.hpp>
#include <cassert>
#include <list>
#include "algorithms/std_permutation.hpp"

size_t factorial(size_t n)
{
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

template<typename Algo, typename Container>
std::vector<Container> make_all_permutation(Container& container) {
    std::sort(container.begin(), container.end());
    auto its = hippobaro::create_permutation_iterators<Algo>(container);
    std::vector<Container> ret;
    ret.reserve(factorial(container.size()));

    do {
        ret.push_back(container);

    } while(hippobaro::next_permutation(its.first, its.second));
    return ret;
}

template<typename Algo, typename Container>
void output_all_permutation(Container& container) {
    std::sort(container.begin(), container.end());
    auto its = hippobaro::create_permutation_iterators<Algo>(container);


    do {
        for (auto &&item : container) {
            std::cout << item;
        }
        std::cout << std::endl;

    } while(hippobaro::next_permutation(its.first, its.second));
}

int main() {
    //STRING
    std::string s = { 'X', 'i', 'a', 'o', 'o' };

    if (!(std::unique(s.begin(), s.end()) == s.end())) {
        std::cout << "The input set contains non-unique elements" << std::endl;
        return 0;
    }

    auto sjt = make_all_permutation<hippobaro::sjt_permutation>(s);
    auto std = make_all_permutation<hippobaro::std_permutation>(s);

    std::sort(sjt.begin(), sjt.end());
    std::sort(std.begin(), std.end());

    assert(sjt.size() == std.size());

    for (size_t i = 0; i < std.size(); ++i) {
        assert(sjt[i] == std[i]);
    }
}