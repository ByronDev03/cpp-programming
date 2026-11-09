<h1 align="center">Árboles en C++</h1>

## Contenido

1. [Concepto de árbol]()
    - [1.1. Elementos de un árbol]()
    - [1.2. Ejemplo de un árbol]()
    - [1.3. Propiedades de los árboles]()
    - [1.4. Longitud de camino]()
    - [1.5. Altura de un nodo]()
    - [1.6. Profundidad y nivel de un nodo]()
    - [1.7. Distribución de niveles]()
    - [1.8. Nodos hermanos]()
    - [1.9. Orden de un árbol]()
        - [1.9.1. Ejemplos de orden de un árbol]()
2. [Concepto de árbol binario]()
    - [2.1. Estructura recursiva]()
    - [2.2. Representación de un árbol binario]()
    - [2.3. Tipos de árboles binarios]()
        - [2.3.1. Árbol lleno]()
        - [2.3.2. Árbol completo]()
        - [2.3.3. Árbol degenerado]()
    - [2.4. Estructura de un árbol binario en C++]()
    - [2.5. Estructura del nodo]()
    - [2.6. Componentes]()
    - [2.7. Representación de la estructura]()
3. [Árbol binario de búsqueda]()
    - [3.1. Concepto de árbol binario de búsqueda]()
    - [3.2. Ejemplo de inserción de elementos]()
    - [3.3. Reglas de inserción]()
    - [3.4. Ejemplo de construcción de un árbol binario de búsqueda]()
    - [3.5. Operaciones en árboles binarios de búsqueda]()
4. [Insertar un nodo en el árbol binario de búsqueda ABB]()
    - []()
    - []()
    - []()
5. [Mostrar el árbol completo]()
    - []()
    - []()
    - []()
6. [Búsqueda de un nodo en el árbol]()
    - [6.1. Definición de la función]()
    - [6.2. Condiciones de búsqueda]()
    - [6.3. Ejemplo de búsqueda]()
    - [6.4. Código completo de la función]()
    - [6.5. Resumen del funcionamiento]()
[]()
- []()
- []()
- []()

---

# 1. Concepto de árbol
Un **árbol** es una estructura de datos no lineal que consta de un conjunto finito de elementos, denominados **nodos**, y un conjunto finito de líneas dirigidas, denominadas **ramas**, que conectan los nodos.
Los árboles permiten representar relaciones jerárquicas entre sus elementos.

## 1.1. Elementos de un árbol
Dentro de un árbol podemos identificar los siguientes elementos:

- **Raíz:** es el nodo principal del árbol, del cual parten las demás ramas. No tiene un nodo padre.
- **Nodo hijo:** es un nodo que depende directamente de otro nodo, denominado padre.
- **Nodo hoja:** es un nodo que no tiene hijos, es decir, no tiene ramas que salgan de él.
- **Rama:** es la conexión dirigida que existe entre dos nodos.

## 1.2. Ejemplo de un árbol
```text
             A  ← Raíz
           /   \
          B     C   ← Nodo hijo
         / \     \
        D   E     F  ← Hojas
```

En este ejemplo:
- `A` es la raíz del árbol.
- `B` y `C` son hijos de `A`.
- `D` y `E` son hijos de `B`.
- `F` es hijo de `C`.
- `D`, `E` y `F` son nodos hoja.

## 1.3. Propiedades de los árboles
Las propiedades de un árbol permiten analizar su estructura, las relaciones entre sus nodos y la distancia que existe entre ellos.
Para explicar estas propiedades utilizaremos el siguiente árbol como ejemplo:

```text
                16
              /    \
             8      24
            / \     /
           3   13  19
            \        \
             7        21
```

## 1.4. Longitud de camino
La **longitud de camino** de un nodo es la cantidad de ramas o aristas que se deben recorrer desde la raíz hasta llegar a dicho nodo.
**Ejemplo:**

Para llegar desde la raíz (`16`) hasta el nodo `7`, debemos recorrer las siguientes ramas:

```text
16 → 8 → 3 → 7
```

