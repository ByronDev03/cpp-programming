<h1 align="center">22. Algoritmos Recursivos</h1>

<p align="justify">
En esta unidad se estudian los algoritmos recursivos en C++, una técnica de programación que consiste en resolver un problema mediante funciones que se llaman a sí mismas, dividiendo una tarea en problemas más pequeños hasta alcanzar una condición que permita detener las llamadas. A través de los ejercicios, se trabajará con casos base y casos recursivos, así como con la recursividad directa, indirecta y su comparación con soluciones iterativas. Se aplicarán estos conceptos en diferentes problemas y algoritmos, como la suma de los dígitos de un número, las Torres de Hanoi, la búsqueda binaria recursiva y el ordenamiento por mezclas (MergeSort). También se resolverán problemas de búsqueda y exploración mediante la técnica de vuelta atrás (*Backtracking*), incluyendo el recorrido del caballo por un tablero de ajedrez y el problema de las cuatro reinas.</p>

## Conceptos principales
- **Recursividad directa:** utilización de funciones que se llaman a sí mismas para resolver un problema.
- **Recursividad indirecta o mutua:** interacción entre dos o más funciones que se llaman entre sí.
- **Caso base:** condición que detiene las llamadas recursivas y permite obtener un resultado.
- **Caso recursivo:** parte de la función que reduce el problema y realiza una nueva llamada a sí misma.
- **Recursividad e iteración:** comparación entre la resolución de problemas mediante llamadas recursivas y estructuras repetitivas.
- **Suma recursiva de dígitos:** descomposición de un número para sumar sus dígitos mediante operaciones aritméticas.
- **Torres de Hanoi:** resolución de un problema de movimiento de discos utilizando llamadas recursivas.
- **Búsqueda binaria recursiva:** localización de un elemento en un arreglo ordenado mediante la división del intervalo de búsqueda.
- **Ordenamiento por mezclas (MergeSort):** división de un arreglo en subarreglos, ordenamiento recursivo y combinación de sus elementos.
- **Backtracking (vuelta atrás):** exploración de posibles soluciones, retrocediendo cuando un camino no permite alcanzar el objetivo.
- **Problemas de recorrido y colocación:** aplicación de la recursividad y la vuelta atrás en el recorrido del caballo y la colocación de reinas en un tablero de ajedrez.

## Objetivo
Comprender y aplicar la recursividad en C++, identificando los casos base y recursivos para resolver problemas mediante la descomposición de tareas, implementar algoritmos de búsqueda y ordenamiento, y utilizar la técnica de vuelta atrás para explorar posibles soluciones en problemas de mayor complejidad.

## Apuntes
- **Algoritmos Recursivos** → [Ver apunte](/notes/.md) 

## Ejercicios

##### 1. Hacer un programa que muestre el alfabeto, carácter a carácter, utilizando recursividad mutua o indirecta. 
<details>
<summary>Solución</summary>

```c++
#include<iostream>
using namespace std;

//Prototipos de funciones
void funcionA(char);
void funcionB(char);

int main(){
	cout<<"Alfabeto: ";
	funcionA('Z');
	cout<<endl;
	
	return 0;
}

void funcionA(char letra){
	if(letra > 'A'){
		funcionB(letra);	
	}
	
	cout<<letra<<" ";
}

void funcionB(char letra){
	funcionA(--letra);
}
```
</details>

##### 2. Dado un número natural N, obtener la suma de los dígitos de que consta. Presentar un algoritmo recursivo y otro iterativo. 
<details>
<summary>Solución</summary>

