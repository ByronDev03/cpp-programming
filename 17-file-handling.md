<h1 align="center">17. Archivos</h1>

<p align="justify">
En esta unidad se estudia el manejo de archivos en C++, una herramienta que permite almacenar información de manera permanente para recuperarla posteriormente, incluso después de cerrar el programa. A través de los ejercicios, se aprenderá a crear archivos de texto, escribir frases, leer su contenido y agregar nueva información sin eliminar los datos existentes. También se desarrollarán programas que utilizan archivos para guardar y consultar información organizada, como una agenda telefónica y un registro de las pulsaciones de un atleta. Estos ejercicios permitirán trabajar tanto con archivos de texto como con archivos binarios, utilizando estructuras para organizar los datos y menús para seleccionar las operaciones disponibles.
</p>

## Conceptos principales
- **Flujos de archivos:** uso de `ofstream` para escribir información y `ifstream` para leer archivos.
- **Apertura y cierre de archivos:** utilización de `open()` y `close()` para abrir y cerrar archivos.
- **Modos de apertura:** uso de `ios::out` para escribir, `ios::in` para leer, `ios::app` para agregar información al final y `ios::binary` para trabajar con archivos binarios.
- **Lectura y escritura de texto:** utilización de `getline()` para leer frases completas y del operador `<<` para escribir información en un archivo.
- **Validación de archivos:** comprobación de errores mediante `fail()` antes de realizar operaciones.
- **Lectura del contenido de un archivo:** recorrido de archivos de texto para mostrar la información almacenada.
- **Archivos de texto:** creación y actualización de una agenda telefónica que permite registrar, agregar y visualizar contactos.
- **Archivos binarios:** almacenamiento y recuperación de registros mediante `write()` y `read()`.
- **Estructuras y archivos:** utilización de `struct` para organizar datos, como el nombre, apellido y teléfono de un contacto, o la hora y las pulsaciones de un atleta.
- **Menús de opciones:** uso de estructuras de control para seleccionar operaciones de creación, consulta y adición de registros.

## Objetivo
Aprender a crear, leer, escribir y actualizar archivos en C++, comprendiendo las diferencias entre los archivos de texto y los binarios, para almacenar y recuperar información de forma permanente mediante flujos de archivos, estructuras y menús de opciones.

---

## 📝 Ejercicios

##### 1. Realice un programa que pida al usuario el nombre de un fichero de texto y, a continuación permita almacenar al usuario tantas frases como el usuario desee.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;

void escribirFrases();

int main(){
	escribirFrases();
	
	system("pause");
	return 0;
} 

