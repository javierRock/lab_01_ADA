# Laboratorio de máximo subarreglo

Este laboratorio compara tres algoritmos para encontrar la suma máxima de un segmento contiguo dentro de un arreglo.

Las tres versiones están escritas de forma directa en `main.cpp`:

- `max_cubica`: prueba cada segmento y lo suma desde cero. Su orden es Theta(n^3).
- `max_cuadratica`: conserva la suma parcial mientras extiende el segmento. Su orden es Theta(n^2).
- `max_lineal`: aplica el algoritmo de Kadane. Su orden es Theta(n).

El código usa `using namespace std`, arreglos simples, `rand()` y `clock()`. Solo incluye las cabeceras estándar `iostream`, `cstdlib` y `ctime`. Se usa `long long` para las sumas, de modo que los arreglos grandes no produzcan desbordamientos.

## Archivos

- `main.cpp`: contiene los algoritmos, las pruebas, las mediciones y las predicciones.
- `PREDICCIONES.md`: contiene los cálculos y las conclusiones.
- `Makefile`: permite compilar el programa.
- `semana02.pdf`: diapositivas usadas como referencia.

## Compilación y ejecución

```bash
make
./subarreglo
```

El programa realiza todo el laboratorio en una sola ejecución. La versión cúbica con `n = 8000` puede tardar varios segundos.

## Verificación

Se generaron 100 arreglos de tamaños entre 2 y 20. Sus valores están entre `-10` y `10`, y se garantiza que cada arreglo tenga por lo menos un número positivo y uno negativo.

Para cada arreglo se comparó el resultado de las tres funciones. La semilla usada fue `2026`, para que las pruebas puedan repetirse.

Resultado:

```text
Las 3 soluciones coinciden en las 100 pruebas.
```

## Medición

Los arreglos se generan antes de iniciar el cronómetro. Por lo tanto, los tiempos corresponden solamente a la ejecución de cada algoritmo.

Se utilizó `clock()`. Las ejecuciones muy cortas se repiten varias veces y se calcula el promedio. También se hizo un calentamiento breve del procesador antes de construir la tabla.

Medición realizada el 5 de septiembre de 2026. Los tiempos están en segundos.

| n | Cúbica | Razón | Cuadrática | Razón | Lineal | Razón |
|---:|---:|---:|---:|---:|---:|---:|
| 1 000 | 0.033131750 | - | 0.000192460 | - | 0.000000750 | - |
| 2 000 | 0.258955000 | 7.82 | 0.000763480 | 3.97 | 0.000001505 | 2.01 |
| 4 000 | 2.045394000 | 7.90 | 0.003028500 | 3.97 | 0.000002999 | 1.99 |
| 8 000 | 16.312131000 | 7.98 | 0.012153000 | 4.01 | 0.000006036 | 2.01 |

La razón se calcula dividiendo cada tiempo entre el tiempo del tamaño anterior.

## Orden deducido

Cuando `n` se duplica, el tiempo de la versión cúbica se multiplica aproximadamente por `8`. Esto coincide con Theta(n^3), porque `2^3 = 8`.

El tiempo de la versión cuadrática se multiplica aproximadamente por `4`. Esto coincide con Theta(n^2), porque `2^2 = 4`.

El tiempo de la versión lineal se multiplica aproximadamente por `2`. Esto coincide con Theta(n), porque `2^1 = 2`.

## Equipo utilizado

- Lenguaje: C++17.
- Compilador: g++ 16.2.1 con optimización `-O2`.
- Procesador: AMD Ryzen 9 8940HX, 16 núcleos y 32 hilos. El programa utiliza un solo hilo.
- Memoria visible para el sistema: aproximadamente 14.82 GiB.
- Sistema operativo: Linux 7.2.3-1-cachyos, arquitectura x86-64.
