<h1 align="center">Funciones en C++</h1>

## Contenido
1. [¿Qué es?]()
    - [1.1. Definición de funciones]()
    - [1.2. Ejemplos de funciones]()
    - [1.3. Estructura básica de un programa en C++]()
    - [1.4. Partes de la estructura]()
    - [1.5. Ejemplo de prototipo y definición]()
    - [1.6. Resumen]()

# 1. ¿Qué es?
Una función realiza una tarea concreta y puede ser diseñada, implementada y depurada de manera independiente al resto del código. Las funciones permiten dividir un programa en partes más pequeñas y organizadas, facilitando su comprensión, mantenimiento y reutilización.

## 1.1. Definición de funciones
La sintaxis básica para la definición de una función en C++ es la siguiente:
``` cpp
tipo nombre(tipo var1, tipo var2, ..., tipo varn) {
    // Conjunto de instrucciones
}
```

**Elementos de la sintaxis:**
- `tipo`: indica el tipo de dato que devuelve la función. Si no devuelve ningún valor, se utiliza `void`.
- `nombre`: es el identificador de la función.
- `tipo var1, tipo var2, ...`: son los parámetros que recibe la función. Cada parámetro tiene un tipo de dato y un nombre.
- **Conjunto de instrucciones:** contiene las operaciones que ejecutará la función.
- `return`: permite devolver un resultado cuando la función tiene un tipo de retorno distinto de `void`.

## 1.2. Ejemplos de funciones
Algunos ejemplos de declaraciones de funciones en C++ son:

``` cpp
int numMax(int x, int y);

double intercambio(double x, double y);

void desplegar(float x, float y);
```

En estos ejemplos:

- `numMax` recibe dos valores enteros y devuelve un entero.
- `intercambio` recibe dos valores de tipo `double` y devuelve un valor de ese mismo tipo.
- `desplegar` recibe dos valores de tipo `float` y no devuelve ningúnvalor, ya que su tipo de retorno es `void`.

> [!NOTE]
> En la tercera función se interpreta que el segundo parámetro es `y`. En la imagen aparece repetida la variable `x`; se ha corregido para que el ejemplo tenga dos parámetros con nombres distintos.

## 1.3. Estructura básica de un programa en C++
Como una cuestión de buena forma de programación, el siguiente ordenamiento de instrucciones deberá formar la estructura básica alrededor de la cual se construyan los programas en C++.

``` cpp
// Directivas del preprocesador
#include <iostream>

// Prototipos de función
int numMax(int x, int y);
double intercambio(double x, double y);
void desplegar(float x, float y);

int main() {
    // Conjunto de instrucciones

    return 0;
}

// Definiciones de función
```

## 1.4. Partes de la estructura
1. **Directivas del preprocesador:** instrucciones que se procesan antes de la compilación. Por ejemplo, `#include` permite incorporar bibliotecas.
2.  **Prototipos de función:** indican al compilador el nombre, el tipo de retorno y los parámetros de las funciones antes de que sean utilizadas.
3.  **Función principal `main()`:** es el punto de entrada del programa. Aquí se ejecutan las instrucciones principales y se pueden llamar otras funciones.
4.  **Definiciones de función:** contienen el código o conjunto de instrucciones que realiza cada función.

## 1.5. Ejemplo de prototipo y definición
``` cpp
#include <iostream>
using namespace std;

// Prototipo de la función
int numMax(int x, int y);

int main() {
    int resultado = numMax(10, 20);

    cout << "El numero mayor es: " << resultado << endl;

    return 0;
}

// Definición de la función
int numMax(int x, int y) {
    if (x > y) {
        return x;
    }

    return y;
}
```

En este ejemplo, el prototipo permite que `main()` conozca la función `numMax` antes de su definición. La definición contiene las instrucciones que comparan los dos números y devuelven el mayor.

## 1.6. Resumen
Las **funciones en C++** permiten dividir un programa en partes más pequeñas e independientes, cada una encargada de realizar una tarea específica. Esto facilita la organización, comprensión, mantenimiento y reutilización del código.

Una función se compone de un tipo de retorno, un nombre, parámetros y un conjunto de instrucciones. Además, puede devolver un resultado mediante la instrucción `return` o no devolver ningún valor utilizando `void`.

Para trabajar con funciones se utilizan dos elementos importantes:

- **Prototipo:** declara la función e informa al compilador sobre su nombre, tipo de retorno y parámetros antes de utilizarla.
- **Definición:** contiene las instrucciones que ejecutará la función.

La estructura básica de un programa en C++ incluye las directivas del preprocesador, los prototipos de funciones, la función principal `main()` y las definiciones de las funciones.

En conclusión, las funciones permiten desarrollar programas más organizados, modulares y fáciles de mantener, ya que cada tarea puede implementarse y probarse de manera independiente.