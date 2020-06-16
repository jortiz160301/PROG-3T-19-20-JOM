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




Admin* Admin::operator=(Admin* a){
	//this->setTotalConsultas(a->getTotalConsultas());
	this->setLogin(a->getLogin());
	this->setNombre(a->getNombre());
	this->setApellido(a->getApellido());
	this->setperfil_usuario(a->getperfil_usuario());

	return this;
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

/*
void TablaUsuarios :: resizePP(int tamanio){	
	cout<<"resize"<<endl;
	Usuario** nuevo = new Usuario*[tamanio];
	
	if(tamanio > getTotaltuplas()){//si pedimos más tamaño del que tiene: 
		
		for(int i = 0; i < getTotaltuplas(); i++){
			nuevo[i] = getPunteroapuntero(i);
		}
		
	}else if(tamanio < getTotaltuplas()){// si pedimos menos tamaño del que tiene
		
		for(int i = 0; i < tamanio; i++){
			nuevo[i] = getPunteroapuntero(i);
		}
	}
	delete [] punteroapuntero;
	setVectorPunteroapuntero(nuevo);
	
}
*/
void Normal :: resizevFotos(int tamanio){
	cout<<"Resize fotos haciednose"<<endl;
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



ostream& operator<<(ostream &flujo, Normal *n){
	
	flujo<<"Nombre: "<<n->getNombre()<<endl;
	flujo<<"Apellido: "<<n->getApellido()<<endl;
	flujo<<"Login: "<<n->getLogin()<<endl;
	flujo<<"Perfil: "<<n->getperfil_usuario()<<endl;
	flujo<<endl;
	
	return flujo;
}

ostream& operator<<(ostream &flujo, Admin *a){
	
	flujo<<"Nombre: "<<a->getNombre()<<endl;
	flujo<<"Apellido: "<<a->getApellido()<<endl;
	flujo<<"Login: "<<a->getLogin()<<endl;
	flujo<<"Perfil: "<<a->getperfil_usuario()<<endl;
	flujo<<endl;
	
	return flujo;
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



Usuario :: ~Usuario(){
	this->login = "";
	this->nombre = "";
	this->apellido = "";
	this->perfil_usuario = "";
	cout<<"Destructor Usuario"<<endl;
}

Normal :: ~Normal(){
	delete[] this->v_fotos;
	this->dim_vfotos = 0;
	cout<<"Destructor Normal"<<endl;
}

Admin :: ~Admin(){
	this->total_consultas = 0;
	cout<<"Destructor Admin"<<endl;
}


