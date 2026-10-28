<h1 align="center">15. Listas Enlazadas</h1>

<p align="justify">
En esta unidad se estudian las listas enlazadas en C++, una estructura de datos dinámica que permite almacenar elementos mediante nodos conectados entre sí por medio de punteros. A diferencia de los arreglos tradicionales, las listas enlazadas permiten incorporar y eliminar elementos durante la ejecución del programa sin depender de una cantidad fija de posiciones consecutivas en memoria. A través de los ejercicios, se aprenderá a crear nodos, insertar elementos al final o en una posición ordenada, recorrer y mostrar los datos almacenados, buscar valores y eliminar nodos. También se utilizarán listas para realizar cálculos numéricos, como determinar el mayor y el menor elemento, así como calcular la suma y el promedio de sus valores.
</p>

## Conceptos principales
- **Estructura de un nodo:** utilización de `struct` para almacenar un dato y un puntero al siguiente nodo.
- **Punteros y memoria dinámica:** creación de nodos mediante `new` y liberación de memoria mediante `delete`.
- **Lista vacía y nodo inicial:** representación de una lista sin elementos mediante `NULL` y acceso al primer nodo a través de un puntero.
- **Inserción de elementos:** incorporación de nuevos nodos al final de una lista o en la posición correspondiente para mantener los elementos ordenados.
- **Recorrido de listas:** utilización de ciclos `while` y punteros auxiliares para visitar los nodos y procesar sus datos.
- **Visualización de elementos:** recorrido secuencial de la lista para mostrar sus valores.
- **Búsqueda de elementos:** comparación de los datos de cada nodo para determinar si un valor se encuentra en la lista.
- **Eliminación de nodos:** actualización de los enlaces entre nodos y liberación de memoria al eliminar elementos.
- **Eliminación completa de una lista:** recorrido y eliminación sucesiva de los nodos hasta dejar la estructura vacía.
- **Procesamiento de datos:** cálculo del mayor y menor valor, la suma y el promedio de los elementos almacenados.
- **Funciones con parámetros por referencia:** modificación del puntero inicial de la lista desde funciones de inserción y eliminación.

## Objetivo
Comprender cómo funcionan las listas enlazadas en C++ y desarrollar operaciones para crear, recorrer, buscar, insertar y eliminar nodos mediante punteros y memoria dinámica, aplicando estas operaciones al procesamiento y análisis de conjuntos de datos.

## Ejercicios

##### 1. Crear una lista que almacene "n" números enteros y calcular el menor y mayor de ellos.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;	
};

void insertarLista(Nodo *&,int);
void mostrarLista(Nodo *);
void calcularMayorMenor(Nodo *);

int main(){
	Nodo *lista = NULL;
	int dato;
	char opcion;
	
	do{
		cout<<"Digite un numero para agregarlo a lista: ";
		cin>>dato;
		insertarLista(lista,dato);
		
		cout<<"\nDesea agregar un nuevo numero(s/n): ";
		cin>>opcion;
	}while(opcion == 's' || opcion == 'S');
	
	cout<<"\nElementos de la lista: \n";
	mostrarLista(lista); //mostramos la lista
	
	calcularMayorMenor(lista);	
	
	getch();
	return 0;
}

//Insertar elemento en la lista
void insertarLista(Nodo *&lista,int n){
	Nodo *nuevo_nodo = new Nodo();
	Nodo *aux;
	
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = NULL;
	
	if(lista == NULL){//Si la lista esta vacia
		lista = nuevo_nodo;//agregamos el primer nodo
	}
	else{
		aux = lista;
		while(aux->siguiente != NULL){//recorremos la lista hasta llegar al final
			aux = aux->siguiente;
		}
		aux->siguiente = nuevo_nodo;//agregamos el nuevo nodo al final de la lista
	}
	cout<<"\tElemento "<<n<<" agregado a lista correctamente\n";
}

//Mostrar todos los elementos de la lista
void mostrarLista(Nodo *lista){	
	Nodo *actual = new Nodo();
	
	actual = lista;
	while(actual != NULL){ //mientras no sea final de la lista
		cout<<actual->dato<<" -> "; //mostramos el dato
		actual = actual->siguiente; //avanzamos a la siguiente posicion de la lista
	}
}

