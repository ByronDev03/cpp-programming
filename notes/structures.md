<h1 align="center">Estructuras en C++ </h1>

## ¿Qué es una estructura?
Una estructura es una colección de uno o más elementos denominados **campos**, cada uno de los cuales puede ser de un tipo de dato diferente.

Las estructuras permiten agrupar datos relacionados bajo un mismo nombre, aunque sus tipos sean distintos.

## Ejemplo de una estructura
Supongamos que se desea almacenar los datos de una colección de discos compactos (CD) de música. Estos datos pueden ser:

- Título
- Artista
- Número de canciones
- Precio
- Fecha de compra

Para almacenar esta información, podemos definir una estructura llamada `coleccion_CD`:

```cpp
struct coleccion_CD {
    char titulo[30];
    char artista[25];
    int numCanciones;
    float precio;
    char fecha_compra[20];
};
```

En este ejemplo, la estructura contiene cinco campos:

| Campo          | Tipo de dato | Descripción                             |
| ---            | ---          | ---                                     |
| `titulo`       | `char[30]`   | Almacena el título del CD.              |
| `artista`      | `char[25]`   | Almacena el nombre del artista.         |
| `numCanciones` | `int`        | Almacena el número de canciones.        |
| `precio`       | `float`      | Almacena el precio del CD.              |
| `fecha_compra` | `char[20]`   | Almacena la fecha de compra como texto. |

## Declaración de una estructura
La sintaxis general para declarar una estructura en C++ es la siguiente:

```cpp
struct <nombreDeLaEstructura> {
    <tipoDeDato> <nombreDeCampo>;
    <tipoDeDato> <nombreDeCampo>;
    <tipoDeDato> <nombreDeCampo>;
    // ...
    <tipoDeDato> <nombreDeCampo>;
};
```

- `struct`: palabra reservada que permite definir una estructura.
- `<nombreDeLaEstructura>`: nombre que identifica la estructura.
- `<tipoDeDato>`: tipo de dato de cada campo, como `int`, `float` o `char`.
- `<nombreDeCampo>`: nombre de la variable que pertenece a la estructura.
- `;`: indica el final de la declaración.

### Ejemplo

```cpp
struct coleccion_CD {
    char titulo[30];
    char artista[25];
    int numCanciones;
    float precio;
    char fecha_compra[20];
};
```

**Importante:** la declaración de la estructura define un nuevo tipo de dato, pero por sí sola no crea variables individuales de ese tipo.

## Declarando variables de tipo `struct`
Una vez definida la estructura, podemos declarar variables que utilicen ese tipo.

### Declaración dentro de `main()`

```cpp
struct coleccion_CD {
    char titulo[30];
    char artista[25];
    int numCanciones;
    float precio;
    char fecha_compra[20];
};

int main() {
    struct coleccion_CD CD1, CD2, CD3;
}
```

En este caso, se declaran tres variables de tipo `coleccion_CD`:

- `CD1`
- `CD2`
- `CD3`

Cada variable dispone de sus propios campos para almacenar los datos de un CD.

### Declaración al finalizar la estructura
También es posible declarar las variables inmediatamente después de cerrar la definición de la estructura:

```cpp
struct coleccion_CD {
    char titulo[30];
    char artista[25];
    int numCanciones;
    float precio;
    char fecha_compra[20];
} CD1, CD2, CD3;
```

En este caso, `CD1`, `CD2` y `CD3` se declaran al mismo tiempo que se define la estructura.

Ambas formas permiten crear variables que almacenan los campos definidos en `coleccion_CD`.