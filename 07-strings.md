<h1 align="center">7. Cadenas de Caracteres</h1>

<p align="justify">
En esta unidad se estudia el manejo de cadenas de caracteres en C++, que permiten almacenar y procesar texto, como palabras, nombres y frases. Se aprenderá a utilizar la clase `string` de la biblioteca estándar para consultar la longitud de una cadena, acceder a sus caracteres, comparar textos, concatenar cadenas y transformar su contenido. A través de los ejercicios, se aplicarán estas operaciones para resolver problemas como identificar palabras palíndromas, comparar cadenas alfabéticamente, convertir texto entre mayúsculas y minúsculas, contar vocales y convertir cadenas numéricas en valores enteros o reales para realizar operaciones aritméticas.
</p>

## Conceptos principales
- **Arreglos de caracteres:** declaración y utilización de arreglos `char[]` para almacenar cadenas de caracteres.
- **Lectura de cadenas:** uso de `cin.getline()` para leer cadenas completas, incluidos los espacios.
- **Longitud de una cadena:** utilización de `strlen()` para determinar la cantidad de caracteres de una cadena.
- **Copia de cadenas:** uso de `strcpy()` para copiar el contenido de una cadena en otra.
- **Comparación de cadenas:** aplicación de `strcmp()` para determinar si dos cadenas son iguales o cuál es mayor alfabéticamente.
- **Concatenación de cadenas:** utilización de `strcat()` para unir dos cadenas de caracteres.
- **Inversión de cadenas:** uso de `strrev()` para invertir el orden de los caracteres y comprobar si una palabra es un palíndromo.
- **Conversión entre mayúsculas y minúsculas:** aplicación de `strupr()` y `strlwr()` para modificar el uso de mayúsculas y minúsculas en una cadena.
- **Comparación parcial de cadenas:** utilización de `strncmp()` para comparar una cantidad determinada de caracteres.
- **Conversión de cadenas numéricas:** uso de `atoi()` y `atof()` para convertir cadenas de caracteres en valores numéricos enteros y de punto flotante, respectivamente.
- **Recorrido y análisis de cadenas:** utilización de ciclos `for` y estructuras `switch` para contar las apariciones de cada vocal en una cadena.

## Objetivo
Comprender y aplicar las operaciones fundamentales de manipulación de cadenas en C++, desarrollando programas que permitan comparar, concatenar, transformar y analizar texto, así como convertir cadenas numéricas en valores que puedan utilizarse en operaciones aritméticas.

## Ejercicios

##### 1. Hacer un programa que pida al usuario que digite una cadena de caracteres, luego verificar la longitud de la cadena, y si ésta supera a 10 caracteres mostrarla en pantalla, caso contrario no mostrarla.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
int main(){
	char frase[50];
	
	cout<<"Digite una cadena de caracteres: ";
	cin.getline(frase,50,'\n'); //Guardando la cadena de caracteres
	
	if(strlen(frase)>10){
		cout<<frase;
	}
	else{
		cout<<"La cadena no supera los 10 caracteres";
	}
		
	getch();
	return 0;
}
```
</details>

##### 2. Pedir al usuario una cadena de caracteres, almacenarla en un arreglo y copiar todo su contenido hacia otro arreglo de caracteres.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
int main(){
	char frase[20],frase2[20];
	
	cout<<"Digite una cadena de caracteres: "; 
	cin.getline(frase,20,'\n');
	
	strcpy(frase2,frase);
	
	cout<<"Frase: "<<frase2<<endl;
	
	getch();
	return 0;
}
```
</details>

##### 3. Pedir al usuario que digite 2 cadenas de caracteres, e indicar si ambas cadenas son iguales, en caso de no serlo, indicar cual es mayor alfabeticamente.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
int main(){
	char palabra1[20],palabra2[20];
	
	cout<<"Digite una palabra: ";
	cin.getline(palabra1,20,'\n');
	cout<<"Digite otra palabra: ";
	cin.getline(palabra2,20,'\n');
	
	if(strcmp(palabra1,palabra2)==0){
		cout<<"Ambas cadenas son iguales";
	}
	else if(strcmp(palabra1,palabra2)>0){
		cout<<palabra1<<" es mayor alfabeticamente";
	}
	else{
		cout<<palabra2<<" es mayor alfabeticamente";
	}
	
	getch();
	return 0;
} 
```
</details>

##### 4. Crear una cadena que tenga la siguiente frase "Hola que tal", luego crear otra cadena para preguntarle al usuario su nombre, por ultimo añadir el nombre al final de la primera cadena y mostrar el mensaje completo "Hola que tal (NombreDelUsuario)".
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
int main(){
	char cad1[] = "Hola que tal ";
	char cad2[20];
	
	cout<<"Digite su nombre: ";
	cin.getline(cad2,20,'\n');
	
	strcat(cad1,cad2);
	
	cout<<"Frase: "<<cad1<<endl;	
	
	
	getch();
	return 0;
}
```
</details>

