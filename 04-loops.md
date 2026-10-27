<h1 align="center">4. Bucles</h1>

<p align="justify">
En esta unidad se estudian las estructuras repetitivas de C++, también conocidas como bucles o ciclos, que permiten ejecutar un conjunto de instrucciones varias veces mientras se cumpla una condición o durante un número determinado de iteraciones. Estas estructuras son fundamentales para automatizar tareas y resolver problemas que requieren procesar datos de forma repetitiva. A través de los ejercicios, se utilizarán bucles para generar tablas de multiplicar, calcular sumas y productos, trabajar con factoriales, construir series numéricas y resolver problemas que requieren la lectura y el análisis de múltiples datos.
</p>

## Conceptos principales

- **Bucle `for`:** repetición de instrucciones durante un número determinado de iteraciones.
- **Bucle `while`:** ejecución repetitiva mientras una condición sea verdadera.
- **Bucle `do-while`:** ejecución de un bloque de instrucciones al menos una vez, evaluando la condición al final.
- **Contadores y acumuladores:** variables utilizadas para contar iteraciones, sumar valores y acumular resultados.
- **Condiciones de terminación:** criterios que determinan cuándo debe finalizar un ciclo, incluyendo valores centinela.
- **Sumatorias y productorias:** cálculo de expresiones numéricas mediante operaciones repetitivas.
- **Factoriales y potencias:** aplicación de ciclos para realizar multiplicaciones sucesivas.
- **Series numéricas:** generación de secuencias como Fibonacci y otras sucesiones aritméticas.
- **Bucles anidados:** utilización de ciclos dentro de otros para procesar conjuntos de datos y realizar cálculos más complejos.
- **Procesamiento de datos y estadísticas:** lectura repetida de valores para calcular promedios, máximos, mínimos y cantidades que cumplen determinadas condiciones.

## Objetivo

Comprender y aplicar las estructuras repetitivas de C++ para automatizar operaciones, procesar conjuntos de datos y resolver problemas matemáticos mediante ciclos, contadores, acumuladores y condiciones de terminación.

## Ejercicios

##### 1. Realice un programa que solicite de la entrada estándar un entero del 1 al 10 y muestre en la salida estándar su tabla de multiplicar.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	int numero;
	
	do{
		cout<<"Digite un numero[1-10]: "; cin>>numero;
	}while((numero<1) || (numero>10));
	
	
	for(int i=1;i<=20;i++){
		cout<<numero<<" * "<<i<<" = "<<numero*i<<endl;
	}
	
	getch();	
	return 0;
}
```
</details>

##### 2. Realice un programa que lea de la entrada estándar números hasta que se introduzca un cero. En ese momento el programa debe terminar y mostrar en la salida estándar el número de valores mayores que cero leídos.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	int numero,conteo=0; 
	
	do{
		cout<<"Digite un numero: "; 
		cin>>numero;
		if(numero>0){
			conteo++; //aumentamos el conteo cada vez que encuentra un numero mayor a 0	
		}
	}while(numero != 0);
	
	cout<<"\nEl total de numeros mayores que 0 es: "<<conteo;
	
	getch();
	return 0;
}
```
</details>

##### 3. Realice un programa que calcule y muestre en la salida estándar la suma de los cuadrados de los 10 primeros enteros mayores que cero.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	int suma=0,cuadrado;
	
	for(int i=1;i<=10;i++){
		cuadrado = i * i;
		suma += cuadrado;		
	}
	
	cout<<"\nLa suma de los cuadrados es: "<<suma;
	
	getch();
	return 0;
}
```
</details>

##### 4. Escriba un programa que tome cada 4 horas la temperatura exterior, leyéndola durante un período de 24 horas. Es decir, debe leer 6 temperaturas. Calcule la temperatura media del día, la temperatura más alta y la más baja.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	float temperatura,suma_temperatura=0,temperatura_media;
	float temperatura_alta=0,temperatura_baja=999;
	
	for(int i=0;i<24;i+=4){ //vamos aumentando de 4 en 4 horas
		cout<<"Digite la temperatura a las "<<i<<": ";
		cin>>temperatura;
		
		suma_temperatura += temperatura;
		
		if(temperatura > temperatura_alta){
			temperatura_alta = temperatura;
		}
		if(temperatura < temperatura_baja){
			temperatura_baja = temperatura;
		}
	}
	
	temperatura_media = suma_temperatura / 6; //entre 6 porque son 6 temperaturas al dia
	
	cout<<"\nLa temperatura media del dia es: "<<temperatura_media<<endl;
	cout<<"La temperatura mas alta es: "<<temperatura_alta<<endl;
	cout<<"La temperatura mas baja es: "<<temperatura_baja<<endl;	
	
	getch();
	return 0;
}
```
</details>

