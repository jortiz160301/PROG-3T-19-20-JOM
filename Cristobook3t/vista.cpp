
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
/*
Admin Vista :: construirUsuario(Usuario* u){
    Admin* selecAdm;
	cout<<"guay"<<endl;
	return selecAdm;
}

Normal Vista :: construirUsuario(Usuario* u){
     Normal* selecNor;
	cout<<"guay"<<endl;
	return selecNor;
}
*/

/*
Usuario* Vista :: construirUsuario(Usuario* u){
    Normal* selecNor;
	Admin* selecAdm;
	bool adm = false;
	if(Normal* n = dynamic_cast<Normal*>(u)){
		Normal(u);
		selecAdm -> ~Admin();
		adm = false;
	}
	else if(Admin* n = dynamic_cast<Admin*>(u)){
		Admin(u);
		selecNor -> ~Normal();
		adm = true;
	}
	if(adm ==true){
		return selecAdm;
	}else if(adm == false){
		return selecNor;
	}
}
*/

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
	cout<<"Creo una tabla de usuarios, le meto dos usuarios de ejemplo, imprimo y meto otros dos usuarios. "<<endl;
	
	crearTablaUsuarios();
	imprimirTabla();
	crearUsuario();
	crearUsuario();
	imprimirTabla();
}

/**
 * @brief método de ten el que se inserta un usuario en la tabla de usuarios
 * @version
 */
TablaUsuarios* Vista :: insertarUsuario(Usuario* u){
	//TablaUsuarios* nueva = new TablaUsuarios;
	/*if(debug == true){
	cout<<"Totaltuplas: "<<t->getTotaltuplas()<<endl;
	}*/
	
	t->setTotaltuplas(t->getTotaltuplas()+1);
	/*if(debug == true){
	cout<<"Totaltuplas: "<<t->getTotaltuplas()<<endl;
	}*/

	TablaUsuarios* nueva = new TablaUsuarios(t);
	/*if(debug == true){
	cout<<"Creada nueva tabla "<<endl;
	}*/
	
	
	/*if(debug == true){
	cout<<"Total tuplas de la nueva tabla" << nueva->getTotaltuplas()<<endl;
	}*/
	
	nueva->setPunteroapuntero((nueva->getTotaltuplas())-1,u);
	//cout<<(nueva->getPunteroapuntero(0))->getNombre()<<endl;
	

	return nueva;


}
/**
 * @brief método de creación de usuarios, aquí se hace los sets según se tenga un usuario normal o admin
 * @version
 */

void Vista :: crearUsuario(){
	int opcion= 0;
	string nombre_us;
	string apellido_us;
	string login_us;
	string perfil_us;
	
	cout<<"Elija el tipo de usuario:"<<endl;
	cout<<"1: Admin"<<endl;
	cout<<"2: Normal"<<endl;
	cin>>opcion;
	
	cout<<"Introduzca el nombre del usuario: "<<endl;
	cin>>nombre_us;
	
	cout<<"Introduzca el apellido del usuario: "<<endl;
	cin>>apellido_us;
	
	cout<<"Introduzca el login del usuario: "<<endl;
	cin>>login_us;
	
	cout<<"Introduzca el perfil del usuario: "<<endl;
	cin>>perfil_us;
	
	if(opcion == 1){
		Admin* nuevoAdm = new Admin;
		
		//nuevoAdm = construirUsuario(nuevoAdm);
		
		nuevoAdm->setNombre(nombre_us);
		nuevoAdm->setApellido(apellido_us);
		nuevoAdm->setLogin(login_us);
		nuevoAdm->setperfil_usuario(perfil_us);
		//cout<<(t->getPunteroapuntero(0))->getNombre()<<endl;
		t=insertarUsuario(nuevoAdm);
		//cout<<(t->getPunteroapuntero(0))->getNombre()<<endl;
		
			
	
	}
	else if(opcion == 2){
		Normal* nuevoNor= new Normal;
		//nuevoNor = construirUsuario(nuevoNor);
		
		nuevoNor->setNombre(nombre_us);
		nuevoNor->setApellido(apellido_us);
		nuevoNor->setLogin(login_us);
		nuevoNor->setperfil_usuario(perfil_us);
		
		t=insertarUsuario(nuevoNor);
		
		
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
	Juan->setdimFotos(10);
	Juan->settotalFotosUsuario(0);
	this->t->setPunteroapuntero(0,Juan);
	

	Normal* Antonio;
	Antonio = new Normal;
	
	Antonio->setNombre("Antonio");
	Antonio->setApellido("García");
	Antonio->setLogin("Antonio123");
	Antonio->setperfil_usuario("Biografía de Antonio");
	Antonio->setdimFotos(10);
	Antonio->settotalFotosUsuario(0);
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
		cout<<"5: Buscar un usuario."<<endl;	
		cout<<"6: Crear foto a un usuario"<<endl;
		cout<<"7: Imprimir la foto de un usuario"<<endl;
		cout<<"8: Salir."<<endl;
		
		
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
			instertarFotoUsuario();
		}else if(opcion ==6){
			buscarUsuario(true);
		}else if(opcion ==7){
			ImprimirVectorFotos();
		}else if(opcion ==8){
		 	eliminarTabla();
		 	menu=false;
		}
	
	
	}while(menu == true && (opcion != 1 || opcion != 2 || opcion !=3 || opcion !=4 || opcion !=5 || opcion !=6 || opcion !=7 || opcion !=8 || opcion !=9 || opcion !=10 ));

	
}
/**
 * @brief método de búsqueda de usuarios
 * @version
 */
