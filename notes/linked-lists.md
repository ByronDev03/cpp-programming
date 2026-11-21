<h1 align="center">Listas Enlazadas en C++</h1>

## Contenido
1. [¿Qué es una lista enlazada?]()
    - [1.1. Representación de una lista enlazada]()
    - [1.2. Estructura de un nodo en C++]()
2. [Clasificación de listas enlazadas]()
    - [2.1. Listas simplemente enlazadas]()
    - [2.2. Listas doblemente enlazadas]()
    - [2.3. Lista circular simplemente enlazada]()
    - [2.4. Lista circular doblemente enlazada]()
3. [Operaciones en listas enlazadas]()
    - [3.1. Insertar elementos en una lista enlazada]()
    - [3.2. Mostrar los elementos de una lista enlazada]()
    - [3.3. Buscar un elemento en una lista enlazada]()
    - [3.4. Eliminar un elemento en una lista enlazada]()
4. [Resumen]()

# 1. ¿Qué es una lista enlazada?
Una **lista enlazada** es una estructura de datos que consta de un número de nodos. Cada nodo contiene dos componentes (campos):

- **Dato:** almacena un valor que puede ser de cualquier tipo.
- **Enlace:** es un puntero que guarda la dirección del siguiente nodo de la lista.

A diferencia de los arreglos, los elementos de una lista enlazada no necesitan almacenarse en posiciones consecutivas de memoria, ya que se conectan mediante punteros.

## 1.1. Representación de una lista enlazada
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

## 1.2. Estructura de un nodo en C++
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

# 2. Clasificación de listas enlazadas
Las listas enlazadas se pueden dividir en cuatro categorías:

1. Listas simplemente enlazadas.
2. Listas doblemente enlazadas.
3. Listas circulares simplemente enlazadas.
4. Listas circulares doblemente enlazadas.

## 2.1. Listas simplemente enlazadas
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

## 2.2. Listas doblemente enlazadas
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

## 2.3. Lista circular simplemente enlazada
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

## 2.4. Lista circular doblemente enlazada
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

# 3. Operaciones en listas enlazadas
Las operaciones principales que se pueden realizar en una lista enlazada son:

1. **Insertar elementos:** agregar nuevos nodos a la lista.
2. **Mostrar elementos:** recorrer la lista para visualizar los datos almacenados.
3. **Buscar un elemento:** localizar un dato dentro de la lista.
4. **Eliminar un elemento:** quitar un nodo de la lista.

## 3.1. Insertar elementos en una lista enlazada
La inserción consiste en crear un nuevo nodo, almacenar un dato en él y establecer los enlaces necesarios para incorporarlo a la lista. Dependiendo de la implementación, se puede insertar un nodo al inicio, al final o en una posición determinada.

# 1. Pasos para insertar elementos en una lista
Para insertar elementos en una lista enlazada se deben seguir **cuatro pasos**:

1. Crear un nuevo nodo.
2. Asignar al campo `nuevo_nodo->dato` el elemento que queremos incluir en la lista.
3. Crear dos nodos auxiliares y asignar `lista` al primero de ellos.
4. Insertar el elemento en la lista.

## 1.1. Crear un nuevo nodo
Primero, se crea un nuevo nodo utilizando el operador `new`, que reserva espacio en memoria dinámica.

Antes de insertar el primer elemento, la lista se encuentra vacía:

```cpp
lista = NULL;
```

Se declara un puntero llamado `nuevo_nodo`, que apuntará al espacio de memoria reservado:

```cpp
void insertarLista(Nodo *&lista, int n) {
    Nodo *nuevo_nodo = new Nodo();
}
```

En este momento, el nuevo nodo todavía no contiene un dato asignado y su campo `siguiente` debe apuntar a `NULL` cuando se inicialice.

## 1.2. Asignar el dato al nuevo nodo
Se asigna al campo `dato` del nuevo nodo el elemento que queremos insertar en la lista.

Por ejemplo, si queremos insertar el número `10`:

```cpp
n = 10;

nuevo_nodo->dato = n;
```

La estructura del nodo utilizada es:

