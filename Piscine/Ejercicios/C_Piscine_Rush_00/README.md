# 🎮 C Piscine · Rush 00 — Rectángulos en ASCII

[![Piscina](https://img.shields.io/badge/🗓️_Piscina-42-1f6feb)](../../README.md)
[![Módulo](https://img.shields.io/badge/📦_Rush_00-Grupal-2ea44f)](./)
[![Lenguaje](https://img.shields.io/badge/🛠️_C-98-orange)](./)

---

## 🧭 Índice

1. [🌟 Introducción](#-introducción)
2. [🎯 Objetivos](#-objetivos)
3. [📄 Enunciado](#-enunciado)
4. [🏗️ Estructura](#️-estructura)
5. [🛠️ Compilación](#️-compilación)
6. [🚀 Uso](#-uso)
7. [🧪 Verificación](#-verificación)
8. [📚 Recursos](#-recursos)

---

## 🌟 Introducción

Primer **Rush** de la piscina y primer **trabajo en equipo**. 👥 Se trata de imprimir **rectángulos** en la consola con caracteres ASCII, con esquinas, bordes y rellenos distintos según el `rush` (00–04).

Es un ejercicio de **bucles anidados** y **casos especiales** (dimensiones 1×1, 1×N, N×1).

## 🎯 Objetivos

- 🔁 Dominar **bucles anidados** (`for`/`while`) para pintar filas y columnas.
- 🧠 Manejar los **casos esquina/lateral** con condicionales.
- 🤝 Trabajar en **pareja/trío** y resolver un solo enunciado entre varios.
- ✍️ Respetar la Norma y el porte (`write`).

## 📄 Enunciado

| Carácter | Esquina sup. izq. | Esquina sup. der. | Esq. inf. izq. | Esq. inf. der. | Lado horiz. | Lado vert. | Relleno |
|---|---|---|---|---|---|---|---|
| `rush00` | `o` | `o` | `o` | `o` | `-` | `|` | espacio |
| `rush01` | `/` | `\` | `\` | `/` | `*` | `*` | espacio |
| `rush02` | `A` | `A` | `C` | `C` | `B` | `B` | espacio |
| `rush03` | `A` | `C` | `A` | `C` | `B` | `B` | espacio |
| `rush04` | `A` | `C` | `C` | `A` | `B` | `B` | espacio |

## 🏗️ Estructura

```
C_Piscine_Rush_00/
├── ex00/   # rush00 – rush04 con todos los archivos
├── ex01/   # rush01 individual con su propio main
├── ex02/   # rush02 individual con su propio main
├── ex03/   # rush03 individual con su propio main
└── ex04/   # rush04 individual con su propio main
```

## 🛠️ Compilación

```bash
cd ex00
cc -Wall -Wextra -Werror -o rush00 *.c
```

## 🚀 Uso

```bash
./rush00 5 3
# o----o
# |    |
# o----o

./rush01 1 1
# /
```

## 🧪 Verificación

| Herramienta | Criterio |
|---|---|
| **Moulinette** | Compila con `-Wall -Wextra -Werror` y compara el dibujo exacto |
| **Casos borde** | `1x1`, `1xN`, `Nx1`, `5x3`, dimensiones negativas/0 |
| **norminette** | `norminette *.c` — un ejercicio con fallo de norma cae entero |
| **Entrega** | En un rush se puntúa **el trabajo del equipo**: nadie sabe quién hizo qué |

💡 Consejos: pinta siempre **columna por columna** con el carácter de esquina/lateral según coincida `x` en `{0, width-1}` o `y` en `{0, height-1}`.

## 📚 Recursos

- [Piscine 42 — Índice](../../README.md)
- [La Norma de 42](https://github.com/42Paris/norminette)
- [Rush04 · ejemplo interactivo](https://42quebec.github.io/rush04/)