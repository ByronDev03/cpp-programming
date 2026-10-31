#include <iostream>
#include "Turismo.h"
#include "Deportivo.h"
#include "Furgoneta.h"
using namespace std;

int main(int argc, char** argv) {
	cout<<"-Herencia Publica-"<<endl;
	Turismo* t1 = new Turismo("Toyota","Plomo","GH89",4);
	
	cout<<"Color: "<<t1->getColor()<<endl;
	t1->setColor("Negro");
	cout<<"Color: "<<t1->getColor()<<endl;
	cout<<"Modelo: "<<t1->retornarModelo()<<endl;
	
	cout<<"\n-Herencia Privada-"<<endl;
	Deportivo* d1 = new Deportivo("Audi","Blanco","KP98",10);
	
	cout<<"Cilindrada: "<<d1->getCilindrada()<<endl;
	cout<<"Marca: "<<d1->reportarMarca()<<endl;
	
	cout<<"\n-Herencia Protegida-"<<endl;
	Furgoneta* f1 = new Furgoneta("Kia","Verde","AS12",1200);
	
	cout<<"Carga: "<<f1->getCarga()<<endl;
	cout<<"Color: "<<f1->reportarColor()<<endl;
	
	delete t1;
	delete d1;
	delete f1;
	return 0;
}
