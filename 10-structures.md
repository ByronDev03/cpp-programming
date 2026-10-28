<h1 align="center">10. Estructuras</h1>

<p align="justify">
En esta unidad se estudian las estructuras en C++, un mecanismo que permite agrupar diferentes datos bajo un mismo tipo, incluso cuando sus campos tienen distintos tipos de datos. Las estructuras facilitan la representación de entidades del mundo real, como corredores, alumnos, empleados, atletas y personas, mediante la organización de sus atributos en un solo registro. A través de los ejercicios, se aprenderá a declarar estructuras, acceder a sus miembros, almacenar múltiples registros en arreglos de estructuras y combinar estructuras mediante el anidamiento. También se utilizarán ciclos y condiciones para procesar la información, comparar registros, calcular resultados y organizar datos según determinados criterios.
</p>

## Conceptos principales
- **Declaración de estructuras:** utilización de `struct` para definir tipos de datos personalizados con varios campos.
- **Miembros de una estructura:** acceso y modificación de los campos mediante el operador punto (`.`).
- **Arreglos de estructuras:** almacenamiento y procesamiento de múltiples registros del mismo tipo, como alumnos, empleados o atletas.
- **Lectura y visualización de datos:** captura de información de cada registro y presentación de sus campos en pantalla.
- **Comparación de registros:** identificación de valores máximos y mínimos, como el mejor promedio, el salario más alto o el mayor número de medallas.
- **Estructuras anidadas:** inclusión de una estructura dentro de otra para organizar información relacionada, como los datos personales de un alumno y sus calificaciones.
- **Cálculos con estructuras:** utilización de los campos para calcular promedios y acumular tiempos expresados en horas, minutos y segundos.
- **Clasificación de registros:** distribución de los datos en diferentes arreglos según condiciones específicas, como la presencia o ausencia de una discapacidad.
- **Recorrido de arreglos de estructuras:** utilización de ciclos `for` para leer, comparar, procesar y mostrar múltiples registros.
- **Uso de condiciones y variables auxiliares:** selección de registros que cumplen determinados criterios y almacenamiento de sus posiciones dentro de un arreglo.

## Objetivo
Comprender cómo definir y utilizar estructuras en C++ para representar información relacionada, almacenar múltiples registros y procesar sus campos mediante arreglos, ciclos y condiciones, desarrollando programas que permitan comparar datos, realizar cálculos y organizar información de manera estructurada.

- **Estructuras** → [Ver apunte](/notes/structures.md) 
- **Estructuras Anidadas** → [Ver apunte](/notes/nested-structures.md)

## Ejercicios

##### 1. Hacer una estructura llamada corredor, en la cual se tendrán los siguientes campos: Nombre, edad, sexo, club, pedir datos al usuario para un corredor, y asignarle una categoría de competición: 
- **Juvenil <= 18 años**
- **Señor <= 40 años**
- **Veterano > 40 años**

##### Posteriormente imprimir todos los datos del corredor, incluida su categoría de competición.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
struct Corredor{
	char nombre[20];
	int edad;
	char sexo[10];
	char club[20];
}c1;

