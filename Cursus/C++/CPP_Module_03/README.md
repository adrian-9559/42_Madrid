# 🎮 CPP Module 03 — Herencia

[![Nota](https://img.shields.io/badge/⭐_Nota-Aprobado-2ea44f)](./)
[![Módulo](https://img.shields.io/badge/📦_Módulo-03-1f6feb)](../)
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

Módulo dedicado a la **herencia**: constructores encadenados, destructores y jerarquías de clases con la familia de robots **ClapTrap**. 🤖

Aprenderás cómo se **construye y destruye** una clase derivada (orden: base → derivada; destrucción: derivada → base) y qué implica **ocultar atributos** de la clase base.

## 🎯 Objetivos

- 🧬 Comprender **herencia simple** y **múltiple** (DiamondTrap).
- 🔗 Encadenar **constructores** (initializer lists que llaman a la base).
- 🎭 **Ocultar** y sobrecargar métodos de la clase base.
- 🧠 Gestionar la **ambigüedad** de la herencia en diamante (`virtual`).

## 📄 Ejercicios

### ex00 — 🤖 ClapTrap
Clase base con `hitPoints`, `energyPoints`, `attackDamage` y métodos `attack()`, `takeDamage()`, `beRepaired()`.

### ex01 — 🛡️ ScavTrap
Clase derivada de ClapTrap con más hp/energía y su `guardGate()`.

### ex02 — 🧨 FragTrap
Otra derivada con `highFivesGuys()`.

### ex03 — 💎 DiamondTrap
Herencia **múltiple** (ScavTrap + FragTrap → DiamondTrap) con `whoAmI()` y nombre propio. Introduce la **herencia virtual** para resolver el diamante.

## 🏗️ Estructura

```
CPP_Module_03/
├── ex00/  → ./ClapTrap
├── ex01/  → ./ScavTrap
├── ex02/  → ./FlagTrap
├── ex03/  → ./DiamondTrap
└── README.md
```

## 🛠️ Compilación

```bash
cd ex00 && make && ./ClapTrap
cd ../ex01 && make && ./ScavTrap
cd ../ex02 && make && ./FlagTrap
cd ../ex03 && make && ./DiamondTrap
```

## 🚀 Uso y ejemplos

```bash
./ClapTrap
# ClapTrap ClapTrap created!
# ClapTrap ClapTrap attacks ...
# ...

./DiamondTrap pitufo
# DiamondTrap pitufo, ¿quién soy? Soy pitufo
```

## 🧪 Verificación

| Herramienta | Comandos |
|---|---|
| **Compilación C++98** | `cd exXX && make && c++ -std=c++98` |
| **Mensajes de creación** | Deben imprimirse en el orden base → derivado |
| **Destrucción** | `make clean && valgrind ./ClapTrap` → orden inverso sin leaks |

💡 Atención a:
- 🎭 **Shadowing**: en `DiamondTrap` los atributos de la base quedan "ocultos"; el nombre propio debe gestionarse aparte.
- 🔗 La **herencia virtual** evita la duplicación de la base en el diamante.
- 👷 La **FCO** (compilador) debe estar en todas las clases desde Módulo 02.

## 📚 Recursos

- [Índice C++](../README.md)
- [cppreference · Herencia](https://en.cppreference.com/w/cpp/language/derived_class)
- [cppreference · Herencia virtual](https://en.cppreference.com/w/cpp/language/virtual_base)