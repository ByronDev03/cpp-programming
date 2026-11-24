<h1 align="center">Algoritmos Divide y Vencerás</h1>

## Contenido
1. [Concepto de Divide y Vencerás]()
2. [Caso base]()
3. [Funcionamiento del algoritmo]()
4. [Ejemplo: Dibujar un segmento]()

# 1. Concepto de Divide y Vencerás
Una de las técnicas más importantes para la resolución de muchos problemas de computadora es la denominada **divide y vencerás**. El diseño de algoritmos basados en esta técnica consiste en transformar (dividir) un problema de tamaño \(n\) en problemas más pequeños, de tamaño menor que \(n\), pero similares al problema original. De modo que, resolviendo los **subproblemas** y combinando las soluciones, se pueda construir fácilmente una solución del problema completo (vencerás).

# 2. Caso base
Normalmente, el proceso de división del problema en otros de tamaño menor va a dar lugar a que se llegue al **caso base**, cuya solución es inmediata. A partir de la obtención de la solución del problema para el caso base, se combinan soluciones que amplían el tamaño del problema resuelto, hasta que el problema original queda resuelto.

# 3. Funcionamiento del algoritmo
Un algoritmo de **divide y vencerás** se define de manera recursiva, de tal modo que se llama a sí mismo sobre un conjunto menor de elementos. Normalmente, se implementa con dos llamadas recursivas, cada una con un tamaño menor, generalmente la mitad. Se alcanza el caso base cuando el problema se resuelve directamente. Un algoritmo divide y vencerás consta de **2 partes**:

1. Dividir recursivamente el problema original en subproblemas cada vez más pequeños.
2. Resolver el problema dando solución a los subproblemas a partir del caso base.

# 4. Ejemplo: Dibujar un segmento
Se plantea el problema de dibujar un segmento que está conectado por los puntos en el plano \((x1,y1)\) y \((x2,y2)\).

**Representación del segmento:**
```text
(x1,y1)  ●──────●──────●──────●  (x2,y2)
```

