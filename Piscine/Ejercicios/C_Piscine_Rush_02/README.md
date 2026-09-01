# 🎮 C Piscine · Rush 02 — Números a texto con diccionario

[![Piscina](https://img.shields.io/badge/🗓️_Piscina-42-1f6feb)](../../README.md)
[![Módulo](https://img.shields.io/badge/📦_Rush_02-Parseo-2ea44f)](./)
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

Tercer **Rush**: convertir números a su **representación textual en inglés** (español e inglés es válido según 42, normalmente inglés) leyendo un **diccionario** externo. 🔤

Integra **lectura de archivos**, **parseo línea a línea**, gestión de memoria dinámica y la lógica de descomposición numérica (`4321` → `four thousand three hundred twenty-one`).

## 🎯 Objetivos

- 📄 Leer y parsear un **archivo de diccionario** (`numbers.dict`).
- 🔤 Buscar claves y valores con `strstr`/comparación exacta.
- 🧩 Descomponer el número en **Millares/Cientos/Decenas/Unidades**.
- 💾 Gestionar memoria dinámica sin leaks (el diccionario dado cabe en el heap).
- 🎛️ Bonus: soportar diccionarios propios y comprimir.

## 📄 Enunciado

```bash
./rush-02 42
# forty-two

./rush-02 421123 numbers.dict
# four hundred twenty-one thousand one hundred twenty-three
```

Formato del diccionario (una entrada por línea, `número:nombre`):

```
0: zero
1: one
...
100: hundred
1000: thousand
1000000: million
```

## 🏗️ Estructura

```
C_Piscine_Rush_02/
├── ex00/
│   ├── main.c               # parseo de argv
│   ├── dict.c               # carga y búsqueda en el diccionario
│   ├── convert.c            # lógica de descomposición numérica
│   ├── *.c / *.h
│   └── numbers.dict         # diccionario por defecto
└── README.md
```

## 🛠️ Compilación

```bash
cd ex00
cc -Wall -Wextra -Werror -o rush-02 *.c
```

## 🚀 Uso

```bash
./rush-02 0
# zero

./rush-02 100
# one hundred

./rush-02 999999999
# nine hundred ninety-nine million nine hundred ninety-nine thousand nine hundred ninety-nine
```

## 🧪 Verificación

| Herramienta | Criterio |
|---|---|
| **Moulinette** | Compara la salida exacta con el diccionario oficial |
| **Casos borde** | `0`, `10`, `100`, `1000`, `1000000`, números con ceros intermedios (`1001`), máximo permitido |
| **Errores** | Entrada inválida / diccionario corrupto → `Error\n` |
| **norminette** | `norminette *.c *.h` |
| **valgrind** | Sin leaks al leer el fichero |

💡 Consejos:
- 🔤 La **unidad** (`zero`/`one`…) siempre precede a la **magnitud** (`hundred`/`thousand`…).
- 0️⃣ `zero` solo aparece solo; el resto usa join con `-` para decenas compuestas (`twenty-one`).
- 📚 Si el diccionario no tiene una clave (p. ej. no hay `ten`), la solución óptima **agrupa por magnitudes mínimas**.

## 📚 Recursos

- [Piscine 42 — Índice](../../README.md)
- [Números en inglés (referencia)](https://www.ego4u.com/en/cram-up/vocabulary/numbers)
- [fopen / lectura de archivos en C](https://www.geeksforgeeks.org/c-file-io/)