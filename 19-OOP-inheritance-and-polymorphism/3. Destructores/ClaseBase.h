#include<iostream>
using namespace std;

class ClaseBase{
	private:
		int numero;
	
	public:
		ClaseBase(int numero){ //Constructor
			this->numero = numero;
			cout<<"Constructor de la clase Base"<<endl;
		}
		
		~ClaseBase(){ //Destructor
			cout<<"Destructor de la clase Base"<<endl;
		}
};
