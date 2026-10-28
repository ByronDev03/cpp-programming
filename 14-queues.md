<h1 align="center">14. Colas</h1>

<p align="justify">
En esta unidad se estudian las colas en C++, una estructura de datos lineal que permite almacenar y procesar elementos siguiendo el principio FIFO (First In, First Out), es decir, el primer elemento que ingresa es el primero en salir. Esta estructura resulta útil para representar situaciones en las que se debe respetar el orden de llegada, como la atención de clientes en un banco. A través de los ejercicios, se aprenderá a implementar colas mediante nodos enlazados y punteros, realizar operaciones de inserción y extracción, comprobar si una cola está vacía y administrar elementos de distintos tipos, como caracteres, números enteros y registros de clientes.
</p>

## Conceptos principales
- **Principio FIFO:** organización de los elementos según el orden en que ingresan a la cola.
- **Estructura de un nodo:** utilización de `struct` para almacenar un dato y un puntero al siguiente nodo.
- **Punteros de frente y fin:** referencias que permiten identificar el primer y el último elemento de la cola.
- **Inserción de elementos:** incorporación de nuevos nodos al final de la cola mediante funciones como `insertarCola()` y `agregarCola()`.
- **Extracción de elementos:** eliminación del nodo ubicado al frente de la cola y recuperación de su dato mediante funciones como `suprimirCola()`.
- **Comprobación de una cola vacía:** utilización de una función como `cola_vacia()` para determinar si existen elementos almacenados.
- **Memoria dinámica:** creación de nodos mediante `new` y liberación de memoria mediante `delete` al extraer elementos.
- **Manejo de punteros:** actualización de los enlaces entre nodos y de los punteros de frente y fin durante las operaciones.
- **Colas de diferentes tipos de datos:** almacenamiento de caracteres, números enteros y registros de clientes mediante estructuras.
- **Recorrido y procesamiento de elementos:** extracción sucesiva de los elementos para mostrarlos en el orden en que fueron insertados.
- **Funciones y parámetros por referencia:** modificación de los punteros de la cola desde funciones que insertan o extraen elementos.

## Objetivo
Comprender e implementar colas en C++ mediante estructuras, punteros y memoria dinámica, desarrollando operaciones para insertar, consultar y extraer elementos, y aplicando el principio FIFO para procesar datos y registros en el orden correcto.

## Ejercicios

##### 1. Hacer un programa en C++, utilizando Colas que contenga el siguiente menu: 
1. **Insertar un caracter a una cola**
2. **Mostrar todos los elementos de la cola**
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

//Prototipos de Funciones
void menu();
void insertarCola(Nodo *&,Nodo *&,char);
bool cola_vacia(Nodo *);
void suprimirCola(Nodo *&,Nodo *&,char &);

int main(){
	
	menu();
	
	getch();
	return 0;
}