Por lo tanto:

- De `16` a `8`: 1 rama.
- De `8` a `3`: 1 rama.
- De `3` a `7`: 1 rama.

**Longitud de camino del nodo 7 = 3.**

## 1.5. Altura de un nodo
La **altura de un nodo** es la cantidad de ramas que existen en el camino más largo desde ese nodo hasta una hoja descendiente.
**Ejemplo:**

Para calcular la altura del nodo `24`, observamos su camino más largo hasta una hoja:

```text
24 → 19 → 21
```

Por lo tanto:

- De `24` a `19`: 1 rama.
- De `19` a `21`: 1 rama.

**Altura del nodo 24 = 2.**

La altura de un árbol es la altura de su raíz, es decir, la longitud del camino más largo desde la raíz hasta una hoja.

## 1.6. Profundidad y nivel de un nodo
La **profundidad de un nodo** es la cantidad de ramas que existen desde la raíz hasta dicho nodo.
El **nivel** representa la posición jerárquica de un nodo dentro del árbol. En esta convención, el nivel coincide con la profundidad y la raíz comienza en el nivel 0.

## 1.7. Distribución de niveles
```text
Nivel 0:              16

Nivel 1:           8      24

Nivel 2:         3   13  19

Nivel 3:          7       21
```

**Ejemplos:**
- La profundidad del nodo `19` es 2, porque desde la raíz hasta él existen dos ramas.
- El nodo `19` se encuentra en el nivel 2.
- La raíz `16` tiene profundidad y nivel 0.

## 1.8. Nodos hermanos
Los **nodos hermanos** son aquellos que comparten el mismo nodo padre.
**Ejemplo:**
En el siguiente árbol:

```text
                16
              /    \
             8      24
            / \     /
           3   13  19
            \        \
             7        21
```

Los nodos `3` y `13` son hermanos porque ambos tienen como padre al nodo `8`.

**Características:**

- Comparten el mismo nodo padre.
- Pueden encontrarse en el mismo nivel.
- No necesariamente tienen hijos.

## 1.9. Orden de un árbol
El **orden de un árbol** es la cantidad máxima de hijos que puede tener un nodo.
En un árbol binario, el orden es 2, lo que significa que cada nodo puede tener:

1. **Cero hijos:** no tiene hijos.
2. **Un hijo:** puede tener únicamente un hijo izquierdo o derecho.
3. **Dos hijos:** tiene un hijo izquierdo y uno derecho.

## 1.9.1. Ejemplos de orden de un árbol
**Nodo sin hijos:**

```text
   16
```

**Nodo con un hijo:**

```text
    16
   /
  8
```

**Nodo con dos hijos:**

```text
     16
    /  \
   8    24
```

Por lo tanto, en un árbol binario ningún nodo puede tener más de dos hijos.

---

# 2. Concepto de árbol binario
Un **árbol binario** es un árbol de orden 2, es decir, cada nodo puede tener como máximo dos hijos:
- **Hijo izquierdo:** nodo que se encuentra en la rama izquierda.
- **Hijo derecho:** nodo que se encuentra en la rama derecha.

Un árbol binario puede contener nodos con dos hijos, un solo hijo o ningún hijo.

## 2.1. Estructura recursiva
Un árbol binario es una **estructura de datos recursiva** que se divide en tres subconjuntos disjuntos:
1. **Nodo raíz:** es el nodo principal del árbol, del cual parten los demás nodos.
2. **Subárbol izquierdo:** es el árbol binario que se encuentra a la izquierda del nodo raíz.
3. **Subárbol derecho:** es el árbol binario que se encuentra a la derecha del nodo raíz.

Cada subárbol también puede dividirse recursivamente en una raíz, un subárbol izquierdo y un subárbol derecho.

## 2.2. Representación de un árbol binario
```text
             R
           /   \
          I     D
         / \     \
        A   B     C
```

- **R:** nodo raíz.
- **I:** subárbol izquierdo.
- **D:** subárbol derecho.
- **A, B y C:** nodos pertenecientes a los respectivos subárboles.

