<h1 align="center">23. Biblioteca Estándar de Plantillas</h1>

<p align="justify">
En esta unidad se estudia la Biblioteca Estándar de Plantillas (STL) de C++, un conjunto de herramientas que proporciona contenedores, iteradores y algoritmos genéricos para almacenar, recorrer, organizar y manipular datos de manera eficiente. A través de los ejercicios, se conocerán diferentes tipos de contenedores, como vector, deque y list, así como sus operaciones para insertar, eliminar, ordenar y acceder a sus elementos. También se trabajará con iteradores para recorrer los contenedores y acceder a sus elementos, utilizando diferentes categorías de iteradores y funciones para mostrar información. Finalmente, se aplicarán algoritmos de la STL para generar, copiar, buscar, ordenar, filtrar, transformar y realizar operaciones matemáticas sobre colecciones de datos. Además, se estudiarán los contenedores asociativos set, multiset, map y multimap, que permiten almacenar elementos y relacionar claves con valores.</p>

## Conceptos principales
- **Contenedores de secuencia:** utilización de `vector`, `deque` y `list` para almacenar y organizar colecciones de elementos.
- **Operaciones con contenedores:** inserción y eliminación de elementos mediante `push_back()`, `push_front()`, `pop_back()`, `pop_front()`, `insert()` y `erase()`.
- **Iteradores:** utilización de objetos que permiten recorrer y acceder a los elementos de los contenedores.
- **Categorías de iteradores:** trabajo con iteradores de acceso aleatorio (*Random Access Iterators*) y de avance (*Forward Iterators*).
- **Acceso a los elementos:** utilización de `begin()`, `end()`, `rbegin()` y `rend()` para establecer rangos de recorrido.
- **Iteradores de flujo:** uso de `istream_iterator` y `ostream_iterator` para leer y mostrar datos mediante flujos de entrada y salida.
- **Algoritmos de la STL:** utilización de funciones como `generate()`, `copy()` y `find()` para generar, copiar y buscar elementos.
- **Algoritmos de búsqueda y ordenamiento:** aplicación de `find_if()` y `sort()` para localizar elementos mediante condiciones y ordenar colecciones.
- **Algoritmos matemáticos:** utilización de `max_element()`, `min_element()`, `accumulate()` y `count_if()` para obtener valores máximos, mínimos, sumas, promedios y conteos.
- **Algoritmos de transformación:** aplicación de `for_each()`, `transform()` y `random_shuffle()` para modificar, transformar y reorganizar elementos.
- **Contenedores asociativos:** utilización de `set` y `multiset` para almacenar conjuntos ordenados, con o sin elementos duplicados.
- **Contenedores de pares clave-valor:** uso de `map` y `multimap` para relacionar claves con valores, permitiendo realizar búsquedas, inserciones y eliminaciones.

## Objetivo
Comprender y aplicar los componentes fundamentales de la Biblioteca Estándar de Plantillas (STL) en C++, utilizando contenedores, iteradores y algoritmos genéricos para almacenar, recorrer, buscar, ordenar, transformar y procesar colecciones de datos, así como administrar información mediante contenedores asociativos.

## Ejercicios

##### 1. Contenedor lineal - vector
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<int> numeros; //Arreglos de enteros
	
	numeros.push_back(5); //Agrega elementos al final del arreglo
	numeros.push_back(10);
	numeros.push_back(1);
	numeros.push_back(15);
	numeros.push_back(20);
	
	numeros[2] = 7;
	
	//Mostrar los elementos del arreglo
	for(int i=0;i<numeros.size();i++){
		cout<<numeros[i]<<"|";
	}
	
    //numeros.pop_back(); //Elimina el ultimo elemento del arreglo
	
    //numeros.erase(numeros.begin()+1,numeros.begin()+3);
	return 0;
}
```
</details>

##### 2. Contenedor lineal - deque (doble cola)
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<deque>
using namespace std;

int main(){
	deque<char> letras;
	
	// A B C D E F
	
	letras.push_front('C'); //Agregar elementos al principio
	letras.push_front('B');
	letras.push_front('A');
	
	letras.push_back('D'); //Agregar elementos por el final
	letras.push_back('E'); 
	letras.push_back('F');
	
	//Mostrar los elementos
	for(int i=0;i<letras.size();i++){
		cout<<letras[i]<<"|";
	}
	
	letras.pop_front(); //Eliminamos por el principio
	letras.pop_back(); //Eliminamos por el final
	
	cout<<endl;
	
	//Mostrar los elementos
	for(int i=0;i<letras.size();i++){
		cout<<letras[i]<<"|";
	}
	
	return 0;
}
```
</details>

