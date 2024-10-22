/*NOMBRE: FARFAN DE LEON JOSE OSVALDO
  CODIGO: 214796622
  SECCION: "D07"
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <math.h>
using namespace std;

class Figuras{
	private:
		double base;
		double altura;
	public:
		void setBase(double);
		double getBase();
		void setAltura(double);
		double getAltura();
};

class Poligono:public Figuras{
    private:
        double area;
        double ang=0, apotema=0, tangente=0;
    public:
        void CalcularArea();
        double getArea();
};

class Triangulo:public Figuras{
    private:
        double area;
    public:
        void CalcularArea();
        double getArea();
};

class Cuadrado:public Figuras{
    private:
        double area;
    public:
        void CalcularArea();
        double getArea();
};
class Rectangulo:public Figuras{
    private:
        double area;
    public:
        void CalcularArea();
        double getArea();
};

void Figuras:: setBase (double base){
    this->base=base;
}
double Figuras:: getBase (){
    return this->base;
}
void Figuras:: setAltura (double altura){
    this->altura=altura;
}
double Figuras:: getAltura (){
    return this->altura;
}

//Clase hija Triangulo
void Triangulo:: CalcularArea(){
    this->area=(this->getBase()*this->getAltura())/2;
}
double Triangulo:: getArea(){
    return this->area;
}
//Clase hija Cuadrado
void Cuadrado:: CalcularArea(){
    this->area=this->getBase()*this->getBase();
}
double Cuadrado:: getArea(){
    return this->area;
}
//Clase hija Rectangulo
void Rectangulo:: CalcularArea(){
    this->area=this->getBase()*this->getAltura();
}
double Rectangulo:: getArea(){
    return this->area;
}

//Clase hija Poligono
void Poligono:: CalcularArea(){
    double ang=0, apotema=0, tangente=0;
    ang=(360/this->getBase())/2;
    tangente=tan(ang*(3.14159265/180.0));
    apotema=(this->getAltura()/2)/tangente;
    this->area=(this->getBase()*this->getAltura()*apotema)/2;
}
double Poligono:: getArea(){
    return this->area;
}
//---------------------------------------------------------------------------
int validar ();

int main(int argc, char** argv) {
	double base=0,altura=0;
	int opc=0;
    Triangulo t;
    Cuadrado c;
    Rectangulo r;
    Poligono p;
	do{
        system("cls");
		cout<<"Menu"<<endl;
		cout<<"1)Triangulo"<<endl;
		cout<<"2)Cuadrado"<<endl;
		cout<<"3)Rectangulo"<<endl;
		cout<<"4)Poligono"<<endl;
		cout<<"5)Salir"<<endl;
		cout<<"Ingrese una opcion valida: ";
		opc=validar();
		switch(opc){
			case 1:{
					cout<<"Ingrese Base:"<<endl;
					base= validar();
					cout<<"Ingrese Altura:"<<endl;
					altura= validar();
					t.setBase(base);
					t.setAltura(altura);
					t.CalcularArea();
					cout<<"Area:"<<t.getArea()<<endl;
		      	}break;
            case 2:{
                    cout<<"Ingrese Base:"<<endl;
					base= validar();
					c.setBase(base);
					c.CalcularArea();
					cout<<"Area:"<<c.getArea()<<endl;
            }break;
            case 3:{
					cout<<"Ingrese Base:"<<endl;
					base= validar();
					cout<<"Ingrese Altura:"<<endl;
					altura= validar();
					r.setBase(base);
					r.setAltura(altura);
					r.CalcularArea();
					cout<<"Area:"<<r.getArea()<<endl;
            }break;
            case 4:{
					cout<<"Ingrese el numero de lados: ";
					base= validar();
					cout<<"Ingrese la medida del lado: ";
					altura= validar();
					p.setBase(base);
					p.setAltura(altura);
					p.CalcularArea();
					cout<<"Area:"<<p.getArea()<<endl;
            }
		}
		system("pause");
	}while(opc!=5);
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
