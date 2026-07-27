# CPP Module 08

## Overview
Introduction to STL containers and iterators. Implementing `easyfind`, `Span`, and `MutantStack` — a stack subclass with full iterator support.

## Exercises
- ex00: easyfind — template function to find a value in any container
- ex01: Span — store N numbers and compute shortest/longest span
- ex02: MutantStack — `std::stack` with iterators

## Build and run
```bash
cd ex00 && make && ./easyfind
cd ../ex01 && make && ./span
cd ../ex02 && make && ./mutantstack
```

## Notes
- Follow canonical C++98 compilation flags from each Makefile.
- Templates and class definitions are in header files.
- `MutantStack` inherits from `std::stack` and exposes `begin()`/`end()` iterators.
