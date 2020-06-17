
#define DEFAULT "\033[1;0m"
#define ROJO "\033[1;41m"
#define CIAN "\033[1;35m"
#define AZUL "\033[1;34m"
#define R "\033[1;31m"
#define VERDE "\033[1;32m"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
#include "vista.h"

	
Vista::Vista(){
	this->t = new TablaUsuarios;
};
Vista::~Vista(){
	//t->~TablaUsuarios();
	t = 0;
	cout<<"Eliminando Vista"<<endl;
}


/**
 * @brief método que muestra el debug de las funciones
 * @version
 */
/*void Vista :: debug(){
	this->debug = true;
}
/**
 * @brief método de testing
 * @version
 */
 

void Vista :: testing(){
	cout<<"Creo una tabla de usuarios con dos usuarios normales de ejemplo, imprimo e inserto otros dos usuarios (uno normal y otro admin)." <<endl;
	cout<<"Imprimo otra vez y luego le inserto tres fotos al normal de login 'normal' "<<endl;
	
	crearTablaUsuarios();
	imprimirTabla();
	
	Admin* nuevoAdm = new Admin();
	
	nuevoAdm->setNombre("prueba");
	nuevoAdm->setApellido("admin");
	nuevoAdm->setLogin("admin");
	nuevoAdm->setperfil_usuario("admin");
	
	t->insertarUsuario(nuevoAdm);
	
	Normal* nuevoNor = new Normal();
	
	nuevoNor->setNombre("prueba");
	nuevoNor->setApellido("normal");
	nuevoNor->setLogin("normal");
	nuevoNor->setperfil_usuario("normal");
	
	t->insertarUsuario(nuevoNor);
	
	imprimirTabla();
	
	cout<<"\nCreo tres fotos: "<<endl;
	
	Foto nueva1;
	
	nueva1.setRuta("ruta1");
	nueva1.setTipo("tipo1");
	nueva1.setTamanio(1);
	
	Foto nueva2;
	
	nueva2.setRuta("ruta2");
	nueva2.setTipo("tipo2");
	nueva2.setTamanio(2);
	
	Foto nueva3;
	
	nueva3.setRuta("ruta3");
	nueva3.setTipo("tipo3");
	nueva3.setTamanio(3);
	
	
	cout<<"\nY se insertan en dicho usuario: "<<endl;
	
	t->insertarFotoUsuario(nueva1, nuevoNor);   
	t->insertarFotoUsuario(nueva2, nuevoNor); 
	t->insertarFotoUsuario(nueva3, nuevoNor); 
	
	
	cout<<"\nImprimo su vector de fotos: "<<endl;
	
	for(int j= 0; j < nuevoNor->getdimFotos(); j++){
		nuevoNor->getFoto(j).ImprimirFoto();
	}
	
	cout<<"\nElimino la primera y la útima: "<<endl;

	
	
	
}


/**
 * @brief método de creación de usuarios, aquí se hace los sets según se tenga un usuario normal o admin
 * @version
 */
 
 
 

