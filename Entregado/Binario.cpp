/*NOMBRE:FARFAN DE LEON JOSE OSVALDO
  CODIGO: 214796622
  SECCION:"D07"
---------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int *ptr1=NULL;
void binario(int*);
int *a=(int*)malloc(sizeof(int));

int main(int argc, char** argv) {
    system("cls");
    cout<<"ingrese numero 1"<<endl;
    cin>>*a;
    ptr1=&*a;
    binario(ptr1);
    return 0;
}

void binario(int *a){
    int x=0;
    string cadena="", aux="";
    while(*a>0){
            if(*a%2==0){
                cadena="0"+cadena;
            }
            else{
                cadena = "1"+cadena;
            }
            *a = (int) *a/2;
    }
    x=cadena.size();
    while(x%4 != 0){
            if(x%4 != 0){
                aux="0"+aux;
                x++;
            }
    }
    cout<<aux<<cadena;
}
