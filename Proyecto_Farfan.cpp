#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <ctime>
#include <stdio.h>
#include <string.h>
using namespace std;

class Nodo{
    public:
        int id;
        string nombre;
        char destino[15];
        Nodo* next;
};
int cabe=0;

class Nodo2{
    public:
        string nombre;
        Nodo2* next;
};

void display(Nodo2 *&pila, int numc){
    Nodo2 *temp2;
    temp2 = pila;
    cout << "\n";
    while(temp2!=NULL){
        if(temp2==pila){
            cout<<temp2->nombre;
            cout << "\n";
            temp2=temp2->next;
        }else{
            cout<<temp2->nombre;
            cout << "\n";
            temp2=temp2->next;
        }
    }
    system("pause");
    system("cls");
}

void pila_(Nodo2 *&pila, Nodo *&frente, int numC){
    Nodo *temp;
    temp = frente;
    for(int i=1 ; i<=numC ; i++){
        Nodo2 *temp2 = new Nodo2();
        temp2->nombre = temp->nombre;
        temp2->next = pila;
        pila = temp2;
        temp = temp->next;
    }
};

 void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }

void menu();
int validar();
void cabezera();

bool cola_vacia(Nodo *frente){
    return (frente==NULL)? true : false;
};


void registrar(Nodo *&frente, Nodo *&fin, int numC){
    cabezera();
    char nom[10];
    Nodo2 *pila = NULL;
    int n=1;
    for(int i=0 ; i<numC ; i++){
        for(int i=0 ;i<=119 ; i++){
        printf("%c",205);
        }
        cout<<"\n";
        Nodo *nuevo_nodo = new Nodo();
        nuevo_nodo->id=n;
        cout<<"ID de pasajero:"<<nuevo_nodo->id<<endl;
        cout<<"Ingrese el nombre del pasajero: ";
        cin>>nuevo_nodo->nombre;
        cout<<"Ingrese el destino: ";
        cin>>nuevo_nodo->destino;
        nuevo_nodo->next=NULL;
        if(cola_vacia(frente)){
            frente = nuevo_nodo;
        }else{
            fin->next = nuevo_nodo;
        }
        fin = nuevo_nodo;
        n++;

    }
    for(int i=0 ;i<=119 ; i++){
        printf("%c",205);
        }
    system("pause");
    system("cls");
};

int compra_ticket(Nodo *&frente){
    Nodo *temp;
    temp = frente;
    int cont=1;
    cabezera();
    for(int i=0 ;i<=119 ; i++){
        printf("%c",205);
    }
    while(temp != NULL){
        cout<<"Asiento no["<<cont<<"]-> "<<temp->nombre<<endl;
        temp = temp->next;
        for(int i=0 ;i<=119 ; i++){
            printf("%c",205);
        }
        cont++;
        Sleep(500);
    }
    system("pause");
    system("cls");
}

int bajada(Nodo *&frente){
    Nodo *temp;
    temp = frente;
    int cont=1;
    cabezera();
    cout<<"Orden de pasajeros en bajar"<<endl;
    for(int i=0 ;i<=119 ; i++){
        printf("%c",205);
    }
    while(temp != NULL){
        cout<<cont<<"->"<<temp->nombre<<endl;
        temp = temp->next;
        for(int i=0 ;i<=119 ; i++){
            printf("%c",205);
        }
        cont++;
        Sleep(500);
    }
    system("pause");
    system("cls");
}

void animacion1(int numC){
    int pos=90, ban=0;
    cabezera();
    gotoxy(90,11);cout<<"MANTENGA SU SANA DISTANCIA"<<endl;
    gotoxy(100,12);cout<<"   _____"<<endl;
    gotoxy(100,13);cout<<" /  o  |"<<endl;
    gotoxy(100,14);cout<<" |__|__|"<<endl;
    gotoxy(100,15);cout<<" |_____|"<<endl;
    for(int i=0 ; i<numC ; i++){
        for(int i=0;i<pos;i++){
             gotoxy(i,13);cout<< "  o";
            gotoxy(i,14); cout<< " /| \\";
            if(ban==0){
                    gotoxy(i,15); cout<< " / ";
                ban=1;
            }else{
                gotoxy(i,15); cout<< "   \\";
                ban=0;
            }
             Sleep(50);
        }
        pos=pos-10;
    }
    cout<<"\n\n"<<endl;
    system("pause");
    system("cls");
}

