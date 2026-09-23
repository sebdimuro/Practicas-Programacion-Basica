/*
Ejercicio Práctico: Contador de Consonantes (Estilo C)

Enunciado:

**Escribe un programa que solicite al usuario una frase utilizando arreglos de caracteres tradicionales de C (char[]). 
**El programa debe recorrer la frase y contar únicamente las consonantes que contiene, ignorando por completo las vocales, 
**los espacios en blanco y los números o símbolos si los hubiera. 

Al final, debe mostrar el total de consonantes encontradas.

Herramientas y conceptos que debes usar:

Un arreglo de tipo char para almacenar la frase y cin.getline() para capturarla con espacios.

La librería <cstring> y su función strlen() para controlar el tamaño del ciclo de recorrido.

Un ciclo for para examinar la cadena carácter por carácter (cadena[i]).

Estructuras condicionales (if / else) combinadas con operadores lógicos (&&, ||) para filtrar qué letras son consonantes y cuáles no.

(Opcional) La librería <cctype> y la función tolower() si quieres facilitarte la comparación de letras mayúsculas y minúsculas.
*/
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void consonantes(char frase[]){

    int longitud = strlen(frase);

    int contador = 0;

    for(int i=0; i<longitud; i++){

        if( frase[i] == 'B' || frase[i] == 'C' || frase[i] == 'D' || 
            frase[i] == 'F' || frase[i] == 'G' || frase[i] == 'H' || 
            frase[i] == 'J' || frase[i] == 'K' || frase[i] == 'L' ||
            frase[i] == 'M' || frase[i] == 'N' || frase[i] == 'P' ||
            frase[i] == 'Q' || frase[i] == 'R' || frase[i] == 'S' ||
            frase[i] == 'T' || frase[i] == 'V' || frase[i] == 'W' ||
            frase[i] == 'X' || frase[i] == 'Y' || frase[i] == 'Z' ){
                contador++;
        }

        else if(frase[i] == 'b' || frase[i] == 'c' || frase[i] == 'd' || 
            frase[i] == 'f' || frase[i] == 'g' || frase[i] == 'h' || 
            frase[i] == 'j' || frase[i] == 'k' || frase[i] == 'l' ||
            frase[i] == 'm' || frase[i] == 'n' || frase[i] == 'p' ||
            frase[i] == 'q' || frase[i] == 'r' || frase[i] == 's' ||
            frase[i] == 't' || frase[i] == 'v' || frase[i] == 'w' ||
            frase[i] == 'x' || frase[i] == 'y' || frase[i] == 'z'){
                contador++;
            }
    }
    cout<<"El numero de consonantes que tiene la frase es: ";
    cout<<contador<<endl;
}
int main(){


    char frase[50];

    cout<<"~~~~~~~~[CONTADOR DE CONSONANTES]~~~~~~~~\n";

    cout<<"Ingrese su frase: ";

    cin.getline(frase,50);

    consonantes(frase);


    return 0;
}