void Vista :: crearUsuario(){
	int opcion= 0;
	bool usado=false;
	string nombre_us;
	string apellido_us;
	string login_us;
	string perfil_us;
	
	cout<<"Elija el tipo de usuario:"<<endl;
	cout<<"1: Admin"<<endl;
	cout<<"2: Normal"<<endl;
	cin>>opcion;
	//PIDO LOS DATOS EN CLASE VISTA
	cout<<"Introduzca el nombre del usuario: "<<endl;
	cin>>nombre_us;
	
	cout<<"Introduzca el apellido del usuario: "<<endl;
	cin>>apellido_us;
	
	cout<<"Introduzca el login del usuario: "<<endl;
	cin>>login_us;
	
	do{//FILTRO PARA NO REPETIR LOGINS
		usado = false;
		for(int i = 0; i<t->getTotaltuplas(); i++){
			if(login_us == t->getPunteroapuntero(i)->getLogin()){	
				cout<<"Por favor, introduzca un nombre que no esté en uso."<<endl;
				usado = true;
			}
		}
		if(usado == true){
			cin>>login_us;
		}

	}while(usado == true);
	
	cout<<"Introduzca el perfil del usuario: "<<endl;
	cin>>perfil_us;
	
	//HAGO LOS SETS
	
	if(opcion == 1){
		Admin* nuevoAdm = new Admin;
		
		//nuevoAdm = construirUsuario(nuevoAdm);
		
		nuevoAdm->setNombre(nombre_us);
		nuevoAdm->setApellido(apellido_us);
		nuevoAdm->setLogin(login_us);
		nuevoAdm->setperfil_usuario(perfil_us);
		
		t->insertarUsuario(nuevoAdm);
		

	}
	else if(opcion == 2){
		Normal* nuevoNor= new Normal;
		//nuevoNor = construirUsuario(nuevoNor);
		
		nuevoNor->setNombre(nombre_us);
		nuevoNor->setApellido(apellido_us);
		nuevoNor->setLogin(login_us);
		nuevoNor->setperfil_usuario(perfil_us);
		
		t->insertarUsuario(nuevoNor);
		
		
	}
	
}




/**
 * @brief método que crea la tabla de usuarios
 * @version
 */

void Vista :: crearTablaUsuarios(){
	cout<<"CREANDO TABLA"<<endl;
	Normal* Juan;
	Juan = new Normal;
	
	Juan->setNombre("Juan");
	Juan->setApellido("Perez");
	Juan->setLogin("Juan123");
	Juan->setperfil_usuario("Biografía de Juan");
	Juan->setdimFotos(0);
//	Juan->settotalFotosUsuario(0);
	this->t->setPunteroapuntero(0,Juan);
	

	Normal* Antonio;
	Antonio = new Normal;
	
	Antonio->setNombre("Antonio");
	Antonio->setApellido("García");
	Antonio->setLogin("Antonio123");
	Antonio->setperfil_usuario("Biografía de Antonio");
	Antonio->setdimFotos(0);
//	Antonio->settotalFotosUsuario(0);
	this->t->setPunteroapuntero(1,Antonio);
	
	//cout<<this->t->getPunteroapuntero(0)->getNombre()<<endl;
	
	this->t->setTotaltuplas(2);
};

void Vista :: FiltrarLetras(int &num){
	while(!(cin>> num)){
		cin.clear();
		cin.ignore(256, '\n');
		cout<<ROJO<<"Introduzca solo números."<<DEFAULT<<endl;
	}
}

void Vista :: menu (){
	int opcion;
	bool menu=true;

	
	do{
		cout<<"\nElija introduciendo un número: "<<endl;
		
		cout<<"1: Testing."<<endl;
		cout<<"2: Crear la tabla de usuarios."<<endl;
		cout<<"3: Crear un nuevo usuario."<<endl;
		cout<<"4: Imprimir la tabla."<<endl;		
		cout<<"5: Eliminar usuario."<<endl;
		cout<<"6: Insertar foto a un usuario."<<endl;	
		cout<<"7: Buscar un usuario"<<endl;
		cout<<"8: Imprimir la foto de un usuario"<<endl;
		cout<<"9: Eliminar foto de un usuario"<<endl;
		cout<<"10: Ordenar usuarios"<<endl;
		cout<<"11: Eliminar por mínimo de fotos"<<endl;
		cout<<"12: Salir."<<endl;
		
		
		FiltrarLetras(opcion);
	
		if(opcion == 1){
			testing();
		}else if(opcion ==2){
			crearTablaUsuarios();
		}else if(opcion ==3){
			crearUsuario();
		}else if(opcion ==4){
			imprimirTabla();
		}else if(opcion ==5){
			eliminarUsuarioVista();
		}else if(opcion ==6){
			insertarFotoUsuarioVista();
		}else if(opcion ==7){
			buscarPosUsuarioVista(true);
		}else if(opcion ==8){
			imprimirFotosUsuario();
		}else if(opcion ==9){
			eliminarFotoUsuarioVista();
		}else if(opcion ==10){
			ordenarUsuariosVista();
		}else if(opcion ==11){
			eliminarPorMinVista();
		}else if(opcion ==12){
		 	eliminarTabla();
		 	menu=false;
		}
	
	
	}while(menu == true && (opcion != 1 || opcion != 2 || opcion !=3 || opcion !=4 || opcion !=5 || opcion !=6 || opcion !=7 || opcion !=8 || opcion !=9 || opcion !=10 ));

	
}
/**
 * @brief método de búsqueda de usuarios
 * @version
 */
