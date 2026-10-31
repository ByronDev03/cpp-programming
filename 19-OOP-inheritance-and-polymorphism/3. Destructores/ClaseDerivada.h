#include<iostream>
#include "ClaseBase.h"
using namespace std;

class ClaseDerivada : public ClaseBase{
	private:
		int numero2;
	
	public:
		ClaseDerivada(int numero,int numero2) : ClaseBase(numero){
			this->numero2 = numero2;
			cout<<"Constructor de la clase Derivada"<<endl;
		}
		
		~ClaseDerivada(){
			cout<<"Destructor de la clase Derivada"<<endl;
		}
};
