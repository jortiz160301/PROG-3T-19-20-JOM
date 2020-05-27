#include <iostream>
using namespace std;
#include "foto.h"
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
	
};

class Normal : public Usuario{
	
};
