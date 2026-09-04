/*
El intercambio de valores (Swap).

El problema:
Tienes dos variables en tu main: int a = 10; e int b = 20;.
Queremos crear una función que intercambie sus valores para que 
a valga 20 y b valga 10.

Tu misión (Paso 1):
Intenta hacer una función void intercambiar(int a, int b) usando paso por referencia (&).

Llámala desde el main e imprime a y b antes y después de llamar a la función para verificar 
que los valores se hayan cruzado.
*/
#include <iostream>

//Usamos en este caso &x y &y como nuestro alias para nuestro variables originales a y b

void intercambiar(int *x, int *y){

    //Asignamos el alias/mote a la variable original 
    // y accedemos a su dirección de memoria modificando su valor

    int temp = *x; 
    *x = *y;
    *y = temp;
}
using namespace std;
int main(){

    int a = 10; int b = 20;

    cout<<"Valor Original de a: "<<a<<endl; //Muestra al usuario el valor original de a

    cout<<"Valor Original de b: "<<b<<endl; //Muestra al usuario el valor original de b

    intercambiar(&a,&b);

    cout<<"Valor Modificado de a: "<<a<<endl; //Muestra al usuario el valor modificado de a

    cout<<"Valor Modificado de b: "<<b<<endl; //Muestra al usuario el valor modificado de b


    return 0;
}