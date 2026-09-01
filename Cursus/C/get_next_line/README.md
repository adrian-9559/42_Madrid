# 🎮 get_next_line — Lectura de una línea por llamada

[![Nota](https://img.shields.io/badge/⭐_Nota-125/125-2ea44f)](./)
[![Anillo](https://img.shields.io/badge/🔵_Anillo-2º_Círculo-1f6feb)](../)
[![Lenguaje](https://img.shields.io/badge/🛠️_C-98-orange)](./)

---

## 🧭 Índice

1. [🌟 Introducción](#-introducción)
2. [🎯 Objetivos](#-objetivos)
3. [📄 Enunciado](#-enunciado)
4. [🧠 Conceptos clave](#-conceptos-clave)
5. [🏗️ Estructura](#️-estructura)
6. [🚀 Uso y ejemplos](#-uso-y-ejemplos)
7. [🧪 Testers y verificación](#-testers-y-verificación)
8. [🎁 Bonus](#-bonus)
9. [✅ Nota](#-nota)
10. [📚 Recursos](#-recursos)

---

## 🌟 Introducción

**get_next_line** (GNL) devuelve una línea leída de un file descriptor en cada llamada. 📖 Parece sencillo, pero esconde uno de los retos más delicados del Cursus: gestionar una **variable estática** que sobreviva entre llamadas y lidiar con las **lecturas parciales** de `read()`.

Aquí no vas a "uso printf con un while": aquí aprendes a pensar en **estados persistentes** y en **memoria exacta** (ni un byte de más, ni un byte de menos).

## 🎯 Objetivos

- 🗂️ Dominar **file descriptors** y la función `read()`.
- 🔁 Manejar el **buffer dinámico** sin depender del tamaño de `BUFFER_SIZE`.
- 🧠 Usar **variables estáticas** para mantener estado entre llamadas.
- 🧹 Gestionar memoria de forma quirúrgica: free de `tmp`, `stash`, `line`…
- 📚 Reutilizar funciones de tu **Libft** (`ft_strjoin`, `ft_strchr`, `ft_strlen`…).

## 📄 Enunciado

Escribe una función:

```c
char *get_next_line(int fd);
```

- 📥 Lee del file descriptor `fd` una **línea completa** por cada llamada.
- 📏 Respeta **cualquier `BUFFER_SIZE`** compilado (1024, 9999, 1…).
- 🔚 Devuelve la línea incluyendo el **`\n`** salvo que el final sea EOF sin salto.
- 🪁 Devuelve `NULL` cuando se alcanza el final del archivo o hay error.
- ⚠️ La llamada a `read()` nunca debe exceder `BUFFER_SIZE` bytes **por llamada**.

## 🧠 Conceptos clave

- **Variable estática**: conserva el contenido no leído (`stash`) entre invocaciones. Cada fd necesita su propio stash en el bonus.
- **Double join**: técnica clásica para añadir el fragmento leído al stash sin perder memoria:
  ```c
  char *new_stash = ft_strjoin(stash, buf);
  free(stash);
  stash = new_stash;
  ```
- **Caso borde**: buffer con múltiples `\n` → la línea termina en el primero y el resto se guarda para la siguiente llamada.

## 🏗️ Estructura

```
get_next_line/
├── Makefile                # all, clean, fclean, re
├── get_next_line.h         # Prototipos + BUFFER_SIZE
├── get_next_line.c         # get_next_line() y lectura en bucle
├── get_next_line_utils.c   # Funciones auxiliares
├── get_next_line_bonus.h   # Bonus: múltiples fd
├── get_next_line_bonus.c
└── get_next_line_utils_bonus.c
```

## 🚀 Uso y ejemplos

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd = open("mapa.txt", O_RDONLY);
    char    *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

Compilación (definiendo `BUFFER_SIZE`):

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o gnl
```

## 🧪 Testers y verificación

| Herramienta | Instalación | Comandos |
|---|---|---|
| **gnlTester** (Tripouille) | `git clone https://github.com/Tripouille/gnlTester.git` | `cd gnlTester && make` |
| **Francinette** (paco) | `bash -c "$(curl -fsSL https://raw.github.com/xicodomingues/francinette/master/install.sh)"` | `paco get_next_line` |
| **norminette** | `pip install norminette` | `norminette *.c *.h` |
| **valgrind** | parte del sistema | `valgrind --leak-check=full ./gnl` |

💡 Truco (de la doc de gnlTester): algunas pruebas tardan en finalizar con `BUFFER_SIZE` pequeños. Si salta por timeout, compila definiendo un valor mayor:

```bash
make BUFFER_SIZE=9999
```

> ℹ️ También incluido como librería reutilizable dentro de `so_long` → [doc GNL en so_long_linux](../so_long/so_long_linux/lib/get_next_line/README.md).

## 🎁 Bonus

- Gestión de **múltiples file descriptors**: la función debe recordar la lectura de cada fd **por separado** (arriba/abajo/intermedio) y devolver la línea correcta sin mezclas.

## ✅ Nota

| Resultado | Detalle |
|---|---|
| ⭐ **125/125** | Perfecto, incluye bonus de múltiples fd |

## 📚 Recursos

- [Subject oficial](https://cdn.intra.42.fr/pdf/pdf/65392/en.subject.pdf)
- [Cursus C — Índice](../README.md)
- [Tripouille · gnlTester](https://github.com/Tripouille/gnlTester)
- [Implementación GNL dentro de so_long](../so_long/so_long_linux/lib/get_next_line/README.md)