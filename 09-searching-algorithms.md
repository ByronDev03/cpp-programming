<h1 align="center">9. Algoritmos de Búsqueda</h1>

<p align="justify">
En esta unidad se estudian los algoritmos de búsqueda en C++, utilizados para localizar un elemento específico dentro de un arreglo. Estos algoritmos permiten determinar si un valor existe en una colección de datos y, cuando se encuentra, identificar la posición que ocupa. A través de los ejercicios, se implementarán dos métodos de búsqueda: la búsqueda secuencial, que examina los elementos uno por uno, y la búsqueda binaria, que reduce progresivamente el intervalo de búsqueda mediante la comparación con el elemento central. Se analizará cómo funciona cada método y qué condiciones deben cumplirse para utilizarlos correctamente.
</p>

## Conceptos principales
- **Búsqueda secuencial:** recorrido de un arreglo elemento por elemento hasta encontrar el valor buscado o llegar al final.
- **Búsqueda binaria:** división progresiva del intervalo de búsqueda en mitades para localizar un elemento de manera más eficiente.
- **Arreglos e índices:** acceso a los elementos de un arreglo mediante sus posiciones.
- **Límites de búsqueda:** utilización de variables para controlar el inicio y el final del intervalo de búsqueda.
- **Elemento central:** cálculo de la posición media del intervalo mediante operaciones aritméticas.
- **Condiciones de búsqueda:** uso de comparaciones para determinar si el elemento buscado coincide con el valor actual.
- **Control de iteraciones:** utilización de ciclos `while` para repetir las comparaciones mientras se cumplan determinadas condiciones.
- **Indicadores de búsqueda:** uso de una variable de control para registrar si el elemento fue encontrado.
- **Complejidad algorítmica:** comparación conceptual de la cantidad de operaciones que requieren ambos métodos; la búsqueda secuencial tiene complejidad \(O(n)\), mientras que la búsqueda binaria tiene complejidad \(O(\log n)\).

## Objetivo
Comprender e implementar los algoritmos de búsqueda secuencial y binaria en C++, identificando la posición de un elemento dentro de un arreglo y reconociendo las condiciones necesarias para aplicar cada método de manera correcta y eficiente.

## Ejercicios

##### 1. Busqueda Binaria
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	int numeros[] = {1,2,3,4,5};
	int inf,sup,mitad,dato,i;
	char band='F';
	
	dato = 1;
	
	//Algoritmo de la Busqueda Binaria
	inf=0;
	sup=5;
	i=0;
	while((inf<=sup)&&(i<5)){
		mitad = (inf+sup)/2;
		if(numeros[mitad] == dato){
			band='V';
			break;
		}
		if(numeros[mitad]>dato){
			sup = mitad;
			mitad = (inf+sup)/2;
		}
		if(numeros[mitad]<dato){
			inf = mitad;
			mitad = (inf+sup)/2;
		}
		i++;
	}
	
	if(band == 'V'){
		cout<<"El numero se encontro en la pos: "<<mitad<<endl;
	}
	else{
		cout<<"El numero NO se encontro";
	}
	
	getch();
	return 0;
}
```
</details>

##### 2. Busqueda Secuencial
<details>
<summary>Solución</summary>

```c++
//a[5] = {3,4,2,1,5}; dato = 4;

#include<iostream>
#include<conio.h>

using namespace std;

int main(){
	int a[] = {3,4,2,1,5};
	int i,dato;
	char band = 'F';
	
	dato = 4; 
	//Busqueda Secuencial
	i=0;
	while((band == 'F') && (i<5)){
		if(a[i] == dato){
			band = 'V';
		}
		i++;
	}
	
	if(band == 'F'){
		cout<<"El numero a buscar no existe en el arreglo"<<endl;
	}
	else if(band == 'V'){
		cout<<"El numero a sido encontrado en la pos: "<<i-1<<endl;
	}
	
	getch();
	return 0;
}
```
</details>