##### 1. Escriba una función llamada mult() que acepte dos números en punto flotante como parámetros, multiplique estos dos números y despliegue el resultado.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

//Prototipo de Funcion
void mult(float x,float y);
void pedirDatos();

float n1,n2;

int main(){
	pedirDatos();
	mult(n1,n2);
	
	getch();
	return 0;
}

void pedirDatos(){	
	cout<<"Digite 2 numeros: ";
	cin>>n1>>n2;
}

void mult(float x,float y){
	float multiplicacion = x * y;

	cout<<"La multiplicacion es: "<<multiplicacion<<endl;
}
```
</details>

##### 2. Escriba una función llamada al_cuadrado() que calcule el cuadrado del valor que se le transmite y despliegue el resultado. La función deberá ser capaz de elevar al cuadrado números flotantes
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

void pedirDatos();
void al_cuadrado(float n);

float numero;

int main(){
	pedirDatos();	
	al_cuadrado(numero);
	
	getch();
	return 0;
}

void pedirDatos(){
	cout<<"Digite un numero: ";
	cin>>numero;
}

void al_cuadrado(float n){
	float cuadrado=0;
	
	cuadrado = numero*numero;
	
	cout<<"El cuadrado del numero es: "<<cuadrado<<endl;
}
```
</details>

##### 3. Escriba una función nombrada funpot() que eleve un número entero que se le transmita a una potencia en número entero positivo y despliegue el resultado. El número entero positivo deberá ser el segundo valor transmitido a la función.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

void pedirDatos();
void funpot(int x,int y);

int numero,exponente;

int main(){
	pedirDatos();
	funpot(numero,exponente);
	
	getch();
	return 0;
}

void pedirDatos(){
	cout<<"Digite el numero a elevar: ";
	cin>>numero;
	cout<<"Digite el exponetente de elevacion: ";
	cin>>exponente;
}

void funpot(int x,int y){
	long resultado=1;
	
	for(int i=1;i<=y;i++){
		resultado *= x;
	}
	
	cout<<"El resultado de la elevacion es: "<<resultado<<endl;
}
```
</details>

##### 4. Escriba un programa en C++ que devuelva la parte fraccionaria de cualquier número introducido por el usuario. Por ejemplo, si se introduce el número 256.879, debería desplegarse el número 0.879.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

void pedirDatos();
float devolucionFraccionaria(float n);

float numero;

int main(){
	pedirDatos();
	
	cout<<"La parte fraccionaria del numero es: "<<devolucionFraccionaria(numero)<<endl;
	
	getch();
	return 0;
}

void pedirDatos(){
	cout<<"Digite un numero: ";
	cin>>numero;
}

float devolucionFraccionaria(float n){
	//por ejemplo si el numero es 45.567 en entero solo se guardaria 45
	int entero = n;
	//y por ultimo restamos el valor flotante menos el entero para tener la parte fraccionaria
	float resultado = n - entero;
	
	return resultado;	
}
```
</details>

##### 5. Escriba una plantilla de función llamada despliegue() que despliegue el valor del argumento único que se le transmite cuando es invocada la función.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

template <class TIPOD>
void despliegue(TIPOD dato);

int main(){
	int dato1 = 4;
	float dato2 = 5.678;
	double dato3 = 15.6789;
	char dato4 = 'a';
	
	despliegue(dato1);
	despliegue(dato2);
	despliegue(dato3);
	despliegue(dato4);
	
	getch();
	return 0;
}