```c++
#include<iostream>
using namespace std;

//Solucion Recursiva
int sumaRecursiva(int n){
	if(n<=9){ // Caso base
		return n;
	}
	else{ // Caso recursivo   
		return sumaRecursiva(n/10) + n%10;
	}
}

//Solucion Iterativa
int sumaIterativa(int n){
	int suma=0;

	while(n > 9){
		suma += n%10;
		n /= 10;
	}
	
	return (suma+n);
}

int main(){
	int numero;
	
	cout<<"Digite un numero: ";
	cin>>numero;
	
	cout<<"\nLa suma de los digitos del numero es: "<<endl;
	cout<<"Algoritmo recursivo: "<<sumaRecursiva(numero)<<endl;
	cout<<"Algoritmo Iterativo: "<<sumaIterativa(numero)<<endl;
	
	return 0;
}
```
</details>

##### 3. Torres de Hanoi 
<details>
<summary>Solución</summary>

```c++
#include<iostream>
using namespace std;

void hanoi(char varInicial,char varCentral,char varFinal,int n){
	if(n==1){ //Caso base
		cout<<"Mover disco "<<n<<" desde varilla "<<varInicial
		<<" a varilla "<<varFinal<<endl;
	}
	else{ //Caso recursivo
		hanoi(varInicial,varFinal,varCentral,n-1);
		cout<<"Mover disco "<<n<<" desde varilla "<<varInicial
		<<" a varilla "<<varFinal<<endl;
		hanoi(varCentral,varInicial,varFinal,n-1);
	}
}

int main(){
	
	hanoi('A','B','C',3);
	
	return 0;
}
```
</details>

##### 4. Búsqueda binaria Recursiva 
<details>
<summary>Solución</summary>

```c++
#include<iostream>
using namespace std;

int busquedaBinaria(int a[],int dato,int inferior,int superior){
	int mitad;
	if(inferior > superior){ //No encontrado
		return -1;
	}
	else{
		mitad = (inferior+superior)/2;
		if(dato == a[mitad]){ //Caso base
			return mitad;
		}
		else if(dato > a[mitad]){
			return busquedaBinaria(a,dato,mitad+1,superior);
		}
		else{
			return busquedaBinaria(a,dato,inferior,mitad-1);
		}
	}
}

int main(){
	int arreglo[] = {3,4,5,8,9,10};
	int dato = 12;
	
	int retorno = busquedaBinaria(arreglo,dato,0,5);
	
	if(retorno == -1){
		cout<<"El dato no ha sido encontrado"<<endl;
	}
	else{
		cout<<"El dato si ha sido encontrado"<<endl;
		cout<<"Posicion: "<<retorno<<endl;
	}
	
	return 0;
}
```
</details>

##### 5. Ordenamiento por Mezclas - MergeSort 
<details>
<summary>Solución</summary>

```c++
#include<iostream>
using namespace std;

void mezcla(int a[],int izquierda,int medio,int derecha){
	int* aux;
	int i,k,z;
	aux = new int[derecha-izquierda + 1];
	i = z = izquierda;
	k = medio + 1;
	
	//bucle para la mezcla, utiliza aux[] como arreglo auxiliar
	while(i<=medio && k<=derecha){
		if(a[i] <= a[k]){
			aux[z++] = a[i++];
		}
		else{
			aux[z++] = a[k++];
		}
	}
	
	//Se mueven elementos no mezclados de sublistas
	while(i<=medio){
		aux[z++] = a[i++];
	}
	
	while(k<=derecha){
		aux[z++] = a[k++];
	}
	
	//Copia de elementos de aux[] hacia a[]
	for(int i=izquierda; i<=derecha;i++){
		a[i] = aux[i];
	}
	
	delete aux;
}

void mergesort(int a[],int primero,int ultimo){
	int central;
	
	if(primero < ultimo){
		central = (primero+ultimo)/2;
		mergesort(a,primero,central);
		mergesort(a,central+1,ultimo);
		mezcla(a,primero,central,ultimo);
	}
}

int main(){
	int arreglo[] = {5,7,2,1,9,10,16,25,8};
	
	mergesort(arreglo,0,8);
	
	for(int i=0;i<9;i++){
		cout<<arreglo[i]<<endl;
	}
	
	return 0;
}
```
</details>

##### 6. Algoritmo Salto del caballo 
<details>
<summary>Solución</summary>

