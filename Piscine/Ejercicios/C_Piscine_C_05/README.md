# 🎮 C Piscine · C 05 — Matemáticas y recursividad

[![Piscina](https://img.shields.io/badge/🗓️_Piscina-42-1f6feb)](../../README.md)
[![Módulo](https://img.shields.io/badge/📦_C_05-Recursividad-2ea44f)](./)
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

Módulo de **matemáticas y recursividad**: factorials, potencias, **Fibonacci**, raíces cuadradas enteras y números primos. 🧮

Aquí se entrena el **pensamiento algorítmico**: traducir una fórmula matemática a código, tanto **iterativo** como **recursivo**.

## 🎯 Objetivos

- 🔁 Implementar lo mismo de forma **iterativa y recursiva** (factorial, potencias).
- 🔢 Series y sucesiones (Fibonacci).
- √ Raíz cuadrada **entera** sin float.
- 🧬 Comprobar/detectar números primos (divisibilidad).

## 📄 Ejercicios

| # | Ejercicio | Enlace |
|---|---|---|
| ex00 | `ft_iterative_factorial` | [ver](./ex00/ft_iterative_factorial.c) |
| ex01 | `ft_recursive_factorial` | [ver](./ex01/ft_recursive_factorial.c) |
| ex02 | `ft_iterative_power` | [ver](./ex02/ft_iterative_power.c) |
| ex03 | `ft_recursive_power` | [ver](./ex03/ft_recursive_power.c) |
| ex04 | `ft_fibonacci` · n-ésimo núm. Fibonacci | [ver](./ex04/ft_fibonacci.c) |
| ex05 | `ft_sqrt` · raíz entera | [ver](./ex05/ft_sqrt.c) |
| ex06 | `ft_is_prime` · ¿primo? | [ver](./ex06/ft_is_prime.c) |
| ex07 | `ft_find_next_prime` · siguiente primo | [ver](./ex07/ft_find_next_prime.c) |

## 🧪 Verificación

| Herramienta | Comandos |
|---|---|
| **Moulinette + peers** | Corrección automática y entre compañeros |
| **norminette** | `norminette *.c` |
| **Compilación** | `cc -Wall -Wextra -Werror` |

💡 VIP:
- ❌ Valores de retorno en casos inválidos: factorial/potencia de **negativos → 0**; `ft_fibonacci(0) = 0`, `fib(1) = 1`, **negativo → -1**; `ft_sqrt` de no cuadrado perfecto → **0**.
- 🧠 `ft_find_next_prime` llama a `ft_is_prime` en bucle; en `INT_MAX` no hay siguiente primo → cuidado en evaluación con rangos grandes (usa `unsigned`/`long` internamente).

## 📚 Recursos

- [Piscine 42 — Índice](../../README.md)
- [Sucesión de Fibonacci (Wikipedia)](https://es.wikipedia.org/wiki/Sucesi%C3%B3n_de_Fibonacci)
- [La Norma de 42](https://github.com/42Paris/norminette)