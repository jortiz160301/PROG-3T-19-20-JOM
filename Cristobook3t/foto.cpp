#include <iostream>
#include "foto.h"
using namespace std;

Foto::Foto(){

}
void Foto :: setRuta(string ruta_in){
	ruta = ruta_in;
}

void Foto :: setTipo(string tipo_in){
	tipo = tipo_in;
}

void Foto :: setTamanio(unsigned long int tamanio_in){
	tamanio = tamanio_in;
}

string Foto :: getRuta(){
	return ruta;
}

string Foto :: getTipo(){
	return tipo;
}

unsigned long int Foto :: getTamanio(){
	return tamanio;
}

/*
Foto* Foto :: operator=(const Foto* f){
	if(f != this){
		this->ruta = f->ruta;
		this->tipo = f->tipo;
		this->tamanio = f->tamanio;
	}
	return this;
}
*/
