#include <iostream>
using namespace std;
#include "tablausuario.h"



class Vista{
	
	private:
	
	TablaUsuarios* t;

	
	public:
		
	Vista();
	void menu();
	void crearTablaUsuarios();
	void eliminarTabla();
	void imprimirUsuario(Usuario* u);
	void imprimirTabla();
	void insertarUsuario();
	/*Admin construirUsuario(Usuario* u);
	Normal construirUsuario(Usuario* u);*/
	Usuario* construirUsuario(Usuario* u);
	void crearUsuario();
	//void testing();
	//todos los cin
};