<h1 align="center">Genericidad - Plantillas (templates)</h1>

## Contenido
1. [Genericidad]()
2. [Plantillas de Funciones]()
3. [Plantillas de Clases]()
   - [3.1. Declaración de una plantilla de clase]()
4. [Resumen]()

# 1. Genericidad
La **genericidad** es una propiedad que permite definir una clase (o una función) sin especificar el tipo de datos de uno o más de sus miembros (parámetros). De esta forma se puede cambiar la clase para adaptarla a los diferentes usos sin tener que reescribirla.

La razón de la genericidad se basa principalmente en el hecho de que los algoritmos de resolución de numerosos problemas no dependen del tipo de datos que procesa, y sin embargo, cuando se implementan en un lenguaje de programación, los programas que resuelven cada algoritmo serán diferentes para cada tipo de dato que procesan.

# 2. Plantillas de Funciones
Una *plantilla de función* es un modelo de función que el compilador de C++ usará para construir diferentes versiones de una misma función, según los tipos de datos que se especifiquen al invocar a la misma. La plantilla permite escribir funciones que difieren exclusivamente en el tipo de datos que manejan.

Para definir una plantilla de función se aplica la siguiente sintaxis:

**Utilizando `class`:**

```cpp
template <class T1, class T2, ..., class Tn>
```

**Utilizando `typename`:**

```cpp
template <typename T1, typename T2, ..., typename Tn>
```

# 3. Plantillas de Clases
Las *plantillas de clases* permiten definir versiones de una misma clase que difieren en el tipo de dato de alguno(s) de sus miembros. Es decir, se crea el modelo de una clase el cual permitirá definir distintas instancias de la misma para diferentes tipos de datos.

## 3.1. Declaración de una plantilla de clase
Para declarar una plantilla de clase se utiliza lo siguiente:

```cpp
template <class T>
class PlantillaClase {
    private:
        T atributo;
        ...

    public:
        PlantillaClase();
        T Metodo1();
        void Metodo2(T valor);
        ...
};
```

# 4. Resumen
La **genericidad** permite crear funciones y clases sin especificar previamente los tipos de datos que utilizarán. Esto facilita la reutilización del código y evita tener que reescribir implementaciones para diferentes tipos de datos.

En C++, la genericidad se implementa mediante **plantillas (*templates*)**, que se dividen principalmente en dos tipos:

- **Plantillas de funciones:** permiten crear diferentes versiones de una misma función según los tipos de datos utilizados al invocarla. Se pueden declarar utilizando `class` o `typename`.
- **Plantillas de clases:** permiten crear distintas versiones de una misma clase para trabajar con diferentes tipos de datos. Se utiliza `template <class T>` para declarar el tipo genérico.

En conclusión, las plantillas permiten desarrollar código más flexible y reutilizable, ya que una misma función o clase puede trabajar con distintos tipos de datos sin necesidad de duplicar su implementación.