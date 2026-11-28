<h1 align="center">Torres de Hanói (Recursividad)</h1>

## Contenido
1. [Descripción del problema]()
2. [Reglas del juego]()
3. [Ejemplo de solución]()
4. [Algoritmo recursivo]()
    - [4.1. Implementación en C++]()
    - [4.2. Número de movimientos]()
5. [Resumen]()

# 1. Descripción del problema
Este juego (un algoritmo clásico) tiene sus orígenes en la cultura oriental y en una leyenda sobre el Templo de Brahma, cuya estructura simulaba una plataforma metálica con tres varillas y discos en su interior.

El problema en cuestión suponía la existencia de tres varillas (**A, B y C**) o postes en los que se alojaban discos (\(n\) discos) que se podían trasladar de una varilla a otra libremente, pero con una condición: cada disco era ligeramente inferior en diámetro al que estaba justo debajo de él.

# 2. Reglas del juego
El objetivo es mover todos los discos desde la varilla inicial (**A**) hasta la varilla final (**C**), utilizando la varilla central (**B**) como auxiliar.

Se deben respetar las siguientes condiciones:

- Solo se puede mover un disco a la vez.
- Únicamente se puede mover el disco que se encuentra en la parte superior de una varilla.
- Nunca se puede colocar un disco más grande sobre uno más pequeño.

# 3. Ejemplo de solución
Para comprender el funcionamiento, se muestra el movimiento de tres discos desde la varilla **A** hacia la varilla **C**.

**Estado inicial:**

```text
    A          B          C
    1
   2
  3
─────────  ─────────  ─────────
```

**Secuencia de movimientos:**

| Movimiento | Varilla A | Varilla B | Varilla C |
| ---        | ---       | --        | ---       |
| Inicial    | 1, 2, 3   | Vacía     | Vacía     |
| 1          | 1, 2      | 3         | Vacía     |
| 2          | 3         | 2         | 1         |
| 3          | 3         | Vacía     | 1, 2      |
| 4          | Vacía     | 1, 2, 3   | Vacía     |
| 5          | 1         | 2, 3      | Vacía     |
| 6          | Vacía     | 2, 3      | 1         |
| 7          | Vacía     | Vacía     | 1, 2, 3   |

**Resultado final:** todos los discos se encuentran en la varilla C, conservando el orden de mayor a menor.

# 4. Algoritmo recursivo
El algoritmo recursivo para resolver las Torres de Hanói utiliza tres varillas:

- `varInicial`: varilla de origen.
- `varCentral`: varilla auxiliar.
- `varFinal`: varilla de destino.

El algoritmo contempla dos casos:

- **Caso base:** cuando existe un solo disco (`n == 1`), se mueve directamente desde la varilla inicial hasta la varilla final.
- **Caso recursivo:** cuando hay más de un disco, se realizan los siguientes pasos:
  1. Mover los primeros `n - 1` discos desde la varilla inicial hasta la varilla central, utilizando la varilla final como auxiliar.
  2. Mover el disco más grande desde la varilla inicial hasta la varilla final.
  3. Mover los `n - 1` discos desde la varilla central hasta la varilla final, utilizando la varilla inicial como auxiliar.

## 4.1. Implementación en C++

```cpp
void hanoi(char varInicial, char varCentral, char varFinal, int n) {
    if (n == 1) { // Caso Base
        cout << "Mover disco " << n << " desde varilla "
             << varInicial << " a varilla " << varFinal << endl;
    }
    else { // Caso Recursivo
        hanoi(varInicial, varFinal, varCentral, n - 1);

        cout << "Mover disco " << n << " desde varilla "
             << varInicial << " a varilla " << varFinal << endl;

        hanoi(varCentral, varInicial, varFinal, n - 1);
    }
}
```

## 4.2. Número de movimientos
Para resolver las Torres de Hanói con \(n\) discos, el número mínimo de movimientos necesarios es:

\[M(n) = 2^n - 1\]

Por ejemplo, para 3 discos:

\[M(3) = 2^3 - 1 = 7\]

# 5. Resumen
El problema de las Torres de Hanói consiste en trasladar un conjunto de discos desde una varilla inicial hasta una varilla final, utilizando una tercera varilla como auxiliar y respetando las reglas de movimiento: trasladar un solo disco a la vez, mover únicamente el disco superior y nunca colocar un disco más grande sobre uno más pequeño.

Para resolverlo se utiliza un algoritmo recursivo que contempla dos casos:

- **Caso base:** cuando existe un solo disco, se mueve directamente desde la varilla inicial hasta la varilla final.
- **Caso recursivo:** cuando hay más de un disco, se trasladan primero los \(n-1\) discos a la varilla auxiliar, después se mueve el disco más grande al destino y, finalmente, se trasladan los \(n-1\) discos restantes a la varilla final.

El número mínimo de movimientos necesarios para resolver el problema con \(n\) discos se calcula mediante la fórmula \(M(n) = 2^n - 1\). Por lo tanto, la cantidad de movimientos aumenta exponencialmente conforme se incrementa el número de discos.