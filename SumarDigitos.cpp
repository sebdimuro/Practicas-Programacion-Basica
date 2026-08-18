/*
Ejercicio: Suma de los dígitos

Crea un programa en C++ que reciba un número entero positivo y calcule la suma de todos sus dígitos.

Por ejemplo:
583 → 5 + 8 + 3 = 16
7294 → 7 + 2 + 9 + 4 = 22

Condiciones:
** Crea una función llamada sumardigitos.
** La función debe recibir el número.
** No puedes convertir el número a string.
** Utiliza un ciclo.
** Debe devolver o mostrar el resultado.
*/
#include <iostream>
using namespace std;

void sumardigitos(int n);

int main(){

    int n;

    cout<<"Ingrese un numero entero positivo:  ";
    cin>>n;

    sumardigitos(n);

    return 0;
}
void sumardigitos(int n){
     
    int suma=0; int digito=0;

     if(n<0){
        cout<<"Invalido! Ingrese un numero entero positivo"<<endl;
     }

     else{

       do{

          digito = n % 10;

          suma += digito;

          n /= 10;

       }while(n>0);
       

       cout<<"El resultado de la suma de los digitos del numero es: "<<suma<<endl;
     }
}