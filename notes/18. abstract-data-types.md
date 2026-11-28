<h1 align="center">Tipos Abstractos de Datos en C++ (TAD)</h1>

## Contenido
1. [¿Qué es un TAD?]()
2. [Implementación de un TAD en C++]() 
    - [2.1. Ejemplo: TAD PuntoTres]()
    - [2.2. Elementos de la clase]() 
3. [Resumen]()

# 1. ¿Qué es un TAD?
Un **Tipo Abstracto de Datos (TAD)** es un conjunto de valores y de operaciones definidos mediante una especificación independiente de cualquier representación.

En otras palabras, un TAD define qué valores se pueden manejar y qué operaciones se pueden realizar sobre ellos, sin depender de cómo están implementados internamente.

\[\text{TAD} = \text{valores} + \text{operaciones}\]

# 2. Implementación de un TAD en C++
La estructura más adecuada en C++ para implementar un TAD es la **clase**. Dentro de la clase va a residir la representación de los valores (**atributos**) junto con las operaciones (**métodos**).

## 2.1. Ejemplo: TAD PuntoTres
Por ejemplo, si se ha especificado el TAD `PuntoTres` para representar la abstracción punto en el espacio tridimensional, la clase que implementa el tipo sería:

```cpp
class PuntoTres {
private:
    double x, y, z; // Representación de los valores

public:
    PuntoTres(double x, double y, double z); // Operaciones
    double distancia(PuntoTres p);

    ...
};
```

## 2.2. Elementos de la clase
- **Atributos (`private`):** representan los valores que forman parte del TAD. En este ejemplo, las coordenadas `x`, `y` y `z`.
- **Métodos (`public`):** representan las operaciones que se pueden realizar sobre los valores. En este ejemplo, el constructor `PuntoTres()` y el método `distancia()`.

De esta manera, la clase encapsula los datos y las operaciones que conforman el Tipo Abstracto de Datos.

# 3. Resumen
Un **Tipo Abstracto de Datos (TAD)** define un conjunto de valores y las operaciones que se pueden realizar sobre ellos, independientemente de su representación interna. En C++, los TAD se implementan mediante **clases**, que permiten encapsular los datos mediante atributos y definir sus operaciones mediante métodos. Esta organización facilita la abstracción y mantiene separados los detalles internos de implementación de las operaciones disponibles.