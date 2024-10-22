/*Farfan de Leon Jose Osvaldo
  codigo: 214796622
  Seccion:"D07"
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
using namespace std;


template<class TIPO> class List; //declaramos la lista

template<class TIPO>
class Nodo {
    public:
        Nodo(TIPO v, Nodo<TIPO> *pnext = NULL, Nodo<TIPO> *pprev = NULL) :
        value(v), ptrNext(pnext), ptrPrev(pprev) {}
        // constructor de nodo, guarda el objeto indicado y si no se indica nada entonces no hay sig ni anterior
    private:
        TIPO value; // typename.
        Nodo<TIPO> *ptrNext; // inicializamos nuestros nodos vacios
        Nodo<TIPO> *ptrPrev;
    friend class List<TIPO>; // funcion amiga que permite sobrecargar la lista
};

template<class TIPO>
class List { // objeto lista
    public:
        List() : ptrList(NULL) {} // puntero vacio.
        ~List(); // destructor
        void Add(TIPO v); // agregar nuevo objeto a la lista
        void remove(TIPO v); // remover objeto de la lista
        bool Empty() { return ptrList == NULL; } // vaciar nodo
        void print(); // mostrar lista
        void ptrNext(); // nodo siguiente
        void ptrPrev(); // nodo anterior
        void First(); // primer nodo
        void Last(); // ultimo nodo
        bool Current() { return ptrList != NULL; } // nodo  actual
        TIPO CurrentValue() { return ptrList->value; } // retornar el valor del nodo
    private:
        Nodo<TIPO> *ptrList; // puntero de la lista
};

template<class TIPO>
List<TIPO>::~List(){ // Destructor de lca clase
    Nodo<TIPO> *aux; // nodo temporal
    First(); // llamamos el primer nodo
    while(ptrList) {  // eliminamos todos los nodos con este while.
        aux = ptrList;
        ptrList = ptrList->ptrNext;
        delete aux;
    }
}

template<class TIPO>
void List<TIPO>::Add(TIPO v){ // Agregar al Nodo
    Nodo<TIPO> *ptrNew; // nodo temporal
    First(); // Posicionamos la lista en el primer nodo
    if(Empty() || ptrList->value > v) { // Si es el primer nodo o el primer nodo de la lista es igual entonces.
        ptrNew = new Nodo<TIPO>(v, ptrList); // asignamos valor al nodo temporal con nuestro nodo actual
        if(!ptrList) ptrList = ptrNew; // si esta vacio entonces lo sustituimos
        else ptrList->ptrPrev = ptrNew; // si no esta vacio entonces el nodo anterior se sustituye por el nuevo
    }
    else{ // si el primer nodo no esta vacio o el primero de la lista no es igual
        while(ptrList->ptrNext && ptrList->ptrNext->value <= v) ptrNext();  // recorremos todos los nodos para dejar libre el actual
        ptrNew = new Nodo<TIPO>(v, ptrList->ptrNext, ptrList); // creamos un nodo con los valores actuales
        ptrList->ptrNext = ptrNew; // sustituimos el siguiente nodo por el nuevo
        if(ptrNew->ptrNext) ptrNew->ptrPrev->ptrPrev = ptrNew; // si nuestro nodo siguiente existe entonces los 2 anteriores (prob head) es igual al nuevo nodo
    }
}

template<class TIPO>
void List<TIPO>::remove(TIPO v){ // quitar nodo
    Nodo<TIPO> *ptrNode; // nodo temporal
    ptrNode = ptrList; // el nodo temporal es igual a los nodos actuales
    while(ptrNode && ptrNode->value < v) ptrNode = ptrNode->ptrNext; // buscamos los nodos hacia adelante
    while(ptrNode && ptrNode->value > v) ptrNode = ptrNode->ptrPrev; // buscamos los nodos hacia atras
    if(!ptrNode || ptrNode->value != v) return; // si no existe el nodo retornamos
    if(ptrNode->ptrPrev) // si existe el sig nodo previo lo sistuimos por el anterior al actual, saltandolo
        ptrNode->ptrPrev->ptrNext = ptrNode->ptrNext;
    if(ptrNode->ptrNext) // si existe el nodo siguiente entonces sustituimos el siguiente por el actual
        ptrNode->ptrNext->ptrPrev = ptrNode->ptrPrev;
    delete ptrNode;
}

template<class TIPO>
void List<TIPO>::print(){
    Nodo<TIPO> *ptrNode; // nodo temporal
    First(); // nos movemos al primer nodo
    ptrNode = ptrList; // nodo temporal es igual al nodo actual
    while(ptrNode) { // nos movemos en el nodo temporal
        cout << ptrNode->value << "-> "; // mostramos el valor
        ptrNode = ptrNode->ptrNext; // nos movemos al siguiente nodo
    }
    cout << endl;
}

template<class TIPO>
void List<TIPO>::ptrNext() { // mover al siguiente nodo
    if(ptrList) {
        ptrList = ptrList->ptrNext; // movemos el siguiente nodo al actual
    }
}

template<class TIPO>
void List<TIPO>::ptrPrev() { // mover al nodo anterior
    if(ptrList) {
        ptrList = ptrList->ptrPrev; // movemos el anterior nodo al actual
    }
}

template<class TIPO>
void List<TIPO>::First(){ // mover lista al primer nodo
    while(ptrList && ptrList->ptrPrev) {
        ptrList = ptrList->ptrPrev;
    }
}

template<class TIPO>
void List<TIPO>::Last(){
    while(ptrList && ptrList->ptrNext) { // mientras el nodo anterior exista
        ptrList = ptrList->ptrNext; // colocamos el nodo al encontrado
    }
}

int main() {
    List<int> list;
    list.Add(10);
    list.Add(20);
    list.Add(30);
    list.Add(40);
    //imprimir la lista
    list.print();
    list.First();
    cout << "First Node: " << list.CurrentValue() << endl;

    list.Last();
    cout << "Last Node: " << list.CurrentValue() << endl;
    cout << "Insert new nodes: 80,85"<<endl;
    list.Add(80);
    list.Add(85);
    //imprimir la lista
    list.print();
    list.First();
    cout << "First Node: " << list.CurrentValue() << endl;

    list.Last();
    cout << "Last Node: " << list.CurrentValue() << endl;
    cout << "remove Node: 40"<<endl;
    list.remove(40);
    list.print();

    return 1;
}
// :)