```cpp
struct Nodo {
    int dato;
    Nodo *siguiente;
};
```

El operador `->` permite acceder a los miembros de una estructura o clase mediante un puntero.

## 1.3. Crear nodos auxiliares
Se crean dos punteros auxiliares:

```cpp
Nodo *aux1 = lista;
Nodo *aux2;
```

- `aux1`: apunta inicialmente al primer nodo de la lista y permite recorrerla.
- `aux2`: almacena la dirección del nodo anterior al que está apuntando `aux1`.

Si la lista está vacía, ambos punteros tienen inicialmente la siguiente situación:

```text
aux1 -> NULL
lista -> NULL
```

El puntero `aux2` todavía no tiene una dirección asignada. Se utilizará durante el recorrido de la lista.

## 1.4. Insertar el elemento en la lista
Existen diferentes situaciones al insertar un elemento:

- Lista vacía.
- Lista con uno o más elementos.

Además, se consideran dos posiciones posibles para insertar:

- **Al principio:** cuando el nuevo elemento debe quedar antes del primer nodo.
- **En medio o al final:** cuando debe insertarse después de uno o más nodos existentes.

El procedimiento utiliza dos punteros auxiliares para encontrar la posición correcta.

## 1.4.1. Insertar al principio
Cuando la lista está vacía o el nuevo elemento es menor que el primer elemento, se inserta al principio.

Por ejemplo, si queremos insertar el valor `10` en una lista vacía:

```cpp
lista = nuevo_nodo;
nuevo_nodo->siguiente = aux1;
```

Como `aux1` contiene `NULL`, el nuevo nodo apuntará a `NULL`.

**Estado final:**

```text
lista
  |
  v
+------+-----------+
|  10  | siguiente | ----> NULL
+------+-----------+
```

## 1.4.2. Insertar en medio o al final
Para encontrar la posición de inserción, se utiliza un ciclo `while` que recorre la lista mientras existan nodos y el dato del nodo actual sea menor que el nuevo valor:

```cpp
while ((aux1 != NULL) && (aux1->dato < n)) {
    aux2 = aux1;
    aux1 = aux1->siguiente;
}
```

En cada iteración:

1. `aux2` guarda la dirección del nodo actual.
2. `aux1` avanza al siguiente nodo.

Cuando termina el recorrido, `aux1` apunta al nodo que debe quedar después del nuevo elemento, mientras que `aux2` apunta al nodo anterior.

**Ejemplo de inserción al principio:**

Si la lista contiene `10` y queremos insertar `5`, el nuevo nodo debe quedar antes del `10`.

```text
Antes:

lista
  |
  v
+------+-----------+
|  10  | siguiente | ----> NULL
+------+-----------+

nuevo_nodo
    |
    v
+------+-----------+
|   5  | siguiente |
+------+-----------+
```

Se actualizan los punteros:

```cpp
lista = nuevo_nodo;
nuevo_nodo->siguiente = aux1;
```

**Resultado:**

```text
lista
  |
  v
+------+-----------+     +------+-----------+
|   5  | siguiente | --> |  10  | siguiente | --> NULL
+------+-----------+     +------+-----------+
```

**Ejemplo de inserción en medio o al final:**

Si la lista contiene `10` y queremos insertar `12`, el nuevo nodo debe quedar después del `10`.

Cuando termina el recorrido:

- `aux2` apunta al nodo que contiene `10`.
- `aux1` apunta a `NULL`.

Se realizan las siguientes asignaciones:

```cpp
aux2->siguiente = nuevo_nodo;
nuevo_nodo->siguiente = aux1;
```

**Resultado:**

```text
lista
  |
  v
+------+-----------+     +------+-----------+
|  10  | siguiente | --> |  12  | siguiente | --> NULL
+------+-----------+     +------+-----------+
```

## 1.4.3. Actualizar los enlaces de la lista
Una vez encontrado el lugar donde se insertará el nuevo nodo, se comprueba si debe colocarse al principio o después de otro nodo:

