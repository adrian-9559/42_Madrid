# 🎮 C Piscine · C 01 — Punteros y arrays

[![Piscina](https://img.shields.io/badge/🗓️_Piscina-42-1f6feb)](../../README.md)
[![Módulo](https://img.shields.io/badge/📦_C_01-Punteros-2ea44f)](./)
[![Lenguaje](https://img.shields.io/badge/🛠️_C-98-orange)](./)

---

## 🧭 Índice

1. [🌟 Introducción](#-introducción)
2. [🎯 Objetivos](#-objetivos)
3. [📄 Ejercicios](#-ejercicios)
4. [🧪 Verificación](#-verificación)
5. [📚 Recursos](#-recursos)

---

## 🌟 Introducción

Este módulo trabaja **punteros y arrays**: direcciones de memoria, paso de parámetros por referencia y operaciones sobre arrays de enteros. 🧠

Es el momento en que "la caja con un valor" deja de ser suficiente: ahora el código **guarda direcciones** (`&`) y **desreferencia** (`*`).

## 🎯 Objetivos

- 🎯 Entender `&` (dirección) y `*` (desreferencia).
- 🔗 Pasar **por referencia** para modificar el original.
- 🧮 Operar sobre **arrays de ints** (invertir, ordenar).
- 🔟 Manejar punteros a punteros (`ft_ultimate_ft`).

## 📄 Ejercicios

| # | Ejercicio | Enlace |
|---|---|---|
| ex00 | `ft_ft` · asigna 42 a un `int*` | [ver](./ex00/ft_ft.c) |
| ex01 | `ft_ultimate_ft` · asigna 42 a un `int*******` | [ver](./ex01/ft_ultimate_ft.c) |
| ex02 | `ft_swap` · intercambia dos enteros | [ver](./ex02/ft_swap.c) |
| ex03 | `ft_div_mod` · cociente y resto por punteros | [ver](./ex03/ft_div_mod.c) |
| ex04 | `ft_ultimate_div_mod` · reemplaza con div y mod | [ver](./ex04/ft_ultimate_div_mod.c) |
| ex05 | `ft_putstr` · imprime una cadena | [ver](./ex05/ft_putstr.c) |
| ex06 | `ft_strlen` · longitud de una cadena | [ver](./ex06/ft_strlen.c) |
| ex07 | `ft_rev_int_tab` · invierte un array de ints | [ver](./ex07/ft_rev_int_tab.c) |
| ex08 | `ft_sort_int_tab` · ordena ascendente | [ver](./ex08/ft_sort_int_tab.c) |

## 🧪 Verificación

| Herramienta | Comandos |
|---|---|
| **Moulinette + peers** | Corrección automática y entre compañeros |
| **norminette** | `norminette *.c` |
| **Compilación** | `cc -Wall -Wextra -Werror` + `main` de prueba |

💡 Puntos clave:
- ➗ `ft_div_mod` usa la **aritmética entera con punteros** (el resultado debe quedar en *div* y *mod*).
- 🔄 `ft_rev_int_tab` se prueba con arrays de **longitud par e impar** (y de tamaño 1).
- 📶 Los `main` de prueba suelen pasar arrays por referencia y comprobar que el **array original cambió**.

## 📚 Recursos

- [Piscine 42 — Índice](../../README.md)
- [C punteros (tutorial)](https://www.geeksforgeeks.org/c-pointer-basics/)
- [La Norma de 42](https://github.com/42Paris/norminette)