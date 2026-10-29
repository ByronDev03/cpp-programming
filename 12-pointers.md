<h1 align="center">12. Punteros</h1>

<p align="justify">
En esta unidad se estudian los punteros en C++, variables que permiten almacenar direcciones de memoria y acceder indirectamente a los datos almacenados en ellas. Los punteros son fundamentales para comprender cómo se manipula la memoria, cómo se transmiten direcciones entre funciones y cómo se trabaja con estructuras de datos dinámicas. A través de los ejercicios, se aprenderá a declarar e inicializar punteros, obtener direcciones de memoria, acceder a valores mediante la desreferenciación y recorrer arreglos utilizando aritmética de punteros. También se aplicarán estos conocimientos en la reserva dinámica de memoria, el procesamiento de cadenas y matrices, y el acceso a los miembros de estructuras mediante punteros.

## Conceptos principales
- **Declaración de punteros:** utilización del operador `*` para declarar variables que almacenan direcciones de memoria.
- **Direcciones de memoria:** uso del operador `&` para obtener la dirección de una variable.
- **Desreferenciación:** utilización del operador `*` para acceder al valor almacenado en la dirección a la que apunta un puntero.
- **Punteros y arreglos:** recorrido y manipulación de los elementos de un arreglo mediante punteros y aritmética de direcciones.
- **Aritmética de punteros:** incremento de punteros y acceso a posiciones consecutivas de arreglos.
- **Transmisión de direcciones a funciones:** envío de direcciones como argumentos para permitir que una función acceda o modifique variables originales.
- **Intercambio de valores mediante punteros:** utilización de direcciones y variables auxiliares para intercambiar el contenido de dos variables.
- **Asignación dinámica de memoria:** utilización de `new` para reservar memoria durante la ejecución y de `delete` o `delete[]` para liberarla.
- **Arreglos y matrices dinámicas:** creación y manipulación de arreglos de tamaño variable y matrices mediante punteros.
- **Punteros a cadenas de caracteres:** recorrido de cadenas mediante punteros y análisis de sus caracteres para contar vocales.
- **Punteros a estructuras:** acceso a los miembros de estructuras mediante el operador `->` y procesamiento de registros.
- **Transmisión de arreglos a funciones:** envío de arreglos mediante punteros para realizar operaciones como encontrar el máximo, ordenar elementos o buscar valores.

## Objetivo
Comprender cómo funcionan los punteros en C++, utilizar direcciones de memoria para acceder y modificar datos, y aplicar la aritmética de punteros y la asignación dinámica de memoria en arreglos, cadenas, matrices y estructuras, desarrollando programas que manipulen información de forma indirecta y eficiente.

## Ejercicios

##### 1. Comprobar si un número es par o impar, y señalar la posicion de memoria donde se está guardando el número. Con punteros.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

int main(){
	int numero, *dir_numero;
	
	cout<<"Digite un numero: "; cin>>numero; //Pedimos el numero al usuario
	
	dir_numero = &numero;
	
	if(*dir_numero%2==0){
		cout<<"El numero: "<<*dir_numero<<" es par"<<endl;
		cout<<"Posicion: "<<dir_numero<<endl;
	}
	else{
		cout<<"El numero: "<<*dir_numero<<" es impar"<<endl;
		cout<<"Posicion: "<<dir_numero<<endl;
	}
	
	getch();
	return 0;
}
```
</details>

##### 2. Determinar si un número es primo o no; con puteros y además indicar en que posicion de memoria se guardo el número.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

int main(){
	int numero,*dir_num,cont=0;
	
	cout<<"Digite un numero: "; //Pedimos y guardamos el numero
	cin>>numero;
	
	dir_num = &numero; //Almacenamos su direccion
	
	//Determinamos si es primo o no
	for(int i=1;i<*dir_num;i++){
		if(*dir_num%i == 0){
			cont++;
		}
	}
	
	if(cont>2){
		cout<<"El numero "<<*dir_num<<" NO es primo"<<endl;
	}
	else{
		cout<<"El numero "<<*dir_num<<" ES PRIMO"<<endl;
		cout<<"Direccion: "<<dir_num<<endl; //Mostramos su direccion en memoria
	}
	
	getch();
	return 0;
}
```
</details>

##### 3. Rellenar un array de 10 números, posteriormente utilizando punteros indicar cuales son números pares y su posicion en memoria.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