int Vista :: buscarPosUsuarioVista(bool imprimir){
		
	bool encontrado = false;
	string login_buscado;
	int pos_enc = 0;
	
	cout<<"Seleccione un usuario por su login: "<<endl;
	do{
		
		cin>>login_buscado;
		pos_enc = t->buscarPosUsuario(login_buscado);
		
		
		if(pos_enc >=0){
			encontrado = true;
		}else if(pos_enc <0 && t->getTotaltuplas()!=0){
			cout<<"Usuario no encontrado. Escriba el nombre de nuevo."<<endl;
		}else if(t->getTotaltuplas()==0){
			cout<<"No hay usuarios en la tabla."<<endl;
			encontrado = true; //para salir del bucle
		}
		
		
	}while(encontrado == false);
	
	if(imprimir == true){
		cout<<"El usuario encontrado es: "<<endl;
		t->getPunteroapuntero(pos_enc)->imprimirUsuario();
	}else{
		return pos_enc;
	}
}

	/*
Usuario* Vista :: buscarUsuarioVista(bool imprimir){

	string login_buscado;
	cout<<"Seleccione un usuario por su login: "<<endl;
	cin>>login_buscado;
	
	BuscarUsuario(login_buscado);


}
*/

void Vista :: eliminarUsuarioVista(){		
	cout<<"¿Qué usuario queire eliminar?"<<endl;

	//obtengo la posición del usuario que busco
	int posicion_usu = buscarPosUsuarioVista(false);
	
	//la paso a eliminar usuario
	t->eliminarUsuario(posicion_usu);
	
}





int Vista :: buscarFotoVista(int pos_usu){	
	
	int pos_foto = 0;
	string ruta_buscada;
	if(Normal* n = dynamic_cast<Normal*>(t->getPunteroapuntero(pos_usu))){
	
		cout<<"Introduzca la ruta de la foto a eliminar. "<<endl;
		cin>>ruta_buscada;
		pos_foto = n->buscarFoto(ruta_buscada);
	
	}else{
		cout<<"Ese usuario no puede tener fotos."<<endl;
		pos_foto = -1;
	}
	return pos_foto;

}



/**
 * @brief método que crea una foto
 * @version
 */
Foto Vista :: crearFoto(){
	Foto nueva;
	string ruta_in;
	string tipo_in; 
	unsigned long int tamanio_in; 
	
	//PIDO DATOS
	cout<<"Introduzca la ruta de la foto: "; cin>>ruta_in;
	cout<<"Introduzca el tipo de la foto: ";cin>>tipo_in; 
	cout<<"Introduzca el tamaño de la foto: ";cin>>tamanio_in; 
	
	//HAGO SETS
	nueva.setRuta(ruta_in);
	nueva.setTipo(tipo_in);
	nueva.setTamanio(tamanio_in);
	
	return nueva;
}
/*
void Normal::setFoto(int posicion, Foto f_in){
	v_fotos[posicion] = f_in;
}*/
/**
 * @brief método que inserta una foto en el vector de fotos de usuario
 * @version
 */
void Vista :: insertarFotoUsuarioVista(){
	
	cout<<"Elija al usuario al que quiere introducir la foto: "<<endl;
	int posicion_usu = buscarPosUsuarioVista(false);

	if(Normal *n = dynamic_cast<Normal*>(t->getPunteroapuntero(posicion_usu))) {
		
		Foto fnueva=crearFoto();
		t->insertarFotoUsuario(fnueva, n);
		cout<<"foto insertada"<<endl;
		
	}else{
		cout<<"Ese usuario no puede tener fotos."<<endl;
	}	
}

