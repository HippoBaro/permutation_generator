# Permutation generator

**Combinatorics & Algorithms Design** assignment. The purpose of this assignment is to implement algorithms that generate all permutations given a set.

## Instructions

### Dependency

- `CMake 3.8` and newer
- `Boost 1.64` and newer

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

The code is tuned for performance with the exclusive use of fixed-sized arrays. The algorithm are implemented in STL style, allowing the compiler to specialize all operations for every data type.