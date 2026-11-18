<h1 align="center">Eficiencia de Bucles</h1>

## Contenido
1. [Eficiencia de bucles]()
   - [1.1. Función de eficiencia]()
   - [1.2. Bucles lineales]()
   - [1.3. Bucles algorítmicos]()
   - [1.4. Bucles anidados]()
   - [1.5. Resumen]()

# 1. Eficiencia de bucles
En general, el formato de la eficiencia se puede expresar mediante una función:

\[f(n) = \text{eficiencia}\]

Es decir, la eficiencia del algoritmo se examina como una función del número de elementos a ser procesados.

## 1.1. Función de eficiencia
En los bucles se repiten las sentencias del cuerpo del bucle un número determinado de veces, lo que determina la eficiencia del mismo.

Normalmente, en los algoritmos los bucles son el término dominante en cuanto a la eficiencia, debido a que las instrucciones que contienen se ejecutan repetidamente.

## 1.2. Bucles lineales
Los bucles lineales son aquellos en los que el número de iteraciones es directamente proporcional al tamaño de la entrada `n`.

**Ejemplo 1. ¿Cuántas veces se repite el cuerpo del bucle en el siguiente código?**
```cpp
i = 1;

while (i <= n) {
    // Código de la aplicación
    i = i + 1;
}
```

En cada iteración, el contador `i` aumenta una unidad.

Por ejemplo, si `n` es un entero de valor 100, el cuerpo del bucle se ejecutará 100 veces.

El número de iteraciones es directamente proporcional al factor del bucle `n`. Por lo tanto, la función que expresa la eficiencia es:

\[f(n) = n\]

**Ejemplo 2. ¿Cuántas veces se repite el cuerpo del bucle en el siguiente código?**
```cpp
i = 1;

while (i <= n) {
    // Código de la aplicación
    i = i + 2;
}
```

En este caso, el contador `i` avanza de 2 en 2, por lo que el número de iteraciones es aproximadamente `n/2`.

La función que expresa la eficiencia es:

\[f(n) = \frac{n}{2}\]

## 1.3. Bucles algorítmicos
Consideremos un bucle en el que su variable de control se multiplique o divida dentro de dicho bucle.

¿Cuántas veces se repetirá el cuerpo del bucle?

**Ejemplo 1. Bucle de multiplicar**
```cpp
i = 1;

while (i < 1000) {
    // Código de la aplicación
    i = i * 2;
}
```

**Ejemplo 2. Bucle de dividir**
```cpp
i = 1000;

while (i >= 1) {
    // Código de la aplicación
    i = i / 2;
}
```

En ambos bucles se ejecutan 10 iteraciones. La razón es que en cada iteración el valor de `i` se dobla en el bucle de multiplicar y se divide por la mitad en el bucle de división.

Por consiguiente, el número de iteraciones es una función del multiplicador o divisor, en este caso 2.

**Tabla de iteraciones:**

| Iteración | Bucle de multiplicar (`i`) | Iteración | Bucle de dividir (`i`) |
| ---:      | ---:                       | ---:      | ---:                   |
| 1         | 1                          | 1         | 1000                   |
| 2         | 2                          | 2         | 500                    |
| 3         | 4                          | 3         | 250                    |
| 4         | 8                          | 4         | 125                    |
| 5         | 16                         | 5         | 62                     |
| 6         | 32                         | 6         | 31                     |
| 7         | 64                         | 7         | 15                     |
| 8         | 128                        | 8         | 7                      |
| 9         | 256                        | 9         | 3                      |
| 10        | 512                        | 10        | 1                      |
| Salida    | 1024                       | Salida    | 0                      |

El análisis de ambos bucles se puede expresar de la siguiente manera:

**Bucle de multiplicar:**

\[2^{\text{iteraciones}} < 1000\]

**Bucle de dividir:**

\[\frac{1000}{2^{\text{iteraciones}}} < 1\]

Generalizando, el análisis permite decir que las iteraciones de los bucles especificados se determinan mediante la siguiente fórmula:

\[f(n) = \log_2 n\]

## 1.4. Bucles anidados
El total de iteraciones de bucles anidados (bucles que contienen a otros bucles) se determina multiplicando el número de iteraciones del bucle interno por el número de iteraciones del bucle externo.

\[\text{Iteraciones} = \text{Iteraciones del bucle externo} \times \text{Iteraciones del bucle interno}\]

Existen tres tipos de bucles anidados: **lineal logarítmico, cuadráticos dependientes y cuadráticos**, que con análisis similares a los anteriores nos conducen a las siguientes ecuaciones de eficiencia:

| Tipo de bucle anidado  | Función de eficiencia       |
| ---                    | ---                         |
| Lineal logarítmica     | \(f(n) = n\log_2 n\)        |
| Dependiente cuadrática | \(f(n) = \frac{n(n+1)}{2}\) |
| Cuadrática             | \(f(n) = n^2\)              |

## 1.5. Resumen
La **eficiencia de los bucles** se determina principalmente por la cantidad de veces que se ejecuta el cuerpo del bucle en función del tamaño de la entrada `n`.

Los principales tipos estudiados son:

- **Bucles lineales:** el número de iteraciones crece proporcionalmente a `n`. Sus ejemplos presentan funciones como \(f(n)=n\) y \(f(n)=n/2\).
- **Bucles algorítmicos:** la variable de control se multiplica o divide en cada iteración. Su función de eficiencia es \(f(n)=\log_2 n\).
- **Bucles anidados:** contienen uno o más bucles dentro de otros. Su número total de iteraciones se obtiene multiplicando las iteraciones de los bucles involucrados.

Las funciones de eficiencia permiten identificar cómo aumenta el trabajo de un algoritmo conforme crece el tamaño de los datos que procesa.