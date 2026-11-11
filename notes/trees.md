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
4. [Insertar un nodo en el árbol]()
    - [4.1. Creación de un nodo]()
    - [4.2. Definición de la función insertar]()
    - [4.3. Inserción en un árbol vacío]()
    - [4.4. Inserción en un árbol con elementos]()
    - [4.5. Ejemplo de inserción]()
    - [4.6. Código completo de la función]()
    - [4.7. Resumen del funcionamiento]()
5. [Mostrar el árbol completo]()
    - [5.1. Definición de la función]()
    - [5.2. Comprobación de árbol vacío]()
    - [5.3. Recorrido e impresión de los nodos]()
    - [5.4. Ejemplo de ejecución]()
    - [5.5. Código completo de la función]()
    - [5.6. Resumen del funcionamiento]()
6. [Búsqueda de un nodo en el árbol]()
    - [6.1. Definición de la función]()
    - [6.2. Condiciones de búsqueda]()
    - [6.3. Ejemplo de búsqueda]()
    - [6.4. Código completo de la función]()
    - [6.5. Resumen del funcionamiento]() 
7. [Recorridos de árboles binarios]()
    - [7.1. Recorrido de árboles - PreOrden]() 
        - [7.1.1. Definición de la función PreOrden]() 
        - [7.1.2. Ejemplo de ejecución]() 
        - [7.1.3. Resumen del recorrido en PreOrden]() 
    - [7.2. Recorrido de árboles - InOrden]()      
        - [7.2.1. Definición de la función InOrden]() 
        - [7.2.2. Ejemplo de ejecución]() 
        - [7.2.3. Resumen del recorrido en InOrden]() 
    - [7.3. Recorrido de árboles - PostOrden]()                            
        - [7.3.1. Definición de la función PostOrden ]() 
        - [7.3.2. Ejemplo de ejecución]() 
        - [7.3.3. Resumen del recorrido en PostOrden]() 
    - [7.4. Comparación de los tres recorridos]()

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

# 4. Insertar un nodo en el árbol
La inserción consiste en agregar un nuevo elemento a un árbol binario de búsqueda, respetando las reglas que determinan la ubicación de cada nodo.

Para realizar esta operación debemos considerar dos situaciones:

1. **El árbol está vacío:** el nuevo nodo se convierte en la raíz del árbol.
2. **El árbol ya contiene elementos:** debemos comparar el valor que queremos insertar con los nodos existentes para encontrar su posición correspondiente.

Recordemos las reglas de un árbol binario de búsqueda:

- Los valores menores que un nodo se insertan en su subárbol izquierdo.
- Los valores mayores o iguales se insertan en su subárbol derecho, de acuerdo con la implementación presentada en estos apuntes.

## 4.1. Creación de un nodo
Primero necesitamos una función que permita crear un nuevo nodo y asignarle el valor que queremos almacenar.

Para ello utilizamos memoria dinámica mediante el operador `new`.

**Estructura del nodo:**
```cpp
struct Nodo {
    int dato;
    Nodo *der;
    Nodo *izq;
};
```

Cada nodo contiene tres campos:

- `dato`: almacena el valor del nodo.
- `der`: apunta al hijo derecho.
- `izq`: apunta al hijo izquierdo.

**Función para crear un nodo:**
```cpp
Nodo *crearNodo(int n) {

    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo->dato = n;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;

    return nuevo_nodo;
}
```

**Explicación paso a paso:**
1. Se reserva memoria dinámica para un nuevo nodo utilizando `new Nodo()`.
2. Se asigna el valor recibido en el parámetro `n` al campo `dato`.
3. Se inicializan los punteros `der` e `izq` en `NULL`, porque el nuevo nodo todavía no tiene hijos.
4. Finalmente, se devuelve el puntero `nuevo_nodo` para poder utilizarlo dentro del árbol.

## 4.2. Definición de la función insertar
Una vez que tenemos la función para crear nodos, definimos la función encargada de insertarlos en el árbol.

```cpp
void insertar(Nodo *&arbol, int n) {

}
```

La función recibe dos parámetros:

- `Nodo *&arbol`: referencia al puntero del árbol. Permite modificar directamente el puntero cuando sea necesario insertar la raíz o actualizar un enlace.
- `int n`: valor que queremos insertar.

El tipo de retorno es `void`, porque la función modifica directamente la estructura del árbol.

## 4.3. Inserción en un árbol vacío
Primero debemos comprobar si el árbol está vacío.
```cpp
if (arbol == NULL) {

    Nodo *nuevo_nodo = crearNodo(n);

    arbol = nuevo_nodo;

}
```

**Explicación:**
1. Se comprueba si el puntero `arbol` es igual a `NULL`.
2. Si está vacío, se llama a la función `crearNodo(n)` para generar un nuevo nodo.
3. El puntero `arbol` recibe la dirección del nuevo nodo.
4. De esta manera, el nuevo nodo se convierte en la raíz del árbol o en el hijo correspondiente de otro nodo.

**Ejemplo:**
Si el árbol está vacío y queremos insertar el valor `10`, el resultado será:
```text
    10
```

## 4.4. Inserción en un árbol con elementos
Si el árbol ya contiene uno o más nodos, necesitamos encontrar la posición correcta para insertar el nuevo elemento. Para ello utilizamos una condición que compara el valor que queremos insertar con el dato de la raíz actual.
```cpp
else {
    int valorRaiz = arbol->dato;
    if (n < valorRaiz) {
        insertar(arbol->izq, n);
    }
    else {
        insertar(arbol->der, n);
    }
}
```

**Explicación paso a paso:**

**1. Obtener el valor de la raíz**
```cpp
int valorRaiz = arbol->dato;
```

Se obtiene el valor almacenado en el nodo actual y se guarda en la variable `valorRaiz`.

**2. Comprobar si el valor es menor**
```cpp
if (n < valorRaiz) {
    insertar(arbol->izq, n);
}
```

Si el valor que queremos insertar es menor que el valor de la raíz actual, debemos continuar por el subárbol izquierdo.

Se realiza una llamada recursiva a `insertar()`, pasando como primer parámetro el puntero `arbol->izq`.

**3. Insertar en el subárbol derecho**
```cpp
else {
    insertar(arbol->der, n);
}
```

- Si el valor es mayor o igual que el valor de la raíz actual, debemos continuar por el subárbol derecho.
- Nuevamente se realiza una llamada recursiva, pero ahora utilizando el puntero `arbol->der`.
- Este proceso se repite hasta encontrar una posición vacía (`NULL`), donde se crea e inserta el nuevo nodo.

## 4.5. Ejemplo de inserción
Consideremos el siguiente árbol binario de búsqueda:
```text
        10
       /  \
      5    15
```

Queremos insertar los siguientes valores:
```cpp
insertar(arbol, 4);
insertar(arbol, 8);
insertar(arbol, 20);
```

**Ejemplo 1: Insertar el valor 4**
1. Se compara `4` con la raíz `10`.
2. Como `4` es menor que `10`, se continúa por la izquierda.
3. Se compara `4` con el nodo `5`.
4. Como `4` es menor que `5`, se continúa por la izquierda.
5. Se encuentra una posición vacía (`NULL`) y se crea el nuevo nodo.

Resultado:
```text
        10
       /  \
      5    15
     /
    4
```

**Ejemplo 2: Insertar el valor 8**
1. Se compara `8` con la raíz `10`.
2. Como `8` es menor que `10`, se continúa por la izquierda.
3. Se compara `8` con el nodo `5`.
4. Como `8` es mayor que `5`, se continúa por la derecha.
5. Se encuentra una posición vacía y se inserta el nuevo nodo.

Resultado:
```text
        10
       /  \
      5    15
     / \
    4   8
```

**Ejemplo 3: Insertar el valor 20**
1. Se compara `20` con la raíz `10`.
2. Como `20` es mayor que `10`, se continúa por la derecha.
3. Se compara `20` con el nodo `15`.
4. Como `20` es mayor que `15`, se continúa por la derecha.
5. Se encuentra una posición vacía y se inserta el nuevo nodo.

Resultado final:
```text
        10
       /  \
      5    15
     / \     \
    4   8     20
```