//Calcular el menor y mayor elemento de la lista
void calcularMayorMenor(Nodo *lista){
	int mayor=0,menor=99999;
	
	while(lista != NULL){//mientras no sea el final de la lista
		if((lista->dato)>mayor){//Comprobamos el numero mayor
			mayor = lista->dato;
		}
		if((lista->dato)<menor){//Comprobamos el numero menor
			menor = lista->dato;
		}
		lista = lista->siguiente;//Avanzamos en la lista
	}
	
	cout<<"\n\nEl mayor numero es: "<<mayor<<endl;
	cout<<"El menor numero es: "<<menor<<endl;	
}
```
</details>

##### 2. Crear una lista que almacene "n" números reales y calcular su suma y promedio.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

struct Nodo{
	float dato;
	Nodo *siguiente;	
};

void insertarLista(Nodo *&,float);
void mostrarLista(Nodo *);
void calcularSumaPromedio(Nodo *);

int main(){
	Nodo *lista = NULL;
	float dato;
	char opcion;
	
	do{
		cout<<"Digite un numero: ";;
		cin>>dato;
		insertarLista(lista,dato);
		
		cout<<"\nDesea agregar otro elemento a lista(s/n): ";
		cin>>opcion;
	}while(opcion == 's' || opcion == 'S');
	
	cout<<"\nElementos de la lista:\n";
	mostrarLista(lista);
	
	calcularSumaPromedio(lista); 
	
	getch();
	return 0;
}

//Insertar elementos al final de la lista
void insertarLista(Nodo *&lista,float n){
	Nodo *nuevo_nodo = new Nodo();
	Nodo *aux;
	
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = NULL;
	
	if(lista == NULL){//lista vacia
		lista = nuevo_nodo;
	}
	else{
		aux = lista; //aux se�ala el inicio de la lista
		while(aux->siguiente != NULL){ //recorremos la lista
			aux = aux->siguiente;
		}
		aux->siguiente = nuevo_nodo;
	}
	cout<<"\tElemento "<<n<<" insertado a lista correctamente\n";
}

//Mostrar todos los elementos de la lista
void mostrarLista(Nodo *lista){
	while(lista != NULL){ //mientras no sea el final de la lista
		cout<<lista->dato<<" -> "; //mostramos el dato
		lista = lista->siguiente; //avanzamos una posicion mas en la lista
	}
}

//Calcular suma y promedio de los elementos de la lista
void calcularSumaPromedio(Nodo *lista){
	float suma=0,promedio=0;
	int contador=0;
	
	while(lista != NULL){//mientras no sea el final de la lista
		suma += lista->dato; //suma iterativa
		contador++; //aumentamos el contador de elementos de la lista
		lista = lista->siguiente; //Avanzamos en la lista
	}
	
	promedio = suma / contador;
	
	cout<<"\n\nLa suma es: "<<suma<<endl;
	cout<<"El promedio es: "<<promedio<<endl;
}
```
</details>

##### 3. Listas Enlazadas
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;	
};

//Prototipos de Funciones
void menu();
void insertarLista(Nodo *&,int);
void mostrarLista(Nodo *);
void buscarLista(Nodo *,int);
void eliminarNodo(Nodo *&,int);
void eliminarLista(Nodo *&,int &);

Nodo *lista = NULL;

int main(){

	menu();	
	
	getch();
	return 0;
}

void menu(){
	int opcion,dato;
	
	do{
		cout<<"\t.:MENU:.\n";
		cout<<"1. Insertar elementos a la lista\n";
		cout<<"2. Mostrar los elementos de la lista\n";
		cout<<"3. Buscar un elemento en lista\n";
		cout<<"4. Eliminar un nodo de la lista\n";
		cout<<"5. Dejar vacia la lista\n";
		cout<<"6. Salir\n";
		cout<<"Opcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 1: cout<<"\nDigite un numero: ";
					cin>>dato;
					insertarLista(lista,dato);
					cout<<"\n";
					system("pause");
					break;
			case 2: mostrarLista(lista);
					cout<<"\n";
					system("pause");
					break;
			case 3: cout<<"\nDigite un numero a buscar: ";
					cin>>dato;
					buscarLista(lista,dato);
					cout<<"\n";
					system("pause");
					break;
			case 4: cout<<"\nDigite el elemento que desea eliminar: ";
					cin>>dato;
					eliminarNodo(lista,dato);
					cout<<"\n";
					system("pause");
					break;
			case 5: 
					while(lista != NULL){ //mientras no sea el final de la lista
						eliminarLista(lista,dato);
						cout<<dato<<" -> "; 
					}
					cout<<"\n";
					system("pause");
					break;					
		}
		system("cls");
	}while(opcion != 6);
}

void insertarLista(Nodo *&lista,int n){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->dato = n;
	Nodo *aux1 = lista;
	Nodo *aux2;
	
	while((aux1 != NULL) && (aux1->dato < n)){
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}
	
	if(lista == aux1){
		lista = nuevo_nodo;
	}
	else{
		aux2->siguiente = nuevo_nodo;
	}
	
	nuevo_nodo->siguiente = aux1;
	
	cout<<"\tElemento "<<n<<" insertado a lista correctamente\n";
}

void mostrarLista(Nodo *lista){
	Nodo *actual = new Nodo();
	actual = lista;
	
	while(actual != NULL){
		cout<<actual->dato<<" -> ";
		actual = actual->siguiente;
	}
}

void buscarLista(Nodo *lista,int n){
	bool band = false;
	
	Nodo *actual = new Nodo();
	actual = lista;
	
	while((actual != NULL) && (actual->dato <= n)){
		if(actual->dato == n){
			band = true;
		}
		actual = actual->siguiente;
	}
	
	if(band == true){
		cout<<"Elemento "<<n<<" SI a sido encontrado en lista\n";
	}
	else{
		cout<<"Elemento "<<n<<" NO a sido encontrado en lista\n";
	}
}

void eliminarNodo(Nodo *&lista,int n){
	//Preguntar si la lista no esta vacia
	if(lista != NULL){
		Nodo *aux_borrar;
		Nodo *anterior = NULL;
		
		aux_borrar = lista;
		
		//Recorrer la lista
		while((aux_borrar != NULL) && (aux_borrar->dato != n)){
			anterior = aux_borrar;
			aux_borrar = aux_borrar->siguiente;
		}
		
		//El elemento no ha sido encontrado
		if(aux_borrar == NULL){
			cout<<"El elemento no ha sido encontrado";
		}	
		//El primer elemento es el que vamos a eliminar
		else if(anterior == NULL){
			lista = lista->siguiente;
			delete aux_borrar;
		}
		//El elemento esta en la lista pero, no es el primer nodo
		else{
			anterior->siguiente = aux_borrar->siguiente;
			delete aux_borrar;
		}
	}
}

//Dejar vacía la lista
void eliminarLista(Nodo *&lista,int &n){
	Nodo *aux = lista;
	n = aux->dato;
	lista = aux->siguiente;
	delete aux;
}
```
</details>