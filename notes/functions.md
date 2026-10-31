<h1 align="center">Funciones en C++</h1>

## ¿Qué es?
Una función realiza una tarea concreta y puede ser diseñada, implementada y depurada de manera independiente al resto del código. Las funciones permiten dividir un programa en partes más pequeñas y organizadas, facilitando su comprensión, mantenimiento y reutilización.

## Definición de funciones
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

## Ejemplos de funciones
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

## Estructura básica de un programa en C++
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

## Partes de la estructura
1. **Directivas del preprocesador:** instrucciones que se procesan antes de la compilación. Por ejemplo, `#include` permite incorporar bibliotecas.
2.  **Prototipos de función:** indican al compilador el nombre, el tipo de retorno y los parámetros de las funciones antes de que sean utilizadas.
3.  **Función principal `main()`:** es el punto de entrada del programa. Aquí se ejecutan las instrucciones principales y se pueden llamar otras funciones.
4.  **Definiciones de función:** contienen el código o conjunto de instrucciones que realiza cada función.

## Ejemplo de prototipo y definición

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
