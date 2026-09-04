/*
Imagina que necesitas una función llamada procesarNotas que reciba tres notas de un estudiante (por valor) y 
calcule dos resultados:

El promedio de las tres notas.

La nota más alta (el máximo).

Tu misión:
Diseña la función void procesarNotas(double n1, double n2, double n3, double &promedio, double &maxima)

n1, n2, n3 entran por valor (solo para ser leídos).

promedio y maxima entran por referencia (&) para que la función escriba los resultados en ellas.

En el main(), declara las variables para las notas y las variables promedio y maxima sin inicializar (o en 0).

Llama a la función e imprime los resultados en el main().
*/

#include <iostream>
using namespace std;

void procesarnotas(double n1, double n2, double n3, double &p, double &m){

    //1. Calculamos el promedio 

    p = (n1 + n2 + n3)/3;

    //2. Calculamos el valor maximo sin usar librerias

    if(n1 > n2 && n1 > n3){
        m = n1;
        cout<<"La nota maxima es: "<<m<<endl;
    }
    else if(n2 > n1 && n2 > n3){
        m = n2;
        cout<<"La nota maxima es: "<<m<<endl;
    }
    else if(n3 > n1 && n3 > n2 ){
        m = n3;
        cout<<"La nota maxima es: "<<m<<endl;
    }

    cout<<"El promedio de las tres notas es: "<<p<<endl;

    
}
int main(){

    //Declaramos variables

    double n1, n2, n3;

    double promedio, maxima;

    cout<<"Digite la primera nota: ";
    cin>>n1;

    cout<<"Digite la segunda nota: ";
    cin>>n2;

    cout<<"Digite la tercera nota: ";
    cin>>n3;

    //Hacemos llamado a la función
    
    procesarnotas(n1,n2,n3,promedio,maxima);

    return 0;
}