```markdown
# CPP Module 02 — Recursos avanzados y STL

Objetivo

Profundizar en templates, containers de la STL, algoritmos y técnicas modernas que permiten escribir código genérico, eficiente y reutilizable.

Temas principales

- Templates de funciones y clases.
- Contenedores de la STL: `vector`, `list`, `map`, `set`.
- Algoritmos estándar (`<algorithm>`) y adaptadores.
- Smart pointers: `std::unique_ptr`, `std::shared_ptr`.
- Manejo avanzado de excepciones y diseño de API segura.

Ejercicios típicos

- Implementar clases genéricas con templates.
- Resolver problemas usando `std::vector` y algoritmos (`std::sort`, `std::find`, etc.).
- Reescribir estructuras propias usando la STL para comparar rendimiento y simplicidad.

Consejos de desarrollo

- Prefiere `std::vector` sobre arrays crudos cuando sea posible.
- Usa `const` y referencias para evitar copias innecesarias.
- Aprovecha los iteradores y algoritmos estándar para mantener código conciso.

```

## Instrucciones generales para proyectos C++

Incluye las siguientes reglas y recomendaciones en cada README de ejercicio C++:

1) Compiling
- Compile your code with `c++` and the flags `-Wall -Wextra -Werror`.
- Your code should still compile if you add the flag `-std=c++98`.

2) Formatting and naming conventions
- The exercise directories will be named this way: `ex00`, `ex01`, ..., `exn`.
- Name your files, classes, functions, member functions and attributes as required in the guidelines.
- Write class names in UpperCamelCase format. Files containing class code will always be named according to the class name. For instance: `ClassName.hpp`/`ClassName.h`, `ClassName.cpp`, or `ClassName.tpp`. Example: a header for class `BrickWall` will be `BrickWall.hpp`.
- Unless specified otherwise, every output message must end with a newline character and be displayed to the standard output.
- Goodbye Norminette! No coding style is enforced in the C++ modules. You can follow your favorite one, but write clean and readable code.

3) Allowed / Forbidden
- You are not coding in C anymore. Time to C++! You are allowed to use almost everything from the standard library. Use the C++-ish versions of C functions when possible.
- You can’t use any other external library. C++11 (and derived forms) and Boost libraries are forbidden. The following functions are forbidden too: `*printf()`, `*alloc()` and `free()`.

4) Module-specific restrictions (Module 02 example)
- Note that unless explicitly stated otherwise, the `using namespace <ns_name>` and `friend` keywords are forbidden.
- You are allowed to use the STL only in Modules 08 and 09. That means: no Containers (vector/list/map, etc.) and no Algorithms (anything requiring `<algorithm>`) until then.

5) A few design requirements
- Avoid memory leaks when using `new`; free allocated memory appropriately.
- From Module 02 to Module 09, design classes in the Orthodox Canonical Form unless stated otherwise.
- Any function implementation put in a header file (except for function templates) means 0 to the exercise.
- Headers must be independently usable and include their dependencies. Protect against double inclusion with include guards.

6) Read me
- You can add additional files if needed (to split code), but submit the mandatory files.
- Read each module completely before starting and follow the examples in the guidelines.

Use this block as a template to paste into every `CPP_Module_*` README.

## Instrucciones generales para proyectos C++ (ES)

Incluye las siguientes reglas y recomendaciones en cada `README` de ejercicio C++:

1) Compilación
- Compila tu código con `c++` y las banderas `-Wall -Wextra -Werror`.
- Tu código debe seguir compilando si añades la bandera `-std=c++98`.

2) Formato y convenciones de nombres
- Los directorios de los ejercicios se nombrarán así: `ex00`, `ex01`, ..., `exn`.
- Nombra tus archivos, clases, funciones, métodos y atributos según las pautas del enunciado.
- Escribe los nombres de las clases en formato UpperCamelCase. Los ficheros que contienen el código de una clase deberán llamarse según el nombre de la clase: `ClassName.hpp`/`ClassName.h`, `ClassName.cpp` o `ClassName.tpp`.
- Salvo indicación contraria, cada mensaje de salida debe terminar con un carácter de nueva línea y mostrarse por la salida estándar.
- ¡Adiós Norminette! No se impone una guía de estilo en los módulos de C++; puedes seguir tu preferida, pero escribe código claro y legible.

3) Permitido / Prohibido
- Ya no programas en C, ahora en C++: se permite usar casi todo de la biblioteca estándar. Emplea las versiones C++ de las funciones C cuando corresponda.
- No se permiten librerías externas. C++11 (y derivados) y Boost están prohibidos. También están prohibidas las funciones `printf()`, `alloc()` y `free()` (y sus variantes).

4) Restricciones por módulo (ej. Módulo 02)
- Salvo indicación explícita, `using namespace <ns_name>` y la palabra clave `friend` están prohibidas.
- La STL solo se permite en los Módulos 08 y 09. Es decir: no usar Containers (vector/list/map, etc.) ni Algorithms (cualquier cosa que requiera `<algorithm>`) hasta esos módulos.

5) Requisitos de diseño
- Evita fugas de memoria al usar `new`; libera la memoria asignada correctamente.
- Desde el Módulo 02 hasta el Módulo 09, las clases deben diseñarse en la Forma Canónica Ortodoxa (regla de tres/cinco), salvo que el enunciado indique lo contrario.
- Cualquier implementación de función en un fichero header (excepto plantillas) conlleva 0 en el ejercicio.
- Los headers deben ser independientes: incluir sus dependencias y protegerse contra inclusiones múltiples mediante include guards.

6) README
- Puedes añadir ficheros adicionales si los necesitas (por ejemplo para separar código), pero entrega siempre los ficheros obligatorios.
- Lee cada módulo completo antes de empezar y presta atención a los ejemplos del enunciado.

Usa este bloque como plantilla para pegarlo en cada `CPP_Module_*` `README`.
