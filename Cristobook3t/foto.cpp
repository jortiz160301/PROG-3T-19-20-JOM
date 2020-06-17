#include <iostream>
#include "foto.h"
using namespace std;


Foto::Foto(){

}

/**************************** SETS *************************************************************/
void Foto :: setRuta(string ruta_in){
	ruta = ruta_in;
}

void Foto :: setTipo(string tipo_in){
	tipo = tipo_in;
}

void Foto :: setTamanio(unsigned long int tamanio_in){
	tamanio = tamanio_in;
}
/**************************** GETS *************************************************************/
string Foto :: getRuta(){
	return ruta;
}

string Foto :: getTipo(){
	return tipo;
}

unsigned long int Foto :: getTamanio(){
	return tamanio;
}
/**************************** MÉTODOS PROPIOS  **************************************************/



void Foto :: ImprimirFoto(){
	cout<<"IMPRIMIENDO foto"<<endl;
	cout<<"Ruta: "<<this->getRuta()<<endl;
	cout<<"Tipo: "<<this->getTipo()<<endl;
	cout<<"Tamaño: "<<this->getTamanio()<<endl;
}