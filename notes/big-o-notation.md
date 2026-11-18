<h1 align="center">Notación O-Grande (Big O)</h1>

## Contenido
1. [Notación O-Grande]()
   - [1.1. Importancia de la notación O-Grande]()
   - [1.2. Factor de eficiencia]()
   - [1.3. Definición de la notación O]()
   - [1.4. Cómo determinar la notación O]()
   - [1.5. Ejemplos de cálculo]()
   - [1.6. Resumen]()

# 1. Notación O-Grande
La alta velocidad de las computadoras actuales hace que la medida exacta de la eficiencia de un algoritmo no sea una preocupación vital en el diseño, pero sí lo es el orden general de magnitud de la misma. Si el análisis de dos algoritmos muestra que uno ejecuta 25 iteraciones mientras que otro ejecuta 40, la práctica muestra que ambos son muy rápidos. Entonces, ¿cómo valorar las diferencias? Ahora bien, si un algoritmo realiza 25 iteraciones y otro 25 000 iteraciones, entonces debemos estar preocupados por la rapidez o la lentitud de uno y otro.

## 1.1. Importancia de la notación O-Grande
Anteriormente, se ha expresado mediante la fórmula `f(n)` el número de sentencias ejecutadas para `n` datos. El factor dominante que se debe considerar para determinar el orden de magnitud de la fórmula es el denominado **factor de eficiencia**. Por consiguiente, no se necesita determinar la medida completa de la eficiencia; basta con calcular el factor que determina la magnitud. Este factor se define como **O-Grande**, que representa «está en el orden de» y se expresa como: \[O(n)\] Es decir, «en el orden de n».

## 1.2. Factor de eficiencia
El factor de eficiencia permite identificar el término dominante de una función de ejecución. En lugar de considerar todos los términos de una función, se identifica aquel que tiene mayor influencia en el crecimiento del tiempo de ejecución conforme aumenta el tamaño de la entrada.

## 1.3. Definición de la notación O
La **notación O** indica la cota superior del tiempo de ejecución de un algoritmo o programa. Así, en lugar de decir que un algoritmo emplea un tiempo de `4n - 1` en procesar un arreglo de longitud `n`, se dirá que emplea un tiempo: \[O(n)\] Se lee «O grande de n» u «O de n». Informalmente, esto significa que el tiempo de ejecución está limitado por una constante multiplicada por `n`, para valores suficientemente grandes de entrada.

## 1.4. Cómo determinar la notación O
La notación O-Grande se puede obtener a partir de `f(n)` utilizando los siguientes pasos:

1. En cada término, establecer el coeficiente del término en 1.
2. Mantener el término mayor de la función y descartar los restantes. Los términos se ordenan de menor a mayor.

**Jerarquía de crecimiento de las funciones:**

De menor a mayor crecimiento:

\[\log_2 n\]

\[n\]

\[n\log_2 n\]

\[n^2\]

\[n^3\]

\[\cdots\]

\[n^k\]

\[2^n\]

\[n!\]

Esta jerarquía permite comparar el crecimiento de distintas funciones de eficiencia.

## 1.5. Ejemplos de cálculo
**Ejemplo 1.**
Calcular la función O-Grande de la siguiente función de eficiencia:

\[f(n)=\frac{n(n+1)}{2}\]

**Paso 1. Desarrollar la expresión:**
\[f(n)=\frac{n^2+n}{2}\]

**Paso 2. Separar los términos:**
\[f(n)=\frac{n^2}{2}+\frac{n}{2}\]

**Paso 3. Establecer los coeficientes en 1:**
\[f(n)=n^2+n\]

**Paso 4. Conservar el término de mayor crecimiento:**
\[f(n)=n^2\]

La notación O correspondiente es:

\[\boxed{O(f(n))=O(n^2)}\]

**Ejemplo 2.**
Calcular la función O-Grande de la siguiente función de eficiencia:

\[f(n)=a_jn^k+a_{j-1}n^{k-1}+a_{j-2}n^{k-2}+\cdots+a_2n^2+a_1n+a_0\]

**Paso 1. Establecer los coeficientes en 1:**
\[f(n)=n^k+n^{k-1}+n^{k-2}+\cdots+n^2+n+1\]

**Paso 2. Conservar el término de mayor crecimiento:**
\[f(n)=n^k\]

La notación O correspondiente es:

\[\boxed{O(f(n))=O(n^k)}\]

## 1.6. Resumen
La **notación O-Grande (Big O)** permite expresar el orden de crecimiento del tiempo de ejecución de un algoritmo en función del tamaño de su entrada.

En lugar de analizar todos los términos de una función de eficiencia, se identifica el término dominante, es decir, aquel que determina su crecimiento para valores grandes de `n`.

Para calcular la notación O se siguen dos pasos principales:

1. Establecer los coeficientes de los términos en 1.
2. Conservar únicamente el término de mayor crecimiento y descartar los demás.

Algunos órdenes de crecimiento importantes son:

- \(O(\log n)\): logarítmico.
- \(O(n)\): lineal.
- \(O(n\log n)\): lineal logarítmico.
- \(O(n^2)\): cuadrático.
- \(O(n^3)\): cúbico.
- \(O(n^k)\): polinómico.
- \(O(2^n)\): exponencial.
- \(O(n!)\): factorial.

La notación O-Grande facilita la comparación de algoritmos y permite identificar cuáles mantienen un mejor rendimiento cuando aumenta la cantidad de datos que deben procesar.