##### 3. Contenedor lineal - list
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<list>
using namespace std;

int main(){
	list<int> datos;
	
	// 7 2 5 1 6
	
	//insertar elementos
	datos.push_back(5);
	datos.push_back(1);
	datos.push_back(6);
	
	datos.push_front(2);
	datos.push_front(7);
	
	//Ordenar la lista
	datos.sort();
	
	// 1 2 5 6 7
	
	//Crear un iterador para listas llamado i
	list<int>::iterator i;
	
	//Hacer que i apunte al primer elemento de la lista
	i = datos.begin();
	
	//Recorrer la lista incrementando i hasta llegar al final
	while(i != datos.end()){
		cout<< *i <<"|";
		
		i++;
	}
	
	cout<<endl;
	
	//Eliminamos elementos
	datos.pop_front();
	datos.pop_back();
	
	//Hacer que i apunte al primer elemento de la lista
	i = datos.begin();
	
	//Recorrer la lista incrementando i hasta llegar al final
	while(i != datos.end()){
		cout<< *i <<"|";
		
		i++;
	}
	
	return 0;
}
```
</details>

##### 4. Iteradores - Random acces iterators
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

//Funcion template para mostrar los elementos de un contenedor
template <class Iter>
void mostrarEnPantalla(Iter inicio,Iter final){
	while(inicio != final){
		cout<<*inicio <<"|";
		inicio++;
	}
}

int main(){
	vector<char> letras(10); //Creamos un arreglo de char (10 elementos)
	
	//Agregamos letras aleatorias entre A-Z
	for(int i=0;i<10;i++){
		letras[i] = 'A' + (rand() % 26);
	}
	
	//Visualizar el contenido
	mostrarEnPantalla(letras.begin(),letras.end());
	cout<<endl;
	
	//Visualizar el contenido en orden inverso
	mostrarEnPantalla(letras.rbegin(),letras.rend());
	cout<<endl;
	
	//Visualizamos solo los elementos del medio (1-8)
	mostrarEnPantalla(letras.begin()+1,letras.end()-1);
	cout<<endl;
	
	return 0;
}
```
</details>

##### 5. Iteradores - Forward iterators
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<fstream>  //para archivos
#include<iterator> //para streams_iterators
#include<cstdlib>
#include<vector>
using namespace std;

int main(){
	ifstream archivo;
	
	archivo.open("documento.txt",ios::in);
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}

	istream_iterator<char> p(archivo);
	
	vector<char> frase;
	while(!archivo.eof()){	
	
		frase.push_back(*p); //Agregamos al vector
		p++;
	}

	//Mostramos el contenido de frase
	for(int i=0;i<frase.size();i++){
		cout<<frase[i];
	}
	cout<<endl;
	
	archivo.close();
	return 0;
}
```
</details>

##### 6. Algoritmos - Iniciando con algorithm
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<list>
#include<iterator>
#include<algorithm>
#include<cstdlib>
using namespace std;

int numerosAleatorios(){
	return rand()%10;
}

int main(){
	list<int> valores(10); //Lista de 10 valores enteros
	
	//Generar elementos aleatorios para la lista
	generate(valores.begin(),valores.end(),numerosAleatorios);
	
	//Mostrar los elementos de la lista por pantalla
	ostream_iterator<int> salida(cout,"|");
	copy(valores.begin(),valores.end(),salida);
	
	//Buscar la primera aparicion del numero 8 en la lista
	list<int>::iterator i;
	i = find(valores.begin(),valores.end(),8);
	
	cout<<endl;
	
	//Analizamos si i quedo dentro del rango de busqueda
	if(i != valores.end()){
		cout<<"El valor "<<*i<<" esta en la lista"<<endl;
	}
	else{
		cout<<"El valor no esta en la lista"<<endl;
	}
	
	return 0;
}
```
</details>

##### 7. Algoritmos de Búsqueda y Ordenamiento
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<cstdlib>
using namespace std;

int numerosAleatorios(){
	return rand()%30;
}

//Funcion logica para saber si un numero es par
template <class T>
bool esPar(T valor){
	return ((valor%2) == 0);
}

