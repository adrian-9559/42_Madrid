# 🎮 NetPractice — Redes (10 niveles de configuración)

[![Nota](https://img.shields.io/badge/⭐_Nota-Aprobado-2ea44f)](./)
[![Bloque](https://img.shields.io/badge/🔵_Redes-1/1-1f6feb)](../)
[![Tipo](https://img.shields.io/badge/🛠️_Simulador-Web-6f42c1)](./)

---

## 🧭 Índice

1. [🌟 Introducción](#-introducción)
2. [🎯 Objetivos](#-objetivos)
3. [📄 Enunciado](#-enunciado)
4. [🗂️ Estructura](#️-estructura)
5. [🚀 Uso práctico](#-uso-práctico)
6. [🧪 Verificación](#-verificación)
7. [📚 Recursos](#-recursos)

---

## 🌟 Introducción

**NetPractice** es un proyecto "teórico-práctico" **sin código**: se resuelve en un **simulador web** de la intra de 42 e incluye **10 niveles** de configuración de redes (TCP/IP addressing, máscaras de subred, routing y switches). 🌐

Este repositorio guarda la **configuración final resuelta de cada nivel** en archivos `levelN.json` exportados desde el simulador, listos para mostrarse en evaluación.

## 🎯 Objetivos

- 🧮 Calcular **máscaras de subred**, direcciones de red, broadcast y rangos útiles.
- 🚦 Configurar **rutas estáticas** y **default gateways**.
- 🧩 Entender **switches** (segmentación por VLAN) y **routers** (encaminamiento entre redes).
- ❌ Saber **por qué falla** una comunicación (lookup table, IP fuera de rango, ruta inexistente).

## 📄 Enunciado

El simulador de 42 consta de **10 niveles** de dificultad creciente. Cada nivel presenta una topología (interfaces, IPs, máscaras, switches, routers) y pide que los hosts se comuniquen:

- ✍️ Rellenar IPs y máscaras correctas.
- 🚏 Añadir **rutas** donde haga falta.
- 📡 Activar/desactivar interfaces y comprobar la conectividad con el simulador.
- ✅ Al final, **Export** de cada nivel resuelto.

## 🗂️ Estructura

```
NetPractice/
├── README.md                  # 📘 Este documento
├── level01.json  …  level10.json   # ✅ Configuraciones resueltas (1–10)
└── …
```

> 💡 La entrega oficial de 42 pide, además, **capturas de pantalla** de los niveles resueltos o demostración en vivo. Los JSON son el "estado" reproducible de cada nivel.

## 🚀 Uso práctico

1. Entra en la intra de 42 → proyecto **NetPractice** → "Web Interface".
2. Resuelve los niveles **con el simulador** (mira la leyenda del nivel: IPs de red, máscaras, gateways).
3. Usa **`Export`** de cada nivel tras validarlo → guarda el JSON en el repo (`level01.json`… `level10.json`).
4. Para repasar un nivel sin el simulador, revisa el JSON: contiene las IPs, máscaras y rutas tal cual las configuraste.

### Consejos rápidos por nivel

- 🔢 **Cálculo de rango útil**: `hosts = 2^(32-máscara) - 2`.
- 🚏 Si quieres que `R1` alcance una red remota, R1 necesita una ruta a esa red *via* la IP del router siguiente en su propia subred.
- 🌀 No uses una IP **dentro de una subred equivocada**: los switches solo encaminan en su propia VLAN.

## 🧪 Verificación

| Criterio | Detalle |
|---|---|
| ✅ **Simulador** | Cada nivel debe quedar "OK" en el propio simulador |
| 📄 **Archivos** | `ls level*.json` → deben existir los 10 |
| 🧠 **Explicación** | En evaluación te pedirán justificar cada decisión (máscara, ruta, gateway) |
| 🖥️ **Demo en vivo** | Cargar un nivel y arreglar un fallo en directo |

## 📚 Recursos

- [Subject oficial NetPractice](https://cdn.intra.42.fr/pdf/pdf/65344/en.subject.pdf)
- [Cursus 42 — Índice](../../README.md)
- [RFC 1918 · Direccionamiento privado](https://datatracker.ietf.org/doc/html/rfc1918)
- [Subnet Cheat Sheet](https://www.freecodecamp.org/news/subnet-cheat-sheet-24-subnet-mask-ip-adressing-and-subnetting-guide/)