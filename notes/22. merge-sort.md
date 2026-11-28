<h1 align="center">Ordenación por Mezclas (MergeSort)</h1>

## Contenido
1. [Concepto de MergeSort]()
2. [Ejemplo de ordenamiento]()
    - [2.1. División de la lista]() 
    - [2.2. Mezcla de las sublistas]()
3. [Algoritmo MergeSort]() 
    - [3.1. Implementación del algoritmo MergeSort]()
4. [Algoritmo de mezcla]() 
    - [4.1. Proceso de mezcla]() 
    - [4.2. Implementación del algoritmo de mezcla]()
5. [Implementación en C++]()
6. [Resumen]()

# 1. Concepto de MergeSort
La idea básica de este algoritmo de ordenación es la mezcla (*merge*) de listas ya ordenadas. El algoritmo sigue la típica estrategia **divide y vencerás**. Cada paso se basa en dividir el problema de ordenar \(n\) elementos en dos subproblemas más pequeños, de tamaño mitad, de tal forma que una vez ordenada cada mitad se mezclan para así resolver el problema original.

# 2. Ejemplo de ordenamiento
Seguir la estrategia del algoritmo MergeSort para ordenar la siguiente lista:

```text
[9, 1, 3, 5, 10, 4, 6]
```

## 2.1. División de la lista
Primero, se divide la lista en dos mitades y posteriormente se continúa dividiendo cada sublista hasta obtener elementos individuales.

```text
                 [9, 1, 3, 5, 10, 4, 6]
                       /        \
             [9, 1, 3, 5]      [10, 4, 6]
               /      \          /    \
           [9, 1]    [3, 5]   [10, 4]  [6]
            / \       / \       / \
          [9] [1]   [3] [5]   [10] [4]
```

## 2.2. Mezcla de las sublistas
Una vez que todos los elementos se encuentran separados, comienza el proceso de mezcla, combinando las sublistas y ordenando sus elementos.

```text
[9] + [1]       → [1, 9]
[3] + [5]       → [3, 5]
[10] + [4]      → [4, 10]

[1, 9] + [3, 5] → [1, 3, 5, 9]
[4, 10] + [6]   → [4, 6, 10]

[1, 3, 5, 9] + [4, 6, 10]
                 ↓
        [1, 3, 4, 5, 6, 9, 10]
```

**Resultado final:**

```text
[1, 3, 4, 5, 6, 9, 10]
```

# 3. Algoritmo MergeSort
Este algoritmo de ordenación se diseña fácilmente con ayuda de las llamadas recursivas para dividir las listas en dos mitades; posteriormente se invoca a la función de mezcla de dos listas ordenadas.

La delimitación de las dos listas se hace con tres índices: primero, central y último.

Así, si se tiene una lista de 10 elementos, los valores de los índices son:

```cpp
primero = 0;
ultimo = 9;
central = (primero + ultimo) / 2; // 4
```

La primera sublista comprende los elementos `a[0] ... a[4]`, y la segunda los elementos siguientes `a[5] ... a[9]`.

## 3.1. Implementación del algoritmo MergeSort

```cpp
void mergesort(int a[], int primero, int ultimo) {
    int central;

    if (primero < ultimo) {
        central = (primero + ultimo) / 2;

        mergesort(a, primero, central);
        // Ordena primera mitad de la lista

        mergesort(a, central + 1, ultimo);
        // Ordena segunda mitad de la lista

        mezcla(a, primero, central, ultimo);
        // Fusiona las dos sublistas ordenadas,
        // delimitadas por los extremos
    }
}
```

# 4. Algoritmo de mezcla
El algoritmo de mezcla utiliza un arreglo auxiliar, `aux[]`, para realizar la mezcla entre dos sublistas ordenadas, que se encuentran en el vector `a[]`, delimitadas por los índices izquierda, medio y derecha.

A partir de estos índices se pueden recorrer las sublistas con las variables `i`, `k`.

En cada pasada del algoritmo de mezcla se compara `a[i]` con `a[k]`, el menor se copia en el vector auxiliar, `aux[]`, y avanzan los índices de la sublista y del vector auxiliar.

## 4.1. Proceso de mezcla
Se tienen dos sublistas ordenadas:

```text
Primera sublista:  [1, 9]
Segunda sublista:  [3, 5]
```

Se comparan los elementos de ambas sublistas:

| Comparación | Elemento copiado en `aux[]` |
| ---         | ---                         |
| 1 y 3       | 1                           |
| 9 y 3       | 3                           |
| 9 y 5       | 5                           |
| 9 y —       | 9                           |

El resultado del arreglo auxiliar será:

```text
aux = [1, 3, 5, 9]
```

Los índices utilizados son:

- `i`: recorre la primera sublista.
- `k`: recorre la segunda sublista.
- `z`: recorre el arreglo auxiliar.

## 4.2. Implementación del algoritmo de mezcla

```cpp
void mezcla(int a[], int izquierda, int medio, int derecha) {
    int* aux;
    int i, k, z;

    aux = new int[derecha - izquierda + 1];

    i = z = izquierda;
    k = medio + 1;

    // Bucle para la mezcla, utiliza aux[] como arreglo auxiliar
    while (i <= medio && k <= derecha) {
        if (a[i] <= a[k]) {
            aux[z++] = a[i++];
        }
        else {
            aux[z++] = a[k++];
        }
    }

    // Se mueven elementos no mezclados de las sublistas
    while (i <= medio) {
        aux[z++] = a[i++];
    }

    while (k <= derecha) {
        aux[z++] = a[k++];
    }

    // Copia de elementos de aux[] hacia a[]
    for (int i = izquierda; i <= derecha; i++) {
        a[i] = aux[i];
    }

    delete aux;
}
```

# 5. Implementación en C++
Para utilizar MergeSort se necesitan dos funciones:

- `mergesort()`: divide recursivamente el arreglo en dos mitades hasta obtener sublistas de un solo elemento y después invoca la función de mezcla.
- `mezcla()`: combina las dos sublistas ordenadas en un arreglo auxiliar y devuelve los elementos ordenados al arreglo original.

# 6. Resumen
**MergeSort (ordenación por mezclas)** es un algoritmo de ordenamiento que utiliza la estrategia **Divide y Vencerás**. Consiste en dividir recursivamente un arreglo en sublistas más pequeñas hasta obtener elementos individuales. Posteriormente, mediante el proceso de mezcla (*merge*), combina las sublistas ordenándolas hasta obtener el arreglo completo ordenado.

El algoritmo utiliza dos funciones principales: `mergesort()`, que realiza la división recursiva, y `mezcla()`, que combina las sublistas utilizando un arreglo auxiliar.

**Complejidad:**

- **Mejor caso:** \(O(n \log n)\).
- **Caso promedio:** \(O(n \log n)\).
- **Peor caso:** \(O(n \log n)\).
- **Espacio auxiliar:** \(O(n)\).

En conclusión, MergeSort es un algoritmo eficiente y estable para ordenar grandes cantidades de elementos, aunque requiere memoria adicional para realizar el proceso de mezcla.