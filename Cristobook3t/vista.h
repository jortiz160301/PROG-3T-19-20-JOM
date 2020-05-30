#include <iostream>
using namespace std;
#include "tablausuario.h"



class Vista{
	
	private:
	
	TablaUsuarios* t;
	//bool debug;
	
	public:
		
	Vista();
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
	Foto crearFoto();
	void ImprimirFoto(Foto f);
	void ImprimirVectorFotos();
	void instertarFotoUsuario();
	TablaUsuarios* insertarUsuario(Usuario* u);
	Usuario* construirUsuario(Usuario* u);
	void crearUsuario();
	//void ordenar
	//void testing();
	//todos los cin
};