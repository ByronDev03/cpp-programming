//Clases Compuestas

#include <iostream>
#include "Estudiente.h"

using namespace std;

int main(int argc, char** argv) {
	Estudiante* estudiante1 = new Estudiante("34FG",15.6,56,"Calle las Palmas #789");
	
	estudiante1->mostrarDatos(); 
	
	return 0;
}
