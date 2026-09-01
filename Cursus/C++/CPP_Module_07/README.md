# 🎮 CPP Module 07 — Templates (programación genérica)

[![Nota](https://img.shields.io/badge/⭐_Nota-Aprobado-2ea44f)](./)
[![Módulo](https://img.shields.io/badge/📦_Módulo-07-1f6feb)](../)
[![Lenguaje](https://img.shields.io/badge/🛠️_C++98-00599c)](./)

---

## 🧭 Índice

1. [🌟 Introducción](#-introducción)
2. [🎯 Objetivos](#-objetivos)
3. [📄 Ejercicios](#-ejercicios)
4. [🏗️ Estructura](#️-estructura)
5. [🛠️ Compilación](#️-compilación)
6. [🚀 Uso y ejemplos](#-uso-y-ejemplos)
7. [🧪 Verificación](#-verificación)
8. [📚 Recursos](#-recursos)

---

## 🌟 Introducción

Módulo introductorio a los **templates** de funciones y clases. 🔧 Escribirás código genérico que funciona con cualquier tipo: `swap`, `min`, `max`, una función `iter` y un contenedor `Array` completo (con su FCO y excepciones).

Es la puerta a la **STL**: entender templates aquí es entender cómo funcionan `std::vector`, `std::map`…

## 🎯 Objetivos

- 🔨 Sintaxis de **templates de funciones y clases**.
- 📤 Gestión de **`typename`** múltiples y deducción de tipos.
- 🧱 Implementar una **clase `Array`** genérica con memoria dinámica.
- 🚨 Lanzar **excepciones** desde la clase genérica (`std::out_of_range`).

## 📄 Ejercicios

### ex00 — 🔁 Function templates
`swap`, `min`, `max` genéricos. Aprende a **probar con `::`** para evitar la colisión con `std::min`/`std::max`.

### ex01 — 🔂 Funcion iter
Template que recibe un array, su longitud y una función, y **aplica la función a cada elemento**.

### ex02 — 📦 Array
**Clase template `Array<T>`** con:
- Constructor por defecto y con tamaño `n` (elementos default-inicializados).
- **FCO** (constructor de copia + asignación, **copia profunda**).
- `operator[]` con excepción `std::out_of_range` para índices fuera de límites.
- `size()`.

## 🏗️ Estructura

```
CPP_Module_07/
├── ex00/  → ./whatever       # templates swap/min/max
├── ex01/  → ./Iter           # función template iter
├── ex02/  → ./Array          # clase template Array<T>
└── README.md
```

## 🛠️ Compilación

```bash
cd ex00 && make && ./whatever
cd ../ex01 && make && ./Iter
cd ../ex02 && make && ./Array
```

## 🚀 Uso y ejemplos

```bash
./whatever
# max(2,3) = 3
# min("cadena1","cadena2") = cadena1

./Array
# src[0..4] → copia → dst.size() = 5
# dst[6] → std::out_of_range (excepción capturada)
```

## 🧪 Verificación

| Herramienta | Comandos |
|---|---|
| **Compilación C++98** | `cd exXX && make && c++ -std=c++98` |
| **`std::out_of_range`** | Acceder a índice fuera de rango debe lanzar y capturarse |
| **Copia profunda** | Modificar el array original y verificar que la copia no cambia (valgrind sin double free) |
| **Sin `.cpp`** | Todos los templates en `.hpp` (si hay `.cpp` → 0) |

💡 `Array<int>()` con `n` deja los enteros a **cero** (`T()` default). El corrector suele probar `Array<char>` y `Array<std::string>` también.

## 📚 Recursos

- [Índice C++](../README.md)
- [cppreference · Templates](https://en.cppreference.com/w/cpp/language/templates)
- [cppreference · Template (clases)](https://en.cppreference.com/w/cpp/language/class_template)