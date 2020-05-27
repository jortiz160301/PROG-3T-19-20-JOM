#include <iostream>
using namespace std;
#include "usuario.h"
class TablaUsuarios{

	private: 
		Usuario** punteroapuntero; //Vector Dinámico de Punteros a Burbuja (EjercicioUD7 Alumnos v2)
		int totaltuplas;
		//La reserva siempre es exacta y al tamaño, la dimensión, siempre coincide con las útiles.
	
	public:
		TablaUsuarios ();
		void setPunteroapuntero(int posicion, Usuario* u);
		void setTotaltuplas(int totaltuplas_in);
		
		Usuario* getPunteroapuntero(int posicion);
		int getTotaltuplas();
};

