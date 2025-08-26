# Práctica Spectre Attack

## Objetivos

El objetivo principal de esta práctica es comprender y experimentar de forma progresiva con el **Ataque Spectre**, una vulnerabilidad crítica descubierta en 2017 que afecta a la mayoría de los procesadores modernos (Intel, AMD, ARM). Para facilitar su entendimiento, el ataque se descompone en una serie de tareas que abordan los distintos componentes técnicos involucrados.

A través de esta práctica, se pretende que el estudiante:

- **Analice el comportamiento de la memoria caché** y su impacto en el rendimiento de acceso a datos.
- **Implemente técnicas de canal encubierto (side channel)** como FLUSH+RELOAD para inferir información sensible.
- **Explore la ejecución fuera de orden y la predicción de saltos**, mecanismos internos de optimización en CPUs modernas, y cómo estos pueden ser explotados.
- **Desarrolle un ataque Spectre funcional**, capaz de filtrar datos protegidos mediante ejecución especulativa.
- **Mejore la precisión del ataque** mediante técnicas estadísticas que reduzcan el ruido en los resultados.

Esta práctica se basa en [https://seedsecuritylabs.org/Labs_20.04/Files/Spectre_Attack/Spectre_Attack_es.pdf](https://seedsecuritylabs.org/Labs_20.04/Files/Spectre_Attack/Spectre_Attack_es.pdf)
