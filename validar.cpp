#include <stdlib.h>
#include<iostream>
using namespace std;

int validar ();

int main(){
    double base=0,altura=0;
    cout<<"Ingrese un numero: ";
    base= validar();
    cout<< "numero:"<<base;
    system("pause");
    return 0;
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
