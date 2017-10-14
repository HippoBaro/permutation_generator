cmake_minimum_required(VERSION 3.8)
project(permutation_generator)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp include/permutations.hpp include/algorithms/std_permutation.hpp)
add_executable(permutation_generator ${SOURCE_FILES})

target_include_directories(permutation_generator PUBLIC include)

set(OPTS -O3 -Werror -Wall -Wextra)
target_compile_options(permutation_generator PUBLIC ${OPTS})