void animacion2(Nodo *&frente, int numC){
    int pos=90, ban=0, x=0;
    Nodo *temp;
    temp = frente;
    cabezera();
    gotoxy(90,11);cout<<"MANTENGA SU SANA DISTANCIA"<<endl;
    gotoxy(100,12);cout<<"   _____"<<endl;
    gotoxy(100,13);cout<<" /  o  |"<<endl;
    gotoxy(100,14);cout<<" |__|__|____________"<<endl;
    gotoxy(100,15);cout<<" |_____|_|_|_|_|_|_|"<<endl;
    for(int i=0 ; i<numC ; i++){
        srand(time(NULL));
        x=rand()%5+1;
        gotoxy(10,7);cout<<"El pasajero "<<temp->nombre<<" lleva: "<<x<<" maletas"<<endl;
        for(int i=0;i<pos;i++){
             gotoxy(i,13);cout<< "  o";
            gotoxy(i,14);printf(" /| \\%c%c",201,187);
            if(ban==0){
                    gotoxy(i,15); printf(" /   %c%c",200,188);
                ban=1;
            }else{
                gotoxy(i,15);printf("   \\ %c%c",200,188);
                ban=0;
            }
             Sleep(50);
        }
        temp=temp->next;
        pos=pos-10;
        gotoxy(10,7);cout<<"                                                             "<<endl;
    }
    cout<<"\n\n"<<endl;
    system("pause");
    system("cls");
}

void animacion3(){
    gotoxy(50,15);cout<<"   Avion_mamalonx.jpg "<<endl;
    for(int i=85;i>0;i--){
        gotoxy(i,9);cout<< "  OOOOOOOOOOOO                                 ";
        gotoxy(i,10);cout<< " OO          OO                               ";
        gotoxy(i,11);cout<< " OO          OO                               ";
        gotoxy(i,12);cout<< "  OOOOOOOOOOOO                                ";
        Sleep(30);
        gotoxy(i-40,20);cout<< "  OOOOOOOOOOOO                                    ";
        gotoxy(i-40,21);cout<< " OO          OO                                   ";
        gotoxy(i-40,22);cout<< " OO          OO                                   ";
        gotoxy(i-40,23);cout<< "  OOOOOOOOOOOO                                    ";
        Sleep(30);
    }
    system("cls");
}
void animacion4(Nodo2 *&pila, int numC){
    int pos=90, ban=0, cont=1;
    cabezera();
    Nodo2 *temp2;
    temp2 = pila;
    while(temp2!=NULL){
        if(temp2==pila){
            cout<<cont<<" en tomar el taxi-> "<<temp2->nombre<<endl;
            temp2=temp2->next;
        }else{
            cout<<cont<<" en tomar el taxi-> "<<temp2->nombre<<endl;
            temp2=temp2->next;
        }
        cont++;
    }
    gotoxy(90,11);cout<<"MANTENGA SU SANA DISTANCIA"<<endl;
    gotoxy(100,12);cout<<"     ______"<<endl;
    gotoxy(100,13);cout<<"  __/  |o  |__"<<endl;
    gotoxy(100,14);cout<<" |____taxi____|"<<endl;
    gotoxy(100,15);cout<<" o           o"<<endl;
    for(int i=0 ; i<numC ; i++){
        for(int i=0;i<pos;i++){
             gotoxy(i,13);cout<< "  o";
            gotoxy(i,14); cout<< " /| \\";
            if(ban==0){
                    gotoxy(i,15); cout<< " / ";
                ban=1;
            }else{
                gotoxy(i,15); cout<< "   \\";
                ban=0;
            }
             Sleep(50);
        }
        pos=pos-10;
    }
    cout<<"\n\n"<<endl;
    system("pause");
    system("cls");
}

