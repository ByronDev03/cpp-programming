/*Ejercicio 2: Definir dos plantillas de funciones dentro de un archivo de 
cabecera llamado “ordenar.h” que puedan ordenar tanto ascendentemente como 
descendentemente un arreglo de N elementos, recuerde que puede utilizar la 
plantilla intercambiar del ejercicio anterior.*/

#include <iostream>
#include "Ordenar.h"
using namespace std;

template <typename T>
void pedirDatos(T *arreglo,int n){
	for(int i=0;i<n;i++){
		cout<<"Digite un elemento["<<i<<"]: ";
		cin>>arreglo[i];
	}
}

template <typename T>
void mostrarArreglo(T *arreglo,int n){
	for(int i=0;i<n;i++){
		cout<<"Elemento["<<i<<"]: "<<arreglo[i]<<endl;
	}
}

int main(int argc, char** argv) {
	int nElementos;
	
	cout<<"Digite la cantidad de elementos del arreglo: ";
	cin>>nElementos;
	
	char *elementos = new char[nElementos];
	
	cout<<"\nPidiendo los elementos del arreglo:"<<endl;
	pedirDatos(elementos,nElementos);
	
	//Ordenamos los elementos del arreglo Ascendentemente
	ordenarAscendente(elementos,nElementos);
	
	cout<<"\nArreglo ordenado Ascendentemente: "<<endl;
	mostrarArreglo(elementos,nElementos);
	
	//Ordenamos los elementos del arreglo Descendentemente
	ordenarDescendente(elementos,nElementos);
	
	cout<<"\nArreglo ordenado Descendentemente: "<<endl;
	mostrarArreglo(elementos,nElementos);
	
	
	delete[] elementos;
	return 0;
}
