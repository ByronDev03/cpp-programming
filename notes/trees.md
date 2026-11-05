<h1 align="center">Árboles en C++</h1>

## Contenido

1. [Concepto de árbol]()
[¿Cómo definimos un nodo?]()
[Propiedades del arbol]()
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