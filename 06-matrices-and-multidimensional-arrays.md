<h1 align="center">6. Matrices y Arreglos Multidimensionales (Matrices and Multidimensional Arrays)</h1>

<p align="justify">
En esta unidad se estudian las matrices en C++, estructuras de datos que permiten organizar elementos del mismo tipo en filas y columnas. Las matrices son una extensión de los arreglos unidimensionales y resultan útiles para representar y procesar información tabular, realizar cálculos matemáticos y trabajar con datos organizados en dos o más dimensiones.A través de los ejercicios, se aprenderá a declarar, llenar y recorrer matrices utilizando ciclos anidados, así como a copiar sus elementos y realizar operaciones como la transposición, la suma y la multiplicación de matrices.
</p>

## Conceptos principales

- **Declaración e inicialización de matrices:** creación de arreglos bidimensionales para almacenar datos organizados en filas y columnas.
- **Acceso mediante índices:** consulta y modificación de elementos utilizando los índices de fila y columna.
- **Recorrido de matrices:** utilización de ciclos anidados para procesar todos los elementos de una matriz.
- **Dimensiones de una matriz:** identificación del número de filas y columnas y su relación con el almacenamiento de los datos.
- **Diagonal principal:** identificación de los elementos cuya posición de fila coincide con su posición de columna.
- **Copia de matrices:** transferencia de los elementos de una matriz a otra.
- **Matriz transpuesta:** intercambio de filas por columnas para obtener una nueva organización de los elementos.
- **Matrices simétricas:** comprobación de si una matriz cuadrada es igual a su transpuesta.
- **Operaciones con matrices:** realización de sumas y productos entre matrices, respetando las condiciones necesarias para cada operación.

## Objetivo

Comprender cómo se representan y manipulan las matrices en C++, desarrollar programas que recorran y transformen sus elementos, y aplicar ciclos anidados para resolver problemas relacionados con operaciones matriciales y procesamiento de datos bidimensionales.

## Ejercicios

##### 1. Hacer un programa para rellenar una matriz pidiendo al usuario el número de filas y columnas, Posteriormente mostrar la matriz en pantalla.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	int numeros[100][100],filas,columnas;
	
	cout<<"Digite el numero de filas: "; cin>>filas;
	cout<<"Digite el numero de columnas: "; cin>>columnas;
	
	//Rellenando la matriz	
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			cout<<"Digite un numero ["<<i<<"]["<<j<<"]: ";
			cin>>numeros[i][j];
		}
	} 
	
	cout<<"\nMostrando matriz\n\n";
	
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			cout<<numeros[i][j];
		}
		cout<<"\n";
	}
	
	
	getch();
	return 0;
}
```
</details>

##### 2. Realiza un programa que defina una matriz de 3x3 y escriba un ciclo para que muestre la diagonal principal de la matriz.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	int numeros[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	
	cout<<"Mostrando Matriz completa\n";
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<numeros[i][j];
		}
		cout<<"\n";
	}
	
	cout<<"\n\nMostrando diagonal principal de la matriz\n";
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(i==j){
				cout<<numeros[i][j]<<endl;
			}
		}
	}
	
	getch();
	return 0;
}
```
</details>

##### 3. Hacer una matriz de tipo entera de 2 * 2, llenarla de números y luego copiar todo su contenido hacia otra matriz.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	int matriz1[2][2] = {{1,2},{3,4}};
	int matriz2[2][2];
	
	//Copiando el contenido de la matriz1 hacia matriz2
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			matriz2[i][j]=matriz1[i][j];
		}
	}
	
	//Mostrando matriz2
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			cout<<matriz2[i][j];
		}
		cout<<"\n";
	}	
	
	getch();
	return 0;
}
```
</details>

##### 4. Hacer una matriz preguntando al usuario el numero de filas y columnas,llenarla de números aleatorios, copiar el contenido a otra matriz y por último mostrarla en pantalla.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main(){
	int matriz[100][100],filas,columnas;
	int matriz2[100][100],dato=0;
	
	cout<<"Digite el numero de filas: "; cin>>filas;
	cout<<"Digite el numero de columnas: "; cin>>columnas;
	
	srand(time(NULL));
	
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			dato = 1+rand()%(100); //numeros aleatorios de 1 a 100
			matriz[i][j] = dato;
		}
	}
	
	//Copiando el contenido a una nueva matriz
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			matriz2[i][j] = matriz[i][j];
		}
	}
	
	//Mostrando en pantalla la nueva matriz
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			cout<<matriz2[i][j]<<"  ";
		}
		cout<<"\n";
	}
	
	system("pause");
	return 0;
}
```
</details>

