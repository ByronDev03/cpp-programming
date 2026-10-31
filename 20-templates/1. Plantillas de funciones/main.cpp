#include <iostream>
#include "Mayor.h"
using namespace std;

int main(int argc, char** argv) {
	cout<<"El mayor de 2 numeros enteros es: "<<mayor(5,9.76)<<endl;
	cout<<"El mayor de 2 numeros reales es: "<<mayor(9.87,4.56)<<endl;
	cout<<"El mayor de 2 caracteres es: "<<mayor('r','z')<<endl;
	
	

	return 0;
}
