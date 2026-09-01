# 🎮 Inception — Infraestructura Docker de alto nivel

[![Nota](https://img.shields.io/badge/⭐_Nota-Aprobado-2ea44f)](./)
[![Bloque](https://img.shields.io/badge/🔵_Sistemas-2/2-1f6feb)](../)
[![Tipo](https://img.shields.io/badge/🛠️_Docker-Compose-2496ed)](./)
[![SO](https://img.shields.io/badge/🐧_Alpine-Linux-000000)](./)

---

## 🧭 Índice

1. [🌟 Introducción](#-introducción)
2. [🏗️ Arquitectura](#️-arquitectura)
3. [⚖️ Decisiones de diseño](#️-decisiones-de-diseño)
4. [📦 Servicios](#-servicios)
5. [📋 Instrucciones](#-instrucciones)
6. [🧪 Verificación](#-verificación)
7. [🛠️ Comandos de gestión](#️-comandos-de-gestión)
8. [📝 Uso de IA](#-uso-de-ia)
9. [📚 Recursos](#-recursos)

---

## 🌟 Introducción

**Inception** es un proyecto de **administración de sistemas** que monta una pequeña infraestructura con **Docker Compose**: **NGINX** (reverse proxy con TLS), **WordPress** (con php-fpm) y **MariaDB** (base de datos), cada uno en su **contenedor aislado** conectados por una **red bridge** propia.

Proyecto creado dentro del currículo de 42 por adriescr.

## 🏗️ Arquitectura

```
                    ┌─────────────┐
                    │   NGINX     │
                    │  (443 HTTPS)│
                    └──────┬──────┘
                           │
                    ┌──────┴──────┐
                    │  WordPress  │
                    │  (php-fpm)  │
                    └──────┬──────┘
                           │
                    ┌──────┴──────┐
                    │   MariaDB   │
                    │   (3306)    │
                    └─────────────┘
```

## ⚖️ Decisiones de diseño

### Máquinas virtuales vs Docker

| Aspecto | Máquina virtual | Docker |
|---|---|---|
| Tamaño | Rango de GB | Rango de MB |
| Arranque | Minutos | Segundos |
| Aislamiento | Nivel hardware | Nivel SO |
| Recursos | Pesado | Ligero |
| Portabilidad | Baja | Alta |

Se eligió **Docker** por su aislamiento ligero, arranque rápido y reproducibilidad: cada servicio corre en su contenedor con su **propio filesystem** y **namespace de red**.

### Variables de entorno

Todas las credenciales y config en `srcs/.env`. El script de setup genera un `.env` **fresco** automáticamente para el usuario actual y arranca todo el stack sin editar a mano.

### Red Docker (bridge) vs red del host

| Aspecto | Bridge network | Host network |
|---|---|---|
| Aislamiento | Red totalmente aislada | Comparte el stack de red del host |
| Mapeo de puertos | Requerido | No necesario |
| Seguridad | Los contenedores no ven el tráfico ajeno | Todo el tráfico visible |
| Rendimiento | Ligera sobrecarga | Velocidad nativa |

El **bridge** aísla los contenedores y permite comunicación controlada vía **nombres de servicio**.

### Volúmenes Docker vs bind mounts

| Aspecto | Named Volumes | Bind Mounts |
|---|---|---|
| Gestión | Gestionados por Docker | Ruta directa del host |
| Backup | Fácil con `docker volume` | Copia manual |
| Permisos | Los gestiona Docker | Aplican los del host |
| Ubicación | `/var/lib/docker/volumes/` | Cualquier ruta del host |

Se usan **named volumes** para la persistencia, ubicados en `/home/adriescr/data/` en el host pero gestionados por Docker.

## 📦 Servicios

- 🌐 **NGINX**: reverse proxy con HTTPS (**TLSv1.2/1.3**) en el puerto **443**.
- 📝 **WordPress**: CMS sobre **php-fpm**, accesible solo a través de NGINX.
- 🗄️ **MariaDB**: base de datos compatible con MySQL que almacena los datos de WordPress.

## 📋 Instrucciones

### Prerrequisitos

- Docker y Docker Compose instalados.
- **Máquina virtual** (requisito del subject de 42).
- Añadir `adriescr.42.fr` → `127.0.0.1` en `/etc/hosts`.

### Quick start

```bash
# Compila y arranca todos los servicios
make

# O manualmente:
mkdir -p /home/adriescr/data/wordpress /home/adriescr/data/db
docker compose -f srcs/docker-compose.yml up --build -d
```

### Acceso

Abre `https://adriescr.42.fr` en el navegador (acepta el certificado autofirmado). 🔐

## 🧪 Verificación

| Área | Comandos / criterio |
|---|---|
| **Contenedores** | `docker ps` → nginx + wordpress + mariadb en ejecución |
| **HTTPS** | `curl -k https://adriescr.42.fr` → responde la web de WordPress |
| **Red** | `docker network inspect <red>` → los 3 contenedores conectados |
| **Volúmenes** | `docker volume ls` → volúmenes creados y persistidos |
| **Reboot** | Reiniciar la VM → los contenedores deben **seguir levantados** (restart policy) |
| **pgrep/ps** | No debe haber procesos "piggybacked": 1 servicio por contenedor (nginx, php-fpm, mariadbd) |

## 🛠️ Comandos de gestión

| Comando | Acción |
|---|---|
| `make up` | Levantar servicios |
| `make down` | Parar servicios |
| `make stop` | Parar contenedores |
| `make logs` | Ver logs |
| `make ps` | Listar contenedores |
| `make clean` | Parar y limpiar (prune) |
| `make fclean` | Limpieza total **incluidos los datos** |
| `make re` | Rebuild completo |

## 📝 Uso de IA

Se usó IA para:
- 🧱 Generar plantillas de Dockerfiles y ficheros de configuración.
- 🔧 Crear **entrypoint scripts** con manejo de errores.
- 📝 Redactar documentación (README, USER_DOC, DEV_DOC).
- 🐛 Depurar problemas de red de Docker Compose.

Todo el código fue **revisado, testeado y entendido** antes de su implementación final.

## 📚 Recursos

- [Documentación de Docker](https://docs.docker.com/)
- [Documentación de Docker Compose](https://docs.docker.com/compose/)
- [Documentación de NGINX](https://nginx.org/en/docs/)
- [Documentación de WordPress](https://developer.wordpress.org/)
- [Documentación de MariaDB](https://mariadb.org/documentation/)
- [Alpine Linux](https://alpinelinux.org/)
- Subject de Inception de 42 (v5.3)