int main(){
	int numeros[10], *dir_numeros;
	
	for(int i=0;i<10;i++){//Pidiendo los n�meros al usuario
		cout<<i+1<<". Digite un numero: ";
		cin>>numeros[i];
	}
	
	dir_numeros = numeros; //indicar al puntero que inicie en a[0]
	
	for(int i=0;i<10;i++){
		if(*dir_numeros%2==0){//Comprobar n�meros pares
			cout<<"Numero par: "<<*dir_numeros<<endl;
			cout<<"Posicion: "<<dir_numeros<<endl;
		}
		dir_numeros++;
	}
	
	getch();
	return 0;
}
```
</details>

##### 4. Rellenar un arreglo con n numeros, posteriormente utilizando punteros determinar el menor elemento del vector.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

int main(){
	int nElementos,numeros[100],*dir_numeros,menor=999999;
	
	cout<<"Digite el numero de elementos del arreglo: ";
	cin>>nElementos;
	
	for(int i=0;i<nElementos;i++){
		cout<<i+1<<". Digite un numero: ";
		cin>>numeros[i]; //Guardamos los elementos en el arreglo
	}
	
	dir_numeros = numeros;
	
	for(int i=0;i<nElementos;i++){//Determinamos el menor elemento en cada
		if(*dir_numeros < menor){//iteracion del bucle
			menor = *dir_numeros;
		}
		dir_numeros++;
	}
	
	cout<<"\nEl menor elemento es: "<<menor<<endl;
	
	getch();
	return 0;
}
```
</details>

##### 5. Pedir al usuario N números, almacenarlos en un arreglo dinámico posteriormente ordenar los números en orden ascendente y mostrarlos en pantalla. NOTA: Utilizar cualquier método de ordenamiento.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

//Prototipos de Funciones
void pedirDatos();
void ordenarNumeros(int *,int);
void mostrarArregloOrdenado(int *,int);

int nElementos, *elemento;

int main(){
	pedirDatos();
	ordenarNumeros(elemento,nElementos);	
	mostrarArregloOrdenado(elemento,nElementos);
	
	delete[] elemento;
	
	getch();
	return 0;
}

void pedirDatos(){//Pedimos los datos al usuario
	cout<<"Digite el numero de elementos: ";
	cin>>nElementos;
	
	elemento = new int[nElementos];
	
	for(int i=0;i<nElementos;i++){
		cout<<"Digite un numero ["<<i<<"]: ";
		cin>>*(elemento+i);
	}
}

void ordenarNumeros(int *elemento,int nElementos){
	int aux;
	
	//Ordenamiento por metodo burbuja con punteros
	for(int i=0;i<nElementos;i++){
		for(int j=0;j<nElementos-1;j++){
			if(*(elemento+j) > *(elemento+j+1)){
				aux = *(elemento+j);
				*(elemento+j) = *(elemento+j+1);
				*(elemento+j+1) = aux;
			}
		}
	}
}

void mostrarArregloOrdenado(int *elemento,int nElementos){//Mostrando Arreglo ordenado
	cout<<"\n\nMostrando Arreglo Ordenado: ";
	for(int i=0;i<nElementos;i++){
		cout<<*(elemento+i)<<" ";
	}
}
```
</details>

##### 6. Hacer una función para almacenar N números en un arreglo dinámico, posteriormente en otra función buscar un número en particular. NOTA: Puedes utilizar cualquier método de búsqueda (Secuencial o Binaria)
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

void pedirDatos();
void busqueda(int *,int);

int nElementos, *elemento;

int main(){
	pedirDatos();
	busqueda(elemento,nElementos);
	
	delete[] elemento; //Liberar memoria utilizada en el arreglo
	
	getch();
	return 0;
}

void pedirDatos(){
	cout<<"Digite el numero de elementos del arreglo: ";
	cin>>nElementos;
	
	elemento = new int[nElementos]; //Crear el arreglo
	
	for(int i=0;i<nElementos;i++){//Pedir datos al usuario para el arreglo
		cout<<"Digite un numero["<<i<<"]: ";
		cin>>*(elemento+i);
	}
}

void busqueda(int *elemento,int nElementos){
	int dato,i;
	bool band=false;
	
	cout<<"\nDigite el numero que quiere buscar: ";
	cin>>dato;
	
	//Busqueda Secuencial
	i=0;
	while((band==false)&&(i<nElementos)){
		if(*(elemento+i)==dato){ //Verificar si existe el numero en el arreglo
			band = true; //Si lo encuentra bandera cambia a Verdadero
		}
		i++;
	}
	
	if(band==false){
		cout<<"El numero "<<dato<<" NO ha sido encontrado"<<endl;
	}
	else{
		cout<<"El numero "<<dato<<" ha sido encontrado en la posicion "<<i-1<<endl;
	}
}
```
</details>

