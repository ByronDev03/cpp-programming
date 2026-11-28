<h1 align="center">Recursividad indirecta</h1>

# Recursividad indirecta – Funciones mutuamente recursivas
La **recursividad indirecta** se produce cuando una función llama a otra, que eventualmente terminará llamando de nuevo a la primera función.

## Ejemplo
Hacer un programa que muestre el alfabeto, carácter a carácter, utilizando recursividad mutua o indirecta.

```cpp
#include <iostream>
using namespace std;

// Prototipos de las funciones
void funcionA(char letra);
void funcionB(char letra);

// Primera función
void funcionA(char letra) {
    if (letra <= 'Z') {
        cout << letra << " ";
        funcionB(letra + 1);
    }
}

// Segunda función
void funcionB(char letra) {
    if (letra <= 'Z') {
        cout << letra << " ";
        funcionA(letra + 1);
    }
}

int main() {
    funcionA('A');

    return 0;
}
```

**Salida esperada**
```text
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
```

## Explicacion paso a paso del código
1. En `main()` se llama a `funcionA('A')`, iniciando el recorrido desde la letra A.
2. `funcionA()` comprueba que la letra no sea posterior a Z, la imprime y llama a `funcionB()` enviándole la siguiente letra.
3. `funcionB()` realiza la misma comprobación, imprime la letra y llama nuevamente a `funcionA()`.
4. Ambas funciones continúan alternándose hasta llegar a Z.
5. Cuando se intenta procesar la siguiente letra ('['), la condición `letra <= 'Z'` deja de cumplirse y termina la recursividad.
