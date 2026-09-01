# 🎮 C Piscine · C 08 — Headers y macros

[![Piscina](https://img.shields.io/badge/🗓️_Piscina-42-1f6feb)](../../README.md)
[![Módulo](https://img.shields.io/badge/📦_C_08-Preprocesador-2ea44f)](./)
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

Módulo de **archivos de cabecera** y **macros** (`#define`): cómo organizar prototipos, definir constantes y escribir código con el **preprocesador**. 🧩

Es la base de los `.h` que usarás en todo el Cursus (los `ft_*.h` de cada proyecto).

## 🎯 Objetivos

- 📁 Crear headers con **prototipos** e include guards.
- 🔤 Definir **macros con parámetros** (`ABS`, `EVEN`).
- 💡 Escribir un tipo booleano propio (`TRUE`/`FALSE`/`t_bool`).

## 📄 Ejercicios

| # | Ejercicio | Enlace |
|---|---|---|
| ex00 | `ft.h` · prototipos de funciones básicas | [ver](./ex00/ft.h) |
| ex01 | `ft_boolean.h` · tipo booleano con TRUE/FALSE | [ver](./ex01/ft_boolean.h) |
| ex02 | `ft_abs.h` · macro de valor absoluto | [ver](./ex02/ft_abs.h) |

## 🧪 Verificación

| Herramienta | Comandos |
|---|---|
| **Moulinette + peers** | Corrección automática y entre compañeros |
| **norminette** | `norminette *.c *.h` |
| **Compilación** | `cc -Wall -Wextra -Werror` con un `.c` que incluya el header |

💡 VIP:
- 🧪 `ft_boolean.h` define `#define TRUE 1`, `#define FALSE 0`, `#define EVEN(nbr) (nbr % 2 == 0)` y `typedef int t_bool;`, y un `#define EVEN_MSG` / `#define ODD_MSG`.
- ✖️ `ft_abs.h` → `#define ABS(Value) (Value < 0 ? -Value : Value)` — el evaluador prueba `ABS(-5)` y `ABS(5)`.
- 🧬 Los headers deben servir **solo con `#include` directo** (los prototipos apuntan a funciones ya definidas en otro `.c`).

## 📚 Recursos

- [Piscine 42 — Índice](../../README.md)
- [Preprocesador y macros en C](https://www.geeksforgeeks.org/cc-preprocessors/)
- [La Norma de 42](https://github.com/42Paris/norminette)