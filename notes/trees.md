<h1 align="center">Árboles en C++</h1>

## Contenido

1. [Concepto de árbol]()
    - [¿Cómo definimos un nodo?]()
    - [Propiedades del arbol]()
1. [Concepto de árbol binario](#1.concepto-de-arbol-binario)
   - [Estructura recursiva](#1.1.estructura-recursiva)
2. [Tipos de árboles binarios](#2-tipos-de-arboles-binarios)
   - [Árbol lleno](#2.1-arbol-lleno)
   - [Árbol completo](#22-arbol-completo)
   - [Árbol degenerado](#23-arbol-degenerado)
3. [Estructura de un árbol binario en C++](#3-estructura-de-un-arbol-binario-en-c)
    - [Estructura del nodo]()
    - [Componentes]()
    - [Representación de la estructura]()
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

### Ejemplo de un árbol

```text
             A  ← Raíz
           /   \
          B     C
         / \     \
        D   E     F  ← Hojas
```

En este ejemplo:

- `A` es la raíz del árbol.
- `B` y `C` son hijos de `A`.
- `D` y `E` son hijos de `B`.
- `F` es hijo de `C`.
- `D`, `E` y `F` son nodos hoja.

---

# 5. Propiedades de los árboles

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

## 5.1. Longitud de camino

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

## 5.2. Altura de un nodo

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

## 5.3. Profundidad y nivel de un nodo

La **profundidad de un nodo** es la cantidad de ramas que existen desde la raíz hasta dicho nodo.

El **nivel** representa la posición jerárquica de un nodo dentro del árbol. En esta convención, el nivel coincide con la profundidad y la raíz comienza en el nivel 0.

### Distribución de niveles

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

## 5.4. Nodos hermanos

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

## 5.5. Orden de un árbol

El **orden de un árbol** es la cantidad máxima de hijos que puede tener un nodo.

En un árbol binario, el orden es 2, lo que significa que cada nodo puede tener:

1. **Cero hijos:** no tiene hijos.
2. **Un hijo:** puede tener únicamente un hijo izquierdo o derecho.
3. **Dos hijos:** tiene un hijo izquierdo y uno derecho.

### Ejemplos

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

# 1. Concepto de árbol binario
Un **árbol binario** es un árbol de orden 2, es decir, cada nodo puede tener como máximo dos hijos:
- **Hijo izquierdo:** nodo que se encuentra en la rama izquierda.
- **Hijo derecho:** nodo que se encuentra en la rama derecha.

Un árbol binario puede contener nodos con dos hijos, un solo hijo o ningún hijo.

## 1.1. Estructura recursiva
Un árbol binario es una **estructura de datos recursiva** que se divide en tres subconjuntos disjuntos:
1. **Nodo raíz:** es el nodo principal del árbol, del cual parten los demás nodos.
2. **Subárbol izquierdo:** es el árbol binario que se encuentra a la izquierda del nodo raíz.
3. **Subárbol derecho:** es el árbol binario que se encuentra a la derecha del nodo raíz.

Cada subárbol también puede dividirse recursivamente en una raíz, un subárbol izquierdo y un subárbol derecho.

### Representación de un árbol binario

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

---

# 2. Tipos de árboles binarios

Los árboles binarios pueden clasificarse de diferentes maneras según la distribución y organización de sus nodos.

## 2.1. Árbol lleno

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

## 2.2. Árbol completo
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

## 2.3. Árbol degenerado

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

---

# 3. Estructura de un árbol binario en C++
Para implementar un árbol binario en C++ se utiliza una estructura `struct` que permite almacenar el dato de cada nodo y dos punteros que apuntan a sus hijos.

## 3.1. Estructura del nodo
```cpp
struct Nodo {
    int dato;
    Nodo *der;
    Nodo *izq;
};
```

## 3.2. Componentes
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

## 3.3. Representación de la estructura
```text
             A
           /   \
          B     C
         / \   / \
        D   E F   G
```

Cada nodo almacena su dato y las direcciones de sus respectivos hijos. Los nodos que no tienen hijos apuntan a `NULL`.