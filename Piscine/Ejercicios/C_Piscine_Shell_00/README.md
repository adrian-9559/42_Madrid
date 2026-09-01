# 🎮 C Piscine · Shell 00 — Fundamentos de la línea de comandos

[![Piscina](https://img.shields.io/badge/🗓️_Piscina-42-1f6feb)](../../README.md)
[![Módulo](https://img.shields.io/badge/📦_Shell_00-Shell_básico-2ea44f)](./)
[![Shell](https://img.shields.io/badge/🛠️_bash/sh-3E3E3E)](./)

---

## 🧭 Índice

1. [🌟 Introducción](#-introducción)
2. [🎯 Objetivos](#-objetivos)
3. [📄 Enunciado](#-enunciado)
4. [🧪 Verificación](#-verificación)
5. [📚 Recursos](#-recursos)

---

## 🌟 Introducción

Primer módulo de la piscina y **primer contacto con la terminal**. 🐚 Aprenderás los básicos del shell Unix: comandos, **redirecciones**, **permisos** de archivos y creación de directorios, todo sin tocar el ratón.

La **precisión manda**: en shell, «casi igual» es «mal». 🎯

## 🎯 Objetivos

- 💻 Comandos básicos (`ls`, `cd`, `mkdir`, `touch`, `find`…).
- 🔒 **Permisos** `chmod` y gestión de `-rw-r--r--`.
- 📂 Redirecciones y pipes básicos.
- 🧹 Crear el árbol de archivos exacto que exige el subject (ni uno más, ni uno menos).

## 📄 Enunciado

El subject de este módulo se compone de pequeños **retos** (ft_pwd, ft_ls, ft_tar… según versión) que evalúan comandos y el **resultado exacto** en el sistema del evaluador.

📄 Enunciado en español: [es.subject.pdf](./es.subject.pdf)

> ⚠️ En los ejercicios de shell **solo se puede usar `/bin/sh`** y está prohibido añadir archivos fuera de lo especificado.

## 🧪 Verificación

| Herramienta | Criterio |
|---|---|
| **Moulinette** | Ejecuta los comandos de los `.sh` y compara salida byte a byte |
| **Permisos** | `ls -l` → los ejecutables deben tener `-r-x------` (si los pide el enunciado) |
| **`/bin/sh`** | Los scripts deben correr con `sh`, no con `bash` |
| **Precisión** | Cualquier carácter de más en la salida → fallo |

💡 Consejo: ejecuta `diff` contra los resultados esperados y `chmod +x` donde haga falta **antes** de entregar.

## 📚 Recursos

- [Piscine 42 — Índice](../../README.md)
- [Referencia de comandos Linux](https://explainshell.com/)
- [Guía de permisos chmod](https://www.chmodcommand.com/)