int main(){
	char categoria[20];
	
	cout<<"Nombre: "; cin.getline(c1.nombre,20,'\n');
	cout<<"Edad: "; cin>>c1.edad;
	fflush(stdin);
	cout<<"Sexo: "; cin.getline(c1.sexo,10,'\n');
	cout<<"Club: "; cin.getline(c1.club,20,'\n');
	
	if(c1.edad <= 18){
		strcpy(categoria,"Juvenil");
	}	
	else if(c1.edad <= 40){
		strcpy(categoria,"Senior");
	}
	else{
		strcpy(categoria,"Veterano");
	}
	
	cout<<"\n\nMostrando Datos"<<endl;
	cout<<"Nombre: "<<c1.nombre<<endl;
	cout<<"Edad: "<<c1.edad<<endl;
	cout<<"Sexo: "<<c1.sexo<<endl;
	cout<<"Club: "<<c1.club<<endl;
	cout<<"Categoria: "<<categoria<<endl;
	
	getch();
	return 0;
}
```
</details>

##### 2. Hacer una estructura llamada alumno, en la cual se tendrán los siguientes Campos: Nombre, edad, promedio, pedir datos al usuario para 3 alumnos, comprobar cuál de los 3 tiene el mejor promedio y posteriormente imprimir los datos del alumno.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;
struct Alumno{
	char nombre[20];
	int edad;
	float promedio;
}alumnos[3];

int main(){
	int mayor = 0,pos=0;
	
	//Pedir los datos para 3 alumnos
	for(int i=0;i<3;i++){
		fflush(stdin);
		cout<<"Nombre: "; cin.getline(alumnos[i].nombre,20,'\n');
		cout<<"Edad: "; cin>>alumnos[i].edad;
		cout<<"Promedio: "; cin>>alumnos[i].promedio;
		
		if(alumnos[i].promedio > mayor){
			mayor = alumnos[i].promedio; //sacamos el mayor promedio
			pos = i; // guardamos la posicion del mayor promedio
		}
		cout<<"\n";
	}
	
	//Imprimimos los datos del alumno con el mejor promedio
	cout<<"\nAlumnos con el mejor Promedio: \n";
	cout<<"Nombre: "<<alumnos[pos].nombre<<endl;
	cout<<"Edad: "<<alumnos[pos].edad<<endl;
	cout<<"Promedio: "<<alumnos[pos].promedio<<endl;
	
	getch();
	return 0;
}
```
</details>

##### 3. Realizar un programa que lea un arreglo de estructuras los datos de N empleados de la empresa y que imprima los datos del empleado con mayor y menor salario.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

struct Empleado{
	char nombre[20];
	float salario;	
}e[100];

int main(){
	int n_empleados,mayor=0,menor=999999,posM,posm;
	
	cout<<"Digite el numero de empleados: "; cin>>n_empleados;
	
	for(int i=0;i<n_empleados;i++){
		fflush(stdin); //Vacias el buffer y poder digitar mas valores
		cout<<"Nombre: "; cin.getline(e[i].nombre,20,'\n');
		cout<<"Salario: "; cin>>e[i].salario;
		
		//Empleado con mayor salario
		if(e[i].salario > mayor){
			mayor = e[i].salario;
			posM = i;
		}
		//Empleado con menor salario
		if(e[i].salario < menor){
			menor  = e[i].salario;
			posm = i;
		}		
		cout<<"\n";
	}
	
	cout<<"\nEmpleado con mayor salario: "<<endl;
	cout<<"Nombre: "<<e[posM].nombre<<endl;
	cout<<"Salario: "<<e[posM].salario<<endl;
	
	cout<<"\nEmpleado con menor salario: "<<endl;
	cout<<"Nombre: "<<e[posm].nombre<<endl;
	cout<<"Salario: "<<e[posm].salario<<endl;
	
	getch();
	return 0;
}
```
</details>

##### 4. Hacer un arreglo de estructura llamada atleta para N atletas que contenga los siguientes campos: nombre, país, numero_medallas. y devuelva los datos (Nombre, país) del atleta que ha ganado el mayor número de medallas.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

struct Atleta{
	char nombre[20];
	char pais[20];
	int n_medallas;
}atletas[100];

int main(){
	int n_atletas,mayor = 0,posM=0;
	
	cout<<"Digite el numero de atletas: ";
	cin>>n_atletas;
	
	//Pedimos los datos para N atletas
	for(int i=0;i<n_atletas;i++){
		fflush(stdin);
		cout<<"Nombre: "; cin.getline(atletas[i].nombre,20,'\n');
		cout<<"Pais: "; cin.getline(atletas[i].pais,20,'\n');
		cout<<"Numero de Medallas: "; cin>>atletas[i].n_medallas;

		//Sacando el atleta con mayor numero de medallas
		if(atletas[i].n_medallas > mayor){
			mayor = atletas[i].n_medallas;
			posM = i;
		}
		cout<<"\n";
	}
	
	cout<<"\nAtleta con mas medallas ganadas: \n";
	cout<<"Nombre: "<<atletas[posM].nombre<<endl;
	cout<<"Pais: "<<atletas[posM].pais<<endl;
	
	getch();
	return 0;
}
```
</details>

