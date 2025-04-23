# Introducción

## Proyectos de lenguaje C en 42 Madrid

Este repositorio contiene una colección de proyectos realizados como parte del programa de formación en 42 Madrid. Cada proyecto está diseñado para desarrollar habilidades en programación en C, siguiendo estrictas normas de codificación y buenas prácticas. A continuación, se describen algunos aspectos clave:

- **Normas estrictas**: Los proyectos deben cumplir con la Norma de 42, asegurando un código limpio, estructurado y sin errores de estilo.
- **Gestión de memoria**: Se requiere una gestión adecuada de la memoria, evitando fugas y liberando todos los recursos asignados.
- **Evaluación rigurosa**: Los proyectos son evaluados tanto por compañeros como por herramientas automatizadas como Deepthought.
- **Bonus y modularidad**: Se fomenta la implementación de funcionalidades adicionales (bonus) en archivos separados, promoviendo la modularidad del código.
- **Uso de Makefiles**: Los proyectos que necesiten de un Makefile deben incluir un Makefile funcional que facilite la compilación y limpieza del entorno de trabajo.

Estos proyectos no solo fortalecen las bases de la programación en C, sino que también preparan a los estudiantes para enfrentar desafíos reales en el desarrollo de software.

## Herramientas opcionales a instalar 

### Norminette

La **Norminette** es una herramienta de análisis estático de código utilizada en la 42 Network para garantizar que el código fuente cumpla con las normas de estilo y convenciones establecidas por la escuela. Estas normas están diseñadas para fomentar la legibilidad, la consistencia y las buenas prácticas en la programación.

Algunos puntos clave que verifica la Norminette incluyen:
- Longitud máxima de líneas y funciones.
- Correcto uso de espacios y tabulaciones.
- Nombres de variables y funciones descriptivos y en el formato adecuado.
- Organización y estructura del código, como el uso correcto de llaves y la separación de funciones.

#### Instalación

1. Clonar el repositorio de github
```bash
git clone https://github.com/42school/norminette.git norminette
```

2. Entrar en el directorio del repositorio clonado
```bash
cd norminette
```

3. Ejecutar el comando de instalación de la herramienta
```bash
python3 -m pip install norminette
```

#### Ejecución

Para ejecutar la Norminette en tu proyecto, puedes usar el siguiente comando en la terminal:

```bash
norminette
```

#### Solución a problemas comunes

Si al ejecutar el comando aparece el error:
```bash
zsh: command not found: norminette
```

Sigue estos pasos para solucionarlo:

1. **Verifica la ruta del ejecutable de Norminette**  
Ejecuta el siguiente comando en tu terminal:
```bash
python3 -m site --user-base
```
Esto debería devolver la ruta base donde se encuentra el ejecutable de **Norminette**. Por ejemplo:
```bash
/Users/adrian_9559/Library/Python/3.9
```

2. **Accede al directorio del ejecutable**  
Cambia al directorio correspondiente utilizando:
```bash
cd /Users/adrian_9559/Library/Python/3.9/bin
```

3. **Añade la ruta al archivo PATH**  
Agrega la ruta del ejecutable al archivo de configuración de tu terminal (`~/.zshrc` o `~/.zprofile` si `~/.zshrc` no funciona):
```bash
echo 'export PATH=$PATH:/Users/adrian_9559/Library/Python/3.9/bin' >> ~/.zshrc
```
Si estás usando `~/.zprofile`, utiliza:
```bash
echo 'export PATH=$PATH:/Users/adrian_9559/Library/Python/3.9/bin' >> ~/.zprofile
```

4. **Aplica los cambios**  
Recarga la configuración de tu terminal para que los cambios surtan efecto:
```bash
source ~/.zshrc
```

5. **Verifica la instalación**  
Comprueba que **Norminette** está correctamente instalado ejecutando:
```bash
norminette --version
```

Si todo está configurado correctamente, deberías ver la versión instalada de **Norminette**.

#### Documentación original

