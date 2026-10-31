<h1 align="center">Arrays Bidimensionales (Matrices o Tablas) en C++</h1>

## ¿Qué es?
Una **matriz** es un arreglo de arreglos, también conocido como *array bidimensional*. Permite almacenar datos del mismo tipo organizados en filas y columnas.

En C++, la forma de declarar una matriz es similar a la de un vector, pero se utilizan dos dimensiones: una para las filas y otra para las columnas.

## Declarando una matriz en C++
Para declarar una matriz se utiliza la siguiente sintaxis:

```cpp
tipo nombre[nfilas][ncolumnas];
```

- `tipo`: tipo de dato que almacenará la matriz.
- `nombre`: identificador de la matriz.
- `nfilas`: cantidad de filas.
- `ncolumnas`: cantidad de columnas.

### Ejemplos
```cpp
int numeros[2][3];
char letras[3][2];
```

En estos ejemplos:

- `numeros` tiene 2 filas y 3 columnas, por lo que puede almacenar 6 números enteros.
- `letras` tiene 3 filas y 2 columnas, por lo que puede almacenar 6 caracteres.

### Representación de una matriz
Una matriz de \(n\) filas y \(m\) columnas se organiza de la siguiente manera:

|  | Columna 0 | Columna 1 | Columna 2 | ... | Columna m-1 |
|:---:|:---:|:---:|:---:|:---:|:---:|
| **Fila 0** | | | | ... | |
| **Fila 1** | | | | ... | |
| **Fila 2** | | | | ... | |
| **...** | | | | ... | |
| **Fila n-1** | | | | ... | |

Los índices de las filas y las columnas comienzan en `0`.

## Agregar elementos a una matriz
Podemos inicializar una matriz al momento de declararla, asignando los valores entre llaves `{}`.

### Primera forma: inicialización sin separar las filas
```cpp
int numeros[2][3] = {1, 2, 3, 4, 5, 6};
```

Los valores se asignan de izquierda a derecha y de arriba hacia abajo.

La matriz resultante es:

| Índice de fila / columna | Columna 0 | Columna 1 | Columna 2 |
| :---:                    | :---:     | :---:     | :---:     |
| **Fila 0**               | 1         | 2         | 3         |
| **Fila 1**               | 4         | 5         | 6         |

### Segunda forma: inicialización separando las filas
También podemos utilizar llaves internas para agrupar los elementos de cada fila:

```cpp
int numeros[2][3] = {{1, 2, 3}, {4, 5, 6}};
```

La primera lista `{1, 2, 3}` corresponde a la fila 0 y la segunda `{4, 5, 6}` corresponde a la fila 1.

La matriz resultante es la misma:

| Índice de fila / columna | Columna 0 | Columna 1 | Columna 2 |
| :---:                    | :---:     | :---:     | :---:     |
| **Fila 0**               | 1         | 2         | 3         |
| **Fila 1**               | 4         | 5         | 6         |

## Acceder a los elementos de una matriz
Para acceder a un elemento específico se utilizan dos índices:

```cpp
nombre[fila][columna]
```

- El primer índice indica la fila.
- El segundo índice indica la columna.

Tomando como ejemplo la matriz anterior:

```cpp
int numeros[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

Podemos consultar sus elementos mediante `cout`:

```cpp
cout << numeros[1][2];  // 6
cout << numeros[0][1];  // 2
```

La matriz se interpreta de la siguiente manera:

|  | Columna 0 | Columna 1 | Columna 2 |
|:---:|:---:|:---:|:---:|
| **Fila 0** | 1 | **2** | 3 |
| **Fila 1** | 4 | 5 | **6** |

Por lo tanto:

- `numeros[1][2]` devuelve `6`, porque corresponde a la fila 1 y columna 2.
- `numeros[0][1]` devuelve `2`, porque corresponde a la fila 0 y columna 1.

**Importante:** para acceder a un elemento, ambos índices deben estar dentro de los límites de la matriz. En `numeros[2][3]`, las filas válidas son `0` y `1`, mientras que las columnas válidas son `0`, `1` y `2`.

## Ejemplo completo
```cpp
#include <iostream>
using namespace std;

int main() {
    int numeros[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    cout << "Elemento en [1][2]: "
         << numeros[1][2] << endl;

    cout << "Elemento en [0][1]: "
         << numeros[0][1] << endl;

    return 0;
}
```

**Salida esperada:**

```text
Elemento en [1][2]: 6
Elemento en [0][1]: 2
```

## Resumen
| Concepto                     | Descripción                                         |
| ---                          | ---                                                 |
| Matriz o array bidimensional | Estructura de datos organizada en filas y columnas. |
| Fila                         | Primera dimensión de la matriz.                     |
| Columna                      | Segunda dimensión de la matriz.                     |
| Declaración                  | `tipo nombre[filas][columnas];`                     |
| Acceso a un elemento         | `nombre[fila][columna]`                             |
| Primer elemento              | `nombre[0][0]`                                      |
| Índice de la última fila     | `filas - 1`                                         |
| Índice de la última columna  | `columnas - 1`                                      |

**Recuerda:** en una matriz de C++, primero se indica la fila y después la columna. Por ejemplo, `numeros[1][2]` hace referencia al elemento situado en la segunda fila y la tercera columna.