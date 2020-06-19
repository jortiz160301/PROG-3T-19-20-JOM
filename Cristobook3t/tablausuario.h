#include <iostream>
#include "usuario.h"
using namespace std;
class TablaUsuarios{

	private: 
		Usuario** punteroapuntero; 
		int totaltuplas;

	
	public:

		TablaUsuarios();
		TablaUsuarios(const TablaUsuarios* t);
		
		//void debug(string mnsj);
		/**
		 * @brief hace el set de un usuario en una posición 
		 * @param sus oarámetros son la posicion y el usuario que va a ir e ella
		 */
		void setPunteroapuntero(int posicion, Usuario* u);
		void setTotaltuplas(int totaltuplas_in);
		void setVectorPunteroapuntero(Usuario** nuevo);
		/**
		 * @brief obtiene la dirección del vector punteroapuntero
		 * @param
		 */
		Usuario** getVectorPunteroapuntero();
		
		
		Usuario* getPunteroapuntero(int posicion);
		int getTotaltuplas();
		/**
		 * @brief inserta un usuario en la tabla 
		 * @param el usuario que va a insertar
		 */
		void insertarUsuario(Usuario* u);
		/**
		 * @brief crea un nuevo vector punteroapuntero con el mismo contenido pero diferente dimensión  
		 * @param dimensión del nuevo vector
		 */
		void resizePP(int tamanio);
		/**
		 * @brief elimina un usuario de la tabla de usuarios
		 * @param la posición del usuario que va a eliminar
		 */
		void eliminarUsuario(int posicion_usu);
		/**
		 * @brief inserta una foto a un usuario
		 * @param a foto y el usuario al que se la va a insertar
		 */
		void insertarFotoUsuario(const Foto &fnueva, Normal* n);
		/**
		 * @brief ordena, según el número de fotos de los usuarios, el vector punteroapuntero
		 * @param
		 */
		void ordenarUsuariosNumFot();
		/**
		 * @brief ordena, según el login de los usuarios, el vector punteroapuntero
		 * @param
		 */
		void ordenarUsuariosLogin();
		/**
		 * @brief elimina usuarios según el mńimo que se le da de dimFotos
		 * @param
		 */
		void eliminarPorMin(int min);
		/**
		 * @brief devuelve la posición en el vector de punteroapuntero de un usuario buscado según su login
		 * @param login que vamos a buscar
		 */
		int buscarPosUsuario(string login_buscado);
		/**
		 * @brief destructor de tablausuario
		 * @version
		 */
		~TablaUsuarios();
};

