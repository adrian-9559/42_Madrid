# 🎮 CPP Module 04 — Polimorfismo, abstract classes y copia profunda

[![Nota](https://img.shields.io/badge/⭐_Nota-Aprobado-2ea44f)](./)
[![Módulo](https://img.shields.io/badge/📦_Módulo-04-1f6feb)](../)
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

Este es el módulo clave del **polimorfismo de subtipos**: métodos **virtuales**, clases **abstractas** y la **copia profunda**. 🧬

Aquí ya no construyes una clase que "parece otra": haces que un puntero a la base llame a la implementación correcta **en tiempo de ejecución** (dispatch dinámico) mediante `virtual`.

## 🎯 Objetivos

- 🌀 Usar **`virtual`** para polimorfismo dinámico.
- 🌫️ Crear **clases abstractas** con métodos puros (`= 0`).
- 📋 Entender **copia profunda** vs copia superficial (`Brain`).
- 🧱 Diseñar jerarquías coherentes (Animal → Cat/Dog).

## 📄 Ejercicios

### ex00 — 🐾 Polymorphism
`Animal` (método `makeSound()`), `Cat` y `Dog` que **sobreescriben** el sonido. Comprueba por qué hace falta `virtual`.

### ex01 — 🧠 Brain
`Cat` y `Dog` tienen un **`Brain`** (array de 100 ideas). Implementa **copia profunda** en la FCO para que cada objeto tenga su propia cabecera de memoria.

### ex02 — 🌫️ Abstract Animal
La clase `Animal` se convierte en **abstracta**: `makeSound()` pasa a ser método puro. No se puede instanciar `Animal`.

## 🏗️ Estructura

```
CPP_Module_04/
├── ex00/  → ./Polymorphism          # Animal + Cat/Dog
├── ex01/  → ./Brain                 # Animal + Brain (copia profunda)
├── ex02/  → ./Abstract              # AAnimal abstracto + Cat/Dog
└── README.md
```

## 🛠️ Compilación

```bash
cd ex00 && make && ./Polymorphism
cd ../ex01 && make && ./Brain
cd ../ex02 && make && ./Abstract
```

## 🚀 Uso y ejemplos

```bash
./Polymorphism        # imprime los sonidos correctos de cada animal
./Brain               # copia un Dog y verifica que el Brain es independiente
./Abstract            # no puede crear un Animal pero sí Cat/Dog
```

## 🧪 Verificación

| Herramienta | Comandos |
|---|---|
| **Compilación C++98** | `cd exXX && make && c++ -std=c++98` |
| **Salida exacta** | Debe coincidir con los `main` del enunciado |
| **Copia profunda** | `valgrind ./Brain` + cambiar el brain del original y ver que la copia no cambia |
| **Abstract** | Intentar `Animal a;` en ex02 → error de compilación (clase abstracta) |

💡 Errores típicos:
- 🐛 Olvidar `virtual` en `~Animal()` → **leak** o destructor de la base sin llamar al de la parte derivada.
- 📋 **Copia superficial** del `Brain` → dos objetos comparten el mismo puntero (doble free).
- 🌫️ No poner `= 0` → la clase sigue siendo instanciable.

## 📚 Recursos

- [Índice C++](../README.md)
- [cppreference · Virtual functions](https://en.cppreference.com/w/cpp/language/virtual)
- [cppreference · Rule of three/five](https://en.cppreference.com/w/cpp/language/rule_of_three)