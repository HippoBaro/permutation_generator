cmake_minimum_required(VERSION 3.8)
project(permutation_generator)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp include/permutations.hpp include/algorithms/log_permutation.hpp include/algorithms/sjt_permutation.hpp)
add_executable(permutation_generator ${SOURCE_FILES})

find_package(Boost 1.64 COMPONENTS program_options REQUIRED)
target_include_directories(permutation_generator PUBLIC include ${Boost_INCLUDE_DIR})

set(OPTS -O3 -Werror -Wall -Wextra)
target_compile_options(permutation_generator PUBLIC ${OPTS})

TARGET_LINK_LIBRARIES(permutation_generator LINK_PUBLIC ${Boost_LIBRARIES})