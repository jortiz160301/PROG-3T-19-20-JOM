#include <iostream>
using namespace std;
#include "usuario.h"
class TablaUsuarios{

	private: 
		Usuario** punteroapuntero; //Vector Dinámico de Punteros a Burbuja (EjercicioUD7 Alumnos v2)
		int totaltuplas;
		//La reserva siempre es exacta y al tamaño, la dimensión, siempre coincide con las útiles.
	
	public:

		TablaUsuarios();
		/**
		 * @brief constructor poir copia
		 * @version
		 */

		TablaUsuarios(const TablaUsuarios* t);
		
		void setPunteroapuntero(int posicion, Usuario* u);
		void setTotaltuplas(int totaltuplas_in);
		Usuario** getVectorPunteroapuntero();
		
		Usuario* getPunteroapuntero(int posicion);
		int getTotaltuplas();
		/**
		 * @brief destructor de tablausuario
		 * @version
		 */
		~TablaUsuarios();
};