template <class TIPOD>
void despliegue(TIPOD dato){
	
	cout<<"El dato es: "<<dato<<endl;
}
```
</details>

##### 6. Escriba una plantilla de función llamada maximo() que devuelva el valor máximo de tres argumentos que se transmitan a la función cuando sea llamada. Suponga que los tres argumentos serán del mismo tipo de datos.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

template <class T>
T maximo(T dato1, T dato2, T dato3);

int main(){
	char dato1='e',dato2='f',dato3='a';
	
	cout<<"El maximo valor es: "<<maximo(dato1,dato2,dato3);
	
	getch();
	return 0;
}

template <class T>
T maximo(T dato1, T dato2, T dato3){
	T max;
	
	if((dato1 > dato2) && (dato1 > dato3)){
		max = dato1;
	}
	else{
		 if((dato2>dato1) && (dato2>dato3)){
			max = dato2;
		}
		else{
			max = dato3;
		}
	}
	return max;
}
```
</details>

##### 7. Intercambiar el valor de 2 variables utilizando paso de parámetros por referencia.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

void intercambio(int&, int&);

int main(){
	int num1=10,num2=15;
	
	cout<<"El valor almacenado en num1 es: "<<num1<<endl;
	cout<<"El valor almacenado en num2 es: "<<num2<<endl;
	
	intercambio(num1,num2);
	
	cout<<"Ahora el nuevo valor de num1 es: "<<num1<<endl;
	cout<<"Ahora el nuevo valor de num2 es: "<<num2<<endl;			
	
	getch();
	return 0;
}

void intercambio(int& num1, int& num2){
	int aux;
	//Intercambiamos ambos valores de las variables num1 y num2
	aux = num1;
	num1 = num2;
	num2 = aux;
}
```
</details>

##### 8. Escriba una función nombrada cambio() que tenga un parámetro en número entero y seis parámetros de referencia en número entero nombrados cien, cincuenta, veinte, diez, cinco y uno, respectivamente. La función tiene que considerar el valor entero transmitido como una cantidad en dólares y convertir el valor en el número menor de billetes equivalentes.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

void cambio(int,int&,int&,int&,int&,int&,int&);

int main(){
	int valor,cien=0,cincuenta=0,veinte=0,diez=0,cinco=0,uno=0;
	
	cout<<"Digite un valor: ";
	cin>>valor;
	//Llamos a la funcion
	cambio(valor,cien,cincuenta,veinte,diez,cinco,uno);
	
	cout<<"Cantidad de billetes a entregar como cambio:"<<endl;
	cout<<"Cien: "<<cien<<endl;
	cout<<"Cincuenta: "<<cincuenta<<endl;
	cout<<"Veinte: "<<veinte<<endl;
	cout<<"Diez: "<<diez<<endl;
	cout<<"Cinco: "<<cinco<<endl;
	cout<<"Uno: "<<uno<<endl;
	
	getch();
	return 0;
}

void cambio(int valor,int& cien,int& cincuenta,int& veinte,int& diez,int& cinco,int& uno){
	cien = valor/100;
	valor %= 100;
	cincuenta = valor/50;
	valor %= 50;
	veinte = valor/20;
	valor %= 20;
	diez = valor/10;
	valor %= 10;
	cinco = valor/5;
	uno = valor%5;
}
```
</details>

##### 9. Escriba una función nombrada tiempo() que tenga un parámetro en número entero llamado totalSeg y tres parámetros de referencia enteros nombrados horas, min y seg. La función es convertir el número de segundos transmitido en un número equivalente de horas, minutos y segundos.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

void tiempo(int,int&,int&,int&);

int main(){
	int totalSeg,horas,min,seg;
	
	cout<<"Digita la cantidad de segundos: ";
	cin>>totalSeg;
		
	tiempo(totalSeg,horas,min,seg);
	
	cout<<"\nHoras: "<<horas<<endl;
	cout<<"Minutos: "<<min<<endl;
	cout<<"Segundos: "<<seg<<endl;
	
	getch();
	return 0;
}

