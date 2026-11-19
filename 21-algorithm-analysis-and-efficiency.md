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

##### 1. Determinar la complejidad de la función:
```cpp
double mayor(double x, double y) {
    if (x > y) {
        return x;
    }
    else {
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

##### 2. Determinar la complejidad de la siguiente función
```cpp
void mostrarArreglo(double x[], int n) {
    int j;

    for (j = 0; j < n; j++) {
        cout << x[j] << endl;
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

##### 3. 

<details>
<summary>Solución</summary>

</details>


<details>
<summary>Solución</summary>

</details>