#include <iostream>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <cstdlib>

using namespace std;

int *ptr1=NULL,*ptr2=NULL;

int * suma(int*,int*);
int * resta(int*,int*);
int * multiplicacion(int*,int*);
int * division(int*,int*);
int * potencia(int*, int*);
int * factorial(int *);
int * decimal_bin(int *);
int * binario_dec(int *);
int * decimal_oct(int *);
int * octal_dec(int *);
int * hexadecimal_dec(char hex[]);
int a=0,b=0;

int *validar();

int main(int argc, char** argv){
    int opc=0;
    do{
        system("cls");
        cout<<"Menu"<<endl;
        cout<<"1)Suma.\n2)Resta.\n3)Multiplicacion.\n4)Division.\n5)Potencia.\n6)Factorial.\n7)Decimal-Binario.\n8)Binario-Decimal.\n9)Decimal-Octal.\n10)Octal-Decimal.\n11)Decimal-Hexadecimal.\n12)Hexadecimal-Decimal."<<endl;
        cout<<"0 PARA SALIR."<<endl;
        cout<<"Ingrese una opcion valide:";
        cin >>opc;
        if(opc==1 || opc==2 || opc==3 || opc==4 || opc==5){
            a= *validar();
            b= *validar();
            ptr1=&a;
            ptr2=&b;
            switch(opc){
                case 1: cout<<"El resultado de la suma es: "<< *suma(ptr1,ptr2)<<endl;break;
                case 2: cout<<"El resultado de la resta es: "<< *resta(ptr1,ptr2)<<endl;break;
                case 3: cout<<"El resultado de la multiplicacion es: "<< *multiplicacion(ptr1,ptr2)<<endl;break;
                case 4: cout<<"El resultado de la division es: "<< *division(ptr1,ptr2)<<endl;break;
                case 5: cout<<"El resultado de la potencia es: "<< *potencia(ptr1,ptr2)<<endl;break;
            }
        }else{
            if(opc==6 || opc==7 || opc==8 || opc==9 || opc==10 || opc==11){
                a= *validar();
                ptr1=&a;
                switch(opc){
                    case 6: cout<<"Resultado del factorial es: "<<*factorial(ptr1)<<endl;break;
                    case 7: *decimal_bin(ptr1);break;
                    case 8: cout<<"El numero decimal es: "<<*binario_dec(ptr1)<<endl;break;
                    case 9: cout<<"El numero octal es:"<<*decimal_oct(ptr1)<<endl;break;
                    case 10:cout<<"El numero decimal es:"<<*octal_dec(ptr1)<<endl;break;
                    case 11:cout<<"El numero hexadecimal es: "<< hex << a << endl;break;
                }
            }if(opc == 12){
                    char num[10];
                    int band=0;
                    do{
                        band=0;
                        cout << "Ingrese el numero en hexadecimal: " << endl;
                        cin>>num;
                        for(int i = 0; num[i]; i++){
                            num[i] = toupper(num[i]);
                            if(num[i]>= 65 && num[i]<=70 || num[i]>= 48 && num[i]<=57){
                            }else{
                                cout<<"ERROR...ALGUNA LETRA NO COINCIDE CON EL SISTEMA HEXADECIMAL "<<endl;
                                band=1;
                                break;
                            }
                        }
                    }while(band != 0);
                    cout<<num;
                    cout << "El numero decimal es: " << *hexadecimal_dec(num) << endl;
            }
        }
        system("pause");
    }while(opc != 0);
    return 0;
}

int *validar(){
    int x=0;
    int *r=(int*)malloc(sizeof(int));
    char str[10];
    do{
    cout<<"Ingrese el numero:";
    cin>>str;
    if(isdigit(str[0]))
    {
        *r = atoi (str);
        x=1;
    }else
        cout<<"ERROR... DATO INVALIDO"<<endl;
    }while(x==0);
    return r;
}

int * suma(int *a,int *b){
int *r=(int*)malloc(sizeof(int));
*r=*a+*b;
return r;
}

int * resta(int *a,int *b){
int *r=(int*)malloc(sizeof(int));
*r=*a-*b;
return r;
}

int * multiplicacion(int *a,int *b){
int *r=(int*)malloc(sizeof(int));
*r=(*a)*(*b);
return r;
}

int * division(int *a,int *b){
int *r=(int*)malloc(sizeof(int));
*r=(*a)/(*b);
return r;
}

int * potencia(int*a, int*b){
    int *r=(int*)malloc(sizeof(int));
    *r=1;
    for(int i=0; i<*b ; i++){
        *r =*r*(*a);
    }
    return r;
}
int * factorial(int *a){
    int *r=a;
    for(int u=*a-1 ; u>0 ; u--)
        *r=*r*(u);
    return r;
}

int *decimal_bin(int *a){
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
    cout<<"El numero en binario es: "<<aux<<cadena<<endl;
}

int * binario_dec(int *a){
    int *r=(int*)malloc(sizeof(int));
    int exp=0,digito;
    while(((int)(*a/10))!=0)
   {
           digito = (int)*a % 10;
           *r = *r + digito * pow(2.0,exp);
           exp++;
           *a=(int)(*a/10);
   }
   *r=*r + *a * pow(2.0,exp);
   return r;
}

int *decimal_oct(int *a){
    int *r=(int*)malloc(sizeof(int));
    int aux, i = 1;
    while( *a != 0 ) {
        aux = *a % 8;
        *a /= 8;
        *r += aux * i;
        i *= 10;
    }
    return r;
}

int *octal_dec(int *a){
    int *r=(int*)malloc(sizeof(int));
    int i = 0, rem;
    while (*a != 0)
    {
        rem = *a % 10;
        *a /= 10;
        *r += rem * pow(8, i);
        ++i;
    }
    return r;
}

int * hexadecimal_dec(char hex[]){
    int len = strlen(hex), base = 1;
    int *r=(int*)malloc(sizeof(int));
    for(int i = 0; hex[i]; i++){
      hex[i] = toupper(hex[i]);
    }
    for (int i=len-1; i>=0; i--)
    {
        if (hex[i]>='0' && hex[i]<='9')
        {
            *r += (hex[i] - 48)*base;
            base = base * 16;
        }
        else if (hex[i]>='A' && hex[i]<='F')
        {
            *r += (hex[i] - 55)*base;
            base = base*16;
        }
    }
    return r;
}