void tiempo(int totalSeg,int& horas,int& min,int& seg){	
	horas = totalSeg/3600;
	totalSeg %= 3600;
	min = totalSeg/60;
	seg = totalSeg%60; 
}
```
</details>

##### 10. Escriba una función nombrada calc_años() que tenga un parámetro entero que represente el número total de días desde la fecha 1/1/2000 y parámetros de referencia nombrados año, mes y día. La función es calcular el año, mes y día actual para el número dado de días que se le transmitan. Usando las referencias, la función deberá alterar en forma directa los argumentos respectivos en la función que llama. Para este problema suponga que cada año tiene 365 días y cada mes tiene 30 días.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

void calc_anios(int,int&,int&,int&);

int main(){
	int totalDias,anio,mes,dia;
	
	cout<<"Digite el numero total de dias transcurridos: ";
	cin>>totalDias;
	
	calc_anios(totalDias,anio,mes,dia);
	
	cout<<"Fecha Actual: "<<dia+1<<"/"<<mes+1<<"/"<<anio+2000<<endl;	
	
	getch();
	return 0;
}

void calc_anios(int totalDias,int& anio,int& mes,int& dia){
	anio = totalDias/365;
	totalDias %= 365;
	mes = totalDias/30;
	dia = totalDias%30;
}
```
</details>

##### 11. Realice una función que tome como parámetros un vector de números enteros y devuelva la suma de sus elementos.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

void pedirDatos();
int calcularSuma(int vec[],int);

int vec[100],tam;

int main(){
	pedirDatos();
	
	cout<<"\nLa suma es: "<<calcularSuma(vec,tam)<<endl;
	
	getch();
	return 0;
}

void pedirDatos(){
	cout<<"Digite el numero de elementos del arreglo: ";
	cin>>tam;
	
	for(int i=0;i<tam;i++){
		cout<<i+1<<". Digite un numero: ";
		cin>>vec[i];
	}
}

int calcularSuma(int vec[],int tam){
	int suma=0;
	
	for(int i=0;i<tam;i++){
		suma += vec[i];
	}
	return suma;
}
```
</details>

##### 12. Realice una función que tome como parámetros un vector y su tamaño y diga si el vector está ordenado crecientemente. Sugerencia: compruebe que para todas las posiciones del vector, salvo para la 0, el elemento del vector es mayor o igual que el elemento que le precede en el vector.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

void pedirDatos();
void comprobarOrdenamiento(int vec[],int);

int vec[100],tam;

int main(){
	pedirDatos();
	comprobarOrdenamiento(vec,tam);
	
	getch();
	return 0;
}

void pedirDatos(){
	cout<<"Digite el numero de elementos del vector: ";
	cin>>tam;
	
	for(int i=0;i<tam;i++){
		cout<<i+1<<". Digite un numero: ";
		cin>>vec[i];
	}
}

void comprobarOrdenamiento(int vec[],int tam){
	char band = 'F';
	
	//1 2 3 4 5
	int i=0;
	while((band=='F')&&(i<tam-1)){
		if(vec[i]>vec[i+1]){
			band = 'V';
		}
		i++;
	}
	
	if(band == 'F'){
		cout<<"\nEl arreglo esta ordenado en forma creciente";
	}
	else{
		cout<<"\nEl arreglo NO esta ordenado";
	}
}
```
</details>

##### 13. Realiza una función que tome como parámetros un vector de números y su tamaño y cambie el signo de los elementos del vector.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

//Prototipos de Funciones
void pedirDatos();
void cambiarSigno(int vec[],int);
void mostrarVector(int vec[],int);


int tam,vec[100];

int main(){
	//Llamada a las funciones - en orden
	pedirDatos();
	cambiarSigno(vec,tam);	
	mostrarVector(vec,tam);
	
	getch();
	return 0;
}

void pedirDatos(){
	cout<<"Digite el tamanio del vector: ";
	cin>>tam;
	
	for(int i=0;i<tam;i++){
		cout<<i+1<<". Digite un numero: ";
		cin>>vec[i];
	}
}

void cambiarSigno(int vec[],int tam){
	for(int i=0;i<tam;i++){
		vec[i] *= -1;
	}
}

