//Arreglo de Objetos

class Alumno{
	//Atributos
	private: 
		float calMate, calProgra, promedio; 
	
	//Métodos
	public: 
		Alumno(float _calMate,float _calProgra){ //Constructor1
			calMate = _calMate;
			calProgra = _calProgra;
		}
		
		Alumno(){ //Constructor por Defecto
			
		}
		
		void pedirDatos();
		void mostrarNotas();
};
