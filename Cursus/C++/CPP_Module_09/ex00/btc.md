# btc — Bitcoin Exchange

## Descripción

**btc** es una calculadora de tipo de cambio de Bitcoin. Lee una base de datos histórica (`data.csv`) con el precio de Bitcoin por fecha, procesa un archivo de entrada con fechas y cantidades, y muestra el valor convertido según el tipo de cambio más cercano disponible.

El programa valida cada línea del archivo de entrada: formato de fecha (YYYY-MM-DD), que sea una fecha real válida (incluyendo años bisiestos), y que el valor esté entre 0 y 1000.

## Compilación

```bash
make        # compila el ejecutable btc
make re     # recompila desde cero
make clean  # elimina los .o
make fclean # elimina .o y el ejecutable
```

## Uso

```bash
./btc <input.txt>
```

El archivo de entrada debe tener el formato:

```
date | value
```

### Ejemplos

```
$ cat input.txt
date | value
2011-01-03 | 3
2011-01-03 | 2
2011-01-03 | 1
2011-01-03 | 1.2
2011-01-09 | 1
2012-01-11 | -1
2001-42-42
2012-01-11 | 1
2012-01-11 | 2147483648
```

```bash
./btc input.txt
```

```
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3
2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
2012-01-11 => 1 = 0.29
Error: too large a number.
```

### Formato de salida

```
<date> => <value> = <resultado>
```

### Posibles errores

| Mensaje | Causa |
|---------|-------|
| `Error: could not open file.` | No se puede abrir el archivo de entrada |
| `Error: bad input => <línea>` | Formato incorrecto o fecha inválida |
| `Error: not a positive number.` | Valor negativo |
| `Error: too large a number.` | Valor mayor a 1000 |
| `Error: no data available for date <fecha>` | No hay datos históricos para esa fecha |

### Nota sobre fechas sin datos

Si el archivo `data.csv` no tiene una entrada exacta para la fecha solicitada, el programa busca la **fecha anterior más cercana** disponible. Por ejemplo, si pides `2011-01-09` y el CSV tiene `2011-01-08`, usará ese precio.

## Tests

Puedes probar el programa con archivos como:

```bash
# Ejemplo básico
echo -e "date | value\n2021-01-03 | 2" > /tmp/test.txt
./btc /tmp/test.txt

# Valores con decimales
echo -e "date | value\n2021-01-03 | 1.5" > /tmp/test.txt
./btc /tmp/test.txt

# Fechas sin datos
echo -e "date | value\n2008-01-01 | 1" > /tmp/test.txt
./btc /tmp/test.txt

# Error: negativo
echo -e "date | value\n2021-01-03 | -5" > /tmp/test.txt
./btc /tmp/test.txt

# Error: valor muy grande
echo -e "date | value\n2021-01-03 | 1001" > /tmp/test.txt
./btc /tmp/test.txt

# Error: formato incorrecto
echo -e "date | value\nhola mundo" > /tmp/test.txt
./btc /tmp/test.txt
```

## Cómo funciona

### 1. Carga de la base de datos

El constructor de `BitcoinExchange` abre `data.csv` y carga cada línea en un `std::map<std::string, double>`:

```
"2009-01-02" → 0.0
"2009-01-03" → 0.0
...
"2022-03-29" → 47481.29
```

Se usa `std::map` porque mantiene las claves ordenadas, lo que permite búsquedas por rango.

### 2. Parsing del archivo de entrada

`main.cpp` procesa línea por línea:

1. Busca el separador `|`
2. Extrae y recorta la fecha y el valor
3. Reemplaza comas por puntos en el valor (formato europeo)
4. Valida la fecha con `isValidDate()`:
   - Longitud 10, guiones en posiciones 4 y 7
   - Todos dígitos en las posiciones correctas
   - Mes entre 1 y 12
   - Día válido para ese mes (incluyendo 29/2 en años bisiestos)
5. Valida el valor: positivo y ≤ 1000

### 3. Búsqueda del tipo de cambio

`getPriceByDate()` usa `std::map::lower_bound()`:

```cpp
std::map<std::string, double>::iterator it = _prices.lower_bound(date);
```

- Si encuentra la fecha exacta: usa ese precio
- Si `lower_bound` apunta al primer elemento mayor que la fecha: retrocede uno (techo → piso)
- Si `lower_bound` apunta al principio (todas las fechas son mayores): error, no hay datos

### 4. Cálculo

```
resultado = valor * precio_bitcoin_en_esa_fecha
```

### Complejidad

- **Carga:** O(n · log n) — inserción en `std::map`
- **Búsqueda:** O(log n) por consulta — `lower_bound` en árbol balanceado

## Estructura del proyecto

```
src/
└── class/BitcoinExchange/
    ├── BitcoinExchange.hpp   # declaración de la clase
    └── BitcoinExchange.cpp   # implementación
main.cpp                      # punto de entrada
data.csv                      # base de datos histórica (2009-2022)
Makefile
```

## Referencia

- [Bitcoin historical data (CoinDesk)](https://www.coindesk.com/price/bitcoin/)
- Estándar: **C++98**