void mostrarVector(int vec[],int tam){
	cout<<"\nMostrando vector con cambio de signo: "<<endl;
	for(int i=0;i<tam;i++){
		cout<<vec[i]<<" ";
	}
}
```
</details>

##### 14. Realiza una función que tome como parámetros un vector de enteros y su tamaño e imprima un vector con los elementos impares del vector recibido.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

void pedirDatos();
void impares(int vec[],int);

int tam,vec[100];

int main(){
	pedirDatos();
	impares(vec,tam);
	
	getch();
	return 0;
}

void pedirDatos(){
	cout<<"Digite el tamanio del vector: ";
	cin>>tam;
	
	for(int i=0;i<tam;i++){
		cout<<i+1<<". Digite un numero: ";
		cin>>vec[i];
	}
}

void impares(int vec[],int tam){
	int vecImpares[100];
	int j=0;
	for(int i=0;i<tam;i++){
		if(vec[i]%2!=0){
			vecImpares[j] = vec[i];
			j++;
		}
	}
	
	cout<<"\nImprimiendo los elementos impares del vector: "<<endl;
	for(int i=0;i<j;i++){
		cout<<vecImpares[i]<<" ";
	}
}
```
</details>

##### 15. Desarrollar una función que determine si una matriz es simétrica o no.
##### Una matriz es simetrica: A = A^t
- **La matriz debe ser cuadrada. _--**
- **Aij = Aji**
```text
|2   5   9|		  |2  5   9|
|5   8  -1|   ->  |5  8  -1|
|9  -1  10|	      |9 -1  10|
```
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

void pedirDatos();
void comprobarSimetria(int m[][100],int,int);

int m[100][100],nfilas,ncol;

int main(){
	pedirDatos();
	comprobarSimetria(m,nfilas,ncol);
	
	getch();
	return 0;
}

void pedirDatos(){
	cout<<"Digite el numero de filas: ";
	cin>>nfilas;
	cout<<"Digite el numero de columnas: ";
	cin>>ncol;
	
	//Pedimos todos los elementos de la matriz
	for(int i=0;i<nfilas;i++){
		for(int j=0;j<ncol;j++){
			cout<<"Digite m["<<i<<"]["<<j<<"]: ";
			cin>>m[i][j];
		}
	}
}

void comprobarSimetria(int m[][100],int nfilas,int ncol){
	int cont = 0;
	
	//Si es cuadrada
	if(nfilas==ncol){
		//y ademas si Aij = Aji
		for(int i=0;i<nfilas;i++){
			for(int j=0;j<ncol;j++){
				if(m[i][j]==m[j][i]){
					cont++;//El conteo debe ser igual al numero de elementos de la matriz
				}
			}
		}
	}
	
	if(cont == nfilas*ncol){
		cout<<"\nLa matriz es Simetrica";
	}
	else{
		cout<<"\nLa matriz NO es simetrica";
	}
}
```
</details>

##### 16. Realice una función que dada una matriz y un número de fila de la matriz devuelva el menor de los elementos almacenados en dicha fila.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

void pedirDatos();
int comprobarMenorElemento(int m[][100],int,int);

int m[100][100],nfilas,ncol;

int main(){
	pedirDatos();
	
	cout<<"\nEl menor elemento de la fila seleccionada es: "<<comprobarMenorElemento(m,nfilas,ncol)<<endl;
	
	getch();
	return 0;
}

void pedirDatos(){
	cout<<"Digite el numero de filas: ";
	cin>>nfilas;
	cout<<"Digite el numero de columnas: ";
	cin>>ncol;
	
	for(int i=0;i<nfilas;i++){
		for(int j=0;j<ncol;j++){
			cout<<"Digite m["<<i<<"]["<<j<<"]: ";
			cin>>m[i][j];
		}
	}
}

int comprobarMenorElemento(int m[][100],int nfilas,int ncol){
	int fila,menor=99999;
	
	cout<<"\nDigite el numero de fila a comprobar: ";
	cin>>fila;
	
	for(int i=0;i<nfilas;i++){
		for(int j=0;j<ncol;j++){
			if(i==fila){
				if(m[i][j] < menor){
					menor = m[i][j];
				}
			}
		}
	}
	
	return menor;
}
```
</details>

