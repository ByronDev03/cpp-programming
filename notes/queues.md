<h1 align="center">Colas en C++</h1>

## ¿Qué es?
Una **cola** es una estructura de datos lineal caracterizada por ser una secuencia de elementos en la que la operación de inserción se realiza por un extremo y la extracción por el otro. Las colas siguen el principio **FIFO** (*First In, First Out*), que significa: *el primero en entrar es el primero en salir*. Un ejemplo cotidiano es una fila de personas: quien llega primero a la fila es atendido primero.
En una cola se distinguen dos extremos:

- **Frente:** extremo por el que se extraen o quitan los elementos.
- **Final:** extremo por el que se insertan los elementos.

## Operaciones básicas de una cola
Las operaciones usuales en las colas son **Insertar** y **Quitar**.
- **Insertar (`enqueue`):** añade un elemento por el extremo final de la cola.
- **Quitar (`dequeue`):** elimina o extrae un elemento por el extremo del frente.

## Ejemplo de inserción y extracción
Supongamos que inicialmente tenemos una cola vacía.

**1. Insertar X**

```text
Frente
  |
  v
+---+---+---+---+---+
| X |   |   |   |   |
+---+---+---+---+---+
  ^
  Final
```

**2. Insertar Y**

```text
Frente  Final
  |       |
  v       v
+---+---+---+---+---+
| X | Y |   |   |   |
+---+---+---+---+---+
```

**3. Insertar Z**

```text
Frente      Final
  |           |
  v           v
+---+---+---+---+---+
| X | Y | Z |   |   |
+---+---+---+---+---+
```

**4. Quitar un elemento**

Se elimina `X`, porque fue el primer elemento en entrar.

```text
Frente  Final
  |       |
  v       v
+---+---+---+---+---+
| Y | Z |   |   |   |
+---+---+---+---+---+
```

**5. Quitar otro elemento**

Se elimina `Y`. Ahora `Z` queda al frente.

```text
Frente
  |
  v
+---+---+---+---+---+
| Z |   |   |   |   |
+---+---+---+---+---+
  ^
  Final
```

Este comportamiento demuestra el principio **FIFO**: el primer elemento insertado (`X`) es el primero en salir.

---

## Representación de una cola mediante nodos

Una cola puede implementarse mediante una **lista enlazada**. Para ello, se utiliza una estructura llamada `Nodo`.

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

### Punteros de la cola

Para administrar una cola implementada mediante nodos se utilizan dos punteros:

- **`frente`:** apunta al primer nodo, que es el siguiente elemento que se eliminará.
- **`fin`:** apunta al último nodo, donde se insertarán los nuevos elementos.

### Representación de una cola enlazada

```text
frente                                  fin
  |                                       |
  v                                       v
+------+-----------+     +------+-----------+
| dato | siguiente | --> | dato | siguiente | --> NULL
+------+-----------+     +------+-----------+
```

Cuando la cola está vacía, ambos punteros deben apuntar a `NULL`:

```cpp
frente = NULL;
fin = NULL;
```

---

## Insertar elementos en una cola

Para insertar elementos en una cola, solo hay que seguir **3 pasos**:

1. Crear espacio en memoria para almacenar un nodo.
2. Asignar ese nuevo nodo al dato que queremos insertar.
3. Asignar los punteros `frente` y `fin` hacia el nuevo nodo, según corresponda.

### Paso 1. Crear espacio en memoria para almacenar un nodo

Primero, se crea un nuevo nodo utilizando `new`.

```cpp
Nodo *nuevo_nodo = new Nodo();
```

También se considera que inicialmente la cola está vacía:

```cpp
frente = NULL;
fin = NULL;
```

El puntero `nuevo_nodo` guarda la dirección de memoria del nodo recién creado.

```text
nuevo_nodo
    |
    v
+------+-----------+
|      |           |
+------+-----------+
```

### Paso 2. Asignar el dato al nuevo nodo

Se almacena en el campo `dato` el valor que queremos insertar.

Después, se establece el campo `siguiente` en `NULL`, porque el nuevo nodo será el último de la cola.

```cpp
nuevo_nodo->dato = n;
nuevo_nodo->siguiente = NULL;
```

Por ejemplo, si `n = 10`, el nodo queda así:

```text
nuevo_nodo
    |
    v
+------+-----------+
|  10  | siguiente | ---> NULL
+------+-----------+
```

### Paso 3. Asignar los punteros `frente` y `fin` hacia el nuevo nodo

La actualización depende de si la cola está vacía o si ya contiene uno o más nodos.

#### Caso 1. La cola está vacía

Si `frente` apunta a `NULL`, el nuevo nodo será el primero y también el último.

Por eso, ambos punteros deben apuntar al nuevo nodo:

```cpp
frente = nuevo_nodo;
fin = nuevo_nodo;
```

Representación:

```text
       frente
          |
          v
      +------+-----------+
      |  10  | siguiente | ---> NULL
      +------+-----------+
          ^
          |
         fin
```

#### Caso 2. La cola tiene uno o más nodos

Si la cola ya contiene elementos, se enlaza el nodo que actualmente señala `fin` con el nuevo nodo.

```cpp
fin->siguiente = nuevo_nodo;
```

Después, se actualiza `fin` para que apunte al nuevo último nodo:

```cpp
fin = nuevo_nodo;
```

**Ejemplo: insertar 20 en una cola que ya contiene 10.**

Antes de insertar:

```text
frente                  fin
  |                      |
  v                      v
+------+-----------+   +------+-----------+
|  10  | siguiente |-->|  20  | siguiente | ---> NULL
+------+-----------+   +------+-----------+
```

Después de insertar, el puntero `fin` debe señalar al nuevo último nodo.

### Código completo de la operación Insertar

```cpp
void insertarCola(Nodo *&frente, Nodo *&fin, int n) {
    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = NULL;

    if (frente == NULL) {
        frente = nuevo_nodo;
    } else {
        fin->siguiente = nuevo_nodo;
    }

    fin = nuevo_nodo;
}
```

**Explicación del código:**

1. Se crea un nuevo nodo en memoria.
2. Se almacena el valor `n` en el campo `dato`.
3. Se establece `siguiente` en `NULL`.
4. Se comprueba si la cola está vacía.
5. Si está vacía, `frente` apunta al nuevo nodo.
6. Si ya contiene elementos, el último nodo apunta al nuevo nodo.
7. Finalmente, `fin` se actualiza para apuntar al nuevo nodo.

**Complejidad temporal:**

- **Mejor caso:** O(1).
- **Caso promedio:** O(1).
- **Peor caso:** O(1).

La inserción tiene una complejidad temporal constante **O(1)**, porque no es necesario recorrer los nodos para agregar un elemento.

---

## Eliminar elementos de una cola

Para eliminar elementos de una cola, solo hay que seguir **3 pasos**:

1. Obtener el valor del nodo.
2. Crear un nodo auxiliar (`aux`) y asignarle el frente de la cola.
3. Eliminar el nodo del frente de la cola.

### Paso 1. Obtener el valor del nodo

Primero, se obtiene el valor almacenado en el nodo que señala el puntero `frente`.

```cpp
n = frente->dato;
```

Por ejemplo, si tenemos una cola con un solo elemento:

```text
frente
   |
   v
+------+-----------+
|  10  | siguiente | ---> NULL
+------+-----------+
   ^
   |
  fin
```

El valor `10` se almacena en la variable `n`.

```cpp
n = frente->dato;
```

### Paso 2. Crear un nodo auxiliar y asignarle el frente de la cola

Se crea un puntero auxiliar llamado `aux`, que guardará la dirección del primer nodo de la cola.

```cpp
Nodo *aux = frente;
```

De esta manera, tanto `frente` como `aux` apuntan al mismo nodo.

Antes:

```text
frente
   |
   v
+------+-----------+     +------+-----------+
|  10  | siguiente | --> |  20  | siguiente | ---> NULL
+------+-----------+     +------+-----------+
```

Después:

```text
frente
   |
   v
+------+-----------+     +------+-----------+
|  10  | siguiente | --> |  20  | siguiente | ---> NULL
+------+-----------+     +------+-----------+
   ^
   |
  aux
```

### Paso 3. Eliminar el nodo del frente de la cola

Para eliminar el primer nodo, debemos considerar dos situaciones:

#### Caso 1. La cola tiene un solo nodo