```c++
#include<iostream>
using namespace std;

const int N = 5;

int tablero[N][N];

//Desplazamientos relativos del caballo
int d[8][2] = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};

void escribeTablero(){
	int i,j;
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			cout<<tablero[i][j]<<"|";
		}
		cout<<endl;
	}
	cout<<endl;
}

void saltoCaballo(int i,int x,int y,bool &exito){
	int nx,ny;
	int k=0;  // inicializa contador de posibles 8 movimientos
	exito=false;
	
	do{
		k++;
		nx = x + d[k-1][0];
		ny = y + d[k-1][1];
		
		//Determina si nuevas coordenadas son aceptables
		if((nx>=0) && (nx<N) && (ny>=0) && (ny<N) && (tablero[nx][ny]==0)){
			//Anota movimiento
			tablero[nx][ny] = i;
			escribeTablero();
			
			if(i < N*N){
				saltoCaballo(i+1,nx,ny,exito);
	
				//Analiza si se ha completado la soluci�n
				if(!exito){
					tablero[nx][ny] = 0; // no se alcanzo la soluci�n, se borra anotaci�n
				}
			}
			else{
				exito = true; //Caballo a cubierto el tablero
	 		}
		}
	}while((k<8) && !exito);
}

int main(){
	bool exito;
	int fila = 2;
	int col = 2;

	tablero[fila][col] = 1;
		
	saltoCaballo(2,fila,col,exito);
	
	if(exito){
		cout<<"\nCamino encontrado"<<endl;
		escribeTablero();
	}
	else{
		cout<<"\nCamino no encontrado"<<endl;
	}
	 
	return 0;
}
```
</details>

##### 7. Problema de las N Reinas (Backtracking)
<details>
<summary>Solución</summary>

```c++
#include<iostream>
using namespace std;

//Prototipos de Funciones
void ponerReina(int,bool&);
bool valido(int);
void mostrarTablero();

const int N = 4;
int reinas[N];

int main(){
	bool solucion;
	
	ponerReina(0,solucion);
	
	if(solucion){
		cout<<"Si existe combinacion de reinas"<<endl;
		mostrarTablero();
	}
	else{
		cout<<"No existe combinacion de reinas"<<endl;
	}
	
	return 0;
}

void mostrarTablero(){
	int tablero[N][N];
	
	cout<<"\nMostrar las reinas"<<endl;
	for(int i=0;i<N;i++){
		cout<<reinas[i]<<"|";
	}
	
	cout<<endl<<endl;
	
	//Inicializamos todas las casillas del tablero en 0
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			tablero[i][j] = 0;
		}
	}

	//Asignamos las reinas (1) en el tablero
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			tablero[reinas[j]][j] = 1;
		}
	}
	
	//Mostramos el tablero
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<tablero[i][j]<<"|";
		}
		cout<<endl;
	}
}

void ponerReina(int i,bool &solucion){
	int k=0; //Inicializa contador de movimientos
	solucion = false;
	
	do{
		reinas[i] = k; // Coloca y anota reina i en la fila k
		k++;
		
		mostrarTablero();
		cout<<endl;
		
		if(valido(i)){
			if(i<(N-1)){
				ponerReina(i+1,solucion);
				
				//vuelta atras
				if( !solucion ){
					reinas[i] = 0;
				}
			}
			else{ //Todas las reinas colocadas
				solucion = true;
			}
		}
	}while(!solucion && (k<N));	
}

bool valido(int i){
	/*Comprueba si la reina de la columna i es atacada por 
	alguna reina colocada anteriormente*/
	
	bool v = true;
	
	for(int r=0; r<i; r++){
		v = v && (reinas[r] != reinas[i]); //No este en la misma fila
		v = v && ((reinas[i]-i) != (reinas[r]-r)); // Diagonal 1
		v = v && ((reinas[i]+i) != (reinas[r]+r)); // Diagonal 2
	}
	
	return v;
}
```
</details>