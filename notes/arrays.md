<h1 align="center">Vectores (arreglos unidimensionales) en C++</h1>

## 1. ¿Qué es un vector o arreglo?
Un **vector** o *array unidimensional* es un tipo de dato que permite almacenar una secuencia de elementos del mismo tipo. Los elementos se almacenan en posiciones contiguas de memoria y se puede acceder a cada uno de ellos de manera directa mediante un **índice o posición**.

Por ejemplo, el siguiente vector contiene cinco números:
| Índice | Valor |
| :----: | :---: |
|    0   |   2   |
|    1   |   5   |
|    2   |   8   |
|    3   |   1   |
|    4   |   9   |

En C++, los índices de un vector comienzan en **0**, por lo que el primer elemento está en la posición `0` y el último en la posición `n - 1`, donde `n` es el número de elementos.

## 2. Declaración de un vector

Para declarar un vector en C++ se utiliza la siguiente sintaxis:

```cpp
tipo nombre[tamaño];
```

- `tipo`: indica el tipo de dato que almacenará el vector.
- `nombre`: es el identificador del vector.
- `tamaño`: indica la cantidad de elementos que puede almacenar.

### Ejemplos

```cpp
int numeros[10];
char letras[5];
float reales[15];
```

En estos ejemplos:

- `numeros` puede almacenar 10 números enteros.
- `letras` puede almacenar 5 caracteres.
- `reales` puede almacenar 15 números de tipo `float`.

## 3. Inicialización de un vector

Un vector puede inicializarse al momento de declararlo, asignando sus valores entre llaves `{}` y separados por comas.

### Ejemplo 1: vector de números enteros

```cpp
int numero[] = {1, 4, 6, 7, 3};
```

En este caso, el tamaño se determina automáticamente a partir de los cinco valores proporcionados.

| Índice | Valor |
| :----: | :---: |
|    0   |   1   |
|    1   |   4   |
|    2   |   6   |
|    3   |   7   |
|    4   |   3   |

También podemos acceder individualmente a cada elemento mediante su índice:

```cpp
numero[0] = 1;
numero[1] = 4;
numero[2] = 6;
numero[3] = 7;
numero[4] = 3;
```

**Importante:** los índices permiten consultar o modificar los elementos del vector. Por ejemplo, `numero[2]` hace referencia al tercer elemento, cuyo valor es `6`.

### Ejemplo 2: vector de caracteres

```cpp
char letra[] = {'a', 'e', 'i', 'o', 'u'};
```

Este vector almacena las cinco vocales en minúsculas.

| Índice | Valor |
| :----: | :---: |
|    0   | `'a'` |
|    1   | `'e'` |
|    2   | `'i'` |
|    3   | `'o'` |
|    4   | `'u'` |

Podemos acceder a cada vocal de la siguiente manera:

```cpp
letra[0] = 'a';
letra[1] = 'e';
letra[2] = 'i';
letra[3] = 'o';
letra[4] = 'u';
```

**Nota:** en C++, los valores de tipo `char` se escriben entre comillas simples, como `'a'`, mientras que las cadenas de texto se escriben entre comillas dobles, como `"Hola"`.

## 4. Resumen

| Concepto       | Descripción                                       |
| -------------- | ------------------------------------------------- |
| Vector o array | Estructura que almacena elementos del mismo tipo. |
| Índice         | Posición que permite acceder a un elemento.       |
| Declaración    | Define el tipo, nombre y tamaño del vector.       |
| Inicialización | Asigna valores iniciales a los elementos.         |
| Primer índice  | `0`                                               |
| Último índice  | `tamaño - 1`                                      |

### Ejemplo completo

```cpp
#include <iostream>
using namespace std;

int main() {
    int numero[] = {1, 4, 6, 7, 3};

    cout << "Primer elemento: " << numero[0] << endl;
    cout << "Tercer elemento: " << numero[2] << endl;
    cout << "Ultimo elemento: " << numero[4] << endl;

    return 0;
}
```

**Salida esperada:**

```text
Primer elemento: 1
Tercer elemento: 6
Ultimo elemento: 3
```

**Recuerda:** acceder a un índice fuera de los límites del vector produce un comportamiento indefinido en C++. Para un vector de cinco elementos, los índices válidos son del `0` al `4`.
