# CPP Module 06

## Overview
C++ casts — static_cast, reinterpret_cast, and dynamic_cast through type conversion, pointer serialization, and runtime class identification.

## Exercises
- ex00: ScalarConverter
- ex01: Serializer
- ex02: Base (identify via dynamic_cast)

## Build and run
```bash
cd ex00 && make && ./Conversion "42.0f"
cd ../ex01 && make && ./Serializer
cd ../ex02 && make && ./Identify
```

## Notes
- Follow canonical C++98 compilation flags from each Makefile.
- Keep memory management simple and explicit.