int main(){
	vector<int> valores(10);
	
	//Generar numeros aleatorios y almacenarlos en el vector
	generate(valores.begin(),valores.end(),numerosAleatorios);
	
	//Mostrar los elementos de vector
	copy(valores.begin(),valores.end(),ostream_iterator<int> (cout,"|"));
	
	cout<<"\n\nNumeros pares del vector"<<endl;
	
	//Creamos un vector para almacenar los elementos pares
	vector<int> pares;
	
	//Creamos un iterador y lo inicializamos al principio de vector(valores)
	vector<int>::iterator i = valores.begin();
	
	while((i=find_if(i,valores.end(),esPar<int>)) != valores.end()){
		pares.push_back(*i);
		i++;
	}
	
	//Ordenamos el vector pares 
	sort(pares.begin(),pares.end());
	
	//Mostramos por pantalla
	copy(pares.begin(),pares.end(),ostream_iterator<int> (cout,"|"));
	
	return 0;
}
```
</details>

##### 8. Algoritmos STL - Matemáticos
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<fstream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<numeric> //para accumulate
using namespace std;

//Funcion para comprobar si un numero es positivo
template <class T>
bool esPositivo(T valor){
	return (valor>=0);
}

int main(){
	vector<float> numeros;
	
	//Abrimos el archivo en modo lectura
	ifstream archivo("archivoNumerico.txt",ios::in);
	
	//Copiamos los numeros del archivo hacia el vector numeros
	copy(istream_iterator<float>(archivo),istream_iterator<float>(),back_inserter(numeros));
	
	//Cerramos el archivo
	archivo.close();
	
	//Calcular el maximo y minimo elemento del vector
	cout<<"Maximo: "<<*max_element(numeros.begin(),numeros.end())<<endl;
	cout<<"Minimo: "<<*min_element(numeros.begin(),numeros.end())<<endl;
	
	//Calcular el valor promedio
	cout<<"\nValor promedio: "
	<<accumulate(numeros.begin(),numeros.end(),0.0)/numeros.size()<<endl;
	
	//Cantidad de elementos positivos
	cout<<"Cantidad de numeros positivos: "
	<<count_if(numeros.begin(),numeros.end(),esPositivo<float>)<<endl;
	
	return 0;
}
```
</details>

##### 9. Algoritmos STL - Transformación
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

//Funcion para pasar un letra a MAYUSCULA
void mayusculas(char &letra){
	if(letra>='a' && letra<='z'){
		letra = letra - ('a' - 'A');
	}
}

//Funcion unaria para identificar vocales
char vocales(char letra){
	return (letra=='A'||letra=='E'||letra=='I'||letra=='O'||letra=='U') ? letra : '-';
}

int main(){
	vector<char> letras;
	
	//generar un vector con letras en minuscula
	for(int i=0;i<10;i++){
		letras.push_back('a' + i);
	}
	
	//mostramos en pantalla
	copy(letras.begin(),letras.end(),ostream_iterator<char> (cout,"|"));
	cout<<endl;
	
	//Desordenamos las letras
	random_shuffle(letras.begin(),letras.end());
	
	cout<<"\nVector desordenado: "<<endl;
	
	//mostramos en pantalla
	copy(letras.begin(),letras.end(),ostream_iterator<char> (cout,"|"));
	cout<<endl;
	
	//Aplicar a cada elemento la funcion mayusculas
	for_each(letras.begin(),letras.end(),mayusculas);
	
	cout<<"\nVector en Mayusculas"<<endl;
	
	//mostramos en pantalla
	copy(letras.begin(),letras.end(),ostream_iterator<char> (cout,"|"));
	cout<<endl;
	
	cout<<"\nVocales encontradas"<<endl;
	
	//buscar las vocales
	transform(letras.begin(),letras.end(),
		ostream_iterator<char> (cout,"|"),vocales);
	
	return 0;
}
```
</details>

##### 10. Contenedores Asociativos - Set y Multiset  
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<iterator>
#include<algorithm>
#include<set> //para set y multiset
using namespace std;

int main(){
	set<int> valores;
	
	//Insertar valores en set (Conjunto) 
	valores.insert(10);
	valores.insert(3);
	valores.insert(15);
	valores.insert(1);
	valores.insert(5);
	
	//Mostramos los valores por pantalla
	copy(valores.begin(),valores.end(),ostream_iterator<int> (cout,"|"));
	cout<<endl;
	
	//Buscar un elemento en set (conjunto)
	set<int>::iterator i = valores.find(2);
	
	if(i != valores.end()){
		cout<<"\nEl valor "<<*i<<" si existe en el set (conjunto)"<<endl;
	}
	else{
		cout<<"\nEl valor no existe"<<endl;
	}
	
	//Eliminar un elemento en el set (Conjunto)
	
	valores.erase(1);
	
	//Mostramos los valores por pantalla
	copy(valores.begin(),valores.end(),ostream_iterator<int> (cout,"|"));
	cout<<endl;
	
	return 0;
}
```
</details>