int Vista :: buscarUsuario(bool imprimir){
	
	bool encontrado = false;
	string login_buscado;
	int pos_enc = 0;
	char crearnuevo;
	
	do{
		cout<<"Seleccione un usuario por su login: "<<endl;
		cin>>login_buscado;
	
		for(int i = 0; (i<t->getTotaltuplas()) && (encontrado == false); i++){	
		
			if((t->getPunteroapuntero(i))->getLogin() == login_buscado){
				encontrado = true;
				pos_enc = i;
			}
		
		}
		
		
		
		
		if(encontrado == false && t->getTotaltuplas()!=0){
			cout<<"Usuario no encontrado. Escriba el nombre de nuevo."<<endl;
		}else if(t->getTotaltuplas()==0){
			cout<<"No hay usuarios en la tabla.\nCree nuevo usuario:"<<endl;
			
			encontrado == true; //para salir del bucle
		}
		
	}while(encontrado == false);
	
	if(imprimir == true){
		cout<<"El usuario encontrado es: "<<endl;
		imprimirUsuario(t->getPunteroapuntero(pos_enc));
	}else{
		return pos_enc;
	}
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
	cout<<"Introduzca la ruta de la foto: "; cin>>ruta_in;
	cout<<"Introduzca el tipo de la foto: ";cin>>tipo_in; 
	cout<<"Introduzca el tamaño de la foto: ";cin>>tamanio_in; 
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
void Vista :: instertarFotoUsuario(){
	cout<<"Elija al usuario al que quiere introducir la foto: "<<endl;
	//(t->getPunteroapuntero(buscarUsuario(false)))->setFoto(gettotalFotosUsuario()-1),crearFoto() ) ;
	/*Normal* n = */
	
	int posicion_usu = (buscarUsuario(false));
	Foto fnueva=crearFoto();
	int posicion_fot;
	
	Normal* nuevoNor = new Normal(dynamic_cast<Normal*>(t->getPunteroapuntero(posicion_usu)));
	
	nuevoNor->settotalFotosUsuario(nuevoNor->gettotalFotosUsuario()+1);
	
	if(nuevoNor->getdimFotos() <=  nuevoNor->gettotalFotosUsuario()){
		nuevoNor->setdimFotos(nuevoNor->gettotalFotosUsuario()+2);
		Foto* nuevo_v_foto =  new Foto[nuevoNor->getdimFotos()];
		nuevo_v_foto = nuevoNor->getV_fotos();
		//delete[] nuevoNor->v_fotos;
		nuevoNor->eliminarv_Fotos();
	}
	
	posicion_fot = nuevoNor->gettotalFotosUsuario();
	cout<<"Dynamic cast hecho"<<endl;
	nuevoNor->setFoto(posicion_fot, fnueva);
	/*cout<<"OBTENIENDO RUTA DESDE insertar: "<<dynamic_cast<Normal*>(t->getPunteroapuntero(posicion_usu))-> getNombre()<<endl;*/
	t->getPunteroapuntero(posicion_usu)->~Usuario();
	
	t->setPunteroapuntero(posicion_usu, nuevoNor);
	
	//ImprimirFoto(Foto f)
}

/**
 * @brief método que imprime una foto
 * @version
 */
void Vista :: ImprimirFoto(Foto f){
	cout<<"IMPRIMIENDO foto"<<endl;
	cout<<"Ruta: "<<f.getRuta()<<endl;
	cout<<"Tipo: "<<f.getTipo()<<endl;
	cout<<"Tamaño: "<<f.getTamanio()<<endl;
}
/**
 * @brief método que imprime un vector de fotos
 * @version
 */

void Vista :: ImprimirVectorFotos(){
	cout<<"IMPRIMIENDO"<<endl;

	for(int i= 0; i<t->getTotaltuplas(); i++){
	
	cout<<"Bucle 1"<<endl;
		cout<<"Total fotos: "<<dynamic_cast<Normal*>(t->getPunteroapuntero(i))->gettotalFotosUsuario()<<endl;
	
	
		for(int j= 0; j <( dynamic_cast<Normal*>(t->getPunteroapuntero(i)))->gettotalFotosUsuario(); j++){
			cout<<"Bucle 2"<<endl;
			cout<<"j ="<<j<<endl;
			//cout<<"RUTA: "<<dynamic_cast<Normal*>(t->getPunteroapuntero(i) )->getFoto(j).getRuta()<<endl;
			Normal* nuevoNor = new Normal(dynamic_cast<Normal*>(t->getPunteroapuntero(j)));
			ImprimirFoto(nuevoNor->getFoto(j));
		}
	}
	
		
}

void Vista :: eliminarTabla(){
	this->t-> ~TablaUsuarios();

}
/**
 * @brief método que imprime un usuario
 * @version
 */
void Vista :: imprimirUsuario(Usuario* u){
	cout<<9<<endl;
	cout<<"Nombre: "<<u->getNombre()<<endl;
	cout<<10<<endl;
	cout<<"Apellido: "<<u->getApellido()<<endl;
	cout<<"Login: "<<u->getLogin()<<endl;
	cout<<"Perfil: "<<u->getperfil_usuario()<<endl;
	cout<<endl;
}

/**
 * @brief método que imprime la tabla de usuarios
 * @version
 */
void Vista :: imprimirTabla(){
	
	
	for(int i=0; i<(t->getTotaltuplas());i++){
	
		imprimirUsuario(this->t->getPunteroapuntero(i));
	}
}




















