<h1 align="center">1. Introducción y Entrada/Salida</h1>

<p align="justify">
En este bloque se presentan los fundamentos de un programa en C++, desde su estructura básica hasta la interacción con el usuario mediante la entrada y salida estándar. Se aprenderá a declarar variables, utilizar tipos de datos básicos y realizar operaciones sencillas con la información proporcionada durante la ejecución.
</p>

## Conceptos principales
- **Estructura de un programa en C++:** función `main()`, directivas del preprocesador y sentencias.
- **Entrada estándar:** lectura de datos mediante `cin`.
- **Salida estándar:** visualización de información mediante `cout`.
- **Variables y tipos de datos:** uso de tipos como `int`, `char` y `double`.
- **Operadores aritméticos:** suma, resta, multiplicación y división.
- **Conversión de tipos y operaciones básicas:** aplicación de expresiones aritméticas y cálculo de resultados.

## Objetivo
Desarrollar programas sencillos que reciban datos desde la entrada estándar, realicen operaciones básicas y muestren resultados en la salida estándar, comprendiendo cómo se procesan los datos dentro de un programa.

## Ejercicios

##### 1. Escribe un programa que lea de la entrada estándar dos números y muestre en la salida estándar su suma, resta, multiplicación y división.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
using namespace std;
int main(){
	int n1, n2, suma = 0, resta = 0, multiplicacion=0, division=0;

	cout<<"Digite un numero: "; cin>>n1;
	cout<<"Digite otro numero: "; cin>>n2;

	suma = n1 + n2;
	resta = n1 - n2;
	multiplicacion = n1 * n2;
	division = n1 / n2;

	cout<<"\nLa suma es: "<<suma<<endl;
	cout<<"La resta es: "<<resta<<endl;
	cout<<"La multiplicacion es: "<<multiplicacion<<endl;
	cout<<"La division es: "<<division<<endl;

	return 0;
}
```
</details>

##### 2. Escribir un programa que de la entrada estándar el precio de un producto y muestre en la salida estándar el precio del producto al aplicarle el IVA. 
<details>
<summary>Solución</summary>

```c++
#include<iostream>
using namespace std;
int main(){
	float precio,precioFinal,IVA;
	
	cout<<"Digite el precio del producto: ";
	cin>>precio;
	
	IVA = precio*0.21;
	precioFinal = precio + IVA;
	
	cout<<"\nEl precio Final al aplicarle IVA es: "<<precioFinal;
	
	return 0;
}
```
</details>

##### 3. Realice un programa que lea de la entrada estándar los siguientes datos de una persona:
- **Edad: dato de tipo entero.**
- **Sexo: dato de tipo carácter.**
- **Altura en metros: dato de tipo real.**
	
**Tras leer los datos, el programa debe mostrarlos en la salida estándar.**
<details>
<summary>Solución</summary>

```c++
#include<iostream>
using namespace std;
int main(){
	int edad;
	char sexo[10];
	float altura;
	
	cout<<"Digite su edad: "; cin>>edad;
	cout<<"Digite su sexo: "; cin>>sexo;
	cout<<"Digite su altura en metros: "; cin>>altura;
	
	cout<<"\nEdad: "<<edad<<endl;
	cout<<"Sexo: "<<sexo<<endl;
	cout<<"Altura en metros: "<<altura<<endl;
	
	
	return 0;
}
```
</details>

##### 4.Ejecute el programa del ejercicio anterior con entradas erróneas y observe los resultados. Por ejemplo, introduzca un dato de tipo carácter cuando se espera un dato de tipo entero.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
using namespace std;
int main(){
	int edad;
	char sexo[10];
	float altura;
	
	cout<<"Digite su edad: "; cin>>edad;
	cout<<"Digite su sexo: "; cin>>sexo;
	cout<<"Digite su altura en metros: "; cin>>altura;
	
	cout<<"\nEdad: "<<edad<<endl;
	cout<<"Sexo: "<<sexo<<endl;
	cout<<"Altura en metros: "<<altura<<endl;
	
	return 0;
}
```
</details>