void escribirFrases(){
	ofstream archivo;
	string nombreArchivo,frase;
	char rpt;
	
	cout<<"Digite el nombre del archivo: ";
	getline(cin,nombreArchivo);
	
	archivo.open(nombreArchivo.c_str(),ios::out); //Creamos el archivo
	
	if(archivo.fail()){ //Si a ocurrido algun error
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	do{
		fflush(stdin);
		cout<<"Digite una frase: ";
		getline(cin,frase);
		archivo<<frase<<endl;
		
		cout<<"\nDesea agregar otra frase(S/N): ";
		cin>>rpt;
	}while((rpt == 'S') || (rpt == 's'));
	
	archivo.close(); //Cerramos el archivo
}
```
</details>

##### 2. Realice un programa que pida al usuario el nombre o ubicacion de un fichero de texto y, a continuación de lectura a todo el fichero. 
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
using namespace std;

void lectura();

int main(){
	lectura();
	
	system("pause");
	return 0;
}

void lectura(){
	ifstream archivo;
	string nombreArchivo,texto;
	
	cout<<"Digite el nombre o la ubicacion del archivo o fichero: ";
	getline(cin,nombreArchivo);
	
	archivo.open(nombreArchivo.c_str(),ios::in); //Abrimos el archivo en modo lectura
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	while(!archivo.eof()){ //mientras no sea final del archivo
		getline(archivo,texto);
		cout<<texto<<endl;
	}
	
	archivo.close(); //Cerramos el archivo
}
```
</details>

##### 3. Realice un programa que pida al usuario el nombre o ubicacion de un fichero de texto y, a continuación añada texto en el hasta que el usuario lo decida. 
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
using namespace std;

void aniadir();

int main(){
	aniadir();
	
	system("pause");
	return 0;
}

void aniadir(){
	ofstream archivo;
	string nombreArchivo,texto;
	char rpt;
	
	cout<<"Digite el nombre o ubicacion del archivo: ";
	getline(cin,nombreArchivo);
	
	archivo.open(nombreArchivo.c_str(),ios::app); //Abrimos el archivo en modo a�adir
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	do{
		fflush(stdin);
		cout<<"Digite una frase: ";
		getline(cin,texto);
		archivo<<texto<<endl;
		
		cout<<"Desea agregar otra frase? (s/n): ";
		cin>>rpt;
	}while((rpt == 'S') || (rpt == 's'));
	
	archivo.close();
}
```
</details>

##### 4. Hacer un programa en C++. Para guardar numeros telefonicos que muestre un menu con las siguientes opciones:
1. **Crear(nombre,apellidos,telefono)**
2. **Agregar mas contactos(nombre,apellidos,telefono)**
3. **Visualizar contactos existentes**
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
using namespace std;

void menu();
void crear_contacto();
void agregar_contacto();
void visualizar_contacto();

struct contacto{
	string nombre,apellido,telefono;
}datos;

int main(){
	menu();	
	
	system("pause");
	return 0;
}

void menu(){
	int opcion;
	
	do{
		cout<<"\t.:MENU:."<<endl;
		cout<<"1. Crear Agenda Telefonica"<<endl;
		cout<<"2. Agregar mas contactos"<<endl;
		cout<<"3. Visualizar contactos existentes"<<endl;
		cout<<"4. Salir"<<endl;
		cout<<"Opcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 1: crear_contacto();
					cout<<"\n";
					system("pause");
					break;
			case 2: agregar_contacto();
					cout<<"\n";
					system("pause");
					break;
			case 3: visualizar_contacto();
					cout<<"\n";
					system("pause");
					break;
		}
		system("cls");
	}while(opcion!=4);
}

//Funcion para crear un contacto
void crear_contacto(){
	ofstream archivo;
	char rpt;
	
	archivo.open("AgendaTelefonica.txt",ios::out); //Abrimos el archivo en modo escritura
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	archivo<<"\tAgenda Telefonica\n\n";
	
	do{
		fflush(stdin);
		cout<<"\nDigite su nombre: ";
		getline(cin,datos.nombre);
		cout<<"Digite su Apellido: ";
		getline(cin,datos.apellido);
		cout<<"Digite su Telefono: ";
		getline(cin,datos.telefono);
	
		archivo<<"Nombre: "<<datos.nombre<<endl;
		archivo<<"Apellido: "<<datos.apellido<<endl;
		archivo<<"Telefono: "<<datos.telefono<<endl<<endl;
		
		cout<<"\nDesea Agregar otro contacto: ";
		cin>>rpt;
	}while((rpt == 'S') || (rpt == 's'));
	
	archivo.close(); //Cerramos el archivo	
}

//Funcion para agregar más contactos
void agregar_contacto(){
	ofstream archivo;
	char rpt;
	
	archivo.open("AgendaTelefonica.txt",ios::app); //Abrimos el archivo en modo agregar
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	do{
		fflush(stdin);
		cout<<"\nNombre: "; getline(cin,datos.nombre);
		cout<<"Apellido: "; getline(cin,datos.apellido);
		cout<<"Telefono: "; getline(cin,datos.telefono);
	
		archivo<<"Nombre: "<<datos.nombre<<endl;
		archivo<<"Apellido: "<<datos.apellido<<endl;
		archivo<<"Telefono: "<<datos.telefono<<endl<<endl;
	
		cout<<"\nDesea Agregar otro contacto: ";
		cin>>rpt;
	}while((rpt == 'S') || (rpt == 's'));
	
	archivo.close(); //Cerramos el archivo
}

void visualizar_contacto(){
	ifstream archivo;
	string texto;
	
	archivo.open("AgendaTelefonica.txt",ios::in); //Abrimos el archivo en modo lectura
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	while(!archivo.eof()){ //mientras no sea el final de archivo
		getline(archivo,texto);
		cout<<texto<<endl;
	}
	
	archivo.close(); //Cerramos el archivo
}
```
</details>

##### 5. Crear un archivo binario donde almacenar un Registro que contenga las pulsaciones de un atleta en una determinada hora, el programa debe tener un menú con las siguientes opciones: 
1. **Comenzar a digitar las pulsaciones**
2. **Añadir mas pulsaciones**
3. **Mostrar las pulsaciones registradas**
4. **Salir**
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

void menu();
void escribirPulsacion();
void aniadirPulsacion();
void mostrarPulsaciones();

struct Registro{
	float hora;
	int pulsaciones;
};

int main(){
	menu();
	
	getch();
	return 0;
}

void menu(){
	int opcion;
	
	do{
		cout<<"\t.:MENU:."<<endl;
		cout<<"1. Comenzar a digitar las pulsaciones"<<endl;
		cout<<"2. Añadir mas pulsaciones"<<endl;
		cout<<"3. Mostrar las pulsaciones registradas"<<endl;
		cout<<"4. Salir"<<endl;
		cout<<"Digite una opcion: "; cin>>opcion;
		
		switch(opcion){
			case 1: escribirPulsacion();
					break;
			case 2: aniadirPulsacion();
					break;
			case 3: mostrarPulsaciones();
					break;
			case 4: break;
			default: cout<<"Se equivoco de opcion de menu"<<endl;
		}
		
		system("pause");
		system("cls");
	}while(opcion!=4);
}

void escribirPulsacion(){
	ofstream archivoB;
	
	archivoB.open("pulsaciones.dat",ios::out | ios::binary);
	
	if(archivoB.fail()){
		cout<<"No se pudo crear el archivo"<<endl;
		exit(1);
	}
	
	Registro pulso;
	
	cout<<"\nDigite la hora: "; cin>>pulso.hora;
	cout<<"Digite la cantidad de pulsaciones: "; cin>>pulso.pulsaciones;
	
	archivoB.write((char *)&pulso,sizeof(Registro));
	
	archivoB.close();
}

void aniadirPulsacion(){
	ofstream archivoB;
	
	archivoB.open("pulsaciones.dat",ios::app | ios::binary);
	
	if(archivoB.fail()){
		cout<<"No se pudo crear el archivo"<<endl;
		exit(1);
	}
	
	Registro pulso;
	
	cout<<"\nDigite la hora: "; cin>>pulso.hora;
	cout<<"Digite la cantidad de pulsaciones: "; cin>>pulso.pulsaciones;
	
	archivoB.write((char *)&pulso,sizeof(Registro));
	
	archivoB.close();
}

void mostrarPulsaciones(){
	ifstream archivoB;
	
	archivoB.open("pulsaciones.dat",ios::in | ios::binary);
	
	if(archivoB.fail()){
		cout<<"No se pudo crear el archivo"<<endl;
		exit(1);
	}
	
	Registro pulso;
	
	cout<<"\nMostrando Pulsaciones registradas: "<<endl;
	while(!archivoB.eof()){ //Mientras no haya finalizado de recorrer mi archivo
		archivoB.read((char *)&pulso,sizeof(Registro));
		
		if(!archivoB.eof()){
			cout<<"Hora: "<<pulso.hora<<endl;
			cout<<"Pulsaciones: "<<pulso.pulsaciones<<endl<<endl;
		}
	}
	
	archivoB.close();
}
```
</details>