/*NOMBRE: FARFAN DE LEON JOSE OSVALDO
  CODIGO: 214796622
  SECCION: "D07"
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <math.h>

using namespace std;

class CasadeMoneda{
	private:
		double cantidad;
	public:
		void setCantidad(double);
		double getCantidad();
};

class Peso_dolar:public CasadeMoneda{
    private:
        double cambio;
    public:
        void CalcularCambio();
        double getCambio();
};

class Dolar_peso:public CasadeMoneda{
    private:
        double cambio;
    public:
        void CalcularCambio();
        double getCambio();
};
class Peso_euro:public CasadeMoneda{
    private:
        double cambio;
    public:
        void CalcularCambio();
        double getCambio();
};
class Euro_peso:public CasadeMoneda{
    private:
        double cambio;
    public:
        void CalcularCambio();
        double getCambio();
};
class Peso_yen:public CasadeMoneda{
    private:
        double cambio;
    public:
        void CalcularCambio();
        double getCambio();
};
class Yen_peso:public CasadeMoneda{
    private:
        double cambio;
    public:
        void CalcularCambio();
        double getCambio();
};
class Peso_yuan:public CasadeMoneda{
    private:
        double cambio;
    public:
        void CalcularCambio();
        double getCambio();
};
class Yuan_peso:public CasadeMoneda{
    private:
        double cambio;
    public:
        void CalcularCambio();
        double getCambio();
};
//------------------------------------------------------
void CasadeMoneda:: setCantidad(double cantidad){
    this->cantidad=cantidad;
}
double CasadeMoneda:: getCantidad(){
    return this->cantidad;
}

//Clases hija Peso-Dolar
void Peso_dolar:: CalcularCambio(){
    this->cambio=this->getCantidad()/21.4311;
}
double Peso_dolar:: getCambio(){
    return this->cambio;
}
void Dolar_peso:: CalcularCambio(){
    this->cambio=this->getCantidad()*21.4311;
}
double Dolar_peso:: getCambio(){
    return this->cambio;
}
//peso-euro
void Peso_euro:: CalcularCambio(){
    this->cambio=this->getCantidad()/25.20;
}
double Peso_euro:: getCambio(){
    return this->cambio;
}
void Euro_peso:: CalcularCambio(){
    this->cambio=this->getCantidad()*25.20;
}
double Euro_peso:: getCambio(){
    return this->cambio;
}

//PESO-YEN
void Peso_yen:: CalcularCambio(){
    this->cambio=this->getCantidad()*472336;
}
double Peso_yen:: getCambio(){
    return this->cambio;
}
void Yen_peso:: CalcularCambio(){
    this->cambio=this->getCantidad()/472336;
}
double Yen_peso:: getCambio(){
    return this->cambio;
}
//PESO-YUAN
void Peso_yuan:: CalcularCambio(){
    this->cambio=this->getCantidad()/3.15;
}
double Peso_yuan:: getCambio(){
    return this->cambio;
}
void Yuan_peso:: CalcularCambio(){
    this->cambio=this->getCantidad()*3.15;
}
double Yuan_peso:: getCambio(){
    return this->cambio;
}

//----------------------------------------------------

int validar ();
int main(int argc, char** argv) {
	double cantidad=0;
	int opc=0;
    Peso_dolar pd;
    Dolar_peso dp;
    Peso_euro pe;
    Euro_peso ep;
    Peso_yen py;
    Yen_peso yp;
    Peso_yuan pyu;
    Yuan_peso yup;
	do{
        system("cls");
		cout<<"Menu"<<endl;
		cout<<"1)Peso-Dolar"<<endl;
		cout<<"2)Dolar-Peso"<<endl;
		cout<<"3)Peso-Euro"<<endl;
		cout<<"4)Euro-Peso"<<endl;
		cout<<"5)Peso-Yen"<<endl;
		cout<<"6)Yen-Peso"<<endl;
		cout<<"7)Peso-Yuan"<<endl;
		cout<<"8)Yuan-Peso"<<endl;
		cout<<"9)salir"<<endl;
		cout<<"Ingrese una opcion valida: ";
		opc=validar();
		switch(opc){
			case 1:{
					cout<<"Ingrese los pesos a cambiar:";
					cantidad= validar();
					pd.setCantidad(cantidad);
					pd.CalcularCambio();
					cout<<"Dolares: "<<pd.getCambio()<<endl;
		      	}break;
            case 2:{
                    cout<<"Ingrese los dolares a cambiar:";
					cantidad= validar();
					dp.setCantidad(cantidad);
					dp.CalcularCambio();
					cout<<"pesos: "<<dp.getCambio()<<endl;
                }break;
            case 3:{
                    cout<<"Ingrese la cantidad de pesos:";
					cantidad= validar();
					pe.setCantidad(cantidad);
					pe.CalcularCambio();
					cout<<"Euros: "<<pe.getCambio()<<endl;

                }break;
            case 4:{
					cout<<"Ingrese la cantidad de euros:";
					cantidad= validar();
					ep.setCantidad(cantidad);
					ep.CalcularCambio();
					cout<<"pesos: "<<ep.getCambio()<<endl;
                }break;
            case 5:{
                    cout<<"Ingrese la cantidad de pesos:";
					cantidad= validar();
					py.setCantidad(cantidad);
					py.CalcularCambio();
					cout<<"Yens: "<<py.getCambio()<<endl;

                }break;
            case 6:{
					cout<<"Ingrese la cantidad de yen's: ";
					cantidad= validar();
					yp.setCantidad(cantidad);
					yp.CalcularCambio();
					cout<<"pesos: "<<yp.getCambio()<<endl;

                }break;
            case 7:{
					cout<<"Ingrese la cantidad depesos: ";
					cantidad= validar();
					pyu.setCantidad(cantidad);
					pyu.CalcularCambio();
					cout<<"yuanes: "<<pyu.getCambio()<<endl;
                }break;
            case 8:{
					cout<<"Ingrese la cantidad de yuanes: ";
					cantidad= validar();
					yup.setCantidad(cantidad);
					yup.CalcularCambio();
					cout<<"pesos: "<<yup.getCambio()<<endl;
                }break;
		}
		system("pause");
	}while(opc!=9);
	system("cls");
	return 0;
}

int validar (){
    char dato[10];
    int n;
    do{
    	cin>>dato;
    	n=atoi(dato);
    	if(n==0){
            cout<<"Error... DATO INVALIDO"<<endl;
            Sleep(2000);
            cout<<"\e[A";
            cout<<"Ingrese una opcion valida: ";
    	}
	}while(n==0);
  return n;
}

