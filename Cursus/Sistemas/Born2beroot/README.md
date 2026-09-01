# 🎮 Born2beroot — Tu primer servidor virtualizado

[![Nota](https://img.shields.io/badge/⭐_Nota-100/125-2ea44f)](./)
[![Bloque](https://img.shields.io/badge/🔵_Sistemas-1/2-1f6feb)](../)
[![Tipo](https://img.shields.io/badge/🛠️_Administración-SisOps-6f42c1)](./)
[![SO](https://img.shields.io/badge/🐧_Debian-bookworm-cc0000)](./)

---

## 🧭 Índice

1. [🌟 Introducción](#-introducción)
2. [🎯 Objetivos](#-objetivos)
3. [📄 Requisitos del enunciado](#-requisitos-del-enunciado)
4. [⚙️ Guía paso a paso](#️-guía-paso-a-paso)
   - [1. Descargar la ISO](#1-descargar-la-iso)
   - [2. Creación de la máquina virtual](#2-creación-de-la-máquina-virtual)
   - [3. Instalación del sistema operativo](#3-instalación-del-sistema-operativo)
5. [🧪 Verificación y preguntas de corrección](#-verificación-y-preguntas-de-corrección)
6. [🛠️ Herramientas recomendadas](#️-herramientas-recomendadas)
7. [✅ Nota](#-nota)
8. [📚 Recursos](#-recursos)

---

## 🌟 Introducción

**Born2beroot** es una introducción al mundo de la **administración de sistemas** y la **virtualización**. 🌐 Configurarás y gestionarás un servidor virtualizado aplicando buenas prácticas de **seguridad** y **optimización**, desde cero y documentando cada paso. 🔒

A lo largo del proyecto trabajas con **particiones (LVM cifrado)**, **gestión de usuarios y permisos**, **servicios** (`sshd`, `ufw`, `cron`), **red** y un **script de monitorización**. 🛠️

## 🎯 Objetivos

- 🖥️ Montar una **máquina virtual** desde una ISO (Debian o Rocky Linux).
- ⚙️ Instalar el sistema con **LVM cifrado** y particionado guiado.
- 👤 Crear **usuarios y grupos** con permisos correctos.
- 🔐 Configurar **SSH (4242)**, **UFW**, **sudo** con logs y políticas de contraseñas.
- 📊 Realizar un **script de monitorización** (`monitoring.sh`) con `cron`.
- 🧠 Poder **final antiguo**: justificar cada decisión de configuración.

## 📄 Requisitos del enunciado

✅ Resumen de lo que exige el subject:

- 🗂️ **VirtualBox** (o UTM si VirtualBox no funciona en tu máquina) es obligatorio.
- 🐧 Sistema **Debian** (>  equivalente al actual stable) o **Rocky Linux**.
- 🧱 Particionado con **LVM**, usando **encrypted LVM**.
- 🎛️ **solo una partición** para `/home` y el resto del espacio sin asignar.
- 🔑 **Política de contraseñas** seguras (expiración, cambios mínimos, diccionario…).
- 🌐 **UFW** activado con el puerto **4242** abierto.
- 🖥️ **SSH** en el puerto **4242** (prohibido conectarse como root).
- 📂 **cron** ejecutando cada 10 min el script `monitoring.sh`; también en el arranque (`crontab`).
- 📝 **sudo**: configuración con logs, límites y «sudoers.d».
- 💾 Entrega: **solo `signature.txt`** con la firma del disco virtual en la raíz del repo.

## ⚙️ Guía paso a paso

### 1. Descargar la ISO

Elige entre **Debian** o **Rocky Linux**:

- [Descargar Debian](https://www.debian.org/index.es.html)
- [Descargar Rocky](https://rockylinux.org/)

Selecciona la **versión estable** y arquitectura adecuada (`amd64`/`x86_64`).  
**En este proyecto se eligió Debian.** 🐧

### 2. Creación de la máquina virtual

> ⚠️ Si no tienes VirtualBox: [Descarga 🔎](https://www.virtualbox.org/wiki/Downloads)

1. **Crear una máquina virtual** → botón `New / Nueva`.
    <div>
        <img src="./imagenes/BotonNew.png">
    </div>

2. **Opciones principales** → nombre de la MV y **selección de la ISO** descargada.
    <div>
        <img src="./imagenes/VentanaCreacionMaquinas.png">
    </div>

3. **Hardware** → indica la **RAM** y el **número de núcleos**.
    <div>
        <img src="./imagenes/VentanaSeleccionRAMCPU.png">
    </div>

4. **Disco** → formato *Virtual Hard Disk* con **10 GB** de almacenamiento.
    <div>
        <img src="./imagenes/VentanaSeleccionDiscoDuro.png">
    </div>

5. **Resumen** → revisa la información final de la máquina virtual.
    <div>
        <img src="./imagenes/VentanaInformacionMaquinaVirtual.png">
    </div>

### 3. Instalación del sistema operativo

1. **Idioma** → se eligió **inglés** (estándar en informática).
    <div>
        <img src="./imagenes/1.png">
    </div>

2. **Zona geográfica y país** → afecta a la zona horaria.
    <div style="display: flex; gap: 2%; align-items: flex-start;">
        <img src="./imagenes/2.png" width="32%">
        <img src="./imagenes/3.png" width="32%">
        <img src="./imagenes/4.png" width="32%">
    </div>

3. **Teclado** → distribución acorde al idioma (p. ej. "Spanish" o "English (US)").
    <div style="display: flex; gap: 2%; align-items: flex-start;">
        <img src="./imagenes/5.png" width="48%">
        <img src="./imagenes/6.png" width="48%">
    </div>

4. **Hostname** → debe ser `tuLogin42` (login de 42 + 42).
    <div>
        <img src="./imagenes/7.png">
    </div>

5. **Dominio** → se deja **vacío** (no es obligatorio para el proyecto).
    <div>
        <img src="./imagenes/8.png">
    </div>

6. **Contraseña `root`** → segura (mayúsculas, minúsculas, números, símbolos). ¡Anótala!
    <div style="display: flex; gap: 2%; align-items: flex-start;">
        <img src="./imagenes/9.png" width="48%">
        <img src="./imagenes/10.png" width="48%">
    </div>

7. **Usuario no privilegiado** → nombre completo y **login de 42**; contraseña segura (≥ 8 caracteres, mayúsc./minúsc., números y símbolos).
    <div>
        <img src="./imagenes/11.png">
    </div>
    <div>
        <img src="./imagenes/12.png">
    </div>
    <div style="display: flex; gap: 2%; align-items: flex-start;">
        <img src="./imagenes/13.png" width="48%">
        <img src="./imagenes/14.png" width="48%">
    </div>

8. **Zona horaria** → p. ej. `Europe/Madrid`.
    <div>
        <img src="./imagenes/15.png">
    </div>

9. **Encriptado del disco (LVM)** → elige `Guided - use entire disk and set up encrypted LVM` y define la contraseña de cifrado (se pedirá en cada arranque).
    <div>
        <img src="./imagenes/16.png">
    </div>

10. **Selección de partición** → la única partición existente.
    <div>
        <img src="./imagenes/17.png">
    </div>

11. **Particionado manual** → elimina las particiones existentes y crea **una única partición para `/home`** con todo el espacio; deja `/` y `swap` sin asignar (así todo el sistema queda en `/home`, cumpliendo el requisito).
    <div>
        <img src="./imagenes/18.png">
    </div>

---

## 🧪 Verificación y preguntas de corrección

La evaluación de Born2beroot es **oral y práctica**: tendrás que responder sobre la VM en vivo. Estas son las preguntas clave con sus respuestas:

### ❓ ¿Qué es una Máquina Virtual?
Una VM es una aplicación que permite **instalar un sistema operativo adicional** sobre tu máquina física, ejecutando ambos sistemas simultáneamente y de forma aislada.

### ❓ Beneficios de usar máquinas virtuales
- 💰 **Rentable**: los costes de mantenimiento son mínimos al compartir los componentes físicos con el host.
- 🛡️ **Seguridad**: si la VM se ve comprometida, el host principal permanece seguro (basta con desinstalar la VM).

### ❓ Selección de ISO
- **Debian**: estabilidad, amplia documentación y gran comunidad. Ideal para aprendizaje y servidores de propósito general.
- **Rocky Linux**: orientada a empresa, compatible con RHEL, seguridad avanzada y gestores `yum`/`dnf`.

### ❓ Diferencias entre APT y Aptitude
- **APT**: ejecuta solo los comandos indicados en la CLI, gestionando paquetes de forma directa.
- **Aptitude**: versión avanzada de APT con **interfaz interactiva**; distingue paquetes explícitos de dependencias y **elimina automáticamente** las dependencias no usadas.

### ❓ ¿Qué es AppArmor?
Sistema de **control de acceso obligatorio (MAC)** usado por defecto en Debian. Define **perfiles de seguridad por aplicación**, limitando estrictamente los archivos y recursos a los que cada programa puede acceder, reduciendo el impacto de una posible intrusión.

---

## 🛠️ Herramientas recomendadas

- **VirtualBox / UTM**: virtualización → [Descarga](https://www.virtualbox.org/wiki/Downloads)
- **SSH**: gestión remota del servidor (`ssh -p 4242 login@IP`).

## ✅ Nota

| Resultado | Detalle |
|---|---|
| ⭐ **100/125** | Configuración completa, se perdieron puntos en algún apartado del subject |

💡 Consejo: repasa los puntos donde se perdió puntuación (normalmente política de contraseñas, **cron con `monitoring.sh` en cada arranque** o particiones) para evitarlos en la revisión.

## 📚 Recursos

- [Subject oficial Born2beroot](https://cdn.intra.42.fr/pdf/pdf/61278/en.subject.pdf)
- [Cursus 42 — Índice](../../README.md)
- [Manual de instalación Debian](https://www.debian.org/releases/stable/installmanual)
- [Rocky Linux docs](https://docs.rockylinux.org/)
- [UFW · Ubuntu docs](https://help.ubuntu.com/community/UFW)