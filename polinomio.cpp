#include <iostream>
using namespace std;

class Polinomio{
	private: 
		float *coef;
		int grado;
		int grado_max;
	
	public: 
		Polinomio();
		void setCoef(float coef_in);
		void setCoefv2(float coef_in);
		float getCoef() const;
		void setGrado(int grado_in);
		int getGrado()const;
		void setGrado_max(int gradomax_in);
		int getGrado_max() const;
		void resize();
		void printPolinomio() const;
		~Polinomio();
};	
	
	
	Polinomio::Polinomio(){
        
        grado_max = 5;
        grado = 0;
        coef = new float[grado_max];
		for(int i=0;i<=grado_max;i++){
			coef[i]=0;
		}
		
	}

	void Polinomio :: setCoef(float coef_in){
		coef[grado]=coef_in;
	}
	
	void Polinomio :: setCoefv2(float coef_in){
		if(grado<grado_max){
			coef[grado]=coef_in;
		}else{
			resize();
			coef[grado]=coef_in;
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
	
	void Polinomio :: resize(){
		cout<<"Se hace resize:"<<endl;
		do{
			grado_max = grado_max+1;
		}while(grado>=grado_max);
	}
	
	void Polinomio :: printPolinomio()const{
		cout<<"El polinomio es: "<<endl;
		
		for(int i = 0; i<= grado_max; i++){
			if(coef[i] != 0){
				cout<<coef[i]<<"x^"<<i;
			}
		}
		
	}
	
	~Polinomio(){
		delete coef;
		coef=0;
		
	}
	
	
int main(){	
	float coef_in=0;
	int grado_in;
	Polinomio poli;
	int miembros;
	
	
	/*do{
		cout<<"Introduzca el grado máximo del polinomio que quiere introducir: "<<endl;
		cin>>gradomax_in;
		poli.setGrado_max(gradomax_in);
	}while(gradomax_in <= 0 || gradomax_in > 10);
	*/
	cout<<"Introiduzca el número de miembros del polinomio"<<endl;
	cin>>miembros;
	
	for(int i=0;i<miembros;i++){
		cout<<1<<endl;
		cout<<"Introduzca el grado del monomio"<<endl;
		cin>>grado_in;

		if(grado_in<poli.getGrado_max()){
			poli.setGrado(grado_in);
		}else{
			poli.resize();
		}
		cout<<2<<endl;
		
		cout<<"Introduzca el coeficiente para x^"<<grado_in<<":"<<endl;
		cin>>coef_in;
		cout<<3<<endl;
		//poli.setCoefv2(coef_in);
		cout<<4<<endl;
	}
	
	poli.printPolinomio();
	
	cout<<endl;
}