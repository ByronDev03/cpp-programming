<h1 align="center">13. Pilas</h1>

<p align="justify">
En esta unidad se estudian las pilas en C++, una estructura de datos lineal que organiza sus elementos siguiendo el principio LIFO (Last In, First Out), es decir, el último elemento que ingresa es el primero en salir. Esta estructura permite insertar y extraer elementos desde un mismo extremo, conocido como la cima de la pila. A través de los ejercicios, se aprenderá a implementar pilas mediante nodos enlazados y punteros, insertar elementos de diferentes tipos, extraer los elementos almacenados y desarrollar menús interactivos para administrar las operaciones de la estructura.
</p>

## Conceptos principales
- **Principio LIFO:** organización de los elementos según el orden en que se insertan y extraen.
- **Estructura de un nodo:** utilización de `struct` para almacenar un dato y un puntero al siguiente nodo.
- **Puntero de la pila:** referencia al nodo ubicado en la cima, que permite acceder al elemento más reciente.
- **Inserción de elementos:** utilización de funciones como `agregarPila()` para crear un nodo y colocarlo en la cima de la pila.
- **Extracción de elementos:** utilización de funciones como `sacarPila()` para recuperar y eliminar el elemento ubicado en la cima.
- **Punteros y memoria dinámica:** creación de nodos mediante `new`, actualización de enlaces y liberación de memoria mediante `delete`.
- **Inicialización de una pila vacía:** utilización de `NULL` para indicar que la estructura no contiene elementos.
- **Recorrido y extracción de elementos:** uso de ciclos `while` para procesar los elementos hasta que la pila quede vacía.
- **Manejo de diferentes tipos de datos:** almacenamiento de números enteros y caracteres mediante estructuras de nodos.
- **Menús interactivos:** utilización de estructuras `do-while` y `switch` para permitir al usuario insertar elementos, mostrar el contenido de la pila y salir del programa.
- **Funciones con parámetros por referencia:** modificación del puntero de la pila desde funciones que insertan o extraen elementos.

## Objetivo
Comprender e implementar pilas en C++ mediante estructuras, punteros y memoria dinámica, desarrollando operaciones para insertar y extraer elementos y aplicando el principio LIFO para administrar datos de manera ordenada.

## Ejercicios

##### 1. Hacer un programa para agregar números enteros a una pila, hasta que el usuario lo decida, después mostrar todos los números introducidos en la pila.
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

//Prototipos de Función
void agregarPila(Nodo *&,int); 
void sacarPila(Nodo *&,int &);

int main(){
	Nodo *pila = NULL;	//Inicializamos pila
	int dato;
	char rpt;
	
	do{ //Pedimos todos los elementos de la pila
		cout<<"Digite un numero: ";
		cin>>dato;
		agregarPila(pila,dato);
	
		cout<<"\nDesea agregar otro numero a pila(s/n): ";
		cin>>rpt;
	}while((rpt == 's')||(rpt=='S'));
	
	
	cout<<"\nMostrando los elementos de la pila: ";
	while(pila != NULL){
		sacarPila(pila,dato);
		
		if(pila != NULL){
			cout<<dato<<" , ";
		}
		else{
			cout<<dato<<".";
		}
	}
	
	getch();
	return 0;
}

void agregarPila(Nodo *&pila,int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
	
	cout<<"\tElemento "<<n<<" agregado a PILA correctamente";
}

void sacarPila(Nodo *&pila,int &n){
	Nodo *aux = pila;
	n = aux->dato;
	pila = aux->siguiente;
	delete aux;
}
```
</details>

##### 2. Hacer un programa utilizando Pilas que contenga el siguiente menu: 
1. **Insertar un caracter a la pila**
2. **Mostrar todos los elementos de la pila**
3. **Salir**
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct Nodo{
	char dato;
	Nodo *siguiente;	
};

//Prototipo
void menu();
void agregarPila(Nodo *&,char);
void sacarPila(Nodo *&,char &);

int main(){
	
	menu();
	
	getch();
	return 0;
}

void menu(){
	Nodo *pila = NULL;
	int opcion;
	char dato;
	
	do{
		cout<<"\t.:MENU:.\n";
		cout<<"1. Insertar un caracter a la pila"<<endl;
		cout<<"2. Mostrar todos los elementos de la pila"<<endl;
		cout<<"3. Salir"<<endl;
		cout<<"Opcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 1: cout<<"\nDigite un caracter: ";
					cin>>dato;
					agregarPila(pila,dato);
					break;
			case 2: cout<<"\nMostrando todos los elementos de la pila: ";
					while(pila != NULL){
						sacarPila(pila,dato);
						if(pila != NULL){
							cout<<dato<<" , ";
						}
						else{
							cout<<dato<<".";
						}
					}
					cout<<"\n";
					system("pause");
					break;
			case 3: break;
		}
		system("cls"); //limpiar pantalla
	}while(opcion != 3);
	
}

void agregarPila(Nodo *&pila,char n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
}

void sacarPila(Nodo *&pila,char &n){
	Nodo *aux = pila;
	n = aux->dato;
	pila = aux->siguiente;
	delete aux;
}
```
</details>

##### 3. Insertar elementos en la pila
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

void agregarPila(Nodo *&,int); //Prototipo de Funcion

int main(){
	Nodo *pila = NULL;
	int n1,n2;
	
	cout<<"Digite un numero: ";
	cin>>n1;
	agregarPila(pila,n1);
	
	cout<<"Digite otro numero: ";
	cin>>n2;
	agregarPila(pila,n2);
	
	getch();
	return 0;
}

void agregarPila(Nodo *&pila,int n){
	Nodo *nuevo_nodo = new Nodo(); //1. Crear el espacio en memoria para almacenar un nodo.
	nuevo_nodo->dato = n; //2. Cargar el valor dentro del nodo(dato).
	nuevo_nodo->siguiente = pila; //3. Cargar el puntero pila dentro del nodo(*siguiente).
	pila = nuevo_nodo; //4. Asignar el nuevo nodo a pila.
	
	cout<<"\tElemento "<<n<<" ha sido agregado a PILA correctamente"<<endl;
}
```
</details>