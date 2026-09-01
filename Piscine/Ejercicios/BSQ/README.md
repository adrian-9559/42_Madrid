# 🎮 BSQ — Biggest Square (el cuadrado más grande)

[![Piscina](https://img.shields.io/badge/🗓️_Piscina-42-1f6feb)](../../README.md)
[![Módulo](https://img.shields.io/badge/📦_BSQ-Proyecto_final-2ea44f)](./)
[![Lenguaje](https://img.shields.io/badge/🛠️_C-98-orange)](./)

---

## 🧭 Índice

1. [🌟 Introducción](#-introducción)
2. [🎯 Objetivos](#-objetivos)
3. [📄 Enunciado](#-enunciado)
4. [🧪 Verificación](#-verificación)
5. [✅ Resultado](#-resultado)
6. [📚 Recursos](#-recursos)

---

## 🌟 Introducción

**BSQ** (Biggest Square) es el **reto final de la piscina**: encontrar el **cuadrado más grande** dentro de una matriz rectangular llena de espacios vacíos y obstáculos. 📦

No solo hay que encontrar el cuadrado: hay que hacerlo **eficientemente** (el algoritmo de fuerza bruta falla con mapas grandes) y gestionar la **entrada**, los **errores** y la **memoria** con rigor.

## 🎯 Objetivos

- 📏 Diseñar un algoritmo **O(n·m)** (programación dinámica) en vez de O(n²·m²).
- 📄 Leer archivos de entrada y detectar formatos inválidos.
- 💾 Gestionar memoria dinámica sin leaks.
- 🧪 Probar con mapas enormes (hasta cientos de miles de líneas).

## 📄 Enunciado

El programa recibe la **ruta de un archivo de mapa**:

```
9.ox
.........
...o.....
....o....
.........
.........
.........
.........
.........
.........
```

- Primera línea: **nº de filas**, luego los 3 caracteres para **vacío** `.`, **obstáculo** `o` y **resultado** `x`.
- Hay que marcar el **mayor cuadrado** de vacíos con el tercer carácter y **imprimir el mapa resultante**.

```
.........
...o.....
....o....
.........
...xxx...
...xxx...
...xxx...
.........
.........
```

### Restricciones

- 📏 El mapa debe ser **rectangular** (todas las filas con la misma longitud).
- 🚨 Errores: archivo inexistente/inaccesible, formato incorrecto, caracteres inválidos → `map error`.
- ⏱️ Solución lo más **eficiente** posible para matrices grandes.

## 🧪 Verificación

| Herramienta | Criterio / comando |
|---|---|
| **Makefile** | `make` → genera el ejecutable `bsq` |
| **Ejecución** | `./bsq mapa.txt` o `./bsq mapa1 mapa2 …` (varios mapas) |
| **Mapas de prueba** | Contrasta con generadores (+ desordenados) |
| **Casos borde** | Sin `\n` final, mapas de 1 fila/1 columna, todos obstáculos, todo vacío |
| **Errores** | `map error` (catcher de la Moulinette) ante cualquier inconsistencia |
| **norminette** | `norminette *.c *.h` |
| **valgrind** | Sin leaks |

💡 Algoritmo recomendado (DP):
1. 🧮 Recorre la matriz; `dp[i][j] = min(arriba, izquierda, diagonal↑↖) + 1` si celda vacía.
2. 📍 Guarda el mayor valor y su posición final.
3. 🔍 Con ese tamaño, marca el cuadrado `x`.

## ✅ Resultado

| Resultado | Detalle |
|---|---|
| 🟡 **Incompleto** | La lectura del archivo y la representación de la matriz funcionaron, pero el algoritmo de búsqueda **falló en mapas con múltiples obstáculos o tamaños irregulares**; gestión de errores y rendimiento también incompletos |

> 📝 Esta era la **segunda oportunidad** del proyecto: aunque no se completó, sirvió para reflexionar sobre la importancia de **planificar y probar exhaustivamente los algoritmos antes de implementarlos**, y la necesidad de **validar las entradas** antes de procesarlas. Cada error es una lección. 🌟

## 📚 Recursos

- [Piscine 42 — Índice](../../README.md)
- [Problema del cuadrado máximo (DP)](https://www.geeksforgeeks.org/maximum-size-square-sub-matrix-with-all-1s/)
- [Generador de mapas (gen.pl)](https://github.com/42-piscine/docker-test/tree/master/bsq)