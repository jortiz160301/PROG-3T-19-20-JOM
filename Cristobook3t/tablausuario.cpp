#include <iostream>
using namespace std;
#include "tablausuario.h"
TablaUsuarios :: TablaUsuarios(){
	
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

TablaUsuarios :: ~TablaUsuarios(){
	//delete[] punteroapuntero;
	cout<<"eliminando TablaUsuarios"<<endl;
}