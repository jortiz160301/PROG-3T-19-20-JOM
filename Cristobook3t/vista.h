#include <iostream>
#include "tablausuario.h"
using namespace std;




class Vista{
	
	private:
	
		TablaUsuarios* t;
		//bool debug;
	
	public:
		
		Vista();
		~Vista();
		/**
		 * @brief método menú por la que se va a navegar por el programa
		 * @param
		 */
		void menu();
		void testing();
		void crearTablaUsuarios();
		void eliminarTabla();
		 /**
		 * @brief método que imprime la tabla de usuarios
		 * @param
		 */
		void imprimirTabla();
		 /**
		 * @brief filro de letras
		 * @param se le pasa un int para comprobarlo
		 */
		void FiltrarLetras(int &num);
	
		 /**
		 * @brief devuelve la posición del usuario con el mismo login que el introducido por el usuario final
		 * @param bool que controla si imprimir o no el ususrio encontrado
		 */
		int buscarPosUsuarioVista(bool imprimir);
		
		 /**
		 * @brief busca al usuario y ordena a ElminarUsuario de TablaUsuarios eliminarlo
		 * @param
		 */
		void eliminarUsuarioVista();
		/**
		 * @brief busca la foto del usuario y ordena a EliminarFoto de TablaUsuarios eliminarla
		 * @param
		 */
		void eliminarFotoUsuarioVista();
		/**
		 * @brief crea una foto haciendo los sets con la entrada del usuario final
		 * @param
		 */
		Foto crearFoto();
		/**
		 * @brief imprime todas las fotos de todos los usuarios
		 * @param
		 */
		void imprimirTodosFotos();
		/**
		 * @brief imprime todas las fotos de un usuario
		 * @param
		 */
		void imprimirFotosUsuario();
		/**
		 * @brief recoge la entrada para insertar una foto a usuario normal y lolama al método insertarFoto para hacerlo
		 * @param
		 */
		void insertarFotoUsuarioVista();
		/**
		 * @brief busca la foto a eliminar para pasársela a EliminarFotoVista
		 * @param
		 */
		int buscarFotoVista(int pos_usu);
		/**
		 * @brief crea un usuario dando a elegir si hacerlo admin o normal
		 * @param
		 */
		void crearUsuario();
		/**
		 * @brief recoge las entradas para decidir qué criterio de ordenación invoca de tablaUsuarios, si  ordenar por login o por número de fotos
		 * @param
		 */
		void ordenarUsuariosVista();
		/**
		 * @brief recoge la entrada para llamar a eliminarPorMin de TablaUsuarios para eliminar según un mínimo de foptos de usuario normal
		 * @param
		 */
		void eliminarPorMinVista();

};
