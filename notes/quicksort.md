<h1 align="center">Ordenación Rápida (QuickSort) en C++</h1>

## ¿Qué es?
<p align="justify">Es un método de ordenación basado en la técnica divide y vencerás. Su funcionamiento consiste en dividir una lista de elementos en particiones más pequeñas para ordenarlas de manera independiente. Es un algoritmo conocido por su eficiencia en la práctica, su implementación relativamente compacta y su uso de la recursividad. El algoritmo divide los \(n\) elementos de la lista en dos particiones separadas por un elemento denominado pivote:</p>

- **Partición izquierda:** contiene los elementos menores o iguales que el pivote.
- **Pivote:** elemento que se utiliza como referencia para dividir la lista.
- **Partición derecha:** contiene los elementos mayores o iguales que el pivote.

Una vez realizada la partición, las dos sublistas se ordenan de manera independiente mediante llamadas recursivas al mismo algoritmo.

## Algoritmo QuickSort
Los pasos que sigue el algoritmo QuickSort son:

1. Seleccionar un elemento de la lista como **pivote**.
2. Dividir los elementos restantes en particiones izquierda y derecha, de modo que ningún elemento de la izquierda tenga una clave mayor que el pivote y que ningún elemento a la derecha tenga una clave más pequeña que la del pivote.
3. Ordenar la partición izquierda utilizando QuickSort recursivamente.
4. Ordenar la partición derecha utilizando QuickSort recursivamente.
5. Obtener la lista ordenada mediante la combinación de la partición izquierda, el pivote y la partición derecha.

**Nota:** el pivote puede elegirse de distintas maneras. En el ejemplo siguiente se selecciona el elemento central de la lista.

## Ejemplo de ejecución
Consideremos el siguiente arreglo de números:

```cpp
int a[] = {8, 3, 6, 4, 2, 5, 7, 1};
```

### Seleccionar el pivote
Primero, calculamos la posición central del arreglo mediante la siguiente fórmula:

```cpp
central = (primero + ultimo) / 2;
```

Como el primer índice es `0` y el último es `7`:

```cpp
central = (0 + 7) / 2;
central = 3;
```

Después, obtenemos el valor del pivote:

```cpp
pivote = a[central];
pivote = a[3];
pivote = 4;
```

Por tanto, el pivote es el número `4`, ubicado en el índice `3`.

| Índice | 0     | 1    | 2     | **3** | 4     | 5     | 6     | 7     |
| :---:  | :---: |:---: | :---: | :---: | :---: | :---: | :---: | :---: |
| Valor  | 8     | 3    | 6     | **4** | 2     | 5     | 7     | 1     |

### Utilizar los índices `i` y `j`
Para realizar la partición, se utilizan dos índices que recorren el arreglo:

- `i`: avanza desde la izquierda buscando un elemento que deba colocarse a la derecha del pivote.
- `j`: retrocede desde la derecha buscando un elemento que deba colocarse a la izquierda del pivote.

Cuando ambos encuentran elementos que están en el lado incorrecto, se intercambian sus valores.

#### Estado inicial

```text
Arreglo:  [8, 3, 6, 4, 2, 5, 7, 1]
Índices:   0  1  2  3  4  5  6  7
Pivote: 4 (índice 3)
```

Inicialmente, `i` apunta al primer elemento (`8`) y `j` al último (`1`).

Como `8` es mayor que el pivote y `1` es menor que el pivote, ambos valores deben intercambiarse.

#### Primer intercambio

Intercambiamos `8` y `1`:

```text
Antes:   [8, 3, 6, 4, 2, 5, 7, 1]
Después: [1, 3, 6, 4, 2, 5, 7, 8]
```

Ahora, `1` está en la partición izquierda y `8` en la derecha.

#### Continuar la búsqueda

El índice `i` avanza hasta encontrar el `6`, que es mayor que el pivote `4`. Por su parte, `j` retrocede hasta encontrar el `2`, que es menor que el pivote.

Por lo tanto, intercambiamos ambos valores:

```text
Antes:   [1, 3, 6, 4, 2, 5, 7, 8]
Después: [1, 3, 2, 4, 6, 5, 7, 8]
```

El arreglo queda dividido alrededor del pivote `4`:

| Partición izquierda | Pivote | Partición derecha |
| :---:               | :---:  |:---:              |
| 1, 3, 2             | **4**  | 6, 5, 7, 8        |

