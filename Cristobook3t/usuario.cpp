#include <iostream>
using namespace std;
#include "usuario.h"

Usuario::Usuario(){
	
	this->login = "";
	this->nombre = "";
	this->apellido = "";
	this->perfil_usuario = "";
}
/*
Usuario::Usuario(string nombre_in, string apellido_in, string login_in, string perfil_in){
	
	this->login = "";
	this->nombre = "";
	this->apellido = "";
	this->perfil_usuario = "";
	
	this->setLogin(login_in);
	this->setNombre(nombre_in);
	this->setApellido(apellido_in);
	this->setperfil_usuario(perfil_in);
	
}

*/
void Usuario::setLogin(string login_in){
	this->login = login_in;
}

void Usuario::setNombre(string nombre_in){
	this->nombre = nombre_in;
}

void Usuario::setApellido(string apellido_in){
	this->apellido = apellido_in;
}

void Usuario::setperfil_usuario(string perfil_usuario_in){
	this->perfil_usuario = perfil_usuario_in;
}


void Normal::setdimFotos(int dim_vfotos_in){
	this->dim_vfotos = dim_vfotos_in;
}
/*
void Normal::settotalFotosUsuario(int totalFotosUsuario_in){
	this->totalFotosUsuario = totalFotosUsuario_in;
}*/

void Normal::setFoto(int posicion, Foto f_in){
	v_fotos[posicion] = f_in;
}



string Usuario::getLogin(){
	return this->login;
}	

string Usuario::getNombre(){
	return this->nombre;
}

string Usuario::getApellido(){
	return apellido;
}

string Usuario::getperfil_usuario(){
	return perfil_usuario;
}

int Normal::getdimFotos(){
	return dim_vfotos;
};
/*
int Normal::gettotalFotosUsuario(){
	return totalFotosUsuario;
}*/

Foto Normal::getFoto(int posicion){
	return v_fotos[posicion];
}
Foto* Normal :: getV_fotos(){
	return v_fotos;
}

void Normal :: eliminarv_Fotos(){
	
	delete[] v_fotos;
}


void Normal :: resizevFotos(Foto* v_fotos_in){
	int total = getdimFotos();
	
	setdimFotos(total +1);
	eliminarv_Fotos();
	v_fotos = new Foto[dim_vfotos];
	
}
/**
 * @brief método que imprime una foto
 * @version
 */
void Normal :: ImprimirFoto(Foto f){
	cout<<"IMPRIMIENDO foto"<<endl;
	cout<<"Ruta: "<<f.getRuta()<<endl;
	cout<<"Tipo: "<<f.getTipo()<<endl;
	cout<<"Tamaño: "<<f.getTamanio()<<endl;
}

Usuario :: ~Usuario(){
	this->login = "";
	this->nombre = "";
	this->apellido = "";
	this->perfil_usuario = "";
	cout<<"Usuario"<<endl;
}

Normal :: ~Normal(){
	delete[] this->v_fotos;
	cout<<"Normal"<<endl;
}

Admin :: ~Admin(){
	cout<<"Admin"<<endl;
}
