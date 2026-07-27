# RPN — Reverse Polish Notation Calculator

## Descripción

**RPN** implementa una calculadora de **notación polaca inversa** (RPN). Evalúa expresiones matemáticas donde los operandos preceden a los operadores, usando una pila interna (`std::stack<int>`).

Soporta las cuatro operaciones básicas: suma (`+`), resta (`-`), multiplicación (`*`) y división entera (`/`). Los operandos son dígitos del 0 al 9.

## Compilación

```bash
make        # compila el ejecutable RPN
make re     # recompila desde cero
make clean  # elimina los .o
make fclean # elimina .o y el ejecutable
```

## Uso

```bash
./RPN "<expresión>"
```

La expresión debe contener dígitos (0–9) y operadores (`+`, `-`, `*`, `/`) separados por espacios.

### Ejemplos

```bash
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
# Output: 42

./RPN "7 7 * 7 -"
# Output: 42

./RPN "1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /"
# Output: 15

./RPN "3 4 +"
# Output: 7

./RPN "9 8 * 5 * 4 *"
# Output: 1440

./RPN "3 4 5 * +"
# Output: 23    (3 + 4*5 = 23)

./RPN "9 3 /"
# Output: 3

./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
# Output: 42
```

### Errores

```bash
./RPN "(1 + 2)"
# Error

./RPN "1 2 + 3"
# Error  (demasiados números al final)

./RPN "5 0 /"
# Error  (división entre cero)
```

## Cómo funciona

### Notación Polaca Inversa (RPN)

En RPN los operadores **van después** de sus operandos:

| Infija | RPN |
|--------|-----|
| `3 + 4` | `3 4 +` |
| `3 + 4 × 5` | `3 4 5 * +` |
| `(8 × 9) - 9 - 9 - 9 - 4 - 1 + 5` | `8 9 * 9 - 9 - 9 - 4 - 1 +` |

Ventajas:
- No necesita paréntesis
- No hay reglas de precedencia que gestionar
- Se evalúa en un solo paso lineal

### Algoritmo

Se recorre la expresión de izquierda a derecha:

```
Expresión: "3 4 5 * +"

Token  "3" → push(3)          Pila: [3]
Token  "4" → push(4)          Pila: [3, 4]
Token  "5" → push(5)          Pila: [3, 4, 5]
Token  "*" → pop(5), pop(4)   Pila: [3]
             4 * 5 = 20
             push(20)          Pila: [3, 20]
Token  "+" → pop(20), pop(3)  Pila: []
             3 + 20 = 23
             push(23)          Pila: [23]

Resultado: 23
```

### Implementación

```cpp
int RPN::compute(const char op)
{
    int num1 = _stack.top(); _stack.pop();
    int num2 = _stack.top(); _stack.pop();
    int result;

    switch (op)
    {
        case '+': result = num2 + num1; break;
        case '-': result = num2 - num1; break;
        case '*': result = num2 * num1; break;
        case '/':
            if (num1 == 0) return (0);  // Error: división por cero
            result = num2 / num1;
            break;
    }
    _stack.push(result);
    return (1);
}
```

> **Orden:** se desempaqueta `num1` (tope) y `num2` (segundo). Para la resta y división el orden importa: `num2 - num1` y `num2 / num1`.

### Validaciones

- Si al final la pila no tiene exactamente 1 elemento → `Error`
- Si en algún momento faltan operandos para un operador → `Error`
- Si se intenta dividir por cero → `Error`
- Caracteres no válidos (ni dígito ni operador ni espacio) → `Error`

### Complejidad

- **Tiempo:** O(n) — un solo recorrido lineal
- **Espacio:** O(n) — en el peor caso todos los operandos están en la pila antes de usar operadores

## Tests

```bash
# Básicos
./RPN "3 4 +"          # 7
./RPN "9 3 /"          # 3
./RPN "2 3 *"          # 6
./RPN "5 3 -"          # 2

# Compuestos
./RPN "3 4 5 * +"      # 23  (3 + 20)
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"  # 42

# Errores
./RPN ""               # Error
./RPN "1 +"            # Error (faltan operandos)
./RPN "1 2 3 +"        # Error (sobra un operando)
./RPN "5 0 /"          # Error (división por cero)
./RPN "a b +"          # Error (caracter inválido)
```

## Estructura del proyecto

```
src/
└── class/RPN/
    ├── RPN.hpp   # declaración de la clase
    └── RPN.cpp   # implementación
main.cpp          # punto de entrada
Makefile
```

## Referencia

- [Reverse Polish Notation — Wikipedia](https://en.wikipedia.org/wiki/Reverse_Polish_notation)
- Estándar: **C++98**
