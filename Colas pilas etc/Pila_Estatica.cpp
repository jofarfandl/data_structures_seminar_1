#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
using namespace std;

class pila{
    private:
        int datos[10],tope;
    public:
        pila();
        void push();
        void pop();
        int vacia();
        int llena();
        void mostrar_tope();
        void mostrar_pila();
        void gotoxy(int,int);
};

pila::pila(){
    tope=-1;
}

int validar (){
    char dato[10];
    int n;
    do{
    	cin>>dato;
    	n=atoi(dato);
    	if(n==0) cout<<"Error... Ingrese un dato valido: ";
	}while(n==0);
  return n;
}

void pila::push(){
    int x;
    if(llena()==0){
        cout<<"ingresa numero"<<endl;
        x= validar();
        //cin>>x;
        tope++;
        datos[tope]=x;
    }
}

void pila::pop(){
    if(vacia()==0){
        datos[tope]=0;
        tope--;
    }
}

void pila::mostrar_tope(){
    if(vacia()==0){
        system("cls");
        cout<<"el tope es: "<<datos[tope]<<endl;
        system("pause");
    }
}



void pila::mostrar_pila(){
    int ayuda, i;
    if(vacia()==0){
        system("cls");
        printf("\n\n\t\t%c%c%c%c%c   \n",201,205,205,205,187);
        for(i=tope ; i>=0 ; i--){
            printf("\t\t%c ",186,205);
            cout<<datos[i]; printf(" %c\n",186);
            printf("\t\t%c%c%c%c%c\n",204,205,205,205,185);
        }

    }
}

int pila::vacia(){
    if (tope==-1){
        system("cls");
        cout<<"la pila esta vacia"<<endl;
        system("pause");
        return 1;
    }else{
        return 0;
    }
}

int pila::llena(){
    if(tope==9){
        system("cls");
        cout<<"la pila esta llena"<<endl;
        system("pause");
        return 1;
    }else{
        return 0;
    }
}

/*void pila:: gotoxy(int x, int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon,dwPos);
}*/



int main(){
    pila p;
    int opcion, num;

    do{
        system("cls");
        p.mostrar_pila();
        cout<<"\n\n[1].ingresar numero\n[2].Eliminartope\n[3].Mostrar tope\n[4].Mostrar pila\n[5].SALIR"<<endl;
        cin>>opcion;
        switch(opcion){
            case 1:{
                p.push();
            }break;
            case 2:{
                p.pop();
            }break;
            case 3:{
                p.mostrar_tope();
            }break;
            case 4:{
                p.mostrar_pila();
            }break;
            case 5:{
                cout<<"usted saldra del programa"<<endl;
            }break;
            default:
                cout<<"Opcion incorrecta"<<endl;
                system("pause");
        }
    }while(opcion != 5);

}





