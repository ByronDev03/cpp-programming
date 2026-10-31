//Sobrecarga de Funciones Miembro

#include <iostream>
#include "Persona.h"

using namespace std; 

int main(int argc, char** argv) {
	Persona* persona1 = new Persona("Alejandro",21);
	persona1->correr();
	
	Persona* persona2 = new Persona("112312454");
	persona2->correr(4);
		
	return 0;
}