```cpp
if (lista == aux1) {
    lista = nuevo_nodo;
}
else {
    aux2->siguiente = nuevo_nodo;
}

nuevo_nodo->siguiente = aux1;
```

- **Si `lista == aux1`:** significa que el nuevo nodo debe insertarse al principio. Se actualiza `lista` para que apunte al nuevo nodo.
- **En caso contrario:** se enlaza el nodo anterior (`aux2`) con el nuevo nodo.
- Finalmente, `nuevo_nodo->siguiente = aux1` enlaza el nuevo nodo con el siguiente elemento de la lista.

# 2. Código completo de insertarLista()
Integrando los cuatro pasos, la función queda de la siguiente manera:

```cpp
void insertarLista(Nodo *&lista, int n) {
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;

    Nodo *aux1 = lista;
    Nodo *aux2;

    while ((aux1 != NULL) && (aux1->dato < n)) {
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }

    if (lista == aux1) {
        lista = nuevo_nodo;
    }
    else {
        aux2->siguiente = nuevo_nodo;
    }

    nuevo_nodo->siguiente = aux1;
}
```

**Parámetros:**

- `Nodo *&lista`: referencia al puntero que representa el inicio de la lista. Se utiliza una referencia para poder modificar el puntero original.
- `int n`: contiene el valor que se desea insertar.

**Importante:** esta implementación mantiene los elementos ordenados de menor a mayor. La condición `aux1->dato < n` determina la posición donde se insertará el nuevo elemento.

La función contempla la inserción al principio, en medio o al final de la lista, actualizando los enlaces correspondientes.



## 3.2. Mostrar los elementos de una lista enlazada
Consiste en recorrer los nodos de la lista desde el primero hasta el último, mostrando el dato almacenado en cada uno. En una lista simplemente enlazada, el recorrido termina cuando el puntero llega a `NULL`.

# 1. Pasos para mostrar los elementos de una lista

Para mostrar los elementos de una lista enlazada solo hay que seguir **tres pasos**:

1. Crear un nuevo nodo (`actual`).
2. Igualar ese nuevo nodo (`actual`) a `lista`.
3. Recorrer la lista de inicio a fin.

## 1.1. Crear un nuevo nodo (`actual`)

Primero, se declara un puntero llamado `actual`, que permitirá recorrer los nodos de la lista.

En la diapositiva se muestra la siguiente instrucción:

```cpp
void mostrarLista(Nodo *lista) {
    Nodo *actual = new Nodo();
}
```

El puntero `actual` se utilizará para desplazarse por los diferentes nodos de la lista.

## 1.2. Igualar `actual` a `lista`

Después, se asigna al puntero `actual` la dirección del primer nodo de la lista:

```cpp
actual = lista;
```

Por ejemplo, si la lista contiene los valores `5` y `10`, ambos punteros apuntarán inicialmente al primer nodo:

```text
lista
  |
  v
+------+-----------+     +------+-----------+
|   5  | siguiente | --> |  10  | siguiente | --> NULL
+------+-----------+     +------+-----------+
  ^
  |
actual
```

De esta manera, `actual` comienza el recorrido desde el inicio de la lista.

## 1.3. Recorrer la lista de inicio a fin

Para recorrer todos los elementos, se utiliza un ciclo `while` que se ejecuta mientras `actual` sea diferente de `NULL`.

```cpp
while (actual != NULL) {
    cout << actual->dato;
    actual = actual->siguiente;
}
```

Dentro del ciclo se realizan dos operaciones:

1. **Mostrar el dato:** se utiliza `cout` para imprimir el valor almacenado en el nodo actual.
2. **Avanzar al siguiente nodo:** se actualiza `actual` para que apunte al siguiente nodo mediante `actual->siguiente`.

El recorrido continúa hasta que `actual` llega a `NULL`, indicando que se alcanzó el final de la lista.

**Ejemplo del recorrido:**

Supongamos que tenemos la siguiente lista:

```text
lista
  |
  v
+------+-----------+     +------+-----------+
|   5  | siguiente | --> |  10  | siguiente | --> NULL
+------+-----------+     +------+-----------+
  ^
  |
actual
```

