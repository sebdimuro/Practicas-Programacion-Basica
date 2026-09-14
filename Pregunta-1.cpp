
/*Encontrar el mensaje cifrado, se tiene 2 vectores:
* vector char mensajeCifrado: contiene todas las letras del abecedario, minusculas como mayusculas
* vector int decodifcador: en la cual contiene las posiciones claves de las letras del mensaje a 
* decodificar, tienen un tamano de 19 numeros enteros
* se requiere por medio de apuntadores recorrer en el mensajeCifrado segun el numero del decodificador
* e imprimir el mensaje cifrado, preferible que lo haga con funciones.
* Valor 3 puntos, si utiliza funciones y da con el mensaje cifrado
* Valor 2 puntos, si no utiliza funciones y da con el mensaje
* Valor 0, si no da con el mensaje aunque use funciones
*/
#include<iostream>
#include<conio.h>
using namespace std;
    
    void mostrarmensaje(char* mensaje, int* decodificador, int cantidad){

        int posicion = 0; //Variable local que acumula los desplazamientos para seleccionar la letra correcta en el arreglo mensajeCifrado.

        int* codigo = decodificador; //Puntero que nos permite acceder al decodificador de manera local

        

        // Decodificador = Posición Inicial del Arreglo
        // Cantidad = 19, cantidad de los desplazamientos que hace el decodificador
        // Código = Puntero que nos permite acceder al decodificador de manera local, Evalua cada posición
        // Decodificador + Cantidad = Es el límite del arreglo, es lo que nos permite evaluar nuestro finitamente en este caso (19 desplazamientos)
        // Bucle While que nos permite evaluar el decodificador mediante los 19 desplazamientos 
        while(codigo < decodificador + cantidad ){
        
        //Se hace un acumulador con la variable posición sobre el código que arroja el decodificador así sumara la letra que quiera mostrar de cada posición
        posicion += *codigo;
        //Mostrara la letra que se evaluo en la pasada correspondiente
        cout<<*(mensaje+posicion);
        //Incrementa y pasa a la siguiente posición del arreglo
        ++codigo;
        }
    }

int main() {

    // Arreglo tipo Char que contiene vocales y consonantes mayúsculas y minúsculas por igual
    char mensajeCifrado[] = {
        ' ','A','E','I','O','U','a','e','i','o','u',
        'B','C','D','F','G','H','J','K','L','M','N','P','Q','R','S','T','V','W','X','Y','Z',
        'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'
    };
    // Arreglo tipo Entero que contiene valores enteros que indican los 19 valores de desplazamiento del vector apoyados en el Arreglo tipo Char
    int decodificador[] = { 2,17,-19,2,48,-44,35,-34,35,-42,2,44,1,-41,-6,2,4,40,5};

    //Seguir desde aqui el codigo a implementar
    
    char* mensaje = mensajeCifrado; // Declaración de punteros del Arreglo tipo Char (Redundantes)
    int* codigo = decodificador; // Declaración de punteros del Arreglo tipo Entero (Redundantes)

    cout<<"El mensaje cifrado es: ";

    mostrarmensaje(mensajeCifrado,decodificador,19); //Guarda la dirección de memoria del Mensaje Cifrado, El Decodificador y la posición fija de 19 

    // A su vez mostrará el mensaje cifrado: 'El Examen Esta Easy'

	return 0;
}