#include <iostream>
using namespace std;
#include "tablausuario.h"


TablaUsuarios :: TablaUsuarios(){
	totaltuplas = 2;
	punteroapuntero = new Usuario*[getTotaltuplas()];
}



TablaUsuarios :: TablaUsuarios(const TablaUsuarios* t){
	punteroapuntero = new Usuario*[getTotaltuplas()];
	this->totaltuplas = t->totaltuplas;
	this->punteroapuntero = t->punteroapuntero;
	for(int i=0;i<this->getTotaltuplas();i++){
		
		this->punteroapuntero[i] = t->punteroapuntero[i];
	}
	
}

void TablaUsuarios :: setVectorPunteroapuntero(Usuario** nuevo){
	this-> punteroapuntero = nuevo;
}
/*
void TablaUsuarios :: debug(string mnsj){
	if(debug == true){
		cout<<mnsj<<endl;
	}
}
*/

void TablaUsuarios :: setPunteroapuntero(int posicion, Usuario* u){
	punteroapuntero[posicion]=u;
}

void TablaUsuarios :: setTotaltuplas(int totaltuplas_in){
	totaltuplas = totaltuplas_in;
}



Usuario* TablaUsuarios :: getPunteroapuntero(int posicion){
	return punteroapuntero[posicion];
}

int TablaUsuarios :: getTotaltuplas(){
	return totaltuplas;
}

Usuario** TablaUsuarios :: getVectorPunteroapuntero(){
	return punteroapuntero;
}

TablaUsuarios :: ~TablaUsuarios(){
	cout<<this->getTotaltuplas()<<endl;
	for(int i = 0; i<this->getTotaltuplas(); i++){	
		delete this->punteroapuntero[i];
	}
	delete[] punteroapuntero;
	punteroapuntero = 0;
	
	
	cout<<"eliminando TablaUsuarios"<<endl;
}




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
/**
 * @brief método de ten el que se inserta un usuario en la tabla de usuarios
 * @version
 */
void TablaUsuarios :: insertarUsuario(Usuario* u){
	cout<<"INSERTANDO"<<endl;
	resizePP(getTotaltuplas()+1);
	setTotaltuplas(getTotaltuplas()+1);
	setPunteroapuntero(getTotaltuplas()-1 , u);
	

}




void TablaUsuarios :: eliminarUsuario(int posicion_usu){		
	
	for(int i = posicion_usu; i<(getTotaltuplas()-1); i++){
		setPunteroapuntero(i,getPunteroapuntero(i+1));//pap(i) = pap(i+1) tantas veces como la dimensión del vector-1
	}
	
	resizePP(getTotaltuplas()-1);//tengo que eliminar el vector antiguo en el resize
	setTotaltuplas(getTotaltuplas()-1);
	
/*
	for(int i= 0; i<getTotaltuplas();i++){
		cout<<getPunteroapuntero(i)->getNombre()<<endl;
	}
	*/
}

void TablaUsuarios :: insertarFotoUsuario(const Foto &fnueva, Normal* n){
	cout<<"Insertando foto..."<<endl;
	n->resizevFotos(n->getdimFotos()+1);//se amuenta la dimensión del vector por 1
	n->setdimFotos(n->getdimFotos()+1);
	n->setFoto(n->getdimFotos()-1, fnueva);//se añade la foto nueva a la ultima posición del vector  

	
}


void TablaUsuarios :: ordenarUsuariosNumFot(){
	bool cambio = true;
	Normal* aux_n = new Normal;
	Admin* aux_a = new Admin;
	int num_adm = 0;
		cout<<""<<endl;
		
	for(int i=0;i<getTotaltuplas(); i++){//bucle para contar cuántos admins hay
		if(Admin* a = dynamic_cast<Admin*>(getPunteroapuntero(i))){
		
			aux_a = a;
			setPunteroapuntero(i, getPunteroapuntero(num_adm));//n = n_antes;
			setPunteroapuntero(num_adm,aux_a);
			num_adm++;
		}
	}
	
	for(int izda=num_adm; izda < getTotaltuplas(); izda++){
		cambio = false;
		
		
		for(int i=getTotaltuplas()-1;i>izda; i--){
			
			if(Normal* n = dynamic_cast<Normal*>(getPunteroapuntero(i))){
				if(Normal* n_antes = dynamic_cast<Normal*>(getPunteroapuntero(i-1))){
					if(n->getdimFotos() < n_antes->getdimFotos()){
						cambio = true;
				
						aux_n = n;
						setPunteroapuntero(i,n_antes);//n = n_antes;
						setPunteroapuntero(i-1,aux_n);//n_antes = aux_n;
					}
				}
			}
		}
	}
}

void TablaUsuarios :: ordenarUsuariosLogin(){
	bool cambio = true;
	
	for(int izda=0; izda < getTotaltuplas(); izda++){
		cambio = false;
		
		for(int i=getTotaltuplas()-1; i>izda; i--){
			if(getPunteroapuntero(i)->getLogin() < getPunteroapuntero(i-1)->getLogin()){
				bool cambio = true;
			
				Usuario* aux = getPunteroapuntero(i);
				setPunteroapuntero(i,getPunteroapuntero(i-1));//v[i] = v[i-1];
				setPunteroapuntero(i-1,aux);//v[i-1]=aux;
				
				
				/*if(Normal* n = dynamic_cast<Normal*>(getPunteroapuntero(i))){
					aux_n = n;
				}else if(Admin* n = dynamic_cast<Admin*>(getPunteroapuntero(i))){
					aux_a = a;
				}*/
				//n = n_antes;
				//setPunteroapuntero(i-1,aux_n);
			}
		}
	}
}



void TablaUsuarios :: eliminarPorMin(int min){
	for(int i = 0; i<getTotaltuplas();){
		if(Normal *n = dynamic_cast<Normal*> (getPunteroapuntero(i) ) ) {
			if(n->getdimFotos() < min){
				
				for(int j = i; j<getTotaltuplas()-1; j++){
					punteroapuntero[j]=punteroapuntero[j+1];
				}
				resizePP(getTotaltuplas()-1);
				setTotaltuplas(getTotaltuplas()-1);
				
			}else{
				i++;
			}
		}else{
			i++;
		}
	}
}



int TablaUsuarios :: buscarPosUsuario(string login_buscado){

	bool encontrado = false;
	int pos_enc = 0;
	
	for(int i = 0; (i<getTotaltuplas()) && (encontrado == false); i++){	
	
		if((getPunteroapuntero(i))->getLogin() == login_buscado){
			encontrado = true;
			pos_enc = i;
		}
	
	}
	
	if(encontrado == false){
		pos_enc = -1;
	}
	
	return pos_enc;
		
}


