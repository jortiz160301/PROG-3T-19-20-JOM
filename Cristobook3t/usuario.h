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
		
	
	public: 
		Usuario();
		//Usuario(string nombre_in, string apellido_in, string login_in, string perfil_in);
		void setLogin(string login_in);
		void setNombre(string nombre_in);
		void setApellido(string apellido_in);
		void setperfil_usuario(string perfil_usuario_in);
		string getLogin();	
		string getNombre();
		string getApellido();
		string getperfil_usuario();
		virtual ~Usuario();
};


class Admin : public Usuario{
	protected: 
		int total_consultas;
		
	
	public:
		Admin() : Usuario(){
			this->total_consultas= 0;
		}   
		void setTotalConsultas();
		int getTotalConsultas();
		void buscarFotografias(string cadena);
		~Admin();
	
};

class Normal : public Usuario{

    
	protected: 
	Foto* v_fotos; 
	int totalFotosUsuario; //utiles del vector
	double saldo;
	int dim_vfotos; //Dimension del vector
	
	public:    
	
		Normal() : Usuario(){
			this->v_fotos = new Foto[10];
			if(this->v_fotos == 0){
				cerr << "no";
				exit(-1);
			}
		};
		void setdimFotos(int dim_vfotos_in);
		void settotalFotosUsuario(int totalFotosUsuario_in);
		void setFoto(int posicion, Foto f_in);
		int getdimFotos();
		int gettotalFotosUsuario();
		Foto getFoto(int posicion);
		~Normal();
		
	
};