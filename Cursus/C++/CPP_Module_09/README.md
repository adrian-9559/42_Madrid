# CPP Module 09

## Overview
STL containers and algorithm efficiency. Three exercises exploring `std::map`, `std::stack`, and merge-insertion sort (Ford-Johnson) comparing `std::vector` vs `std::deque` performance.

## Exercises
- ex00: BitcoinExchange — historical BTC exchange rate calculator using `std::map` and `lower_bound`
- ex01: RPN — Reverse Polish Notation calculator using `std::stack<int>`
- ex02: PmergeMe — Ford-Johnson merge-insertion sort implemented with both `std::vector` and `std::deque`

## Build and run
```bash
cd ex00 && make && ./btc input.txt
cd ../ex01 && make && ./RPN "8 9 * 9 -"
cd ../ex02 && make && ./PmergeMe 3 5 9 7 4
```

## Notes
- Follow canonical C++98 compilation flags from each Makefile.
- `BitcoinExchange` uses `std::map` for O(log n) date lookups.
- `RPN` evaluates expressions left-to-right with a stack in O(n).
- `PmergeMe` demonstrates that container choice affects real-world performance even with identical algorithms.
