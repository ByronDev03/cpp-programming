//Herencia publica

#include<iostream>
#include "Vehiculo.h"
using namespace std;

class Turismo : public Vehiculo{
	private:
		int numeroPuertas;
	
	public:
		Turismo(string marca,string color,string modelo,int numeroPuertas) : Vehiculo(marca,color,modelo){
			this->numeroPuertas = numeroPuertas;
		}
		
		~Turismo(){
			
		}
		
		int getNumeroPuertas(){
			return numeroPuertas;
		}
		
		string retornarModelo(){
			string mensaje = getModelo();
			return mensaje;
		}
};

