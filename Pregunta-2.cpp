#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;

// Esta es nuestra "rueda" o lista de letras disponibles (incluye espacio, mayúsculas y minúsculas).
char codificacionDecodificacion[] = {
        ' ','A','E','I','O','U','a','e','i','o','u',
        'B','C','D','F','G','H','J','K','L','M','N','P','Q','R','S','T','V','W','X','Y','Z',
        'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'
};

    // Le decimos al programa cuántas casillas/letras hay en total en nuestra lista (53 casillas).
    const int TAM = 53;

    // Esta función busca en qué casilla (número de posición) está una letra específica.
    int buscarIndice(char c, char* code) {
    char* p = code; // Apuntamos al inicio de nuestra lista de letras.
    
    // Recorremos la lista letra por letra de izquierda a derecha.
    for (int i = 0; i < TAM; i++) {
        // Si la letra de la lista es igual a la letra que estoy buscando, devuelvo su número de casilla.
        if (*(p + i) == c) return i; 
    }
    return -1; // Si no encuentra la letra en la lista, devuelve -1 (no existe).
}

// Función para transformar la palabra normal en una palabra secreta (Cifrar)
void cifrarMensaje(char* m, int desplazamiento, char* code) {

    char* p = m; // Apuntamos a la primera letra de la palabra que escribió el usuario.
    
    // Mientras no hayamos llegado al final del texto (el símbolo '\0' marca donde termina una palabra)
    while (*p != '\0') {
        
        // 1. Averiguamos en qué casilla de la lista está la letra actual.
        int idx = buscarIndice(*p, code); 
        
        // Si la letra existe en nuestra lista:
        if (idx != -1) {
            // 2. Le sumamos el salto fijo para encontrar la nueva letra. 
            // El '%' evita que nos salgamos del límite (si pasa de 53, vuelve a empezar desde el 0).
            int nuevoIdx = (idx + desplazamiento) % TAM; 
            
            // Si por alguna razón da un número negativo, le damos una vuelta completa sumando 53.
            if (nuevoIdx < 0) nuevoIdx += TAM; 
            
            // 3. Reemplazamos la letra original por la nueva letra encubierta.
            *p = *(code + nuevoIdx); 
        }
        p++; // Pasamos a la siguiente letra de la palabra.
    }
    // Mostramos la palabra ya transformada en pantalla.
    cout << "Mensaje cifrado: " << m << endl; 

}

// Función para devolver la palabra secreta a su estado original (Descifrar)
void descifrarMensaje(char* m, int desplazamiento, char* code) {

    char* p = m; // Apuntamos a la primera letra del texto cifrado.
    
    // Recorremos letra por letra hasta el final del texto.
    while (*p != '\0') {
        
        // 1. Buscamos la posición de la letra cifrada.
        int idx = buscarIndice(*p, code); 
        
        if (idx != -1) {
            // 2. En lugar de sumar, RESTAMOS el mismo salto para regresar a la letra original.
            int nuevoIdx = (idx - desplazamiento) % TAM; 
            
            // Si al restar nos da un número negativo, le sumamos 53 para dar la vuelta hacia el final de la lista.
            if (nuevoIdx < 0) nuevoIdx += TAM; 
            
            // 3. Reemplazamos la letra secreta por la letra original recuperada.
            *p = *(code + nuevoIdx); 
        }
        p++; // Pasamos a la siguiente letra.
    }
    // Mostramos en pantalla el mensaje recuperado.
    cout << "Mensaje descifrado: " << m << endl; 

}

int main() {
    char mensaje[100]; // Espacio guardado para la palabra que escriba el usuario (máximo 100 letras).
    int d = 0;          // Variable para guardar el número de casillas que saltaremos.

    // Pedimos al usuario la palabra y el número de salto.
    cout << "Digite mensaje a cifrar: ";
    cin >> mensaje; 
    cout << "Digite desplazamiento: ";
    cin >> d; 

    // Llamamos a la función para encubrir la palabra.
    cifrarMensaje(mensaje, d, codificacionDecodificacion);

    // Pedimos la palabra cifrada para hacer el proceso inverso.
    cout << endl << "Digite mensaje descifrar: ";
    cin >> mensaje; 

    // Llamamos a la función para regresar la palabra a su estado original.
    descifrarMensaje(mensaje, d, codificacionDecodificacion);

    return 0;
}

