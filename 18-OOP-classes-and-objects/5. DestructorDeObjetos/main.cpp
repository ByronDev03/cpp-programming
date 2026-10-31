//Autorreferencia del Objeto: this

#include <iostream>
#include "Perro.h"

using namespace std;

int main(int argc, char** argv) {
	Perro perro1("Fido","Doberman");
	
	perro1.mostrarDatos();
	perro1.jugar();
	
	Perro* perro2 = new Perro("Sasa","Pitbull");
	
	perro2->jugar();
	
	delete perro2;
	return 0;
}
