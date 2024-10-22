#include <iostream>
#include <cstdlib>
using namespace std;

int *ptr1=NULL,*ptr2=NULL;

int * suma(int*,int*);
int * resta(int*,int*);
int * multiplicacion(int*,int*);
int * division(int*,int*);
int a=0,b=0;

int main(int argc, char** argv){
    int opc;
    do {
            system("cls");
            cout << "Menu de Opciones\n" << endl;
            cout << "1. Suma." << endl;
            cout << "2. Resta." << endl;
            cout << "3. Multiplicacion" << endl;
            cout << "4. Division" << endl;
            cout << "5. SALIR" << endl;
            cout << "\nIngrese una opcion: ";
            cin >> opc;
            if(opc!=5){
                cout<<"ingrese numero 1:"<<endl;
                cin>>a;
                cout<<"ingrese numero 2:"<<endl;
                cin>>b;
            }
            ptr1=&a;
            ptr2=&b;
            switch (opc) {
                case 1: cout<<"El resultado es: "<< *suma(ptr1,ptr2)<<endl;system("pause");;break;
                case 2: cout<<"El resultado es: "<< *resta(ptr1,ptr2)<<endl;system("pause");;break;
                case 3: cout<<"El resultado es: "<< *multiplicacion(ptr1,ptr2)<<endl;system("pause");;break;
                case 4: cout<<"El resultado es: "<< *division(ptr1,ptr2)<<endl;system("pause");;break;
                case 5:
                    cout<<"Usted selecciono salir del programa"<<endl;
                    system("pause");
                    break;
            }
        } while (opc != 5);
    return 0;
};


int * suma(int *a,int *b){
int *r=(int*)malloc(sizeof(int));
*r=*a+*b;
return r;
}

int * resta(int *a,int *b){
int *r=(int*)malloc(sizeof(int));
*r=*a-*b;
return r;
}

int * multiplicacion(int *a,int *b){
int *r=(int*)malloc(sizeof(int));
*r=(*a)*(*b);
return r;
}

int * division(int *a,int *b){
int *r=(int*)malloc(sizeof(int));
*r=(*a)/(*b);
return r;
}
