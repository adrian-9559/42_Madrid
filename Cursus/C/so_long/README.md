# 🎮 so_long — Un minijuego 2D con MiniLibX

[![Nota](https://img.shields.io/badge/⭐_Nota-100/100-2ea44f)](./)
[![Anillo](https://img.shields.io/badge/🔵_Anillo-3º_Círculo-1f6feb)](../)
[![Lenguaje](https://img.shields.io/badge/🛠️_C-98-orange)](./)
[![Gráficos](https://img.shields.io/badge/🎨_MiniLibX-42-6f42c1)](./)

---

## 🧭 Índice

1. [🌟 Introducción](#-introducción)
2. [🎯 Objetivos](#-objetivos)
3. [📄 Enunciado](#-enunciado)
4. [🗺️ Mapa y reglas](#️-mapa-y-reglas)
5. [🏗️ Estructura](#️-estructura)
6. [🛠️ Compilación](#️-compilación)
7. [🚀 Uso y ejemplos](#-uso-y-ejemplos)
8. [🧪 Verificación](#-verificación)
9. [✅ Nota](#-nota)
10. [📚 Recursos](#-recursos)

---

## 🌟 Introducción

**so_long** es una introducción práctica al desarrollo de videojuegos en C. 🕹️ Crearás un pequeño juego donde el jugador recorre un mapa, **recoge objetos** y **alcanza la salida**, usando gráficos básicos de la biblioteca **MiniLibX**.

Además de lógica de juego, aprenderás a **parsear y validar mapas**, a dibujar sprites/texturas por teclado y a cerrar la ventana gestionando los eventos correctamente. 🎨

## 🎯 Objetivos

- 🗺️ Leer y **validar un mapa `.ber`** con un parser estricto.
- 🎨 Renderizar sprites con **MiniLibX** (texturas, eventos de teclado/ventana).
- 🚶 Implementar movimiento en una **matriz** con colisiones.
- 🍎 Gestión del juego: recoger coleccionables y llegar a la salida.
- 🧹 Memoria sin leaks y código bajo **norminette**.

## 📄 Enunciado

- 🎮 El jugador (`P`) debe poder moverse con **WASD o flechas**.
- 🍎 Debe recoger **todos** los coleccionables (`C`) para poder abrir la salida (`E`).
- 📉 El número de **movimientos se muestra en la terminal**.
- 🧱 Las paredes (`1`) bloquean el paso; el suelo (`0`) es espacio libre.
- ✖️ Solo se permite **una salida, un jugador** y al menos un coleccionable.
- 📐 El mapa debe estar **cerrado por paredes** y ser **rectangular**.
- 🔁 Todo camino es verificable: el jugador debe poder alcanzar **todos** los objetos y la salida (flood fill).

### 🗺️ Leyenda del mapa

| Carácter | Elemento |
|---|---|
| `1` | 🧱 Pared |
| `0` | 🌫️ Suelo vacío |
| `C` | 🍎 Coleccionable |
| `E` | 🚪 Salida |
| `P` | 🧑 Jugador (posición inicial) |

## 🏗️ Estructura

```
so_long/
├── README.md                # 📘 Este documento
├── so_long_linux/           # 🐧 Versión de trabajo (Linux / gcc)
│   ├── Makefile             # NAME = so_long
│   ├── so_long.h            # Prototipos + struct s_game
│   ├── main.c               # Inicialización y bucle del juego
│   └── src/                 # Parsing, render, gestión de eventos
│       └── lib/             # get_next_line y utilidades reutilizables
└── so_long_mac/             # 🍏 Clon para macOS (MiniLibX de 42)
```

> 💡 La versión "activa" documentada es `so_long_linux/` (con su propio README). `so_long_mac/` es el clon para compilar en los iMacs del campus.

## 🛠️ Compilación

Dentro de `so_long_linux/`:

```bash
make          # Compila el ejecutable so_long (cc -Wall -Wextra -Werror -w)
make clean    # Elimina los .o
make fclean   # Elimina .o y el binario
```

Requisito: tener instalada la **MiniLibX** y, en Linux, sus dependencias (`libx11-dev libxext-dev`…).

## 🚀 Uso y ejemplos

```bash
./so_long mapa.ber   # Lanza el juego con el mapa dado
```

Los mapas `.ber` de ejemplo se colocan en una carpeta `maps/` (o el nombre que quieras):

```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

→ El jugador debe recoger la `C` y llegar a la `E` contando los pasos en la terminal. 🧮

## 🧪 Verificación

No existe un tester estándar de la comunidad para so_long; la evaluación se apoya en:

| Herramienta | Comandos |
|---|---|
| **Mapas de prueba** | Comprueba que los `.ber` de prueba pasan el parser (paredes, rectángulo, cerrado, accesibilidad) |
| **norminette** | `norminette *.c *.h src/` |
| **valgrind** | `valgrind --leak-check=full ./so_long mapa.ber` → al cerrar con ESC/✕ no debe haber leaks |
| **Evaluación manual** | Movimiento fluido, contador de pasos correcto, cierre de ventana con error/success |

💡 Casos que suelen salir en evaluación:
- ❌ Mapa **sin salida**, sin jugador o sin coleccionables → error claro y limpio.
- ❌ Mapa **abierto** (pared rota) o **no rectangular** → rechazo.
- 🍎 Todos los `C` inaccesibles pero llegando a la salida → comprobar flood fill.

## ✅ Nota

| Resultado | Detalle |
|---|---|
| ⭐ **100/100** | Perfecto |

## 📚 Recursos

- [Subject oficial](https://cdn.intra.42.fr/pdf/pdf/61014/fr.subject.pdf)
- [Cursus C — Índice](../README.md)
- [MiniLibX · man de 42](https://github.com/42Paris/minilibx-linux)
- [get_next_line incluido en el proyecto](./so_long_linux/lib/get_next_line/README.md)
- [GNL principal del cursus](../get_next_line/README.md)