**Primera iteración:**

- `actual->dato` muestra `5`.
- `actual = actual->siguiente` avanza al segundo nodo.

**Segunda iteración:**

- `actual->dato` muestra `10`.
- `actual = actual->siguiente` avanza a `NULL`.

**Fin del recorrido:**

Como `actual == NULL`, el ciclo termina.

La salida será:

```text
5 -> 10 ->
```

---

# 2. Código completo de `mostrarLista()`

Integrando los tres pasos, la función queda de la siguiente manera:

```cpp
void mostrarLista(Nodo *lista) {
    Nodo *actual = new Nodo();

    actual = lista;

    while (actual != NULL) {
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    }
}
```

**Parámetro:**

- `Nodo *lista`: recibe un puntero al primer nodo de la lista. Se pasa por valor porque la función únicamente necesita recorrerla, sin modificar el puntero original.

**Importante:** la condición `actual != NULL` permite comprobar que todavía existe un nodo por recorrer. Cuando el puntero llega a `NULL`, significa que se alcanzó el final de la lista y el ciclo termina.



## 3.3. Buscar un elemento en una lista enlazada
Consiste en recorrer los nodos de la lista comparando el dato almacenado en cada uno con el valor que se desea encontrar. Si el valor coincide, significa que el elemento fue encontrado. Si se llega al final de la lista sin encontrarlo, significa que el elemento no existe.

# 1. Pasos para buscar un elemento en una lista

Para buscar un elemento en una lista enlazada solo hay que seguir **cuatro pasos**:

1. Crear un nuevo nodo (`actual`).
2. Igualar ese nuevo nodo (`actual`) a la lista.
3. Recorrer la lista.
4. Determinar si el elemento existe o no en la lista.

## 1.1. Crear un nuevo nodo (`actual`)

Primero, se declara un puntero llamado `actual`, que permitirá recorrer los nodos de la lista.

```cpp
void buscarLista(Nodo *lista, int n) {
    Nodo *actual = new Nodo();
}
```

El puntero `actual` se utilizará para desplazarse por los diferentes nodos de la lista.

## 1.2. Igualar `actual` a `lista`

Después, se asigna al puntero `actual` la dirección del primer nodo de la lista:

```cpp
actual = lista;
```

Por ejemplo, si la lista contiene los valores `5` y `10`, ambos punteros apuntarán inicialmente al primer nodo:

```text
lista
  |
  v
+------+-----------+     +------+-----------+
|   5  | siguiente | --> |  10  | siguiente | --> NULL
+------+-----------+     +------+-----------+
  ^
  |
actual
```

De esta manera, `actual` comienza el recorrido desde el inicio de la lista.

## 1.3. Recorrer la lista

Para recorrer los nodos se utiliza un ciclo `while` con dos condiciones:

```cpp
while ((actual != NULL) && (actual->dato <= n)) {

}
```

Las condiciones indican lo siguiente:

- `actual != NULL`: comprueba que todavía exista un nodo por recorrer.
- `actual->dato <= n`: comprueba que el valor del nodo actual sea menor o igual al elemento que se está buscando.

La segunda condición permite detener el recorrido cuando se encuentra un valor mayor que `n`, ya que se trabaja con una lista ordenada de menor a mayor.

**Ejemplo:**

Supongamos que tenemos la siguiente lista y queremos buscar el número `10`:

```cpp
int n = 10;
```

**Estado inicial:**

```text
lista
  |
  v
+------+-----------+     +------+-----------+
|   5  | siguiente | --> |  10  | siguiente | --> NULL
+------+-----------+     +------+-----------+
  ^
  |
actual
```

El ciclo comprueba las condiciones y permite recorrer la lista mientras se cumplan.

## 1.4. Determinar si el elemento existe en la lista

Dentro del ciclo `while`, se utiliza una condición `if` para comparar el dato del nodo actual con el elemento que se está buscando.

```cpp
if (actual->dato == n) {
    band = true;
}

actual = actual->siguiente;
```

