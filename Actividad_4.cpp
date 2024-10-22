#include <cstdlib>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>

using namespace std;

 void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }

 void TextColor(int color){
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

template<class TIPO> class List;
int posicion=0,posicion2=1;
template<class TIPO>
class Nodo {
    public:
        Nodo(string v,string c,string a,string t,TIPO id, Nodo<TIPO> *pnext = NULL, Nodo<TIPO> *pprev = NULL) :
        value(v),cantante(c),album(a),tipo(t),id(id), ptrNext(pnext), ptrPrev(pprev){}
    private:
        string value;
        string cantante;
        string album;
        string tipo;
        TIPO id;
        Nodo<TIPO> *ptrNext;
        Nodo<TIPO> *ptrPrev;
    friend class List<TIPO>;
};

template<class TIPO>
class List {
    public:
        List(): ptrList(NULL){}
        ~List();
        void Add(string v,string c,string a,string t,TIPO id);
        void remove(TIPO v);
        bool Empty(){ return ptrList == NULL; }
        void print();
        void ptrNext();
        void ptrPrev();
        void First();
        void Last();
        void ascendente();
        void deleteFirst();
        void deleteLast();
        void descendente();
        void Modificar(int pos);
        void print2(int pos);
        void Adelante(int pos);
        void Atras(int pos);
        bool Current(){return ptrList != NULL;}
        TIPO CurrentValue(){return ptrList->id;}
        TIPO CurrentValue1(){return ptrauxiliar->id;}
    private:
        Nodo<TIPO> *ptrList;
        Nodo<TIPO> *ptrauxiliar;
};

template<class TIPO>
List<TIPO>::~List(){
    Nodo<TIPO> *aux;
    First();
    while(ptrList){
        aux = ptrList;
        ptrList = ptrList->ptrNext;
        delete aux;
    }
}

template<class TIPO>
void List<TIPO>::Add(string v,string c,string a,string t,TIPO id){
    Nodo<TIPO> *ptrNew;
    First();
    if(Empty() || ptrList->id > id){
        ptrNew = new Nodo<TIPO>(v,c,a,t,id, ptrList);
        if(!ptrList) ptrList = ptrNew;
        else ptrList->ptrPrev = ptrNew;
    }
    else{
        while(ptrList->ptrNext && ptrList->ptrNext->id <= id) ptrNext();
        ptrNew = new Nodo<TIPO>(v,c,a,t,id, ptrList->ptrNext, ptrList);
        ptrList->ptrNext = ptrNew;
        if(ptrNew->ptrNext) ptrNew->ptrPrev->ptrPrev = ptrNew;
    }
}

template<class TIPO>
void List<TIPO>::ascendente(){
    int swapped, i;
    Nodo<TIPO> *ptr1;
    Nodo<TIPO> *lptr = NULL;
    if(Empty()){
        return; }
    do{
        swapped = 0;
        ptr1 = ptrList;
        while (ptr1->ptrNext != lptr){
            if (ptr1->id > ptr1->ptrNext->id)
            {
                swap(ptr1->id, ptr1->ptrNext->id);
                swap(ptr1->value, ptr1->ptrNext->value);
                swap(ptr1->album, ptr1->ptrNext->album);
                swap(ptr1->cantante, ptr1->ptrNext->cantante);
                swap(ptr1->tipo, ptr1->ptrNext->tipo);
                swapped = 1;
            }
            ptr1 = ptr1->ptrNext;
        }
        lptr = ptr1;
    } while(swapped!=0);
}

template<class TIPO>
void List<TIPO>::descendente(){
    Nodo<TIPO> *temp = NULL;
    Nodo<TIPO> *current = ptrList;
    while (current != NULL)
    {
        temp = current->ptrPrev;
        current->ptrPrev = current->ptrNext;
        current->ptrNext = temp;
        current = current->ptrPrev;
    }
    if(temp != NULL )
        ptrList = temp->ptrPrev;
}

template<class TIPO>
void List<TIPO>::remove(TIPO id){
    Nodo<TIPO> *ptrNode;// nodo temporal
    ptrNode = ptrList;// el nodo temporal es igual a los nodos actuales
    while(ptrNode && ptrNode->id < id) ptrNode = ptrNode->ptrNext; // buscamos los nodos hacia adelante
    while(ptrNode && ptrNode->id > id) ptrNode = ptrNode->ptrPrev;// buscamos los nodos hacia atras
    if(!ptrNode || ptrNode->id != id)  return;// si no existe el nodo retornamos
    if(ptrNode->ptrPrev) // no es el primer elemento
    ptrNode->ptrPrev->ptrNext = ptrNode->ptrNext;
    if(ptrNode->ptrNext) // no el �ltimo Nodo
    ptrNode->ptrNext->ptrPrev = ptrNode->ptrPrev;
}

template<class TIPO>
void List<TIPO>::deleteFirst(){
    Nodo<TIPO> *ptrNodo;
    if (!ptrNodo){
        gotoxy(1,20);cout<<"la lista esta vacia"<<endl;
        return;
    }else{
        ptrNodo=ptrList;
        ptrList= ptrList->ptrNext;
        ptrList->ptrPrev=NULL;
        free(ptrNodo);
    }
}

template<class TIPO>
void List<TIPO>::deleteLast(){
    Nodo<TIPO> *nodetodel;
    if(ptrList==NULL){
        gotoxy(1,20);cout<<"la lista esta vacia"<<endl;
        return;
    }else{
        Last();
        nodetodel=ptrList;
        ptrList=ptrList->ptrPrev;
        ptrList->ptrNext=NULL;
        free(nodetodel);
    }
}

template<class TIPO>
void List<TIPO>::print(){
    int cont=1;
    Nodo<TIPO> *ptrNode;
    First();
    ptrNode = ptrList;
    while(ptrNode){
        TextColor(4);
        gotoxy(1,cont);cout <<"id: "<<ptrNode->id;
        TextColor(6);
        gotoxy(20,cont);cout <<ptrNode->value;
        TextColor(3);
        gotoxy(40,cont);cout <<ptrNode->cantante;
        TextColor(2);
        gotoxy(60,cont);cout <<ptrNode->album;
        TextColor(5);
        gotoxy(80,cont);cout <<ptrNode->tipo<<endl;
        ptrNode = ptrNode->ptrNext;
        cont++;
    }
    cout << endl;
    TextColor(15);
}

template<class TIPO>
void List<TIPO>::ptrNext(){
    if(ptrList!=NULL){
        ptrList=ptrList->ptrNext;
        ptrauxiliar=ptrList;
    }
}

template<class TIPO>
void List<TIPO>::Adelante(int pos){
    ptrauxiliar=ptrList;
    if(ptrList==NULL){
            gotoxy(1,20);cout<<"No hay nada"<<endl;
            return;
    }else{
        Nodo<TIPO>* aux1=ptrList;
        for(int i=1;i<pos;i++){
            aux1=aux1->ptrNext;
        }
    ptrauxiliar=aux1;
    }
}

template<class TIPO>
void List<TIPO>::ptrPrev() {
    if(ptrList){
        ptrList = ptrList->ptrPrev;
    }
}

template<class TIPO>
void List<TIPO>::Atras(int pos){
    if(ptrList==NULL){
            gotoxy(1,20);cout<<"No hay nada"<<endl;
            return;
    }else{
        Nodo<TIPO>* aux2=ptrList;
        for(int i=1;i<pos;i++){
            aux2=aux2->ptrPrev;
        }
    ptrauxiliar=aux2;
    }
}

template<class TIPO>
void List<TIPO>::First(){
    while(ptrList && ptrList->ptrPrev){
        ptrList = ptrList->ptrPrev;
    }
}

template<class TIPO>
void List<TIPO>::Last(){
    while(ptrList && ptrList->ptrNext){
        ptrList = ptrList->ptrNext;
    }
}

template<class TIPO>
void List<TIPO>::print2(int pos){
    Nodo<TIPO>* aux3=ptrList;

    for(int i=1;i<pos;i++){
        aux3=aux3->ptrNext;
    }

    gotoxy(2,16);cout <<"  Cancion:"<<aux3->value;
    gotoxy(2,18);cout <<"  Cantante: "<<aux3->cantante;
    gotoxy(50,16);cout <<"  Album:"<<aux3->album;
    gotoxy(50,18);cout <<"  tipo:"<<aux3->tipo;
        TextColor(31);
        gotoxy(2,pos);cout <<"id: "<<aux3->id<<"                          ";
        gotoxy(20,pos);cout <<aux3->value<<"                          ";
        gotoxy(40,pos);cout <<aux3->cantante<<"                          ";
        gotoxy(60,pos);cout <<aux3->album<<"                          ";
        gotoxy(80,pos);cout <<aux3->tipo<<"                          ";
}

template<class TIPO>
void List<TIPO>::Modificar(int pos){
    if(ptrList==NULL){
        gotoxy(1,20);cout<<"La agenda esta vacia\n";
    }
    else{
            char opc;
            int n;
            string cad;
            Nodo<TIPO>* aux1=ptrList;
            for(int i=0;i<pos;i++){
                aux1=aux1->ptrNext;
            }
            do{
            gotoxy(1,20);cout<<"1-.Cambiar Nombre\n";
            gotoxy(1,21);cout<<"2-.Cambiar Cantante\n";
            gotoxy(1,22);cout<<"3-.Cambiar Album\n";
            gotoxy(1,23);cout<<"4-.Cambiar Tipo\n";
            gotoxy(1,24);cout<<"0-.Regresar al menu\n";
            cin.sync();
            gotoxy(1,26);cin>>opc;
            switch(opc){
                case '1':{
                    getline(cin,cad);
                    gotoxy(1,27);cout<<"Ingresa el nuevo nombre\n";
                    getline(cin,cad);
                    aux1->value=cad;
                break;
                }
                case '2':{
                    getline(cin,cad);
                    gotoxy(1,26);cout<<"Ingresa el nuevo cantante\n";
                    getline(cin,cad);
                    aux1->cantante=cad;
                break;
                }
                case '3':{
                    getline(cin,cad);
                    gotoxy(1,26);cout<<"Ingresa el nuevo album\n";
                    getline(cin,cad);
                    aux1->album=cad;
                break;
                }
                case '4':{
                    getline(cin,cad);
                    gotoxy(1,27);cout<<"Ingresa el nuevo tipo\n";
                    getline(cin,cad);
                    aux1->tipo=cad;
                break;
                }
               }
               system("cls");
            }while(opc!='0');
    }
}

int main(){
    List<int> list;
    int opc=0,cont=0,aux,aux1,aux3;
    string n,c,a,t;
    do{
        system("cls");
        list.print();
        for(int j=0;j<15;j++){
            gotoxy(1,j);cout <<"|";
            gotoxy(19,j);cout <<"|";
            gotoxy(39,j);cout <<"|";
            gotoxy(59,j);cout <<"|";
            gotoxy(79,j);cout <<"|";
        }
        gotoxy(1,15);cout<<"_______________________________________________________________________________________";
        gotoxy(1,17);cout<<"_______________________________________________________________________________________";
        gotoxy(1,19);cout<<"_______________________________________________________________________________________";
        gotoxy(1,16);cout<<"|";gotoxy(1,18);cout<<"|";gotoxy(87,16);cout<<"|";gotoxy(87,18);cout<<"|";
        gotoxy(2,0);cout<<"ID";
        gotoxy(20,0);cout<<"CANCION";
        gotoxy(40,0);cout<<"CANTANTE";
        gotoxy(60,0);cout<<"ALBUM";
        gotoxy(80,0);cout<<"TIPO";

        if(cont>=1){
        list.print2(posicion2);}
        TextColor(240);
        gotoxy(95,0);cout<<"                         \n";
        gotoxy(95,1);cout<<" 1-.Nueva cancion.       \n";
        gotoxy(95,2);cout<<" 2-.Adelante.            \n";
        gotoxy(95,3);cout<<" 3-.Atras.               \n";
        gotoxy(95,4);cout<<" 4-.Borrar.              \n";
        gotoxy(95,5);cout<<" 5-.Orden ascendente.    \n";
        gotoxy(95,6);cout<<" 6-.Orden descendente.   \n";
        gotoxy(95,7);cout<<" 7-.Editar registro.     \n";
        gotoxy(95,8);cout<<" 8-.Borrar la primera.   \n";
        gotoxy(95,9);cout<<" 9-.Borrar la ultima.    \n";
        gotoxy(95,10);cout<<" 0-.Salir..              \n";
        gotoxy(95,11);cout<<" Seleccione un opcion    \n";
        TextColor(15);
        gotoxy(95,12);cin>>opc;
        switch (opc){
            case 1:{
                cont++;
                gotoxy(1,20);cout<<"Nombre de la cancion"<<endl;
                gotoxy(1,21);cin>>n;
                gotoxy(1,22);cout<<"cantante:"<<endl;
                gotoxy(1,23);cin>>c;
                gotoxy(1,24);cout<<"Album:"<<endl;
                gotoxy(1,25);cin>>a;
                gotoxy(1,26);cout<<"Tipo:"<<endl;
                gotoxy(1,27);cin>>t;
                list.Add(n,c,a,t,cont);
                cout <<"Agregado correctamente"<<endl;
                system("pause>>cls");
                break;
            }
            case 2:{
                posicion++;posicion2++;
                list.Adelante(posicion);
                system("cls");
                break;
            }
            case 3:{
                posicion--;posicion2--;
                list.Atras(posicion);
                system("cls");
                break;
            }
            case 4:{
                gotoxy(1,20);cout<<"ingrese el id que desea borrar"<<endl;
                gotoxy(1,21);cin>>aux;
                gotoxy(1,22);cout << "remover Node:"<<aux<<endl;
                list.remove(aux);
                system("cls");
                break;
            }
            case 5:{
                list.ascendente();
                system("cls");
                break;
            }
            case 6:{
                list.descendente();
                system("cls");
                break;
            }
            case 7:{
                aux1=list.CurrentValue1();
                list.Modificar(aux1);
                system("cls");
                break;
            }
            case 8:{
                list.deleteFirst();
                system("cls");
                break;
            }
            case 9:{
                list.deleteLast();
                system("cls");
                break;
            }
            case 0:{
                system("cls");
                cout <<"FIN DEL PROGRAMA"<<endl;
                system("pause>>cls");
                break;
            }
            default:{
                gotoxy(1,20);cout<<"Error... Dato invalido"<<endl;
                system("pause");
            }
        }
    }while(opc!=0);
    return 1;
}
