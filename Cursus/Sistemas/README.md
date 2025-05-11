# Introducción

Este documento tiene como objetivo ser tu compañero ideal en el emocionante viaje por el mundo de la administración de sistemas y las herramientas de virtualización, esenciales para los proyectos del programa de formación en **42 Madrid**. Aquí encontrarás:

📌 **Instrucciones claras**: Aprende a instalar y configurar herramientas como **VirtualBox** y **VMware**.  
💡 **Consejos prácticos**: Soluciona problemas comunes y optimiza tus entornos virtuales.  
📚 **Recursos útiles**: Accede a documentación oficial, tutoriales y comandos esenciales.  
🚀 **Proyectos destacados**: Descubre cómo estos conocimientos se aplican en desafíos reales del área de sistemas.

Prepárate para desarrollar habilidades clave en administración de sistemas, virtualización y configuración de entornos, mientras sigues las mejores prácticas y normas de calidad. ¡Es hora de llevar tus conocimientos al siguiente nivel! 🌐💻✨

## Máquinas y servicios 

Este repositorio contiene una colección de proyectos realizados como parte del programa de formación en 42 Madrid, enfocados en el área de sistemas. Cada proyecto está diseñado para desarrollar habilidades en administración de sistemas, virtualización y configuración de entornos, siguiendo estrictas normas de buenas prácticas. A continuación, se describen algunos aspectos clave:

- **Normas estrictas**: Los proyectos deben cumplir con la Norma de 42, asegurando configuraciones limpias, estructuradas y funcionales.
- **Gestión de recursos**: Se requiere una gestión adecuada de los recursos del sistema, optimizando el uso de memoria, CPU y almacenamiento.
- **Evaluación rigurosa**: Los proyectos son evaluados tanto por compañeros como por herramientas automatizadas, garantizando la calidad de las configuraciones y scripts.
- **Documentación y scripts**: Se fomenta la creación de documentación clara y scripts reutilizables para automatizar tareas comunes.
- **Uso de herramientas de virtualización**: Los proyectos incluyen el uso de herramientas como VirtualBox y VMware para configurar y gestionar máquinas virtuales.

Estos proyectos no solo fortalecen las bases en administración de sistemas, sino que también preparan a los estudiantes para enfrentar desafíos reales en la gestión de infraestructuras tecnológicas.

## Ejercicios a realizar
- [Born2beroot](./Born2beroot/README.md)

## Herramientas opcionales a instalar 

### VirtualBox

**VirtualBox** es una herramienta de virtualización que permite ejecutar sistemas operativos adicionales en una máquina virtual. Es ampliamente utilizada en 42 Madrid para configurar entornos de desarrollo y pruebas.

### Instalación