## 4.6. Código completo de la función
Una vez comprendidos los pasos anteriores, podemos unirlos en una sola función:
```cpp
void insertar(Nodo *&arbol, int n) {

    if (arbol == NULL) {

        Nodo *nuevo_nodo = crearNodo(n);
        arbol = nuevo_nodo;
    }
    else {

        int valorRaiz = arbol->dato;

        if (n < valorRaiz) {
            insertar(arbol->izq, n);
        }
        else {
            insertar(arbol->der, n);
        }
    }
}
```

**Ejemplo de llamadas:**
```cpp
insertar(arbol, 10);
insertar(arbol, 5);
insertar(arbol, 15);
insertar(arbol, 4);
insertar(arbol, 8);
insertar(arbol, 20);
```

## 4.7. Resumen del funcionamiento
| Condición           | Acción                                  |
| ---                 | ---                                     |
| `arbol == NULL`     | Crear un nuevo nodo.                    |
| `n < valorRaiz`     | Continuar por el subárbol izquierdo.    |
| `n >= valorRaiz`    | Continuar por el subárbol derecho.      |
| Se encuentra `NULL` | Insertar el nuevo nodo en esa posición. |

**Complejidad temporal:**
- Mejor caso: \(O(1)\), cuando se inserta directamente en la raíz de un árbol vacío.
- Caso promedio: \(O(\log n)\), cuando el árbol está aproximadamente equilibrado.
- Peor caso: \(O(n)\), cuando el árbol está degenerado.

Donde `n` representa la cantidad de nodos que contiene el árbol antes de realizar la inserción.

**Complejidad espacial:** \(O(h)\), debido a las llamadas recursivas, donde `h` representa la altura del árbol.

---

# 5. Mostrar el árbol completo
Mostrar el árbol completo consiste en recorrer todos sus nodos e imprimir sus valores, procurando representar visualmente la estructura jerárquica del árbol.
Para conseguirlo, se utiliza una función recursiva que recorre primero el subárbol derecho, imprime el nodo actual y finalmente recorre el subárbol izquierdo.
De esta manera, el árbol se representa de forma vertical, colocando los nodos del subárbol derecho en la parte superior y los del subárbol izquierdo en la parte inferior.

## 5.1. Definición de la función
Primero definimos una función llamada `mostrarArbol()` que recibe dos parámetros:

- `Nodo *arbol`: puntero al nodo actual del árbol.
- `int contador`: variable que permite controlar la cantidad de espacios de indentación para representar los niveles del árbol.

La función utiliza el tipo de retorno `void`, ya que su propósito es mostrar los elementos en pantalla y no devolver ningún valor.

**Definición:**
```cpp
void mostrarArbol(Nodo *arbol, int contador) {

}
```

## 5.2. Comprobación de árbol vacío
Antes de comenzar a recorrer los nodos, debemos comprobar si el árbol está vacío o si se ha llegado a una posición sin elementos.

```cpp
if (arbol == NULL) {
    return;
}
```

**Explicación:**
- Si el puntero `arbol` es igual a `NULL`, significa que no existe ningún nodo en esa posición.
- En ese caso, la función ejecuta `return` y finaliza esa llamada recursiva sin realizar ninguna impresión.

## 5.3. Recorrido e impresión de los nodos
Si el árbol no está vacío, se ejecutan tres pasos:

**1. Recorrer el subárbol derecho**
```cpp
mostrarArbol(arbol->der, contador + 1);
```

Se realiza una llamada recursiva para recorrer primero el subárbol derecho.

El contador aumenta en uno para representar el siguiente nivel de profundidad.

**2. Imprimir los espacios de indentación**
```cpp
for (int i = 0; i < contador; i++) {
    cout << "    ";
}
```

Se utiliza un ciclo `for` para imprimir espacios antes del valor del nodo.

La cantidad de espacios depende del valor de `contador`:

- `contador = 0`: nodo sin indentación.
- `contador = 1`: un nivel de indentación.
- `contador = 2`: dos niveles de indentación.
- `contador = 3`: tres niveles de indentación.

Esto permite distinguir visualmente los diferentes niveles del árbol.

