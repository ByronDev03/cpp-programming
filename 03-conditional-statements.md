##### 1. Escriba un programa que lea dos números y determine cuál de ellos es el mayor.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
using namespace std;
int main(){
	int n1,n2;
	
	cout<<"Digite 2 numeros: "; 
	cin>>n1>>n2; //guarando los 2 numeros
	
	
	if(n1==n2){
		cout<<"Ambos numeros son iguales";
	}
	else if(n1>n2){
		cout<<"El mayor es: "<<n1;
	}
	else{
		cout<<"El mayor es: "<<n2;
	}
	
	return 0;
}
```
</details>

##### 2. Escriba un programa que lea tres números y determine cuál de ellos es el mayor.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
using namespace std;
int main(){
	int n1,n2,n3;
	
	cout<<"Digite 3 numeros: "; 
	cin>>n1>>n2>>n3;
	
	if((n1>n2)&&(n1>n3)){
		cout<<"El mayor es: "<<n1;
	}
	else if((n2>n1)&&(n2>n3)){
		cout<<"El mayor es: "<<n2;
	}
	else{
		cout<<"El mayor es: "<<n3;
	}
	
	return 0;
}
```
</details>

##### 3. Realice un programa que lea un valor entero y determine si se trata de un número par o impar.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
using namespace std;
int main(){
	long long int numero;
	
	cout<<"Digite un numero: ";
	cin>>numero;
	
	if(numero==0){
		cout<<"El numero es cero";
	}
	else if(numero%2==0){
		cout<<"El numero es par";
	}
	else{
		cout<<"El numero es impar";
	}
	
	
	return 0;
}
```
</details>

##### 4. Comprobar si un número digitado por el usuario es positivo o negativo.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
using namespace std;
int main(){
	int numero;
	
	cout<<"Digite un numero: "; 
	cin>>numero;
	
	if(numero==0){
		cout<<"El numero es cero";
	}
	else if(numero>0){
		cout<<"El numero es positivo";
	}
	else{
		cout<<"El numero es negativo";
	}
		
	return 0;
}
```
</details>

##### 5. Escriba un programa que lea de la entrada estándar un carácter e indique en la salida estándar si el carácter es una vocal minúscula o no.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
using namespace std;
int main(){
	char letra;
	
	cout<<"Digite un caracter: "; 
	cin>>letra;
	
	switch(letra){
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u': cout<<"Es una vocal minuscula"; break;
		default : cout<<"No es una vocal minuscula"; break;			
	}
		
	return 0;
}
```
</details>

##### 6. Escriba un programa que lea de la entrada estándar un carácter e indique en la salida estándar si el carácter es una vocal minúscula, es una vocal mayúscula o no es una vocal.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
using namespace std;
int main(){
	char letra;
	
	cout<<"Digite un caracter: "; 
	cin>>letra;
	
	switch(letra){
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u': cout<<"Es una vocal minuscula";break;
		case 'A': 
		case 'E':
		case 'I':
		case 'O':
		case 'U': cout<<"Es una vocal MAYUSCULA";break;
		default : cout<<"No es una vocal";break;
	}
	
	return 0;
}
```
</details>

##### 7. Escriba un programa que solicite una edad (un entero) e indique en la salida estándar si la edad introducida está en el rango [18-25].
<details>
<summary>Solución</summary>

```c++
#include<iostream>
using namespace std;
int main(){
	int edad;
	
	cout<<"Digite su edad: "; 
	cin>>edad;
	
	if((edad>=18)&&(edad<=25)){
		cout<<"Su edad esta en el rango de [18-25]";
	}
	else{
		cout<<"Su edad esta fuera de rango";
	}
	
	
	return 0;
}
```
</details>

