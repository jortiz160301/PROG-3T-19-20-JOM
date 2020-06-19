#include <iostream>
#define DEFAULT "\033[1;0m"
#define ROJO "\033[1;41m"
#define CIAN "\033[1;35m"
#define AZUL "\033[1;34m"
#define R "\033[1;31m"
#define VERDE "\033[1;32m"
using namespace std;
#include "usuario.h"




/***********************************************************************************************************/
/**************************** MÉTODOS DE USUARIO************************************************************/
/***********************************************************************************************************/
Usuario::Usuario(){
	
	this->login = "";
	this->nombre = "";
	this->apellido = "";
	this->perfil_usuario = "";
}

Usuario :: ~Usuario(){
	this->login = "";
	this->nombre = "";
	this->apellido = "";
	this->perfil_usuario = "";
	cout<<"Destructor Usuario"<<endl;
}


Usuario* Usuario::operator=(Usuario* u){

	this->setLogin(u->getLogin());
	this->setNombre(u->getNombre());
	this->setApellido(u->getApellido());
	this->setperfil_usuario(u->getperfil_usuario());

	return this;
}/*
void Usuario :: debug(string mnsj){
	if(debug == true){
		cout<<mnsj<<endl;
	}
}*/
/**************************** SETS ************************************************************/


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

/**************************** GETS ************************************************************/

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



/*
Usuario* Usuario::operator=(const Usuario* u){//hacerlo virtual? si. esto está mal
	if(u != this){
		if(Normal *n = dynamic_cast<Normal*>(u))) {
			delete[] this->v_fotos;
			this->saldo = u->saldo;
			this->dim_vfotos = u->dim_vfotos;
			this->v_fotos = new Foto[this->dim_vfotos];
			for(int i = 0; i <dim_vfotos; i++){
				this->v_fotos[i]= u->v_fotos[i];
			}
		}else if(Admin *n = dynamic_cast<Admin*>(u))){
			
		}
		
	return this;
}*/


/**
 * @brief método que imprime un usuario
 * @version
 */
void Usuario :: imprimirUsuario(){
	/*if(Normal* n = dynamic_cast<Normal*>(u)){
		cout<<n;
	}else if(Admin* a = dynamic_cast<Admin*>(u)){
		cout<<a;
	}
	*/
	cout<<"Nombre: "<<this->getNombre()<<endl;
	cout<<"Apellido: "<<this->getApellido()<<endl;
	cout<<"Login: "<<this->getLogin()<<endl;
	cout<<"Perfil: "<<this->getperfil_usuario()<<endl;
	cout<<endl;
	
}





/***********************************************************************************************************/
/**************************** MÉTODOS DE NORMAL*************************************************************/
/***********************************************************************************************************/


Normal :: ~Normal(){
	
	delete[] this->v_fotos;
	this->v_fotos = 0;
	this->dim_vfotos = 0;
	cout<<"Destructor Normal"<<endl;
}

/**************************** SETS *************************************************************/

void Normal::setdimFotos(int dim_vfotos_in){
	this->dim_vfotos = dim_vfotos_in;
}


void Normal::setFoto(int posicion, Foto f_in){
	v_fotos[posicion] = f_in;
}




/**************************** GETS *************************************************************/

int Normal::getdimFotos(){
	return dim_vfotos;
};

Foto Normal::getFoto(int posicion){
	return v_fotos[posicion];
}
Foto* Normal :: getV_fotos(){
	return v_fotos;
}

void Normal :: eliminarv_Fotos(){
	
	delete[] v_fotos;
}
/**************************** MÉTODOS PROPIOS ***************************************************/

Normal Normal::operator=(Normal* n){
	if(n!= this){
		delete[] n->v_fotos;
		this->dim_vfotos = n->dim_vfotos;
		this->v_fotos = new Foto[n->dim_vfotos];
		this->saldo = n->saldo;
		for(int i = 0; i>this->dim_vfotos; i++){
			this->v_fotos[i] = n->v_fotos[i];
		}
		this->setLogin(n->getLogin());
		this->setNombre(n->getNombre());
		this->setApellido(n->getApellido());
		this->setperfil_usuario(n->getperfil_usuario());
	}
	return *this;
}


