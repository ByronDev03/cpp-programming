# Listas Enlazadas

## 1. ¿Qué es una lista enlazada?

Una **lista enlazada** es una estructura de datos que consta de un número de nodos. Cada nodo contiene dos componentes (campos):

- **Dato:** almacena un valor que puede ser de cualquier tipo.
- **Enlace:** es un puntero que guarda la dirección del siguiente nodo de la lista.

A diferencia de los arreglos, los elementos de una lista enlazada no necesitan almacenarse en posiciones consecutivas de memoria, ya que se conectan mediante punteros.

### Representación de una lista enlazada

Una lista enlazada está formada por una secuencia de nodos conectados entre sí.

```text
 Cabeza
   |
   v
+------+--------+    +------+--------+    +------+--------+
|  e1  |   p    | -> |  e2  |   p    | -> |  e3  |   p    | -> ... -> NULL
+------+--------+    +------+--------+    +------+--------+
```

Donde:

- `e1`, `e2`, `e3`, ..., `en` representan los valores almacenados en cada nodo.
- `p` representa el puntero al siguiente nodo.
- `NULL` indica que no existe otro nodo después del último elemento.

### Estructura de un nodo en C++

Para implementar una lista enlazada en C++, se utiliza una estructura `struct`:

```cpp
struct Nodo {
    int dato;
    Nodo *siguiente;
};
```

**Explicación:**

- `int dato`: almacena el valor del nodo.
- `Nodo *siguiente`: es un puntero que almacena la dirección del siguiente nodo.

---

## 2. Clasificación de listas enlazadas

Las listas enlazadas se pueden dividir en cuatro categorías:

1. Listas simplemente enlazadas.
2. Listas doblemente enlazadas.
3. Listas circulares simplemente enlazadas.
4. Listas circulares doblemente enlazadas.

### 2.1. Listas simplemente enlazadas

Cada nodo contiene un único enlace que conecta ese nodo con el siguiente o nodo sucesor.

La lista es eficiente en recorridos directos (hacia adelante), ya que solamente permite avanzar de un nodo al siguiente.

**Características:**

- Cada nodo contiene un dato y un puntero.
- El puntero apunta al siguiente nodo.
- El último nodo apunta a `NULL`.
- Solamente permite recorrer la lista en una dirección.

**Representación:**

```text
+--------+     +--------+     +--------+     +--------+
| Dato1  | --> | Dato2  | --> | Dato3  | --> | Dato4  | --> NULL
|   p    |     |   p    |     |   p    |     |   NULL |
+--------+     +--------+     +--------+     +--------+
```

### 2.2. Listas doblemente enlazadas

Cada nodo contiene dos enlaces: uno a su nodo predecesor y el otro a su nodo sucesor.

La lista es eficiente tanto en recorrido directo (hacia adelante) como en recorrido inverso (hacia atrás).

**Características:**

- Cada nodo contiene un dato y dos punteros.
- Un puntero apunta al nodo anterior.
- Otro puntero apunta al nodo siguiente.
- Permite recorrer la lista en ambas direcciones.

**Representación:**

```text
         siguiente       siguiente       siguiente
             |               |               |
             v               v               v
NULL <-- [Dato1] <------> [Dato2] <------> [Dato3] <------> [Dato4] --> NULL
             ^               ^               ^               ^
             |               |               |               |
         anterior        anterior        anterior        anterior
```

### 2.3. Lista circular simplemente enlazada

Es una lista enlazada simplemente en la que el último elemento (cola) se enlaza al primer elemento (cabeza), de tal modo que la lista puede ser recorrida de modo circular (en anillo).

**Características:**

- Cada nodo contiene un dato y un puntero al siguiente nodo.
- El último nodo apunta nuevamente al primer nodo.
- No existe un enlace final que apunte a `NULL`.
- Permite recorrer la lista continuamente en una sola dirección.

**Representación:**

