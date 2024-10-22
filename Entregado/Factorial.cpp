/*Nombre:Farfan de Leon Jose Osvaldo
  codigo:214796622
  SEDA1 11AM
-------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int factorial(int*numero){
    int *aux=numero;
    for(int u=*numero-1;u>0; u--)
        *aux=*aux*(u);
    return *aux;
}
int main(int argc, char *argv[]){
    int numero=0, *ptr;
    cout<<"ingrese un numero para sacar el factorial"<<endl;
    cin>>numero;
    ptr=&numero;
    cout<<"Resultado:"<<factorial(ptr)<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
