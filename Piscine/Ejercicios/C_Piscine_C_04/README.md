# 🎮 C Piscine · C 04 — Atoi y bases numéricas

[![Piscina](https://img.shields.io/badge/🗓️_Piscina-42-1f6feb)](../../README.md)
[![Módulo](https://img.shields.io/badge/📦_C_04-Parseo-2ea44f)](./)
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

Este módulo introduce **parseo** y **bases numéricas**: convertir cadenas a enteros, imprimir con bases arbitrarias (binario, hex…) y gestionar entradas del usuario. 🔢

Es la antesala de `ft_atoi_base`/`ft_putnbr_base`, funciones que verás de nuevo en `ft_printf` y la Libft.

## 🎯 Objetivos

- ✅ Convertir string → int (`ft_atoi`) ignorando espacios y signos.
- 🔢 Imprimir/converter en **cualquier base** (`ft_putnbr_base`, `ft_atoi_base`).
- 🧮 Reimplementar `strlen`, `putstr`, `putnbr` desde cero (otra vez, ahora más fino).

## 📄 Ejercicios

| # | Ejercicio | Enlace |
|---|---|---|
| ex00 | `ft_strlen` · longitud de cadena | [ver](./ex00/ft_strlen.c) |
| ex01 | `ft_putstr` · imprime cadena | [ver](./ex01/ft_putstr.c) |
| ex02 | `ft_putnbr` · imprime entero | [ver](./ex02/ft_putnbr.c) |
| ex03 | `ft_atoi` · string → entero | [ver](./ex03/ft_atoi.c) |
| ex04 | `ft_putnbr_base` · imprime en la base dada | [ver](./ex04/ft_putnbr_base.c) |
| ex05 | `ft_atoi_base` · string en base dada → entero | [ver](./ex05/ft_atoi_base.c) |

## 🧪 Verificación

| Herramienta | Comandos |
|---|---|
| **Moulinette + peers** | Corrección automática y entre compañeros |
| **norminette** | `norminette *.c` |
| **Compilación** | `cc -Wall -Wextra -Werror` |

💡 VIP:
- ⌨️ `ft_atoi` debe gestionar **`\t\n\v\f\r `** como espacios en blanco y el signo `-`.
- 🔢 `ft_putnbr_base`/`ft_atoi_base` deben devolver/**no hacer nada** si la base no es válida (menos de 2 caracteres, **duplicados** o contienen `+`/`-`).
- 🎯 `ft_putnbr` con `INT_MIN` → el caso que rompe el algoritmo si haces `n = -n`.

## 📚 Recursos

- [Piscine 42 — Índice](../../README.md)
- [Problema INT_MIN (desbordamiento)](https://www.geeksforgeeks.org/why-negative-numbers-uint-min/)
- [La Norma de 42](https://github.com/42Paris/norminette)