##### 7. Pedir su nombre al usuario y devolver el número de vocales que hay. NOTA: Recuerda que debes utilizar punteros.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

//Prototipo de Función
void pedirDatos();
int contarVocales(char *);

char nombreUsuario[30];

int main(){
	pedirDatos();
	cout<<"\nNumero de vocales en el nombre: "<<contarVocales(nombreUsuario);	
	
	getch();
	return 0;
}

void pedirDatos(){
	cout<<"Digite su nombre: ";
	cin.getline(nombreUsuario,30,'\n');
	
	strupr(nombreUsuario); //Pasar el nombre a mayuscula 
}

int contarVocales(char *nombre){
	int cont = 0;
	
	while(*nombre){ //mientras nombre no sea nulo '\0'
		switch(*nombre){
			case 'A': 
			case 'E':
			case 'I':
			case 'O':
			case 'U': cont++;
		}
		nombre++;
	}
	
	return cont;
}
```
</details>

##### 8. Pedir una cadena de caracteres (string) al usuario, e indicar cuantas veces aparece la vocal a,e,i,o,u; en la cadena de caracteres. NOTA: Usar punteros
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

void pedirDatos();
void contarVocales(char *);

char palabraUsuario[30];

int main(){
	pedirDatos();
	contarVocales(palabraUsuario);//Llamada a la funcion para contar vocales del nombre
	
	getch();
	return 0;
}

void pedirDatos(){
	cout<<"Digite una palabra: ";
	cin.getline(palabraUsuario,30,'\n');
	
	strupr(palabraUsuario); //pasar el nombre a mayuscula
}

void contarVocales(char *palabra){
	int contA=0,contE=0,contI=0,contO=0,contU=0;
	
	while(*palabra){ //mientras nombre sea diferente de nulo '\0'
		switch(*palabra){
			case 'A': contA++;break;
			case 'E': contE++;break;
			case 'I': contI++;break;
			case 'O': contO++;break;
			case 'U': contU++;break;
		}
		palabra++;
	}
	
	//Imprimiendo el conteo de cada vocal
	cout<<"\nNumero de vocales A: "<<contA<<endl;
	cout<<"Numero de vocales E: "<<contE<<endl;
	cout<<"Numero de vocales I: "<<contI<<endl;
	cout<<"Numero de vocales O: "<<contO<<endl;
	cout<<"Numero de vocales U: "<<contU<<endl;
}
```
</details>

##### 9. Realice un programa que calcule la suma de dos matrices dinámicas. 
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

void pedirDatos();
void sumarMatrices(int **,int **,int,int);
void mostrarMatrizSuma(int **,int,int);

int **puntero_matriz1,**puntero_matriz2,nFilas,nCol;

int main(){
	pedirDatos();
	sumarMatrices(puntero_matriz1,puntero_matriz2,nFilas,nCol);
	mostrarMatrizSuma(puntero_matriz1,nFilas,nCol);
	
	//Liberar la memoria utiliza en matriz2
	for(int i=0;i<nFilas;i++){
		delete[] puntero_matriz2[i];
	}
	delete[] puntero_matriz2;
	
	//Liberar la memoria utiliza en matriz1
	for(int i=0;i<nFilas;i++){
		delete[] puntero_matriz1[i];
	}
	delete[] puntero_matriz1;
	
	getch();
	return 0;
}

void pedirDatos(){
	cout<<"Digite el numero de filas: ";
	cin>>nFilas;
	cout<<"Digite el numero de columnas: ";
	cin>>nCol;
	
	//Reservar memoria para la primera matriz
	puntero_matriz1 = new int*[nFilas]; //Reservar memoria para las filas
	for(int i=0;i<nFilas;i++){
		puntero_matriz1[i] = new int[nCol]; //Reservar memoria para las columnas
	}
	
	cout<<"\nDigitando los elementos de la primera matriz: \n";
	for(int i=0;i<nFilas;i++){
		for(int j=0;j<nCol;j++){
			cout<<"Digite un numero["<<i<<"]["<<j<<"]: ";
			cin>>*(*(puntero_matriz1+i)+j); //puntero_matriz1[i][j]
		}
	}
	
	//Reservar memoria para la segunda matriz
	puntero_matriz2 = new int*[nFilas]; //Reservar memoria para las filas
	for(int i=0;i<nFilas;i++){
		puntero_matriz2[i] = new int[nCol]; //Reservar memoria para las columnas
	}
	
	cout<<"\nDigitando los elementos de la segunda matriz: \n";
	for(int i=0;i<nFilas;i++){
		for(int j=0;j<nCol;j++){
			cout<<"Digite un numero["<<i<<"]["<<j<<"]: ";
			cin>>*(*(puntero_matriz2+i)+j); //puntero_matriz1[i][j]
		}
	}
}

