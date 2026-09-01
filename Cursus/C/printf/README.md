# 🎮 ft_printf — Réplica de printf

[![Nota](https://img.shields.io/badge/⭐_Nota-110/125-2ea44f)](./)
[![Anillo](https://img.shields.io/badge/🔵_Anillo-2º_Círculo-1f6feb)](../)
[![Lenguaje](https://img.shields.io/badge/🛠️_C-98-orange)](./)

---

## 🧭 Índice

1. [🌟 Introducción](#-introducción)
2. [🎯 Objetivos](#-objetivos)
3. [📄 Enunciado](#-enunciado)
4. [🏗️ Estructura](#️-estructura)
5. [🛠️ Compilación](#️-compilación)
6. [🚀 Uso y ejemplos](#-uso-y-ejemplos)
7. [🧪 Testers y verificación](#-testers-y-verificación)
8. [🎁 Bonus](#-bonus)
9. [✅ Nota](#-nota)
10. [📚 Recursos](#-recursos)

---

## 🌟 Introducción

**ft_printf** replica el comportamiento de la función `printf` de la libc. ✍️ Es tu primer encuentro con **funciones variádicas** (`va_list`): aprenderás a procesar un número variable de argumentos, formatear su salida y gestionar cada especificador a mano.

Es también el primer proyecto donde se suele **reutilizar tu propia Libft** 📦, marcando la pauta de todo el Cursus.

## 🎯 Objetivos

- 🔧 Entender el **stack de argumentos variádicos** (`va_start`, `va_arg`, `va_end`).
- 🧩 Implementar conversiones de tipos con formato (`%d`, `%x`, `%p`…).
- 🧱 Crear una arquitectura de código modular (una función por conversión).
- 🐛 Aprender a depurar comparando con `printf` original.

## 📄 Enunciado

Escribe una función `ft_printf` que imite `printf` con las siguientes conversiones:

| Conversión | Descripción |
|---|---|
| `%c` | Imprime un carácter |
| `%s` | Imprime una cadena (string) |
| `%p` | Imprime un puntero en hexadecimal (`0x…`) |
| `%d` / `%i` | Imprime un entero en base 10 |
| `%u` | Imprime un entero sin signo en base 10 |
| `%x` | Imprime un entero en hexadecimal (minúsculas) |
| `%X` | Imprime un entero en hexadecimal (mayúsculas) |
| `%%` | Imprime el símbolo `%` |

Comportamiento exigido:
- 🚫 No debe usar `printf` en la parte obligatoria.
- 📏 Debe devolver el **número de caracteres impresos** (igual que la original).
- 🔄 Debe gestionar el ancho, precisión y flags si se implementa el bonus.

## 🏗️ Estructura

```
printf/
├── Makefile                  # Reglas: all, bonus, clean, fclean, re
├── ft_printf.h               # Prototipos y struct de flags
├── ft_printf.c               # Lógica principal y parseo
├── ft_printf_utils.c         # Funciones auxiliares
└── ft_print_*.c              # Una función por conversión
```

## 🛠️ Compilación

```bash
make          # Compila libftprintf.a
make bonus    # Añade las conversiones del bonus
make fclean   # Limpia objetos y librería
```

⚠️ El Makefile usa `cc` con `-Wall -Wextra -Werror` y no hace relink.

Para enlazarla con tu programa:

```bash
cc main.c libftprintf.a -o programa
```

## 🚀 Uso y ejemplos

```c
#include "ft_printf.h"

int main(void)
{
    int n = 42;

    ft_printf("Hola %s, tienes %d años y vives en %p\n",
              "Adrián", n, &n);
    ft_printf("Hex: %x | Hex mayúscula: %X | %%\n", 255, 255);
    return (0);
}
```

Salida:

```
Hola Adrián, tienes 42 años y vives en 0x7ffc...
Hex: ff | Hex mayúscula: FF | %
```

## 🧪 Testers y verificación

| Herramienta | Instalación | Comandos |
|---|---|---|
| **printfTester** (Tripouille) | `git clone https://github.com/Tripouille/printfTester.git` | `cd printfTester && make` |
| **ft_printf_tester** (cacharle) | `git clone https://github.com/cacharle/ft_printf_tester.git` | `cd ft_printf_tester && make` |
| **Francinette** (paco) | `bash -c "$(curl -fsSL https://raw.github.com/xicodomingues/francinette/master/install.sh)"` | `paco ft_printf` |
| **norminette** | `pip install norminette` | `norminette *.c *.h` |

💡 Consejo: estos testers comparan tu salida y tu **valor de retorno** contra el `printf` real en cientos de casos borde, incluidos `INT_MIN`, punteros `NULL` y caracteres no imprimibles.

## 🎁 Bonus

- Gestión de **ancho** (`%10d`) y **precisión** (`%.2f`, `%.5s`).
- **Flags** de alineación y relleno: `-`, `0`, `.`, `#`, `+`, espacio.

Estas banderas cambian por completo el parseo: el `printf` real usa un struct de flags que se rellena según el orden de parseo.

## ✅ Nota

| Resultado | Detalle |
|---|---|
| ⭐ **110/125** | Bonificación conseguida: flags + ancho/precisión |

## 📚 Recursos

- [Subject oficial](https://cdn.intra.42.fr/pdf/pdf/64372/en.subject.pdf)
- [Cursus C — Índice](../README.md)
- [cacharle · ft_printf_tester](https://github.com/cacharle/ft_printf_tester)
- [Tripouille · printfTester](https://github.com/Tripouille/printfTester)