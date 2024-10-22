#include <cstdlib>
#include <string.h>
#include <iostream>

using namespace std;
template<class TIPO> class List;

template<class TIPO>
class Nodo {
    public:
        Nodo(string v, Nodo<TIPO> *pnext = NULL, Nodo<TIPO> *pprev = NULL) :
        value(v), ptrNext(pnext), ptrPrev(pprev){}
    private:
        string value;
        Nodo<TIPO> *ptrNext;
        Nodo<TIPO> *ptrPrev;
    friend class List<TIPO>;
};


template<class TIPO>
class List {
    public:
        List(): ptrList(NULL){}
        ~List();
        void Add(string v);
        bool Empty(){ return ptrList == NULL; }
        void print();
        void ptrNext();
        void ptrPrev();
        void First();
        void Last();
        void bubbleSort();
        void mayor();
        void deleteFirst();
        void deleteLast();
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
void List<TIPO>::Add(string v){
    Nodo<TIPO> *ptrNew;
    First();
    if(Empty() || ptrList->value > v){
        ptrNew = new Nodo<TIPO>(v, ptrList);
        if(!ptrList) ptrList = ptrNew;
        else ptrList->ptrPrev = ptrNew;
    }
    else{
        while(ptrList->ptrNext && ptrList->ptrNext->value <= v) ptrNext();
        ptrNew = new Nodo<TIPO>(v, ptrList->ptrNext, ptrList);
        ptrList->ptrNext = ptrNew;
        if(ptrNew->ptrNext) ptrNew->ptrPrev->ptrPrev = ptrNew;
    }
}

template<class TIPO>
void List<TIPO>::bubbleSort(){
    int swapped, i;
    Nodo<TIPO> *ptr1;
    Nodo<TIPO> *lptr = NULL;
    if(Empty()){
        return; }
    do{
        swapped = 0;
        ptr1 = ptrList;
        while (ptr1->ptrNext != lptr){
            if (ptr1->value > ptr1->ptrNext->value)
            {
                swap(ptr1->value, ptr1->ptrNext->value);
                swapped = 1;
            }
            ptr1 = ptr1->ptrNext;
        }
        lptr = ptr1;
    } while(swapped!=0);
}
//---------------------------------
template<class TIPO>
void List<TIPO>::mayor(){
    int aux=0, i;
    Nodo<TIPO> *ptr1;
    Nodo<TIPO> *lptr = NULL;
    ptr1 = ptrList;
    while (ptr1->ptrNext != lptr){
        if (ptr1->value > ptr1->ptrNext->value){
            aux = ptr1->value;
        }
        ptr1 = ptr1->ptrNext;
        }
        lptr = ptr1;

}

template<class TIPO>
void List<TIPO>::deleteFirst(){
    Nodo<TIPO> *ptrNodo;
    if (!ptrNodo){
        cout<<"la lista esta vacia"<<endl;
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
        cout<<"la lista esta vacia"<<endl;
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
    Nodo<TIPO> *ptrNode;
    First();
    ptrNode = ptrList;
    while(ptrNode){
        cout <<" "<<ptrNode->value;
        cout <<" ";
        ptrNode = ptrNode->ptrNext;
    }
    cout << endl;
}

template<class TIPO>
void List<TIPO>::ptrNext(){
    if(ptrList!=NULL){
        ptrList=ptrList->ptrNext;
        ptrauxiliar=ptrList;
    }
}

template<class TIPO>
void List<TIPO>::ptrPrev() {
    if(ptrList){
        ptrList = ptrList->ptrPrev;
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
    cout<<ptrList->value;
}


int main(){
    List<int> list;
    int opc=0,cont=0,aux,aux1,aux3;
    string v;
    do{
        system("cls");
        list.print();

        cout<<"1-.Agregar un numero a la lista\n";
        cout<<"2-.Nodo con mayor valor\n";
        cout<<"3-.Ordenar\n";
        cout<<"4-.Borrar primer nodo\n";
        cout<<"5-.Borrar ultimo nodo \n";
        cout<<"6-.Borrar nodo con mayor valor\n";
        cout<<"0-.Salir..\n";
        cout<<"Seleccione un opcion\n";
        cin>>opc;
        switch (opc){
            case 1:{
                cout<<"Ingrese un numero"<<endl;
                cin>>v;
                list.Add(v);
                system("cls");
                break;
            }
            case 2:{
                list.Last();
                cout<<" "<<endl;
                system("pause");
                break;
            }
            case 3:{
                list.bubbleSort();
                system("cls");
                break;
            }
            case 4:{
                list.deleteFirst();
                system("cls");
                break;
            }
            case 5:{
                list.deleteLast();
                system("cls");
                break;
            }
            case 6:{
                list.deleteLast();
                system("cls");
                break;
            }
        }
    }while(opc!=0);
    return 1;
}
