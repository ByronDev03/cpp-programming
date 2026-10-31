<h1 align="center">Ordenación Shell en C++</h1>

## ¿Qué es?
<p align="justify">
La ordenación Shell debe su nombre a su inventor, Donald L. Shell. También se suele denominar ordenación por inserción con incrementos decrecientes, ya que se considera una mejora del método de inserción directa. En el algoritmo de inserción directa, cada elemento se compara con los elementos contiguos de su izquierda, uno tras otro. Si el elemento que se desea insertar es el más pequeño, pueden ser necesarias muchas comparaciones antes de colocarlo en su posición definitiva. El algoritmo de Shell modifica los saltos contiguos por saltos de mayor tamaño. De esta manera, los elementos pueden desplazarse más rápidamente hacia su posición correcta. Generalmente, se toma como salto inicial la mitad del número de elementos (n / 2) y, en cada iteración, se reduce el salto a la mitad hasta llegar a 1. </p>

## Algoritmo de ordenación Shell
Los pasos generales del algoritmo para una lista de `n` elementos son:
1.  Se divide la lista original en grupos cuyos elementos están separados por un incremento o salto inicial de aproximadamente `n / 2`.
2.  Se compara cada pareja de elementos separados por ese salto. Si no están en orden ascendente, se intercambian o se reubican.
3.  Se reduce el salto a la mitad y se vuelve a recorrer la lista, comparando los elementos que ahora quedan separados por el nuevo salto.
4.  Se repite el proceso, disminuyendo el salto en cada pasada.
5.  El algoritmo termina después de completar la pasada con salto `1`.

> [!NOTE]
> Cuando el número de elementos no permite una división exacta, se utiliza normalmente la división entera para calcular el salto. Por ejemplo, con siete elementos, el primer salto es `7 // 2 = 3`.

## Ejemplo paso a paso

Se desea ordenar de menor a mayor el siguiente arreglo:

``` text
[6, 1, 5, 2, 3, 4, 0]
```

El arreglo contiene siete elementos, por lo que el salto inicial será:

``` text
salto = n // 2
salto = 7 // 2
salto = 3
```

## Primera pasada: salto = 3

Se comparan los elementos que están separados por tres posiciones.

**Primera comparación: 6 y 2**

Los elementos se encuentran en las posiciones `0` y `3`.

``` text
[6, 1, 5, 2, 3, 4, 0]
```

Como `6 <= 2` es falso, se intercambian:

``` text
[2, 1, 5, 6, 3, 4, 0]
```

**Segunda comparación: 1 y 3**

Los elementos se encuentran en las posiciones `1` y `4`.

``` text
1 <= 3  →  Sí
```

No se necesita intercambio:

``` text
[2, 1, 5, 6, 3, 4, 0]
```

**Tercera comparación: 5 y 4**

Los elementos se encuentran en las posiciones `2` y `5`.

``` text
5 <= 4  →  No: intercambio
```

El arreglo queda así:

``` text
[2, 1, 4, 6, 3, 5, 0]
```

**Cuarta comparación: 6 y 0**

Los elementos se encuentran en las posiciones `3` y `6`.

``` text
6 <= 0  →  No: intercambio
```

Después del intercambio:

``` text
[2, 1, 4, 0, 3, 5, 6]
```

**Quinta comparación: 2 y 0**

Al continuar la inserción con salto `3`, se compara el elemento desplazado con el elemento que se encuentra tres posiciones antes:

``` text
2 <= 0  →  No: intercambio
```

El arreglo queda:

``` text
[0, 1, 4, 2, 3, 5, 6]
```

Al finalizar esta pasada, los elementos separados por tres posiciones han quedado ordenados.

## Segunda pasada: salto = 1

Se reduce el salto a la mitad mediante división entera:

``` text
salto = 3 // 2
salto = 1
```

Con salto `1`, se comparan los elementos consecutivos.

**Primera comparación: 0 y 1**

``` text
0 <= 1  →  Sí
```

El arreglo permanece igual:

``` text
[0, 1, 4, 2, 3, 5, 6]
```

**Segunda comparación: 1 y 4**

``` text
1 <= 4  →  Sí
```

No se requiere intercambio.

**Tercera comparación: 4 y 2**

``` text
4 <= 2  →  No: intercambio
```

El arreglo queda:

``` text
[0, 1, 2, 4, 3, 5, 6]
```

**Cuarta comparación: 4 y 3**

``` text
4 <= 3  →  No: intercambio
```

El arreglo queda:

``` text
[0, 1, 2, 3, 4, 5, 6]
```

**Comparaciones restantes**
Se comprueba que los elementos consecutivos restantes están en orden:

``` text
3 <= 4  →  Sí
4 <= 5  →  Sí
5 <= 6  →  Sí
```

El arreglo ya se encuentra ordenado de menor a mayor.

## Condición de comparación

Durante el ejemplo se utiliza la siguiente condición:

``` text
Si (a[j] <= a[k]) Entonces
    El orden es correcto
Sino
    Intercambiar los elementos
```

-   **Si `a[j] <= a[k]` es verdadero:** los elementos están en el orden correcto y no es necesario intercambiarlos.
-   **Si `a[j] <= a[k]` es falso:** los elementos están en el orden incorrecto y deben intercambiarse o reubicarse según el procedimiento de inserción con incrementos.

En las imágenes, `a[j]` representa el elemento que se está evaluando y `a[k]` el elemento con el que se compara, separado por el salto vigente.

## Resultado final

Arreglo original:

``` text
[6, 1, 5, 2, 3, 4, 0]
```

Arreglo ordenado:

``` text
[0, 1, 2, 3, 4, 5, 6]
```

El algoritmo termina cuando el salto llega a `1` y se completa la pasada final. En este ejemplo, los intercambios permiten colocar los elementos en orden ascendente.

## Complejidad temporal
| Caso          | Complejidad                            |
| ---           | ---                                    |
| Mejor caso    | \(O(n \log n)\)                        |
| Caso promedio | Depende de la secuencia de incrementos |
| Peor caso     | \(O(n^2)\)                             |

## Características
- Es una mejora del algoritmo de inserción directa.
- Utiliza saltos decrecientes para comparar elementos alejados entre sí.
- Reduce progresivamente la distancia entre los elementos comparados.
- Su rendimiento depende de la secuencia de saltos utilizada.
- La ordenación termina cuando se procesa el salto de tamaño 1.