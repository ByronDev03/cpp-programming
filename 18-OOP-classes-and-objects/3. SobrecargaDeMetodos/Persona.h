//Implementacion de la clase Persona

#include<iostream>
using namespace std;

class Persona{
	//Atributos
	private: 
		string nombre;
		int edad;
		string dni; 
		
	//Métodos
	public: 
		Persona(string _nombre,int _edad){ //Constructor1
			nombre = _nombre;
			edad = _edad;
		}
		
		Persona(string _dni){ //Constructor2
			dni = _dni;
		}
		
		void correr(){
			cout<<"Soy "<<nombre<<", tengo "<<edad<<" años y estoy corriendo una maraton"<<endl;
		}
		
		void correr(int km){
			cout<<"He corrido "<<km<<" kilometros"<<endl;
		}
};
