# 🎮 CPP Module 01 — Memoria, referencias y punteros

[![Nota](https://img.shields.io/badge/⭐_Nota-Aprobado-2ea44f)](./)
[![Módulo](https://img.shields.io/badge/📦_Módulo-01-1f6feb)](../)
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

Este módulo profundiza en **memoria dinámica** (`new`/`delete`), **referencias** (`&`) y **punteros**, además de manipulación básica de archivos. Es aquí donde se entiende la diferencia entre pasar por valor, por puntero y por referencia. 📦

## 🎯 Objetivos

- 🧠 Diferenciar **referencias vs punteros**.
- 📥 Gestionar **memoria dinámica** sin fugas (`new`/`delete`).
- 📑 Leer/escribir **archivos** de texto.
- 🧩 Diseñar clases con relaciones entre objetos (Human + Weapon).
- 🐙 Emular "switch" con arrays de punteros a miembros (Harl).

## 📄 Ejercicios

### ex00 — 🧟 Zombie
### ex01 — 🧟 Zombie Horde
Crea zombies en el heap con `new Zombie[N]` y una función de "destructor masivo" (`delete[]`).

### ex02 — 🧠 HI THIS IS BRAIN
Demuestra la diferencia entre la variable, su puntero y su referencia (`&string`, `*stringPTR`).

### ex03 — ⚔️ Human and Weapon
Clases `HumanA` (referencia a `Weapon`) y `HumanB` (puntero a `Weapon`, puede ir desarmado).

### ex04 — 📝 Replace
Sustituye todas las apariciones de un string por otro en un archivo, **sin** usar `std::string::replace`.

### ex05 — 🗣️ Harl 2.0
Clase `Harl` con 4 niveles de queja (`DEBUG`, `INFO`, `WARNING`, `ERROR`) despachados con un **array de punteros a funciones miembro**.

### ex06 — 📢 Harl Filter
Usa los niveles para filtrar: muestra desde el nivel dado hacia abajo (lógica "switch").

## 🏗️ Estructura

```
CPP_Module_01/
├── ex00/  → ./zombie
├── ex01/  → ./zombie
├── ex02/  → ./brain
├── ex03/  → ./human
├── ex04/  → ./replace
├── ex05/  → ./harl
├── ex06/  → ./harlFilter
└── README.md
```

## 🛠️ Compilación

```bash
cd ex00 && make && ./zombie
cd ../ex01 && make && ./zombie
cd ../ex02 && make && ./brain
cd ../ex03 && make && ./human
cd ../ex04 && make && ./replace
cd ../ex05 && make && ./harl
cd ../ex06 && make && ./harlFilter
```

## 🚀 Uso y ejemplos

```bash
# Zombie (ex01): crea horda y la destruye
./zombie

# Replace (ex04)
./replace archivo.txt "wanted" "replacement"

# Harl Filter (ex06) — pide nivel y muestra las quejas
./harlFilter WARNING
```

## 🧪 Verificación

| Herramienta | Comandos |
|---|---|
| **Compilación C++98** | `cd exXX && make && c++ -std=c++98` |
| **valgrind** | `valgrind ./zombie` → comprobar que `delete[]` libera todo |
| **Casos bordes (ex04)** | archivo inexistente, string objetivo vacío, string de reemplazo con caracteres especiales |

💡 Puntos de evaluación habituales:
- 🧹 **Sin leaks**: toda la memoria `new` debe tener su `delete` (ex00/ex01/ex03).
- 🔗 Referencias **no reasignables**: `HumanA` fuerza el arma por referencia.
- 📄 `Replace`: comportamiento exacto como el `sed` de la shell.

## 📚 Recursos

- [Índice C++](../README.md)
- [cppreference · new/delete](https://en.cppreference.com/w/cpp/language/new)
- [cppreference · fstream](https://en.cppreference.com/w/cpp/io/basic_fstream)