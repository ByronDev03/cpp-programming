<h1 align="center">Algoritmos (Algorithms)</h1>

## Contenido
1. [Concepto de algoritmos]()
2. [Estructura general]()  
    - [2.1. Ejemplo utilizando un contenedor Vector]() 
    - [2.2. Ejemplo utilizando iteradores]()

# 1. Concepto de algoritmos
Como se mencionó anteriormente, existe una gran cantidad de algoritmos disponibles en la STL que pueden ser utilizados con los contenedores e iteradores que se explicaron hasta aquí. Hay algoritmos de ordenamiento, búsqueda, mezcla, matemáticos, etc. Estos algoritmos no son otra cosa que funciones template que operan sobre los contenedores a través de los iteradores de éstos.

# 2. Estructura general
Para describir la estructura general que poseen los algoritmos de la biblioteca se utilizará un ejemplo.

## 2.1. Ejemplo utilizando un contenedor Vector
```cpp
template <class T>
T max(vector<T> &v) {
    // Crear una variable para devolver el máximo
    T maximo = v[0];

    // Buscar el máximo
    for (int i = 1; i < v.size(); i++) {
        if (maximo < v[i]) {
            maximo = v[i];
        }
    }

    return maximo;
}
```

En este ejemplo se define una función template que recibe un vector y devuelve el elemento máximo que contiene.

## 2.2. Ejemplo utilizando iteradores

```cpp
#include <iostream>
using namespace std;

// Crear un algoritmo genérico para encontrar el máximo
template<class Iter>
Iter max(Iter inicio, Iter fin) {
    // Crear una variable para devolver el máximo
    Iter maximo = inicio;
    Iter aux = inicio;

    // Buscar el máximo
    while (aux != fin) {
        if ((*maximo) < (*aux)) {
            maximo = aux;
        }
        aux++;
    }

    return maximo;
}
```

En este segundo ejemplo, el algoritmo recibe dos iteradores que representan el inicio y el final del rango que se desea recorrer. Mediante ellos se busca el elemento máximo de la secuencia.