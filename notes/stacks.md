# Pilas

## 1. Concepto de pila

Una **pila** es una estructura de datos lineal en la que los elementos se introducen y eliminan por un único extremo, llamado **cima** (*top*).

La pila sigue el principio **LIFO** (*Last In, First Out*), que significa: *el último elemento en entrar es el primero en salir*.

Por ejemplo, al apilar platos, el último plato colocado encima es el primero que podemos retirar.

## 2. Operaciones básicas de una pila

Las operaciones usuales de una pila son **Insertar** y **Quitar**:

- **Insertar (`push`):** añade un elemento en la cima de la pila.
- **Quitar (`pop`):** elimina y extrae el elemento que se encuentra en la cima.

### Ejemplo

Si insertamos los elementos `M`, `A` y `C`, la pila queda así:

```text
       C  <- Cima
       A
       M
```

Al quitar elementos, se extraen en el orden inverso al que fueron insertados:

| Operación | Elemento retirado | Elementos que permanecen |
|---|---|---|
| Insertar M | — | M |
| Insertar A | — | M, A |
| Insertar C | — | M, A, C |
| Quitar | C | M, A |
| Quitar | A | M |
| Quitar | M | Pila vacía |

**Entrada:** `MAC`

**Salida:** `CAM`

Esto demuestra el comportamiento LIFO: el último elemento insertado (`C`) es el primero en salir.

## 3. Representación de una pila mediante nodos

Una pila también puede implementarse mediante una **lista enlazada**. Para ello, se utiliza una estructura llamada `Nodo`.

Cada nodo contiene dos campos:

- **`dato`:** almacena el valor del elemento.
- **`siguiente`:** es un puntero que guarda la dirección del siguiente nodo.

### Estructura de un nodo en C++

```cpp
struct Nodo {
    int dato;
    Nodo *siguiente;
};
```

### Ejemplo de una lista de nodos

Una secuencia de nodos se enlaza mediante el puntero `siguiente`. El último nodo apunta a `nullptr`, lo que indica que no hay otro nodo después de él.

```text
+---------+-----------+
|  dato   | siguiente |       Nodo
+---------+-----------+
     |          |
     v          |
+---------+-----------+
|  dato   | siguiente |
+---------+-----------+
     |          |
     v          |
+---------+-----------+
|  dato   | siguiente |
+---------+-----------+
                |
                v
              nullptr
```

En una implementación de pila con lista enlazada, normalmente se mantiene un puntero llamado `cima` que apunta al primer nodo. Las inserciones y eliminaciones se realizan en ese extremo.


## 4. Insertar elementos en una pila

Para insertar un elemento en una pila implementada mediante una lista enlazada, se siguen **cuatro pasos**:

1. Crear el espacio en memoria para almacenar un nuevo nodo.
2. Cargar el valor dentro del nodo (`dato`).
3. Asignar el puntero de la pila al campo `siguiente` del nuevo nodo.
4. Asignar el nuevo nodo como la nueva cima de la pila.

### Paso 1. Crear el espacio en memoria

Primero, se crea un nuevo nodo utilizando el operador `new`. Este reserva memoria dinámica para almacenar el nodo.

Antes de insertar el primer elemento, la pila está vacía y su puntero tiene el valor `nullptr`.

```cpp
pila = nullptr;

Nodo *nuevo_nodo = new Nodo();
```

La estructura del nodo es:

```cpp
struct Nodo {
    int dato;
    Nodo *siguiente;
};
```

En este momento, `nuevo_nodo` apunta al espacio de memoria reservado para el nuevo nodo.

### Paso 2. Cargar el valor dentro del nodo

Se asigna al campo `dato` el valor que queremos insertar. En el ejemplo, se inserta el número `10`.

```cpp
nuevo_nodo->dato = 10;
```

El operador `->` permite acceder a los miembros de una estructura o clase mediante un puntero.

### Paso 3. Enlazar el nuevo nodo con la pila

El campo `siguiente` del nuevo nodo debe apuntar al nodo que actualmente se encuentra en la cima de la pila.

```cpp
nuevo_nodo->siguiente = pila;
```

Si la pila está vacía, `pila` vale `nullptr`, por lo que el campo `siguiente` del nuevo nodo también apuntará a `nullptr`.

