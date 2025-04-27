# BSQ
## Introducción 🚀

El proyecto **BSQ** (Biggest Square) es un desafío de programación diseñado para poner a prueba tus habilidades en el diseño de algoritmos eficientes, la manipulación de estructuras de datos y la optimización de código. Este ejercicio es una excelente oportunidad para mejorar tu capacidad de análisis y resolución de problemas, habilidades esenciales en el desarrollo de software. 💻✨

El objetivo principal del proyecto es desarrollar un programa que sea capaz de analizar una matriz rectangular de caracteres y encontrar el cuadrado más grande posible que cumpla con ciertas condiciones. Este cuadrado debe estar compuesto únicamente por espacios vacíos, evitando obstáculos, y debe ser representado en la salida con un carácter específico. 🟦❌

El proyecto no solo evalúa tu capacidad para implementar una solución funcional, sino también tu habilidad para manejar entradas y salidas de datos, gestionar errores y optimizar el rendimiento del programa. Además, fomenta el uso de buenas prácticas de programación, como la modularidad, la legibilidad del código y la gestión eficiente de recursos. 🛠️📈

## Instrucciones 📋

### 1. Entrada del programa 📝

El programa debe recibir como entrada un archivo de texto que contenga una matriz rectangular de caracteres. Este archivo debe cumplir con el siguiente formato:

- La primera línea del archivo especifica:
    - El número total de filas de la matriz.
    - Los caracteres utilizados para representar:
        - Espacios vacíos.
        - Obstáculos.
        - El cuadrado encontrado.
- Las líneas siguientes contienen la matriz, donde cada carácter representa una celda. Los caracteres deben ser consistentes con los especificados en la primera línea.

Ejemplo de archivo de entrada:

```
9.ox
.........
...o.....
....o....
.........
.........
.........
.........
.........
.........
```

En este ejemplo:
- `.` representa un espacio vacío.
- `o` representa un obstáculo.
- `x` se usará para marcar el cuadrado más grande encontrado.

### 2. Salida del programa 🖨️

El programa debe imprimir la misma matriz recibida como entrada, pero con el cuadrado más grande posible marcado con el carácter especificado en la primera línea del archivo. Si hay múltiples cuadrados del mismo tamaño, se puede marcar cualquiera de ellos.

Ejemplo de salida para el archivo anterior:

```
9.ox
.........
...o.....
....o....
.........
...xxx...
...xxx...
...xxx...
.........
.........
```

### 3. Restricciones ⚠️

Para garantizar el correcto funcionamiento del programa, se deben cumplir las siguientes restricciones:

- **Formato válido**: La matriz debe ser rectangular, es decir, todas las filas deben tener la misma longitud.
- **Gestión de errores**: El programa debe manejar adecuadamente los errores de entrada, como:
    - Archivos inexistentes o inaccesibles.
    - Formato incorrecto en el archivo.
    - Caracteres no válidos en la matriz.
- **Eficiencia**: La solución debe ser lo más eficiente posible, especialmente para matrices grandes. 🕒💡

### 4. Ejecución del programa ▶️

Para compilar y ejecutar el programa, es necesario contar con un archivo `Makefile` que automatice el proceso de compilación. Asegúrate de que tu entorno de desarrollo esté configurado correctamente y que todas las dependencias necesarias estén instaladas. ⚙️

Pasos generales para la ejecución:

1. Asegúrate de que el archivo `Makefile` esté en el mismo directorio que el código fuente del programa.
2. Compila el programa ejecutando el comando `make` en la terminal. Esto generará el ejecutable según las reglas definidas en el `Makefile`.
3. Ejecuta el programa desde la línea de comandos, proporcionando el archivo de entrada como argumento. Por ejemplo:
    ```
    ./bsq input_file.txt
    ```
4. Observa la salida en la terminal o en un archivo de salida, según lo especificado en el proyecto. 🖥️

El uso de un `Makefile` facilita la compilación y asegura que todos los archivos necesarios se compilen correctamente, además de permitir una limpieza sencilla de los archivos generados con el comando `make clean`. 🧹

### 5. Consejos y recomendaciones 💡

- **Divide y vencerás**: Divide el problema en subproblemas más pequeños y resuélvelos de manera incremental. 🧩
- **Pruebas exhaustivas**: Crea múltiples casos de prueba, incluyendo matrices pequeñas, grandes, con muchos obstáculos y sin obstáculos. 🧪
- **Optimización**: Considera el uso de estructuras de datos y algoritmos eficientes para reducir el tiempo de ejecución y el uso de memoria. 🚀
- **Documentación**: Comenta tu código para facilitar su comprensión y mantenimiento. 📝

¡Buena suerte y diviértete resolviendo este emocionante desafío! Recuerda que cada error es una oportunidad para aprender y mejorar. 🌟

## Resultados del Proyecto 📊

A pesar de los esfuerzos realizados, el proyecto **BSQ** no logró cumplir con todos los requisitos establecidos. Aunque se implementaron varias funcionalidades clave, como la lectura del archivo de entrada y la representación de la matriz, el programa no consiguió identificar correctamente el cuadrado más grande en todos los casos de prueba. ❌

### Problemas Identificados 🛑

1. **Errores en la lógica del algoritmo**: 
    - La implementación del algoritmo para encontrar el cuadrado más grande no funcionó correctamente en matrices con múltiples obstáculos o tamaños irregulares.
    - En algunos casos, el programa marcaba cuadrados incorrectos o no encontraba ninguno.

2. **Gestión de errores incompleta**:
    - No se manejaron adecuadamente ciertos errores de entrada, como archivos con formato incorrecto o caracteres no válidos.

3. **Falta de optimización**:
    - El rendimiento del programa fue insuficiente para matrices grandes, lo que resultó en tiempos de ejecución elevados. 🕒

### Lecciones Aprendidas 📚

Aunque el proyecto no se completó con éxito, fue una experiencia valiosa que permitió aprender y mejorar en varios aspectos:

- La importancia de planificar y probar exhaustivamente los algoritmos antes de implementarlos.
- La necesidad de manejar adecuadamente los errores y validar las entradas del programa.
- La utilidad de dividir el problema en partes más pequeñas y abordarlas de manera incremental.

### Próximos Pasos 🔜

Para mejorar el proyecto en el futuro, se podrían considerar las siguientes acciones:

- Revisar y depurar la lógica del algoritmo para garantizar que funcione correctamente en todos los casos.
- Implementar pruebas unitarias y casos de prueba más variados para identificar errores antes. 🧪
- Optimizar el código para mejorar el rendimiento en matrices grandes. 🚀
- Solicitar retroalimentación de compañeros o mentores para identificar áreas de mejora. 🤝

Aunque el proyecto no se completó con éxito, el proceso fue una oportunidad para aprender y crecer como programador. ¡El siguiente desafío será una nueva oportunidad para aplicar lo aprendido y lograr mejores resultados! 🌟