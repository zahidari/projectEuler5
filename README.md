# Project Euler Problem 5 - Smallest Multiple

This repository contains a C++ solution for [Project Euler Problem 5](https://projecteuler.net/problem=5). The problem involves finding the smallest positive number that is evenly divisible by all numbers from 1 to 20.

## Problem Description

The smallest number that can be divided by each of the numbers from 1 to 10 without any remainder is 2520. The task is to find the smallest positive number that is evenly divisible by all numbers from 1 to 20.

## Solution

The solution provided in this repository explores two methods to solve the problem:

1. **Questioning Every Prime for Every Number**: 
This method involves iterating through each number from 1 to 20 and
finding the prime factors of each number. The prime factors are then 
stored in a vector, taking into account how many times each prime appears 
in the number.

2. **Logarithmic Approach**: This method leverages the concept of prime 
factorization. The logarithm of the searched number divided by the logarithm 
of prime numbers indicates how many times each prime number occurs in the number. 
The result is calculated by multiplying all prime numbers raised to 
their respective counts.

Both methods are explained in detail within the source code.

## Usage

To compile and run the solution, you can follow these steps:

1. Make sure you have a C++ compiler installed.
2. Copy the C++ code from `main.cpp` and save it to a file named `main.cpp`.
3. Open a terminal/command prompt and navigate to the directory where `main.cpp` is located.
4. Compile the code using the command: `g++ main.cpp -o smallest_multiple`
5. Run the compiled program: `./smallest_multiple`

The program will calculate and display the smallest positive number that
is evenly divisible by all numbers from 1 to 20.

## Contributing

Feel free to contribute improvements or optimizations to the solution.
 If you have any suggestions or find any issues, please open an issue 
 or a pull request.
