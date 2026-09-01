# 🎮 C Piscine · C 06 — Argumentos de línea de comandos

[![Piscina](https://img.shields.io/badge/🗓️_Piscina-42-1f6feb)](../../README.md)
[![Módulo](https://img.shields.io/badge/📦_C_06-argc_argv-2ea44f)](./)
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

Este módulo introduce los **argumentos de línea de comandos** (`argc` / `argv`): el momento en que los programas **reciben entrada del terminal**. ⌨️

Ya no hay pruebas con una sola llamada: ahora tienes **`./prog arg1 arg2 …`** y hay que acceder bien al array de strings.

## 🎯 Objetivos

- 🧮 Entender `argc` (número de argumentos) y `argv` (array de strings).
- 🖨️ Imprimir argumentos, en orden normal e inverso.
- 🔤 Ordenar strings **alfabéticamente** (comparando con `ft_strcmp` del C 03).

## 📄 Ejercicios

| # | Ejercicio | Enlace |
|---|---|---|
| ex00 | `ft_print_program_name` · imprime su propio nombre | [ver](./ex00/ft_print_program_name.c) |
| ex01 | `ft_print_params` · imprime los argumentos, uno por línea | [ver](./ex01/ft_print_params.c) |
| ex02 | `ft_rev_params` · argumentos en orden inverso | [ver](./ex02/ft_rev_params.c) |
| ex03 | `ft_sort_params` · argumentos ordenados alfabéticamente | [ver](./ex03/ft_sort_params.c) |

## 🧪 Verificación

| Herramienta | Comandos |
|---|---|
| **Moulinette + peers** | Corrección automática y entre compañeros |
| **norminette** | `norminette *.c` |
| **Compilación** | `cc -Wall -Wextra -Werror` |

💡 VIP:
- 🎯 **ex00**: imprime `argv[0]` **sin** la ruta `./` (solo el nombre). La catalogación con `./prog` imprime `prog`.
- 🖨️ **ex01/02/03**: se usa un **bucle `while (i < argc)`** a partir de `i = 1`; cada línea acaba en `\n` (`write` + newline, ¡sin `printf`!).
- 🔤 `ft_sort_params` usa **burbuja/inserción** con `ft_strcmp` y un **swap de punteros a char** (`char *tmp = argv[i]`).

## 📚 Recursos

- [Piscine 42 — Índice](../../README.md)
- [C argc/argv (tutorial)](https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/)
- [La Norma de 42](https://github.com/42Paris/norminette)