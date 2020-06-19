#include <iostream>
using namespace std;
class Foto{
	
	private: 
		string ruta; //Ruta del archivo en el SO
		string tipo; //Ej: jpg, png
		unsigned long int tamanio; // Se va a guardar en bytes
	
	public:
		/**
		 * @brief constructor 
		 * @version
		 */
		Foto();
		void setRuta(string ruta_in);
		void setTipo(string tipo_in);
		void setTamanio(unsigned long int tamanio_in);
		//void muestraDebug(string mnsj);
		
		string getRuta();
		string getTipo();
		unsigned long int getTamanio();
		
		void ImprimirFoto();
		~Foto(){
			this->ruta = "";
			this->tipo = "";
			this->tamanio = 0;
			cout<<"Destruye Foto"<<endl;
		}
		
		
};

