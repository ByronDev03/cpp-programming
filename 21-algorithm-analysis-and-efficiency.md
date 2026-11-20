<h1 align="center">21. Análisis y Eficiencia de Algoritmos</h1>








## Objetivos
Con el estudio de este capitulo 
- Revisar los conceptos básicos de tipos de datos.
- Introducirse en las ideas fundamentales de estructuras de datos.
- Revisar el concepto de algoritmo y programa. 
- Entender los conceptos análisis, verificación y eficiencia de un algoritmo.
- Conocer las propiedades matemáticas de la notación O.
- Conocer la complejidad de las sentencias básicas de todo programa C++.

## Apuntes
- **Algoritmos y Programas** → [Ver apunte](/notes/algorithms-and-programs.md) 
- **Eficiencia y Exactitud** → [Ver apunte](/notes/efficiency-and-correctness.md)
- **Eficiencia de Bucles** → [Ver apunte](/notes/loop-efficiency.md)
- **Notación O-Grande** → [Ver apunte](/notes/big-o-notation.md)
- **Propiedades de la notación O** → [Ver apunte](/notes/properties-of-big-o-notation.md)
- **Complejidad de las sentencias básicas de C++** → [Ver apunte](/notes/basic-cpp-statements-complexity.md)

## Ejercicios

##### Determinar la complejidad de la siguiente función: 1. Función mayor
```cpp
double mayor(double x, double y) {
    if (x > y) { //O(1)
        return x;
    }
    else { //O(1)
        return y;
    }
}
```

<details>
<summary>Solución</summary>

**Paso 1. Identificar las instrucciones.**

La función contiene:

- Una comparación: `x > y`.
- Una instrucción `return x`.
- Una instrucción `return y`.

Cada una tiene complejidad constante O(1).

**Paso 2. Analizar la estructura condicional.**

La estructura `if/else` ejecuta solamente uno de los dos bloques, dependiendo de la condición.

Por lo tanto, se considera la complejidad máxima entre ambos bloques:

\[T(n)=\max(O(1),O(1))\]

**Paso 3. Simplificar.**

\[T(n)=O(1)\]

**Resultado final:**

\[\boxed{O(1)}\]

**Interpretación:** La función tiene complejidad constante porque realiza una cantidad fija de operaciones, independientemente de los valores recibidos.
</details>

##### 2. Mostrar arreglo
```cpp
void mostrarArreglo(double x[], int n) {
    int j;

    for (j = 0; j < n; j++) { //O(n)
        cout << x[j] << endl; //O(1)
    }
}
```

<details>
<summary>Solución</summary>

**Paso 1. Identificar las instrucciones.**

- Declaración de la variable `j`: O(1).
- Inicialización `j = 0`: O(1).
- Comparación `j < n`: se evalúa en cada iteración.
- Incremento `j++`: O(1) por iteración.
- Instrucción `cout`: O(1) por iteración.

**Paso 2. Determinar el número de iteraciones.**

El ciclo comienza con `j = 0` y termina cuando `j` alcanza `n`.

Por lo tanto, el cuerpo del ciclo se ejecuta `n` veces.

**Paso 3. Calcular la complejidad del ciclo.**

Cada iteración realiza operaciones de costo constante:

\[T(n)=n\cdot O(1)\]

**Paso 4. Simplificar.**

\[T(n)=O(n)\]

**Resultado final:**

\[\boxed{O(n)}\]

**Interpretación:** La complejidad es lineal porque el tiempo de ejecución aumenta proporcionalmente al número de elementos del arreglo.
</details>

##### 3. Suma con bucle logarítmico
```cpp
double suma(double d[], int n) {
    int k = 0, s = 0; //O(1)

    while (k < n) { //O(log2n)
        s += d[k];  //O(1)

        if (k == 0) { //O(1)
            k = 2;
        }
        else { //O(1)
            k *= 2;
        }
    }

    return s;
}
```

<details>
<summary>Solución</summary>

**Paso 1. Identificar las instrucciones.**

- Inicialización de `k` y `s`: O(1).
- Condición del `while`: O(1) por evaluación.
- Suma `s += d[k]`: O(1).
- Condición `if (k == 0)`: O(1).
- Asignación `k = 2`: O(1).
- Multiplicación `k *= 2`: O(1).
- Retorno `return s`: O(1).

