# 🎮 C Piscine · Rush 01 — Skyline (Skyscrapers)

[![Piscina](https://img.shields.io/badge/🗓️_Piscina-42-1f6feb)](../../README.md)
[![Módulo](https://img.shields.io/badge/📦_Rush_01-Algoritmia-2ea44f)](./)
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

Segundo **Rush**: un reto de lógica pura — implementar un solucionador del juego **Skyline** (rascacielos). 🏙️

Dada una cuadrícula y las "vistas" (cuántos edificios se ven desde cada lado), hay que colocar los números 1..N de forma que cada fila y columna sea una permutación **y** cumpla las restricciones de visibilidad.

## 🎯 Objetivos

- 🧠 Diseñar un algoritmo de **backtracking** con poda.
- 🔁 Entender **recursividad** como backtracking natural.
- 🧩 Validar restricciones de visibilidad (N-queens-style).
- 🤝 Trabajo en equipo y reparto de tareas (4 vistas: left/right/up/down).

## 📄 Enunciado

Entrada (un solo argumento), p. ej. para una cuadrícula 4×4:

```
./skyline "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
```

Los **16 números** se interpretan como: vistas desde `col1..colN`, luego `row1..rowN` (lado izquierdo), después vistas desde la derecha/abajo. Salida: la cuadrícula resuelta, una fila por línea.

## 🏗️ Estructura

```
C_Piscine_Rush_01/
├── ex00/
│   ├── main.c               # parseo de argv y lanzamiento
│   ├── *.c / *.h            # backtracking, validate, print
│   └── ...
└── README.md
```

## 🛠️ Compilación

```bash
cd ex00
make            # o: cc -Wall -Wextra -Werror -o skyline *.c
```

## 🚀 Uso

```bash
./skyline "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
# 1 2 3 4
# 2 3 4 1
# 3 4 1 2
# 4 1 2 3
```

## 🧪 Verificación

| Herramienta | Criterio |
|---|---|
| **Moulinette** | Ejecuta con los argumentos oficiales y compara la salida exacta |
| **Casos borde** | Entradas mal formadas → `Error\n`; sin solución → `Error\n`; varios argumentos → `Error\n` |
| **norminette** | `norminette *.c *.h` |
| **Entrega** | En el rush, **todos** son responsables del código entregado |

💡 Consejos:
- 🧵 La **representación**: `argv[1]` contiene `n^2*4` números de las 4 caras.
- ✂️ **Poda temprana**: valida cada fila/columna al colocarla (no al final).
- ⚡ Complejidad: para 4×4 es trivial, pero con 9×9 un backtracking tonto no acaba; prioriza el orden de inserción de filas.

## 📚 Recursos

- [Piscine 42 — Índice](../../README.md)
- [Backtracking (Wikipedia)](https://es.wikipedia.org/wiki/Vuelta_atr%C3%A1s)
- [Reglas del juego Skycrapers](https://www.krazydad.com/skyscrapers/)