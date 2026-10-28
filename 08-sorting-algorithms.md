<h1 align="center">8. Métodos de Ordenamiento</h1>

<p align="justify">
En esta unidad se estudian los algoritmos de ordenamiento en C++, utilizados para organizar los elementos de un arreglo siguiendo un criterio determinado, como el orden ascendente o descendente. Estos algoritmos permiten comprender diferentes estrategias para reorganizar datos y analizar cómo se comportan al procesar colecciones de elementos. A través de los ejercicios, se implementarán cinco métodos de ordenamiento: burbuja, inserción, selección, Shell y QuickSort. Se trabajará con arreglos numéricos y se utilizarán comparaciones, intercambios y diferentes estrategias para colocar los elementos en el orden deseado.
</p>

## Conceptos principales
- **Ordenamiento ascendente y descendente:** organización de los elementos de menor a mayor o de mayor a menor.
- **Comparación de elementos:** utilización de operadores relacionales para determinar el orden entre dos valores.
- **Intercambio de elementos:** uso de una variable auxiliar para intercambiar los valores de dos posiciones.
- **Ordenamiento burbuja (Bubble Sort):** comparación de elementos adyacentes e intercambio de sus posiciones cuando están desordenados.
- **Ordenamiento por inserción (Insertion Sort):** inserción de cada elemento en la posición correspondiente dentro de la parte previamente ordenada.
- **Ordenamiento por selección (Selection Sort):** búsqueda del elemento menor y colocación en la posición que le corresponde.
- **Ordenamiento Shell (Shell Sort):** comparación e intercambio de elementos separados por intervalos que se reducen progresivamente.
- **Ordenamiento rápido (QuickSort):** división del arreglo en particiones a partir de un pivote y ordenamiento recursivo de las sublistas.
- **Ciclos y variables de control:** utilización de estructuras `for`, `while` y `do-while`, junto con índices, límites y variables auxiliares.
- **Funciones y parámetros por referencia:** creación de funciones para intercambiar valores y organizar arreglos, utilizando referencias cuando es necesario modificar los datos originales.
- **Recursividad:** aplicación de llamadas a una misma función para ordenar las particiones de un arreglo mediante QuickSort.

## Objetivo
Comprender e implementar diferentes algoritmos de ordenamiento en C++, aprender cómo reorganizan los elementos de un arreglo y comparar sus estrategias de funcionamiento, aplicando ciclos, comparaciones, intercambios, funciones y recursividad para obtener resultados ordenados.

## Apuntes
- **Ordenación de Burbuja (Bubble Sort)** → [Ver apunte](/notes/bubblesort.md) 
- **Ordenamiento por Selección** → [Ver apunte](/notes/seleccion.md) 
- **Ordenamiento por Inserción** → [Ver apunte](/notes/insercion.md) 
- **Ordenación Shell** → [Ver apunte](/notes/shell.md) 
- **Ordenación Rápida (QuickSort)** → [Ver apunte](/notes/quicksort.md)

## Ejercicios

##### 1. Método Burbuja
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	int array[5] = {2,3,1,5,4};
	int i,j,aux;
	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(array[j] > array[j+1]){
				aux = array[j];
				array[j] = array[j+1];
				array[j+1] = aux;
			}
		}
	}
	
	cout<<"Numeros de forma Ascendente: ";
	for(i=0;i<5;i++){
		cout<<array[i]<<" ";
	}
	
	cout<<"\nNumeros de forma Descendente: ";
	for(i=4;i>=0;i--){
		cout<<array[i]<<" ";
	}
	
	getch();
	return 0;
}
```
</details>

##### 2. Ordenamiento por Inserción
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	int numeros[] = {3,4,2,1,5};
	int i,pos,aux;
	
	for(i=0;i<5;i++){
		pos = i; 
		aux = numeros[i];
		
		while((pos>0) && (numeros[pos-1] > aux)){
			numeros[pos] = numeros[pos-1];
			pos--;
		}
		numeros[pos] = aux;
	}
	
	cout<<"Orden Ascendente: ";
	for(i=0;i<5;i++){
		cout<<numeros[i]<<" ";
	}
	
	cout<<"\nOrden Descendente: ";
	for(i=4;i>=0;i--){
		cout<<numeros[i]<<" ";
	}
	
	getch();
	return 0;
}
```
</details>

##### 3. Ordenamiento por Selección
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>

using namespace std;

int main(){
	int numeros[] = {3,4,5,2,1};
	int i,j,aux,min;
	
	//Algoritmo del Ordenamiento por Selecci�n
	for(i=0;i<5;i++){
		min = i;
		for(j=i+1;j<5;j++){
			if(numeros[j] < numeros[min]){
				min = j;
			}
		}
		aux = numeros[i];
		numeros[i] = numeros[min];
		numeros[min] = aux;
	}
	
	cout<<"Orden Ascendente: ";
	for(i=0;i<5;i++){
		cout<<numeros[i]<<" ";
	}
	
	cout<<"\nOrden Descendente: ";
	for(i=4;i>=0;i--){
		cout<<numeros[i]<<" ";
	}
	
	getch();
	return 0;
}
```
</details>

##### 4. Ordenamiento Shell
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;
void intercambiar(float &x,float &y){
	float aux;
	
	aux = x;
	x = y;
	y = aux;
}

void ordenacionShell(float a[],int n){
	int salto,i,j,k;
	salto = n/2;
	
	while(salto>0){
		for(i=salto;i<n;i++){
			j = i-salto;
			while(j>=0){
				k = j + salto;
				if(a[j] <= a[k]){
					j = -1;   //par de elementos ordenado
				}
				else{
					intercambiar(a[j],a[k]);
					j -= salto;
				}
			}
		}
		salto = salto/2;
	}
}

int main(){
	float arreglo[] = {6,1,5,2,3,4,0};	
	
	ordenacionShell(arreglo,7);
	
	cout<<"Arreglo Ordenado - Forma Ascendente: "<<endl;
	for(int i=0;i<7;i++){
		cout<<arreglo[i]<<"|";
	}
	
	cout<<"\n\nArreglo Ordenado - Forma Descendente"<<endl;
	for(int i=6;i>=0;i--){
		cout<<arreglo[i]<<"|";
	}
	
	getch();
	return 0;
}

```
</details>

##### 5. Ordenación Rápida (QuickSort)
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;
void intercambio(float &x,float &y){
	float aux;
	
	aux = x;
	x = y;
	y = aux;
}

void quickSort(float a[],int primero,int ultimo){
	int i,j,central;
	float pivote;
	
	central = (primero+ultimo) / 2;
	pivote = a[central];
	i = primero;
	j = ultimo;
	
	do{
		while(a[i] < pivote) i++;
		while(a[j] > pivote) j--;
		
		if(i<=j){
			intercambio(a[i],a[j]);
			i++;
			j--;
		}
	}while(i<=j);
	
	if(primero < j){
		quickSort(a,primero,j); //Ordenamos la sublista izquierda
	}
	if(i < ultimo){
		quickSort(a,i,ultimo); //Ordenamos la sublista derecha
	}	
}

int main(){
	float arreglo[] = {4,7,1,8,2,10,5,9,3};
	
	quickSort(arreglo,0,8);
	
	cout<<"Arreglo Ordenado - Forma Ascendente"<<endl;
	for(int i=0;i<9;i++){
		cout<<arreglo[i]<<"|";
	}
	
	cout<<"\n\nArreglo Ordenado - Forma Descendente"<<endl;
	for(int i=8;i>=0;i--){
		cout<<arreglo[i]<<"|";
	}
	
	getch();
	return 0;
}
```
</details>