## 2.3. Tipos de árboles binarios
Los árboles binarios pueden clasificarse de diferentes maneras según la distribución y organización de sus nodos.

## 2.3.1. Árbol lleno
Un árbol lleno (también conocido como árbol perfecto en la terminología habitual) es aquel en el que todos sus niveles están completamente ocupados.
Cada nodo interno tiene exactamente dos hijos y todas las hojas se encuentran en el mismo nivel.
**Representación:**

```text
             A
           /   \
          B     C
         / \   / \
        D   E F   G
```

**Características:**
- Todos los niveles están completos.
- Cada nodo interno tiene exactamente dos hijos.
- Todas las hojas se encuentran en el mismo nivel.

## 2.3.2. Árbol completo
Un árbol binario completo es aquel en el que todos los niveles están completamente ocupados, excepto posiblemente el último.
Los nodos del último nivel deben estar colocados de izquierda a derecha, sin dejar espacios entre ellos.
**Representación:**
```text
              A
            /   \
           B     C
          / \   / \
         D   E F   G
        / \
       H   I
```

**Características:**
- Todos los niveles, excepto posiblemente el último, están completos.
- Los nodos del último nivel se colocan de izquierda a derecha.
- No existen espacios vacíos entre los nodos del último nivel.

## 2.3.3. Árbol degenerado
Un árbol degenerado es aquel en el que cada nodo tiene como máximo un hijo.
Su estructura se asemeja a una lista enlazada, ya que los nodos forman una única secuencia de elementos.
**Representación:**
```text
       A
        \
         B
          \
           C
          /
         D
          \
           E
```

**Características:**
- Cada nodo tiene como máximo un hijo.
- No existen nodos con dos hijos.
- Su estructura se asemeja a una lista enlazada.
- Puede presentar una mayor profundidad que otros árboles con la misma cantidad de nodos.

## 2.4. Estructura de un árbol binario en C++
Para implementar un árbol binario en C++ se utiliza una estructura `struct` que permite almacenar el dato de cada nodo y dos punteros que apuntan a sus hijos.

## 2.5. Estructura del nodo
```cpp
struct Nodo {
    int dato;
    Nodo *der;
    Nodo *izq;
};
```

## 2.6. Componentes
| Atributo | Descripción                 |
| ---      | ---                         |
| `dato`   | Almacena el valor del nodo. |
| `der`    | Puntero al hijo derecho.    |
| `izq`    | Puntero al hijo izquierdo.  |

Cada nodo contiene tres componentes:

1. Un espacio para almacenar el dato.
2. Un puntero al subárbol derecho.
3. Un puntero al subárbol izquierdo.

Los punteros pueden contener la dirección de otro nodo o `NULL` cuando no existe un hijo correspondiente.

## 2.7. Representación de la estructura
```text
             A
           /   \
          B     C
         / \   / \
        D   E F   G
```

Cada nodo almacena su dato y las direcciones de sus respectivos hijos. Los nodos que no tienen hijos apuntan a `NULL`.

---

# 3. Árbol binario de búsqueda
Un **árbol binario de búsqueda (ABB)** es un tipo de árbol binario que organiza sus elementos siguiendo una regla de ordenamiento:
- Todos los valores del subárbol izquierdo de un nodo son menores que el valor de dicho nodo.
- Todos los valores del subárbol derecho de un nodo son mayores que el valor de dicho nodo.

Esta propiedad se cumple para cada nodo del árbol, por lo que ambos subárboles también deben respetar las mismas reglas.

## 3.1. Concepto de árbol binario de búsqueda
Para comprender su funcionamiento, consideremos un árbol cuya raíz contiene el valor `10`.

## 3.2. Ejemplo de inserción de elementos
**1. Insertar el valor 10**
El primer elemento se convierte en la raíz del árbol.

```text
    10
```

**2. Insertar el valor 5**
Como `5` es menor que `10`, se coloca en el subárbol izquierdo.

```text
       10
      /
     5
```

**3. Insertar el valor 15**
Como `15` es mayor que `10`, se coloca en el subárbol derecho.

