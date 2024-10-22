#include <cstdlib>
#include <iostream>
using namespace std;


int main(){
    int arreglo[5]={7, 8, 9, 4, 5};
    int arr[5];
    for (int i=0 ; i<=4 ; i++){
        arr[i]=arreglo[i];
    }
    for (int j=0 ; j<=4 ; j++){
        cout<<arr[j]<<" ";
    }
    return 0;
}

























/*
int validar ();

int main(){
    float n=0;
    cout<<"ingrese un numero"<<endl;
    return 0;
}

int burbuja(type_list *L){
    int aux;
    i=L->ultimo;
    while(i>0){
        j=0;
        while(j<i){
            if(datos[j] > datos[j+1]){
                aux=datos[j]
                datos[j]=datos[j+1];
                datos[j+1] = aux;
            }
            j++;
        }
        i++;
    }
}*/
