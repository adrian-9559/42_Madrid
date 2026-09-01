# 🎮 philosophers — El problema clásico de la cena de los filósofos

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

**philosophers** introduce la **programación concurrente**: una mesa redonda, `n` filósofos, `n` tenedores y un deadlock esperándote. 🍝

Aquí dejamos de tener un solo hilo: cada filósofo es un **thread** (con `pthread`) que comparte recursos. El reto es evitar **carreras de datos (data races)**, **deadlocks** y **starvation** usando exclusión mutua (`pthread_mutex`).

## 🎯 Objetivos

- 🧵 Crear y sincronizar **threads** con `pthread_create` / `pthread_join`.
- 🔒 Proteger recursos compartidos con **mutex**.
- 🚫 Evitar **data races** y **deadlocks**.
- ⏱️ Bucle "pensar → comer → dormir" con tiempos estrictos.
- 📉 Detección de **muerte** (un filósofo sin comer en `time_to_die` ms).

## 📄 Enunciado

Simula el problema clásico:

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

- 🍽️ Cada filósofo coge sus **dos tenedores** (izq. y der.), come, duerme y piensa.
- 💀 Un filósofo **muere** si pasa `time_to_die` ms sin empezar a comer.
- 📊 La salida es el log: `timestamp_in_ms philosopher_number action`.
- `<N>` (argumento opcional): el sim termina cuando **todos** han comido N veces.
- 🧭 El programa debe **terminar limpio** ante la muerte del primero.

## 🏗️ Estructura

```
philosophers/
├── philo/                  # Programa principal (MUST be race-free)
│   ├── Makefile            # all, clean, fclean, re
│   ├── philo.h             # Prototipos + struct s_philo / s_data
│   ├── philo.c             # Creación de threads y rutina
│   ├── utils.c             # Timestamps, impresión, parsing
│   ├── actions.c           # comer / dormir / pensar
│   └── ...
└── philo_bonus/            # (opcional) versión con procesos y semáforos
```

## 🛠️ Compilación

```bash
cd philo
make          # Compila ./philo
make fclean   # Limpia el proyecto
```

Usa `cc -Wall -Wextra -Werror -pthread`.

## 🚀 Uso y ejemplos

```bash
# 5 filósofos, 800ms sin comer → muerte, 200ms comer, 200ms dormir
./philo 5 800 200 200

# Termina cuando cada filósofo ha comido 7 veces
./philo 5 800 200 200 7

# Casos típicos de evaluación
./philo 1 800 200 200          # 1 filósofo debe morir (200ms → toma 1 tenedor)
./philo 4 410 200 200 10       # sin muertes, termina al llegar a 10 comidas
./philo 2 60 60 60             # muerte en 60ms (timings justos → data race)
```

🎨 Visualizador online: [philosophers-visualizer](https://nafuka11.github.io/philosophers-visualizer/)

## 🧪 Testers y verificación

| Herramienta | Instalación | Comandos |
|---|---|---|
| **42-philosophers-tester** (dantonik) | `git clone https://github.com/dantonik/42-philosophers-tester.git` | `cd 42-philosophers-tester && bash run.sh` |
| **LazyPhilosophersTester** (MichelleJiam) | `git clone https://github.com/MichelleJiam/LazyPhilosophersTester.git` | `cd LazyPhilosophersTester && bash run_test.sh` |
| **philosophers-visualizer** | https://nafuka11.github.io/philosophers-visualizer/ | carga tu `philo` para verlo en vivo |
| **valgrind** | parte del sistema | `valgrind --tool=helgrind ./philo 5 800 200 200` · `valgrind --tool=drd` |
| **norminette** | `pip install norminette` | `norminette philo/` |
```

💡 Consejos clave:
- ⏱️ Los timestamps y "death check" deben usar **monotonic clock** (`gettimeofday` si lo pide el subject).
- 🔒 Una solución sin data races deja al `2 60 60 60` sin muerte prematura.
- 🧹 Terminar sin leaks y sin hilos colgados al detectar la muerte.

## ✅ Nota

| Resultado | Detalle |
|---|---|
| ⭐ **100/100** | Perfecto |

## 📚 Recursos

- [Subject oficial](https://cdn.intra.42.fr/pdf/pdf/62374/fr.subject.pdf)
- [Cursus C — Índice](../README.md)
- [dantonik · 42-philosophers-tester](https://github.com/dantonik/42-philosophers-tester)
- [MichelleJiam · LazyPhilosophersTester](https://github.com/MichelleJiam/LazyPhilosophersTester)
- [Visualizador interactivo](https://nafuka11.github.io/philosophers-visualizer/)