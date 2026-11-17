<h1 align="center">Análisis de Rendimiento</h1>

## Contenido
1. [Análisis de rendimiento]()
   - [1.1. Complejidad del espacio]()
   - [1.2. Complejidad del tiempo]()
   - [1.3. Ejemplo de análisis del tiempo de ejecución]()
   - [1.4. Casos de análisis]()
2. [Resumen]()

# 1. Análisis de rendimiento
La medida del rendimiento de un programa se consigue mediante la **complejidad del espacio** y la **complejidad del tiempo** de un programa.

## 1.1. Complejidad del espacio
La **complejidad del espacio** de un programa es la cantidad de memoria que se necesita para ejecutarlo hasta su completa ejecución (terminación).

El avance tecnológico proporciona hoy en día memoria abundante, por esa razón, el análisis de algoritmos se centra, fundamentalmente, en el tiempo de ejecución.

## 1.2. Complejidad del tiempo
La **complejidad del tiempo** de un programa es la cantidad de tiempo de computadora que se necesita para ejecutarse.

Se utiliza una función, **T(n)**, para representar el número de unidades de tiempo tomadas por un programa o algoritmo para cualquier entrada de tamaño `n`.

## 1.3. Ejemplo de análisis del tiempo de ejecución
**Tiempo de ejecución lineal de una función que calcula una serie de N términos:**
```cpp
double serie(double x, int n) {
    double s;
    int i = 0;

    s = 0.0;

    for (i = 1; i <= n; i++) {
        s += i * x;
    }

    return s;
}
```

Cada instrucción representa una unidad de tiempo:
| Instrucción                | Tiempo          | 
| ---                        | ---             |
| `s = 0.0;`                 | Tiempo 1 (`t1`) |
| `for (i = 1; i <= n; i++)` | Tiempo 2 (`t2`) |
| `s += i * x;`              | Tiempo 3 (`t3`) |
| `return s;`                | Tiempo 4 (`t4`) |

La función **T(n)** del método es:

\[T(n) = t_1 + n \cdot t_2 + n \cdot t_3 + t_4\]

El tiempo crece a medida que aumenta `n`. Por ello, es preferible expresar el tiempo de ejecución de tal forma que indique el comportamiento que va a tener la función con respecto al valor de `n`.

## 1.4. Casos de análisis
Considerando todas las reflexiones anteriores, si **T(n)** es el tiempo de ejecución de un programa con entrada de tamaño `n`, será posible valorar T(n) como el número de sentencias ejecutadas por el programa. La evaluación se podrá efectuar desde diferentes puntos de vista:

- **Peor caso:** indica el tiempo peor que se puede tener. Este análisis es perfectamente adecuado para algoritmos cuyo tiempo de respuesta sea crítico.
- **Mejor caso:** indica el tiempo mejor que podemos tener.
- **Caso medio:** se puede computar T(n) como el tiempo medio de ejecución del programa sobre todas las posibles ejecuciones de entradas de tamaño `n`. El tiempo de ejecución medio es a veces una medida más realista de lo que el rendimiento será en la práctica, pero es, normalmente, mucho más difícil de calcular que el tiempo de ejecución en el peor caso.

# 2. Resumen
El **análisis de rendimiento** permite evaluar la eficiencia de un programa mediante dos aspectos: la complejidad del espacio, que representa la memoria necesaria para su ejecución, y la complejidad del tiempo, que representa cuánto tiempo necesita para ejecutarse.

La función **T(n)** expresa el tiempo de ejecución de un algoritmo en función del tamaño de su entrada. Para analizar su comportamiento se consideran tres escenarios:

- **Peor caso:** el mayor tiempo de ejecución posible.
- **Mejor caso:** el menor tiempo de ejecución posible.
- **Caso medio:** el tiempo promedio de ejecución para las entradas de un tamaño determinado.

Estos análisis permiten comprender cómo cambia el rendimiento de un algoritmo conforme aumenta el tamaño de los datos de entrada.