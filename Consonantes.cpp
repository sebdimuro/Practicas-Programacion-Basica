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
        char c = tolower(frase[i]);

        if( c == 'b' || c == 'c' || c == 'd' || c == 'f' || c == 'g' || 
            c == 'h' || c == 'j' || c == 'k' || c == 'l' || c == 'm' || 
            c == 'n' || c == 'p' || c == 'q' || c == 'r' || c == 's' || 
            c == 't' || c == 'v' || c == 'w' || c == 'x' || c == 'y' || 
            c == 'z'){
                contador++;
            }
    }
    cout<<"El numero de consonantes que tiene la frase es: ";
    cout<<contador;
}
int main(){


    char frase[50];

    cout<<"~~~~~~~~[CONTADOR DE CONSONANTES]~~~~~~~~\n";

    cout<<"Ingrese su frase: ";

    cin.getline(frase,50);

    consonantes(frase);


    return 0;
}