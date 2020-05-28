#include <iostream>
using namespace std;
#include "vista.h"

	
Vista::Vista(){
	this->t = new TablaUsuarios;
};
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