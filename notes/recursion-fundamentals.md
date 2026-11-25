<h1 align="center">La naturaleza de la recursividad</h1>

## Contenido
1. [Introducción]()
2. [La naturaleza de la recursividad]()
3. [Ejemplo 1: Suma de los N primeros números enteros]()
    - [3.1. Planteamiento]()
    - [3.2. Implementación en C++]()
4. [Ejemplo 2: Serie Fibonacci]()
    - [4.1. Planteamiento]()
    - [4.2. Definición recursiva]()
    - [4.3. Implementación en C++]() 
5. [Resumen]()

# 1. Introducción
La **recursividad (recursión)** es aquella propiedad que posee una función por la cual puede llamarse a sí misma. Aunque la recursividad se puede utilizar como una alternativa a la iteración, una solución recursiva es normalmente menos eficiente, en términos de tiempo de computadora, que una solución iterativa, debido a las operaciones auxiliares que llevan consigo las invocaciones suplementarias a las funciones. Sin embargo, en muchas circunstancias el uso de la recursión permite a los programadores especificar soluciones naturales, sencillas, que serían, en caso contrario, difíciles de resolver. Por esta causa, la recursión es una herramienta poderosa e importante en la resolución de problemas y en la programación. Diversas técnicas algorítmicas utilizan la recursión, como los algoritmos **divide y vence** y los algoritmos de **vuelta atrás**.

# 2. La naturaleza de la recursividad
Una **función recursiva** es aquella que se llama a sí misma, bien directamente o bien indirectamente a través de otra función. La recursividad es un tópico importante examinado frecuentemente en cursos en los que se trata de resolución de algoritmos y en cursos relativos a Estructuras de Datos. Una función que tiene sentencias entre las que se encuentra al menos una que llama a la propia función se dice que es recursiva. Así, la organización recursiva de una función `funcion1()` sería la siguiente:

```cpp
void funcion1(...) {
    ...
    funcion1(); // Llamada recursiva
    ...
}
```

# 3. Ejemplo 1: Suma de los N primeros números enteros

## 3.1. Planteamiento
Planteamiento recursivo de la función matemática que suma los N primeros números enteros positivos.

Como punto de partida se puede afirmar que para \(n = 1\) se tiene que la suma \(S(1) = 1\).

Para \(n = 2\) se puede escribir:

\[S(2) = S(1) + 2\]

En general y aplicando la inducción matemática se tiene:

\[S(n) = S(n-1) + n\]

El algoritmo que determina la suma de modo recursivo ha de tener presente un **caso base** y un **caso recursivo**.

Así, en el caso del cálculo de \(S(6)\), la definición es:

\[S(6) = 6 + S(5)\]

Que de acuerdo a la definición es:

\[S(6) = 6 + 5 + S(4)\]

Este proceso continúa hasta llegar a \(S(1) = 1\), por definición.

## 3.2. Implementación en C++
En consecuencia, la implementación del algoritmo mencionado, que calcula la suma de los N primeros enteros, es:

```cpp
long sumaNEnteros(int n) {
    if (n == 1) {
        return 1;
    }
    else {
        return n + sumaNEnteros(n - 1);
    }
}
```

**Explicación:**

- **Caso base:** cuando `n == 1`, la función devuelve `1` y termina la recursión.
- **Caso recursivo:** cuando `n` es mayor que `1`, devuelve `n` más el resultado de llamar nuevamente a `sumaNEnteros(n - 1)`.

# 4. Ejemplo 2: Serie Fibonacci

## 4.1. Planteamiento
Definir la naturaleza recursiva de la serie Fibonacci:

\[0,\ 1,\ 1,\ 2,\ 3,\ 5,\ 8,\ 13,\ 21,\ldots\]

Se observa en esta serie que comienza con `0` y `1`, y tiene la propiedad de que cada elemento es la suma de los dos elementos anteriores. Por ejemplo:

```text
0 + 1 = 1
1 + 1 = 2
2 + 1 = 3
3 + 2 = 5
5 + 3 = 8
...
```

Entonces se puede establecer que:

\[
\begin{aligned}
fibonacci(0) &= 0 \\
fibonacci(1) &= 1 \\
\vdots \\
fibonacci(n) &= fibonacci(n-1) + fibonacci(n-2)
\end{aligned}
\]

## 4.2. Definición recursiva
La definición recursiva será:

\[
fibonacci(n) =
\begin{cases}
n, & \text{si } n = 0 \text{ o } n = 1 \\
fibonacci(n-1) + fibonacci(n-2), & \text{si } n \geq 2
\end{cases}
\]

Así, por ejemplo:

\[fibonacci(6) = fibonacci(5) + fibonacci(4)\]

## 4.3. Implementación en C++
En consecuencia, la implementación del algoritmo mencionado de la serie Fibonacci es:

```cpp
long fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
```

**Explicación:**

- **Casos base:** cuando `n` es `0` o `1`, la función devuelve `n`.
- **Caso recursivo:** cuando `n` es mayor o igual que `2`, devuelve la suma de las llamadas recursivas `fibonacci(n - 1)` y `fibonacci(n - 2)`.

# 5. Resumen
La recursividad es una propiedad de las funciones que les permite llamarse a sí mismas, directa o indirectamente, para resolver un problema mediante versiones más pequeñas del mismo. Toda función recursiva debe contar con un caso base, que detiene las llamadas, y un caso recursivo, que permite continuar el proceso.

En la suma de los N primeros números enteros, la función utiliza la expresión \(S(n) = S(n-1) + n\), hasta llegar al caso base \(S(1) = 1\).

En la serie Fibonacci, cada término se obtiene sumando los dos anteriores, utilizando los casos base \(fibonacci(0) = 0\) y \(fibonacci(1) = 1\). Su definición recursiva es \(fibonacci(n) = fibonacci(n-1) + fibonacci(n-2)\).

La recursividad permite expresar soluciones de forma natural y sencilla, y es utilizada en técnicas algorítmicas como Divide y Vencerás y Vuelta Atrás.