Si ya existen elementos, el nuevo nodo quedará enlazado con el que anteriormente era la cima.

### Paso 4. Actualizar la cima de la pila

Finalmente, se actualiza el puntero `pila` para que apunte al nuevo nodo.

```cpp
pila = nuevo_nodo;
```

De esta manera, el nuevo nodo se convierte en la cima de la pila.

### Código completo de la función `agregarPila()`

```cpp
void agregarPila(Nodo *&pila, int n) {
    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = pila;

    pila = nuevo_nodo;
}
```

**Parámetros:**

- `Nodo *&pila`: recibe la referencia al puntero que representa la cima de la pila. Se utiliza una referencia para poder modificar el puntero original.
- `int n`: contiene el valor que se desea insertar.

**Importante:** el orden de las instrucciones es fundamental. Primero se enlaza el nuevo nodo con la pila existente y después se actualiza `pila`. Así no se pierde la referencia a los elementos que ya estaban almacenados.

### Ejemplo del resultado

Si la pila estaba vacía y se inserta el valor `10`, queda de la siguiente manera:

```text
pila
  |
  v
+------+-----------+
|  10  | siguiente | ----> nullptr
+------+-----------+
```


## 5. Quitar elementos de una pila

Para quitar un elemento de una pila implementada mediante una lista enlazada, se siguen **cuatro pasos**. La operación elimina siempre el nodo que se encuentra en la cima.

### Paso 1. Crear una variable auxiliar de tipo `Nodo`

Se declara un puntero auxiliar llamado `aux` y se le asigna la dirección del primer nodo de la pila.

```cpp
Nodo *aux = pila;
```

De esta manera, `aux` apunta al nodo que se va a eliminar, mientras que `pila` todavía conserva la dirección de la cima actual.

### Paso 2. Guardar el dato del nodo en la variable `n`

Se copia el valor almacenado en el campo `dato` del nodo apuntado por `aux` a la variable `n`.

```cpp
n = aux->dato;
```

Así se conserva el valor del elemento que se está quitando, incluso después de liberar la memoria del nodo.

### Paso 3. Avanzar la cima al siguiente nodo

Se actualiza el puntero `pila` para que apunte al siguiente nodo de la pila.

```cpp
pila = aux->siguiente;
```

Con esto, el segundo nodo pasa a ser la nueva cima. El puntero `aux` sigue apuntando al nodo anterior, que es el que se eliminará.

### Paso 4. Eliminar el nodo auxiliar

Finalmente, se libera la memoria reservada para el nodo que se quitó de la pila.

```cpp
delete aux;
```

Después de esta instrucción, el nodo deja de existir y la pila comienza en el nodo que ahora señala `pila`.

### Código completo de la función `sacarPila()`

```cpp
void sacarPila(Nodo *&pila, int &n) {
    Nodo *aux = pila;

    n = aux->dato;
    pila = aux->siguiente;

    delete aux;
}
```

**Parámetros:**

- `Nodo *&pila`: referencia al puntero que representa la cima de la pila. Se modifica para que apunte al siguiente nodo.
- `int &n`: referencia a una variable donde se guarda el dato del nodo eliminado.

**Importante:** antes de llamar a `sacarPila()`, se debe comprobar que la pila no esté vacía (`pila != nullptr`). Si está vacía, no existe un nodo que pueda consultarse o eliminarse. Acceder a `aux->dato` en ese caso provocaría un comportamiento indefinido.

### Ejemplo del proceso

Supongamos que la pila contiene los valores `5` y `10`:

**Estado inicial:**

```text
pila
  |
  v
+------+-----------+      +------+-----------+
|  5   | siguiente | ---> |  10  | siguiente | ---> nullptr
+------+-----------+      +------+-----------+
```

1. `aux = pila`: `aux` apunta al nodo que contiene `5`.
2. `n = aux->dato`: se guarda `5` en la variable `n`.
3. `pila = aux->siguiente`: `pila` pasa a apuntar al nodo que contiene `10`.
4. `delete aux`: se libera el nodo que contenía `5`.

**Estado final:**

```text
pila
  |
  v
+------+-----------+
|  10  | siguiente | ---> nullptr
+------+-----------+
```

El valor eliminado se conserva en `n`, mientras que la cima de la pila ahora apunta al elemento `10`.