##### 5. Hacer 2 estructuras una llamada promedio que tendrá los siguientes campos: nota1, nota2, nota3; y otro llamada alumno que tendrá los siguientes miembros: nombre, sexo, edad; hacer que la estructura promedio este anidada en la estructura alumno, luego pedir todos los datos para un alumno, luego calcular su promedio, y por ultimo imprimir todos sus datos incluidos el promedio.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

struct Promedio{
	float nota1;
	float nota2;
	float nota3;
};

struct Alumno{
	char nombre[20];
	char sexo[10];
	int edad;
	struct Promedio prom;
}alumno1;

int main(){
	float promedio_alumno;
	
	cout<<"Nombre: "; cin.getline(alumno1.nombre,20,'\n');
	cout<<"Sexo: "; cin.getline(alumno1.sexo,10,'\n');
	cout<<"Edad: "; cin>>alumno1.edad;
	
	cout<<".:Notas del Examen:."<<endl;
	cout<<"Nota1: "; cin>>alumno1.prom.nota1;
	cout<<"Nota2: "; cin>>alumno1.prom.nota2;
	cout<<"Nota3: "; cin>>alumno1.prom.nota3;
	
	//Sacando el promedio del alumno
	promedio_alumno = (alumno1.prom.nota1+alumno1.prom.nota2+alumno1.prom.nota3)/3;
	
	cout<<"\n\nMostrando Datos"<<endl;
	cout<<"Nombre: "<<alumno1.nombre<<endl;
	cout<<"Sexo: "<<alumno1.sexo<<endl;
	cout<<"Edad: "<<alumno1.edad<<endl;
	cout<<"Promedio: "<<promedio_alumno<<endl;
	
	getch();
	return 0;
}
```
</details>

##### 6. Utilizar las 2 estructuras del problema 5, pero ahora pedir los datos para N alumnos, y calcular cuál de todos tiene el mejor promedio, e imprimir sus datos.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

struct Promedio{
	float nota1;
	float nota2;
	float nota3;
};

struct Alumno{
	char nombre[20];
	char sexo[10];
	int edad;
	struct Promedio prom;
}alumnos[100];

int main(){
	int n_alumnos,posM=0;
	float promedio_alumno[100],mayor=0;
	
	cout<<"Digite el numero de alumnos: ";
	cin>>n_alumnos;
	
	for(int i=0;i<n_alumnos;i++){
		fflush(stdin);
		cout<<"Nombre: "; cin.getline(alumnos[i].nombre,20,'\n');
		cout<<"Sexo: "; cin.getline(alumnos[i].sexo,10,'\n');
		cout<<"Edad: "; cin>>alumnos[i].edad;
	
		cout<<".:Notas del Examen:."<<endl;
		cout<<"Nota1: "; cin>>alumnos[i].prom.nota1;
		cout<<"Nota2: "; cin>>alumnos[i].prom.nota2;
		cout<<"Nota3: "; cin>>alumnos[i].prom.nota3;
	
		//Sacando el promedio del alumno
		promedio_alumno[i] = (alumnos[i].prom.nota1+alumnos[i].prom.nota2+alumnos[i].prom.nota3)/3;
		
		if(promedio_alumno[i] > mayor){
			mayor = promedio_alumno[i];
			posM = i;
		}
		cout<<"\n";
	}
	
	cout<<"\n\nMostrando Datos del alumno con mejor Promedio"<<endl;
	cout<<"Nombre: "<<alumnos[posM].nombre<<endl;
	cout<<"Sexo: "<<alumnos[posM].sexo<<endl;
	cout<<"Edad: "<<alumnos[posM].edad<<endl;
	cout<<"Promedio: "<<promedio_alumno[posM];
		
	getch();
	return 0;
}
```
</details>