##### 8. Escribe un programa que lea de la entrada estándar tres números. Después debe leer un cuarto número e indicar si el número coincide con alguno de los introducidos con anterioridad.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
using namespace std;
int main(){
	int n1,n2,n3,n4;
	
	cout<<"Digite 3 numeros: ";
	cin>>n1>>n2>>n3; //pedimos los 3 primeros numeros

	cout<<"Digite un 4to numero: "; 
	cin>>n4;
	
	if((n1==n4)||(n2==n4)||(n3==n4)){
		cout<<"El numero coincide con uno de los numeros anteriores";
	}	
	else{
		cout<<"El numero no coincide con ninguno de los anteriores";
	}
	
	return 0;
}
```
</details>

##### 9. Cambiar un número entero con el mismo valor pero en romanos.	
- **M = 1000**
- **D = 500**
- **C = 100**
- **L = 50**
- **X = 10**
- **V = 5**
- **I = 1**
<details>
<summary>Solución</summary>

```c++
#include<iostream>
using namespace std;
int main(){
	int numero,unidades,decenas,centenas,millar; 
	
	cout<<"Digite un numero: "; 
	cin>>numero; 
	//2152
	unidades = numero%10; numero /= 10; //unidades = 2 , numero = 215
	decenas = numero%10; numero /= 10; //decenas = 5 , numero = 21
	centenas = numero % 10; numero /= 10; //centenas = 1 , numero = 2
	millar = numero % 10 ; numero /= 10; //millar = 2 , numero = 0
	//2000+100+50+2 = 2152
	
	switch(millar){
		case 1: cout<<"M";break;
		case 2: cout<<"MM"; break;
		case 3: cout<<"MMM";break;
	}
	
	switch(centenas){
		case 1: cout<<"C";break;
		case 2: cout<<"CC";break;
		case 3: cout<<"CCC";break;
		case 4: cout<<"CD";break;
		case 5: cout<<"D";break;
		case 6: cout<<"DC";break;
		case 7: cout<<"DCC";break;
		case 8: cout<<"DCCC";break;
		case 9: cout<<"CM";break;
	}
	
	switch(decenas){
		case 1: cout<<"X";break;
		case 2: cout<<"XX";break;
		case 3: cout<<"XXX";break;
		case 4: cout<<"XL";break;
		case 5: cout<<"L";break;
		case 6: cout<<"LX";break;
		case 7: cout<<"LXX";break;
		case 8: cout<<"LXXX";break;
		case 9: cout<<"XC";break;
	}
	
	switch(unidades){
		case 1: cout<<"I";break;
		case 2: cout<<"II";break;
		case 3: cout<<"III";break;
		case 4: cout<<"IV";break;
		case 5: cout<<"V";break;
		case 6: cout<<"VI";break;
		case 7: cout<<"VII";break;
		case 8: cout<<"VIII";break;
		case 9: cout<<"IX";break;
	}
	return 0;
}
```
</details>

##### 10. Mostrar los meses del año, pidiéndole al usuario un número entre (1-12), y mostrar el mes al que corresponde.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
using namespace std;
int main(){
	int numero;
	
	cout<<"Digite un numero entre [1-12]: ";
	cin>>numero;
	
	switch(numero){
		case 1: cout<<"Enero";break;
		case 2: cout<<"Febrero";break;
		case 3: cout<<"Marzo";break;
		case 4: cout<<"Abril";break;
		case 5: cout<<"Mayo";break;
		case 6: cout<<"Junio";break;
		case 7: cout<<"Julio";break;
		case 8: cout<<"Agosto";break;
		case 9: cout<<"Septiembre";break;
		case 10: cout<<"Octubre";break;
		case 11: cout<<"Noviembre";break;
		case 12: cout<<"Diciembre";break;
		default: cout<<"No existe mes para ese numero";break;
	}
		
	return 0;
}
```
</details>

##### 11. Hacer un programa que simule un cajero automático con un saldo inicial de 1000 Dólares.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
using namespace std;
int main(){
	int saldo_inicial = 1000,opc;
	float extra,saldo = 0,retiro; 
	
	cout<<"\tBienvenido a su cajero automatico"<<endl;
	cout<<"1. Ingresar dinero en cuenta"<<endl;
	cout<<"2. Retirar dinero de la cuenta"<<endl;
	cout<<"3. Salir"<<endl;
	cout<<"Opcion: "; 
	cin>>opc;
	
	switch(opc){
		case 1: cout<<"\nCuanto dinero desea ingresar en cuenta: "; 
				cin>>extra;
				
				saldo = saldo_inicial + extra;
				cout<<"\nDinero en cuenta: "<<saldo; break;
		case 2: cout<<"\nCuanto dinero desea retirar: "; 
				cin>>retiro;
				
				if(retiro > saldo_inicial){
					cout<<"No cuenta con esa cantidad";
				}
				else{
					saldo = saldo_inicial - retiro;
					cout<<"\nDinero en cuenta: "<<saldo; break;
				}
		case 3: break;
		dafault: cout<<"Se equivoco de opcion de menu";break;
	}
	
	return 0;
}
```
</details>

##### 12. Hacer un menú que considere las siguientes opciones:
- **Caso 1: Cubo de un numero**
- **Caso 2: Numero par o impar**
- **Caso 3: salir.**
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int opc,numero,cubo;
	
	cout<<"\tMENU"<<endl;
	cout<<"1. Cubo de un numero"<<endl;
	cout<<"2. Numero par o impar"<<endl;
	cout<<"3. Salir"<<endl;
	cout<<"Opcion: "; 
	cin>>opc;
	
	switch(opc){
		case 1: 
			cout<<"\nDigite un numero: "; cin>>numero;
			cubo = pow(numero,3); //elevamos el numero al cubo
			cout<<"El cubo del numero es: "<<cubo;break;
		case 2: 
			cout<<"\nDigite un numero: "; cin>>numero;
			
			if(numero%2==0){
				cout<<"El numero es par";
			}
			else{
				cout<<"El numero es impar";
			}
			break;
		case 3: break;
	}
	
	return 0;
}
```
</details>