void Normal :: resizevFotos(int tamanio){
	cout<<"Resize fotos haciendose"<<endl;
	Foto* nueva = new Foto[tamanio];
	if(tamanio > getdimFotos()){
		for(int i = 0; i < getdimFotos(); i++){
			nueva[i] = getFoto(i);
		}
	}else if(tamanio < getdimFotos()){
		
		for(int i = 0; i < tamanio; i++){
			nueva[i] = getFoto(i);
		}
	}
	delete[] v_fotos;
	v_fotos = nueva;
	//setdimFotos(total +1);
	//v_fotos = new Foto[dim_vfotos];
	cout<<"Resize fotos hecho"<<endl;
}


int Normal :: buscarFoto(string ruta_buscada){
	
	bool encontrado = false;
	int pos_enc = 0;
	
	do{
	
		for(int i = 0; i<this->getdimFotos() && (encontrado == false); i++){	
		
			if(this->getFoto(i).getRuta() == ruta_buscada){
				encontrado = true;
				pos_enc = i;
			}
		}

		if(encontrado == false && this->getdimFotos()!=0){
			cout<<"Foto no encontrada. Escriba la ruta de nuevo."<<endl;
		}else if(this->getdimFotos()==0){
			cout<<"El usuario no tiene fotos."<<endl;
			encontrado = true; //para salir del bucle
			pos_enc = -1;//en eliminarFoto hay una condición para que si pos = -1, se muestre mensaje de error
		}
		
	}while(encontrado == false);
	
	return pos_enc;
}


void Normal :: eliminarFotoUsuario(int posicion_foto){
	
	for(int i = posicion_foto; i<this->getdimFotos()-1; i++){
		this->setFoto(i, this->getFoto(i+1));
	}
	this->resizevFotos(this->getdimFotos()-1);
	this->setdimFotos(this->getdimFotos()-1);//esto no se podría meter en el resize?no
	
	
}

ostream& operator<<(ostream &flujo, Normal *n){
	
	flujo<<CIAN<<"Nombre: "<<DEFAULT<<n->getNombre()<<endl;
	flujo<<CIAN<<"Apellido: "<<DEFAULT<<n->getApellido()<<endl;
	flujo<<CIAN<<"Login: "<<DEFAULT<<n->getLogin()<<endl;
	flujo<<CIAN<<"Perfil: "<<DEFAULT<<n->getperfil_usuario()<<endl;
	flujo<<endl;
	
	return flujo;
}



/**
 * @brief método que imprime un usuario
 * @version
 */
void Normal :: imprimirUsuario(){

	cout<<CIAN<<"Nombre: "<<DEFAULT<<this->getNombre()<<endl;
	cout<<CIAN<<"Apellido: "<<DEFAULT<<this->getApellido()<<endl;
	cout<<CIAN<<"Login: "<<DEFAULT<<this->getLogin()<<endl;
	cout<<CIAN<<"Perfil: "<<DEFAULT<<this->getperfil_usuario()<<endl;
	cout<<CIAN<<"Número de fotos:  "<<DEFAULT<<this->getdimFotos()<<endl;
	
	cout<<endl;
	
	
	
}

/***********************************************************************************************************/
/**************************** MÉTODOS DE ADMIN*************************************************************/
/***********************************************************************************************************/


Admin :: ~Admin(){
	this->total_consultas = 0;
	cout<<"Destructor Admin"<<endl;
}

ostream& operator<<(ostream &flujo, Admin *a){
	
	flujo<<R<<"Nombre: "<<DEFAULT<<a->getNombre()<<endl;
	flujo<<R<<"Apellido: "<<DEFAULT<<a->getApellido()<<endl;
	flujo<<R<<"Login: "<<DEFAULT<<a->getLogin()<<endl;
	flujo<<R<<"Perfil: "<<DEFAULT<<a->getperfil_usuario()<<endl;
	flujo<<endl;
	
	return flujo;
}


Admin* Admin::operator=(Admin* a){
	//this->setTotalConsultas(a->getTotalConsultas());
	this->setLogin(a->getLogin());
	this->setNombre(a->getNombre());
	this->setApellido(a->getApellido());
	this->setperfil_usuario(a->getperfil_usuario());

	return this;
}
void Admin :: imprimirUsuario(){

	cout<<R<<"Nombre: "<<DEFAULT<<this->getNombre()<<endl;
	cout<<R<<"Apellido: "<<DEFAULT<<this->getApellido()<<endl;
	cout<<R<<"Login: "<<DEFAULT<<this->getLogin()<<endl;
	cout<<R<<"Perfil: "<<DEFAULT<<this->getperfil_usuario()<<endl;
	cout<<R<<"Número de consultas: "<<DEFAULT<<0<<endl;
	
	cout<<endl;
	
	
	
}