##### 5. Escriba un programa que lea valores enteros hasta que se introduzca un valor en el rango [20-30] o se introduzca el valor 0. El programa debe entregar la suma de los valores mayores a 0 introducidos.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	int numero, suma = 0;
	
	do{
		cout<<"Digite un numero: "; 
		cin>>numero; 
		
		if(numero>0){
			suma += numero;
		}
		
	}while( ((numero<20) || (numero>30)) && (numero!=0) );
	
	cout<<"\nLa suma de todos los numeros mayores a cero es: "<<suma<<endl;
	
	getch();
	return 0;
}
```
</details>

##### 6. Escriba un programa que calcule x^y, donde tanto x como y son enteros positivos, sin utilizar la función pow.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	int x,y,elevacion=1;
	
	cout<<"Digite el valor de x: ";cin>>x;
	cout<<"Digite el valor de y: ";cin>>y;
	
	for(int i=1;i<=y;i++){
		elevacion *= x;
	}
	
	cout<<"\nEl resultado de la elevacion es: "<<elevacion;
	
	getch();
	return 0;
}
```
</details>

##### 7. Escriba un programa que calcule el valor de: 1+2+3+...+n
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
	int n,suma=0;
	
	cout<<"Digite el total de numeros a sumar: "; 
	cin>>n;
	
	for(int i=1;i<=n;i++){ 
		suma += i;
	}	
	
	cout<<"\nLa suma es: "<<suma<<endl;
	
	system("pause");	
	return 0;
}
```
</details>

##### 8. Escriba un programa que calcule el valor de: 1+3+5+...+2n-1
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
	int n,suma=0;
	
	cout<<"Digite la cantidad de elementos que desea sumar: ";
	cin>>n;
	
	for(int i=1;i<=2*n-1;i+=2){
		suma += i;
	}
	
	cout<<"La suma es: "<<suma<<endl;
	
	system("pause");
	return 0;
}
```
</details>

##### 9. Escriba un programa que calcule el valor de: 1*2*3*...*n (factorial)
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
	int n,factorial=1;
	
	cout<<"Digite un numero: "; 
	cin>>n;
	
	for(int i=1;i<=n;i++){
		factorial *= i;
	}
	
	cout<<"\nEl factorial del numero es: "<<factorial<<endl;
	
	system("pause");
	return 0;
}
```
</details>

##### 10. Escriba un programa que calcule el valor de: 1!+2!+3!+...+n! (suma de factoriales).
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
	int n,suma=0,factorial=1;
	
	cout<<"Digite el total de elementos a sumar: "; 
	cin>>n;
	
	for(int i=1;i<=n;i++){
		factorial *= i; //primero sacamos los factoriales
		suma +=factorial; //luego los sumamos
	}
	
	cout<<"\nLa suma de factoriales es: "<<suma<<endl;
	
	system("pause");
	return 0;
}
```
</details>

##### 11. Escriba un programa que calcule el valor de: 2^1+2^2+2^3+...+2^n
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
int main(){
	int n,suma=0,elevacion=0;
	
	cout<<"Digite el numero de terminos a sumar: ";
	cin>>n;
	
	for(int i=1;i<=n;i++){
		elevacion = pow(2,i);
		suma += elevacion;
	}
	
	cout<<"\nLa suma es: "<<suma<<endl;
	
	system("pause");
	return 0;
}
```
</details>

##### 12. Hacer un programa que calcule el resultado de la siguiente expresion: 1-2+3-4+5-6...n
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
	int n,suma=0,par=0,impar=0,negativo=0;
	
	cout<<"Digite el numero de elementos: ";
	cin>>n;
	
	for(int i=1;i<=n;i++){
		if(i%2==0){//los numeros pares son negativos
			negativo = i * -1; //los cambiamos de signo
			par += negativo;			
		}
		else{ //los impares son positivos
			impar += i;
		}
	}
	
	suma = par + impar;
	
	cout<<"\nLa suma es: "<<suma<<endl;
	system("pause");
	return 0;
}
```
</details>