##### 7. Defina una estructura que indique el tiempo empleado por un ciclista en una etapa. La estructura debe tener tres campos: horas, minutos y segundos. Escriba un programa que dado n etapas calcule el tiempo total empleado en correr todas las etapas.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

struct tiempo_ciclista{
	int horas;
	int minutos;
	int segundos;
}etapa[10];

int main(){
	int n_etapas,horasT=0,minutosT=0,segundosT=0;
	
	cout<<"Digite el numero de etapas: ";
	cin>>n_etapas;
	
	cout<<"\nDigite el tiempo Obtenido:"<<endl;
	
	for(int i=0;i<n_etapas;i++){
		//Pedimos las horas en cada etapa
		cout<<i+1<<". Horas: "; cin>>etapa[i].horas;
		cout<<i+1<<". Minutos: "; cin>>etapa[i].minutos;
		cout<<i+1<<". Segundos: "; cin>>etapa[i].segundos;
		
		horasT = horasT+etapa[i].horas; //Sacamos las horas totales empleadas
		minutosT = minutosT+etapa[i].minutos;
		if(minutosT>=60){//Si los minutos son mayores a 60, significa que ha pasado
			minutosT-=60;//mas de 1 hora, entonces disminuimos en 60 los minutos
			horasT++;//y aumentamos las horas en 1
		}
		segundosT = segundosT+etapa[i].segundos;
		if(segundosT>=60){//y lo mismo hacemos con los segundos
			segundosT-=60;
			minutosT++;
		}
		cout<<"\n";
	}
	
	//Por ultimo mostramos los totales de tiempos en pantalla
	cout<<"\nEl tiempo total es: "<<endl;
	cout<<"Horas: "<<horasT<<endl;
	cout<<"Minutos: "<<minutosT<<endl;
	cout<<"Segundos: "<<segundosT<<endl;
	
	getch();
	return 0;
}
```
</details>

##### 8. Defina una estructura que sirva para representar a una persona. La estructura debe contener dos campos: el nombre de la persona y un valor de tipo lógico que indica si la persona tiene algún tipo de discapacidad. Realice un programa que dado un vector de personas rellene dos nuevos vectores: uno que contenga las personas que no tienen ninguna discapacidad y otro que contenga las personas con discapacidad.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

struct Persona_discapacidad{
	char nombre[30];
	bool discapacidad;
}personas[30],personasConD[30],personasSinD[30];
//personasConD = Persona con Discapacidad
//personasSinD = Persona sin Discapacidad

int main(){
	int n_personas,j=0,k=0;
	
	cout<<"Digite el numero de personas: ";
	cin>>n_personas;
	//Rellenar el arreglo de estructuras
	for(int i=0;i<n_personas;i++){
		fflush(stdin);
		cout<<"Nombre : "; cin.getline(personas[i].nombre,30,'\n');
		cout<<"Discapacidad (1/0)? :"; cin>>personas[i].discapacidad;
		
		//Almacenamos las personas con discapacidad
		if(personas[i].discapacidad == 1){
			strcpy(personasConD[j].nombre,personas[i].nombre);
			j++; //Es un nuevo arreglo por lo tanto debe iniciar en 0 y aumentar
		}
		//Almacenamos las personas sin Discapacidad
		else{
			strcpy(personasSinD[k].nombre,personas[i].nombre);
			k++; //Es un nuevo arreglo por lo tanto debe iniciar en 0 y aumentar
		}
		cout<<"\n";
	}
	
	//Mostrar las personas con Discapaciadad
	cout<<"\nPersonas con Discapacidad\n";
	for(int i=0;i<n_personas;i++){
		cout<<personasConD[i].nombre<<endl;
	}
	//Mostrar las personas sin Discapacidad
	cout<<"\nPersonas sin Discapacidad\n";
	for(int i=0;i<n_personas;i++){
		cout<<personasSinD[i].nombre<<endl;
	}
	getch();
	return 0;
}
```
</details>