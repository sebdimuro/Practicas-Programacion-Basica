/*
    Ejercicio: Contar cuántos dígitos pares tiene un número

    Crea un programa en C++ que reciba un número entero positivo y 
    determine cuántos de sus dígitos son pares.

    Por ejemplo:

    583 → 1
    7294 → 2
    2468 → 4
    1357 → 0

    Condiciones
    ** Crea una función llamada contarpares.
    ** La función debe recibir el número.
    ** No puedes convertir el número a string.
    ** Utiliza un ciclo.
    ** Debe devolver o mostrar el resultado.
*/
#include <iostream>
using namespace std;
void digitospares(int n);
int main(){

    int N;

    cout<<"Ingrese un numero entero positivo:  ";
    cin>>N;

    digitospares(N);

    return 0;
}
void digitospares(int N){

    int digito=0; int digitospares=0;

    do{
        digito = N % 10; // Me da el dígito

        if(digito%2==0){

            digitospares++; //Aumentar el contador que cuenta los dígitos pares

        }

        N /= 10; // Salto a los dígitos restantes

    }while(N>0);

    if(digitospares==1){

    cout<<"Su Numero tiene "<<digitospares<<" Digito Par"<<endl;

    }

    else{

        cout<<"Su Numero tiene "<<digitospares<<" Digitos Pares"<<endl;

    }
}