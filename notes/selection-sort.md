<h1 align="center">Ordenamiento por Selección (Selection Sort) en C++</h1>

## ¿Qué es?
<p align="justify">Es un algoritmo de ordenamiento que requiere \(O(n^2)\) operaciones para ordenar una lista de \(n\) números. Su funcionamiento consiste en buscar el elemento mínimo de la parte no ordenada de la lista e intercambiarlo con el primer elemento de esa parte. Este proceso se repite hasta que todos los elementos quedan ordenados.</p>

### Funcionamiento
1. Buscar el elemento mínimo de la lista.
2. Intercambiarlo con el primer elemento.
3. Buscar el mínimo del resto de la lista.
4. Intercambiarlo con el segundo elemento.
5. Repetir el proceso sucesivamente hasta ordenar la lista.

## Ejemplo
Partimos de la siguiente lista desordenada:

```text
[4, 3, 1, 5, 2]
```

Los índices de los elementos comienzan en `0`:

| Índice | 0    | 1    | 2    | 3    | 4   |
| ---    | ---: | ---: | ---: | ---: |---: |
| Valor  | 4    | 3    | 1    | 5    | 2   |

### Pasada 1: buscar el mínimo de toda la lista
Buscamos el menor elemento entre `4`, `3`, `1`, `5` y `2`.

El mínimo es `1`, ubicado en el índice `2`.

Intercambiamos el `1` con el primer elemento (`4`).

```text
Antes:  [4, 3, 1, 5, 2]
Después: [1, 3, 4, 5, 2]
```

El primer elemento ya está ordenado.

### Pasada 2: buscar el mínimo del resto de la lista
Ignoramos el primer elemento, porque ya está en su posición correcta.

Buscamos el mínimo entre `3`, `4`, `5` y `2`.

El mínimo es `2`, ubicado en el índice `4`.

Intercambiamos el `2` con el elemento del índice `1`, que es `3`.

```text
Antes:  [1, 3, 4, 5, 2]
Después: [1, 2, 4, 5, 3]
```

Los dos primeros elementos ya están ordenados.

### Pasada 3: buscar el mínimo del resto de la lista
Buscamos el mínimo entre `4`, `5` y `3`.

El mínimo es `3`, ubicado en el índice `4`.

Intercambiamos el `3` con el elemento del índice `2`, que es `4`.

```text
Antes:  [1, 2, 4, 5, 3]
Después: [1, 2, 3, 5, 4]
```

Los tres primeros elementos ya están ordenados.

### Pasada 4: buscar el mínimo del resto de la lista
Buscamos el mínimo entre `5` y `4`.

El mínimo es `4`, ubicado en el índice `4`.

Intercambiamos el `4` con el elemento del índice `3`, que es `5`.

```text
Antes:  [1, 2, 3, 5, 4]
Después: [1, 2, 3, 4, 5]
```

La lista ya está ordenada.

### Resultado final

```text
[1, 2, 3, 4, 5]
```

## Complejidad temporal
| Caso          | Complejidad |
| ---           | ---         |
| Mejor caso    | \(O(n^2)\)  |
| Caso promedio | \(O(n^2)\)  |
| Peor caso     | \(O(n^2)\)  |

El algoritmo sigue buscando el mínimo en la parte no ordenada, incluso si los elementos ya están ordenados.

## Características
- Es sencillo de comprender e implementar.
- Busca el elemento mínimo en cada pasada.
- Realiza, como máximo, \(n-1\) intercambios.
- Tiene complejidad temporal cuadrática en todos los casos.
- Ordena los elementos en el mismo arreglo, sin necesitar otro arreglo de tamaño proporcional a la lista.
- En su implementación habitual, no es estable cuando intercambia elementos directamente.

## Resumen
La idea principal del ordenamiento por selección es **encontrar el elemento más pequeño de la parte no ordenada y colocarlo al principio de esa parte**.

En cada pasada, la sección ordenada aumenta en un elemento, mientras que la sección no ordenada disminuye, hasta completar el ordenamiento.
