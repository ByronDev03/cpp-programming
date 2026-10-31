#include<iostream>
using namespace std;

class Tablero{
	private:
		int x,y;
	
	public:
		Tablero(int x,int y){ //Constructor
			this->x = x;
			this->y = y;
		}
		
		void moverArriba(int);
		void moverAbajo(int);
		void moverDerecha(int);
		void moverIzquierda(int);
		int getX();
		int getY();
};