- Si `actual->dato == n`, significa que el elemento fue encontrado y la variable `band` cambia a `true`.
- Después, `actual = actual->siguiente` permite avanzar al siguiente nodo.

**Ejemplo 1. Buscar el número `10`:**

```cpp
int n = 10;
```

El recorrido comienza en el nodo que contiene `5`:

```text
lista
  |
  v
+------+-----------+     +------+-----------+
|   5  | siguiente | --> |  10  | siguiente | --> NULL
+------+-----------+     +------+-----------+
  ^
  |
actual
```

Como `5` es menor que `10`, el recorrido continúa. Al llegar al nodo que contiene `10`, se cumple la condición:

```cpp
if (actual->dato == n) {
    band = true;
}
```

La variable `band` cambia a `true`, indicando que el elemento fue encontrado.

**Ejemplo 2. Buscar el número `12`:**

```cpp
int n = 12;
```

La lista contiene los valores `5` y `10`:

```text
lista
  |
  v
+------+-----------+     +------+-----------+
|   5  | siguiente | --> |  10  | siguiente | --> NULL
+------+-----------+     +------+-----------+
                           ^
                           |
                         actual
```

Como `10` es menor que `12`, el recorrido continúa hasta llegar a `NULL`.

En este caso, nunca se cumple `actual->dato == n`, por lo que la variable `band` permanece en `false`.

**Finalmente, se determina si el elemento fue encontrado:**

```cpp
if (band == true) {
    cout << "Elemento " << n << " SI a sido encontrado en lista\n";
}
else {
    cout << "Elemento " << n << " NO a sido encontrado en lista\n";
}
```

---

# 2. Código completo de `buscarLista()`

Integrando los cuatro pasos, la función queda de la siguiente manera:

```cpp
void buscarLista(Nodo *lista, int n) {
    bool band = false;

    Nodo *actual = new Nodo();
    actual = lista;

    while ((actual != NULL) && (actual->dato <= n)) {
        if (actual->dato == n) {
            band = true;
        }

        actual = actual->siguiente;
    }

    if (band == true) {
        cout << "Elemento " << n << " SI a sido encontrado en lista\n";
    }
    else {
        cout << "Elemento " << n << " NO a sido encontrado en lista\n";
    }
}
```

**Parámetros:**

- `Nodo *lista`: recibe un puntero al primer nodo de la lista enlazada.
- `int n`: contiene el valor que se desea buscar.

**Variables utilizadas:**

- `bool band`: variable booleana que indica si el elemento fue encontrado. Inicialmente tiene el valor `false`.
- `Nodo *actual`: puntero auxiliar que permite recorrer los nodos de la lista.

**Importante:** la condición `actual->dato <= n` supone que la lista está ordenada de menor a mayor. Esto permite detener la búsqueda cuando se encuentra un valor superior al buscado, evitando recorrer innecesariamente el resto de los nodos.


## 3.4. Eliminar un nodo en una lista enlazada
Consiste en localizar el nodo que contiene el dato que se desea eliminar, modificar los enlaces de los nodos involucrados y liberar la memoria ocupada por el nodo eliminado. Es importante actualizar correctamente los punteros para mantener la conexión entre los nodos restantes.

# 1. Pasos para eliminar un nodo de la lista

Para eliminar un elemento `n` de una lista enlazada, hay que seguir **cinco pasos**:

1. Comprobar que la lista no esté vacía.
2. Crear un puntero `aux_borrar` y otro puntero `anterior = NULL`.
3. Igualar `aux_borrar` al inicio de la lista.
4. Recorrer la lista.
5. Eliminar el elemento.

## 1.1. Comprobar que la lista no esté vacía

Antes de realizar cualquier operación, se debe comprobar que la lista contenga al menos un nodo.

Para ello, se utiliza una condición `if`:

```cpp
if (lista != NULL) {

}
```

Si `lista != NULL`, significa que existe al menos un nodo y se puede continuar con el proceso de eliminación.

Si `lista == NULL`, la lista está vacía y no hay elementos que eliminar.

La estructura inicial de la función es:

```cpp
void eliminarNodo(Nodo *&lista, int n) {
    if (lista != NULL) {

    }
}
```

