/*Farfan de Leon Jose Osvaldo
  Codigo: 214796622
-----------------------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <stdlib.h>
using namespace std;

class CircularList{
    private:
        class Node {
    public:
        int number;
        Node *next;
        Node *back;
};
        Node *ptrHead;
    public:
        CircularList();
        ~CircularList();
        void insert_First(int);
        void insert_Last(int);
        bool empty();
        void print();
        int travel();
        void remove(int);
        void buscar(int);
        void modificar(int, int);
};

CircularList::CircularList(){
    ptrHead = NULL;
}

CircularList::~CircularList() {
    if (ptrHead != NULL) {
        Node *temp = ptrHead
        ->next;
        Node *temp_ptrHead;
        while (temp != ptrHead){
            temp_ptrHead = temp;
            temp = temp
            ->next;
            delete temp_ptrHead;
        }
        delete ptrHead;
    }
}

void CircularList::insert_First(int number) {
    Node *new_node = new Node();
    new_node->number = number;
    if (ptrHead == NULL){
        new_node->next = new_node;
        new_node->back = new_node;
        ptrHead = new_node;
    }else{
        Node *last_node = ptrHead->back;
        new_node->next = ptrHead;
        new_node->back = last_node;
        ptrHead->back = new_node;
        last_node->next = new_node;
        ptrHead = new_node;
    }
}

void CircularList::insert_Last(int number) {
    Node *new_node = new Node();
    new_node->number = number;
    if (ptrHead == NULL){
        new_node->next = new_node;
        new_node->back = new_node;
        ptrHead = new_node;
    }else{
        Node *last_node = ptrHead->back;
        new_node->next = ptrHead;
        new_node->back = last_node;
        ptrHead->back = new_node;
        last_node->next = new_node;
    }
}

bool CircularList::empty() {
    if (ptrHead == NULL)
        return true;
    else
        return false;
}

void CircularList::print() {
    if (!empty()) {
        Node *temp = ptrHead;
        do {
            cout<<temp->number <<"-";
            temp = temp->next;
        } while (temp != ptrHead);
        cout << "\n";
    }
}

int CircularList::travel() {
    int count = 0;
    if (!empty()){
        Node *temp = ptrHead;
        do {
            count++;
            temp = temp->next;
        } while (temp != ptrHead);
    }
    return count;
}

void CircularList::remove(int position) {
    if (position <= travel()){
        if (position == 1){
            if (travel() == 1){
                delete ptrHead;
                ptrHead = NULL;
            }else{
                Node *temp_ptrHead = ptrHead;
                Node *last_node = ptrHead->back;
                ptrHead = ptrHead->next;
                last_node->next = ptrHead;
                ptrHead->back = last_node;
                delete temp_ptrHead;
            }
        }else {
            Node *temp = ptrHead;
            for (int f=1 ; f <= position- 1; f++)
                temp = temp->next;
            Node *temp_ptrHead = temp;
            Node *back = temp->back;
            temp = temp->next;
            back->next = temp;
            temp->back = back;
            delete temp_ptrHead;
        }
    }
}

void CircularList::buscar(int position) {
    if(position <= travel()){
        if(position == 1){
            cout<<ptrHead->number<<endl;
        }else{
            Node *temp = ptrHead;
            for(int f=1 ; f<=position-1 ; f++)
                temp = temp->next;
            cout<<"El valor de esa posicion es: "<<temp->number<<endl;
        }
    }
}
//---------------------------------------------------

void CircularList::modificar(int numero, int position) {
    if(position <= travel()){
        if(position == 1){
            ptrHead->number= numero;
        }else{
            Node *temp = ptrHead;
            for(int f=1 ; f<=position-1 ; f++)
                temp = temp->next;
            temp->number = numero;
        }
    }
}

//---------------------------
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

int main(int argc, char** argv) {
    int opc=0, num=0, pos=0;
    CircularList *obj = new CircularList();
    do{
    system("cls");
    //obj->print();
    cout<<"\n\nMenu"<<endl;
    cout<<"1.-Insertar al principio"<<endl;
    cout<<"2.-Insertar al final"<<endl;
    cout<<"3.-Buscar por posicion"<<endl;
    cout<<"4.-Modificar"<<endl;//---------------
    cout<<"5.-Remover"<<endl;
    cout<<"6.-Listar/imprimir"<<endl;
    cout<<"7.SALIR"<<endl;
    opc=validar();
    switch(opc){
        case 1:{
            cout<<"Ingrese el numero que desea agregar al inicio de la lista: ";
            num=validar();
            obj->insert_First(num);
            break;
        }
        case 2:
            cout<<"Ingrese el numero que desea agregar al final de la lista: ";
            num=validar();
            obj->insert_Last(num);
            break;
        case 3:
            cout<<"Ingrese la posicion a buscar"<<endl;
            pos=validar();
            obj->buscar(pos);
            system("pause");
            break;
        case 4:
            cout<<"Ingrese la posicion a modificar: ";
            pos=validar();
            cout<<"Ingrese el nuevo valor: "<<endl;
            num=validar();
            obj->modificar(num, pos);
            break;
        case 5:
            cout<<"Ingrese la posicion a remover: ";
            pos=validar();
            obj->remove(pos);
            break;
        case 6:obj->print();system("pause");break;
        case 7:
            system("cls");
            cout<<"FIN DEL PROGRAMA"<<endl;
            break;
        default :{
            system("cls");
            cout<<"Error... Dato invalido"<<endl;
            system("pause");
        }
    }

    }while(opc!=7);

    delete obj;
    return 0;
}