##### 11. Contenedores Asociativos - Set y Multiset  
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<iterator>
#include<algorithm>
#include<set> //para set y multiset
using namespace std;

int main(){
	multiset<int> valores; //Creamos un multiset (MultiConjunto)
	
	//Insertar elementos
	valores.insert(5);
	valores.insert(10);
	valores.insert(11);
	valores.insert(1);
	valores.insert(3);
	
	//Mostrar por pantalla
	copy(valores.begin(),valores.end(),ostream_iterator<int> (cout,"|"));
	cout<<endl;
	
	//Insertamos valores duplicados
	valores.insert(10);
	valores.insert(3);
	valores.insert(3);
	valores.insert(3);
	
	//Mostrar por pantalla
	copy(valores.begin(),valores.end(),ostream_iterator<int> (cout,"|"));
	cout<<endl;
	
	//Buscar un elemento
	multiset<int>::iterator i = valores.find(2);
	
	if(i != valores.end()){
		cout<<"\nEl valor "<<*i<<" si ha sido encontrado"<<endl;
	}
	else{
		cout<<"\nEl valor no ha sido encontrado"<<endl;
	}
	
	//Contar las apariciones de 3
	cout<<"El valor de 3 aparece "<<valores.count(3)
	<<" veces en el multiset"<<endl;
	
	//Eliminar elementos del multiset
	valores.erase(3);
	
	//Mostrar por pantalla
	copy(valores.begin(),valores.end(),ostream_iterator<int> (cout,"|"));
	cout<<endl;
	
	return 0;
}
```
</details>

##### 12. Contenedores Asociativos - map y multimap
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<iterator>
#include<map>
using namespace std;

typedef pair<int,string> par;

int main(){
	map<int,string> valores; //Creamos un map<clave,valor>
	
	//Insertar elementos
	valores.insert(par(5,"Alejandro"));
	valores.insert(par(2,"Estefany"));
	valores.insert(par(1,"Fatima"));
	valores.insert(par(7,"Juan"));
	
	//Mostrar los valores del map
	map<int,string>::iterator i;
	for(i=valores.begin(); i!=valores.end();i++){
		cout<<"Clave: "<<i->first<<" | Valor: "<<i->second<<endl;
	}
	cout<<endl;
	
	//Buscar un valor por su clave
	i = valores.find(1);
	
	if(i != valores.end()){
		cout<<"Valor encontrado = "<<i->second<<endl;
	}
	else{
		cout<<"Valor no encontrado"<<endl;
	}
	cout<<endl;
	
	//Eliminar un elemento
	valores.erase(7);
	
	//Mostrar los valores del map
	for(i=valores.begin(); i!=valores.end();i++){
		cout<<"Clave: "<<i->first<<" | Valor: "<<i->second<<endl;
	}
	cout<<endl;
	
	return 0;
}
```
</details>

##### 13. Contenedores Asociativos - map y multimap
<details>
<summary>Solución</summary>

```c++
#include<iostream>
#include<iterator>
#include<map>
using namespace std;

typedef pair<int,string> par;

int main(){
	multimap<int,string> valores; //Creamos un multimap <clave,valor>
	
	//Insertar valores en el multimap
	valores.insert(par(3,"Jose"));
	valores.insert(par(2,"Maria"));
	valores.insert(par(5,"Alejandro"));
	valores.insert(par(1,"Estefany"));
	
	//Insertar elementos con claves repetidas
	valores.insert(par(1,"Kathy"));
	valores.insert(par(5,"Miguel"));
	valores.insert(par(5,"Paola"));
	
	//Mostrar por pantalla
	multimap<int,string>::iterator i;
	for(i=valores.begin(); i!=valores.end();i++){
		cout<<"Clave: "<<i->first<<" | Valor: "<<i->second<<endl;
	}
	cout<<endl;
	
	//Contar la cantidad de veces que aparece una clave
	cout<<"Conteo de la clave 5: "<<valores.count(5)<<endl;
	for(i=valores.lower_bound(5); i!=valores.upper_bound(5);i++){
		cout<<i->second<<" | ";
	}
	
	return 0;
}
```
</details>