void sumarMatrices(int **puntero_matriz1,int **puntero_matriz2,int nFilas,int nCol){
	for(int i=0;i<nFilas;i++){
		for(int j=0;j<nCol;j++){
			*(*(puntero_matriz1+i)+j) += *(*(puntero_matriz2+i)+j);  
		}//puntero_matriz[i][j] = puntero_matriz[i][j]+puntero_matriz2[i][j];
	}
}

void mostrarMatrizSuma(int **putero_matriz1,int nFilas,int nCol){
	cout<<"\nLa suma de ambas matrices es: \n";
	for(int i=0;i<nFilas;i++){
		for(int j=0;j<nCol;j++){
			cout<<*(*(puntero_matriz1+i)+j)<<" ";
		}
		cout<<"\n";
	}
}
```
</details>

##### 10. Realice un programa que lea una matriz dinámica de NxM y cree su matriz traspuesta. La matriz traspuesta es aquella en la que la columna i era la fila i de la matriz original.
```text
|1 2 3|       |1 4 7|
|4 5 6|  -->  |2 5 8|
|7 8 9|       |3 6 9|
```
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

void pedirDatos();
void mostrarMatriz(int **,int,int);

int **puntero_matriz,nFilas,nCol;

int main(){
	pedirDatos();
	mostrarMatriz(puntero_matriz,nFilas,nCol);
	
	//Liberando memoria de la matriz
	for(int i=0;i<nFilas;i++){
		delete[] puntero_matriz[i];
	}
	delete[] puntero_matriz;
	
	getch();
	return 0;
}

void pedirDatos(){
	cout<<"Digite el numero de filas: ";
	cin>>nFilas;
	cout<<"Digite el numero de columnas: ";
	cin>>nCol;
	
	//Reservar memoria para la matriz dinámica
	puntero_matriz = new int*[nFilas]; //Reservando memoria para las filas
	for(int i=0;i<nFilas;i++){
		puntero_matriz[i] = new int[nCol]; //Reservando memoria para las columnas
	}
	
	cout<<"\nDigitando datos para la matriz: \n";
	for(int i=0;i<nFilas;i++){
		for(int j=0;j<nCol;j++){
			cout<<"Digite un numero["<<i<<"]["<<j<<"]: ";
			cin>>*(*(puntero_matriz+i)+j);
		}
	}	
}

void mostrarMatriz(int **puntero_matriz,int nFilas,int nCol){
	cout<<"\nMostrando matriz Original: \n";
	for(int i=0;i<nFilas;i++){
		for(int j=0;j<nCol;j++){
			cout<<*(*(puntero_matriz+i)+j)<<" "; //puntero_matriz[i][j]
		}
		cout<<"\n";
	}
	
	cout<<"\nMostrando matriz Transpuesta: \n";
	for(int i=0;i<nFilas;i++){
		for(int j=0;j<nCol;j++){
			cout<<*(*(puntero_matriz+j)+i)<<" "; //puntero_matriz[j][i]
		}
		cout<<"\n";
	}
}
```
</details>

##### 11. Hacer una estructura llamada alumno, en la cual se tendrán los siguientes Campos: Nombre, edad, promedio, pedir datos al usuario para 3 alumnos, comprobar cuál de los 3 tiene el mejor promedio y posteriormente imprimir los datos del alumno. NOTA: Usar punteros a estructura
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

struct Alumno{
	char nombre[30];
	int edad;
	float promedio;
}alumno[3], *puntero_alumno = alumno;

void pedirDatos();
void comprobarMejorPromedio(Alumno *);

int main(){
	pedirDatos();	
	comprobarMejorPromedio(puntero_alumno);
	
	getch();
	return 0;
}

void pedirDatos(){
	for(int i=0;i<3;i++){
		fflush(stdin); //Limpiar buffer para poder seguir digitando datos
		cout<<"Digite su nombre: ";
		cin.getline((puntero_alumno+i)->nombre,30,'\n');
		cout<<"Digite su edad: ";
		cin>>(puntero_alumno+i)->edad;
		cout<<"Digite su promedio: ";
		cin>>(puntero_alumno+i)->promedio;
		cout<<"\n";
	}
}