**3. Mostrar el dato del nodo actual**
```cpp
cout << arbol->dato << endl;
```

Se imprime el valor almacenado en el nodo actual y se realiza un salto de línea.

**4. Recorrer el subárbol izquierdo**
```cpp
mostrarArbol(arbol->izq, contador + 1);
```

Finalmente, se realiza otra llamada recursiva para recorrer el subárbol izquierdo, aumentando nuevamente el contador.

## 5.4. Ejemplo de ejecución
Consideremos el siguiente árbol binario de búsqueda:

```text
             8
           /   \
          3     10
         / \      \
        1   6      14
           / \    /
          4   7  13
```

Al ejecutar la función `mostrarArbol(arbol, 0)`, el recorrido se realiza en el siguiente orden:

1. Se recorre el subárbol derecho.
2. Se imprime el nodo actual.
3. Se recorre el subárbol izquierdo.

**Orden de impresión:**
```text
8
    10
        14
            13
    3
        6
            7
            4
        1
```

**Interpretación:**
- El nodo raíz `8` se imprime sin espacios de indentación.
- Los nodos `10` y `3` pertenecen al segundo nivel.
- Los nodos `14`, `6` y `1` pertenecen al siguiente nivel.
- Los nodos `13`, `7` y `4` aparecen en el nivel más profundo.

La representación obtenida permite visualizar la estructura del árbol de manera vertical.

## 5.5. Código completo de la función
```cpp
void mostrarArbol(Nodo *arbol, int contador) {

    if (arbol == NULL) {
        return;
    }
    else {

        // Recorrer el subárbol derecho
        mostrarArbol(arbol->der, contador + 1);

        // Imprimir espacios de indentación
        for (int i = 0; i < contador; i++) {
            cout << "    ";
        }

        // Mostrar el dato del nodo actual
        cout << arbol->dato << endl;

        // Recorrer el subárbol izquierdo
        mostrarArbol(arbol->izq, contador + 1);
    }
}
```

**Llamada a la función:**

```cpp
mostrarArbol(arbol, 0);
```

Se utiliza `0` como valor inicial del contador porque el nodo raíz no necesita espacios de indentación.

## 5.6. Resumen del funcionamiento
| Paso | Operación                 | Propósito                                 |
| ---  | ---                       | ---                                       |
| 1    | Comprobar `arbol == NULL` | Evitar recorrer posiciones vacías.        |
| 2    | Recorrer `arbol->der`     | Mostrar primero el subárbol derecho.      |
| 3    | Ciclo `for`               | Aplicar la indentación correspondiente.   |
| 4    | `cout << arbol->dato`     | Imprimir el nodo actual.                  |
| 5    | Recorrer `arbol->izq`     | Mostrar finalmente el subárbol izquierdo. |

- **Complejidad temporal:** \(O(n)\), porque se visitan todos los nodos del árbol.
- **Complejidad espacial:** \(O(h)\), debido a las llamadas recursivas almacenadas en la pila, donde `h` representa la altura del árbol.

---

# 6. Búsqueda de un nodo en el árbol
La búsqueda permite determinar si un valor específico se encuentra almacenado dentro de un árbol binario de búsqueda.
Para realizarla, se compara el valor que buscamos con el dato del nodo actual. Dependiendo del resultado de la comparación, se continúa la búsqueda por el subárbol izquierdo o derecho. La búsqueda aprovecha la organización del árbol binario de búsqueda para evitar recorrer todos sus nodos.

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

# 7. Recorridos de árboles binarios
Los recorridos de árboles binarios son procedimientos que permiten visitar y procesar todos los nodos de un árbol siguiendo un orden determinado.
Existen tres recorridos principales:
- **PreOrden (PreOrder):** raíz, izquierdo, derecho.
- **InOrden (InOrder):** izquierdo, raíz, derecho.
- **PostOrden (PostOrder):** izquierdo, derecho, raíz.

Cada recorrido utiliza recursividad para visitar los nodos de los subárboles izquierdo y derecho.

## 7.1. Recorrido en PreOrden (PreOrder)
El recorrido en PreOrden consiste en visitar los nodos de un árbol binario siguiendo este orden:

1. Visitar la raíz.
2. Recorrer el subárbol izquierdo.
3. Recorrer el subárbol derecho.

Su orden de ejecución se representa de la siguiente manera:

\[\boxed{\text{Raíz} \rightarrow \text{Izquierdo} \rightarrow \text{Derecho}}\]

**Ejemplo:**

Consideremos el siguiente árbol binario:

```text
          8
        /   \
       3     10
      / \      \
     1   6      14
        / \    /
       4   7  13
```

Para recorrerlo en PreOrden seguimos estos pasos:

1. Visitamos la raíz: `8`.
2. Recorremos el subárbol izquierdo:
   - Visitamos `3`.
   - Visitamos su hijo izquierdo: `1`.
   - Visitamos su hijo derecho: `6`.
   - Visitamos el hijo izquierdo de `6`: `4`.
   - Visitamos el hijo derecho de `6`: `7`.
3. Recorremos el subárbol derecho:
   - Visitamos `10`.
   - Visitamos su hijo derecho: `14`.
   - Visitamos el hijo izquierdo de `14`: `13`.

**Secuencia del recorrido:**

```text
8 - 3 - 1 - 6 - 4 - 7 - 10 - 14 - 13
```

## 7.1.1. Definición de la función PreOrden
Para implementar este recorrido en C++ utilizamos una función recursiva llamada `preOrden()`.
```cpp
void preOrden(Nodo *arbol) {

    if (arbol == NULL) {
        return;
    }
    else {

        cout << arbol->dato << " - ";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}
```

**Explicación paso a paso:**

**1. Comprobar si el árbol está vacío**
```cpp
if (arbol == NULL) {
    return;
}
```

Se verifica si el puntero recibido es igual a `NULL`.

- Si es `NULL`, significa que no existe ningún nodo que visitar y la función termina.
- Si no es `NULL`, continúa con el recorrido.

**2. Visitar la raíz**
```cpp
cout << arbol->dato << " - ";
```

Se muestra el valor almacenado en el nodo actual.

Esta instrucción se ejecuta antes de recorrer sus hijos, por lo que primero se visita la raíz.

**3. Recorrer el subárbol izquierdo**
```cpp
preOrden(arbol->izq);
```

Se realiza una llamada recursiva para recorrer todos los nodos del subárbol izquierdo.

**4. Recorrer el subárbol derecho**
```cpp
preOrden(arbol->der);
```

Finalmente, se realiza otra llamada recursiva para recorrer todos los nodos del subárbol derecho.

## 7.1.2. Ejemplo de ejecución
Si utilizamos el árbol anterior, podemos llamar a la función de la siguiente manera:

```cpp
preOrden(arbol);
```

La salida obtenida será:

```text
8 - 3 - 1 - 6 - 4 - 7 - 10 - 14 - 13 -
```

## 7.1.3. Resumen del recorrido en PreOrden
| Paso | Operación                                      |
| ---  | ---                                            |
| 1    | Visitar el nodo raíz.                          |
| 2    | Recorrer recursivamente el subárbol izquierdo. |
| 3    | Recorrer recursivamente el subárbol derecho.   |

**Complejidad temporal:** \(O(n)\), porque cada nodo se visita exactamente una vez.
**Complejidad espacial:** \(O(h)\), debido a las llamadas recursivas, donde `h` representa la altura del árbol.
- Árbol equilibrado: \(O(\log n)\).
- Árbol degenerado: \(O(n)\).

> [!IMPORTANT]
> En un árbol binario de búsqueda, el recorrido en PreOrden no necesariamente muestra los valores ordenados de menor a mayor. Su finalidad es visitar primero cada raíz y después sus subárboles.

---

## 7.2. Recorrido en InOrden (InOrder)
El recorrido en InOrden consiste en visitar los nodos de un árbol binario siguiendo un orden específico:

1. Recorrer el subárbol izquierdo.
2. Visitar la raíz.
3. Recorrer el subárbol derecho.

Su orden de ejecución se representa de la siguiente manera:

\[\boxed{\text{Izquierdo} \rightarrow \text{Raíz} \rightarrow \text{Derecho}}\]

