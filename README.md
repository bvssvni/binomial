binomial
========

Generator in C for bit patterns of constant 1s and 0s.

Binomial numbers are important in combinatorics and statistics.

bin(n, m) gives how many ways it is possible to pick m items among n.

A binomial generator does not count, but produces the actual ways to pick items.

Each 1 in a bit pattern represents picking one item.

For example:

    0000100111000100
    
A such bit pattern can also be mapped to more than one dimensions:

    0000
    1001
    1100
    0100

64 bit allows a two dimensional 8x8 area which is used in Chess and Minesweeper beginner:

    00000000
    00000000
    00000000
    00000000
    00000000
    00000000
    00000000
    00000000
    
Any question asked about connections between a constant number of N items is subset of binomial generator.

By assigning each 1 as number, we can create a number system for each step in the generator.

Deriving number systems from binomial generators under different conditions is essential
to compute combinations of non-binary problems in discrete space, for example Chess or Minesweeper.

2D binary patterns got 4 symmetrical subsets, but I don't know yet how to generate a single one.