void comprobarMejorPromedio(Alumno *puntero_alumno){
	float mayor = 0.0;
	int pos=0;
	
	for(int i=0;i<3;i++){
		if((puntero_alumno+i)->promedio > mayor){
			mayor = (puntero_alumno+i)->promedio;//sacamos el mayor promedio
			pos = i;// guardamos la posicion del mayor promedio
		}
	}
	
	//Imprimimos los datos del alumno con el mejor promedio	
	cout<<"\nAlumno con el mejor promedio: "<<endl;
	cout<<"Nombre: "<<(puntero_alumno+pos)->nombre<<endl;
	cout<<"Edad: "<<(puntero_alumno+pos)->edad<<endl;
	cout<<"Promedio: "<<(puntero_alumno+pos)->promedio<<endl;	
}
```
</details>

##### 12. Defina una estructura que indique el tiempo empleado por un ciclista en recorrer una etapa. La estructura debe tener tres campos: horas, minutos y segundos. Escriba un programa que dado 3 etapas calcule el tiempo total empleado en correr todas las etapas. NOTA: Usar punteros.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

struct Etapa{
	int horas,min,seg;
}etapa[3], *puntero_etapa = etapa;

//Prototipos de Funcion
void pedirDatos();
void calcularTiempo(Etapa *);

int main(){
	pedirDatos();
	calcularTiempo(puntero_etapa);
	
	getch();
	return 0;
}

void pedirDatos(){
	cout<<"Digite los tiempos empleados: \n";	
	for(int i=0;i<3;i++){
		cout<<"Horas: "; cin>>(puntero_etapa+i)->horas;
		cout<<"Minutos: "; cin>>(puntero_etapa+i)->min;
		cout<<"Segundos: "; cin>>(puntero_etapa+i)->seg;
		cout<<"\n";
	}
}

void calcularTiempo(Etapa *puntero_etapa){
	int horasT=0,minutosT=0,segundosT=0;
	
	for(int i=0;i<3;i++){
		horasT += (puntero_etapa+i)->horas; //horasT = horasT + puntero_etapa[i].horas
		minutosT += (puntero_etapa+i)->min;
		if(minutosT >= 60){//Si los minutos son mayores a 60, significa que ha pasado
			minutosT -= 60;//mas de 1 hora, entonces disminuimos en 60 los minutos
			horasT++;//y aumentamos las horas en 1
		}
		segundosT += (puntero_etapa+i)->seg;
		if(segundosT >= 60){//y lo mismo con los segundos
			segundosT -= 60;
			minutosT++; 
		}
	}
	
	//Por ultimo mostramos los totales de tiempos en pantalla
	cout<<"\nEl tiempo total es: "<<endl;
	cout<<"Horas: "<<horasT<<endl;
	cout<<"Minutos: "<<minutosT<<endl;
	cout<<"Segundos: "<<segundosT<<endl;
}
```
</details>

##### 13. Punteros a Estructuras
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

struct Persona{
	char nombre[30];
	int edad;
}persona, *puntero_persona = &persona;

void pedirDatos(); //Prototipo de Funcion
void mostrarDatos(Persona *);

int main(){
	pedirDatos();
	mostrarDatos(puntero_persona);
	
	getch();
	return 0;
}

void pedirDatos(){
	cout<<"Digite su nombre: ";
	cin.getline(puntero_persona->nombre,30,'\n');
	cout<<"Digite su edad: ";
	cin>>puntero_persona->edad;
}

void mostrarDatos(Persona *puntero_persona){
	cout<<"\nSu nombre es: "<<puntero_persona->nombre<<endl;
	cout<<"Su edad es: "<<puntero_persona->edad<<endl;
}
```
</details>

##### 14. Transmisión de Arreglos
##### Ejemplo: Hallar el máximo elemento de un arreglo.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

//Prototipo de Funcion
int hallarMax(int *,int);

int main(){
	const int nElementos = 5;
	int numeros[nElementos] = {3,5,18,24,1};
	
	cout<<"El maximo elemento es: "<<hallarMax(numeros,nElementos);
	
	getch();
	return 0;
}

int hallarMax(int *dirVec,int nElementos){
	int max=0; 
	
	for(int i=0;i<nElementos;i++){
		if(*(dirVec+i) > max){
			max = *(dirVec+i);
		}
	}
	
	return max;
}
```
</details>

