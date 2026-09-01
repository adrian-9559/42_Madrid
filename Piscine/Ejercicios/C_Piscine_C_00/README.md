# 🎮 C Piscine · C 00 — Fundamentos de C

[![Piscina](https://img.shields.io/badge/🗓️_Piscina-42-1f6feb)](../../README.md)
[![Módulo](https://img.shields.io/badge/📦_C_00-Primera_semana-1f6feb)](./)
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

Primer contacto con el lenguaje C. 📗 Este módulo trabaja los **fundamentos**: variables, tipos de datos, bucles, la función `write` y la salida estándar.

Es el "¡hola, mundo!" oficial de la piscina: a partir de aquí, **La Norma** y `cc -Wall -Wextra -Werror` te van a acompañar todo el día. 🛡️

## 🎯 Objetivos

- 🖨️ Usar `write()` para imprimir a stdout.
- 🔁 Dominar bucles (`while`) e iteración de caracteres.
- 🧠 Entender `char` como tipo numérico (`'a' + 1 = 'b'`).
- ✍️ Respetar **La Norma** desde el primer ejercicio.

## 📄 Ejercicios

| # | Ejercicio | Enlace |
|---|---|---|
| ex00 | `ft_putchar` · imprime un carácter | [ver](./ex00/README.md) |
| ex01 | `ft_print_alphabet` · alfabeto en minúsculas | [ver](./ex01/README.md) |
| ex02 | `ft_print_reverse_alphabet` · alfabeto inverso | [ver](./ex02/README.md) |
| ex03 | `ft_print_numbers` · dígitos del 0 al 9 | [ver](./ex03/README.md) |
| ex04 | `ft_is_negative` · ¿negativo? (N/P) | [ver](./ex04/README.md) |
| ex05 | `ft_print_comb` · combinaciones de 3 dígitos | [ver](./ex05/README.md) |
| ex06 | `ft_print_comb2` · combinaciones de 2 números de 2 dígitos | [ver](./ex06/README.md) |
| ex07 | `ft_putnbr` · imprime cualquier entero | [ver](./ex07/README.md) |

📄 Enunciado en español: [es.subject.pdf](./es.subject.pdf)

## 🧪 Verificación

| Herramienta | Comandos |
|---|---|
| **Moulinette + peers** | Corrección automática y entre compañeros |
| **norminette** | `norminette *.c` → 0 errores o nota 0 |
| **Compilación** | `cc -Wall -Wextra -Werror` con un `main` de prueba |

💡 VIP: como los ejercicios son **funciones**, en el `main` de prueba se comparan bytes exactos: `ft_print_numbers` debe imprimir exactamente `0123456789`. Y `ft_putnbr(-2147483648)` es el caso borde clásico.

## 📚 Recursos

- [Piscine 42 — Índice](../../README.md)
- [man write(2)](https://man7.org/linux/man-pages/man2/write.2.html)
- [La Norma de 42](https://github.com/42Paris/norminette)