void Vista :: eliminarFotoUsuarioVista(){
	cout<<"Elija al usuario al que quiere eliminar la foto: "<<endl;
	int posicion_usu = buscarPosUsuarioVista(false);
	int posicion_foto = buscarFotoVista(posicion_usu);
	
	if(posicion_foto >= 0){ 
		t->eliminarFotoUsuario(posicion_usu,posicion_foto);
	}
}
/**
 * @brief método que imprime un vector de fotos
 * @version
 */

void Vista :: imprimirTodosFotos(){
	cout<<"IMPRIMIENDO"<<endl;

	for(int i= 0; i<t->getTotaltuplas(); i++){

		if(Normal* n = dynamic_cast<Normal*>(t->getPunteroapuntero(i)) ) {
			
			cout<<t->getPunteroapuntero(i)->getNombre()<<":"<<endl;
			if(n->getdimFotos() >= 1){//no he podido juntar las dos condiciones
				
				for(int j= 0; j < n->getdimFotos(); j++){
					n->getFoto(j).ImprimirFoto();
				}
				cout<<endl;
			}else{
				cout<<"Este usuario no tiene fotos."<<endl;
			}
		}
	}
}


void Vista :: imprimirFotosUsuario(){
	
	int pos_usu = buscarPosUsuarioVista(false);
	if(Normal* n = dynamic_cast<Normal*>(t->getPunteroapuntero(pos_usu)) ) {
		
		if(n->getdimFotos() >= 1){//no he podido juntar las dos condiciones
			
			for(int j= 0; j < n->getdimFotos(); j++){
				n->getFoto(j).ImprimirFoto();
			}
			cout<<endl;
		}else{
			cout<<"Este usuario no tiene fotos."<<endl;
		}
	}

}

void Vista :: eliminarTabla(){
	this->t-> ~TablaUsuarios();
	//this->~Vista();

}


/**
 * @brief método que imprime un usuario
 * @version

void Vista :: imprimirUsuario(Usuario* u){
	/*if(Normal* n = dynamic_cast<Normal*>(u)){
		cout<<n;
	}else if(Admin* a = dynamic_cast<Admin*>(u)){
		cout<<a;
	}

	cout<<"Nombre: "<<u->getNombre()<<endl;
	cout<<"Apellido: "<<u->getApellido()<<endl;
	cout<<"Login: "<<u->getLogin()<<endl;
	cout<<"Perfil: "<<u->getperfil_usuario()<<endl;
	cout<<endl;
	
}
 */
/**
 * @brief método que imprime la tabla de usuarios
 * @version
 */
void Vista :: imprimirTabla(){
	
	
	for(int i=0; i<(t->getTotaltuplas());i++){
	
		this->t->getPunteroapuntero(i)->imprimirUsuario();
	}
}



void Vista :: ordenarUsuariosVista(){
	int opcion =0;
	cout<<"1: Ordenar por número de fotos"<<endl;
	cout<<"2: Ordenar por login"<<endl;
	do{
		cin>>opcion;
		if(opcion != 1 && opcion != 2 ){
			cout<<"Por favor, introduzca una opción válida"<<endl;
		}
	}while(opcion != 1 && opcion != 2);
	
	
	if(opcion == 1){
		t->ordenarUsuariosNumFot();
	}else if(opcion == 2){
		t->ordenarUsuariosLogin();
	}
}




void Vista :: eliminarPorMinVista(){
	int min;
	cout<<"Introduzca el mínimo de fotos a partir del cual quiere eliminar los usuarios"<<endl;
	cin>>min;
	t->eliminarPorMin(min);
}


/*
void Vista :: debugVista(bool debug){
	
	if(debug == true){
		debug = false;
		
	}else if(debug == false){
		debug = true;
	}
	
	t->debugTabUs(debug);
}

*/










