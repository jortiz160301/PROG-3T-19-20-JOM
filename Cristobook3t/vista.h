
#include <iostream>
using namespace std;
#include "tablausuario.h"



class Vista{
	
	private:
	
	TablaUsuarios* t;
	//bool debug;
	
	public:
		
	Vista();
	~Vista();
	void menu();
	//void debugVista(bool debug);
	void testing();
	void crearTablaUsuarios();
	void eliminarTabla();

	void imprimirTabla();
	void FiltrarLetras(int &num);
	void resize(TablaUsuarios* t);
	int buscarPosUsuarioVista(bool imprimir);
	void resizePP(int tamanio);
	void eliminarUsuarioVista();
	void eliminarFotoUsuarioVista();
	Foto crearFoto();
	void imprimirTodosFotos();
	void imprimirFotosUsuario();
	void insertarFotoUsuarioVista();
	int buscarFotoVista(int pos_usu);
//	void insertarUsuarioVista(Usuario* u);
	Usuario* construirUsuario(Usuario* u);
	void crearUsuario();
	void ordenarUsuariosVista();
	void eliminarPorMinVista();

};