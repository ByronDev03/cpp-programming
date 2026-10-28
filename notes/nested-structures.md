<h1 align="center">Estructuras anidadas en C++ </h1>

### ¿Qué es una estructura anidada?
Una **estructura anidada** es una estructura definida dentro de otra estructura. Permite agrupar información relacionada y organizar datos complejos en campos más específicos.

### Ejemplo de una estructura anidada
Supongamos que se desea almacenar la información de un empleado, incluyendo su nombre, dirección, ciudad, provincia y salario.

Primero, se define una estructura llamada `info_direccion` para almacenar los datos de la dirección:

```cpp
struct info_direccion {
    char direccion[30];
    char ciudad[20];
    char provincia[20];
};
```

Posteriormente, se define la estructura `empleado`, que contiene los datos del empleado e incorpora una variable de tipo `info_direccion`:

```cpp
struct empleado {
    char nombre[20];
    struct info_direccion dir_empleado;
    double salario;
};
```

En este ejemplo, la estructura `empleado` contiene tres campos:

| Campo          | Tipo de dato            | Descripción                                    |
| ---            | ---                     | ---                                            |
| `nombre`       | `char[20]`              | Almacena el nombre del empleado.               |
| `dir_empleado` | `struct info_direccion` | Agrupa los datos de la dirección del empleado. |
| `salario`      | `double`                | Almacena el salario del empleado.              |

A su vez, el campo `dir_empleado` contiene los siguientes datos:

- `direccion`: dirección del empleado.
- `ciudad`: ciudad donde reside.
- `provincia`: provincia correspondiente.

### Representación de la estructura

La organización de los campos puede representarse de la siguiente manera:

```text
empleado
├── nombre
├── dir_empleado
│   ├── direccion
│   ├── ciudad
│   └── provincia
└── salario
```

Esta representación muestra que `dir_empleado` agrupa tres campos dentro de la estructura principal `empleado`.

### Acceso a los campos de una estructura anidada
Para acceder a los campos de una estructura anidada, se utiliza el operador punto (`.`) de manera consecutiva.

Por ejemplo, si declaramos una variable de tipo `empleado`:

```cpp
struct empleado trabajador;
```

Podemos acceder a sus campos de la siguiente manera:

```cpp
trabajador.nombre;
trabajador.dir_empleado.direccion;
trabajador.dir_empleado.ciudad;
trabajador.dir_empleado.provincia;
trabajador.salario;
```

Observa que para acceder a `ciudad`, primero se indica la variable `trabajador`, después el campo `dir_empleado` y finalmente el campo `ciudad`.

**En resumen:** las estructuras anidadas permiten organizar información relacionada en diferentes niveles, facilitando la representación y administración de datos complejos.