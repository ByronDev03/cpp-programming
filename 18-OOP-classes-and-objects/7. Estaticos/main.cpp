//Miembros static de una clase

#include <iostream>
#include "Estatico.h"

using namespace std; 

int main(int argc, char** argv) {
	Estatico* ob1 = new Estatico();
	Estatico* ob2 = new Estatico();
	Estatico* ob3 = new Estatico();
	
	cout<<ob1->getContador()<<endl;
	
	cout<<"La suma es: "<<Estatico::sumar(4,5);
	
	return 0;
}