int main(){
    int opc=0, numC=0;
    Nodo *frente = NULL;
    Nodo *fin = NULL;
    Nodo2 *pila = NULL;

    do{
        menu();
        cout<<"\t\t\t1.-INICIAR VIAJE.                             2.-FIN DEL PROGRAMA"<<endl;
        cout<<"Ingrese una opcion valida:";
        opc = validar();
        switch(opc){
            case 1:{
                cout<<"Ingrese el numero de pasajeros:";
                cin>>numC;
                registrar(frente, fin, numC);
                compra_ticket(frente);
                animacion1(numC);
                animacion2(frente, numC);
                animacion3();
                pila_(pila, frente, numC);
                bajada(frente);
                animacion4(pila,numC);
            }break;
            case 2: system("cls");cout<<"FIN DEL PROGRAMA"<<endl;break;
            default: cout<<"ERROR... Dato invalido."<<endl;system("pause");system("cls");break;
        }
    }while(opc!=2);
    return 0;
}

void menu(){
    cabe=0;
    printf("\n\n\t%c",201);
    for(int i=0 ;i<=100 ; i++){
        printf("%c",205);
    }
    printf("%c\n",187);
    printf("\t%c                                                                                                     %c\n",186,186);
    printf("\t%c              _   _  _   _      ___       _   _   __       _   _   _   _  _                          %c\n",186,186);
    printf("\t%c             |_| |_ |_| | | |    |  |%c | |_  |_| |__      |_  |_| |_| |_ |_| |%c |                    %c\n",186,92,92,186);
    printf("\t%c             | | |_ | %c |_| |_  _|_ | %c| |_  | |  __|     |   | | | %c |  | | | %c|                    %c\n",186,92,92,92,92,186);
    printf("\t%c                                                                                                     %c\n",186,186);
    printf("\t%c                           DONDE SI NO LLEGAS VIVO, LLEGAS MUERTO                                    %c\n",186,186);
    printf("\t%c                                                                                                     %c\n",186,186);
    printf("\t%c                          By:Farfan de Leon Jose Osvaldo                                             %c\n",186,186);
    printf("\t%c                          Codigo:214796622                                                           %c\n",186,186);
    printf("\t%c                                                                                                     %c\n",186,186);
    printf("\t%c",200);
    for(int i=0 ;i<=100 ; i++){
        printf("%c",205);
    }
    printf("%c\n",188);
}

int validar(){
    char dato[10];
    int n;
    do{
    	cin>>dato;
    	n=atoi(dato);
    	if(n==0) {
                cout<<"Error... Ingrese un dato valido: ";
    	}
	}while(n==0);
  return n;
}

void cabezera(){

    system("cls");
    printf("\n\n\t%c",201);
    for(int i=0 ;i<=100 ; i++){
        printf("%c",205);
    }
    printf("%c\n",187);
    printf("\t%c                                                                                                     %c\n",186,186);
    cabe++;
    switch(cabe){
        case 1:{
            printf("\t%c                                     Registro de pasajeros                                           %c\n",186,186);
            printf("\t%c                               El ID se asinga en base al sistema :v                                 %c\n",186,186);
        }break;
        case 2:{
            printf("\t%c                                       COMPRA DE TICKET                                              %c\n",186,186);
            printf("\t%c                                                                                                     %c\n",186,186);
        }break;
        case 3:{
            printf("\t%c                                       COMPRA DE TICKET                                              %c\n",186,186);
            printf("\t%c                                                                                                     %c\n",186,186);
        }break;
        case 4:{
            printf("\t%c                                      Revision de maleta                                             %c\n",186,186);
            printf("\t%c                                                                                                     %c\n",186,186);
        }break;
        case 5:{
            printf("\t%c                                       Bajada del avion                                              %c\n",186,186);
            printf("\t%c                                                                                                     %c\n",186,186);
        }break;
        case 6:{
            printf("\t%c                                          Tomar taxi                                                 %c\n",186,186);
            printf("\t%c                                                                                                     %c\n",186,186);
        }break;
    }
    printf("\t%c",200);
    for(int i=0 ;i<=100 ; i++){
        printf("%c",205);
    }
    printf("%c\n",188);
}
