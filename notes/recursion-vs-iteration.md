<h1 align="center">Recursión vs Iteración</h1>

## Contenido
1. [Introducción]()
2. [Ejemplo: Suma de los dígitos de un número]()
3. [Directrices para elegir entre iteración y recursión]()

# 1. Introducción
En las secciones anteriores se han estudiado varios algoritmos que se pueden implementar fácilmente de modo recursivo, o bien de modo iterativo. En este apartado se comparan los dos enfoques y se examinan las razones por las que el programador puede elegir un enfoque u otro según la situación específica.

La **recursión** tiene muchas desventajas. Se invoca repetidamente al mecanismo de llamada a función y, en consecuencia, se necesita un tiempo suplementario para realizar cada llamada. Esta característica puede resultar cara en tiempo de procesador y espacio de memoria.

Entonces, **¿cuáles son las razones para elegir la recursión?**

La razón fundamental es que existen numerosos problemas complejos que poseen naturaleza recursiva y, en consecuencia, son más fáciles de implementar con algoritmos de este tipo.

# 2. Ejemplo: Suma de los dígitos de un número
Dado un número natural \(N\), obtener la suma de los dígitos de que consta.

Presentar un algoritmo recursivo y otro iterativo.

# 3. Directrices para elegir entre iteración y recursión
- Considérese una solución recursiva sólo cuando una solución iterativa sencilla no sea posible.
- Utilícese una solución recursiva sólo cuando la ejecución y eficiencia de la memoria de la solución estén dentro de límites aceptables considerando las limitaciones del sistema.
- Si son posibles las dos soluciones, iterativa y recursiva, la solución recursiva siempre requerirá más tiempo y espacio debido a las llamadas adicionales a las funciones.
- En ciertos problemas, la recursión conduce naturalmente a soluciones que son mucho más fáciles de leer y comprender que su correspondiente iterativa. En estos casos los beneficios obtenidos con la claridad de la solución suelen compensar el coste extra (en tiempo y memoria) de la ejecución de un programa recursivo.