
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
	//void debug();
	void testing();
	void crearTablaUsuarios();
	void eliminarTabla();
	void imprimirUsuario(Usuario* u);
	void imprimirTabla();
	void FiltrarLetras(int &num);
	void resize(TablaUsuarios* t);
	int buscarUsuario(bool imprimir);
	void resizePP(int tamanio);
	void eliminarUsuarioVista();
	void eliminarFotoUsuarioVista();
	Foto crearFoto();
	void ImprimirVectorFotos();
	void insertarFotoUsuarioVista();
	int buscarFotoVista(int pos_usu);
//	void insertarUsuarioVista(Usuario* u);
	Usuario* construirUsuario(Usuario* u);
	void crearUsuario();
	void ordenarUsuariosVista();
	void eliminarPorMinVista();
	//void ordenar
	//void testing();
	//todos los cin
};