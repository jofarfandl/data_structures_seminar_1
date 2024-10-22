/*Farfan de Leon Jose Osvaldo
   Codigo: 214796622
   Materia: Seminario de Estructura de Datos
   Seccion: "D07"
*/
#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;

class Celsiusk{
	private:
	    float grado;
	    float res;
	public:
		void setGrado(float);
		double getGrado();
		void CalcularRes();
		double getRes();
};

void Celsiusk::setGrado(float grado){
	this->grado=grado;
}
double Celsiusk:: getGrado(){
	return this->grado;
}

void Celsiusk::CalcularRes(){
	this->res=(this->grado + 273.15);
}
double Celsiusk:: getRes(){
	return this->res;
}
//---------------------------------------------------------------------------
class KelvinC{
	private:
	    float grado;
	    float res;
	public:
		void setGrado(float);
		double getGrado();
		void CalcularRes();
		double getRes();
};

void KelvinC::setGrado(float grado){
	this->grado=grado;
}
double KelvinC:: getGrado(){
	return this->grado;
}

void KelvinC::CalcularRes(){
	this->res=(this->grado - 273.15);
}
double KelvinC:: getRes(){
	return this->res;
}
//--------------------------------------------
class CelsiusF{
	private:
	    float grado;
	    float res;
	public:
		void setGrado(float);
		double getGrado();
		void CalcularRes();
		double getRes();
};

void CelsiusF::setGrado(float grado){
	this->grado=grado;
}
double CelsiusF:: getGrado(){
	return this->grado;
}

void CelsiusF::CalcularRes(){
	this->res=((this->grado*1.8)+32);
}
double CelsiusF:: getRes(){
	return this->res;
}
//--------------------------------------------------------
class FahrenheitC{
	private:
	    float grado;
	    float res;
	public:
		void setGrado(float);
		double getGrado();
		void CalcularRes();
		double getRes();
};

void FahrenheitC::setGrado(float grado){
	this->grado=grado;
}
double FahrenheitC:: getGrado(){
	return this->grado;
}

void FahrenheitC::CalcularRes(){
	this->res=((this->grado-32)/1.8);
}
double FahrenheitC:: getRes(){
	return this->res;
}
//-------------------------------------------------------
int main(int argc, char** argv) {
	system("cls");
	float grado=0;
	int opc=0;
	do{
        system("cls");
        cout<<"Menu"<<endl;
        cout<<"1)Celsius-Kelvin"<<endl;
        cout<<"2)Kelvin-Celsius"<<endl;
        cout<<"3)Celsius-Fahrenheit"<<endl;
        cout<<"4)Fahrenheit-Celsius"<<endl;
        cout<<"5)Salir"<<endl;
        cout<<"Ingrese una opcion valida:"<<endl;
        cin>>opc;
		switch(opc){
			case 1:{
                    Celsiusk ob;
					cout<<"Ingrese los grados Celsius:"<<endl;
	            	cin>>grado;
	            	ob.setGrado(grado);
	            	ob.CalcularRes();
	            	cout<<"Los grados Kelvin son:"<< ob.getRes()<<endl;
	            	system("pause");
		      	}break;
            case 2:{
                    KelvinC ob;
					cout<<"Ingrese los grados Kelvin:"<<endl;
	            	cin>>grado;
	            	ob.setGrado(grado);
	            	ob.CalcularRes();
	            	cout<<"Los grados Celsius son:"<< ob.getRes()<<endl;
	            	system("pause");
            }break;
            case 3:{
					CelsiusF ob;
					cout<<"Ingrese los grados Celsius:"<<endl;
	            	cin>>grado;
	            	ob.setGrado(grado);
	            	ob.CalcularRes();
	            	cout<<"Los grados Fahrenheit son:"<< ob.getRes()<<endl;
	            	system("pause");
            }break;
            case 4:{
					FahrenheitC ob;
					cout<<"Ingrese los grados Fahrenheit:"<<endl;
	            	cin>>grado;
	            	ob.setGrado(grado);
	            	ob.CalcularRes();
	            	cout<<"Los grados Centigrados son:"<< ob.getRes()<<endl;
	            	system("pause");
            }break;
		}
	}while(opc!=5);
	cout<<"Saliendo..."<<endl;
	Sleep(3000);
	system("cls");
	return 0;
}
