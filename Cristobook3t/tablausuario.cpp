#include <iostream>
using namespace std;
#include "tablausuario.h"
TablaUsuarios :: TablaUsuarios(){
	punteroapuntero = new Usuario*[4];//totaltuplas////////////////////////////////////////////////
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
	delete[] punteroapuntero;
	cout<<"TablaUsuarios"<<endl;
}