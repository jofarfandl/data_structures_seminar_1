/* Farfan de Leon Jose Osvaldo
   Codigo: 214796622
--------------------------------------------------------------------------------------------------------------------------------------*/
#include <bits/stdc++.h>
#include <windows.h>
#include <iostream>
#include <cstdlib>
using namespace std;

struct nodo{//estructi¿ura del nodo
     int key;
     string nom,dir,email;//esto lo quitas
     struct nodo *left, *right;
};
typedef struct nodo *root;

root crearNodo(int x,string nom,string dir,string email){//solo pasas como parametro x que sera key (acomodo del arbol)
     root nuevoNodo = new(struct nodo);
     nuevoNodo->key = x;
     nuevoNodo->nom = nom;
     nuevoNodo->dir = dir;
     nuevoNodo->email = email;
     nuevoNodo->left = NULL;
     nuevoNodo->right = NULL;
     return nuevoNodo;
}

void insertar(root &arbol, int x,string nom,string dir,string email){//quitar string solo dejar x que seria la key del arbol
     if(arbol==NULL)
     {
           arbol = crearNodo(x,nom,dir,email);
     }
     else if(x < arbol->key)
          insertar(arbol->left, x,nom,dir,email);
     else if(x > arbol->key)
          insertar(arbol->right, x,nom,dir,email);
}

///diferentes formas de imprimir el arbol
void Enorder(struct nodo* root){
    if (root != NULL) {
        Enorder(root->left);
        cout <<" "<< root->key;
        Enorder(root->right);
    }
}

void preOrden(nodo* root){
     if(root!=NULL){
          cout << root->key <<" ";
          preOrden(root->left);
          preOrden(root->right);
     }
}

void postOrden(nodo* root){
     if(root!=NULL){
          postOrden(root->left);
          postOrden(root->right);
          cout <<root->key<< " ";
     }
}
//******************************************************


bool modificar(struct nodo* root,int key){
        if (root == NULL)
            return false;
        if (root->key == key){
            char opc;
            string cad;
            struct nodo* aux1 = root;

            cout<<"1-.Cambiar Nombre"<<endl;
            cout<<"2-.Cambiar Direccion"<<endl;
            cout<<"3-.Cambiar Email"<<endl;
            cout<<"0-.Salir"<<endl;
            cin.sync();
            cin>>opc;
            switch(opc){
                case '1':{
                    getline(cin,cad);
                    cout<<"Ingresa el nuevo nombre"<<endl;
                    getline(cin,cad);
                    aux1->nom=cad;
                    system("cls");
                break;
                }
                case '2':{
                    getline(cin,cad);
                    cout<<"Ingresa el nueva direccion"<<endl;
                    getline(cin,cad);
                    aux1->dir=cad;
                    system("cls");
                break;
                }
                case '3':{
                    getline(cin,cad);
                    cout<<"Ingresa el nuevo email"<<endl;
                    getline(cin,cad);
                    aux1->email=cad;
                    system("cls");
                break;
                }
               }
               system("cls");
            cout<<"Informacion Actualizada correctamente"<<endl;
            return true;}
        bool res1 = modificar(root->left, key);
        if(res1) return true;
        bool res2 = modificar(root->right, key);
        return res2;

}

struct nodo* minValueNode(struct nodo* root){//lo utiliza eliminar
    struct nodo* current = root;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct nodo* eliminarNodo(struct nodo* root, int key){
    if (root == NULL)
        return root;
    if (key < root->key)
        root->left = eliminarNodo(root->left, key);
    else if (key > root->key)
        root->right = eliminarNodo(root->right, key);
    else {
        if (root->left == NULL) {
            struct nodo* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct nodo* temp = root->left;
            free(root);
            return temp;
        }

        struct nodo* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = eliminarNodo(root->right, temp->key);
    }
    return root;
}

bool buscar(struct nodo* root, int key){
    if (root == NULL)
        return false;
    if (root->key == key){
        cout << "ID: "<<root->key<<endl;
        cout << "Nombre: "<<root->nom<<endl;
        cout << "Direccion: "<<root->dir<<endl;
        cout << "Correo: "<<root->email<<endl;
        return true;}
    bool res1 = buscar(root->left, key);
    if(res1) return true;
    bool res2 = buscar(root->right, key);
    return res2;
}

bool vacia(struct nodo* root){
    if (root == NULL){
        return true;
    }
    else{
        return false;
    }
}

void anular(nodo* root){
    if (root == NULL)return;

    anular(root->left);
    anular(root->right);
    delete root;
}

void imprimir(nodo* root, int n){
     if(root==NULL)
          return;
     imprimir(root->right, n+1);
     for(int i=0; i<n; i++)
         cout<<"   ";
     cout<< root->key <<endl;
    imprimir(root->left, n+1);
}



void menu(){
    cout<<"ARBOLES"<<endl;
     cout<<"1.-Crear nuevos nodos"<<endl;
     cout<<"2.-Ordenar en PreOrden"<<endl;
     cout<<"3.-Ordenar en InOrden"<<endl;
     cout<<"4.-Ordenar en PostOrden"<<endl;
     cout<<"5.-Buscar nodo por ID"<<endl;
     cout<<"6.-Modificar datos de un nodo"<<endl;
     cout<<"7.-Eliminar nodo"<<endl;
     cout<<"8.-Mostrar todo el arbol"<<endl;
     cout<<"0.-Salir"<<endl;
     cout<<"Ingrese la opcion que desee...";
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

int main(){
    struct nodo* root = NULL;
    root=NULL;
    string nom,dir,email;
    int x,y;
    int op, op2;
    do{
          system("cls");
          menu();
          cin>>op;
          switch(op){
               case 1:{
                    cout << "Ingrese numero de nodos: ";
                    y=validar();
                    for(int i=0; i<y; i++){
                    cout << "Ingrese el ID: ";
                    x=validar();
                    cout << "Ingrese nombre: ";
                    cin>> nom;
                    cout << "Ingrese direccion: ";
                    cin>> dir;
                    cout << "Ingrese email: ";
                    cin>> email;
                    cout<<""<<endl;
                    insertar(root,x,nom,dir,email);}
                    system("cls");
                    system("cls");
                    break;}
               case 2:
                    preOrden(root);
                    system("pause>>cls");
                    break;
               case 3:
                    Enorder(root);
                    system("pause>>cls");
                    break;
               case 4:
                    postOrden(root);
                    system("pause>>cls");
                    break;
               case 5:
                    cout << " Ingrese valor : ";
                    x=validar();
                    if (buscar(root, x)){
                        }
                    else
                        cout << "NO existe";
                    system("pause>>cls");
                    break;
               case 6:
                    cout << " Ingrese id: ";
                    x=validar();
                    modificar(root,x);
                    system("pause>>cls");
                    break;
               case 7:
                    cout<<" ID a eliminar: ";
                    x=validar();
                    root = eliminarNodo(root,x);
                    cout << "\n\tEliminado..!";
                    system("pause>>cls");
                    break;
               case 8:
                    imprimir(root,0);
                    system("pause>>cls");
                    break;
               case 0:
                    cout<<"Fin del Programa..."<<endl;
                    exit(0);
               default:
                cout<<"ERROR... DATO INVALIDO"<<endl;
          }
    }while(op!=0);
    return 0;
}
