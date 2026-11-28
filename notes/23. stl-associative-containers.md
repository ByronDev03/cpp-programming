<h1 align="center">Contenedores Asociativos (Associative Containers)</h1>

## Contenido
1. [Clasificación de los contenedores]()
2. [Contenedores asociativos]()  
    - [2.1. Ejemplo de estructura]() 
3. [Operaciones de los contenedores asociativos]()

# 1. Clasificación de los contenedores
Los contenedores de la STL se clasifican en dos categorías principales:

- **Lineales:**
  - `List`
  - `Vector`
  - `Deque`

- **Asociativos:**
  - `Map`
  - `Set`
  - `Multimap`
  - `Multiset`

# 2. Contenedores asociativos
Hasta este momento se explicó la estructura general de la STL con los contenedores lineales, los iteradores y los algoritmos. Con esta idea general, se retoma la descripción de los contenedores faltantes, los asociativos. Estos contenedores son: `set`, `multiset`, `map` y `multimap`.

Su estructura en memoria no es secuencial como en los contenedores anteriores, sino que se implementan como árboles binarios de búsqueda balanceados. Esto hace que el tiempo de búsqueda sea proporcional al logaritmo en base dos de la cantidad de elementos, en vez de ser proporcional al tamaño del contenedor, como es el caso de las listas lineales.

## 2.1. Ejemplo de estructura
Un árbol binario de búsqueda balanceado puede representarse de la siguiente manera:

```text
             12
           /    \
          8      23
         / \    /  \
        4  10  15  26
```

Los contenedores asociativos proveen para su manipulación iteradores bidireccionales, al igual que las listas doblemente enlazadas. Por lo tanto, sólo se podrán utilizar aquellos algoritmos que requieran de estos iteradores.

Sin embargo, estos contenedores proveen algunos métodos para las funciones de búsqueda y conteo, los cuales se explican a continuación.

# 3. Operaciones de los contenedores asociativos
En las siguientes operaciones, `A` representa el tipo de contenedor asociativo.

| Operación                                 | Descripción                                                                     |
| :---                                      | :---                                                                            | 
| `A::insert(clave &x)`                     | Inserta el elemento `x` en el contenedor.                                       |
| `A::insert(A::iterator i, A::iterator f)` | Inserta los elementos que están en el rango de los iteradores en el contenedor. |
| `A::erase(clave &x)`                      | Borra todos los elementos que tengan la clave `x`.                              |
| `A::erase(A::iterator p)`                 | Borra el elemento apuntado por `p`.                                             |
| `A::count(clave &x)`                      | Devuelve la cantidad de elementos que tiene la clave `x`.                       |
| `A::find(clave &x)`                       | Devuelve un iterador al primer elemento que tenga la clave `x`.                 |
| `A::lower_bound(clave &x)`                | Devuelve un iterador al primer elemento que tenga la clave `x`.                 |
| `A::upper_bound(clave &x)`                | Devuelve un iterador al elemento siguiente al último elemento con clave `x`.    |