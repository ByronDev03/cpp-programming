#include <iostream>
#include "Poligono.h"
#include "Rectangulo.h"
#include "Triangulo.h"
using namespace std;

int main(int argc, char** argv) {
	Poligono* poligonos[2];

	poligonos[0] = new Rectangulo(7,4);
	poligonos[1] = new Triangulo(3,4,4);
	
	for(int i=0;i<2;i++){
		cout<<"Area: "<<poligonos[i]->area()<<endl;
		cout<<"Perimetro: "<<poligonos[i]->perimetro()<<endl;
	}
	
	return 0;
}
