<h1 align="center">Búsqueda Binaria Recursiva</h1>

## Contenido
1. [Concepto de búsqueda binaria]()
2. [Funcionamiento del algoritmo]()
3. [División de la lista]()
    - [3.1. Búsqueda en la sublista izquierda]()
    - [3.2. Búsqueda en la sublista derecha]()
4. [Condición de terminación]()
5. [Algoritmo recursivo en C++]() 
    - [5.1. Implementación]()
6. [Resumen de las condiciones]()

# 1. Concepto de búsqueda binaria
La **búsqueda binaria** consiste en localizar un dato específico dentro de una lista o arreglo ordenado de \(n\) elementos. El algoritmo de búsqueda binaria se puede describir recursivamente aplicando la técnica **divide y vencerás**.

Supóngase que se tiene un arreglo ordenado `a[]` con un límite inferior y un límite superior. Dado un dato (valor a buscar), la búsqueda comienza en la posición central de la lista.

Para calcular la posición central se utiliza la siguiente fórmula:

\[mitad = \frac{inferior + superior}{2}\]

Posteriormente, se compara el elemento central con el dato que se desea encontrar:

```cpp
a[mitad] == dato
```

# 2. Funcionamiento del algoritmo
Si se encuentra el dato que se está buscando, se ha alcanzado la condición de terminación que permite detener la búsqueda y devolver el índice central.

Si no se produce la coincidencia, dado que la lista está ordenada, se centra la búsqueda en la **sublista inferior** (a la izquierda de la posición central) o en la **sublista superior** (a la derecha de la posición central); el problema de la búsqueda se ha dividido justamente en la mitad.

Cada vez el tamaño de la secuencia donde buscar se reduce a la mitad, así hasta que se encuentre el elemento, o bien la lista resultante esté vacía.

# 3. División de la lista
Existen dos posibilidades cuando el dato no coincide con el elemento central:

## 3.1. Búsqueda en la sublista izquierda

Si:

\[dato < a[mitad]\]

El valor buscado sólo puede estar en la mitad izquierda de `a[]`, con elementos en el rango inferior a `mitad - 1`.

<text>**Rango de búsqueda:** `inferior ... mitad - 1`</text>

```text
inferior             mitad              superior
    |------------------|-------------------|
    [   Sublista izquierda   ]
```

## 3.2. Búsqueda en la sublista derecha

Si:

\[dato > a[mitad]\]

El valor buscado sólo puede estar en la mitad superior de `a[]`, con elementos en el rango `mitad + 1` a `superior`.

<text>**Rango de búsqueda:** `mitad + 1 ... superior`</text>

```text
inferior             mitad              superior
    |------------------|-------------------|
                       [ Sublista derecha ]
```

# 4. Condición de terminación
La búsqueda continúa en sublistas más y más pequeñas, exactamente la mitad, con dos llamadas recursivas: una se corresponde con la sublista inferior y la otra con la sublista superior.

El algoritmo termina:

- **Con éxito:** aparece el dato buscado y se devuelve su índice.
- **Sin éxito:** no aparece el dato buscado, situación que ocurrirá cuando el límite superior de la lista sea más pequeño que el límite inferior.

La condición:

```cpp
inferior > superior
```

Es la condición de salida o terminación sin éxito y el algoritmo devuelve el índice `-1`.

# 5. Algoritmo recursivo en C++

## 5.1. Implementación

```cpp
int busquedaBinaria(int a[], int dato, int inferior, int superior) {
    int mitad;

    if (inferior > superior) { // No encontrado
        return -1;
    }
    else {
        mitad = (inferior + superior) / 2;

        if (dato == a[mitad]) { // Caso base
            return mitad;
        }
        else if (dato > a[mitad]) { // Casos recursivos
            return busquedaBinaria(a, dato, mitad + 1, superior);
        }
        else {
            return busquedaBinaria(a, dato, inferior, mitad - 1);
        }
    }
}
```

# 6. Resumen de las condiciones
| Condición             | Acción                                        |
| ---                   | ---                                           |
| `inferior > superior` | Devuelve `-1`, el elemento no existe.         |
| `dato == a[mitad]`    | Devuelve `mitad`, el elemento fue encontrado. |
| `dato > a[mitad]`     | Busca recursivamente en la mitad derecha.     |
| `dato < a[mitad]`     | Busca recursivamente en la mitad izquierda.   |