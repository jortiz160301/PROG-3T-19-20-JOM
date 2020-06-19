
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
	this->t = new TablaUsuarios();
};
Vista::~Vista(){
	//t->~TablaUsuarios();
	t = 0;
	cout<<"Eliminando Vista"<<endl;
}
/*
void Vista :: debug(string mnsj){
	if(debug == true){
		cout<<mnsj<<endl;
	}
}*/

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
		cout<<endl;
	}
	
	cout<<"\nElimino la primera y la útima: "<<endl;
	
	
	
	cout<<"\nBorrando la primera...(Ahora tiene "<<nuevoNor->getdimFotos()<<" fotos.) Enseño el vector y borramos la siguiente: "<<endl;
	
	nuevoNor->eliminarFotoUsuario(0);
	for(int j= 0; j < nuevoNor->getdimFotos(); j++){
		nuevoNor->getFoto(j).ImprimirFoto();
		cout<<endl;
	}
	
	
	cout<<"\nBorrando la última...(Ahora tiene "<<nuevoNor->getdimFotos()<<" fotos)"<<endl;
	
	nuevoNor->eliminarFotoUsuario(nuevoNor->getdimFotos()-1);
	
	
	cout<<"\nAhora ordeno por número de fotos. Los admin irán primero porque no pueden tener fotos: "<<endl;
	
	t->ordenarUsuariosNumFot();
	imprimirTabla();
	
	cout<<"\nY ahora por login: "<<endl;
	
	t->ordenarUsuariosLogin();
	imprimirTabla();
	
	cout<<"\nElimino al usuario que contiene fotos: "<<endl;
	
	t->eliminarUsuario(t->buscarPosUsuario("normal"));
	imprimirTabla();
	
	
	cout<<"\nInserto dos usuarios normales con 1 y 2 fotos cada uno para eliminar a partir de los que tengan menos de 2 fotos. "<<endl;
	
	
	Foto f1;
	
	nueva1.setRuta("f1");
	nueva1.setTipo("f1");
	nueva1.setTamanio(1);
	
	Foto f2;
	
	nueva1.setRuta("f2");
	nueva1.setTipo("f2");
	nueva1.setTamanio(2);
	
	Foto f3;
	
	nueva1.setRuta("f3");
	nueva1.setTipo("f3");
	nueva1.setTamanio(3);
	
	
	Normal* n1 = new Normal();
	
	n1->setNombre("n1");
	n1->setApellido("n1");
	n1->setLogin("n1");
	n1->setperfil_usuario("n1");
	
	Normal* n2 = new Normal();
	
	n2->setNombre("n2");
	n2->setApellido("n2");
	n2->setLogin("n2");
	n2->setperfil_usuario("n2");
	
	t->insertarFotoUsuario(f1, n1);
	t->insertarFotoUsuario(f2, n1);
	
	t->insertarFotoUsuario(f3, n2);
	
	
	t->insertarUsuario(n1);
	t->insertarUsuario(n2);
	
	imprimirTabla();	
	
	cout<<"\nY elimino a los usuarios con menos de 2 fotos. (Los admins no se eliminan). "<<endl;
	t->eliminarPorMin(2);
	imprimirTabla();
	
	cout<<"Elimino la tabla y la vuelvo a crear, pero esta vez con los usuarios predeterminados Juan y Antonio"<<endl;
	eliminarTabla();
	crearTablaUsuarios();
	imprimirTabla();
	
	
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
	do{
		cout<<"1: Admin"<<endl;
		cout<<"2: Normal"<<endl;
		FiltrarLetras(opcion);
	}while(opcion!=1 && opcion!=2);
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
	t = new TablaUsuarios;
	Normal* Juan;
	Juan = new Normal;
	
	Juan->setNombre("Juan");
	Juan->setApellido("Perez");
	Juan->setLogin("juan123");
	Juan->setperfil_usuario("Biografía de Juan");
	Juan->setdimFotos(0);

	this->t->setPunteroapuntero(0,Juan);
	

	Normal* Antonio;
	Antonio = new Normal;
	
	Antonio->setNombre("Antonio");
	Antonio->setApellido("García");
	Antonio->setLogin("antonio123");
	Antonio->setperfil_usuario("Biografía de Antonio");
	Antonio->setdimFotos(0);
	this->t->setPunteroapuntero(1,Antonio);
	
	
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
	bool tabla = false;

	


	
	do{
		cout<<"\nElija introduciendo un número: "<<endl;
		
		cout<<"1:"<<VERDE<<" Testing."<<DEFAULT<<endl;
		cout<<"2:"<<VERDE<<" Crear la tabla de usuarios."<<DEFAULT<<endl;
		cout<<"3:"<<VERDE<<" Crear un nuevo usuario."<<DEFAULT<<endl;
		cout<<"4:"<<VERDE<<" Imprimir la tabla."<<DEFAULT<<endl;		
		cout<<"5:"<<VERDE<<" Eliminar usuario."<<DEFAULT<<endl;
		cout<<"6:"<<VERDE<<" Insertar foto a un usuario."<<DEFAULT<<endl;	
		cout<<"7:"<<VERDE<<" Buscar un usuario"<<DEFAULT<<endl;
		cout<<"8:"<<VERDE<<" Imprimir la foto de un usuario"<<DEFAULT<<endl;
		cout<<"9:"<<VERDE<<" Eliminar foto de un usuario"<<DEFAULT<<endl;
		cout<<"10:"<<VERDE<<" Ordenar usuarios"<<DEFAULT<<endl;
		cout<<"11:"<<VERDE<<" Eliminar por mínimo de fotos"<<DEFAULT<<endl;
		cout<<"12:"<<VERDE<<" Eliminar Tabla."<<DEFAULT<<endl;
		cout<<"13:"<<VERDE<<" Salir."<<DEFAULT<<DEFAULT<<endl;
		
		
		
		FiltrarLetras(opcion);
		switch(opcion) {
			case 1: 
				testing();
			break;
			case 2: 
				crearTablaUsuarios();
				tabla = true;
			break;
			case 3: 
				if(tabla == true){
					crearUsuario();
				} else{
					cout<<ROJO<<"La tabla no está creada"<<DEFAULT<<endl;
				}
			break;
			case 4: 
				if(tabla == true){
					imprimirTabla();
				} else{
					cout<<ROJO<<"La tabla no está creada"<<DEFAULT<<endl;
				}
			break;
			case 5: 
				if(tabla == true){
					eliminarUsuarioVista();
				} else{
					cout<<ROJO<<"La tabla no está creada"<<DEFAULT<<endl;
				}
			break;
			case 6: 
				if(tabla == true){
					insertarFotoUsuarioVista();
				} else{
					cout<<ROJO<<"La tabla no está creada"<<DEFAULT<<endl;
				}
			break;
			case 7: 
				if(tabla == true){
					buscarPosUsuarioVista(true);
				} else{
					cout<<ROJO<<"La tabla no está creada"<<DEFAULT<<endl;
				}
			break;
			case 8: 
				if(tabla == true){
					imprimirFotosUsuario();
				} else{
					cout<<ROJO<<"La tabla no está creada"<<DEFAULT<<endl;
				}
			break;
			case 9: 
				if(tabla == true){
					eliminarFotoUsuarioVista();
				} else{
					cout<<ROJO<<"La tabla no está creada"<<DEFAULT<<endl;
				}
			break;
			case 10: 
				if(tabla == true){
					ordenarUsuariosVista();
				} else{
					cout<<ROJO<<"La tabla no está creada"<<DEFAULT<<endl;
				}
			break;
			case 11: 
				if(tabla == true){
					eliminarPorMinVista();
				} else{
					cout<<ROJO<<"La tabla no está creada"<<DEFAULT<<endl;
				}
			break;
			case 12: 
				if(tabla == true){
					eliminarTabla();
					tabla = false;
				} else{
					cout<<ROJO<<"La tabla no está creada"<<DEFAULT<<endl;
				}
			break;
			case 13:
				if(tabla == true){
					 eliminarTabla();
					 tabla = false;
				}
			 	menu=false;
			break;
		
			default: cout<<ROJO<<"Introduzca un número válido"<<DEFAULT<<endl;
    	}
    	
    }while(menu == true);

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
	
	if(Normal* n = dynamic_cast<Normal*>(t->getPunteroapuntero(posicion_usu))){
	
		int posicion_foto = buscarFotoVista(posicion_usu);
	
		if(posicion_foto >= 0){ 
			n->eliminarFotoUsuario(posicion_foto);
		}
	}else{
		cout<<"El usuario no puede tener fotos"<<endl;
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
	//delete t;
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

void Vista :: botonDebug(){
	
	if(debug == true){
		debug = false;
		
	}else if(debug == false){
		debug = true;
	}
	
	//t->debugTabUs(debug);
}





*/