##### 17. Suma de números Complejos
```text
z1 = 5-3i   ,  z2 = -4+2i
z1 + z2 = (5-3i)+(-4+2i)
	    = 5-3i-4+2i
		= 1-i
```
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

struct complejo{
	float real,imaginaria;
}z1,z2;

//Prototipo de Funci�n
void pedirDatos();
complejo suma(complejo,complejo);
void muestra(complejo);

int main(){
	pedirDatos();
	
	complejo x = suma(z1,z2);
	
	muestra(x);	
	
	getch();
	return 0;
} 

void pedirDatos(){
	cout<<"Digite el primer numero complejo: "<<endl;
	cout<<"Parte Real: "; cin>>z1.real;
	cout<<"Parte Imaginaria: "; cin>>z1.imaginaria;
	
	cout<<"\nDigite el segundo numero complejo: "<<endl;
	cout<<"Parte Real: "; cin>>z2.real;
	cout<<"Parte Imaginaria: "; cin>>z2.imaginaria;
}

complejo suma(complejo z1,complejo z2){
	z1.real += z2.real;
	z1.imaginaria += z2.imaginaria;
	
	return z1;
}

void muestra(complejo x){
	cout<<"\nLa suma es: "<<x.real<<" , "<<x.imaginaria<<endl;
}
```
</details>

##### 18. Escriba una función en C++ llamada mayor() que devuelva la fecha más reciente de cualquier par de fechas que se le transmitan. Por ejemplo, si se transmiten las fechas 10/9/2005 y 11/3/2015 a mayor(), será devuelta la segunda fecha.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

struct Fecha{
	int dia,mes,anio;
}f1,f2;

//Prototipos de Funciones
void pedirDatos();
Fecha mayor(Fecha,Fecha);
void mostrarFechaMayor(Fecha);

int main(){
	pedirDatos();
	Fecha x = mayor(f1,f2);
	mostrarFechaMayor(x);	
	
	getch();
	return 0;
}

void pedirDatos(){
	cout<<"Digite la Fecha1: "<<endl;
	cout<<"Dia: "; cin>>f1.dia;
	cout<<"Mes: "; cin>>f1.mes;
	cout<<"Anio: "; cin>>f1.anio;
	
	cout<<"\n\nDigite la Fecha2: "<<endl;
	cout<<"Dia: "; cin>>f2.dia;
	cout<<"Mes: "; cin>>f2.mes;
	cout<<"Anio: "; cin>>f2.anio;
}

Fecha mayor(Fecha f1,Fecha f2){
	Fecha mayorFecha;
	
	//Primero comprobamos los años
	if(f1.anio == f2.anio){
		//Ahora, comprobamos los meses
		if(f1.mes ==f2.mes){
			//Por ultimo comprobamos los dias
			if(f1.dia == f2.dia){
				cout<<"\nAmbas fechas son iguales";
			}
			else if(f1.dia > f2.dia){
				mayorFecha = f1;
			}
			else{
				mayorFecha = f2;
			}
		}
		else if(f1.mes > f2.mes){
			mayorFecha = f1;
		}
		else{
			mayorFecha = f2;
		}
	}
	else if(f1.anio > f2.anio){
		mayorFecha = f1;
	}
	else{
		mayorFecha = f2;
	}
	
	
	return mayorFecha;
}

void mostrarFechaMayor(Fecha x){
	cout<<"\nMostrando fecha mayor: "<<x.dia<<"/"<<x.mes<<"/"<<x.anio<<endl;
}
```
</details>

