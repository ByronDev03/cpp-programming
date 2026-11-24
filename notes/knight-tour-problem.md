<h1 align="center">Problema del Salto del Caballo</h1>

## Contenido
1. [Planteamiento del problema]()
2. [Movimientos posibles del caballo]()
3. [Condiciones para realizar un movimiento]()
4. [Aplicación del algoritmo de vuelta atrás]()
5. [Algoritmo recursivo]() 
    - [5.1. Funcionamiento del algoritmo]()

# 1. Planteamiento del problema
En un tablero de ajedrez de `n x n` casillas, se tiene un caballo situado en la posición inicial de coordenadas \((x_0,y_0)\). El problema consiste en encontrar, si existe, un camino que permita al caballo pasar exactamente una vez por cada una de las casillas del tablero, teniendo en cuenta los movimientos (saltos) permitidos a un caballo de ajedrez.

Este es un ejemplo clásico de problema que se resuelve con el esquema del algoritmo de vuelta atrás. El problema consiste en buscar la secuencia de saltos que tiene que dar el caballo, partiendo de una casilla cualquiera, para pasar por cada una de las casillas del tablero.

Se da por supuesto que el tablero está vacío, no hay figuras excepto el caballo.

Lo primero que hay que tener en cuenta es que el caballo, desde una casilla, puede realizar hasta 8 movimientos.

# 2. Movimientos posibles del caballo
Los ocho posibles movimientos de caballo se obtienen sumando a la posición actual de éste, \((x,y)\), unos desplazamientos relativos.

Los desplazamientos posibles son:

\[d = \{(2,1), (1,2), (-1,2), (-2,1),\]

\[(-2,-1), (-1,-2), (1,-2), (2,-1)\}\]

Por ejemplo, suponiendo que el caballo se encuentra en la casilla `(3,5)`, los posibles movimientos que puede realizar son:

```text
{(5,6), (4,7), (2,7), (1,6),
 (1,4), (2,3), (4,3), (5,4)}
```

# 3. Condiciones para realizar un movimiento
No siempre será posible realizar los ocho movimientos, se debe comprobar que la casilla destino esté dentro del tablero y también que no haya pasado previamente el caballo por esa casilla.

En caso de ser posible el movimiento se anota, guardando el número del salto realizado.

La condición que determina que el problema se ha resuelto está ligada con el objetivo que se persigue, y en este problema es que se haya pasado por las \(n^2\) casillas, en definitiva que el caballo haya realizado:

\[n^2 - 1\]

saltos.

Para un tablero de 8 × 8:

\[8^2 - 1 = 64 - 1 = 63 \text{ saltos}\]

# 4. Aplicación del algoritmo de vuelta atrás
¿Qué ocurre si se agotan los ocho posibles movimientos sin alcanzar la solución?

Se vuelve al movimiento anterior, aplicando la técnica de **vuelta atrás**, y se borra la anotación para ensayar con el siguiente movimiento.

El procedimiento consiste en:

1. Obtener los ocho movimientos posibles desde la posición actual.
2. Comprobar que las nuevas coordenadas estén dentro del tablero.
3. Verificar que la casilla de destino no haya sido visitada anteriormente.
4. Si el movimiento es válido, anotarlo en el tablero.
5. Continuar recursivamente desde la nueva posición.
6. Si no se alcanza la solución, borrar la anotación y probar el siguiente movimiento.

# 5. Algoritmo recursivo
La función `saltoCaballo()` intenta realizar los movimientos posibles del caballo hasta encontrar una solución o agotar las alternativas disponibles.

```cpp
void saltoCaballo(int i, int x, int y, bool &exito) {
    int nx, ny;
    int k = 0; // Inicializa contador de posibles 8 movimientos
    exito = false;

    do {
        k++;

        nx = x + d[k-1][0];
        ny = y + d[k-1][1];

        // Determina si nuevas coordenadas son aceptables
        if ((nx >= 0) && (nx < N) &&
            (ny >= 0) && (ny < N) &&
            (tablero[nx][ny] == 0)) {

            // Anota movimiento
            tablero[nx][ny] = i;
            escribeTablero(); // Función para mostrar el tablero (matriz)

            if (i < N*N) {
                saltoCaballo(i+1, nx, ny, exito);

                if (!exito) {
                    tablero[nx][ny] = 0;
                    // No se alcanzó la solución, se borra anotación
                }
            }
            else {
                exito = true; // Caballo ha cubierto el tablero
            }
        }

    } while ((k < 8) && (!exito));
}
```

## 5.1. Funcionamiento del algoritmo
- **Inicialización:** se declaran las nuevas coordenadas `nx`, `ny`, se inicializa el contador `k` y se establece `exito` en `false`.
- **Cálculo del movimiento:** se obtienen las nuevas coordenadas sumando los desplazamientos relativos a la posición actual.
- **Validación:** se comprueba que las coordenadas estén dentro del tablero y que la casilla no haya sido visitada (`tablero[nx][ny] == 0`).
- **Registro:** si el movimiento es válido, se anota el número del salto en el tablero.
- **Recursividad:** si todavía faltan casillas por recorrer, se llama nuevamente a `saltoCaballo()` desde la nueva posición.
- **Vuelta atrás:** si la llamada recursiva no encuentra una solución, se borra la anotación y se prueba otro movimiento.
- **Finalización:** cuando se han recorrido todas las casillas, la variable `exito` cambia a `true`.