# 🎮 CPP Module 02 — Polimorfismo ad-hoc (numbers in fixed point)

[![Nota](https://img.shields.io/badge/⭐_Nota-Aprobado-2ea44f)](./)
[![Módulo](https://img.shields.io/badge/📦_Módulo-02-1f6feb)](../)
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

Este módulo trata de **sobrecarga de operadores** y la **Forma Canónica Ortodoxa**, todo alrededor de una clase `Fixed` que representa números en **coma fija (fixed point)** con 8 bits fraccionarios. 🔢

Es el módulo donde las clases dejan de ser "cajas" y empiezan a **comportarse como tipos propios** (`+`, `-`, `<<`, comparaciones, conversiones).

## 🎯 Objetivos

- 🔧 Implementar los **operadores de clase** (`+`, `-`, `*`, `/`, comparadores, `<<`).
- 🧬 Aplicar la **Forma Canónica Ortodoxa**: constructor por defecto, copia, asignación y destructor.
- 🔄 **Conversiones** entre `float`/`int` y fixed point.
- 📏 Controlar la precisión con **8 bits fraccionarios** y redondeo.

## 📄 Ejercicios

### ex00 — Primer Canon
Clase `Fixed` con un entero `_fixedPointValue`, bits fraccionarios constantes y funciones `getRawBits()` / `setRawBits()`. Solo el esqueleto de la FCO.

```bash
./a.out
# Default constructor called
# Copy constructor called
# ...
# getRawBits() member function called
# 0
```

### ex01 — Hacia un número útil
Añade constructores desde `int` y `float`. Implementa `toFloat()`, `toInt()` y el operador de inserción `<<`. Resultado: `a is 1234.43`.

### ex02 — Ahora hablamos
Sobrecarga de **operadores aritméticos y comparativos**, funciones estáticas `min`/`max`, y pre/post-incremento/decremento.

## 🏗️ Estructura

```
CPP_Module_02/
├── ex00/  → ./a.out   # Fixed (solo getRawBits/setRawBits)
├── ex01/  → ./a.out   # Fixed con toFloat/toInt
├── ex02/  → ./a.out   # Fixed con +,-,*,/,<,>,min/max,++/--
└── README.md
```

## 🛠️ Compilación

```bash
cd ex00 && make && ./a.out
cd ../ex01 && make && ./a.out
cd ../ex02 && make && ./a.out
```

## 🚀 Uso y ejemplos

```bash
# ex01 espera:
$ ./a.out
0
0.00390625
10.1016
10

# ex02 espera (parte):
$ ./a.out
0
0.00390625
10.1016
10.1016
```

## 🧪 Verificación

| Herramienta | Comandos |
|---|---|
| **Compilación C++98** | `cd exXX && make && c++ -std=c++98` |
| **Salida exacta** | Compara la salida con el `main` del enunciado (debe ser idéntica) |
| **Precisión** | Valores como `10.1016` deben redondear bien con 8 bits |

💡 La evaluación mira con lupa:
- 🔢 **`std::cout << a`** → operador `<<` bien implementado (friend o función libre).
- 🔄 **`++` / `--`** pre y post (el post debe devolver el valor anterior).
- 🔀 `min`/`max` como **estáticas** que toman referencias constantes y devuelven la menor/mayor.

## 📚 Recursos

- [Índice C++](../README.md)
- [cppreference · Operadores](https://en.cppreference.com/w/cpp/language/operators)
- [cppreference · Forma Canónica Ortodoxa](https://en.cppreference.com/w/cpp/language/rule_of_three)