<h1 align="center">Contenedores (Containers)</h1>

## Contenido
1. [Concepto de contenedores]()
2. [Clasificación de los contenedores]() 
    - [2.1. Lineales]()
    - [2.2. Asociativos]() 
3. [Operaciones comunes]() 
    - [3.1. Operaciones disponibles]()
    - [3.2. Operaciones de comparación]()

# 1. Concepto de contenedores
Son una colección de las estructuras de datos más populares utilizadas habitualmente. Un contenedor es justamente eso: un lugar en donde contener o agrupar objetos del mismo tipo La diferencia entre un contenedor y otro está en la forma en que los objetos son alojados, en cómo se crea la secuencia de elementos y la manera en que los podrá acceder a cada uno de ellos. Éstos pueden estar almacenados en forma contigua en la memoria o enlazados a través de punteros. Esto hace que las estructuras difieran también en la forma en que se accede a los elementos, la velocidad con la cual se insertan o se eliminan estos y en la eficiencia de los algoritmos que se apliquen a ellas. Como se verá luego, cada una de las diferentes estructuras de datos que implementan los contenedores tiene un propósito particular. Estos diferentes diseños de almacenamiento de datos tienen ventajas y desventajas, lo cual produce que algunos contenedores sean más adecuados que otros para la resolución de un problema en particular.

# 2. Clasificación de los contenedores
Los contenedores se clasifican en dos categorías principales:

## 2.1. Lineales
Los contenedores lineales almacenan sus elementos en una secuencia ordenada, donde cada elemento ocupa una posición dentro del contenedor. Se diferencian principalmente en la forma en que organizan sus elementos en memoria y en las operaciones de acceso, inserción y eliminación que permiten.
- **List:** Las listas son los contenedores adecuados cuando se requieren operaciones de inserción o eliminación en cualquier parte de la lista. Están implementadas como listas doblemente enlazadas, esto es, cada elemento (nodo) contiene las direcciones del nodo siguiente y del anterior, además del valor específico almacenado.
    ***Representación de una lista doblemente enlazada:***
    ```text
    NULL ← [20] ⇄ [34] ⇄ [7] ⇄ [46] → NULL
    ```
    La ventaja de esta implementación es que la inserción o eliminación de un elemento se reduce a ordenar los punteros del siguiente y anterior de cada nodo. Pero la desventaja es que ya no se puede tener acceso aleatorio a los elementos, sino que se tiene un acceso secuencial en forma bidireccional. Es decir, se puede recorrer el contenedor desde el principio hasta el final o viceversa.

    Para poder recorrer listas es necesario utilizar **iteradores**. Como ya dijimos, los iteradores son objetos similares a los punteros, que indican una posición dentro de un contenedor. Todos los contenedores proporcionan dos iteradores que establecen el rango del recorrido: `begin` y `end`.

    **Representación del rango de recorrido:**
    - `begin`: indica la posición del primer elemento del contenedor.
    - `end`: indica la posición siguiente al último elemento del contenedor.
    ---
- **Vector:** Representa al arreglo clásico de elementos, en donde todos los elementos contenidos están contiguos en la memoria. Esta característica permite mayor velocidad de acceso a los elementos debido a que para acceder a cualquiera de ellos, sólo se debe calcular la posición relativa al primer elemento.

    ***Ejemplo de representación:***
    ```text
    Índice:    0   1   2   3    4
             ┌───┬───┬───┬───┬────┐
    Vector:  │ 7 │ 9 │ 1 │ 5 │ 10 │ ...
             └───┴───┴───┴───┴────┘
    ```
    ---
- **Deque (Doble Cola):** Esta es una estructura de datos que representa a una cola con doble final. Este contenedor es similar a `vector` ya que sus elementos también están   contiguos en memoria. La diferencia principal radica en que al tener doble final se pueden insertar elementos por ambos extremos del contenedor.

    ***Ejemplo de representación:***
    ```text
    ...  ┌───┬───┬───┬───┬────┐  ...
         │ 7 │ 9 │ 1 │ 5 │ 10 │
         └───┴───┴───┴───┴────┘
           0   1   2   3    4
    ```

## 2.2. Asociativos
Los contenedores asociativos permiten almacenar y organizar elementos mediante claves, facilitando las operaciones de búsqueda, inserción y eliminación. A diferencia de los contenedores lineales, se implementan mediante árboles binarios de búsqueda balanceados, lo que permite realizar búsquedas de manera eficiente.
- **Map:** Almacena elementos en pares de clave y valor. Cada clave es única y permite acceder al valor asociado.
  **Ejemplo:** Un directorio telefónico donde cada nombre funciona como clave y su número telefónico como valor.
  ```cpp
  map<string, string> telefonos;

  telefonos["Ana"] = "5551234567";
  telefonos["Luis"] = "5559876543";
  ```
  ---
- **Set:** Almacena elementos únicos y ordenados. No permite duplicados y cada elemento funciona como su propia clave.
  **Ejemplo:** Un conjunto de números donde no se pueden repetir los valores.
  ```cpp
  set<int> numeros;

  numeros.insert(10);
  numeros.insert(5);
  numeros.insert(10);
  // Resultado: {5, 10}
  ```
  ---
- **Multimap:** Almacena elementos en pares de clave y valor, permitiendo que una misma clave esté asociada a varios valores.
  **Ejemplo:** Una lista de estudiantes agrupados por carrera, donde varios estudiantes pueden pertenecer a la misma carrera.
  ```cpp
  multimap<string, string> estudiantes;

  estudiantes.insert({"Informatica", "Ana"});
  estudiantes.insert({"Informatica", "Luis"});
  estudiantes.insert({"Derecho", "Carlos"});
  ```
  ---
- **Multiset:** Almacena elementos ordenados y permite que un mismo valor aparezca varias veces dentro del contenedor.
  **Ejemplo:** Una colección de calificaciones donde varios estudiantes pueden obtener la misma nota.
  ```cpp
  multiset<int> calificaciones;

  calificaciones.insert(9);
  calificaciones.insert(8);
  calificaciones.insert(9);
  // Resultado: {8, 9, 9}
  ```

# 3. Operaciones comunes
Antes de realizar cualquier operación con un contenedor hay que crearlo. La sintaxis utilizada para ello es la siguiente:

```cpp
X<T> instancia;
vector<int> valores;
```

Donde:
- `X`: representa el tipo de contenedor.
- `T`: representa el tipo de dato que almacenará.
- `instancia`: es el nombre del contenedor.

## 3.1. Operaciones disponibles
| Operación       | Descripción                                                                               |
| :---            | :---                                                                                      |
| `X::size()`     | Devuelve la cantidad de elementos que tiene el contenedor.                                |
| `X::max_size()` | Devuelve el tamaño máximo que puede alcanzar el contenedor antes de requerir más memoria. |
| `X::empty()`    | Retorna verdadero si el contenedor no tiene elementos.                                    |
| `X::swap(T &a)` | Intercambia el contenido del contenedor con el que se recibe como parámetro.              |
| `X::clear()`    | Elimina todos los elementos del contenedor.                                               |

## 3.2. Operaciones de comparación
Supóngase que existen dos contenedores del mismo tipo: `v` y `w`. Todas las comparaciones se hacen lexicográficamente y retornan un valor booleano.

| Operadores |
| :---       |
| `v == w`   |
| `v != w`   |
| `v < w`    |
| `v > w`    |
| `v <= w`   |
| `v >= w`   |