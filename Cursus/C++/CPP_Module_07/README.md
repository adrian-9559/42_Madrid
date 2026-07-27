# CPP Module 07

## Overview
Introduction to C++ function templates and class templates. Generic programming with `swap`, `min`, `max`, an `iter` function, and a custom `Array` container.

## Exercises
- ex00: Function templates (swap, min, max)
- ex01: Iter template function
- ex02: Array class template

## Build and run
```bash
cd ex00 && make && ./whatever
cd ../ex01 && make && ./Iter
cd ../ex02 && make && ./Array
```

## Notes
- Follow canonical C++98 compilation flags from each Makefile.
- All templates are defined in header files (no `.cpp`).
- Subject functions are called with the global scope operator `::`.
