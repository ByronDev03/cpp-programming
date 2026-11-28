<h1 align="center">Propiedades de la Notación O</h1>

## Contenido
1. [Propiedades de la notación O]()
   - [1.1. Multiplicación por una constante]()
   - [1.2. Suma de funciones]()
   - [1.3. Máximo de funciones]()
   - [1.4. Producto de funciones]()
   - [1.5. Logaritmos de diferentes bases]()
   - [1.6. Logaritmo de un factorial]()
   - [1.7. Sumatoria de potencias]()
   - [1.8. Sumatoria de logaritmos]()
   - [1.9. Resumen]()

# 1. Propiedades de la notación O
De la definición conceptual de la notación O se deducen las siguientes propiedades:

## 1.1. Multiplicación por una constante
Siendo `c` una constante:

\[c \cdot O(f(n)) = O(f(n))\]

**Ejemplo:**

Si:

\[f(n)=3n^4\]

Entonces:

\[3 \cdot O(n^4)=O(n^4)\]

La multiplicación por una constante no modifica el orden de crecimiento de la función.

## 1.2. Suma de funciones
La suma de dos funciones expresadas en notación O se puede representar como:

\[O(f(n))+O(g(n))=O(f(n)+g(n))\]

**Ejemplo:**

Si:

\[f(n)=2e^n\]

Y:

\[g(n)=2n^3\]

Entonces:

\[O(f(n))+O(g(n))\]

\[=O(f(n)+g(n))\]

\[=O(2e^n+2n^3)\]

Por lo tanto:

\[\boxed{O(e^n)}\]

Se conserva el término de mayor crecimiento.

## 1.3. Máximo de funciones
La propiedad del máximo se expresa de la siguiente manera:

\[\max(O(f(n)),O(g(n)))=O(\max(f(n),g(n)))\]

**Ejemplo:**

\[\max(O(\log n),O(n))\]

\[=O(\max(\log n,n))\]

Por lo tanto:

\[\boxed{O(n)}\]

Esto se debe a que la función lineal crece más rápido que la función logarítmica.

## 1.4. Producto de funciones
El producto de dos funciones expresadas en notación O se representa como:

\[O(f(n))\cdot O(g(n))=O(f(n)\cdot g(n))\]

**Ejemplo:**
Si:

\[f(n)=2n^3\]

Y:

\[g(n)=n\]

Entonces:

\[O(f(n))\cdot O(g(n))\]

\[=O(f(n)\cdot g(n))\]

\[=O(2n^3\cdot n)\]

Por lo tanto:

\[\boxed{O(n^4)}\]

## 1.5. Logaritmos de diferentes bases
Los logaritmos de diferentes bases tienen el mismo orden de crecimiento, siempre que sus bases sean mayores que 1.

\[O(\log_a n)=O(\log_b n)\]

Para:

\[a,b>1\]

Las funciones logarítmicas son de orden logarítmico, independientemente de la base del logaritmo.

## 1.6. Logaritmo de un factorial
El logaritmo de un factorial se puede expresar mediante la siguiente propiedad:

\[\boxed{O(\log(n!))=O(n\log n)}\]

Esta propiedad permite simplificar expresiones que contienen el logaritmo de un factorial.

## 1.7. Sumatoria de potencias
Para `k > 1`, la sumatoria de potencias se expresa como:

\[O\left(\sum_{i=1}^{n}i^k\right)=O(n^{k+1})\]

Esta propiedad permite determinar el orden de crecimiento de una sumatoria cuyos términos son potencias de `i`.

## 1.8. Sumatoria de logaritmos
La sumatoria de logaritmos se expresa mediante la siguiente propiedad:

\[O\left(\sum_{i=1}^{n}\log i\right)=O(n\log n)\]

Esta propiedad permite simplificar expresiones en las que se acumulan términos logarítmicos.

## 1.9. Resumen
Las **propiedades de la notación O** permiten simplificar expresiones matemáticas y determinar el orden de crecimiento de las funciones de eficiencia de los algoritmos.

Las principales propiedades son:

1. **Multiplicación por una constante:** las constantes no modifican el orden de crecimiento.
2. **Suma de funciones:** se conserva el término de mayor crecimiento.
3. **Máximo de funciones:** se considera la función que presenta el mayor crecimiento.
4. **Producto de funciones:** se multiplican las funciones para obtener el orden resultante.
5. **Logaritmos de diferentes bases:** tienen el mismo orden de crecimiento.
6. **Logaritmo de un factorial:** \(O(\log(n!))=O(n\log n)\).
7. **Sumatoria de potencias:** para \(k>1\), su orden es \(O(n^{k+1})\).
8. **Sumatoria de logaritmos:** su orden es \(O(n\log n)\).

Estas propiedades facilitan el análisis de algoritmos al permitir reducir expresiones complejas a su orden de crecimiento dominante.