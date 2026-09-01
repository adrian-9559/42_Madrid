# 🎮 C Piscine · C 02 — Strings (cadenas de caracteres)

[![Piscina](https://img.shields.io/badge/🗓️_Piscina-42-1f6feb)](../../README.md)
[![Módulo](https://img.shields.io/badge/📦_C_02-Strings-2ea44f)](./)
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

Módulo dedicado a la **manipulación de cadenas**: copiar, comparar, transformar y analizar strings, así como trabajar con caracteres **no imprimibles**. 📝

Aquí las funciones clásicas de la libc (`strcpy`, `strncpy`, `strlcpy`, `strcapitalize`…) se reimplementan a mano, byte a byte.

## 🎯 Objetivos

- 📋 Copiar y clonar strings de forma segura.
- 🔠 Transformar mayúsculas/minúsculas y capitalizar palabras.
- ✅ Clasificar caracteres (alfabético, numérico, imprimible…).
- 🔣 Imprimir caracteres no imprimibles en hexadecimal.

## 📄 Ejercicios

| # | Ejercicio | Enlace |
|---|---|---|
| ex00 | `ft_strcpy` · copia una cadena | [ver](./ex00/ft_strcpy.c) |
| ex01 | `ft_strncpy` · copia hasta n | [ver](./ex01/ft_strncpy.c) |
| ex02 | `ft_str_is_alpha` · solo letras | [ver](./ex02/ft_str_is_alpha.c) |
| ex03 | `ft_str_is_numeric` · solo dígitos | [ver](./ex03/ft_str_is_numeric.c) |
| ex04 | `ft_str_is_lowercase` · solo minúsculas | [ver](./ex04/ft_str_is_lowercase.c) |
| ex05 | `ft_str_is_uppercase` · solo mayúsculas | [ver](./ex05/ft_str_is_uppercase.c) |
| ex06 | `ft_str_is_printable` · solo imprimibles | [ver](./ex06/ft_str_is_printable.c) |
| ex07 | `ft_strupcase` · a mayúsculas | [ver](./ex07/ft_strupcase.c) |
| ex08 | `ft_strlowcase` · a minúsculas | [ver](./ex08/ft_strlowcase.c) |
| ex09 | `ft_strcapitalize` · capitaliza palabras | [ver](./ex09/ft_strcapitalize.c) |
| ex10 | `ft_strlcpy` · copia segura con límite (devuelve longitud) | [ver](./ex10/ft_strlcpy.c) |
| ex11 | `ft_putstr_non_printable` · imprime no imprimibles en \xhh | [ver](./ex11/ft_putstr_non_printable.c) |

## 🧪 Verificación

| Herramienta | Comandos |
|---|---|
| **Moulinette + peers** | Corrección automática y entre compañeros |
| **norminette** | `norminette *.c` |
| **Compilación** | `cc -Wall -Wextra -Werror` |

💡 VIP:
- 🧹 `ft_strcapitalize` usa **índice bool** (el estándar de 42): una variable `i` que indica si la letra anterior era no-alfanumérica.
- 📏 `ft_strlcpy` debe **rellenar con `\0`**, truncar a `size-1` y **devolver la longitud total** de la fuente (¡incluso si trunca!).
- 💥 `ft_putstr_non_printable` → `\x` + dígitos hexadecimales en **minúsculas**; `\n` y `\t` son no imprimibles (van como `\x0a`, `\x09`…).

## 📚 Recursos

- [Piscine 42 — Índice](../../README.md)
- [C strings (tutorial)](https://www.geeksforgeeks.org/c-string-basics/)
- [La Norma de 42](https://github.com/42Paris/norminette)