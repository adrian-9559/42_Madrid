# minishell

## 🌟 Introducción

El proyecto `minishell` consiste en implementar una shell mínima en C que soporte ejecución de comandos, redirecciones, pipes y builtins básicos. Es un ejercicio práctico para comprender procesos, descriptores y la interacción entre programas y el sistema operativo.

Trabajar en este proyecto mejora tu capacidad para diseñar código modular, manejar errores y garantizar un comportamiento robusto ante casos reales.

## Índice

- [Instrucciones generales](#-instrucciones-generales)
- [Enunciado](#-enunciado)
- [Reglas y restricciones](#-reglas-y-restricciones)
- [Uso y ejemplos](#-uso-del-programa)
- [Tester incluido](#-tester-incluido)
- [Estructura del código](#-estructura-del-código)
- [Herramientas recomendadas](#-herramientas-recomendadas)
- [Entrega](#-entrega)

## 📋 Instrucciones generales

- El proyecto debe ser escrito en C.
- Compila con `cc` y flags `-Wall -Wextra -Werror`.
- Sigue la Norma (norminette); las infracciones pueden invalidar la entrega.
- El `Makefile` debe contener: `all`, `$(NAME)`, `clean`, `fclean`, `re`. Evita relink innecesario.
- No debe haber fugas de memoria (valgrind / ASan recomendados).
- Si incluyes `libft`, ponla en `libft/` y compílala antes del proyecto.

## 📄 Enunciado

Implementa una shell interactiva `minishell` que soporte:

- Ejecución de comandos externos con `execve` y búsqueda en `$PATH`.
- Redirecciones: `<`, `>`, `>>`.
- Tuberías encadenadas (`|`).
- Builtins: `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`.
- Manejo correcto del código de salida (`$?`).
- Gestión de `SIGINT` y `SIGQUIT` en modo interactivo.

### Objetivos de aprendizaje

- Entender creación y sincronización de procesos (`fork`, `execve`, `wait`).
- Gestionar redirecciones y pipes manipulando descriptores.
- Implementar un parser con soporte de comillas, escapes y expansión de variables.

## 📚 Reglas y restricciones

- No usar funciones prohibidas por la evaluación.
- No debe provocar segfaults en condiciones normales.
- Liberar correctamente la memoria.

Comportamientos avanzados como `&&`, `||` o globbing completo son opcionales y se consideran bonus.

## 🚀 Uso del programa

Compila y ejecuta:

```bash
make
./minishell
```

Ejemplos:

```bash
minishell$ echo hello
hello
minishell$ printf 'one\ntwo\n' | wc -l
2
minishell$ export X=42
minishell$ echo $X
42
minishell$ cat <<EOF
heredoc-line
EOF
heredoc-line
```

## ✅ Criterios de evaluación

- Compila sin warnings (warnings tratados como errores).
- Ejecuta correctamente comandos, redirecciones y pipes.
- Implementa los builtins obligatorios.
- No falla en escenarios normales (robustez).
- Gestión de memoria adecuada (sin leaks).

## 🧪 Tester incluido

La carpeta `tests/` contiene un tester que ejecuta la `minishell` en un PTY y compara la salida con las expectativas definidas en `tests/test_cases.txt`.

- Runner: `tests/run_tests.sh`.
- Casos: `tests/test_cases.txt` (bloques `---test---` con `name`, `input`, `output`).
- Artefactos: `tests/.minitest/` (temporal) y `tests/logs/run_<timestamp>.log`.

Ejecuta el tester:

```bash
make
TEST_PROMPT_TIMEOUT=4.0 ./tests/run_tests.sh --verbose
```

Consulta `tests/README.md` para detalles del formato y variables disponibles.

## 🏗️ Estructura del código

Ejemplo de organización recomendada:

- `src/` — código fuente (parser, executor, builtins, redirections, utils).
- `include/` — cabeceras internas.
- `libft/` — (opcional) biblioteca propia si la usas.
- `tests/` — runner, casos y logs.

Sugerencia de módulos:

- `src/parser/`: tokenización, manejo de comillas, here-docs.
- `src/exec/`: fork/exec, pipes, redirecciones.
- `src/builtins/`: `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`.
- `src/signals/`: manejo de señales.

## 🛠️ Herramientas recomendadas

- Valgrind / AddressSanitizer — detectar fugas y errores de memoria.
- Norminette — comprobar estilo y conformidad con la Norma.
- GDB / lldb — depuración.

## 📦 Entrega

- Sube el repo a tu cuenta de Git.
- Asegúrate de que `make` produce `minishell` en la raíz.
- Incluye este `README.md` y notas de diseño si procede.

---
Consejo: documenta diferencias de comportamiento respecto a `bash` (por ejemplo `echo`).
