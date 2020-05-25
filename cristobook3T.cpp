#include <iostream>
using namespace std;

class Foto{
	
	private: 
		string ruta; //Ruta del archivo en el SO
		string tipo; //Ej: jpg, png
		unsigned long int tamanio; // Se va a guardar en bytes
	
	public:
		Foto();
		void setRuta(string ruta_in);
		void setTipo(string tipo_in);
		void setTamanio(unsigned long int tamanio_in);
		
		string getRuta();
		string getTipo();
		unsigned long int getTamanio();
}


class Usuario{
	
	private: 
		string login; //Debe ser único
		string nombre;
		string apellido;
		string perfil_usuario;
		int dim_vfotos; //Dimension del vector
		int totalFotosUsuario; //utiles del vector
		Foto* v_fotos; //Vector Dinámico de Burbujas (EjercicioUD7 Alumnos v1)
	
	public: 
		Usuario();
		void setLogin(string login_in);
		void setNombre(string nombre_in);
		void setApellido(string apellido_in);
		void setperfil_usuario(string perfil_usuario_in);
		void setdimFotos(int dim_vfotos_in);
		void settotalFotosUsuario(int totalFotosUsuario_in);
		void setFoto(int posicion, Foto f_in);
		
		string getLogin(){	
		string getNombre();
		string getApellido(;
		string getperfil_usuario(;
		int getdimFotos();
		int gettotalFotosUsuario();
		Foto getFoto(int posicion);

}





class TablaUsuarios{

	private: 
		Usuario** punteroapuntero; //Vector Dinámico de Punteros a Burbuja (EjercicioUD7 Alumnos v2)
		int totaltuplas;
		//La reserva siempre es exacta y al tamaño, la dimensión, siempre coincide con las útiles.
	
	public:
		void setPunteroapuntero(int posicion, Usuario* u);
		void setTotaltuplas(int totaltuplas_in);
		
		Usuario* getPunteroapuntero(int posicion);
		int getTotaltuplas();
}


void menu(TablaUsuarios &t){

	int opcion;
	bool menu=true;
	bool imprimir = true;
	bool tabla_creada = false;
	
	do{
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
		
		FiltrarLetras(opcion);
	
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
		
	
	
	}while(menu == true && (opcion != 1 || opcion != 2 || opcion !=3 || opcion !=4 || opcion !=5 || opcion !=6 || opcion !=7 || opcion !=8 || opcion !=9 || opcion !=10 ));

	
}