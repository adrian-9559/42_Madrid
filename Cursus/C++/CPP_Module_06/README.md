# 🎮 CPP Module 06 — Casts de C++

[![Nota](https://img.shields.io/badge/⭐_Nota-Aprobado-2ea44f)](./)
[![Módulo](https://img.shields.io/badge/📦_Módulo-06-1f6feb)](../)
[![Lenguaje](https://img.shields.io/badge/🛠️_C++98-00599c)](./)

---

## 🧭 Índice

1. [🌟 Introducción](#-introducción)
2. [🎯 Objetivos](#-objetivos)
3. [📄 Ejercicios](#-ejercicios)
4. [🏗️ Estructura](#️-estructura)
5. [🛠️ Compilación](#️-compilación)
6. [🚀 Uso y ejemplos](#-uso-y-ejemplos)
7. [🧪 Verificación](#-verificación)
8. [📚 Recursos](#-recursos)

---

## 🌟 Introducción

Módulo dedicado a los **cuatro casts de C++**: `static_cast`, `dynamic_cast`, `reinterpret_cast` y `const_cast` (este último solo de boquilla 😉). Descubre **cuándo usar cada uno** y por qué son más seguros que el cast de C.

## 🎯 Objetivos

- 🔄 Dominar **`static_cast`** (conversiones en tiempo de compilación).
- 🔮 Usar **`reinterpret_cast`** para tratar memoria como otro tipo (serialización).
- 🕵️ Implementar **`dynamic_cast`** para *RTTI* (identificación en tiempo de ejecución).
- 🧮 Conversión de literales escalares (char, int, float, double).

## 📄 Ejercicios

### ex00 — 🔢 ScalarConverter
Clase `ScalarConverter` con método estático `convert()`. Dado un literal (`42`, `42.0f`, `a`, `nan`, `inf`…), imprime su valor como `char`, `int`, `float` y `double` con los casos imposibles/de borde (`impossible`, `non displayable`).

### ex01 — 💾 Serializer
`Serializer` con `serialize()` (puntero → `uintptr_t` vía `reinterpret_cast`) y `deserialize()` (el camino inverso). Debe preservar el puntero original.

### ex02 — 🎭 Base
Clase `Base` abstracta, sin atributos. `A`, `B`, `C` derivadas. Funciones `identify(Base*)` y `identify(Base&)` que averiguan el tipo real usando **`dynamic_cast`**.

## 🏗️ Estructura

```
CPP_Module_06/
├── ex00/  → ./Conversion     # ScalarConverter
├── ex01/  → ./Serializer
├── ex02/  → ./Identify       # Base + A/B/C
└── README.md
```

## 🛠️ Compilación

```bash
cd ex00 && make && ./Conversion "42.0f"
cd ../ex01 && make && ./Serializer
cd ../ex02 && make && ./Identify
```

## 🚀 Uso y ejemplos

```bash
./Conversion "42.0f"
# char: '*' | int: 42 | float: 42.0f | double: 42.0

./Conversion "nan"
# char: impossible | int: impossible | float: nanf | double: nan

./Conversion "a"
# char: 'a' | int: 97 | float: 97.0f | double: 97.0

./Identify
# A es Base A | B es Base B | C es Base C
```

## 🧪 Verificación

| Herramienta | Comandos |
|---|---|
| **Compilación C++98** | `cd exXX && make && c++ -std=c++98` |
| **Casos borde** | `0`, `-42`, `2147483647`, `nan`, `+inf`, `inf`, `""`, `z` (overflow) |
| **Serializer** | Tras `deserialize(serialize(p))` el puntero debe ser `p` (compara direcciones) |
| **identify(B&)** | Con una referencia a `B`, debe imprimir "B" (dynamic_cast devuelve null en el fallo) |

💡 En `identify(Base&)`, para `dynamic_cast` sobre referencia hay que capturar la excepción `std::bad_cast` (no devuelve null).

## 📚 Recursos

- [Índice C++](../README.md)
- [cppreference · static_cast](https://en.cppreference.com/w/cpp/language/static_cast)
- [cppreference · dynamic_cast](https://en.cppreference.com/w/cpp/language/dynamic_cast)
- [cppreference · reinterpret_cast](https://en.cppreference.com/w/cpp/language/reinterpret_cast)