##### 5. Realice un programa que lea una matriz de 3x3 y cree su matriz traspuesta. La matriz traspuesta es aquella en la que la columna i era la fila i de la matriz original.
```text
| 1 2 3 |             | 1 4 7 |
| 4 5 6 |     -->     | 2 5 8 |
| 7 8 9 |             | 3 6 9 |
```
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>

using namespace std;

int main(){
	int numeros[3][3];
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<"Digite un numero ["<<i<<"]["<<j<<"]: ";
			cin>>numeros[i][j];
		}
	}
	
	cout<<"\nMatriz Normal\n";
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<numeros[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	cout<<"\nMatriz Transpuesta\n";
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<numeros[j][i]<<" ";
		}
		cout<<"\n";
	}
	
	
	getch();
	return 0;
}
```
</details>

##### 6. Realice un programa que calcule la suma de dos matrices cuadradas de 3x3.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	int matriz1[3][3] = {{2,0,1},{3,0,0},{5,1,1}};
	int matriz2[3][3] = {{1,0,1},{1,2,1},{1,1,0}};
	
	//Mostrando las 2 matrices
	cout<<"Matriz 1\n";
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<matriz1[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	cout<<"\nMatriz 2\n";
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<matriz2[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	//Sumando matrices
	cout<<"\nSuma de matrices\n";
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<matriz1[i][j]+matriz2[i][j]<<" ";
		}
		cout<<"\n";
	}
		
	return 0;
}
```
</details>

##### 7. Desarrollar un programa que determine si una matriz es simétrica o no. Una matriz es simétrica si es cuadrada y si es igual a su matriz transpuesta.
```text
| 8 1 3 |             | 8 1 3 |
| 1 7 4 |      -->    | 1 7 4 | 
| 3 4 9 |             | 3 4 9 |
```
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	int numeros[100][100],filas,columnas;
	char band='F';
	
	cout<<"Digite el numero de filas: "; cin>>filas;
	cout<<"Digite el numero de columnas: "; cin>>columnas;
	
	//Rellenando matriz
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			cout<<"Digite un numero ["<<i<<"]["<<j<<"]: ";
			cin>>numeros[i][j];
		}
	}
	
	//Comprobemos si es simetrica
	if(filas==columnas){
		for(int i=0;i<filas;i++){
			for(int j=0;j<columnas;j++){
				if(numeros[i][j] == numeros[j][i]){
					band='V';
				}
			}
		}
	}

	if(band=='V'){
		cout<<"\nEs una matriz simetrica";
	}
	else{
		cout<<"\nNo es una matriz simetrica";
	}
	
	
	getch();
	return 0;
}
```
</details>

##### 8. Realice un programa que calcule el producto de dos matrices cuadradas de 3x3.
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	int A[3][3]={{1,2,0},{2,-1,-1},{3,2,3}};
	int B[3][3]={{2,1,1},{-1,1,3},{1,2,4}};
	int C[3][3];
	
	//Multiplicando las matrices
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			C[i][j]=0;
			for(int k=0;k<3;k++){
				C[i][j] = C[i][j] + A[i][k]*B[k][j];
			}
		}
	}
	
	//Resultado de la multiplicacion
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<C[i][j]<<"  ";
		}
		cout<<"\n";
	}	
	
	getch();
	return 0;
}
```
</details>

---