##### 13. Hacer un programa que realize la serie fibonacci -> 1 1 2 3 5 8 13...n 
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
	int n,x=0,y=1,z=1;
	
	do{
		cout<<"Digite la cantidad de digitos de la serie: ";
		cin>>n;
	}while(n<=0);
	
	cout<<"1 ";
	for(int i=1;i<n;i++){
		z = x + y;
		cout<<z<<" ";
		x = y;
		y = z;		
	}
	
	cout<<"\n";
	system("pause");
	return 0;
}
```
</details>

##### 14. En una clase de 5 alumnos se han realizado tres exámenes y se requiere determinar el número de: 
1. **Alumnos que aprobaron todos los exámenes.**
2. **Alumnos que aprobaron al menos un examen.**
3. **Alumnos que aprobaron únicamente el último examen.**	
##### Realice un programa que permita la lectura de los datos y el cálculo de las estadísticas.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
using namespace std;
int main(){
	int examen1,examen2,examen3;
	int aprobaron_todos_examenes=0,aprobaron_almenos_uno=0,aprobaron_ultimo=0;
	
	for(int i=1;i<=5;i++){
		cout<<i<<". Digite la nota del primer examen: "; cin>>examen1;
		cout<<i<<". Digite la nota del segundo examen: "; cin>>examen2;
		cout<<i<<". Digite la nota del tercer examen: "; cin>>examen3;
		cout<<"\n";
		
		//examinando la opcion a
		if((examen1>10.5)&&(examen2>10.5)&&(examen3>10.5)){
			aprobaron_todos_examenes++;
		}
		
		//examinando la opcion b
		if((examen1>10.5)||(examen2>10.5)||(examen3>10.5)){
			aprobaron_almenos_uno++;
		}
		
		//examinando la opcion c
		if((examen1<10.5)&&(examen2<10.5)&&(examen3>10.5)){
			aprobaron_ultimo++;
		}
	}
	
	cout<<"\na) Aprobaron todos los examenes: "<<aprobaron_todos_examenes;
	cout<<"\nb) Aprobaron almenos un examen: "<<aprobaron_almenos_uno;
	cout<<"\nc) Aprobaron unicamente el ultimo examen: "<<aprobaron_ultimo;
	
	return 0;
}
```
</details>

##### 15. Realice un programa que solicite al usuario que piense un número entero entre el 1 y el 100. El programa debe generar un numero aleatorio en ese mismo rango[1-100],e indicarle al usuario si el numero que digito es menor o mayor al numero aleatorio, así hasta que lo adivine. y por ultimo mostrarle el numero de intentos que le llevo. variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior);
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main(){
	int numero,dato,contador=0;
	
	srand(time(NULL)); //generar un numero aleatorio entre 1-100
	dato = 1 + rand()%(101-1);
	
	do{
		cout<<"Digite un numero: "; cin>>numero;
		if(numero>dato){
			cout<<"Es un numero menor\n";
		}
		else if(numero<dato){
			cout<<"Es un numero mayor\n";
		}
		contador++;
	}while(numero != dato);
	
	cout<<"\n!FELICIDADES ADIVINO EL NUMERO!"<<endl;
	cout<<"Numero de intentos: "<<contador<<endl;
	
	system("pause");
	return 0;
}
```
</details>

##### 16. Realice un programa que calcule la descomposición en factores primos de un número entero. Por ejemplo: 20 = 2*2*5.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
	int numero;
	
	cout<<"Digite un numero: "; 
	cin>>numero;
	
	cout<<"\nDescomponiendo en factores primos: ";
	for(int i=2;numero>1;i++){
		while(numero%i==0){
			cout<<i<<" ";
			numero /= i;
		}
	}
	
	cout<<"\n";
	system("pause");
	return 0;
}
```
</details>