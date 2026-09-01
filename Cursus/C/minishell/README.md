# 🎮 minishell — Una shell mínima desde cero

[![Nota](https://img.shields.io/badge/⭐_Nota-100/100-2ea44f)](./)
[![Anillo](https://img.shields.io/badge/🔵_Anillo-4º_Círculo-1f6feb)](../)
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
8. [✅ Nota](#-nota)
9. [📚 Recursos](#-recursos)

---

## 🌟 Introducción

**minishell** es el proyecto más completo hasta el momento: crearás una **shell funcional** que interprete y ejecute comandos, como una versión reducida de `bash`. 🐚

Parte de TinyShell (de Aníbal Ibaceta 🐚), escribe el bucle **leer → parsear → ejecutar** y gestiona procesos, redirecciones y variables de entorno. Es el proyecto donde **reutilizas todo lo aprendido**: memoria, procesos, tokens, libc… integrado en un solo binario.

## 🎯 Objetivos

- ⌨️ Leer e interpretar la entrada del usuario en un **intérprete interactivo**.
- 🧠 Construir un **parser/tokenizador** de comandos y operadores.
- 🔀 Lanzar procesos con `fork()`, `execve()` y gestionar `$PATH`.
- 📤 Redirecciones y **pipes** (`>`, `>>`, `<`, `<<`, `|`).
- 🌡️ Variables de entorno y `$?` (último status).
- 🔢 Builtins sin fork: `cd`, `export`, `unset`, `env`, `echo`, `pwd`, `exit`.

## 📄 Enunciado

Tu shell debe gestionar:

- 🔡 **Prompt** propio y bucle lector.
- #️⃣ Comandos con **argumentos** (path absoluto o relativo vía `$PATH`).
- 📌 **Quoting**: manejar comillas simples `'…'`, dobles `"…"`, y caracteres especiales (`\`, `;`, `$`).
- 💭 **`$`** para expandir variables de entorno (`$USER`).
- 🧵 **Signals**: `Ctrl-C`, `Ctrl-D`, `Ctrl-\` con el comportamiento de `bash`.
- 🔴 Redirecciones: `> >> < <<` (heredoc).
- 🚰 **Pipes** `|` que encadenen comandos.
- ⚙️ **`$?`** para conocer el código de salida del último comando.
- ⛔ Builtins (sin fork): `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`.

## 🏗️ Estructura

```
minishell/
├── Makefile                # all, clean, fclean, re (entrega obligatorio)
├── minishell.h             # Cabecera principal
├── src/
│   ├── main.c              # Bucle principal: leer → parsear → ejecutar
│   ├── read.c              # Lectura de la línea con readline()
│   ├── parse.c             # Tokenización y construcción de comandos
│   ├── exec.c              # Ejecución: fork, pipes, redirecciones
│   ├── env.c               # Gestión de variables de entorno
│   ├── builtins.c          # Implementación de los builtins
│   └── ...                 # Señales, expander, utils…
└── tests/                  # 🧪 Pruebas manuales del autor
```

## 🛠️ Compilación

```bash
make          # Compila ./minishell
make fclean   # Limpia el proyecto
```

Requiere la librería **readline** para el prompt (`-lreadline`).

## 🚀 Uso y ejemplos

```bash
./minishell

# Dentro de tu shell:
$ echo hola mundo
hola mundo
$ cd /tmp && pwd
/tmp
$ export MY_VAR=42
$ echo $MY_VAR
42
$ ls -la | grep minishell | wc -l
3
$ cat << EOF
hola
EOF
$ echo $?
0
$ exit
```

- ⚠️ El **comando `export` sin argumentos** imprime las variables «declare».
- 🔌 `Ctrl-D` en prompt vacío sale igual que `bash`.

## 🧪 Testers y verificación

| Herramienta | Instalación | Comandos |
|---|---|---|
| **minishell_tester** (LucasKuhn) | `git clone https://github.com/LucasKuhn/minishell_tester.git` | `cd minishell_tester && ./tester` |
| **minitester** (mcombeau) | `git clone https://github.com/mcombeau/minitester-minishell-tester.git` | `cd minitester-minishell-tester && ./minitester` |
| **tests/ casero** | 📁 dentro del repo | `bash tests/run.sh` |
| **norminette** | `pip install norminette` | `norminette src/` |
| **valgrind** | parte del sistema | `valgrind --leak-check=full ./minishell` |

💡 Consejos de evaluación:
- Pascua de **quotes/expansión**: `$USER`, `"$USER"`, `'$USER'`.
- **`$?`** justo después de un error y de `Ctrl-C`.
- Redirecciones con permisos **sudo** / archivos inexistentes.
- pipes con `stdin/stdout` intercambiados (ej: `cat | cat | ls`).

## ✅ Nota

| Resultado | Detalle |
|---|---|
| ⭐ **100/100** | Perfecto |

## 📚 Recursos

- [Subject oficial](https://cdn.intra.42.fr/pdf/pdf/62809/fr.subject.pdf)
- [Cursus C — Índice](../README.md)
- [LucasKuhn · minishell_tester](https://github.com/LucasKuhn/minishell_tester)
- [mcombeau · minitester](https://github.com/mcombeau/minitester-minishell-tester)
- [TinyShell · proyecto base (Aníbal Ibaceta)](https://github.com/Frikardo/TinyShell)