## 1.2. Crear los punteros auxiliares

Se declaran dos punteros auxiliares:

```cpp
Nodo *aux_borrar;
Nodo *anterior = NULL;
```

- `aux_borrar`: apunta al nodo que se desea eliminar.
- `anterior`: apunta al nodo que se encuentra antes de `aux_borrar`.

Inicialmente, `anterior` se establece en `NULL` porque todavía no se ha recorrido ningún nodo y, por lo tanto, no existe un nodo anterior.

## 1.3. Igualar `aux_borrar` al inicio de la lista

Se asigna al puntero `aux_borrar` la dirección del primer nodo de la lista:

```cpp
aux_borrar = lista;
```

De esta manera, `aux_borrar` comienza apuntando al primer elemento.

**Ejemplo:**

```text
lista
  |
  v
+------+-----------+     +------+-----------+
|   5  | siguiente | --> |  10  | siguiente | --> NULL
+------+-----------+     +------+-----------+
  ^
  |
aux_borrar
```

## 1.4. Recorrer la lista

Para encontrar el nodo que contiene el elemento que se desea eliminar, se utiliza un ciclo `while`:

```cpp
while ((aux_borrar != NULL) && (aux_borrar->dato != n)) {
    anterior = aux_borrar;
    aux_borrar = aux_borrar->siguiente;
}
```

Las condiciones indican lo siguiente:

- `aux_borrar != NULL`: comprueba que todavía existan nodos por recorrer.
- `aux_borrar->dato != n`: comprueba que el dato del nodo actual sea diferente del elemento que se desea eliminar.

Dentro del ciclo se realizan dos operaciones:

1. `anterior = aux_borrar`: guarda la dirección del nodo actual en el puntero `anterior`.
2. `aux_borrar = aux_borrar->siguiente`: avanza `aux_borrar` al siguiente nodo.

**Ejemplo. Buscar el número `12`:**

```cpp
int n = 12;
```

La lista contiene los valores `5` y `10`:

```text
anterior
    |
    v
lista
  |
  v
+------+-----------+     +------+-----------+
|   5  | siguiente | --> |  10  | siguiente | --> NULL
+------+-----------+     +------+-----------+
                           ^
                           |
                       aux_borrar
```

Como ninguno de los nodos contiene el número `12`, el recorrido continúa hasta que `aux_borrar` llega a `NULL`.

En ese momento, significa que el elemento no existe en la lista.

## 1.5. Eliminar el elemento

Una vez terminado el recorrido, se presentan **tres situaciones**:

**Caso 1. El elemento no existe en la lista**

Si `aux_borrar == NULL`, significa que se llegó al final de la lista sin encontrar el elemento.

```cpp
if (aux_borrar == NULL) {
    cout << "El elemento no existe";
}
```

**Caso 2. El elemento está al principio de la lista**

Si `anterior == NULL`, significa que el nodo que se desea eliminar es el primero de la lista.

```cpp
else if (anterior == NULL) {
    lista = lista->siguiente;
    delete aux_borrar;
}
```

Se realizan dos operaciones:

1. `lista = lista->siguiente`: actualiza el inicio de la lista para que apunte al segundo nodo.
2. `delete aux_borrar`: libera la memoria del nodo eliminado.

**Ejemplo. Eliminar el número `5`:**

Estado inicial:

```text
lista
  |
  v
+------+-----------+     +------+-----------+
|   5  | siguiente | --> |  10  | siguiente | --> NULL
+------+-----------+     +------+-----------+
  ^
  |
aux_borrar
```

Como el nodo que contiene `5` es el primero, `anterior` permanece en `NULL`.

Después de ejecutar:

```cpp
lista = lista->siguiente;
delete aux_borrar;
```

La lista queda de la siguiente manera:

```text
lista
  |
  v
+------+-----------+
|  10  | siguiente | --> NULL
+------+-----------+
```

**Caso 3. El elemento está en medio o al final de la lista**

Si `anterior != NULL`, significa que el nodo que se desea eliminar tiene un nodo anterior.