void menu(){
	int opc;
	char dato;
	
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	
	do{
		cout<<"\t.:MENU:.\n";
		cout<<"1. Insertar un caracter a una cola"<<endl;
		cout<<"2. Mostrar todos los elementos de la cola"<<endl;
		cout<<"3. Salir"<<endl;
		cout<<"Opcion: ";
		cin>>opc; 
		
		switch(opc){
			case 1: cout<<"\nIngrese el caracter para agregar a la cola: ";
					cin>>dato;
					insertarCola(frente,fin,dato);
					break;
			case 2: cout<<"\nMostrando los elementos de la cola: ";
					while(frente != NULL){
						suprimirCola(frente,fin,dato);
						if(frente != NULL){
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
		system("cls");
	}while(opc != 3);
}

//Función para insertar elementos en la cola
void insertarCola(Nodo *&frente,Nodo *&fin,char n){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = NULL;
	
	if(cola_vacia(frente)){
		frente = nuevo_nodo;
	}
	else{
		fin->siguiente = nuevo_nodo;
	}
	
	fin = nuevo_nodo;
}

//Función para determinar si la cola est� vacia
bool cola_vacia(Nodo *frente){
	return (frente == NULL)? true : false; 
}

//Función para eliminar elementos de la cola
void suprimirCola(Nodo *&frente,Nodo *&fin,char &n){
	n = frente->dato;
	Nodo *aux = frente;
	
	if(frente == fin){
		frente = NULL;
		fin = NULL;
	}
	else{
		frente = frente->siguiente;
	}
	delete aux;
}
```
</details>

##### 2. Hacer un programa que guarde datos de clientes de un banco, los almacene en cola, y por ultimo muestre los clientes en el orden correcto.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct Cliente{
	char nombre[30];
	char clave[10];
	int edad;
};

struct Nodo{
	Cliente c;
	Nodo *siguiente;	
};

//Prototipos de Funciones
void cargar_cliente(Cliente &);
void insertarCola(Nodo *&,Nodo *&,Cliente);
bool cola_vacia(Nodo *);
void suprimirCola(Nodo *&,Nodo *&,Cliente &);

int main(){
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	Cliente c;
	char rpt;
	
	do{
		cargar_cliente(c); //Cargamos cliente
		insertarCola(frente,fin,c); //y luego lo agregamos a cola
		
		cout<<"Desea agregar mas clientes(s/n): ";
		cin>>rpt;
		cout<<"\n";
	}while(rpt == 'S' || rpt == 's');
	
	cout<<"\n\n=== Carga de Clientes Exitosa ===\n\n";
	
	cout<<"Mostrando clientes:\n\n";
	while(frente != NULL){//Vaciando la cola
		suprimirCola(frente,fin,c);
		//Mostrando todos los clientes agregados
		cout<<"Nombre: "<<c.nombre<<endl;
		cout<<"Clave: "<<c.clave<<endl;
		cout<<"Edad: "<<c.edad<<endl;
		cout<<"\n";		
	}	
	
	getch();
	return 0;
}

void cargar_cliente(Cliente &c){
	fflush(stdin);
	cout<<"\tAgregando un Nuevo Cliente"<<endl;
	cout<<"Nombre: "; cin.getline(c.nombre,30,'\n');
	cout<<"Clave: "; cin.getline(c.clave,10,'\n');
	cout<<"Edad: "; cin>>c.edad;
	cout<<"\n";
} 

void insertarCola(Nodo *&frente,Nodo *&fin,Cliente c){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->c = c;
	nuevo_nodo->siguiente = NULL;
	
	if(cola_vacia(frente)){
		frente = nuevo_nodo;
	}
	else{
		fin->siguiente = nuevo_nodo;
	}
	
	fin = nuevo_nodo;
}

bool cola_vacia(Nodo *frente){
	return (frente == NULL)? true : false;
}

void suprimirCola(Nodo *&frente,Nodo *&fin,Cliente &c){
	c = frente->c;
	Nodo *aux = frente;
	
	if(frente == fin){
		frente = NULL;
		fin = NULL;
	}
	else{
		frente = frente->siguiente;
	}
	
	delete aux;
}
```
</details>

##### 3. Colas en C++
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

struct Nodo{
	int valor;
	Nodo *sgte;	
};

//Prototipos de Funciones
void agregarCola(Nodo *&,Nodo *&,int);
void suprimirCola(Nodo *&,Nodo *&,int &);
bool cola_vacia (Nodo *);

int main(){
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	
	int dato;
	
	cout<<"Digite un numero: ";
	cin>>dato;
	agregarCola(frente,fin,dato);
	
	cout<<"Digite otro numero: ";
	cin>>dato;
	agregarCola(frente,fin,dato);
	
	while(frente != NULL){
		suprimirCola(frente,fin,dato);
		
		if(frente != NULL){
			cout<<dato<<" , ";
		}
		else{
			cout<<dato<<".";
		}
	}
	
	getch();
	return 0;
}

//Función para insertar nodos a la cola
void agregarCola(Nodo *&frente,Nodo *&fin,int n){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo -> valor = n;
	nuevo_nodo -> sgte = NULL;
	
	if(cola_vacia(frente)){
		frente = nuevo_nodo;
	}
	else{
		fin -> sgte = nuevo_nodo;
	}
	
	fin = nuevo_nodo;
}

//Función para extraer nodos de la cola
void suprimirCola(Nodo *&frente,Nodo *&fin,int &n){
	n = frente->valor;
	
	Nodo *aux = frente;
	
	if(frente == fin){
		frente = NULL;
		fin = NULL;
	}
	else{
		frente = frente->sgte;
	}
	
	delete aux;
}

//Función para comprobar el estado de la cola, si esta vacia o no
bool cola_vacia(Nodo *frente){
	if(frente == NULL){
		return true;
	}
	else{
		return false;
	}
}
```
</details>

##### 4. Insertar elementos en una cola
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
void insertarCola(Nodo *&,Nodo *&,int);
bool cola_vacia(Nodo *);

int main(){
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	
	int dato;
	
	cout<<"Digite un numero: ";
	cin>>dato;
	insertarCola(frente,fin,dato);
	
	cout<<"Digite un numero: ";
	cin>>dato;
	insertarCola(frente,fin,dato);
	
	cout<<"Digite un numero: ";
	cin>>dato;
	insertarCola(frente,fin,dato);
	
	
	getch();
	return 0;
}

//Función para insertar elementos en una cola
void insertarCola(Nodo *&frente,Nodo *&fin,int n){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = NULL;
	
	if(cola_vacia(frente)){
		frente = nuevo_nodo;
	}
	else{
		fin->siguiente = nuevo_nodo;	
	}	
	
	fin = nuevo_nodo;
	
	cout<<"\tElemento "<<n<<" insertado a cola correctamente\n";
}

//Función para determinar si la cola esta vacia o no
bool cola_vacia(Nodo *frente){
	return (frente == NULL)? true : false;
}
```
</details>