```text
        +--------+     +--------+     +--------+     +--------+
        | Dato1  | --> | Dato2  | --> | Dato3  | --> | Dato4  |
        +--------+     +--------+     +--------+     +--------+
             ^                                            |
             |                                            |
             +--------------------------------------------+
```

### 2.4. Lista circular doblemente enlazada

Es una lista doblemente enlazada en la que el último elemento se enlaza al primer elemento y viceversa.

Esta lista se puede recorrer de modo circular (en anillo), tanto en dirección directa (hacia adelante) como inversa (hacia atrás).

**Características:**

- Cada nodo contiene un dato y dos punteros.
- El último nodo apunta al primero.
- El primer nodo apunta al último mediante su puntero anterior.
- Permite recorrer la lista en ambas direcciones de manera circular.

**Representación:**

```text
        siguiente       siguiente       siguiente
            |               |               |
            v               v               v
       +--------+ <----> +--------+ <----> +--------+
       | Dato1  |        | Dato2  |        | Dato3  |
       +--------+        +--------+        +--------+
            ^                                 |
            |                                 |
            +---------------------------------+

       La conexión circular también permite
       recorrer la lista en sentido inverso.
```

---

## 3. Operaciones en listas enlazadas

Las operaciones principales que se pueden realizar en una lista enlazada son:

1. **Insertar elementos:** agregar nuevos nodos a la lista.
2. **Mostrar elementos:** recorrer la lista para visualizar los datos almacenados.
3. **Buscar un elemento:** localizar un dato dentro de la lista.
4. **Eliminar un elemento:** quitar un nodo de la lista.

### 3.1. Insertar elementos en una lista enlazada

La inserción consiste en crear un nuevo nodo, almacenar un dato en él y establecer los enlaces necesarios para incorporarlo a la lista.

Dependiendo de la implementación, se puede insertar un nodo al inicio, al final o en una posición determinada.

### 3.2. Mostrar los elementos de una lista enlazada

Consiste en recorrer los nodos de la lista desde el primero hasta el último, mostrando el dato almacenado en cada uno.

En una lista simplemente enlazada, el recorrido termina cuando el puntero llega a `NULL`.

### 3.3. Buscar un elemento en una lista enlazada

Consiste en recorrer los nodos de la lista comparando el dato almacenado en cada uno con el valor que se desea encontrar.

Si el valor coincide, significa que el elemento fue encontrado.

Si se llega al final de la lista sin encontrarlo, significa que el elemento no existe.

### 3.4. Eliminar un elemento en una lista enlazada

Consiste en localizar el nodo que contiene el dato que se desea eliminar, modificar los enlaces de los nodos involucrados y liberar la memoria ocupada por el nodo eliminado.

Es importante actualizar correctamente los punteros para mantener la conexión entre los nodos restantes.

---

## 4. Resumen de las listas enlazadas

| Tipo de lista | Número de enlaces por nodo | Recorrido |
|---|---|---|
| Simplemente enlazada | 1 | Directo |
| Doblemente enlazada | 2 | Directo e inverso |
| Circular simplemente enlazada | 1 | Directo y circular |
| Circular doblemente enlazada | 2 | Directo e inverso, ambos circulares |

### Conceptos importantes

| Concepto | Significado |
|---|---|
| Nodo | Elemento que almacena un dato y uno o más punteros. |
| Dato | Valor almacenado dentro de un nodo. |
| Puntero | Variable que almacena una dirección de memoria. |
| Siguiente | Puntero que señala al nodo sucesor. |
| Anterior | Puntero que señala al nodo predecesor. |
| Cabeza | Referencia al primer nodo de la lista. |
| Cola | Referencia o posición correspondiente al último nodo. |
| NULL | Indica que un puntero no apunta a ningún nodo. |
| Predecesor | Nodo que se encuentra antes del nodo actual. |
| Sucesor | Nodo que se encuentra después del nodo actual. |