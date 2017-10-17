#include <iostream>
#include <vector>
#include <algorithms/sjt_permutation.hpp>
#include <cassert>
#include <list>
#include <boost/program_options.hpp>
#include "algorithms/log_permutation.hpp"

bool print = false;

size_t factorial(size_t n)
{
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

template<typename Algo, typename RandomIterator>
void make_all_permutation(RandomIterator begin, RandomIterator end) {
    std::sort(begin, end);
    auto its = hippobaro::create_permutation_iterators<Algo>(begin, end);

    size_t len = 0;
    do {
        ++len;
        if (print) {
            for (auto i = begin; i != end; ++i) {
                std::cout << *i << " ";
            }
            std::cout << std::endl;
        }
    } while(hippobaro::next_permutation(its.begin, its.end));
    std::cout << "Number of permutations: " << std::distance(begin, end) << "! = " << len << std::endl;
}

auto generate_vector(size_t len) {
    std::vector<int> s(len);
    for (size_t j = 0; j < len; ++j) {
        s[j] = (char)j;
    }
    return s;
}

int main(int ac, char **av) {
    namespace po = boost::program_options;
    po::options_description desc("Allowed options");
    desc.add_options()
            ("help,h", "produce help message")
            ("algorithm,a", po::value<std::string>()->default_value("std"), "set algorithm [log, sjt]")
            ("elements,e", po::value<size_t>(), "set number of elements")
            ("print,p", po::bool_switch(&print), "print output");

    po::variables_map vm;
    po::store(po::parse_command_line(ac, av, desc), vm);
    po::notify(vm);

    if (vm.count("help")) {
        std::cout << desc << "\n";
        return 1;
    }

    if (!vm.count("elements")) {
        std::cerr << "Number of elements was not set. See --help." << std::endl;
        return EXIT_FAILURE;
    }

    auto container = generate_vector(vm["elements"].as<size_t>());
    auto algo = vm["algorithm"].as<std::string>();
    if (algo == "log") {
        std::cout << "Algorithm: Lexicographic Order Generation" << std::endl;
        make_all_permutation<hippobaro::log_permutation>(std::begin(container), std::end(container));
    } else if (algo == "sjt") {
        std::cout << "Algorithm: Steinhaus–Johnson–Trotter" << std::endl;
        make_all_permutation<hippobaro::sjt_permutation>(std::begin(container), std::end(container));
    } else
        std::cerr << "Unknown algorithm. See -help." << std::endl;

    return EXIT_SUCCESS;
}