```cpp
else {
    anterior->siguiente = aux_borrar->siguiente;
    delete aux_borrar;
}
```

Se realizan dos operaciones:

1. `anterior->siguiente = aux_borrar->siguiente`: conecta el nodo anterior con el nodo siguiente al que se va a eliminar.
2. `delete aux_borrar`: libera la memoria del nodo eliminado.

**Ejemplo. Eliminar el número `10`:**

Estado inicial:

```text
lista
  |
  v
+------+-----------+     +------+-----------+
|   5  | siguiente | --> |  10  | siguiente | --> NULL
+------+-----------+     +------+-----------+
  ^                         ^
  |                         |
anterior                aux_borrar
```

Después de ejecutar:

```cpp
anterior->siguiente = aux_borrar->siguiente;
delete aux_borrar;
```

El puntero `siguiente` del nodo que contiene `5` pasa a apuntar a `NULL`, eliminando el enlace con el nodo que contenía `10`.

La lista queda de la siguiente manera:

```text
lista
  |
  v
+------+-----------+
|   5  | siguiente | --> NULL
+------+-----------+
```

---

# 2. Código completo de `eliminarNodo()`

Integrando los cinco pasos, la función queda de la siguiente manera:

```cpp
void eliminarNodo(Nodo *&lista, int n) {
    if (lista != NULL) {
        Nodo *aux_borrar;
        Nodo *anterior = NULL;

        aux_borrar = lista;

        while ((aux_borrar != NULL) && (aux_borrar->dato != n)) {
            anterior = aux_borrar;
            aux_borrar = aux_borrar->siguiente;
        }

        if (aux_borrar == NULL) {
            cout << "El elemento no existe";
        }
        else if (anterior == NULL) {
            lista = lista->siguiente;
            delete aux_borrar;
        }
        else {
            anterior->siguiente = aux_borrar->siguiente;
            delete aux_borrar;
        }
    }
}
```

**Parámetros:**

- `Nodo *&lista`: recibe una referencia al puntero que representa el inicio de la lista. Se utiliza una referencia porque puede ser necesario modificar el primer nodo.
- `int n`: contiene el valor del elemento que se desea eliminar.

**Variables utilizadas:**

- `Nodo *aux_borrar`: apunta al nodo que se desea eliminar.
- `Nodo *anterior`: apunta al nodo anterior al que se desea eliminar. Inicialmente contiene `NULL`.

**Importante:** antes de eliminar un nodo, se debe actualizar el enlace correspondiente para no perder el acceso al resto de la lista. Después, se utiliza `delete` para liberar la memoria dinámica que ocupaba el nodo eliminado.


## 3.5 Dejar vacia la lista enlazada

# Eliminar todos los elementos de una lista enlazada

# 1. Pasos para eliminar todos los elementos de la lista

Para dejar vacía una lista enlazada, solamente hay que seguir **cuatro pasos**:

1. Crear un nodo auxiliar (`aux`) e igualarlo al inicio de la lista.
2. Guardar el dato que queremos eliminar dentro de `aux`.
3. Pasar `lista` al siguiente nodo.
4. Eliminar `aux`.

## 1.1. Crear un nodo auxiliar e igualarlo al inicio de la lista

Primero, se declara un puntero auxiliar llamado `aux` y se le asigna la dirección del primer nodo de la lista.

```cpp
Nodo *aux = lista;
```

De esta manera, `aux` y `lista` apuntan inicialmente al mismo nodo.

**Ejemplo:**

```text
lista
  |
  v
+------+-----------+     +------+-----------+
|   5  | siguiente | --> |  10  | siguiente | --> NULL
+------+-----------+
  ^
  |
 aux
```

La estructura inicial de la función es:

```cpp
void eliminarLista(Nodo *&lista, int &n) {
    Nodo *aux = lista;
}
```

## 1.2. Guardar el dato del nodo auxiliar

Se guarda en la variable `n` el valor almacenado en el campo `dato` del nodo al que apunta `aux`.

```cpp
n = aux->dato;
```