La partición izquierda contiene valores menores que el pivote y la derecha contiene valores mayores que él.

**Importante:** que los elementos estén en la partición correcta no significa que cada partición ya esté ordenada.

### Ordenar recursivamente la partición izquierda
Aplicamos QuickSort a la sublista:

```cpp
int izquierda[] = {1, 3, 2, 4};
```

Para esta sublista, los índices son del `0` al `3`. Calculamos el índice central:

```cpp
central = (0 + 3) / 2;
central = 1;

pivote = izquierda[1];
pivote = 3;
```

El pivote de esta llamada recursiva es `3`.

El índice `i` avanza desde la izquierda y el índice `j` desde la derecha. Al encontrar que `3` y `2` están en posiciones que deben intercambiarse, se realiza el intercambio:

```text
Antes:   [1, 3, 2, 4]
Después: [1, 2, 3, 4]
```

La sublista queda ordenada:

| Índice | 0     | 1     | 2     | 3     |
| :---:  | :---: | :---: | :---: | :---: |
| Valor  | 1     | 2     | 3     | 4     |

### Estado del ejemplo hasta este punto
Después de ordenar la partición izquierda, tenemos:

```text
Partición izquierda: [1, 2, 3, 4]
Partición derecha:   [6, 5, 7, 8]
```

La partición derecha todavía necesita ordenarse mediante otra llamada recursiva a QuickSort.

**Continuación pendiente:** ordenar la partición derecha y completar el proceso hasta obtener el arreglo totalmente ordenado.

### Ordenar la partición derecha
Ahora aplicamos QuickSort a la partición derecha, que contiene los siguientes elementos:

```cpp
int derecha[] = {6, 5, 7, 8};
```

Los índices originales de estos elementos van del `4` al `7`. Calculamos la posición central:

```cpp
central = (primero + ultimo) / 2;
central = (4 + 7) / 2;
central = 5;
```

El pivote corresponde al elemento situado en el índice `5`:

```cpp
pivote = a[central];
pivote = a[5];
pivote = 5;
```

La partición derecha queda representada de la siguiente manera:

| Índice | 4     | **5** | 6     | 7     |
| :---:  | :---: | :---: | :---: | :---: |
| Valor  | 6     | **5** | 7     | 8     |

El pivote es `5`. Durante el recorrido, los índices `i` y `j` avanzan desde extremos opuestos para encontrar elementos que deban intercambiarse.

En este caso, el `6` se encuentra a la izquierda del pivote y debe quedar a su derecha. Al intercambiarlo con el `5`, obtenemos:

```text
Antes:   [6, 5, 7, 8]
Después: [5, 6, 7, 8]
```

La partición derecha queda ordenada:

| Índice | 4     | 5     | 6     | 7     |
| :---:  | :---: | :---: | :---: | :---: |
| Valor  | 5     | 6     | 7     | 8     |

### Resultado final
Una vez ordenadas ambas particiones, el arreglo completo queda de la siguiente manera:

```cpp
int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
```

| Índice | 0     | 1     | 2     | 3     | 4     | 5     | 6     | 7     |
| :---:  | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| Valor  | 1     | 2     | 3     | 4     | 5     | 6     | 7     | 8     |

**Resultado:** el arreglo está ordenado de forma ascendente.

### Resumen del proceso
El funcionamiento de QuickSort puede resumirse en los siguientes pasos:yy
1. Seleccionar un pivote.
2. Recorrer el arreglo mediante los índices `i` y `j`.
3. Intercambiar los elementos que se encuentran en la partición incorrecta.
4. Repetir el procedimiento recursivamente con las particiones izquierda y derecha.
5. Continuar hasta que las sublistas tengan cero o un elemento, ya que en ese punto están ordenadas.

La principal ventaja de QuickSort es que ordena los elementos mediante particiones sucesivas, sin necesitar combinar explícitamente las sublistas al finalizar cada llamada recursiva.

## Complejidad temporal:
| Caso          | Complejidad     |
| ---           |---              |
| Mejor caso    | \(O(n \log n)\) |
| Caso promedio | \(O(n \log n)\) |
| Peor caso     | \(O(n^2)\)      |

El peor caso puede presentarse cuando el pivote divide repetidamente el arreglo de forma muy desigual. La elección del pivote influye considerablemente en el rendimiento del algoritmo.