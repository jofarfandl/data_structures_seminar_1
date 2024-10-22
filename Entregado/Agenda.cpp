#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

struct agenda{
   int cve;
   char nombre[30];
   char direccion[30];
}a[5];
int index=0;
void menu();
void registrar();
int buscar(int);
void editar(int);
void remover(int);
void listar();
void mostrar(int);

int main(int argc, char** argv) {
   int opc=0;
   do{
   	system("cls");
   	 menu();
    cout<<"Continuar 1 salir 2:"<<endl;
    cin>>opc;
   }while(opc!=2);
   system("pause>>cls");
	return 0;
}
void menu(){
	int opc=0,cve=0;
	cout<<"Agenda"<<endl;
	cout<<"1) registrar"<<endl;
	cout<<"2) buscar por clave"<<endl;
	cout<<"3) editar"<<endl;
	cout<<"4) remover"<<endl;
	cout<<"5) listar"<<endl;
	cout<<"6) salir"<<endl;
    cout<<"Seleccione opcion:"<<endl;
    cin>>opc;
	switch(opc){
		case 1: registrar();break;
		case 2: {
			     cout<<"Ingrese la clave del contacto:"<<endl;
                 cin>>cve;
			      mostrar(buscar(cve));
		        }break;
	//	case 3: editar();break;
	//	case 4: remover();break;
	//	case 5: listar();break;
	}

}
void registrar(){
	char n[10][30];
	a[index].cve=index+1;
	cout<<"ingrese nombre:"<<endl;
    cin>>a[index].nombre;
    cout<<"ingrese direccion:"<<endl;
    cin>>a[index].direccion;
    index++;
}
int buscar(int cve){
	int x=0,ban=0,posicion=0;
	while(x<5 && ban==0){
		if(cve==a[x].cve){
		   posicion=x;
		   ban=1;
		}
		x++;
	}
	return posicion;
}

void mostrar(int pos){
	cout<<"Clave: "<<a[pos].cve<<endl;
	cout<<"Nombre: "<<a[pos].nombre<<endl;
	cout<<"Direccion: "<<a[pos].direccion<<endl;

}end
