#include <iostream>
using namespace std;
#include "foto.h"
#include <stdlib.h>
class Usuario{

	protected: 
		string login; //Debe ser único
		string nombre;
		string apellido;
		string perfil_usuario;
		//int dim_vfotos; //Dimension del vector
		//int totalFotosUsuario; //utiles del vector
		//Foto* v_fotos; //Vector Dinámico de Burbujas (EjercicioUD7 Alumnos v1)
	
	public: 
		Usuario();
		void setLogin(string login_in);
		void setNombre(string nombre_in);
		void setApellido(string apellido_in);
		void setperfil_usuario(string perfil_usuario_in);
		/*void setdimFotos(int dim_vfotos_in);
		void settotalFotosUsuario(int totalFotosUsuario_in);
		void setFoto(int posicion, Foto f_in);*/
		string getLogin();	
		string getNombre();
		string getApellido();
		string getperfil_usuario();
		/*int getdimFotos();
		int gettotalFotosUsuario();
		Foto getFoto(int posicion);
		*/
};


class Admin : public Usuario{
	int total_consultas;
	void setTotalConsultas();
	int getTotalConsultas();
	void buscarFotografias(string cadena);
	
	
};

class Normal : public Usuario{

    public:    
	
		Normal() : Usuario(){
	
			this->v_fotos = new Foto[10];
	
			if(this->v_fotos == 0){
				cerr << "no" ;
				exit(-1);
			}
		
	};

	void setdimFotos(int dim_vfotos_in);
	void settotalFotosUsuario(int totalFotosUsuario_in);
	void setFoto(int posicion, Foto f_in);
	int getdimFotos();
	int gettotalFotosUsuario();
	Foto getFoto(int posicion);
	
	protected: 
	Foto* v_fotos; 
	int totalFotosUsuario; //utiles del vector
	double saldo;
	int dim_vfotos; //Dimension del vector
};