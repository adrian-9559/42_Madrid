# 🧵 philo → Implementación del proyecto

> 📘 Documentación principal → [../README.md](../README.md)

Esta carpeta contiene la implementación del proyecto **philosophers** en su versión obligatoria (threads + mutexes).

## 🗂️ Archivos

| Archivo | Descripción |
|---|---|
| `main.c` | Validación de argumentos y construcción de la simulación |
| `src/ft_philosophers.c` | Spawn de los hilos filósofo y del monitor |
| `src/philosophers/ft_philo_routine.c` | Ciclo de vida (comer, dormir, pensar) |
| `src/philosophers/ft_take_forks_and_eat.c` | Toma de tenedores y lógica de comida |
| `src/philosophers/ft_monitor.c` | Detección de muerte y fin de la simulación |
| `src/philosophers/ft_create_philosophers.c` / `ft_destroy_philosophers.c` | Gestión de la lista enlazada |
| `src/philosophers/ft_spawn_philosophers.c` | Creación de threads |
| `src/philosophers/ft_print_status.c` | Salida con timestamp |
| `src/forks/` | Helpers para coger/soltar tenedores |
| `src/time/` | Utilidades de tiempo (`gettimeofday`, sleep en ms) |
| `src/data/` | Configuración y limpieza de la simulación |
| `src/thread/` `src/mutex/` `src/utils/` `src/print/` | Utilidades de apoyo |

## 🛠️ Compilación y ejecución

```bash
make
./philo <n_filosofos> <time_to_die> <time_to_eat> <time_to_sleep> [n_comidas]
```

### Ejemplo

```bash
./philo 5 800 200 200
```

## 📝 Notas de implementación

- 🧵 Cada filósofo es un **thread** (`pthread`); cada tenedor, un **mutex** (`pthread_mutex_t`).
- 👁️ Un **thread monitor** consulta el estado de los filósofos y detiene la simulación ante muerte o «todos han comido».
- ⚖️ Los filósofos de índice **par** arrancan escalonados para evitar contención de tenedores.
- 🧠 Con **número impar** de filósofos se añade pensar extra para evitar el deadlock.

## 🧪 Verificación

```bash
cd ..
make
./philo 5 800 200 200
valgrind --tool=helgrind ./philo/philo 5 800 200 200
```