Si `frente == fin`, significa que la cola solamente contiene un elemento.

Primero, se elimina el nodo y ambos punteros se establecen en `NULL`.

```cpp
if (frente == fin) {
    frente = NULL;
    fin = NULL;
}
```

Representación:

Antes de eliminar:

```text
frente
   |
   v
+------+-----------+
|  10  | siguiente | ---> NULL
+------+-----------+
   ^
   |
  fin
```

Después de actualizar los punteros:

```text
frente ---> NULL
fin    ---> NULL
```

El nodo ya no forma parte de la cola y puede eliminarse mediante `delete`.

#### Caso 2. La cola tiene más de un nodo

Si existen dos o más nodos, el puntero `frente` debe avanzar al siguiente nodo.

```cpp
frente = frente->siguiente;
```

Antes:

```text
frente                 fin
   |                    |
   v                    v
+------+-----------+  +------+-----------+
|  10  | siguiente |->|  20  | siguiente | ---> NULL
+------+-----------+  +------+-----------+
   ^
   |
  aux
```

Después de actualizar `frente`:

```text
aux              frente      fin
 |                  |          |
 v                  v          v
+------+-----------+  +------+-----------+
|  10  | siguiente |->|  20  | siguiente | ---> NULL
+------+-----------+  +------+-----------+
```

Ahora `frente` apunta al nodo que anteriormente era el segundo.

Finalmente, se elimina el nodo antiguo utilizando `delete`:

```cpp
delete aux;
```

La cola queda así:

```text
frente
   |
   v
+------+-----------+
|  20  | siguiente | ---> NULL
+------+-----------+
   ^
   |
  fin
```

### Código completo de la operación Quitar

```cpp
void suprimirCola(Nodo *&frente, Nodo *&fin, int &n) {

    if (frente == NULL) {
        return;
    }

    n = frente->dato;

    Nodo *aux = frente;

    if (frente == fin) {
        frente = NULL;
        fin = NULL;
    }
    else {
        frente = frente->siguiente;
    }

    delete aux;
}
```

**Explicación del código:**

1. Se comprueba si la cola está vacía. Si lo está, no se realiza ninguna operación.
2. Se obtiene el valor del primer nodo y se almacena en `n`.
3. Se crea un puntero auxiliar `aux` que apunta al primer nodo.
4. Se comprueba si la cola tiene un solo nodo.
5. Si tiene un solo nodo, `frente` y `fin` se establecen en `NULL`.
6. Si tiene más de un nodo, `frente` avanza al siguiente nodo.
7. Finalmente, se elimina el nodo antiguo utilizando `delete aux`.

**Nota:** la variable `n` se pasa por referencia (`int &n`) para que la función pueda devolver el valor del elemento eliminado.

**Complejidad temporal:**

- **Mejor caso:** O(1).
- **Caso promedio:** O(1).
- **Peor caso:** O(1).

La eliminación tiene una complejidad temporal constante **O(1)**, porque únicamente se accede al primer nodo y se actualizan los punteros, sin recorrer toda la cola.

---

## Resumen de las operaciones de una cola

| Operación | Descripción | Complejidad temporal |
|---|---|---|
| Insertar (`enqueue`) | Agrega un elemento al final. | O(1) |
| Quitar (`dequeue`) | Elimina el elemento del frente. | O(1) |

**Importante:** estas complejidades corresponden a una cola implementada mediante una lista enlazada que mantiene los punteros `frente` y `fin`. Esto permite insertar y eliminar elementos sin recorrer la estructura.

## Conceptos importantes

| Concepto | Significado |
|---|---|
| FIFO | Primero en entrar, primero en salir. |
| Frente | Puntero al primer nodo de la cola. |
| Fin | Puntero al último nodo de la cola. |
| Nodo | Estructura que almacena un dato y un puntero al siguiente nodo. |
| `new` | Reserva espacio en memoria para un nuevo nodo. |
| `delete` | Libera la memoria de un nodo. |
| `NULL` | Representa un puntero que no apunta a ningún objeto. |
| `aux` | Puntero auxiliar utilizado para conservar la dirección del nodo que se eliminará. |
| `enqueue` | Operación de inserción. |
| `dequeue` | Operación de eliminación. |