# Laboratorio de máximo subarreglo

__Nombre:__ Javier Alonzo Peñalva Humire

## Descripción

El problema consiste en encontrar la suma máxima de un segmento contiguo dentro de un arreglo de enteros positivos y negativos.

Por ejemplo, para el arreglo:

```text
-2 1 -3 4 -1 2 1 -5 4
```

el segmento de suma máxima es `4 -1 2 1` y su suma es `6`.

En este laboratorio se implementan y comparan tres soluciones: una cúbica, una cuadrática y el algoritmo lineal de Kadane.

## Algoritmos implementados

Todo el código se encuentra en `main.cpp`. Las funciones usan arreglos simples y bucles explícitos para mantener una implementación fácil de leer.

| Función | Descripción | Orden de tiempo |
|---|---|---:|
| `max_cubica` | Prueba cada segmento y calcula su suma desde cero | Theta(n^3) |
| `max_cuadratica` | Mantiene una suma parcial mientras extiende cada segmento | Theta(n^2) |
| `max_lineal` | Decide si conviene extender el segmento anterior o comenzar uno nuevo | Theta(n) |

Las sumas se guardan en variables `long long` para evitar desbordamientos con arreglos grandes. Los tres algoritmos suponen que el arreglo tiene por lo menos un elemento.

## Archivos

- `main.cpp`: algoritmos, pruebas, mediciones y predicciones.
- `Makefile`: instrucciones de compilación.

## Compilación y ejecución

El programa fue escrito en C++17 y se compila con:

```bash
make
```

Para ejecutar todo el laboratorio:

```bash
./subarreglo
```

El programa realiza las pruebas de correctitud, construye la tabla de tiempos, calcula las predicciones y ejecuta la versión estimada en menos de un minuto. La medición cúbica con `n = 8000` puede tardar varios segundos.

## Verificación de correctitud

Se generaron 100 arreglos pequeños con tamaños entre 2 y 20. Los valores pertenecen al intervalo `[-10, 10]` y cada arreglo contiene por lo menos un número positivo y uno negativo.

La semilla utilizada fue `2026`, de modo que las pruebas sean reproducibles. En cada caso se ejecutaron las tres funciones y se compararon sus resultados.

```text
Las 3 soluciones coinciden en las 100 pruebas.
```

También se inicializa cada algoritmo con el primer elemento del arreglo. Esto permite obtener una respuesta correcta cuando todos los valores son negativos, en lugar de devolver incorrectamente cero.

## Método de medición

Los arreglos se generan antes de iniciar el cronómetro. Por lo tanto, los tiempos mostrados corresponden solamente a los algoritmos.

La medición usa `clock()`. Debido a que las versiones rápidas pueden terminar en pocos microsegundos, estas se ejecutan varias veces y se presenta el tiempo promedio. Antes de construir la tabla también se realiza un calentamiento breve para reducir las variaciones causadas por el cambio de frecuencia del procesador.

Los tamaños utilizados fueron `1000`, `2000`, `4000` y `8000`. Para cada fila se calcula la razón:

```text
razón = T(n) / T(n/2)
```

## Resultados

Mediciones realizadas el 5 de septiembre de 2026. Los tiempos están expresados en segundos.

| n | Cúbica | Razón | Cuadrática | Razón | Lineal | Razón |
|---:|---:|---:|---:|---:|---:|---:|
| 1 000 | 0.033131750 | - | 0.000192460 | - | 0.000000750 | - |
| 2 000 | 0.258955000 | 7.82 | 0.000763480 | 3.97 | 0.000001505 | 2.01 |
| 4 000 | 2.045394000 | 7.90 | 0.003028500 | 3.97 | 0.000002999 | 1.99 |
| 8 000 | 16.312131000 | 7.98 | 0.012153000 | 4.01 | 0.000006036 | 2.01 |

## Orden de crecimiento deducido

La versión cúbica presenta razones cercanas a `8`. Esto coincide con un orden Theta(n^3), ya que al duplicar `n` se tiene `2^3 = 8`.

La versión cuadrática presenta razones cercanas a `4`. Esto coincide con un orden Theta(n^2), ya que `2^2 = 4`.

La versión lineal presenta razones cercanas a `2`. Esto coincide con un orden Theta(n), ya que `2^1 = 2`.

Las razones medidas confirman los órdenes de crecimiento obtenidos al analizar los bucles de cada algoritmo.

## Predicción para n = 10^8

Las predicciones usan los tiempos medidos con `n = 8000` y la fórmula:

```text
T(10^8) = T(8000) * (10^8 / 8000)^b
```

El exponente `b` es `3` para la versión cúbica, `2` para la cuadrática y `1` para la lineal.

| Algoritmo | Tiempo con n = 8000 | Tiempo estimado con n = 10^8 | Equivalencia aproximada |
|---|---:|---:|---:|
| Cúbica | 16.312131 s | 3.185963 x 10^13 s | 1.01 millones de años |
| Cuadrática | 0.012153 s | 1.898906 x 10^6 s | 21.98 días |
| Lineal | 0.000006036 s | 0.075450 s | 75 milisegundos |

La única versión con un tiempo estimado menor a un minuto fue la lineal. Por este motivo, las versiones cúbica y cuadrática no se ejecutaron con `n = 10^8`.

## Predicción frente a medición real

Se generó un arreglo de `10^8` enteros y se ejecutó solamente la versión lineal. La generación del arreglo se realizó fuera del tiempo medido.

| Tiempo predicho | Tiempo medido | Diferencia |
|---:|---:|---:|
| 0.075450 s | 0.076546 s | 0.001096 s |

El tiempo medido fue aproximadamente `1.45 %` mayor que el predicho. Esta diferencia es pequeña y puede explicarse por factores como la carga del sistema, la memoria caché y los cambios en la frecuencia del procesador.

## Equipo utilizado

- Lenguaje: C++17.
- Compilador: g++ 16.2.1 con optimización `-O2`.
- Procesador: AMD Ryzen 9 8940HX, 16 núcleos y 32 hilos. El programa usa un solo hilo.
- Memoria visible para el sistema: aproximadamente 14.82 GiB.
- Sistema operativo: Linux 7.2.3-1-cachyos, arquitectura x86-64.

## Conclusiones

Las tres implementaciones devolvieron el mismo resultado en los 100 arreglos de prueba, por lo que no se encontraron diferencias de correctitud entre ellas.

Las mediciones muestran que el orden de crecimiento determina qué solución es práctica cuando aumenta el tamaño de la entrada. La versión cúbica crece demasiado rápido, la cuadrática mejora de forma importante y la versión lineal de Kadane mantiene un tiempo reducido incluso con `10^8` elementos.

La predicción de la versión lineal fue cercana a la medición real. Esto muestra que las razones de duplicación y el análisis asintótico permiten estimar de forma razonable cómo se comportará un algoritmo con entradas mayores.