```text
       10
      /  \
     5    15
```

**4. Insertar el valor 4**
Se compara con la raíz y después con el nodo `5`:

- `4 < 10`: ir a la izquierda.
- `4 < 5`: ir a la izquierda.

```text
         10
        /  \
       5    15
      /
     4
```

**5. Insertar el valor 8**
Se compara con los nodos existentes:

- `8 < 10`: ir a la izquierda.
- `8 > 5`: ir a la derecha.

```text
         10
        /  \
       5    15
      / \
     4   8
```

**6. Insertar el valor 20**
Se compara con los nodos existentes:

- `20 > 10`: ir a la derecha.
- `20 > 15`: ir a la derecha.

```text
         10
        /  \
       5    15
      / \     \
     4   8     20
```

De esta manera, todos los elementos quedan organizados respetando las propiedades del árbol binario de búsqueda.

## 3.3. Reglas de inserción
| Condición                             | Acción                         |
| ---                                   | ---                            |
| Nuevo valor menor que el nodo actual  | Avanzar al subárbol izquierdo. |
| Nuevo valor mayor que el nodo actual  | Avanzar al subárbol derecho.   |
| Encontrar una posición vacía (`NULL`) | Insertar el nuevo nodo.        |

> [!NOTE]
> En estos apuntes se consideran valores distintos. El tratamiento de valores duplicados depende de la implementación del árbol.

## 3.4. Ejemplo de construcción de un árbol binario de búsqueda
**Ejercicio:** Construir un árbol binario de búsqueda para almacenar los siguientes datos:

```cpp
12, 8, 7, 16, 14
```

**Solución paso a paso**
**1. Insertar 12**
Es el primer elemento, por lo tanto, se convierte en la raíz.

```text
      12
```

**2. Insertar 8**
Como `8 < 12`, se coloca a la izquierda.

```text
      12
     /
    8
```

**3. Insertar 7**
Como `7 < 12` y `7 < 8`, se coloca a la izquierda de `8`.

```text
       12
      /
     8
    /
   7
```

**4. Insertar 16**
Como `16 > 12`, se coloca a la derecha de `12`.

```text
       12
      /  \
     8    16
    /
   7
```

**5. Insertar 14**
Como `14 > 12`, avanzamos a la derecha. Después, como `14 < 16`, se coloca a la izquierda de `16`.

```text
        12
       /  \
      8    16
     /    /
    7    14
```

**Resultado final:**
El árbol binario de búsqueda queda organizado de la siguiente manera:

- Raíz: `12`.
- Subárbol izquierdo: `8`, con su hijo izquierdo `7`.
- Subárbol derecho: `16`, con su hijo izquierdo `14`.

## 3.5. Operaciones en árboles binarios de búsqueda
Las principales operaciones que se pueden realizar sobre un árbol binario de búsqueda son:
1. **Insertar:** agregar un nuevo nodo al árbol respetando las reglas de ordenamiento.
2. **Mostrar:** visualizar todos los elementos que contiene el árbol.
3. **Buscar:** localizar un nodo específico dentro del árbol.
4. **Recorrer:** visitar los nodos siguiendo un orden determinado.
5. **Borrar:** eliminar un nodo del árbol y reorganizar los enlaces necesarios para conservar sus propiedades.

Estas operaciones permiten administrar los elementos almacenados en un árbol binario de búsqueda de manera organizada.

---

# 6. Búsqueda de un nodo en el árbol
La búsqueda permite determinar si un valor específico se encuentra almacenado dentro de un árbol binario de búsqueda.
Para realizarla, se compara el valor que buscamos con el dato del nodo actual. Dependiendo del resultado de la comparación, se continúa la búsqueda por el subárbol izquierdo o derecho.
La búsqueda aprovecha la organización del árbol binario de búsqueda para evitar recorrer todos sus nodos.

## 6.1. Definición de la función
Primero definimos una función llamada `busqueda()` que recibe dos parámetros:
- `Nodo *arbol`: puntero al nodo actual del árbol.
- `int n`: valor que queremos encontrar.