##### 19. Realice una función recursiva que sume los primeros n enteros positivos. Nota: para plantear la función recursiva tenga en cuenta que la suma puede expresarse mediante la siguiente recurrencia:
```text
suma(n) = 1            , si n=1
	n+suma(n-1)  , si n>1
```
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

//Prototipo de Función
int sumar(int n);

int main(){
	int numero;
	
	//Pedimos un numero hasta que sea entero positivo numero > 0
	do{
		cout<<"Digite un numero: ";
		cin>>numero;
	}while(numero<=0);
	
	//Mandamos llamar a la funcion recursiva sumar
	cout<<"La suma es: "<<sumar(numero)<<endl;
	
	getch();
	return 0;
}

//Definici�n de Funci�n
int sumar(int n){
	int suma=0;
	
	if(n==1){//Caso base
		suma = 1;
	}
	else{//Caso general
		suma = n + sumar(n-1);
	}
	
	return suma;
}
```
</details>

##### 20. Realice una función recursiva para la serie Fibonacci Nota: La serie de Fibonacci está formada por la secuencia de números: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34... 
```text
fibonacci(n) = n                              , si n<2
	fibonacci(n-1)+fibonacci(n-2)  , si n>=2
```
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

int fibonacci(int n);

int main(){
	int nElementos;
	
	//Pedimos un numero entero positivo
	do{
		cout<<"Digite el numero de elementos: ";
		cin>>nElementos;
	}while(nElementos <= 0);
	
	//Mandamos llamar a la funcion pero de forma iterativa para imprimir todos los elementos
	cout<<"Serie Fibonacci: ";
	for(int i=0;i<nElementos;i++){
		cout<<fibonacci(i)<<" , ";	
	}
	
	getch();
	return 0;
}

int fibonacci(int n){
	if(n<2){//Caso base
		return n;
	}
	else{//Caso general
		return fibonacci(n-1)+fibonacci(n-2);
	}
}
```
</details>

##### 21. Escriba una función recursiva que calcule un número elevado a una potencia entera mayor o igual que cero: x^y. 
```text
potencia(x,y) = x                  , y=1
	x*potencia(x,y-1)  , y>1
```
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

int potencia(int,int);

int main(){
	int base,exponente;
	
	//Pedimos los datos al usuario
	cout<<"Digite numero base: ";
	cin>>base;
	cout<<"Digite exponente: ";
	cin>>exponente;
	
	//Mostramos el resultado
	cout<<"\nResultado: "<<potencia(base,exponente)<<endl;	
	
	getch();
	return 0;
}

int potencia(int x,int y){
	int pot;
	if(y==1){//Caso base
		pot = x;
	}
	else{//Caso general
		pot = x*potencia(x,y-1);
	}
	return pot;
}
```
</details>

##### 22. Escriba una función escribeNumeros(int ini, int fin) que devuelva en la salida estándar los números del ini al fin. Escriba una versión que escriba los números en orden ascendente.
```text
escribeNumeros(ini,fin) = ini                             , si ini=fin
	escribeNumeros(ini,fin-1)       , si fin>ini
```
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;

//Prototipo de Funcion
int escribeNumeros(int,int);

int main(){
	int ini,fin;
	
	//Pedimos los datos al usuario
	cout<<"Escriba el inicio: ";
	cin>>ini; 
	cout<<"Escriba el fin: "; 
	cin>>fin;
	
	//Llamamos a la funcion de forma iterativa para mostrar todos los elementos
	for(int i=ini;i<=fin;i++){
		cout<<escribeNumeros(i,fin)<<" ";
	}	
	
	getch();
	return 0;
} 

int escribeNumeros(int ini,int fin){
	if(ini==fin){//Caso base
		return ini;
	}
	else{//Caso general
		return escribeNumeros(ini,fin-1);
	}
}
```
</details>

##### 23.
<details>
<summary>Solución</summary>

```c++

```
</details>