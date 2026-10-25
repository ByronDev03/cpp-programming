##### 1. Escribe la siguiente expresión como expresión en C++: (a/b) + 1
<details>
<summary>Solución</summary>

```c++
#include<iostream>
using namespace std;
int main(){
	float a,b,resultado=0;
	
	cout<<"Digite el valor de a: "; 
	cin>>a;
	cout<<"Digite el valor de b: ";
	cin>>b;
	
	resultado = (a/b) + 1;
	
	cout.precision(2);//recorta los números despues de la coma decimal a 2
	
	cout<<"El resultado es: "<<resultado;	
	
	return 0;
}
```
</details>

##### 2. Escribe la siguiente expresión como expresión en C++: (a+b)/(c+d)   
<details>
<summary>Solución</summary>

```c++
#include<iostream>
using namespace std;
int main(){
	float a,b,c,d,resultado = 0;
	
	cout<<"Digite el valor de a: "; cin>>a;
	cout<<"Digite el valor de b: "; cin>>b;
	cout<<"Digite el valor de c: "; cin>>c;
	cout<<"Digite el valor de d: "; cin>>d;
	
	resultado = (a+b) / (c+d);
	
	cout.precision(2);//recorta los números despues de la coma decimal a 2
	
	cout<<"El resultado es: "<<resultado;
	
	return 0;
}
```
</details>

##### 3. Escribe la siguiente expresión como expresión en C++: (a+(b/c))/(d+(e/f))  
<details>
<summary>Solución</summary>

```c++
#include<iostream>
using namespace std;

int main(){
	float a,b,c,d,e,f,resultado = 0;
	
	cout<<"Digite el valor de a: "; cin>>a;
	cout<<"Digite el valor de b: "; cin>>b;
	cout<<"Digite el valor de c: "; cin>>c;
	cout<<"Digite el valor de d: "; cin>>d;
	cout<<"Digite el valor de e: "; cin>>e;
	cout<<"Digite el valor de f: "; cin>>f;
	
	resultado = (a+(b/c))/(d+(e/f));
	
	cout.precision(2);//recorta los n�meros despues de la coma decimal a 2
	cout<<"El resultado es: "<<resultado;
	
	return 0;
}
```
</details>

##### 4. Escribe la siguiente expresión como expresión en C++: a + (b/(c-d))
<details>
<summary>Solución</summary>

```c++
#include<iostream>
using namespace std;
int main(){
	float a,b,c,d,resultado = 0;
	
	cout<<"Digite el valor de a: "; cin>>a;
	cout<<"Digite el valor de b: "; cin>>b;
	cout<<"Digite el valor de c: "; cin>>c;
	cout<<"Digite el valor de d: "; cin>>d;
	
	resultado = a + (b/(c-d));
	
	cout.precision(2);
	
	cout<<"El resultado es: "<<resultado;
	
	return 0;
}
```
</details>

##### 5. Escriba un fragmento de programa que intercambie los valores de dos variables. 
<details>
<summary>Solución</summary>

```c++
#include<iostream>
using namespace std;
int main(){
	int x,y, aux;
	
	cout<<"Digite el valor de x: "; cin>>x;
	cout<<"Digite el valor de y: "; cin>>y;
	
	aux = x;
	x = y;
	y = aux;
	
	cout<<"\nEl nuevo valor de x es: "<<x<<endl;
	cout<<"El nuevo valor de y es: "<<y<<endl;
	
	return 0;
}
```
</details>

##### 6. Escriba un programa que lea las tres notas de un alumno y calcule la nota final media de dicho alumno 
<details>
<summary>Solución</summary>

```c++
#include<iostream>
using namespace std;
int main(){
	float nota1, nota2, nota3;
	int notaFinalMedia;
	
	cout<<"Ingrese nota1: ";
	cin>>nota1;
	cout<<"Ingrese nota2: ";
	cin>>nota2;
	cout<<"Ingrese nota3: ";
	cin>>nota3;
	
	notaFinalMedia= (nota1+nota2+nota3)/3;
	
	cout<<"la final media es:"<<notaFinalMedia;
	
	return 0;
	
}
```
</details>

##### 7. La calificación final de un estudiante es el promedio de tres notas: la nota de prácticas que cuenta un 30% del total, la nota teórica que cuenta un 60% y la nota de participación que cuenta el 10% restante. Escriba un programa que lea las tres notas del alumno y escriba su nota final. 
<details>
<summary>Solución</summary>

```c++
#include<iostream>
using namespace std;
int main(){
	float notapractica, notateorica, notaparticipacion;
	int notaFinal;
	
	cout<<"ingrese la nota de practica: ";
	cin>>notapractica;
	cout<<"Ingrese la nota teoria: ";
	cin>>notateorica;
	cout<<"Ingrese la nota de participacion: ";
	cin>>notaparticipacion;
	
	notapractica= notapractica * 0.30;
	notateorica *=0.60;
	notaparticipacion *= 0.10;
	
	notaFinal = notaparticipacion + notateorica + notapractica;
	 
	cout<<"La nota final es: "<<notaFinal;
	return 0;
}  
```
</details>

##### 8. Escriba un programa que lea de la entrada estándar los dos catetos de un triángulo rectángulo y escriba en la salida estándar su hipotenusa. 
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<math.h>
using namespace std;
int main(){
	float cateto1,cateto2,hipotenusa;
	
	cout<<"Digite el cateto 1: "; cin>>cateto1;
	cout<<"Digite el cateto 2: "; cin>>cateto2;
	
	hipotenusa = sqrt(pow(cateto1,2)+pow(cateto2,2));
	
	cout<<"\nEl resultado de la hipotenusa es: "<<hipotenusa;
	
	return 0;
}
```
</details>

##### 9. Realice un programa que calcule el valor que toma la siguiente función para unos valores dados de x e y: f(x,y) = sqrt(x) / (pow(y,2)-1) 
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<math.h>
using namespace std;

int main(){
	float x,y,resultado = 0;
	
	cout<<"Digite el valor de x: "; cin>>x;
	cout<<"Digite el valor de y: "; cin>>y;
	
	resultado = sqrt(x)/(pow(y,2)-1);
	
	cout<<"\nEl resultado es: "<<resultado;
	
	return 0;
}
```
</details>

##### 10. Escriba un programa que calcule las soluciones de una ecuación de segundo grado de la forma ax^2 + bx + c = 0, teniendo en cuenta que: (-b+sqrt(pow(b,2)-4*a*c))/(2*a) y (-b-sqrt(pow(b,2)-4*a*c))/(2*a) 
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<math.h>
using namespace std;
int main(){
	float a,b,c,resultado1 = 0,resultado2 = 0;
	
	cout<<"Digite el valor de a: "; cin>>a;
	cout<<"Digite el valor de b: "; cin>>b;
	cout<<"Digite el valor de c: "; cin>>c;
	
	resultado1 = (-b+sqrt(pow(b,2)-4*a*c))/(2*a);
	resultado2 = (-b-sqrt(pow(b,2)-4*a*c))/(2*a);
	
	cout<<"\nEl resultado 1 es: "<<resultado1<<endl;
	cout<<"El resultado 2 es: "<<resultado2<<endl;
	
	
	return 0;
}
```
</details>