La función devuelve un valor de tipo `bool`:
- `true`: si el elemento se encuentra en el árbol.
- `false`: si el elemento no existe en el árbol.

**Código inicial:**
```cpp
bool busqueda(Nodo *arbol, int n) {
    if (arbol == NULL) {
        return false;
    }
}
```

**Explicación:**
- La primera condición comprueba si el puntero `arbol` es igual a `NULL`.
- Esto significa que se llegó a una posición vacía del árbol y, por lo tanto, el elemento buscado no existe en esa rama.
- En ese caso, la función devuelve `false`.

## 6.2. Condiciones de búsqueda
Una vez comprobado que el árbol no está vacío, se realizan las siguientes comparaciones:

**1. El elemento fue encontrado**
```cpp
else if (arbol->dato == n) {
    return true;
}
```

Si el dato almacenado en el nodo actual es igual al valor que buscamos, significa que encontramos el elemento y la función devuelve `true`.

**2. Buscar en el subárbol izquierdo**
```cpp
else if (n < arbol->dato) {
    return busqueda(arbol->izq, n);
}
```

Si el valor buscado es menor que el dato del nodo actual, debemos continuar la búsqueda por el subárbol izquierdo.

La función se llama nuevamente a sí misma, pero ahora recibe como primer parámetro el puntero `arbol->izq`.

**3. Buscar en el subárbol derecho**
```cpp
else {
    return busqueda(arbol->der, n);
}
```

Si el valor buscado es mayor que el dato del nodo actual, debemos continuar la búsqueda por el subárbol derecho.

La función vuelve a llamarse, esta vez utilizando el puntero `arbol->der`.

## 6.3. Ejemplo de búsqueda
Consideremos el siguiente árbol binario de búsqueda:

```text
        5
       / \
      3   8
```

**Ejemplo 1: Buscar el valor 5**
```cpp
int n = 5;
```

1. Se recibe el árbol y se comprueba que no sea `NULL`.
2. Se compara `arbol->dato` con `n`.
3. Como `5 == 5`, el elemento fue encontrado.
4. La función devuelve `true`.

**Resultado:** `true`.

**Ejemplo 2: Buscar el valor 3**
```cpp
int n = 3;
```

1. Se compara `3` con el nodo raíz `5`.
2. Como `3 < 5`, se continúa por el subárbol izquierdo.
3. Se llega al nodo `3`.
4. Como `3 == 3`, la función devuelve `true`.

**Resultado:** `true`.

**Ejemplo 3: Buscar el valor 8**
```cpp
int n = 8;
```

1. Se compara `8` con el nodo raíz `5`.
2. Como `8 > 5`, se continúa por el subárbol derecho.
3. Se llega al nodo `8`.
4. Como `8 == 8`, la función devuelve `true`.

**Resultado:** `true`.

## 6.4. Código completo de la función
```cpp
bool busqueda(Nodo *arbol, int n) {

    if (arbol == NULL) {
        return false;
    }
    else if (arbol->dato == n) {
        return true;
    }
    else if (n < arbol->dato) {
        return busqueda(arbol->izq, n);
    }
    else {
        return busqueda(arbol->der, n);
    }

}
```

## 6.5. Resumen del funcionamiento
| Condición          | Acción                             | Resultado         |
| ---                | ---                                | ---               |
| `arbol == NULL`    | No existe el elemento en esa rama. | `false`           |
| `arbol->dato == n` | Se encontró el elemento.           | `true`            |
| `n < arbol->dato`  | Buscar por la izquierda.           | Llamada recursiva |
| `n > arbol->dato`  | Buscar por la derecha.             | Llamada recursiva |

**Complejidad temporal:**
- Mejor caso: \(O(1)\), cuando el elemento está en la raíz.
- Caso promedio: \(O(\log n)\), cuando el árbol está aproximadamente equilibrado.
- Peor caso: \(O(n)\), cuando el árbol está degenerado.

Donde `n` representa la cantidad de nodos del árbol.

---