**Paso 2. Analizar el comportamiento de la variable `k`.**

La variable `k` comienza en cero. En la primera iteración se establece en 2. Después, se multiplica por 2 en cada iteración.

Su comportamiento es:

| Iteración | Valor de `k` |
| ---:      |---:          |
| 1         | 0            |
| 2         | 2            |
| 3         | 4            |
| 4         | 8            |
| 5         | 16           |
| 6         | 32           |
| ...       | ...          |
| Última | Menor que `n`   |

**Paso 3. Determinar el número de iteraciones.**

Después de la primera iteración, los valores de `k` siguen una progresión geométrica:

\[k=2,4,8,16,\ldots\]

En cada iteración se duplica el valor anterior.

Para determinar cuántas veces se puede multiplicar por 2 antes de alcanzar `n`, se plantea:

\[2^i \geq n\]

Aplicando logaritmos:

\[i\geq \log_2 n\]

Por lo tanto, el número de iteraciones es de orden logarítmico.

**Paso 4. Calcular la complejidad del ciclo.**

El cuerpo del ciclo tiene complejidad constante:

\[T(n)=O(\log_2 n)\cdot O(1)\]

**Paso 5. Simplificar.**

\[T(n)=O(\log_2 n)\]

**Resultado final:**

\[\boxed{O(\log n)}\]

**Interpretación:** La función tiene complejidad logarítmica porque el valor de `k` se duplica en cada iteración, haciendo que el número de repeticiones crezca lentamente conforme aumenta `n`.

</details>

##### 4. Transpuesta de una matriz
```cpp
void traspuesta(float d[][M], int n) {
    int i, j;

    for (i = n - 2; i > 0; i--) { //O(n)
        for (j = i + 1; j < n; j++) { //O(n)
            float t;

            t = d[j][i]; //O(1)
            d[j][i] = d[i][j]; //O(1)
            d[i][j] = t; //O(1)
        }
    }
}
```

<details>
<summary>Solución</summary>

**Paso 1. Identificar las estructuras de control.**

La función contiene dos ciclos `for` anidados:

- Un ciclo externo controlado por `i`.
- Un ciclo interno controlado por `j`.

Dentro del ciclo interno se realizan operaciones de intercambio de elementos de la matriz.

**Paso 2. Determinar las iteraciones del ciclo externo.**

El ciclo externo comienza en `i = n - 2` y termina cuando `i` deja de ser mayor que cero.

Por lo tanto, se ejecuta aproximadamente `n` veces.

Su complejidad es:

\[O(n)\]

**Paso 3. Determinar las iteraciones del ciclo interno.**

El ciclo interno comienza en `j = i + 1` y termina cuando `j` alcanza `n`.

Para cada iteración del ciclo externo, el número de iteraciones internas depende del valor de `i`.

Su complejidad máxima es:

\[O(n)\]

**Paso 4. Analizar las operaciones internas.**

Dentro del ciclo interno se realizan las siguientes instrucciones:

```cpp
float t;

t = d[j][i];
d[j][i] = d[i][j];
d[i][j] = t;
```

Estas instrucciones tienen complejidad constante:

\[O(1)\]

**Paso 5. Calcular la complejidad total.**

Se multiplican las complejidades de los ciclos anidados y las operaciones internas:

\[T(n)=O(n)\cdot O(n)\cdot O(1)\]

**Paso 6. Simplificar.**

\[T(n)=O(n^2)\]

**Resultado final:**

\[\boxed{O(n^2)}\]

**Interpretación:** La función tiene complejidad cuadrática porque contiene dos ciclos anidados. A medida que aumenta el tamaño de la matriz, el número de operaciones crece aproximadamente con el cuadrado de `n`.

</details>

## Resumen de complejidades
| Ejercicio | Función            | Complejidad                                         | Tipo        |
| ---       | ---                | ---                                                 | ---         |
| 1         | `mayor()`          | O(1) + O(1) = O(1)                                  | Constante   |
| 2         | `mostrarArreglo()` | O(n) * O(1) = O(n)                                  | Lineal      |
| 3         | `suma()`           | O(1) + \(O(\log_{2} n)\) * O(1) = \(O(\log_{2} n)\) | Logarítmica |
| 4         | `traspuesta()`     | O(n) * O(n) * O(1) = O(n²)                          | Cuadrática  |