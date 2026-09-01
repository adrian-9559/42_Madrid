# 🎮 Libft — Tu primera librería en C

[![Nota](https://img.shields.io/badge/⭐_Nota-100/100-2ea44f)](./)
[![Anillo](https://img.shields.io/badge/🔵_Anillo-1º_Círculo-1f6feb)](../)
[![Lenguaje](https://img.shields.io/badge/🛠️_C-98-orange)](./)

> 📚 **Documentación detallada por función** → [readmes_de_funciones](./readmes_de_funciones/README.md)

---

## 🧭 Índice

1. [🌟 Introducción](#-introducción)
2. [🎯 Objetivos](#-objetivos)
3. [📄 Enunciado](#-enunciado)
4. [🏗️ Estructura](#️-estructura)
5. [🛠️ Compilación](#️-compilación)
6. [🚀 Uso y ejemplos](#-uso-y-ejemplos)
7. [🧪 Testers y verificación](#-testers-y-verificación)
8. [✅ Nota](#-nota)
9. [📚 Recursos](#-recursos)

---

## 🌟 Introducción

El proyecto **Libft** es el punto de partida de todo el Cursus de 42. 🌱 Es una **reescritura de las funciones más útiles de la libc** más un conjunto de funciones propias organizadas en una librería estática.

Es tu primera "caja de herramientas": todos los proyectos posteriores (printf, GNL, pipex, minishell…) la reutilizan, así que la calidad de esta base importa muchísimo. 💎

## 🎯 Objetivos

- 📚 Dominar las funciones básicas de la **libc** reescribiéndolas desde cero.
- 🧠 Entender punteros, memoria, strings y su manejo seguro.
- 📦 Aprender a empaquetar código en una **librería estática** (`libft.a`).
- 🧹 Seguir **La Norma** (norminette) y la gestión de memoria sin leaks.

## 📄 Enunciado

Crea una librería `libft.a` con:

### Parte 1️⃣ — Funciones de `ctype`, `string` y `memory`
| Función | Propósito |
|---|---|
| `ft_isalpha` `ft_isdigit` `ft_isalnum` `ft_isascii` `ft_isprint` | Comprobaciones de caracteres |
| `ft_toupper` `ft_tolower` | Conversión de caja |
| `ft_strlen` | Longitud de strings |
| `ft_strchr` `ft_strrchr` | Búsqueda de caracteres |
| `ft_strncmp` `ft_strnstr` | Búsqueda y comparación |
| `ft_strlcpy` `ft_strlcat` | Copia/concatena con límite seguro |
| `ft_bzero` `ft_memset` `ft_memcpy` `ft_memmove` `ft_memchr` `ft_memcmp` | Operaciones de memoria |
| `ft_atoi` | Conversión string → int |
| `ft_calloc` `ft_strdup` | Asignación de memoria |

### Parte 2️⃣ — Funciones adicionales
| Función | Propósito |
|---|---|
| `ft_substr` | Subcadena de una cadena |
| `ft_strjoin` | Concatenación con asignación |
| `ft_strtrim` | Recorta caracteres de los extremos |
| `ft_split` | Divide una cadena con un separador |
| `ft_itoa` | Conversión int → string |
| `ft_strmapi` `ft_striteri` | Aplican funciones a caracteres |
| `ft_putchar_fd` `ft_putstr_fd` `ft_putendl_fd` `ft_putnbr_fd` | Salida a un file descriptor |

### 🎁 Bonus — Listas enlazadas
- `ft_lstnew` `ft_lstadd_front` `ft_lstadd_back` `ft_lstdelone` `ft_lstclear`
- `ft_lstiter` `ft_lstmap` `ft_lstsize` `ft_lstlast`

## 🏗️ Estructura

```
Libft/
├── Makefile                  # Reglas: all, bonus, clean, fclean, re
├── libft.h                   # Cabecera con todos los prototipos
├── ft_*.c                    # Implementación de la Parte 1 y 2
├── ft_lst*_bonus.c           # Implementación de los bonus
└── readmes_de_funciones/     # 📚 Doc detallada función por función
```

## 🛠️ Compilación

```bash
make          # Compila libft.a (parte obligatoria)
make bonus    # Añade las funciones de listas (ft_lst*_bonus.o)
make fclean   # Limpia objetos y la librería
```

⚠️ El Makefile usa `cc` con las flags `-Wall -Wextra -Werror` y **no hace relink**.

Para usarla en otro proyecto:

```bash
cc main.c libft.a -o programa
```

## 🚀 Uso y ejemplos

```c
#include "libft.h"

int main(void)
{
    char *s = ft_strjoin("Hola, ", "mundo!");
    ft_putstr_fd(s, 1);
    ft_putchar_fd('\n', 1);
    free(s);
    return (0);
}
```

## 🧪 Testers y verificación

| Herramienta | Instalación | Comandos |
|---|---|---|
| **libftTester** (Tripouille) | `git clone https://github.com/Tripouille/libftTester.git` | `cd libftTester && make` |
| **libft-unit-test** (alelievr) | `git clone https://github.com/alelievr/libft-unit-test.git` | `cd libft-unit-test && make f && ./run_test` |
| **Francinette** (paco) | `bash -c "$(curl -fsSL https://raw.github.com/xicodomingues/francinette/master/install.sh)"` | `paco` / `francinette` |
| **norminette** | `pip install norminette` (o vía 42) | `norminette *.c libft.h` |
| **valgrind** | parte del sistema | `valgrind ./programa` (comprueba leaks) |

💡 Consejo: pasa `libftTester` + `libft-unit-test` **antes** de cada evaluación y revisa con `valgrind` que no haya leaks.

## ✅ Nota

| Resultado | Detalle |
|---|---|
| ⭐ **100/100** | Perfecto, incluye bonus |

## 📚 Recursos

- [Subject oficial](https://cdn.intra.42.fr/pdf/pdf/61299/en.subject.pdf)
- [Cursus C — Índice](../README.md)
- [Cursus 42 — Índice](../../README.md)
- [Documentación por función](./readmes_de_funciones/README.md)
- [lzepeda · libft-unit-test](https://github.com/alelievr/libft-unit-test)