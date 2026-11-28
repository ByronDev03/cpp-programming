<h1 align="center">Complejidad de las Sentencias Básicas de C++ </h1>

## Contenido
1. [Complejidad de las sentencias básicas de C++]()
   - [1.1. Sentencias de asignación]()
   - [1.2. Sentencias de selección]()
   - [1.3. Sentencias de selección múltiple]()
   - [1.4. Sentencias de repetición]()
   - [1.5. Bloques de instrucciones]()
   - [1.6. Llamadas a funciones]()
   - [1.7. Resumen]()

# 1. Complejidad de las sentencias básicas de C++
Al analizar la complejidad de un método no recursivo, se han de aplicar las propiedades de la notación **O** y las siguientes consideraciones relativas al orden que tienen las sentencias, fundamentalmente a las estructuras de control.

## 1.1. Sentencias de asignación
Las sentencias de asignación son de **orden constante O(1)**.

Esto significa que su tiempo de ejecución no depende del tamaño de la entrada, ya que realizan una operación cuyo costo se considera constante.

## 1.2. Sentencias de selección
La complejidad de una sentencia de selección (`if`) es el **máximo de las complejidades** del bloque `if` y del bloque `else`.

Se considera el bloque que tenga el mayor costo de ejecución, debido a que representa el peor caso.

## 1.3. Sentencias de selección múltiple
La complejidad de una sentencia de selección múltiple (`switch`) es el **máximo de las complejidades** de cada uno de los bloques `case`.

Se toma el bloque con mayor complejidad para determinar el costo de ejecución en el peor caso.

## 1.4. Sentencias de repetición
Para calcular la complejidad de un bucle, condicional o automático, se ha de estimar el número máximo de iteraciones para el peor caso.

Entonces, la complejidad del bucle es el producto del número de iteraciones por la complejidad de las sentencias que forman el cuerpo del bucle.

\[T(n) = \text{Número de iteraciones} \times \text{Complejidad del cuerpo}\]

## 1.5. Bloques de instrucciones
La complejidad de un bloque se calcula como la **suma de las complejidades** de cada sentencia del bloque.

\[T(n) = T_1(n) + T_2(n) + \cdots + T_k(n)\]

## 1.6. Llamadas a funciones
La complejidad de la llamada a una función es de **orden 1**, es decir, complejidad constante.

Sin embargo, es necesario considerar la complejidad de la función llamada para determinar el costo real de ejecución.

## 1.7. Resumen
La complejidad de las sentencias básicas de C++ permite analizar el costo de ejecución de un programa utilizando la notación **O**.

Las reglas principales son:
- **Asignaciones:** tienen complejidad constante O(1).
- **Selecciones (`if/else`):** se considera la mayor complejidad entre sus bloques.
- **Selección múltiple (`switch`):** se toma la mayor complejidad de los bloques `case`.
- **Bucles:** su complejidad se obtiene multiplicando el número máximo de iteraciones por la complejidad de su cuerpo.
- **Bloques de instrucciones:** se suman las complejidades de cada sentencia.
- **Llamadas a funciones:** aunque la llamada tiene un costo constante, debe considerarse también la complejidad de la función ejecutada.

Estas reglas permiten determinar cómo aumenta el tiempo de ejecución de un algoritmo conforme crece el tamaño de sus datos de entrada.