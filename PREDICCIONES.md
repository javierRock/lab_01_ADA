# Predicciones y conclusiones

## Cálculo

Se usaron los tiempos medidos con `n = 8000` y la siguiente fórmula:

```text
T(10^8) = T(8000) * (10^8 / 8000)^b
```

El exponente `b` es `3` para la versión cúbica, `2` para la cuadrática y `1` para la lineal.

| Algoritmo | Tiempo base con n = 8000 | Tiempo estimado con n = 10^8 |
|---|---:|---:|
| Cúbica | 16.312131 s | 3.185963 x 10^13 s |
| Cuadrática | 0.012153 s | 1.898906 x 10^6 s |
| Lineal | 0.000006036 s | 0.075450 s |

La versión cúbica tardaría cerca de 1.01 millones de años. La versión cuadrática tardaría cerca de 21.98 días. La versión lineal tardaría cerca de 75 milisegundos.

## Comparación

La única versión estimada en menos de un minuto fue la lineal. Por esta razón fue la única que se ejecutó con `n = 10^8`.

| Tiempo predicho | Tiempo medido | Diferencia |
|---:|---:|---:|
| 0.075450 s | 0.076546 s | 0.001096 s |

El tiempo medido fue aproximadamente `1.45 %` mayor que el predicho. La estimación fue cercana al resultado real.

## Conclusiones

Las 100 pruebas confirmaron que los tres algoritmos devuelven la misma suma máxima.

Las razones de duplicación confirmaron los órdenes esperados: cerca de `8` para la versión cúbica, `4` para la cuadrática y `2` para la lineal.

Para tamaños pequeños las tres versiones funcionan, pero la diferencia aumenta rápidamente al crecer `n`. Con `n = 10^8`, solamente la versión lineal es práctica en este equipo.
