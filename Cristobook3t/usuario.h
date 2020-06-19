#include <iostream>
#include "foto.h"
#include <stdlib.h>
using namespace std;

class Usuario{

	protected: 
		string login; //Debe ser único
		string nombre;
		string apellido;
		string perfil_usuario;
		
	
	public: 
		Usuario();
		
		void setLogin(string login_in);
		void setNombre(string nombre_in);
		void setApellido(string apellido_in);
		void setperfil_usuario(string perfil_usuario_in);
	//	void debug(string mnsj);
		string getLogin();	
		string getNombre();
		string getApellido();
		string getperfil_usuario();
		virtual void imprimirUsuario();
	/**
	 * @brief sobrecarga del operador = 
	 * @param se le pasa un puntero a usuario, que va a se copiado
	 */
		virtual Usuario* operator=(Usuario* u);
		virtual ~Usuario();
		
};



/******************************************** A D M I N **********************************************/

class Admin : public Usuario{
	protected: 
		int total_consultas;
		
	
	public:
		Admin() : Usuario(){
			this->total_consultas= 0;
		}
		/**
		 * @brief imprime un administrador con los artibutos de Usuario pero también con total consultas
		 * @param 
	 	*/
		void imprimirUsuario();
		void setTotalConsultas();
		int getTotalConsultas();
		/**
		 * @brief sobrecarga del operador = 
		 * @param se le pasa un puntero a admin, que va a se copiado
		 */
		Admin* operator=(Admin* a);
		
		/**
		 * @brief sobrecarga del operador << para poder imprimir el usuario
		 * @param se le pasa un puntero a usuario, que va a se copiado y flujo, lo que va a devolver
		 */
		friend ostream& operator<<(ostream &flujo, Admin *a);
		~Admin();
	
};








/******************************************** N O R M A L  **********************************************/


class Normal : public Usuario{

	protected: 
	Foto* v_fotos; 
	//int totalFotosUsuario; //utiles del vector
	double saldo;
	int dim_vfotos; //Dimension del vector
	
	
	public:    
		
		
		/*CONSTRUCTOR*/
		
		
		Normal() : Usuario(){
			dim_vfotos = 0;
			saldo=0.0;
			dim_vfotos=0;
			this->v_fotos = new Foto[dim_vfotos];
			if(this->v_fotos == 0){
				cerr << "no";
				exit(-1);
			}
		};
		
			
		/*CONSTRUCTOR POR COPIA*/
		
		
		Normal(Normal* n) : Usuario(){
			this->login = n->login; //Debe ser único
			this->nombre = n->nombre;
			this->apellido = n->apellido;
			this->perfil_usuario = n->perfil_usuario;
			
		//	totalFotosUsuario=0;
			saldo=0.0;
			dim_vfotos=0;
			cout<<"Constructor por copia empezando"<<endl;
			this->v_fotos = new Foto[dim_vfotos];
			cout<<"V_fotos copiado"<<endl;
			//this->v_fotos = n->v_fotos;
			cout<<"direccion V_fotos copiado"<<endl;
			if(this->v_fotos == 0){
				cerr << "no";
				exit(-1);
			}
			cout<<"Demás variables copiando"<<endl;
			
			
			this->saldo = n->saldo;
			this->dim_vfotos = n->dim_vfotos;
			for(int i = 0; i<dim_vfotos; i++){
				v_fotos[i] = n->v_fotos[i];
			}

			cout<<"saliendo del constructor"<<endl;
		};
		
		
		~Normal();
		
		void imprimirUsuario();
		void ImprimirFoto(Foto f);
		void eliminarFotoUsuario(int posicion_foto);
		
		void setdimFotos(int dim_vfotos_in);
		void setFoto(int posicion, Foto f_in);
		int getdimFotos();
		
		/**
		 * @brief método que ajusta la dimensión del vector de fotos del usuario normal
		 * @param int tamanio es la diensión que tendrá el nuevo vector
	 	*/
		void resizevFotos(int tamanio);
		/**
		 * @brief busca una foto para el método eliminarFoto
		 * @param se le pasa lastring ruta_buscada para encontrar es foto
		 */
		int buscarFoto(const string ruta_buscada);
		Foto getFoto(int posicion);
		/**
		 * @brief devuelve la dirección del vector de fotos
		 * @param 
		 */
		Foto* getV_fotos();
		/**
		 * @brief elimina el vector de fotos del usuario normal
		 * @param 
		 */
		void eliminarv_Fotos();
		/**
		 * @brief sobrecarga del operador = 
		 * @param se le pasa un puntero a usuario, que va a se copiado correctamente con su vector de fotos
		 */
		virtual Normal operator=(Normal* u);
		/**
		 * @brief sobrecarga del operador << para poder imprimir el usuario
		 * @param se le pasa un puntero a usuario, que va a se copiado y flujo, lo que va a devolver
		 */
		friend ostream& operator<<(ostream &flujo, Normal *n);
		
		
	
};

