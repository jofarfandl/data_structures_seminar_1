/*Farfan de Lon Jose Osvaldo
  Codigo:214796622
  Seccion:"D07"
-----------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <cstdlib>
using namespace std;

class Nodo{
    public:
        int value;
        Nodo* next;
};

bool cola_vacia(Nodo *frente){
    return (frente==NULL)? true : false;
}

void push(Nodo *&frente, Nodo *&fin, int n){

    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->value=n;
    nuevo_nodo->next=NULL;
    if(cola_vacia(frente)){
        frente = nuevo_nodo;
    }else{
        fin->next = nuevo_nodo;
    }
    fin = nuevo_nodo;
};

void pop(Nodo *&frente, Nodo *&fin){
    Nodo *aux = frente;
    if(frente == fin){
        frente = NULL;
        fin ==NULL;
    }else{
        frente = frente->next;
    }
    delete aux;
};

int consultar_inicio(Nodo *&frente, Nodo *&fin){
    if(cola_vacia(frente)){
        cout<<"Cola vacia"<<endl;
    }else{
        cout<<"El inicio es: "<<frente->value<<endl;
    }
    system("pause");
};

int consultar_fin(Nodo *&frente, Nodo *&fin){
    if(cola_vacia(frente)){
        cout<<"Cola vacia"<<endl;
    }else{
        cout<<"El fin es: "<<fin->value<<endl;
    }
    system("pause");
};

void display(Nodo *&frente, int cont){
    Nodo *temp;
    temp = frente;

    while(temp != NULL){
        cout<<" "<<temp->value<<" ";
        temp = temp->next;
    }
};

int validar (){
    char dato[10];
    int n;
    do{
    	cin>>dato;
    	n=atoi(dato);
    	if(n==0) cout<<"Error... Ingrese un dato valido: ";
	}while(n==0);
  return n;
};



int menu(){
    int opc;
    cout<<endl;
    cout<<"MENU"<<endl;
    cout<<"[1]Encolar(Push)"<<endl;
    cout<<"[2]Mostrar Inicio"<<endl;
    cout<<"[3]Mostrar fin"<<endl;
    cout<<"[4]Des-Encolar(Pop)"<<endl;
    cout<<"[5]Mostrar cola"<<endl;
    cout<<"[6]Salir"<<endl;
    opc = validar();
    return opc;
};

int main(){
    int band=0;
    Nodo *frente = NULL;
    Nodo *fin = NULL;
    int value,
    cont=0, opc=1, cont2=0;
    do{
        switch(menu()){
            case 1:
                cont2++;
                cont++;
                push(frente, fin, cont);
                system("cls");
                display(frente, cont2);
                break;
            case 2:
                consultar_inicio(frente, fin);
                system("cls");
                display(frente, cont2);
                break;
            case 3:
                consultar_fin(frente, fin);
                system("cls");
                display(frente, cont2);
                break;
            case 4:
                cont2--;
                pop(frente, fin);
                system("cls");
                display(frente, cont2);
                break;
            case 5:
                system("cls");
                display(frente, cont2);
                break;
            case 6:
                cout<<"Fin del programa"<<endl;
                band++;
                break;
        }
    }while(band != 1);
    return 0;
};
