##### 1. Escribe un programa que defina un vector de números y calcule la suma de sus elementos.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	int numeros[5] ={1,2,3,4,5};
	int suma=0;
	
	for(int i=0;i<5;i++){		
		suma += numeros[i]; //Utilizamos una suma iterativa
	}
	
	cout<<"La suma de los elementos del arreglo es: "<<suma<<endl;	
	
	getch();
	return 0;
}
```
</details>

##### 2. Escribe un programa que defina un vector de números y calcule la multiplicación acumulada de sus elementos.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	int numeros[5] = {1,2,3,4,5};
	int multiplicacion=1;

	for(int i=0;i<5;i++){
		multiplicacion *= numeros[i]; //Hacemos la multiplicacion iterativa
	}
	
	cout<<"La multiplicacion de los elementos es: "<<multiplicacion<<endl;
	
	getch();
	return 0;
}
```
</details>

##### 3. Escribe un programa que lea de la entrada estándar un vector de números y muestre en la salida estándar los números del vector con sus índices asociados.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	int numeros[100],n;
	
	cout<<"Digite el numero de elementos: ";
	cin>>n;
	
	for(int i=0;i<n;i++){
		cout<<"Digite un numero: ";
		cin>>numeros[i]; //Guardamos los numeros en el arreglo
	}
	
	//Ahora, vamos a mostrar los numeros con sus indices asociados
	
	for(int i=0;i<n;i++){
		cout<<i<<" -> "<<numeros[i]<<endl; //Mostrando los numeros
	}
		
	getch();
	return 0;
}
```
</details>

##### 4. Escribe un programa que defina un vector de números y muestre en la salida estándar el vector en orden inverso del último al primer elemento.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	int numeros[5] = {1,2,3,4,5}; //Definimos el arreglo
	
	for(int i=4;i>=0;i--){
		cout<<numeros[i]<<endl; //Imprimimos el arreglo en orden inverso
	}
		
	getch();
	return 0;
}
```
</details>

##### 5. Desarrolle un programa que lea de la entrada estándar un vector de enteros y determine el mayor elemento del vector.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	int numeros[100],n,mayor=0;
	
	cout<<"Digite el numero de elementos: ";
	cin>>n;
	
	for(int i=0;i<n;i++){
		cout<<i+1<<". Digite un numero: ";
		cin>>numeros[i]; //Guardamos los elementos en el arreglo
		
		if(numeros[i] > mayor){ //Determinamos el mayor elemento en cada
			mayor = numeros[i]; //iteracion del bucle
		}
	}
	
	cout<<"\nEl mayor elemento del vector es: "<<mayor<<endl;
	
	getch();	
	return 0;
}
```
</details>

##### 6. Escribe un programa que defina un vector de números y calcule si existe algún número en el vector cuyo valor equivale a la suma del resto de números del vector.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	int numeros[5] = {1,2,3,4,10}; //Definimos un arreglo
	int suma=0,mayor=0;
	
	for(int i=0;i<5;i++){
		suma += numeros[i];
		
		if(numeros[i]>mayor){ //Determinamos cual es el numero mayor, ya que
			mayor = numeros[i];//el unico numero que puede ser la suma de los
		}					  //demas es el numero mayor
	}
	
	if(mayor == suma-mayor){//comparamos si el numero mayor es igual a suma menos el numero mayor
		cout<<"El numero "<<mayor<<" es la suma de los demas";
	}
	else{
		cout<<"No existe ningun numero que sea la suma de los demas";
	}
	
	getch();
	return 0;
}
```
</details>

##### 7. Realiza un programa que defina dos vectores de caracteres y después almacene el contenido de ambos vectores en un nuevo vector, situando en primer lugar los elementos del primer vector seguido por los elementos del segundo vector. Muestre el contenido del nuevo vector en la salida estándar.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	char letras1[] = {'a','b','c','d','e'};
	char letras2[] = {'f','g','h','i','j'};
	char letras3[10];
	
	//Copiando el contenido de letras1 hacia letras3
	for(int i=0;i<5;i++){
		letras3[i] = letras1[i]; 
	}
	
	//Copiando el contenido de letras2 hacia letras3
	for(int i=5;i<10;i++){
		letras3[i] = letras2[i-5];
	}
	
	//Imprimiento el numero vector con todos los elementos
	for(int i=0;i<10;i++){
		cout<<letras3[i]<<endl;
	}
	
	getch();
	return 0;
}
```
</details>

##### 8. Hacer un programa que lea 5 numeros en un arreglo, los copie a otro arreglo multiplicados por 2 y muestre el segundo arreglo.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	int numeros[5],numeros2[5];
	
	//Primero vamos a pedir los 5 numeros del primer arreglo
	for(int i=0;i<5;i++){
		cout<<i+1<<". Digite un numero: "; cin>>numeros[i];
	}
	
	//Ahora, vamos a multiplicar por 2 los elementos del primer arreglo
	for(int i=0;i<5;i++){
		numeros2[i] = numeros[i]*2;
	}
	
	cout<<"\nMostrando numeros multiplicados por 2:\n\n";
	
	//Luego mostramos el segundo arreglo
	for(int i=0;i<5;i++){
		cout<<numeros2[i]<<endl;
	}
	
	getch();
	return 0;
}
```
</details>