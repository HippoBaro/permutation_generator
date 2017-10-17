#Generating permutations, an algorithmic perspective 

##Abstract
The focus of this paper is the implementation of two permutation generation algorithms, namely `Lexicographic Order Generation` and `Steinhaus–Johnson–Trotter`.

## Lexicographic Order Generation
The *Lexicographic Order Generation* algorithm is the fastest algorithm to find the next lexicographic permutation.
It is currently the *de facto* implementation in many languages. `std::next_permutation` is implemented using this algorithm.

### Step-by-step
1. Find largest index `i` such that `array[i − 1] < array[i]`. (If no such i exists, then this is already the last permutation.)
2. Find largest index `j` such that `j ≥ i` and `array[j] > array[i − 1]`.
3. Swap `array[j]` and `array[i − 1]`.
4. Reverse the suffix starting at `array[i]`.
### Performance
At most $N/2$ swaps, where $N$ is the number of elements in the set to permute.

## Steinhaus–Johnson–Trotter  (Shimon Even version)
The *Steinhaus–Johnson–Trotter* is a formalisation of a very old permutation generation algorithm. It works by swapping adjacent elements from the previous permutation.
The following implementation uses Shimon Even's modification, adding a *direction* to each elements.

### Step-by-step
1. Sort the set in lexicographical order and associate `LEFT` as the direction for each of the elements
2. Find the largest mobile integer and swap it with the adjacent element on its direction without changing the direction of any of these two.
4. Check if there’s any number, larger than the current largest mobile integer. If there’s one or more, change the direction of all of them.

### Performance
At most $N!$ swaps, where $N$ is the number of elements in the set to permute.

##Results

| Number of elements | LOG              | SJT             | STL        |
| ------------------ | ---------------- | --------------- | ---------- |
| 11!                | 0m0.172s         | 0m2.340s        | 0m0.161s   |
| 12!                | 0m1.856s         | 0m31.980s       | 0m1.760s   |
| 13!                | 0m23.941s        | ---------       | 0m21.679s  |