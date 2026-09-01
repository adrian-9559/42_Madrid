# 🎮 C Piscine · C 07 — Memoria dinámica (malloc)

[![Piscina](https://img.shields.io/badge/🗓️_Piscina-42-1f6feb)](../../README.md)
[![Módulo](https://img.shields.io/badge/📦_C_07-malloc-2ea44f)](./)
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

Este módulo introduce la **memoria dinámica** con `malloc`: reservar memoria en tiempo de ejecución para datos de tamaño variable. 💾

Es el primer (y crucial) contacto con `free`, el heap y la correcta gestión de la memoria que te perseguirá hasta la Libft. Aquí se suele abandonar a mucha gente… 😅

## 🎯 Objetivos

- 💾 Reservar y liberar memoria con `malloc` / `free`.
- 🔄 Duplicar cadenas (`ft_strdup`).
- ➗ Crear arrays de enteros con rangos (`ft_range`, `ft_ultimate_range`).
- ➕ Concatenar un array de cadenas con separador (`ft_strjoin`).

## 📄 Ejercicios

| # | Ejercicio | Enlace |
|---|---|---|
| ex00 | `ft_strdup` · duplica una cadena con malloc | [ver](./ex00/ft_strdup.c) |
| ex01 | `ft_range` · array con todos los valores entre dos límites | [ver](./ex01/ft_range.c) |
| ex02 | `ft_ultimate_range` · rango con puntero doble | [ver](./ex02/ft_ultimate_range.c) |
| ex03 | `ft_strjoin` · concatena array de cadenas con separador | [ver](./ex03/ft_strjoin.c) |

## 🧪 Verificación

| Herramienta | Comandos |
|---|---|
| **Moulinette + peers** | Corrección automática y entre compañeros |
| **norminette** | `norminette *.c` |
| **Compilación** | `cc -Wall -Wextra -Werror` |
| **memoria** | `valgrind ./a.out` → **0 leaks, 0 errores** es obligatorio para pasar bien |

💡 VIP:
- 💾 `ft_strdup` copia **incluyendo el `\0`** (`len + 1`).
- ➗ `ft_range(-5, 3)` devuelve `{-5,-4,-3,-2,-1,0,1,2}` (excluye `max`); si `min >= max` → `NULL`.
- 📦 `ft_ultimate_range` devuelve **1** si OK, **-1** si malloc falla, y escribe el array en el puntero doble.
- 🧵 `ft_strjoin` necesita **calcular la longitud total** antes de reservar (doble paso) para evitar `realloc`.

## 📚 Recursos

- [Piscine 42 — Índice](../../README.md)
- [malloc y gestión de memoria](https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/)
- [La Norma de 42](https://github.com/42Paris/norminette)