//Herencia Múltiple

#include <iostream>
#include "HidroAvion.h"
using namespace std;

int main(int argc, char** argv) {
	HidroAvion* ob1 = new HidroAvion("Veloz12","HA99","123OP");
	
	ob1->mostrarDatos();
	
	cout<<endl;
	
	ob1->indicarBarco();
	ob1->indicarAvion();
	
	delete ob1;
	return 0;
}
