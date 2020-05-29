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
		
		t->setPunteroapuntero(2,nuevoAdm);
		
		
	}
	else if(opcion == 2){
		Normal* nuevoNor= new Normal;
		//nuevoNor = construirUsuario(nuevoNor);
		
		nuevoNor->setNombre(nombre_us);
		nuevoNor->setApellido(apellido_us);
		nuevoNor->setLogin(login_us);
		nuevoNor->setperfil_usuario(perfil_us);
		
		t->setPunteroapuntero(2,nuevoNor);
		
		
	}
	
}


void Vista :: crearTablaUsuarios(){
	
	Normal* Juan;
	Juan = new Normal;
	
	Juan->setNombre("Juan");
	Juan->setApellido("Perez");
	Juan->setLogin("Juan123");
	Juan->setperfil_usuario("Biografía de Juan");
	Juan->setdimFotos(10);
	Juan->settotalFotosUsuario(4);
	this->t->setPunteroapuntero(0,Juan);
	

	Normal* Antonio;
	Antonio = new Normal;
	
	Antonio->setNombre("Antonio");
	Antonio->setApellido("García");
	Antonio->setLogin("Antonio123");
	Antonio->setperfil_usuario("Biografía de Antonio");
	Antonio->setdimFotos(10);
	Antonio->settotalFotosUsuario(4);
	this->t->setPunteroapuntero(1,Antonio);
	
	cout<<this->t->getPunteroapuntero(0)->getNombre()<<endl;
	
	this->t->setTotaltuplas(2);
};


void Vista :: menu (){
	int opcion;
	bool menu=true;

	
	//do{
		cout<<"\nElija introduciendo un número: "<<endl;
		
		cout<<"1: Crear la tabla de usuarios."<<endl;
		cout<<"2: Borrar la tabla."<<endl;
		cout<<"3: Imprimir la tabla."<<endl;
		cout<<"4: Crear un nuevo usuario."<<endl;
		cout<<"5: Eliminar un usuario."<<endl;
		cout<<"6: Buscar un usuario."<<endl;
		cout<<"7: Ordenar usuarios."<<endl;
		cout<<"8: Crear foto a un usuario"<<endl;
		cout<<"9: Eliminar foto a un usuario"<<endl;
		cout<<"10: Imprimir la foto de un usuario"<<endl;
		cout<<"11: Salir."<<endl;
		cout<<"12: Testing."<<endl;
		
		//FiltrarLetras(opcion);
	
		if(opcion == 1){
			
		}else if(opcion ==2){
			
		}else if(opcion ==3){
			
				
		}else if(opcion ==4){
		
		
		}else if(opcion ==5){
			
		
		}else if(opcion ==6){
			
		
		}else if(opcion ==7){
		
		}else if(opcion ==8){
			
			
		}else if(opcion ==9){
		
		
		}else if(opcion ==10){
			
		
		}else if(opcion ==11){
			
		}else if(opcion ==12){
			
		}
		
	
	
	//}while(menu == true && (opcion != 1 || opcion != 2 || opcion !=3 || opcion !=4 || opcion !=5 || opcion !=6 || opcion !=7 || opcion !=8 || opcion !=9 || opcion !=10 ));

	
}
void Vista :: eliminarTabla(){
	this->t-> ~TablaUsuarios();

}

void Vista :: imprimirUsuario(Usuario* u){
	cout<<"Nombre: "<<u->getNombre()<<endl;
	cout<<"Apellido: "<<u->getApellido()<<endl;
	cout<<"Login: "<<u->getLogin()<<endl;
	cout<<"Perfil: "<<u->getperfil_usuario()<<endl;
	cout<<endl;
}
void Vista :: imprimirTabla(){
	for(int i=0; i<3;i++){
		imprimirUsuario(this->t->getPunteroapuntero(i));
	}
}
void Vista :: insertarUsuario(){
	TablaUsuarios* nueva = new TablaUsuarios;
	
	//nueva = new TablaUsuarios;
	//this->t = new TablaUsuarios;
}



















