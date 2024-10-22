/*Farfan de Leon Jose Osvaldo
  Codigo: 214796622
  Seccion:"D07"
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <cstdlib>
using namespace std;

class Nodo{
    public:
        int value;
        Nodo* next;
};

void push(Nodo *&pila, int n){//*&
    Nodo *temp = new Nodo();// crear nuevo nodo
    temp->value = n;//le damos el  nuevo valor a lo que tenga dentro la direccion
    temp->next = pila;
    pila = temp;
};

void pop(Nodo *&pila){
    Nodo *temp = pila;
    pila = temp->next;
    delete(temp);
};

void display(Nodo *&pila, int cont){
    Nodo *temp;
    temp = pila;

    cout << "\n";
    while(temp!=NULL){
        if(temp==pila){
            cout <<"\t*"<<temp->value<<"*";
            temp=temp->next;
        }else{
            cout <<"\t*"<<temp->value<<"*";
            temp=temp->next;
        }
    }
    cout << '\n';

};

int validar (){
    char dato[10];
    int n;
    do{
    	cin>>dato;
    	n=atoi(dato);
    	if(n==0) cout<<"Error... Ingrese un dato valido: ";
	}while(n==0);
	system("cls");
  return n;
}

int menu(){
    int opc;
    cout << "\n\n1.- Push"
            "\n2.- Pop"
            "\n3.- Tope"
            "\n4.- Salir"<<endl;
    //cin>>opc;
    opc= validar();
    return opc;
};

int main(){
    Nodo *pila = NULL;
    int value, cont=0, opc=1;
    do{
            switch(menu()){
                case 1:
                    cont++;
                    push(pila, cont);
                    system("cls");
                    display(pila, cont);
                break;
                case 2:
                    cont--;
                    pop(pila);
                    system("cls");
                    display(pila, cont);
                break;
                case 3:
                    cout<<"el tope es:"<<cont<<endl;
				break;

                case 4:
                opc=4;
                break;

                default: cout <<"\nOpcion no disponible" << 'n';
            }
    }while(opc!=4);
    return 0;
}
