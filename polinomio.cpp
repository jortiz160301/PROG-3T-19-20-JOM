#include <iostream>
using namespace std;

bool testing = true;
class Polinomio{
	private: 
		float *coef;
		int grado;
		int grado_max;
	
	public: 
		Polinomio();
		void setCoef(float coef_in);
		void setCoefv2(int grado, float coef_in);
		float getCoef() const;
		void setGrado(int grado_in);
		int getGrado()const;
		void setGrado_max(int gradomax_in);
		int getGrado_max() const;
		void resize(int grado);
		void printPolinomio() const;
		void testing();
		~Polinomio();
};	
	
	
	Polinomio::Polinomio(){
        
       cout << "DEBUG: Llamada al constructor por defecto..." << endl;
        
        grado = 0; 
        grado_max = 4;
        
        coef = new float[grado_max+1]; 
        if (coef == 0){
            cerr << "Se terminará la ejecución del programa..." << endl;
        }
        //Inicializo a ceros los coeficientes
        for (int i=0; i <= grado_max; i++){
            coef[i] = 0.0;
        }
        cout << "DEBUG: Objeto polinomio construido correctamente..." << endl;
		}
		
	

	void Polinomio :: setCoef(float coef_in){
		coef[grado]=coef_in;
	}
	
	void Polinomio :: setCoefv2(int grado, float coef_in){
		if(grado >= 0){
			if(grado<grado_max){
				coef[grado]=coef_in;
			//	cout<<grado<<endl;
			}else{
				resize(grado);
				coef[grado]=coef_in;
				//cout<<grado<<endl;
			}
		}else{
		cout<<"Ha introducido un valor negativo como grado. Este no se va a tomar en cuenta."<<endl;
		
		}
	}
	
	float Polinomio :: getCoef()const{
		return coef[grado];
	}
	
	void Polinomio :: setGrado(int grado_in){
		grado = grado_in;
	}
	
	int Polinomio :: getGrado()const{
		return grado;
	}
	//introducidsos el set y get de grado_max
	void Polinomio :: setGrado_max(int gradomax_in){
		grado_max = gradomax_in;
	}
	
	int Polinomio :: getGrado_max()const{
		return grado_max;
	}
	
	void Polinomio :: resize(int grado_in){
		
		cout<<"Se hace resize:"<<endl;
		
		float *aux;
		aux = new float[grado_in+1]; 
		
		for (int i=0; i <= grado_in; i++){
            aux[i] = 0.0;
        }
      
        for (int i=0; i <= grado_max; i++){
        	aux[i] = coef[i];
        }
        delete[] coef;
        coef = aux;
		grado_max = grado_in;
		
	}
	
	void Polinomio :: printPolinomio()const{
		cout<<"El polinomio es: "<<endl;
		
		for(int i = 0; i<= grado_max; i++){
			if(coef[i] != 0){
				cout<<coef[i]<<"x^"<<i<<" + ";
			}
		}
		cout<<endl;
	}
	void Polinomio :: testing(){
		
		grado_max = 4;
		cout<<"Elija introduciendo un número: \n"<<endl;
		cout<<"Caso 1: insertar un monomio de grado menor que el grado actual"<<endl;
		cout<<"Caso 2: insertar un monomio de grado negativo"<<endl;
		cout<<"Caso 3: insertar un monomio de grado mayor al grado actual, pero que sea menor que max_grado"<<endl;
		cout<<"Caso 4: insertar un monomio de grado mayor al grado actual, y que sea mayor que max_grado"<<endl;
		cout<<"Caso 5:  insertar un monomio de grado igual que el grado actual, y cuyo coeficiente sea cero"<<endl;
		cout<<"Subcaso 5.1:  ¿y si todos los coeficientes anteriores también son cero?"<<endl;
	
		int opcion = 0;
		cin>>opcion;
		cout<<endl;
		
		
		
		
		if(opcion == 1){
			setCoefv2(2,3);
			cout<<"Establezco un grado actual haciendo setGrado(3)"<<endl;
			setGrado(3);
			
			cout<<"El grado actual es: "<<getGrado()<<endl;
			
			cout<<"Y creo un monomio en ese grado haciendo setCoefv2(3,2) y lo muestro: "<<endl;
			setCoefv2(3,2);
			cout<<getCoef()<<"x^"<<getGrado()<<endl;
			cout<<"Ahora introduzco un monomio de grado menor al actual haciendo setCoefv2(1,3) y muestro el POLINOMIO: "<<endl;
			setCoefv2(2,1);
			
			printPolinomio();
			
		}else if(opcion ==2){
			cout<<"Introduzco un valor negativo en grado haciendo setCoefv2(-3,4): "<<endl;
			setCoefv2(-3,4);
			
		}else if(opcion ==3){
			cout<<"Grado max = "<<getGrado_max()<<endl;
			cout<<"Establezco un grado actual haciendo setGrado(2)"<<endl;
			setGrado(2);
			cout<<"Inserto un monomio en un grado mayor al actual haciendo setCoefv2(3,2) y lo muestro: "<<endl;
			setCoefv2(3,2);
			setGrado(3);
			cout<<getCoef()<<"x^"<<getGrado()<<endl;
			setGrado(2);
			cout<<"Muestro el POLINOMIO"<<endl;
			printPolinomio();
			
		}else if(opcion ==4){
			cout<<"Grado max = "<<getGrado_max()<<endl;
			cout<<"Establezco un grado actual haciendo setGrado(3)"<<endl;
			setGrado(3);
			cout<<"Inserto un monomio en un grado mayor al máximo haciendo setCoefv2(7,2) y lo muestro: "<<endl;
			setCoefv2(7,2);
			setGrado(7);
			cout<<getCoef()<<"x^"<<getGrado()<<endl;
			setGrado(3);
			cout<<"Muestro el POLINOMIO"<<endl;
			printPolinomio();
				
		
			
		
		}else if(opcion ==5){
			cout<<"Establezco un grado actual haciendo setGrado(3)"<<endl;
			setGrado(3);
			cout<<"Y creo un monomio con coeficiente = 0 y grado 3"<<endl;
			setCoefv2(3,0);
			printPolinomio();
		
		}else if(opcion ==6){
			
		
		}

	}
	
	
	Polinomio :: ~Polinomio(){
		delete coef;
		coef=0;
		
	}
	
	
int main(){	
	float coef_in= 0;
	int grado_in;
	int gradomax_in;
	Polinomio poli;
	int miembros;
	
	poli.testing();
	
	
	cout<<"Introduzca grado máximo del polinomio"<<endl;
	cin>>gradomax_in;

	if(gradomax_in > poli.getGrado_max()){//Si el grado máximo introducido es mayor al preexistente, se establece este como grado_max  y se hace resize
		poli.setGrado_max(gradomax_in);
		poli.resize(gradomax_in);
	}
	
	for(int i=0;i<poli.getGrado_max();i++){

		do{
			cout<<"Introduzca el grado del monomio"<<endl;
			cin>>grado_in;
			
			if(grado_in < 0){
				cout<<"Por favor, introduzca un grado positivo."<<endl;
			}
			
		}while(grado_in < 0);
		
		if(grado_in<poli.getGrado_max()){
			poli.setGrado(grado_in);
		}else{
			poli.resize(grado_in);
		}


		cout<<"Introduzca el coeficiente para x^"<<grado_in<<":"<<endl;
		cin>>coef_in;
		
		poli.setCoefv2(grado_in,coef_in);

		cout<<poli.getGrado_max()<<endl;

	}
	
	poli.printPolinomio();
	
	cout<<endl;
}