Para más detalles sobre la herramienta Norminette, consulta la [documentación oficial](https://github.com/42school/norminette/tree/master#readme).

### Francinette

La **Francinette** es una herramienta de evaluación automatizada diseñada para probar y validar los proyectos de 42. Permite a los estudiantes verificar el cumplimiento de los requisitos del proyecto y detectar errores antes de la evaluación oficial.

#### Instalación

1. Clonar el repositorio de Francinette:
```bash
git clone https://github.com/WaRtr0/francinette-image.git
```

2. Entrar en el directorio del repositorio clonado:
```bash
cd francinette-image
```

3. Ejecutar el script de instalación:
```bash
bash -c "$(curl -fsSL https://raw.githubusercontent.com/WaRtr0/francinette-image/master/install.sh)"
```

#### Ejecución

Para ejecutar la herramienta, primero asegúrate de estar en el directorio del proyecto. Luego, simplemente utiliza el siguiente comando en tu terminal:

```bash
paco
```
#### Solución a problemas comunes

Si al ejecutar el comando aparece el error:
```bash
zsh: command not found: paco
```

Sigue estos pasos para solucionarlo:

1. **Verifica la ruta del ejecutable de Francinette**  
Ejecuta el siguiente comando en tu terminal:
```bash
python3 -m site --user-base
```
Esto debería devolver la ruta base donde se encuentra el ejecutable de **Francinette**. Por ejemplo:
```bash
/Users/adrian_9559/Library/Python/3.9
```

2. **Accede al directorio del ejecutable**  
Cambia al directorio correspondiente utilizando:
```bash
cd /Users/adrian_9559/Library/Python/3.9/bin
```

3. **Añade la ruta al archivo PATH**  
Agrega la ruta del ejecutable al archivo de configuración de tu terminal (`~/.zshrc` o `~/.zprofile` si `~/.zshrc` no funciona):
```bash
echo 'export PATH=$PATH:/Users/adrian_9559/Library/Python/3.9/bin' >> ~/.zshrc
```
Si estás usando `~/.zprofile`, utiliza:
```bash
echo 'export PATH=$PATH:/Users/adrian_9559/Library/Python/3.9/bin' >> ~/.zprofile
```

4. **Aplica los cambios**  
Recarga la configuración de tu terminal para que los cambios surtan efecto:
```bash
source ~/.zshrc
```

5. **Verifica la instalación**  
Comprueba que **Francinette** está correctamente instalado ejecutando:
```bash
paco --version
```

Si todo está configurado correctamente, deberías ver la versión instalada de **Francinette**.

#### Documentación original

Para más detalles sobre la herramienta Francinette, consulta la [documentación oficial](https://github.com/xicodomingues/francinette/tree/master#readme).

### LibftTester

El **LibftTester** es una herramienta automatizada diseñada para probar la biblioteca **Libft**, uno de los proyectos fundamentales en 42. Este tester verifica la funcionalidad y el cumplimiento de los requisitos de las funciones implementadas en el proyecto.

#### Instalación

1. Clonar el repositorio de LibftTester dentro de la carpeta del proyecto de Libft:
```bash
git clone https://github.com/Tripouille/libftTester.git
```

2. Entrar en el directorio del repositorio clonado:
```bash
cd libftTester
```

#### Ejecución

Para ejecutar el tester, asegúrate de que el archivo `Makefile` de tu proyecto **Libft** esté en el mismo directorio que el tester. Luego, utiliza el siguiente comando:

```bash
make a
```

Si solo deseas ejecutar las pruebas para las funciones obligatorias, utiliza el siguiente comando:

```bash
make m
```

Esto ejecutará únicamente las pruebas relacionadas con las funciones requeridas por el proyecto, permitiéndote enfocarte en los requisitos mínimos necesarios para la evaluación.

#### Documentación original

Para más detalles sobre el uso de **LibftTester**, consulta la [documentación oficial](https://github.com/Tripouille/libftTester#readme).