**Ejemplo:**
Consideremos el siguiente árbol binario:
```text
          8
        /   \
       3     10
      / \      \
     1   6      14
        / \    /
       4   7  13
```

Para recorrerlo en InOrden seguimos estos pasos:

1. Recorremos el subárbol izquierdo de la raíz:
   - Visitamos el hijo izquierdo de `3`: `1`.
   - Visitamos el nodo `3`.
   - Recorremos el subárbol derecho de `3`:
     - Visitamos el hijo izquierdo de `6`: `4`.
     - Visitamos el nodo `6`.
     - Visitamos el hijo derecho de `6`: `7`.

2. Visitamos la raíz principal: `8`.

3. Recorremos el subárbol derecho:
   - Visitamos el nodo `10`.
   - Recorremos su hijo derecho: `14`.
   - Visitamos el hijo izquierdo de `14`: `13`.
   - Finalmente, visitamos `14`.

**Secuencia del recorrido:**
```text
1 - 3 - 4 - 6 - 7 - 8 - 10 - 13 - 14
```

## 7.2.1. Definición de la función InOrden
Para implementar este recorrido en C++ utilizamos una función recursiva llamada `inOrden()`.
```cpp
void inOrden(Nodo *arbol) {

    if (arbol == NULL) {
        return;
    }
    else {
        inOrden(arbol->izq);
        cout << arbol->dato << " - ";
        inOrden(arbol->der);
    }
}
```

**Explicación paso a paso:**

**1. Comprobar si el árbol está vacío**
```cpp
if (arbol == NULL) {
    return;
}
```

Se verifica si el puntero recibido es igual a `NULL`.

- Si es `NULL`, significa que no existe ningún nodo que visitar y la función termina.
- Si no es `NULL`, continúa con el recorrido.

**2. Recorrer el subárbol izquierdo**
```cpp
inOrden(arbol->izq);
```

Se realiza una llamada recursiva para visitar todos los nodos del subárbol izquierdo antes de procesar el nodo actual.

**3. Visitar la raíz**
```cpp
cout << arbol->dato << " - ";
```

Se muestra el valor almacenado en el nodo actual después de recorrer su subárbol izquierdo.

**4. Recorrer el subárbol derecho**
```cpp
inOrden(arbol->der);
```

Finalmente, se realiza otra llamada recursiva para recorrer todos los nodos del subárbol derecho.

## 7.2.2. Ejemplo de ejecución
Si utilizamos el árbol anterior, podemos llamar a la función de la siguiente manera:
```cpp
inOrden(arbol);
```

La salida obtenida será:

```text
1 - 3 - 4 - 6 - 7 - 8 - 10 - 13 - 14 -
```

## 7.2.3. Resumen del recorrido en InOrden
| Paso | Operación                                      |
| ---  | ---                                            |  
| 1    | Recorrer recursivamente el subárbol izquierdo. |
| 2    | Visitar el nodo raíz.                          |
| 3    | Recorrer recursivamente el subárbol derecho.   |

**Complejidad temporal:** \(O(n)\), porque cada nodo se visita exactamente una vez.

**Complejidad espacial:** \(O(h)\), debido a las llamadas recursivas, donde `h` representa la altura del árbol.

- Árbol equilibrado: \(O(\log n)\).
- Árbol degenerado: \(O(n)\).

**Importante:** Cuando se aplica el recorrido InOrden a un árbol binario de búsqueda (ABB), los elementos se muestran en orden ascendente, ya que todos los valores del subárbol izquierdo son menores que la raíz y los del subárbol derecho son mayores.

---

## 7.3. Recorrido en PostOrden (PostOrder)
El recorrido en PostOrden consiste en visitar los nodos de un árbol binario siguiendo un orden específico:

1. Recorrer el subárbol izquierdo.
2. Recorrer el subárbol derecho.
3. Visitar la raíz.

Su orden de ejecución se representa de la siguiente manera:

\[\boxed{\text{Izquierdo} \rightarrow \text{Derecho} \rightarrow \text{Raíz}}\]

**Ejemplo:**
Consideremos el siguiente árbol binario:
```text
          8
        /   \
       3     10
      / \      \
     1   6      14
        / \    /
       4   7  13
```

