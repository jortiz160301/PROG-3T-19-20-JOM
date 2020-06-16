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
		//Normal* operator=(Normal* u);
		virtual ~Usuario();
		
};





class Admin : public Usuario{
	protected: 
		int total_consultas;
		
	
	public:
		Admin() : Usuario(){
			this->total_consultas= 0;
		}   
		Foto* getV_fotos();
		void setTotalConsultas();
		int getTotalConsultas();
		void buscarFotografias(string cadena);
		Admin* operator=(Admin* a);
		friend ostream& operator<<(ostream &flujo, const Admin *a);
		~Admin();
	
};




class Normal : public Usuario{

    
	protected: 
	Foto* v_fotos; 
	//int totalFotosUsuario; //utiles del vector
	double saldo;
	int dim_vfotos; //Dimension del vector
	
	
	public:    
		
		Normal() : Usuario(){
			
		//	totalFotosUsuario=0;
			dim_vfotos = 0;
			saldo=0.0;
			dim_vfotos=0;
			this->v_fotos = new Foto[dim_vfotos];
			if(this->v_fotos == 0){
				cerr << "no";
				exit(-1);
			}
		};
		
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
			
			
		//	this->totalFotosUsuario = n->totalFotosUsuario;
			this->saldo = n->saldo;
			this->dim_vfotos = n->dim_vfotos;
			for(int i = 0; i<dim_vfotos; i++){
				v_fotos[i] = n->v_fotos[i];
			}
			
			
			cout<<"saliendo del constructor"<<endl;
		};
		
		
		
		
		
		void ImprimirFoto(Foto f);
		void setdimFotos(int dim_vfotos_in);
	//	void settotalFotosUsuario(int totalFotosUsuario_in);
		void setFoto(int posicion, Foto f_in);
		int getdimFotos();
		void resizevFotos(int tamanio);
		int buscarFoto(const string ruta_buscada);
		//int gettotalFotosUsuario();
		Foto getFoto(int posicion);
		Foto* getV_fotos();
		void eliminarv_Fotos();
		Normal operator=(Normal* u);
		friend ostream& operator<<(ostream &flujo, Normal *n);
		~Normal();
		
	
};
/*

Usuario* Usuario::operator=(Usuario* u){
			if(u!= this){
				if(Normal* n = dynamic_cast<Normal*>(u)){
					delete[] n->v_fotos;
					this->dim_vfotos = n->dim_vfotos;
					this->v_fotos = new Foto[n->dim_vfotos];
					this->saldo = n->saldo;
					for(int i = 0; i>this->dim_vfotos; i++){
						this->v_fotos[i] = n->v_fotos[i];
					}
					
				}else if(Admin* a = dynamic_cast<Admin*>(u)){
						this->setTotalConsultas(a->getTotalConsultas());
				}
				this->setLogin(u->getLogin());
				this->setNombre(u->getNombre());
				this->setApellido(u->getApellido());
				this->setperfil_usuario(u->getperfil_usuario());
			}
			return *this;
}*/