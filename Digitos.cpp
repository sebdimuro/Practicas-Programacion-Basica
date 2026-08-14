/*
Ejercicio: contar los digitos de un numero

Crea un programa en C++ que:

** Pida al usuario un numero entero positivo.
** Cree una funcion llamada contarDigitos.
** La funcion debe recibir el numero y devolver cuantos digitos tiene.
** Debes utilizar un ciclo (for o while).
** No puedes convertir el numero a string.
** Debes mostrar el resultado.

*/
#include <iostream>
using namespace std;

void contardigitos(int N);

int main(){
	int N;
	
	cout<<"Programa: [Contar-Digitos]"<<endl;
	cout<<"Ingrese un numero entero positivo: "<<endl;
	cin>>N;
	
	contardigitos(N);
	
	return 0;
}

void contardigitos(int N){
		
		int contador=0;
		do{
			
			N = N/10;
			contador++;
			
		}while(N>0);
		
	if(contador==1){
			cout<<"El numero ingresado tiene "<<contador<<" Digito"<<endl;
		}
	else{
		cout<<"El numero ingresado tiene "<<contador<<" Digitos"<<endl;
	}
}
