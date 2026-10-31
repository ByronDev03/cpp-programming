//Plantilla de Clases

#include <iostream>
#include "EjemploPlantilla.h"
using namespace std;

int main(int argc, char** argv) {
	EjemploPlantilla <int,float> ob1(5,9.87);
	
	ob1.mostrarDatos();
	
	ob1.setDato1(10);
	ob1.setDato2(8.78);
	
	cout<<endl;
	
	ob1.mostrarDatos();
	
	return 0;
}
