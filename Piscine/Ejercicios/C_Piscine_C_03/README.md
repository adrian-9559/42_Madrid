# 🎮 C Piscine · C 03 — Comparación y concatenación

[![Piscina](https://img.shields.io/badge/🗓️_Piscina-42-1f6feb)](../../README.md)
[![Módulo](https://img.shields.io/badge/📦_C_03-Strings-avanzado-2ea44f)](./)
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

Módulo centrado en **comparar y concatenar** cadenas de forma segura. Como las anteriores, son funciones de la libc reimplementadas a mano. 🔀

La estrella aquí es `ft_strlcat`, la función **más traicionera** de todo C… 😈

## 🎯 Objetivos

- ⚖️ Comparar cadenas y subcadenas (`strcmp`, `strncmp`).
- ➕ Concatenar de forma segura (`strcat`, `strncat`, `strlcat`).
- 🔍 Buscar una subcadena dentro de otra (`strstr`).

## 📄 Ejercicios

| # | Ejercicio | Enlace |
|---|---|---|
| ex00 | `ft_strcmp` · compare dos cadenas | [ver](./ex00/ft_strcmp.c) |
| ex01 | `ft_strncmp` · compare hasta n | [ver](./ex01/ft_strncmp.c) |
| ex02 | `ft_strcat` · concatena al final | [ver](./ex02/ft_strcat.c) |
| ex03 | `ft_strncat` · concatena hasta n | [ver](./ex03/ft_strncat.c) |
| ex04 | `ft_strstr` · busca subcadena | [ver](./ex04/ft_strstr.c) |
| ex05 | `ft_strlcat` · concatena con límite seguro | [ver](./ex05/ft_strlcat.c) |

## 🧪 Verificación

| Herramienta | Comandos |
|---|---|
| **Moulinette + peers** | Corrección automática y entre compañeros |
| **norminette** | `norminette *.c` |
| **Compilación** | `cc -Wall -Wextra -Werror` |

💡 VIP:
- 📏 `ft_strcmp` devuelve la **diferencia** de los primeros bytes distintos (comportamiento de libc, no solo 1/-1).
- 🔎 `ft_strstr` con **subcadena vacía** debe devolver la cadena original; si no existe → `NULL`.
- ⚠️ `ft_strlcat`: el valor devuelto es `len(dst) + len(src)` **antes** de truncar. Y el `\0` solo se escribe si `size > len(dst)`.

## 📚 Recursos

- [Piscine 42 — Índice](../../README.md)
- [man strlcat(3)](https://man7.org/linux/man-pages/man3/strlcat.3bsd.html)
- [La Norma de 42](https://github.com/42Paris/norminette)