##### 15. Transmisión de Direcciones
##### Ejemplo: Intercambiar el valor de 2 variables.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

//Prototipo de Función
void intercambio(float *,float *);

int main(){
	float num1 = 20.5, num2 = 6.78;
	
	cout<<"Primer Numero: "<<num1<<endl;
	cout<<"Segundo Numero: "<<num2<<endl;
	
	intercambio(&num1,&num2); //llamando a la función intercambio
	
	cout<<"\nLuego del intercambio: "<<endl;
	cout<<"Nuevo valor de num1: "<<num1<<endl;
	cout<<"Nuevo valor de num2: "<<num2<<endl;	
	
	getch();
	return 0;
}

void intercambio(float *dirNm1, float *dirNm2){
	float aux;
	
	aux = *dirNm1;     //Guarda el valor de num1
	*dirNm1 = *dirNm2; //Mueve el valor de num2 a num1
	*dirNm2 = aux;     //Cambia el valor a num2
}
```
</details>

##### 16. Declaración de Punteros
- **&n = La direccion de n**
- **n = la variable cuya direccion esta almacenada en n**
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

int main(){
	int num,*dir_num;
	
	num = 20;
	dir_num = &num;
	
	cout<<"Numero: "<<num<<endl;
	cout<<"Direccion de num: "<<*dir_num<<endl;
	
	getch();
	return 0;
}
```
</details>

##### 17. Correspondencia entre arrays y punteros
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

int main(){
	int numeros[] = {1,10,32,2,5};
	int *p_numeros;
	
	p_numeros = numeros; 
	
	for(int i=0;i<5;i++){
		cout<<*p_numeros++<<endl;
	}
	
	getch();
	return 0;
}
```
</details>

##### 18. Asignación dinamica de arreglos
- **new : Reserva el número de bytes solicitado por la declaración.**
- **delete : Libera un bloque de bytes reservado con anterioridad.**
##### Ejemplo: Pedir al usuario n calificaciones y almacenarlos en un arreglo dinamico
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

void pedirNotas();
void mostrarNotas();

int numCalif, *calif;

int main(){
	pedirNotas();
	mostrarNotas();	
	
	getch();
	return 0;
}

void pedirNotas(){	
	cout<<"Digite el numero de calificaciones: ";
	cin>>numCalif;
	
	calif = new int[numCalif];
	
	for(int i=0;i<numCalif;i++){
		cout<<"Introduzca una nota: ";
		cin>>calif[i];
	}
}

void mostrarNotas(){
	cout<<"\n\nMostrando notas: \n";
	for(int i=0;i<numCalif;i++){
		cout<<calif[i]<<endl;
	}
}
```
</details>

##### 19. Matrices Dinámicas 
##### Ejemplo: Rellenar una matriz de NxM y mostrar su contenido 
```text
puntero_matriz ->  *puntero_fila -> [int] [int] [int] 
		*puntero_fila -> [int] [int] [int]
		*puntero_fila -> [int] [int] [int]
```
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

void pedirDatos();
void mostrarMatriz(int **,int,int);

int nFilas,nCol,**puntero_matriz;

int main(){	
	pedirDatos();
	mostrarMatriz(puntero_matriz,nFilas,nCol);
		
	//Elimino cada vector de la matriz
	for(int i=0;i<nFilas;i++){
		delete[] puntero_matriz[i];
	}
	
	//Elimino el vector principal
	delete[] puntero_matriz;
	
	getch();
	return 0;
}

void pedirDatos(){
	cout<<"Digite el numero de filas: ";
	cin>>nFilas;
	cout<<"Digite el numero de columnas: ";
	cin>>nCol;
	
	//Reservar memoria para las filas
	puntero_matriz = new int*[nFilas];
	
	for(int i=0;i<nFilas;i++){
		//Reservar memoria para las columnas
		puntero_matriz[i] = new int[nCol];
	}
	
	cout<<"\nDigitando los elementos de la matriz: \n";
	for(int i=0;i<nFilas;i++){
		for(int j=0;j<nCol;j++){
			cout<<"Digite un numero["<<i<<"]["<<j<<"]: ";
			cin>>*(*(puntero_matriz+i)+j);
		}
	}
}

void mostrarMatriz(int **puntero_matriz,int nFilas,int nCol){
	cout<<"\n\nElementos de la matriz: \n";
	for(int i=0;i<nFilas;i++){
		for(int j=0;j<nCol;j++){
			cout<<*(*(puntero_matriz+i)+j)<<" ";
		}
		cout<<"\n";
	}	
}
```
</details>