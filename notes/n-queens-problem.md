<h1 align="center">Problema de las N-Reinas</h1>

## Contenido
1. [Planteamiento del problema]()
2. [Restricciones para colocar las reinas]()
3. [Aplicación del algoritmo de vuelta atrás]()
    - [3.1. Vuelta atrás]()
4. [Representación del problema]() 
    - [4.1. Ejemplo de representación]()
5. [Algoritmo para colocar las reinas]()
    - [5.1. Funcionamiento del algoritmo]()
6. [Resumen]()

# 1. Planteamiento del problema
El juego de colocar ocho reinas en un tablero de ajedrez sin que se ataquen entre sí es otro de los ejemplos del uso de los métodos de búsqueda exhaustiva, sistemática, de los algoritmos de vuelta atrás. El problema se plantea de la forma siguiente:

> [!NOTE]
> Dado un tablero de ajedrez (8 × 8 casillas), hay que situar ocho reinas de forma que ninguna de ellas pueda actuar ("comer") a cualquiera de las otras.

# 2. Restricciones para colocar las reinas
En primer lugar, conviene recordar que la reina puede moverse a lo largo de la columna, fila y diagonales donde se encuentra. Sin embargo, es posible realizar una poda y reducir los movimientos de las reinas en el problema.

Cada columna del tablero puede contener una y sólo una reina, la razón es inmediata: si por ejemplo en una columna se encuentra ya una reina y en esta columna se agrega otra reina entonces se atacan mutuamente.

Entonces, de las \(n \times n\) casillas que puede ocupar una reina, se limita su ubicación a las 8 casillas de la columna en que se encuentra.

# 3. Aplicación del algoritmo de vuelta atrás
Lo primero a considerar a la hora de aplicar el algoritmo de *vuelta atrás* es la tarea básica (solución parcial) que exhaustivamente se va a realizar.

La propia naturaleza del problema de las 8 reinas determina que la tarea sea tantear si es posible ubicar la reina número `i`, para lo que hay 8 alternativas correspondientes a las 8 filas de la columna `i`.

La comprobación de que una selección es válida se hace comprobando que en la fila seleccionada y en las dos diagonales en que una reina puede atacar, no haya otra reina colocada anteriormente.

## 3.1. Vuelta atrás
La segunda cuestión es analizar la vuelta atrás. ¿Qué ocurre si no se es capaz de colocar las 8 reinas?

Se borra la ubicación, la fila donde se ha colocado, y se ensaya con la siguiente fila válida. La realización de cada tarea supone ampliar el número de reinas colocadas, hasta llegar a la solución completa, o bien determinar que no es posible colocar la reina actual en las 8 posibles filas.

Entonces, en la vuelta atrás se coloca la reina actual en otra fila válida para realizar un nuevo tanteo.

## 4. Representación del problema
Debido a que el objetivo del problema es encontrar la fila en que se sitúa la reina de la columna `i`, se define el arreglo entero `reinas[]`, tal que cada elemento contiene el índice de fila donde se sitúa la reina.

El número de reina, `i`, es a su vez el índice de columna dentro de la cual se puede colocar entre los ocho posibles valores de fila.

## 4.1. Ejemplo de representación
El arreglo puede representar una solución de la siguiente manera:

```cpp
reinas[] = {0, 4, 7, 5, 2, 6, 1, 3};
```

Cada posición del arreglo representa una columna y su valor indica la fila donde se encuentra la reina.

| Columna (`i`) | Fila (`reinas[i]`) |
| :---:         | :---:              |
| 0             | 0                  |
| 1             | 4                  |
| 2             | 7                  |
| 3             | 5                  |
| 4             | 2                  |
| 5             | 6                  |
| 6             | 1                  |
| 7             | 3                  |

# 5. Algoritmo para colocar las reinas
La función `ponerReina()` intenta colocar una reina en la columna indicada por `i`, probando las diferentes filas disponibles.

```cpp
void ponerReina(int i, bool &solucion) {
    int k = 0; // Inicializa contador de movimientos
    solucion = false;

    do {
        reinas[i] = k; // Coloca y anota reina i en la fila k
        k++;

        mostrarTablero();
        cout << endl;

        if (valido(i)) {
            if (i < (N - 1)) {
                ponerReina(i + 1, solucion);

                // Vuelta atrás
                if (!solucion) {
                    reinas[i] = 0;
                }
            }
            else { // Todas las reinas colocadas
                solucion = true;
            }
        }

    } while (!solucion && (k < N));
}
```

## 5.1. Funcionamiento del algoritmo
1. Se inicializa el contador `k` en cero y la variable `solucion` en `false`.
2. Se coloca la reina `i` en la fila `k`.
3. Se muestra el tablero con la ubicación actual de las reinas.
4. Se comprueba mediante `valido(i)` si la posición seleccionada es válida.
5. Si la posición es válida y todavía faltan reinas por colocar, se llama recursivamente a `ponerReina(i + 1, solucion)`.
6. Si no se consigue una solución, se aplica la vuelta atrás y se elimina la ubicación de la reina actual.
7. Si todas las reinas se han colocado correctamente, `solucion` toma el valor `true`.
8. El proceso continúa mientras no se encuentre una solución y todavía existan filas por probar.

# 6. Resumen
El problema de las N-Reinas consiste en colocar ocho reinas en un tablero de ajedrez de 8 × 8, de manera que ninguna pueda atacar a otra. Para resolverlo se utiliza el algoritmo de vuelta atrás (*Backtracking*), que intenta colocar una reina en cada columna, probando las diferentes filas disponibles.

La solución se representa mediante el arreglo `reinas[]`, donde cada índice indica una columna y su valor representa la fila en la que se encuentra la reina. Antes de avanzar, el algoritmo verifica que la posición seleccionada sea válida, comprobando que no existan otras reinas en la misma fila o diagonal.

Si no es posible completar la colocación, se aplica la vuelta atrás: se elimina la posición actual y se prueba con otra fila. El proceso continúa hasta encontrar una distribución válida de las ocho reinas o agotar las alternativas disponibles.