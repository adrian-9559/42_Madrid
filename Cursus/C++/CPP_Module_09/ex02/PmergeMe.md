# PmergeMe — Merge-Insertion Sort (Ford-Johnson)

## Descripción

PmergeMe implementa el algoritmo **merge-insertion sort** (también conocido como **Ford-Johnson**) utilizando dos contenedores STL diferentes: `std::vector` y `std::deque`. El programa recibe una secuencia de enteros positivos por línea de comandos, los ordena usando ambos contenedores y muestra los tiempos de ejecución de cada uno.

El objetivo de este ejercicio de **42 Network** es demostrar que la elección del contenedor impacta en el rendimiento, incluso usando exactamente el mismo algoritmo.

## Compilación

```bash
make        # compila el ejecutable PmergeMe
make re     # recompila desde cero
make clean  # elimina los .o
make fclean # elimina .o y el ejecutable
```

## Uso

```bash
./PmergeMe <n1> <n2> ... <nN>
```

Cada argumento puede contener uno o varios números separados por espacios. Solo se aceptan enteros positivos (con o sin prefijo `+`). No se permiten duplicados, negativos, cero ni valores fuera del rango de `int`.

### Salida

```
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::vector : 32.00000 us
Time to process a range of 5 elements with std::deque : 13.00000 us
```

## Ejemplos

### Uso básico

```bash
./PmergeMe 3 5 9 7 4
./PmergeMe 42 21 84 63
./PmergeMe "10 3" "8 1"      # múltiples tokens por argumento
./PmergeMe +10 +3 +8 +1       # con signo '+'
./PmergeMe 2147483647 1 42    # valores grandes (INT_MAX)
```

### Números aleatorios con `shuf`

```bash
# 10 números aleatorios del 1 al 100
shuf -i 1-100 -n 10 | tr '\n' ' ' | xargs ./PmergeMe

# 50 números aleatorios del 1 al 1000
shuf -i 1-1000 -n 50 | tr '\n' ' ' | xargs ./PmergeMe

# 100 números aleatorios
shuf -i 1-10000 -n 100 | tr '\n' ' ' | xargs ./PmergeMe

# 500 números aleatorios
shuf -i 1-100000 -n 500 | tr '\n' ' ' | xargs ./PmergeMe

# 1000 números aleatorios
shuf -i 1-100000 -n 1000 | tr '\n' ' ' | xargs ./PmergeMe

# 3000 números (prueba de estrés)
shuf -i 1-10000000 -n 3000 | tr '\n' ' ' | xargs ./PmergeMe
```

> **Nota:** En macOS `shuf` viene con coreutils (`brew install coreutils`) o puedes usar `sort -R`:
> ```bash
> seq 1 1000 | sort -R | tr '\n' ' ' | xargs ./PmergeMe
> ```

### Contando el tiempo

Si quieres medir solo el tiempo del algoritmo sin contar el parsing:

```bash
time shuf -i 1-10000 -n 5000 | tr '\n' ' ' | xargs ./PmergeMe
```

## Tests

```bash
./test.sh
```

Ejecuta 38 tests que cubren: errores de entrada, casos borde, escala (10–1000 números), validación exhaustiva con 1016 sub-tests en C++, formato de salida y consistencia.

---

## Cómo funciona el algoritmo

El merge-insertion sort (Ford-Johnson) es un algoritmo de ordenación por comparación que minimiza el número de comparaciones en el peor caso. Fue diseñado para ser **óptimo en número de comparaciones** para ciertos tamaños de entrada.

### Paso a paso

#### 1. Emparejamiento

Se recorre la secuencia formando pares `(a, b)`:

```
Input:    [7, 1, 4, 8, 2, 6, 3]
Pares:    (7,1), (4,8), (2,6)
Resto:    3 (straggler)
```

Dentro de cada par se coloca el **mayor primero**: si `a < b` se intercambian, de modo que `pair.first >= pair.second`.

```
(7,1) → (7,1)   ✓
(4,8) → (8,4)   ✓
(2,6) → (6,2)   ✓
```

Si la secuencia tiene un número impar de elementos, el último elemento sobrante se llama **straggler** y se trata aparte.

#### 2. Ordenar pares por el mayor

Se ordenan los pares por su **primer elemento** (el mayor de cada par) usando `std::sort`:

```
Antes:  (7,1), (8,4), (6,2)
Después: (6,2), (7,1), (8,4)
```

#### 3. Secuencia principal inicial

