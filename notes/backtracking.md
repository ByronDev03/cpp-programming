<h1 align="center">Backtracking (Algoritmos de vuelta atrás)</h1>

## Contenido
1. [Concepto de Backtracking]()
2. [Funcionamiento mediante un laberinto]() 
    - [2.1. Proceso de búsqueda]()
3. [Características y aplicaciones]() 
    - [3.1. Ejemplos de aplicación]()

# 1. Concepto de Backtracking
Se trata de una estrategia normalmente recursiva para resolver problemas como los de los laberintos, la colocación de piezas y similares, en los que mediante una **búsqueda en profundidad** se puede dar con la solución.

El nombre vuelta atrás (*backtracking*) viene del hecho de que en la búsqueda de la solución se va **volviendo a un punto anterior para probar alternativas**.

# 2. Funcionamiento mediante un laberinto
Imaginemos un laberinto: al llegar a una encrucijada (1, 2, 3) se prueba con una dirección. Si con eso se llega a la solución, problema resuelto. Si no, se vuelve atrás a la encrucijada anterior y se prueba con otra, repitiendo el proceso cuantas veces sea necesario.

Si se agotan todas las opciones y no se ha llegado, es que no existe solución: *no hay salida*.

## 2.1. Proceso de búsqueda
El proceso puede describirse de la siguiente manera:

1. Se comienza desde la entrada del laberinto.
2. Al llegar a una encrucijada, se selecciona una dirección para continuar.
3. Si el camino conduce a la salida, se ha encontrado la solución.
4. Si el camino no conduce a la solución, se regresa a la encrucijada anterior.
5. Se prueba una alternativa diferente.
6. Se repite el proceso hasta encontrar la salida o agotar todas las opciones.

# 3. Características y aplicaciones
Normalmente las combinaciones de este tipo de problemas son muchas, pero se aplican ciertas restricciones, lo que suele hacer el total de opciones a probar algo computable en un tiempo razonable.

También se puede buscar revisar todas planteando obtener «una solución mejor»; de este modo se puede llegar a la **solución óptima**.

## 3.1. Ejemplos de aplicación
Algunos ejemplos típicos en los que se puede aplicar este método son:

- **Laberintos:** encontrar un camino desde la entrada hasta la salida.
- **Sudoku:** completar el tablero respetando las reglas del juego.
- **Ajedrez:**
  - Problema del recorrido del caballo.
  - Problema de las ocho damas.
- **Problema de la mochila:** seleccionar elementos para obtener una solución óptima respetando determinadas restricciones.

