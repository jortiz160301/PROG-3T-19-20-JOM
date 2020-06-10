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
		void setVectorPunteroapuntero(Usuario** nuevo);
		Usuario** getVectorPunteroapuntero();
		
		Usuario* getPunteroapuntero(int posicion);
		int getTotaltuplas();
		void insertarUsuario(Usuario* u);
		void resizePP(int tamanio);
		void eliminarUsuario(int posicion_usu);
		void insertarFotoUsuario(int posicion_usu, const Foto &fnueva, Normal* n);
		void eliminarFotoUsuario(int posicion_usu, int posicion_foto);
		void ordenarUsuariosNumFot();
		/**
		 * @brief destructor de tablausuario
		 * @version
		 */
		~TablaUsuarios();
};
