# 🎮 CPP Module 00 — Namespaces, clases y streams

[![Nota](https://img.shields.io/badge/⭐_Nota-Aprobado-2ea44f)](./)
[![Módulo](https://img.shields.io/badge/📦_Módulo-00-1f6feb)](../)
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

Primer contacto con C++. 🔤 Con este módulo entras al mundo de **namespaces**, **clases**, **funciones miembro**, **streams de stdio** y diseño básico de objetos. Todo en C++98 y sin STL.

## 🎯 Objetivos

- 🏷️ Entender **namespaces** y cómo evitar colisiones de nombres.
- 🧱 Crear tus primeras **clases** con métodos y atributos privados.
- 📥 Usar **`std::cin` / `std::cout`** para entrada/salida de forma segura.
- 🧠 Diseñar objetos simples con una interfaz clara (PhoneBook).

## 📄 Ejercicios

### ex00 — 📣 Megaphone
Convierte los argumentos de la línea de comandos a **mayúsculas**: grita como un megáfono.

```bash
./megaphone "shhh" "hello world"
# → SHHH HELLO WORLD
```

### ex01 — 📒 PhoneBook
Tu primera app con estado: una agenda de hasta 8 contactos con **búsqueda por índice**, campos truncados (`width 10`, alineación derecha) y gestión de entrada limpia.

```bash
./phone_book
# Comandos: ADD | SEARCH | EXIT
```

## 🏗️ Estructura

```
CPP_Module_00/
├── ex00/               # Megaphone
│   ├── Makefile
│   ├── megaphone.cpp   # → ./megaphone
├── ex01/               # PhoneBook
│   ├── Makefile
│   ├── PhoneBook.hpp / PhoneBook.cpp
│   ├── Contact.hpp / Contact.cpp
│   └── main.cpp        # → ./phone_book
└── README.md
```

## 🛠️ Compilación

```bash
cd ex00 && make        # c++ -Wall -Wextra -Werror
cd ../ex01 && make
```

## 🚀 Uso y ejemplos

```bash
./megaphone "hola" "mundo"          # HOLA MUNDO
./megaphone                         # * LOUD AND UNBEARABLE FEEDBACK NOISE *

./phone_book
> ADD
> SEARCH         # tabla con índice, nombre, apellido y nickname
> 1              # muestra el contacto completo
> EXIT
```

## 🧪 Verificación

| Herramienta | Comandos |
|---|---|
| **Compilación** | `c++ -Wall -Wextra -Werror -std=c++98` |
| **Pruebas manuales** | `./megaphone ""` · `./phone_book` con entradas vacías, espacios y `CTRL-D` |
| **valgrind** | `valgrind ./phone_book` → sin leaks (Contact objects) |

💡 En este módulo aún no hay **FCO**: las clases son simples. La gestión de memoria es explícita y sencilla.

## 📚 Recursos

- [Índice C++](../README.md)
- [cppreference · iostream](https://en.cppreference.com/w/cpp/io)