1. **Descarga VirtualBox**:
    - Visita la página oficial: [https://www.virtualbox.org/](https://www.virtualbox.org/).
    - Descarga el instalador correspondiente a tu sistema operativo.

2. **Instala VirtualBox**:
    - Ejecuta el instalador y sigue las instrucciones en pantalla.

3. **(Opcional) Instala el paquete de extensiones**:
    - Descarga el paquete de extensiones desde la misma página oficial.
    - Ábrelo con VirtualBox y sigue las instrucciones para habilitar características adicionales como soporte USB 2.0/3.0.

### Configuración básica

1. **Crear una nueva máquina virtual**:
    - Abre VirtualBox y haz clic en "Nueva".
    - Asigna un nombre a la máquina virtual y selecciona el sistema operativo.
    - Configura la memoria RAM y el tamaño del disco duro virtual según las necesidades del sistema.

2. **Montar la imagen ISO del sistema operativo**:
    - Descarga la ISO del sistema operativo que deseas instalar.
    - En la configuración de la máquina virtual, ve a "Almacenamiento" y selecciona la ISO como unidad de CD/DVD.

3. **Iniciar la máquina virtual**:
    - Haz clic en "Iniciar" y sigue las instrucciones de instalación del sistema operativo.

### Solución a problemas comunes

1. **Habilitar virtualización en BIOS/UEFI**:
    - Asegúrate de que la virtualización esté activada en la configuración de tu BIOS/UEFI.

2. **Conflictos con otros programas de virtualización**:
    - Desactiva o desinstala otros programas de virtualización que puedan interferir.

3. **Consultar registros de errores**:
    - Ve a `Archivo > Preferencias > Registro` en VirtualBox para revisar los detalles de errores.

4. **Actualizar VirtualBox**:
    - Descarga e instala la última versión desde la página oficial.

### Comandos útiles de VBoxManage

- **Iniciar una máquina virtual**:
  ```bash
  VBoxManage startvm "Nombre_de_la_VM"
  ```

- **Listar máquinas virtuales registradas**:
  ```bash
  VBoxManage list vms
  ```

- **Apagar una máquina virtual**:
  ```bash
  VBoxManage controlvm "Nombre_de_la_VM" poweroff
  ```

- **Cambiar la configuración de red**:
  ```bash
  VBoxManage modifyvm "Nombre_de_la_VM" --nic1 bridged
  ```

### Recursos adicionales

- [Documentación oficial de VirtualBox](https://www.virtualbox.org/manual/)
- [Tutoriales en YouTube sobre VirtualBox](https://www.youtube.com/results?search_query=virtualbox+tutorial)

Con estas instrucciones, podrás instalar y configurar VirtualBox para tus proyectos en 42 Madrid de manera eficiente.

### VMware

**VMware** es otra herramienta de virtualización ampliamente utilizada para ejecutar sistemas operativos en máquinas virtuales. Ofrece una interfaz intuitiva y un rendimiento sólido, siendo una alternativa popular a VirtualBox.

### Instalación

1. **Descarga VMware**:
    - Visita la página oficial: [https://www.vmware.com/](https://www.vmware.com/).
    - Descarga la versión adecuada para tu sistema operativo (VMware Workstation Player o VMware Fusion para macOS).

2. **Instala VMware**:
    - Ejecuta el instalador y sigue las instrucciones en pantalla.

3. **(Opcional) Obtén una licencia**:
    - VMware Workstation Player es gratuito para uso personal, pero puedes adquirir una licencia para funciones avanzadas.

### Configuración básica

1. **Crear una nueva máquina virtual**:
    - Abre VMware y selecciona "Crear una nueva máquina virtual".
    - Elige entre instalar desde un disco, una imagen ISO o configurar la máquina más tarde.
    - Configura la memoria RAM, procesadores y disco duro virtual según las necesidades del sistema operativo.

2. **Montar la imagen ISO del sistema operativo**:
    - Descarga la ISO del sistema operativo que deseas instalar.
    - En la configuración de la máquina virtual, selecciona la ISO como fuente de instalación.

3. **Iniciar la máquina virtual**:
    - Haz clic en "Iniciar" y sigue las instrucciones de instalación del sistema operativo.

### Solución a problemas comunes

1. **Habilitar virtualización en BIOS/UEFI**:
    - Asegúrate de que la virtualización esté activada en la configuración de tu BIOS/UEFI.

2. **Conflictos con otros programas de virtualización**:
    - Desactiva o desinstala otros programas de virtualización que puedan interferir.

3. **Errores de compatibilidad**:
    - Asegúrate de que tu sistema operativo host sea compatible con la versión de VMware instalada.

4. **Actualizar VMware**:
    - Descarga e instala la última versión desde la página oficial.

### Comandos útiles de VMware (VMrun)

- **Iniciar una máquina virtual**:
  ```bash
  vmrun start "/ruta/a/tu/archivo.vmx"
  ```

- **Apagar una máquina virtual**:
  ```bash
  vmrun stop "/ruta/a/tu/archivo.vmx"
  ```

- **Reiniciar una máquina virtual**:
  ```bash
  vmrun reset "/ruta/a/tu/archivo.vmx"
  ```

- **Listar máquinas virtuales activas**:
  ```bash
  vmrun list
  ```

### Recursos adicionales

- [Documentación oficial de VMware](https://techdocs.broadcom.com/)
- [Tutoriales en YouTube sobre VMware](https://www.youtube.com/results?search_query=vmware+tutorial)

Con estas instrucciones, podrás instalar y configurar VMware para tus proyectos en 42 Madrid de manera eficiente.