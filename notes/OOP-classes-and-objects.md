<h1 align="center">Clases y Objetos en C++ (POO) en C++</h1>

## Contenido
1. [Introducción]()
2. [¿Qué es un objeto?]()
    - [2.1. Ejemplo 1: Un automóvil]()
    - [2.2. Ejemplo 2: Una fracción]()
3. [¿Qué es una clase?]()
    - [3.1. Ejemplo 1: Clase Coche]()
        - [3.1.1. Objetos de la clase Coche]()
        - [3.1.2. Representación de una clase]() 
4. [Implementación de clases y objetos en C++]() 
    - [4.1. Ejemplo: Crear una clase Coche]() 
    - [4.2. Explicación del código]()
5. [Diferencias entre clases y objetos]()

# 1. Introducción
La Programación Orientada a Objetos (POO) es un paradigma de programación que organiza el código mediante clases y objetos. Permite representar elementos del mundo real dentro de un programa, agrupando sus características y comportamientos.

# 2. ¿Qué es un objeto?
En el mundo real, las personas identifican los objetos como cosas que pueden ser percibidas mediante los cinco sentidos. En programación, un objeto es una entidad que representa algo y que posee características específicas y comportamientos propios.

Los objetos tienen dos elementos fundamentales:
- **Atributos (Características):** Son las propiedades que definen el estado de un objeto.
- **Métodos (Acciones):** Son las operaciones o comportamientos que puede realizar un objeto.

## 2.1. Ejemplo 1: Un automóvil
Un automóvil puede representarse mediante un objeto que contiene diferentes atributos y métodos.

**Objeto:** `miCoche1`

**Atributos (Características):**

- `color`: Plateado.
- `marca`: Audi.
- `km`: 0 km.

**Métodos (Acciones):**

- `encender()`
- `acelerar()`
- `frenar()`

## 2.2. Ejemplo 2: Una fracción
Una fracción también puede representarse mediante un objeto.

**Objeto:** `fraccion1`

**Atributos (Características):**

- `numerador`: 3.
- `denominador`: 2.

**Métodos (Acciones):**

- `simplificarse()`
- `sumarseConOtraFraccion()`
- `restarseConOtraFraccion()`

# 3. ¿Qué es una clase?
Una clase es un conjunto de objetos que comparten una estructura y un comportamiento comunes. En otras palabras, una clase funciona como una plantilla o modelo que define los atributos y métodos que tendrán los objetos creados a partir de ella. Por ejemplo, podemos definir una clase llamada `Coche` que establezca las características y acciones que tendrán todos los automóviles representados en nuestro programa.

## 3.1. Ejemplo 1: Clase Coche
La clase `Coche` define los siguientes elementos:

**Atributos (Características):**

- `color`
- `marca`
- `km`

**Métodos (Acciones):**

- `encender()`
- `acelerar()`
- `frenar()`

A partir de esta clase podemos crear diferentes objetos, cada uno con sus propios valores.

## 3.1.1. Objetos de la clase Coche
**Objeto 1: `miCoche1`**

- `color`: Rojo.
- `marca`: Ferrari.
- `km`: 0 km.

**Objeto 2: `miCoche2`**

- `color`: Negro.
- `marca`: Audi.
- `km`: 0 km.

Ambos objetos pertenecen a la misma clase `Coche`, por lo que comparten los mismos atributos y métodos, pero sus valores pueden ser diferentes.

## 3.1.2. Representación de una clase
```text
          CLASE COCHE
    ┌─────────────────────┐
    │       Coche         │
    ├─────────────────────┤
    │ Atributos:          │
    │ - color             │
    │ - marca             │
    │ - km                │
    ├─────────────────────┤
    │ Métodos:            │
    │ - encender()        │
    │ - acelerar()        │
    │ - frenar()          │
    └─────────────────────┘
              |
       ┌──────┴──────┐
       |             |
   miCoche1      miCoche2
       |             |
     Rojo          Negro
    Ferrari        Audi
      0 km          0 km
```

# 4. Implementación de clases y objetos en C++
En C++, utilizamos la palabra reservada `class` para definir una clase.

**Sintaxis básica:**

```cpp
class NombreClase {

    // Atributos

    // Métodos

};
```

Es importante recordar que una definición de clase termina con punto y coma (`;`).

## 4.1. Ejemplo: Crear una clase Coche
```cpp
#include <iostream>
#include <string>
using namespace std;

class Coche {

    public:

        // Atributos
        string color;
        string marca;
        int km;

        // Métodos
        void encender() {
            cout << "El coche esta encendido" << endl;
        }

        void acelerar() {
            cout << "El coche esta acelerando" << endl;
        }

        void frenar() {
            cout << "El coche esta frenando" << endl;
        }

};

int main() {

    // Crear objetos
    Coche miCoche1;
    Coche miCoche2;

    // Asignar valores al primer objeto
    miCoche1.color = "Rojo";
    miCoche1.marca = "Ferrari";
    miCoche1.km = 0;

    // Asignar valores al segundo objeto
    miCoche2.color = "Negro";
    miCoche2.marca = "Audi";
    miCoche2.km = 0;

    // Mostrar información del primer coche
    cout << "Primer coche:" << endl;
    cout << miCoche1.color << endl;
    cout << miCoche1.marca << endl;
    cout << miCoche1.km << " km" << endl;

    // Ejecutar un método
    miCoche1.encender();

    return 0;
}
```

## 4.2. Explicación del código

**1. Definir la clase**

```cpp
class Coche {
```

Se utiliza la palabra reservada `class` para crear una clase llamada `Coche`.

**2. Declarar los atributos**

```cpp
string color;
string marca;
int km;
```

Se definen las características que tendrá cada objeto de la clase.

**3. Declarar los métodos**

```cpp
void encender() {
    cout << "El coche esta encendido" << endl;
}
```

Se define una acción que pueden realizar los objetos de la clase.

**4. Crear objetos**

```cpp
Coche miCoche1;
Coche miCoche2;
```

Se crean dos objetos a partir de la clase `Coche`.

**5. Asignar valores a los atributos**

```cpp
miCoche1.color = "Rojo";
miCoche1.marca = "Ferrari";
miCoche1.km = 0;
```

El operador punto (`.`) permite acceder a los atributos y métodos públicos de un objeto.

Cada objeto puede almacenar valores diferentes, aunque ambos pertenezcan a la misma clase.

**6. Ejecutar métodos**

```cpp
miCoche1.encender();
```

Se utiliza el operador punto para llamar al método `encender()` del objeto `miCoche1`.

# 5. Diferencias entre clases y objetos
| Clases                           | Objetos                                       |
| ---                              | ---                                           |
| Son plantillas o modelos.        | Son instancias de una clase.                  |
| Definen atributos y métodos.     | Tienen valores propios para sus atributos.    |
| Establecen una estructura común. | Utilizan la estructura definida por la clase. |
| Se definen mediante `class`.     | Se crean utilizando el nombre de la clase.    |

**En conclusión:**

Una clase define cómo serán los objetos, mientras que un objeto es una instancia concreta de esa clase.

Por ejemplo, `Coche` es la clase, mientras que `miCoche1` y `miCoche2` son objetos creados a partir de ella.