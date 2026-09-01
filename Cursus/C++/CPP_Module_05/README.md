# 🎮 CPP Module 05 — Excepciones

[![Nota](https://img.shields.io/badge/⭐_Nota-Aprobado-2ea44f)](./)
[![Módulo](https://img.shields.io/badge/📦_Módulo-05-1f6feb)](../)
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

Módulo de **gestión de errores con excepciones** (`try`/`catch`/`throw`) ambientado en la burocracia de una oficina: **Bureaucrats**, **Forms** y un **Intern** que fabrica formularios. 🏢

Aprenderás a diseñar **jerarquías de excepciones** propias y a lanzarlas desde constructores y setters cuando los valores no son válidos.

## 🎯 Objetivos

- 🎢 Lanzar y capturar excepciones con `throw` / `try` / `catch`.
- 🏗️ Crear **clases de excepción** anidadas (static `GradeTooHighException`, etc.).
- 🧩 Diseñar jerarquías: `Form` base → `AForm` abstracto → formularios concretos.
- 🏭 Implementar la **factoría** de formularios (Intern) con arrays de punteros.

## 📄 Ejercicios

### ex00 — 🪪 Bureaucrat
`Bureaucrat` con un grado `1..150`. Lanza excepciones al intentar incrementar/decrementar fuera de rango.

### ex01 — 📋 Form
Clase `Form`: nombre, target, grado de firma/ejecución y flag `signed`. `beSigned()` lanza si el grado del burócrata es demasiado bajo.

### ex02 — 📄 AForm y formularios concretos
`AForm` **abstracto** con `execute()`. Implementa:
- `ShrubberyCreationForm` → crea `_shrubbery` con arte ASCII 🌲
- `RobotomyRequestForm` → 50% de éxito "robotomizado" 🤖
- `PresidentialPardonForm` → "ha sido indultado por Zafod Beeblebrox" 🏛️

### ex03 — 🏭 Intern
Clase `Intern` con `makeForm("robotomy request", "Bender")` que devuelve el formulario correcto usando un **array de punteros a crear-formularios**.

## 🏗️ Estructura

```
CPP_Module_05/
├── ex00/  → ./Bureaucrat
├── ex01/  → ./Bureaucrat        # Bureaucrat + Form
├── ex02/  → ./newForms          # AForm + 3 formularios concretos
├── ex03/  → ./Intern            # Intern + makeForm
└── README.md
```

## 🛠️ Compilación

```bash
cd ex00 && make && ./Bureaucrat
cd ../ex01 && make && ./Bureaucrat
cd ../ex02 && make && ./newForms
cd ../ex03 && make && ./Intern
```

## 🚀 Uso y ejemplos

```bash
./Bureaucrat
# Try to create a grade 151 bureaucrat →
# Bureaucrat::GradeTooLowException

./Intern
# Intern creates "ShrubberyCreationForm" → forms/_shrubbery
```

## 🧪 Verificación

| Herramienta | Comandos |
|---|---|
| **Compilación C++98** | `cd exXX && make && c++ -std=c++98` |
| **Casos borde** | Grado 0 y 151 → excepción; firmar con grado insuficiente → excepción |
| **Archivos** | `ShrubberyCreationForm` debe crear el archivo `.shrubbery` con el árbol |
| **Intern** | Formulario inexistente → excepción "unknown form" |

## 📚 Recursos

- [Índice C++](../README.md)
- [cppreference · Excepciones](https://en.cppreference.com/w/cpp/language/exceptions)
- [cppreference · try/catch](https://en.cppreference.com/w/cpp/language/try_catch)