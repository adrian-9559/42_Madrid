# 🎮 CPP Module 09 — STL avanzada y eficiencia

[![Nota](https://img.shields.io/badge/⭐_Nota-Aprobado-2ea44f)](./)
[![Módulo](https://img.shields.io/badge/📦_Módulo-09-1f6feb)](../)
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

Último módulo de C++ del Cursus y el que más "me gusta resolver con cómputo real": tres programas que exprimen la **STL** y comparan la **eficiencia** de contenedores distintos. 📊

- `BitcoinExchange` → `std::map` + búsqueda binaria.
- `RPN` → `std::stack`.
- `PmergeMe` → `std::vector` vs `std::deque` en el **ordenamiento por inserción-mergesort de Ford-Johnson**.

## 🎯 Objetivos

- 🗺️ Usar **`std::map`** con `lower_bound` para búsquedas O(log n).
- 📚 Aplicar **`std::stack`** (LIFO) a notación polaca inversa.
- ⚡ Comparar **rendimiento entre `std::vector` y `std::deque`** con el mismo algoritmo.
- ⏱️ Mostrar tiempos de ejecución por contenedor (chrono).

## 📄 Ejercicios

### ex00 — ₿ BitcoinExchange
Con el archivo `data.csv` (fecha → precio), dado un `input.txt` de la forma `date | value`, devuelve `date => value = precio * value`. Usa `std::map` y `lower_bound` para la fecha **más cercana anterior**. Valida fechas, valores y errores.

### ex01 — 🧮 RPN
Calculadora de **Notación Polaca Inversa**: `8 9 * 9 -` → evaluar con una pila `std::stack<int>`. Operaciones `+-*/`; errores con formato.

### ex02 — ⚡ PmergeMe
Ordena con **Ford-Johnson (merge-insertion sort)** implementado con `std::vector` y `std::deque` a la vez, imprimiendo los tiempos de cada contenedor y demostrando la diferencia práctica.

## 🏗️ Estructura

```
CPP_Module_09/
├── ex00/  → ./btc input.txt     # BitcoinExchange (+ data.csv)
├── ex01/  → ./RPN "8 9 * 9 -"   # calculadora RPN
├── ex02/  → ./PmergeMe 3 5 9 7 4
└── README.md
```

## 🛠️ Compilación

```bash
cd ex00 && make && ./btc input.txt
cd ../ex01 && make && ./RPN "8 9 * 9 -"
cd ../ex02 && make && ./PmergeMe 3 5 9 7 4
```

## 🚀 Uso y ejemplos

```bash
./btc input.txt
# 2011-01-03 => 3 = 0.9
# ...
# Error: not a valid date.

./RPN "8 9 * 9 -"
# 63

./PmergeMe 3 5 9 7 4
# Before: 3 5 9 7 4
# After: 3 4 5 7 9
# Time (vector): 123 us
# Time (deque): 145 us
```

## 🧪 Verificación

| Herramienta | Comandos |
|---|---|
| **Compilación C++98** | `cd exXX && make && c++ -std=c++98` |
| **Entradas erróneas** | `btc` con fechas inválidas/duplicadas, valores > 1000, líneas mal formadas |
| **RPN** | `"8 9 * 9 - 9 - 9 - 4 - 1"` → debe dar 42; operandos de más → error |
| **PmergeMe** | Con 3000 elementos debe ordenar y **no tardar**; comparar `vector` vs `deque` |
| **Duplicados** | PmergeMe debe mantener duplicados (Ford-Johnson es estable) |

💡 La nota del subject valora especialmente: parsing robusto en `btc`, exactitud en RPN y que PmergeMe **muestre tiempos coherentes** para comparar contenedores.

## 📚 Recursos

- [Índice C++](../README.md)
- [cppreference · std::map](https://en.cppreference.com/w/cpp/container/map)
- [cppreference · std::stack](https://en.cppreference.com/w/cpp/container/stack)
- [cppreference · std::deque](https://en.cppreference.com/w/cpp/container/deque)
- [Wikipedia · Merge-insertion sort (Ford-Johnson)](https://en.wikipedia.org/wiki/Merge-insertion_sort)