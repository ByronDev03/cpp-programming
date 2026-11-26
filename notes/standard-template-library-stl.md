<h1 align="center">Biblioteca Estándar de Plantillas (STL)</h1>

## Contenido
1. [¿Qué es la STL?]()
2. [Componentes básicos de la STL]() 
    - [2.1. Contenedores]()
    - [2.2. Iteradores]() 
    - [2.3. Algoritmos]()

# 1. ¿Qué es la STL?
La STL (del inglés *Standard Template Library*) es una biblioteca de clases y funciones templates, creada para estandarizar y optimizar la utilización de algoritmos y estructuras de datos en el desarrollo de software en C++.

La adopción de esta biblioteca posee grandes ventajas: al ser estándar está disponible en todos los compiladores y plataformas; está libre de errores, por lo tanto se ahorrará tiempo en depurar el código; proporciona su propia gestión de memoria.

# 2. Componentes básicos de la STL
La biblioteca presenta tres componentes básicos: **contenedores, iteradores y algoritmos**.

## 2.1. Contenedores
Los **contenedores** son los objetos capaces de almacenar otros objetos, cada uno de una forma particular. Representan a las estructuras de datos usuales, como los arreglos lineales o las listas enlazadas. Además éstos presentan otras características adicionales que los hacen más potentes: *dinámicos* y *templates*.

## 2.2. Iteradores
Los **iteradores** son objetos a través de los cuales se puede acceder a los elementos del contenedor. El concepto de iterador es similar al de un puntero, sólo que al ser una clase provee mayores utilidades que éste.

## 2.3. Algoritmos
Pero la gran utilidad de los **iteradores** ocurre cuando son utilizados por los **algoritmos**. En la biblioteca existen más de setenta algoritmos para aplicar sobre los contenedores a través de los iteradores. Hay algoritmos de búsqueda, de ordenamiento, de transformación, matemáticos, etc.