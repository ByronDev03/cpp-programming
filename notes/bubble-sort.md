<h1 align="center">Método Burbuja (Bubble Sort) en C++</h1>

## ¿Qué es?
<p align="justify">Es un sencillo algoritmo de ordenamiento que funciona revisando cada elemento de una lista y comparándolo con el siguiente. Si ambos elementos están en el orden equivocado, se intercambian de posición. Es necesario revisar la lista varias veces hasta que ya no se necesiten más intercambios, lo cual significa que la lista está ordenada.</p>

## Ejemplo
Partimos de la siguiente lista desordenada:

```text
[4, 5, 2, 1, 3]
```

La condición para intercambiar dos elementos es:

```text
Si numeroActual > numeroSiguiente:
    Intercambiar posiciones
```

### Pasada 1
Comparamos los elementos adyacentes de izquierda a derecha.

**Comparación 1:** `4` y `5`

Como `4 < 5`, no se realiza ningún intercambio.

```text
[4, 5, 2, 1, 3]
```

**Comparación 2:** `5` y `2`

Como `5 > 2`, intercambiamos sus posiciones.

```text
[4, 2, 5, 1, 3]
```

**Comparación 3:** `5` y `1`

Como `5 > 1`, intercambiamos sus posiciones.

```text
[4, 2, 1, 5, 3]
```

**Comparación 4:** `5` y `3`

Como `5 > 3`, intercambiamos sus posiciones.

```text
[4, 2, 1, 3, 5]
```

Al finalizar la primera pasada, el número más grande (`5`) queda en la última posición.

### Pasada 2
Volvemos a recorrer la lista, sin necesidad de comparar el último elemento porque ya está en su posición correcta.

**Comparación 1:** `4` y `2`

Como `4 > 2`, intercambiamos sus posiciones.

```text
[2, 4, 1, 3, 5]
```

**Comparación 2:** `4` y `1`

Como `4 > 1`, intercambiamos sus posiciones.

```text
[2, 1, 4, 3, 5]
```

**Comparación 3:** `4` y `3`

Como `4 > 3`, intercambiamos sus posiciones.

```text
[2, 1, 3, 4, 5]
```

Al finalizar esta pasada, el número `4` queda en su posición correcta.

### Pasada 3
**Comparación 1:** `2` y `1`

Como `2 > 1`, intercambiamos sus posiciones.

```text
[1, 2, 3, 4, 5]
```

**Comparación 2:** `2` y `3`

Como `2 < 3`, no se realiza ningún intercambio.

La lista queda así:

```text
[1, 2, 3, 4, 5]
```

### Pasadas restantes
Las siguientes pasadas no producen intercambios porque la lista ya está ordenada.

```text
[1, 2, 3, 4, 5]
```

**Resultado final:** la lista está ordenada de menor a mayor.

## ¿Cómo funciona el algoritmo?
1. Se recorre la lista desde el primer elemento.
2. Se compara cada elemento con el siguiente.
3. Si el elemento actual es mayor que el siguiente, se intercambian.
4. Se continúa hasta llegar al final de la lista.
5. Se repite el proceso hasta ordenar todos los elementos.
6. Si una pasada completa no realiza ningún intercambio, el algoritmo puede terminar anticipadamente.

## Complejidad temporal
| Caso                                          | Complejidad |
| ---                                           | ---         |
| Mejor caso (lista ordenada, con optimización) | \(O(n)\)    |
| Caso promedio                                 | \(O(n^2)\)  |
| Peor caso (lista en orden inverso)            | \(O(n^2)\)  |

## Características
- Es sencillo de comprender e implementar.
- Compara elementos adyacentes.
- Ordena intercambiando elementos que están en el orden equivocado.
- Es un algoritmo estable si solo intercambia elementos cuando el primero es estrictamente mayor que el segundo.
- No necesita un arreglo auxiliar de tamaño proporcional a la lista.
- Es poco eficiente para listas grandes debido a su complejidad cuadrática.
