<h1 align="center">Ordenamiento por Inserción (Insertion Sort) en C++</h1>

## ¿Qué es el ordenamiento por inserción?
Es una manera muy natural de ordenar para un ser humano. Puede utilizarse fácilmente para ordenar un mazo de cartas numeradas en forma arbitraria. El algoritmo recorre una lista y va insertando cada elemento en su posición correcta dentro de la parte que ya está ordenada. Su complejidad temporal promedio y en el peor caso es **\(O(n^2)\)** para ordenar una lista de \(n\) elementos. Sin embargo, si la lista ya está ordenada, su complejidad es **\(O(n)\)**.

## Ejemplo
Partimos de la siguiente lista desordenada:

```text
[5, 3, 4, 1, 2]
```

### Paso 1. Seleccionar el primer elemento
```text
[5, 3, 4, 1, 2]
 ↑
```

El primer elemento (`5`) se considera inicialmente ordenado, ya que una lista con un solo elemento siempre está ordenada.

### Paso 2. Comparar el segundo elemento
Seleccionamos el número `3` y lo comparamos con los elementos de su izquierda.

```text
[5, 3, 4, 1, 2]
    ↑
```

Si el elemento de la izquierda es mayor que el elemento actual, se desplaza hacia la derecha para dejar espacio.

Como `5 > 3`, intercambiamos sus posiciones:

```text
[3, 5, 4, 1, 2]
```

Ahora la parte ordenada es `[3, 5]` (en el sentido de que el elemento actual ya se insertó en su posición correcta, aunque aquí la parte ordenada correcta debe quedar como `[3, 5]`).

### Paso 3. Insertar el número 4
Seleccionamos el número `4`:

```text
[3, 5, 4, 1, 2]
       ↑
```

Comparamos con el elemento de su izquierda:

- `5 > 4`: desplazamos el `5` a la derecha.
- `3 < 4`: encontramos su posición correcta.

Resultado:

```text
[3, 4, 5, 1, 2]
```

### Paso 4. Insertar el número 1
Seleccionamos el número `1`:

```text
[3, 4, 5, 1, 2]
          ↑
```

Como `5`, `4` y `3` son mayores que `1`, se desplazan hacia la derecha.

Resultado:

```text
[1, 3, 4, 5, 2]
```

### Paso 5. Insertar el número 2
Seleccionamos el número `2`:

```text
[1, 3, 4, 5, 2]
             ↑
```

Comparamos con los elementos de su izquierda:

- `5 > 2`: desplazamos el `5`.
- `4 > 2`: desplazamos el `4`.
- `3 > 2`: desplazamos el `3`.
- `1 < 2`: encontramos su posición correcta.

Resultado:

```text
[1, 2, 3, 4, 5]
```

La lista ya está ordenada.

## ¿Cómo funciona el algoritmo?
1. Se considera que el primer elemento está ordenado.
2. Se selecciona el siguiente elemento de la lista, llamado **elemento actual** o `key`.
3. Se compara con los elementos anteriores.
4. Mientras los elementos anteriores sean mayores que el actual, se desplazan una posición hacia la derecha.
5. Se inserta el elemento actual en la posición que le corresponde.
6. Se repite el proceso hasta recorrer toda la lista.

## Complejidad temporal
| Caso                               | Complejidad |
| ---                                | ---         |
| Mejor caso (lista ordenada)        | \(O(n)\)    |
| Caso promedio                      | \(O(n^2)\)  |
| Peor caso (lista en orden inverso) | \(O(n^2)\)  |

## Características:
- Es un algoritmo sencillo de implementar.
- Es eficiente para listas pequeñas o casi ordenadas.
- Es un algoritmo de ordenamiento estable.
- Ordena en el mismo arreglo, sin necesitar otra estructura de tamaño proporcional a la lista.
- Puede realizar muchos desplazamientos cuando la lista está muy desordenada.
