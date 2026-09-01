# 🎮 push_swap — Algoritmo de ordenación con dos stacks

[![Nota](https://img.shields.io/badge/⭐_Nota-98/125-2ea44f)](./)
[![Anillo](https://img.shields.io/badge/🔵_Anillo-3º_Círculo-1f6feb)](../)
[![Lenguaje](https://img.shields.io/badge/🛠️_C-98-orange)](./)

---

## 🧭 Índice

1. [🌟 Introducción](#-introducción)
2. [🎯 Objetivos](#-objetivos)
3. [📄 Enunciado](#-enunciado)
4. [🎮 Operaciones disponibles](#-operaciones-disponibles)
5. [🏗️ Estructura](#️-estructura)
6. [🛠️ Compilación](#️-compilación)
7. [🚀 Uso y ejemplos](#-uso-y-ejemplos)
8. [🧪 Testers y verificación](#-testers-y-verificación)
9. [✅ Nota](#-nota)
10. [📚 Recursos](#-recursos)

---

## 🌟 Introducción

**push_swap** es un proyecto de **algoritmo y optimización**: tienes dos stacks (`a` y `b`) y un conjunto fijo de operaciones; debes ordenar los números con el **mínimo número de movimientos posible**. 🧠

No es solo "ordenar": es diseñar estrategias (turkey sort, radix, costo-beneficio) y afinar constantes para que el corrector no falle. Es de los proyectos que más **pensamiento previo** exigen de todo el Cursus.

## 🎯 Objetivos

- 🧮 Elegir y justificar un **algoritmo** eficiente para N elementos.
- 🔁 Reducir al máximo el número de **operaciones**.
- 🧱 Trabajar con una **lista simplemente enlazada** como estructura de datos.
- ✅ Validar la entrada con parseo estricto (dup, límites de `int`…).
- 🧊 Mantener invariantes: una operación = una rotación mínima de datos.

## 📄 Enunciado

Crea dos programas:

- **`push_swap`**: recibe los números como argumentos y escribe en stdout la **lista de operaciones** que los ordena.
- **`checker`** (bonus → `checker_Mac` / `checker_linux`): lee la lista de operaciones de stdin y verifica si de verdad ordenan.

Límites recomendados del subject:

| Nº elementos | Movs. objetivo |
|---|---|
| 3 | ≤ 3 |
| 5 | ≤ 12 |
| 100 | ≤ 700 |
| 500 | ≤ 5500 |

## 🎮 Operaciones disponibles

| Opción | Efecto |
|---|---|
| `sa` `sb` `ss` | Intercambia los dos primeros elementos de `a`/`b`/ambos |
| `pa` `pb` | Push: mueve el primer elemento de `a`→`b` o `b`→`a` |
| `ra` `rb` `rr` | Rotar (sube) el stack |
| `rra` `rrb` `rrr` | Rotar hacia abajo |

## 🏗️ Estructura

```
push_swap/
├── Makefile                # Reglas: all, bonus, clean, fclean, re
├── push_swap.h             # Prototipos y struct t_stack
├── main.c                  # main de push_swap
├── push_swap.c             # Lógica principal del algoritmo
├── sort_functions.c        # Estrategia de ordenación
├── push_swap_utils.c       # Utilidades (parseo, validación)
├── ft_stack.c / ft_stack_utils.c   # Lista enlazada
├── ft_checker.c            # main del checker
├── ft_checker_stack.c      # Lectura a aplicar las operaciones
└── lib/                    # 🧪 Testers y utilidades externas
    ├── checker_Mac / checker_linux   # Binarios oficiales de 42
    └── lib_operations/
```

## 🛠️ Compilación

```bash
make          # Compila push_swap
make bonus    # Compila también el checker (./checker)
make fclean   # Limpia el proyecto
```

## 🚀 Uso y ejemplos

```bash
# Ordenar un conjunto pequeño
./push_swap 3 2 1 0
# Salida: una lista de operaciones (ra, pb, sa...)

# Contar las operaciones con el checker
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l

# Verificar con el checker oficial
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker_Mac $ARG
# → "OK"

# Generar args aleatorios y medir
ARG=$(jot -r 100 0 1000 | tr '\n' ' ')
./push_swap $ARG | ./checker_Mac $ARG
./push_swap $ARG | wc -l            # debe ser ≤ 700
```

## 🧪 Testers y verificación

| Herramienta | Instalación | Comandos |
|---|---|---|
| **checker oficial** | traer `checker_Mac` (macOS) o `checker_linux` de la intra de 42 | `./push_swap $ARG \| ./checker_Mac $ARG` |
| **push_swap_visualizer** (o-reo) | `git clone https://github.com/o-reo/push_swap_visualizer.git` | `cmake . && make && ./bin/visualizer` |
| **norminette** | `pip install norminette` | `norminette *.c *.h` |

💡 Medir rendimiento (objetivos):

```bash
for i in $(seq 1 10); do
  ARG=$(jot -r 500 0 1000 | tr '\n' ' ')
  ./push_swap $ARG | wc -l
done   # objetivo: promedio ≤ 5500 en 500 elementos
```

🛠️ Extras que uso a menudo:
- **Valgrand**: `valgrind ./push_swap 5 1 4 2 3` → sin leaks.
- **Edge cases**: `./push_swap ""`, `./push_swap 1 2 2` (error), `./push_swap 2147483648` (fuera de rango), argumentos con espacios.

## ✅ Nota

| Resultado | Detalle |
|---|---|
| ⭐ **98/125** | 100 elementos ≈ 700 movs · 500 elementos ≈ 5500 movs |

## 📚 Recursos

- [Subject oficial](https://cdn.intra.42.fr/pdf/pdf/60267/fr.subject.pdf)
- [Cursus C — Índice](../README.md)
- [o-reo · push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer)
- [Visualizador interactivo (push_swap_visualizer)](https://github.com/o-reo/push_swap_visualizer)