Se construye la secuencia resultado insertando:

1. El **segundo elemento del primer par** → `result = [2]`
2. El **primer elemento del primer par** → `result = [2, 6]`
3. Los **primeros elementos del resto de pares** en orden → `result = [2, 6, 7, 8]`

Esto garantiza que la secuencia `S = [b0, a0, a1, a2, ..., ak]` está ordenada (porque los `a_i` están ordenados y `a_i > b_i`).

#### 4. Insertar los segundos elementos restantes

Faltan por insertar los segundos elementos: `b1, b2, ...` (y el straggler si existe).

Para minimizar comparaciones, se usa el **orden de Jacobsthal**. Los números de Jacobsthal son:

```
J(n) = { 1, 3, 5, 11, 21, 43, 85, 171, ... }
```

La secuencia de inserción se construye así:

```
Jac(n)      : 1,    3,     5,     11,     21, ...
Orden insert: 1,  3,2,  5,4,  11,10,...,6,  21,20,...,12, ...
```

Es decir, para cada número de Jacobsthal `J(k)` se insertan los índices desde `J(k)` hacia abajo hasta el número de Jacobsthal anterior más uno.

```
N = 3 pares → índices: [1, 3, 2]
```

Se inserta cada `b[pairIndex]` usando **búsqueda binaria** (`std::upper_bound`), que es O(log n).

#### 5. Insertar el straggler

Si hay un elemento sobrante (straggler), se inserta al final con búsqueda binaria.

### ¿Por qué Jacobsthal?

Los números de Jacobsthal provienen de la recurrencia:

```
J(n) = J(n-1) + 2·J(n-2),  con J(0) = 0, J(1) = 1
```

Esta secuencia surge naturalmente al analizar cuántos elementos se pueden insertar con un número dado de comparaciones. Insertar en orden Jacobsthal garantiza que, para cada inserción, el rango de búsqueda binaria sea lo más grande posible, aprovechando al máximo las comparaciones ya realizadas.

### Complejidad

- **Comparaciones en peor caso:** ~n·log₂(n) — cercano al óptimo teórico.
- **Intercambios/inserciones:** O(n·log₂(n)) por el uso de búsqueda binaria.
- **Memoria:** O(n) — se crean copias de los contenedores.

### Diferencia vector vs deque

| Operación | `std::vector` | `std::deque` |
|-----------|---------------|--------------|
| `push_back` | O(1) amortizado | O(1) |
| `insert` en medio | O(n) — desplaza elementos | O(n) — peor que vector en la práctica |
| Acceso por índice | O(1) — contiguo | O(1) — dos niveles indirección |
| `std::sort` | O(n·log n) — iterator RA | O(n·log n) — iterator random access |
| `std::upper_bound` | O(log n) — RA iterator | O(log n) — se degrada a lineal si no es RA |

La principal diferencia con `std::deque` es que **no tiene iteradores de acceso aleatorio verdaderos** (son iteradores de acceso aleatorio simulados), por lo que algoritmos como `std::upper_bound` que saltan por la secuencia pueden ser más lentos que en `std::vector`.

### Visualización

```
Input:  [7, 1, 4, 8, 2, 6, 3]

Pares:   (7,1)  (8,4)  (6,2)     straggler=3
          swap   swap   swap
         (7,1)  (8,4)  (6,2)

Ordenar por first:
         (6,2)  (7,1)  (8,4)

Main chain:  [2, 6, 7, 8]

Insertar b's en orden Jacobsthal [1, 3, 2]:
  1 → binary_search en [2,6,7,8] → insertar 1 → [1,2,6,7,8]
  3 → no existe (solo 3 pares, índice 3 >= 3) → skip
  2 → binary_search en [1,2,6,7,8] → insertar 4 → [1,2,4,6,7,8]

Insertar straggler=3:
  3 → binary_search → [1,2,3,4,6,7,8]

Result: [1, 2, 3, 4, 6, 7, 8]
```

## Estructura del proyecto

```
src/
├── class/PmergeMe/
│   ├── PmergeMe.hpp    # declaración de la clase
│   └── PmergeMe.cpp    # implementación (parsing, impresión)
└── templates/
    ├── PairFirstLess.tpp           # functor de comparación
    ├── buildJacobsthalOrder.tpp    # genera orden de Jacobsthal
    └── mergeInsertionSort.tpp      # algoritmo Ford-Johnson
main.cpp                            # punto de entrada
test.sh                             # suite de pruebas
Makefile
```
