<h1 align="center">Iteradores (Iterators)</h1>

## Contenido
1. [Concepto de iteradores]()
2. [Representación de un iterador]()  
3. [Sintaxis de los iteradores]() 
4. [Clasificación de los iteradores]()
    - [4.1. Operaciones según el tipo de iterador]()

# 1. Concepto de iteradores
Entender el concepto de **iterador** es la clave para comprender enteramente la estructura de la STL y hacer una mejor utilización de ella. Los algoritmos genéricos de esta biblioteca están escritos en términos de iteradores como parámetros y los contenedores proveen iteradores para que sean utilizados por los algoritmos. Estos componentes genéricos están diseñados para trabajar en conjunto y así producir un resultado óptimo.

Un **iterador** es un objeto que abstrae el proceso de moverse a través de una secuencia. El mismo permite seleccionar cada elemento de un contenedor encapsulando la estructura interna de ese contenedor. Esto permite crear algoritmos genéricos que funcionen con cualquier contenedor, utilizando operaciones comunes como `++`, `--` o `*`.

# 2. Representación de un iterador
Un iterador permite señalar una posición específica dentro de un contenedor.

**Ejemplo de representación:**

```text
...  ┌────┬────┬────┬────┬────┬────┐  ...
     │ 20 │ 48 │ 17 │  5 │ 36 │ 12 │
     └────┴────┴────┴────┴────┴────┘
                    ↑
                    p
```

En este ejemplo, el iterador `p` señala el elemento `17` dentro de la secuencia.

# 3. Sintaxis de los iteradores
Ya hemos visto el empleo de iteradores con el contenedor `list`. La sintaxis general para crear un objeto iterador es la siguiente:

```cpp
X::iterator instancia;
deque<double>::iterator p;
```

Donde:

- `X`: representa el tipo de contenedor.
- `iterator`: indica el tipo de iterador.
- `instancia` o `p`: es el nombre del iterador.

# 4. Clasificación de los iteradores
Los algoritmos genéricos se construyen empleando iteradores que realizan distintas operaciones con ellos. Sin embargo, no todos los iteradores pueden soportar todas las operaciones posibles. Entonces, la clasificación que surge aquí es por la forma en que un iterador puede moverse a través de un contenedor:

| Tipo de iterador            | Descripción                                                    |
| :---                        | :---                                                           |
| **Forward iterators**       | Iteradores que pueden avanzar al elemento siguiente.           |
| **Bidirectional iterators** | Pueden avanzar al elemento siguiente o retroceder al anterior. |
| **Random access iterators** | Pueden avanzar o retroceder más de una posición de un vez.     |

## 4.1. Operaciones según el tipo de iterador
La siguiente representación muestra las operaciones que puede realizar cada categoría:

| Operaciones           | Forward | Bidirectional | Random Access |
| :---                  | :---:   | :---:         | :---:         |
| `==`, `!=`, `*`, `++` | ✓       | ✓            | ✓             |
| `--`                  | —       | ✓            | ✓             |
| `+=`, `-=`, `+`, `-`  | —       | —            | ✓             |
| `<`, `>`, `<=`, `>=`  | —       | —            | ✓             |