# 🎮 C Piscine · Shell 01 — Scripting de shell

[![Piscina](https://img.shields.io/badge/🗓️_Piscina-42-1f6feb)](../../README.md)
[![Módulo](https://img.shields.io/badge/📦_Shell_01-Scripting-2ea44f)](./)
[![Shell](https://img.shields.io/badge/🛠️_bash/sh-3E3E3E)](./)

---

## 🧭 Índice

1. [🌟 Introducción](#-introducción)
2. [🎯 Objetivos](#-objetivos)
3. [📄 Ejercicios](#-ejercicios)
4. [🧪 Verificación](#-verificación)
5. [📚 Recursos](#-recursos)

---

## 🌟 Introducción

Segundo módulo de shell, ya en **modo scripting**: escribir scripts que automatizan tareas del sistema, con `$(...)`, `find`, `grep`, `cut` y manejo de **caracteres especiales** en nombres de archivo. 🐚

Incluye el mítico ejercicio de crear un archivo llamado `"\?$*'MaRViN'*$?\"`. 💀

## 🎯 Objetivos

- ⌨️ Escribir scripts ejecutables (`#!/bin/sh`).
- 🔍 `find` con fusión de archivos (`-name`, `-type`).
- 🧮 Contar y filtrar con `wc`, `grep`, `cut`.
- 🧾 Obtener información del sistema (`id -Gn`, `ip`/`ifconfig` para MAC).
- ✨ Manejar **caracteres especiales** en nombres de archivo (`\`, `"`, `*`, `?`, `$`).

## 📄 Ejercicios

| # | Ejercicio | Enlace |
|---|---|---|
| ex01 | `print_groups.sh` · grupos de un usuario (`id -Gn`) | [ver](./ex01/print_groups.sh) |
| ex02 | `find_sh.sh` · nombres de `.sh` sin extensión | [ver](./ex02/find_sh.sh) |
| ex03 | `count_files.sh` · cuenta archivos y directorios | [ver](./ex03/count_files.sh) |
| ex04 | `MAC.sh` · direcciones MAC de la máquina | [ver](./ex04/MAC.sh) |
| ex05 | `"\?$*'MaRViN'*$?\"` · crea un archivo con nombre literal | [ver](./ex05/) |
| ex06 | `skip.sh` · `ls -l` saltando líneas pares | [ver](./ex06/skip.sh) |

## 🧪 Verificación

| Herramienta | Criterio |
|---|---|
| **Moulinette** | Ejecuta cada script y compara la salida exacta |
| **Validación manual** | `./ex05/` → `ls` debe mostrar el archivo con el nombre exacto |
| **Permisos** | Los scripts deben ser **ejecutables** (`chmod +x`) |
| **`/bin/sh`** | Debe funcionar con `sh` (los ejercicios se hacen con `/bin/sh`) |

💡 VIP:
- 👥 **ex01**: `id -Gn $FT_USER` — los grupos separados **solo por comas sin espacios** (`$FT_USER` por variable).
- 🌀 **ex02**: `find . -name "*.sh" -exec basename {} .sh \;` → nombres sin extensión.
- 🎨 **ex05**: crear el archivo escapando los caracteres especiales: `touch "\"\\?\$*'MaRViN'*\$?\\\""`
- ➖ **ex06**: `ls -l | awk 'NR%2==1'` (o `sed -n 'p;n'`) imprime la primera, tercera…

## 📚 Recursos

- [Piscine 42 — Índice](../../README.md)
- [Guía de scripting bash](https://mywiki.wooledge.org/BashGuide)
- [Explica comandos shell](https://explainshell.com/)