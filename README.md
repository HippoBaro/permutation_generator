# Permutation generator

**Combinatorics & Algorithms Design** assignment. The purpose of this assignment is to implement algorithms that generate all permutations given a set.

## Instructions

### Dependency

- `CMake 3.8` and newer
- `Boost 1.64` and newer (only `program_options`)

### Compilation

```
$ git clone https://github.com/HippoBaro/permutation_generator.git
$ cd permutation_generator && mkdir build && cd build
$ cmake ..
$ make
$ ./permutation_generator --help
```

### Program options

| Option           | Description                                                      | Default  |
| ---------------- | ---------------------------------------------------------------- |:--------:|
| `algorithm`,`a`  | set algorithm [`log`, `sjt`]                                     |  `log`   |
| `elements`,`e`   | set number of elements                                           |   None   |
| `print`,`p`      | print output                                                     |   OFF    |

### Compiler support

The code uses some C++17 features. It has been compiled successfully on:
- `GCC 7.1` and newer
- `Clang 3.9.0` and newer

## Implementation

### Algorithms
- Lexicographic Order Generation — `log`
- Steinhaus–Johnson–Trotter — `sjt`

## Performances

The code is tuned for performance with the exclusive use of fixed-sized vectors. The algorithms are implemented in STL style, allowing the compiler to specialize all operations for every data type.

| Number of elements | LOG              | SJT             | STL        |
| ------------------ | ---------------- | --------------- | ---------- |
| 11!                | 0m0.172s         | 0m2.340s        | 0m0.161s   |
| 12!                | 0m1.856s         | 0m31.980s       | 0m1.760s   |
| 13!                | 0m23.941s        | ---------       | 0m21.679s  |

```
./permutation_generator -a log -e 5 -p
```
Will list and print all 5! permutation of the set $\{ 0, 1, 2, 3, 4 \}$ using the Lexicographic Order Generation algorithm.

## Bonus

### STL API

The implementation is heavily specialized and works for all container implementing `RandomAccessIterators`, i.e `std::array`, `std::string`, `std::vector`, etc. The permutations can be generated based on any data type implementing `operator<`.
The example's `main()` function uses `std::vector<size_t>` as a demonstration, but could use `std::string` with no further changes.
This is written in a *C++ zero-overhead* fashion where be able to use sophisticated iterator doesn't hurt performance if one prefers plain old pointers.

### Stateful and stateless API equivalent

The API allows other algorithms to be added very easily in their own files, regardless of whether their are stateful (as Steinhaus–Johnson–Trotter) or stateless (as Lexicographic Order Generation). Independently, the API remains the same, and memory allocation is performed iff necessary.