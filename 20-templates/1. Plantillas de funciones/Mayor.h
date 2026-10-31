#include<iostream>
using namespace std;

//Plantilla de Funcion
template <typename T,typename T2>
T2 mayor(T dato1, T2 dato2){
	if(dato1>=dato2){
		return dato1;
	}
	else{
		return dato2;
	}
}