##### 5. Hacer un programa que determine si una palabra es palíndromo
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
int main(){
	char palabra[20];
	char palabra2[20];
	
	cout<<"Digite una palabra: ";
	cin.getline(palabra,20,'\n');
	
	strcpy(palabra2,palabra);
	
	strrev(palabra2);
	
	if(strcmp(palabra,palabra2)==0){
		cout<<"Es una palabra polindroma";
	}
	else{
		cout<<"No es una palabra polindroma";
	}	
	
	getch();
	return 0;
}
```
</details>

##### 6. Convertir dos cadena de minusculas a MAYUSCULAS. Compararlas, y decir si son iguales o no.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
int main(){
	char palabra1[30],palabra2[30];
	
	cout<<"Digite una palabra: ";
	cin.getline(palabra1,30,'\n');
	cout<<"Digite una palabra: ";
	cin.getline(palabra2,30,'\n');
	
	strupr(palabra1);
	strupr(palabra2);
	
	if(strcmp(palabra1,palabra2)==0){
		cout<<"\nAmbas cadenas son iguales";
	}
	else{
		cout<<"Las cadenas no son iguales";
	}
	
	getch();
	return 0;
}
```
</details>

##### 7. Pedir su nombre al usuario en MAYÚSCULA, si su nombre comienza por la letra A, convertir su nombre a minusculas, caso contrario no convertirlo.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
int main(){
	char nombre[20];
	
	cout<<"Digite su nombre en MAYUSCULA: ";
	cin.getline(nombre,20,'\n');
	
	if(strncmp(nombre,"A",1)==0){//strncmp compara solo los digitos que le indiques
		strlwr(nombre);
		cout<<nombre<<endl;
	}
	else{
		cout<<"Su nombre no comienza por A";
	}
	
	getch();
	return 0;
}
```
</details>

##### 8. Pedir al usuario 2 cadenas de caracteres de numeros, uno entero y el otro real, convertirlos a sus respectivos valores y por ultimo sumarlos.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
int main(){
	char cad1[10],cad2[10];
	int valorEntero;
	float valorFlotante;
	
	//Guardamos los numeros como cadenas
	cout<<"Digite un numero entero: ";
	cin.getline(cad1,10,'\n');
	cout<<"Digite un numero flotante: ";
	cin.getline(cad2,10,'\n');
	
	//Transformamos las cadenas a numeros
	valorEntero = atoi(cad1);
	valorFlotante = atof(cad2);
	
	//Por ultimo los sumamos
	cout<<"\nLa suma es: "<<valorEntero+valorFlotante<<endl;
	
	getch();
	return 0;
}
```
</details>

##### 9. Realice un programa que lea una cadena de caracteres de la entrada estándar y muestre en la salida estándar cuántas ocurrencias de cada vocal existen en la cadena.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
int main(){
	char frase[30];
	int vocal_a=0,vocal_e=0,vocal_i=0,vocal_o=0,vocal_u=0;
	
	cout<<"Digite una frase: ";
	cin.getline(frase,30,'\n');
	
	for(int i=0;i<30;i++){
		switch(frase[i]){
			case 'a': vocal_a++; break;
			case 'e': vocal_e++; break;
			case 'i': vocal_i++; break;
			case 'o': vocal_o++; break;
			case 'u': vocal_u++; break;
		}
	}
	
	cout<<"\nContador de vocales"<<endl;
	cout<<"Vocal a: "<<vocal_a<<endl;
	cout<<"Vocal e: "<<vocal_e<<endl;
	cout<<"Vocal i: "<<vocal_i<<endl;
	cout<<"Vocal o: "<<vocal_o<<endl;
	cout<<"Vocal u: "<<vocal_u<<endl;
		
	getch();
	return 0;
}
```
</details>