Para recorrerlo en PostOrden seguimos estos pasos:

1. Recorremos el subárbol izquierdo de la raíz:
   - Visitamos el nodo `1`.
   - Recorremos el subárbol de `6`:
     - Visitamos su hijo izquierdo: `4`.
     - Visitamos su hijo derecho: `7`.
     - Visitamos el nodo `6`.
   - Finalmente, visitamos el nodo `3`.

2. Recorremos el subárbol derecho:
   - Visitamos el hijo izquierdo de `14`: `13`.
   - Visitamos el nodo `14`.
   - Visitamos el nodo `10`.

3. Finalmente, visitamos la raíz principal: `8`.

**Secuencia del recorrido:**
```text
1 - 4 - 7 - 6 - 3 - 13 - 14 - 10 - 8
```

## 7.3.1. Definición de la función PostOrden
Para implementar este recorrido en C++ utilizamos una función recursiva llamada `postOrden()`.
```cpp
void postOrden(Nodo *arbol) {

    if (arbol == NULL) {
        return;
    }
    else {
        postOrden(arbol->izq);
        postOrden(arbol->der);
        cout << arbol->dato << " - ";
    }
}
```

**Explicación paso a paso:**

**1. Comprobar si el árbol está vacío**
```cpp
if (arbol == NULL) {
    return;
}
```

Se verifica si el puntero recibido es igual a `NULL`.

- Si es `NULL`, significa que no existe ningún nodo que visitar y la función termina.
- Si no es `NULL`, continúa con el recorrido.

**2. Recorrer el subárbol izquierdo**
```cpp
postOrden(arbol->izq);
```

Se realiza una llamada recursiva para recorrer todos los nodos del subárbol izquierdo.

**3. Recorrer el subárbol derecho**
```cpp
postOrden(arbol->der);
```

Después, se realiza otra llamada recursiva para recorrer todos los nodos del subárbol derecho.

**4. Visitar la raíz**
```cpp
cout << arbol->dato << " - ";
```

Finalmente, se muestra el valor almacenado en el nodo actual, después de haber recorrido sus dos subárboles.

## 7.3.2. Ejemplo de ejecución
Si utilizamos el árbol anterior, podemos llamar a la función de la siguiente manera:
```cpp
postOrden(arbol);
```

La salida obtenida será:

```text
1 - 4 - 7 - 6 - 3 - 13 - 14 - 10 - 8 -
```

## 7.3.3. Resumen del recorrido en PostOrden
| Paso | Operación                                      |
| ---  | ---                                            |
| 1    | Recorrer recursivamente el subárbol izquierdo. |
| 2    | Recorrer recursivamente el subárbol derecho.   |
| 3    | Visitar el nodo raíz.                          |

**Complejidad temporal:** \(O(n)\), porque cada nodo se visita exactamente una vez.

**Complejidad espacial:** \(O(h)\), debido a las llamadas recursivas, donde `h` representa la altura del árbol.

- Árbol equilibrado: \(O(\log n)\).
- Árbol degenerado: \(O(n)\).

**Importante:** En PostOrden, la raíz siempre se procesa después de sus dos subárboles. Este recorrido resulta especialmente útil para eliminar árboles o liberar memoria, ya que permite procesar primero los nodos hijos y después sus respectivos padres.

---

## 7.4. Comparación de los tres recorridos
| Recorrido | Orden              | Secuencia                    |
| ---       | ---                | ---                          |
| PreOrden  | Raíz → Izq. → Der. | 8, 3, 1, 6, 4, 7, 10, 14, 13	|
| InOrden   | Izq. → Raíz → Der. | 1, 3, 4, 6, 7, 8, 10, 13, 14 |
| PostOrden | Izq. → Der. → Raíz | 1, 4, 7, 6, 3, 13, 14, 10, 8 |		

**Truco para recordar los recorridos**
- PreOrden: la raíz va primero.
- InOrden: la raíz va en medio.
- PostOrden: la raíz va al final.

La estructura de las tres funciones es prácticamente idéntica. Lo que cambia es la posición de la instrucción cout respecto a las llamadas recursivas.