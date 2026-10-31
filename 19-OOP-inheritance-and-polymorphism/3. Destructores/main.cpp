//Constructores y Destructores de clases derivadas

#include <iostream>
#include "ClaseDerivada.h"
using namespace std;

int main(int argc, char** argv) {
	ClaseDerivada* ob1 = new ClaseDerivada(5,10);
	
	cout<<endl;
	
	delete ob1;
	return 0;
}
