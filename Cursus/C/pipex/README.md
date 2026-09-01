# 🎮 pipex — Pipes en la shell

[![Nota](https://img.shields.io/badge/⭐_Nota-100/100-2ea44f)](./)
[![Anillo](https://img.shields.io/badge/🔵_Anillo-3º_Círculo-1f6feb)](../)
[![Lenguaje](https://img.shields.io/badge/🛠️_C-98-orange)](./)

---

## 🧭 Índice

1. [🌟 Introducción](#-introducción)
2. [🎯 Objetivos](#-objetivos)
3. [📄 Enunciado](#-enunciado)
4. [🏗️ Estructura](#️-estructura)
5. [🛠️ Compilación](#️-compilación)
6. [🚀 Uso y ejemplos](#-uso-y-ejemplos)
7. [🧪 Testers y verificación](#-testers-y-verificación)
8. [🎁 Bonus](#-bonus)
9. [✅ Nota](#-nota)
10. [📚 Recursos](#-recursos)

---

## 🌟 Introducción

**pipex** te hace reproducir, en C, el famoso `|` de la shell:

```bash
< infile cmd1 | cmd2 > outfile
```

Es tu primera inmersión en **programación de procesos** en Unix: `fork()`, `execve()`, `dup2()`, `pipe()` y la gestión de errores. 🌉

Comprendí estos conceptos de una vez: hasta aquí todo era memoria y strings; ahora el programa **se multiplica en procesos** y hay que orquestarlos.

## 🎯 Objetivos

- 🔀 Entender y usar `fork()` para crear procesos hijos.
- 🔁 Redirigir entradas/salidas con `dup2()`.
- 🚰 Comunicar procesos con `pipe()`.
- 🗑️ Buscar y ejecutar programas con `execve()` + `PATH`.
- 🛡️ Gestionar errores sin que el programa "muera a lo tonto" (symlinks a `/dev/null`).

## 📄 Enunciado

Tu programa debe ejecutarse así:

```bash
./pipex infile cmd1 cmd2 outfile
```

Y equivale exactamente a:

```bash
< infile cmd1 | cmd2 > outfile
```

- 📥 `infile` se abre, y su contenido alimenta a `cmd1`.
- 🔗 La salida de `cmd1` entra en `cmd2` **sin pasar por archivos intermedios**.
- 📤 La salida de `cmd2` se escribe en `outfile` (creado con los permisos correctos).

## 🏗️ Estructura

```
pipex/
├── Makefile                # all, bonus, clean, fclean, re
├── pipex.h                 # Prototipos y struct de programa
├── pipex.c                 # main y flujo principal (pipe/fork/dup2/exec)
└── src/
    └── utils.c             # Parseo de PATH, ejecución, gestión de errores
```

## 🛠️ Compilación

```bash
make          # Compila el ejecutable pipex
make bonus    # Añade heredoc y múltiples comandos
make fclean   # Limpia objetos y ejecutable
```

⚠️ Makefile con `cc -Wall -Wextra -Werror`, siempre recompila cuando cambian los fuentes (no hace relink.

## 🚀 Uso y ejemplos

```bash
# Equivale a: < input.txt cat | wc -l > output.txt
./pipex input.txt "cat" "wc -l" output.txt

# Equivale a: < input.txt grep foo | sort > sorted.txt
./pipex input.txt "grep foo" "sort" sorted.txt

# Puedes encadenar comandos con opciones
./pipex /etc/hosts "grep localhost" "rev" result.txt
```

## 🧪 Testers y verificación

| Herramienta | Instalación | Comandos |
|---|---|---|
| **pipex_tester** (vfurmane) | `git clone https://github.com/vfurmane/pipex_tester.git` | `cd pipex_tester && ./run.sh` |
| **pipex_tester** (voorivex, fork) | `git clone https://github.com/voorivex/pipex_tester.git` | `cd pipex_tester && ./run.sh` |
| **norminette** | `pip install norminette` | `norminette *.c *.h src/` |
| **valgrind** | parte del sistema | `valgrind ./pipex infile "cmd1" "cmd2" outfile` |

💡 Casos que siempre preguntan:
- 🗂️ Archivos que **no existen** (`infile` inexistente debe seguir creando `outfile`).
- 🚫 Comandos que **no existen** (error a stderr + exit code ≠ 0).
- 🔗 **El mismo comando** con su ruta completa (`/usr/bin/cat`).
- 📎 Varias pipes encadenadas (bonus).

## 🎁 Bonus

- **Heredoc**: `./pipex here_doc LIMITADOR cmd1 cmd2 outfile` equivale a `<< LIMITADOR | cmd1 | cmd2 >> outfile` (con `outfile` en modo append).
- **Múltiples pipes**: soporte para N comandos:
  `./pipex infile cmd1 cmd2 ... cmdn outfile`.

## ✅ Nota

| Resultado | Detalle |
|---|---|
| ⭐ **100/100** | Perfecto |
| 💬 Comentario del corrector | *"Explicación clara de los conceptos anticuados, sin objeciones"* |

## 📚 Recursos

- [Subject oficial](https://cdn.intra.42.fr/pdf/pdf/60801/en.subject.pdf)
- [Cursus C — Índice](../README.md)
- [vfurmane · pipex_tester](https://github.com/vfurmane/pipex_tester)
- [Guía interactiva de pipes en C (Tutorialspoint)](https://www.tutorialspoint.com/inter_process_communication/inter_process_communication_pipes.htm)