De esta forma, se conserva el dato del nodo antes de liberar su memoria.

**Ejemplo:**

Si `aux` apunta al nodo que contiene el valor `5`, entonces:

```cpp
n = aux->dato;
```

El valor de `n` será `5`.

## 1.3. Pasar la lista al siguiente nodo

Se actualiza el puntero `lista` para que apunte al siguiente nodo de la lista.

```cpp
lista = aux->siguiente;
```

Con esta instrucción, `lista` avanza al siguiente nodo, mientras que `aux` continúa apuntando al nodo que se va a eliminar.

**Ejemplo:**

Estado antes de avanzar:

```text
lista
  |
  v
+------+-----------+     +------+-----------+
|   5  | siguiente | --> |  10  | siguiente | --> NULL
+------+-----------+
  ^
  |
 aux
```

Después de ejecutar:

```cpp
lista = aux->siguiente;
```

El puntero `lista` pasa a apuntar al nodo que contiene `10`:

```text
aux
 |
 v
+------+-----------+     +------+-----------+
|   5  | siguiente | --> |  10  | siguiente | --> NULL
+------+-----------+       ^
                            |
                          lista
```

## 1.4. Eliminar el nodo auxiliar

Finalmente, se utiliza el operador `delete` para liberar la memoria dinámica que ocupaba el nodo apuntado por `aux`.

```cpp
delete aux;
```

Después de eliminar el nodo, la lista comienza en el siguiente elemento.

**Ejemplo:**

Antes de eliminar `aux`:

```text
aux
 |
 v
+------+-----------+     +------+-----------+
|   5  | siguiente | --> |  10  | siguiente | --> NULL
+------+-----------+       ^
                            |
                          lista
```

Después de ejecutar:

```cpp
delete aux;
```

El nodo que contenía `5` deja de existir y la lista queda así:

```text
lista
  |
  v
+------+-----------+
|  10  | siguiente | --> NULL
+------+-----------+
```

Este procedimiento se repite hasta que todos los nodos hayan sido eliminados y `lista` apunte a `NULL`.

---

# 2. Código completo de `eliminarLista()`

Integrando los cuatro pasos, la función queda de la siguiente manera:

```cpp
void eliminarLista(Nodo *&lista, int &n) {
    Nodo *aux = lista;

    n = aux->dato;
    lista = aux->siguiente;

    delete aux;
}
```

**Parámetros:**

- `Nodo *&lista`: recibe una referencia al puntero que representa el inicio de la lista. Se utiliza una referencia para poder modificar el puntero original.
- `int &n`: recibe una referencia a una variable donde se guarda el dato del nodo que se va a eliminar.

**Importante:** el procedimiento mostrado elimina un solo nodo por llamada. Para eliminar todos los elementos, se debe repetir mientras la lista no esté vacía, comprobando que `lista != NULL` antes de acceder a `aux->dato`.


# 4. Resumen
| Tipo de lista                 | Número de enlaces por nodo | Recorrido                           |
| ---                           | ---                        | ---                                 |
| Simplemente enlazada          | 1                          | Directo                             |
| Doblemente enlazada           | 2                          | Directo e inverso                   |
| Circular simplemente enlazada | 1                          | Directo y circular                  |
| Circular doblemente enlazada  | 2                          | Directo e inverso, ambos circulares |

### Conceptos importantes
| Concepto   | Significado                                           |
| ---        | ---                                                   |
| Nodo       | Elemento que almacena un dato y uno o más punteros.   |
| Dato       | Valor almacenado dentro de un nodo.                   |
| Puntero    | Variable que almacena una dirección de memoria.       |
| Siguiente  | Puntero que señala al nodo sucesor.                   |
| Anterior   | Puntero que señala al nodo predecesor.                |
| Cabeza     | Referencia al primer nodo de la lista.                |
| Cola       | Referencia o posición correspondiente al último nodo. |
| NULL       | Indica que un puntero no apunta a ningún nodo.        |
| Predecesor | Nodo que se encuentra antes del nodo actual.          |
| Sucesor    | Nodo que se encuentra después del nodo actual.        |