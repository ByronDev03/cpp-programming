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

##### 3. Realice un programa que lea de la entrada est�ndar los siguientes datos de una persona:
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