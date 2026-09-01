# 🎮 CPP Module 08 — Contenedores STL e iteradores

[![Nota](https://img.shields.io/badge/⭐_Nota-Aprobado-2ea44f)](./)
[![Módulo](https://img.shields.io/badge/📦_Módulo-08-1f6feb)](../)
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

¡Por fin se puede usar la **STL**! 🎉 Este módulo introduce **contenedores** (`std::vector`, `std::list`, `std::stack`) e **iteradores**, con tres ejercicios que los explotan: `easyfind`, `Span` y `MutantStack`.

## 🎯 Objetivos

- 📦 Usar contenedores de la STL con sus **iteradores**.
- 🔍 Templates de función que funcionan sobre **cualquier contenedor**.
- 📏 Cálculo de distancias mínicas/máximas entre N números (`Span`).
- 🔄 **Adaptar un contenedor** (`std::stack`) para exponer iteradores propios.

## 📄 Ejercicios

### ex00 — 🔍 easyfind
Template `easyfind<T>(T &container, int value)` que devuelve el **iterador** a la primera aparición o lanza una excepción si no existe. Funciona con `vector`, `list`…

### ex01 — 📏 Span
Clase `Span` que guarda hasta N enteros y calcula `shortestSpan()` y `longestSpan()` (|a-b| mínimo/máximo entre cualquier pareja).

### ex02 — 🌀 MutantStack
`std::stack` **subclasado** para exponer `begin()`/`end()` iteradores (los stacks normales no los tienen porque son LIFO).

## 🏗️ Estructura

```
CPP_Module_08/
├── ex00/  → ./easyfind
├── ex01/  → ./span
├── ex02/  → ./mutantstack
└── README.md
```

## 🛠️ Compilación

```bash
cd ex00 && make && ./easyfind
cd ../ex01 && make && ./span
cd ../ex02 && make && ./mutantstack
```

## 🚀 Uso y ejemplos

```bash
./easyfind
# Contenedor: 1 2 3 4 5 → easyfind(3) = encontrado en posición 2
# easyfind(99) → excepción capturada

./span
# span(5); addNumber(...); shortest = 1 ; longest = 12

./mutantstack
# 5 17 3 → iterador copia el contenido igual que std::stack
```

## 🧪 Verificación

| Herramienta | Comandos |
|---|---|
| **Compilación C++98** | `cd exXX && make && c++ -std=c++98` |
| **Excepciones** | `Span` sin suficientes números → excepción; ocupa demasiado → excepción |
| **MutantStack** | Debe imprimir igual que un `std::list` con los mismos datos (y no explotar con iteradores reverse) |
| **Contenedores** | `easyfind` probado con `std::vector<int>` y `std::list<int>` |

💡 `Span` puede añadir muchos números a la vez (`addRange`) para no llamar `addNumber` 10000 veces. La evaluación siempre pregunta por la excepción de "no hay suficiente números".

## 📚 Recursos

- [Índice C++](../README.md)
- [cppreference · Contenedores](https://en.cppreference.com/w/cpp/container)
- [cppreference · Iteradores](https://en.cppreference.com/w/cpp/iterator)