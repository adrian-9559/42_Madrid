# C Piscine - C 07

## Introducción
Este módulo introduce la gestión de memoria dinámica en C. Aprenderás a usar malloc para reservar memoria en tiempo de ejecución, crear rangos de enteros, y concatenar múltiples cadenas. La memoria dinámica es esencial para escribir programas flexibles que se adapten a datos de tamaño variable.

## Instrucciones
- Esta página será la única referencia: no te fíes de los rumores.
- ¡Ten cuidado! Los enunciados pueden cambiar en cualquier momento.
- Los ejercicios han sido ordenados con mucha precisión, del más sencillo al más complejo. En ningún caso se tendrá en cuenta un ejercicio complejo si no se ha conseguido realizar perfectamente un ejercicio más sencillo.
- Asegúrate de que tus directorios y archivos tienen los permisos adecuados.
- Debes respetar el procedimiento de entrega para todos tus ejercicios.
- Tus compañeros de piscina se encargarán de corregir tus ejercicios.
- Además de por tus compañeros, también serán corregidos por un programa que se llama la Moulinette.
- La Moulinette es muy estricta a la hora de evaluar. Está completamente automatizada. Es imposible discutir con ella sobre tu nota. Por lo tanto, sé extremadamente riguroso para evitar cualquier sorpresa.
- La Moulinette no tiene una mente muy abierta. No intenta comprender el código que no respeta la Norma. La Moulinette utiliza el programa norminette para comprobar La Norma en tus archivos. Entiende entonces que es estúpido entregar un código que no pase la norminette.
- El uso de una función prohibida se considera una trampa. Cualquier trampa será sancionada con la nota -42.
- Solamente hay que entregar una función main() si lo que se pide es un programa.
- La Moulinette compila con los flags -Wall -Wextra -Werror y utiliza cc.
- Si tu programa no compila, tendrás un 0.
- No puedes dejar en tu directorio ningún archivo que no se haya indicado de forma explícita en los enunciados de los ejercicios.
- ¿Tienes alguna pregunta? Pregunta a tu compañero de la derecha. Si no, prueba con tu compañero de la izquierda.

## Ejercicios

### [ex00: ft_strdup](./ex00/ft_strdup.c)
Escribe una función que duplique una cadena usando malloc.

### [ex01: ft_range](./ex01/ft_range.c)
Escribe una función que devuelva un array de enteros con todos los valores entre dos límites.

### [ex02: ft_ultimate_range](./ex02/ft_ultimate_range.c)
Escribe una función que devuelva un array de enteros con un rango, usando un puntero doble.

### [ex03: ft_strjoin](./ex03/ft_strjoin.c)
Escribe una función que concatene un array de cadenas en una sola, separándolas con un separador.
