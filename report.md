#Generating permutations, an algorithmic perspective 

##Abstract
This paper focus on the implementations of two permutation generation algorithms, namely `Lexicographic Order Generation` and `Steinhaus–Johnson–Trotter`.

##Introduction

## Lexicographic Order Generation
### Step-by-step
### Performance

## Steinhaus–Johnson–Trotter
### Step-by-step
### Performance

##Results

| Number of nodes/digits | PIN   	| PATTERN     |
| ---------------------- | -------------------- | ------------------------- |
| 4				         | 10^4  				| 1624        				|
| 5         			 | 10^5  				| 7152                 		|
| 6         			 | 10^6  				| 26016						|
| 7         			 | 10^7  				| 72912						|
| 8         			 | 10^8  				| 140704					|
| 9         			 | 10^9  				| 140704					|
| **Σ**         		 | **1111110000** 		| **389112**     			|

As one can see from the above table, PIN locking always offers a better number of possibilities, making it an overall better security mechanism.