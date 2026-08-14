/*
Los estudiantes deben realizar la calculadora 
usando funciones de Sumar, Restar, Multiplicar y Dividir
** Deben validar la división
** Deben realizar un menu en el cual se pueda escoger la operación y una opción si quiero salir del programa o no
** Adicionar función de elevar a la potencia sin usar la función pow(x,y)
*/

#include <iostream>
using namespace std;

int sumar(int x, int y);

int restar(int x, int y);

int multiplicar(int x, int y);

void dividir(float z, float k);

void potenciacion(int x, int y);

int main(){

	int opcion; int x; 	int y; float z; float k;
	
	do{
		cout<<"\nMenu - [Calculadora]"<<endl;
		cout<<"1. Suma"<<endl;
		cout<<"2. Resta"<<endl;
		cout<<"3. Multiplicacion"<<endl;
		cout<<"4. Division"<<endl;
		cout<<"5. Potenciacion"<<endl;
		cout<<"6. Salir del Programa"<<endl;
		cout<<"\nOperacion a realizar:  "<<endl;
		cin>>opcion;
		
		switch(opcion){
			case 1:{
				system("CLS");
				cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
				cout<<"Digite el primer numero:"<<endl;
				cin>>x;
				cout<<"Digite el segundo numero:"<<endl;
				cin>>y;
				
				cout<<"El resultado de su suma es: "<<sumar(x,y)<<endl;
				break;
			}
			case 2:{
				system("CLS");
				cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
				cout<<"Digite el primer numero:"<<endl;
				cin>>x;
				cout<<"Digite el segundo numero:"<<endl;
				cin>>y;
				
				cout<<"El resultado de su resta es: "<<restar(x,y)<<endl;
				break;
			}
			case 3:{
				system("CLS");
				cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
				cout<<"Digite el primer numero:"<<endl;
				cin>>x;
				cout<<"Digite el segundo numero:"<<endl;
				cin>>y;
				
				cout<<"El resultado de su multiplicacion es: "<<multiplicar(x,y)<<endl;
				break;
			}
			case 4:{
				system("CLS");
				cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
				cout<<"Digite el primer numero:"<<endl;
				cin>>z;
				cout<<"Digite el segundo numero:"<<endl;
				cin>>k;
				
				dividir(z,k);
				
				break;
			}
			case 5:{
				cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
				cout<<"Digite la base: "<<endl;
				cin>>x;
				cout<<"Digite la potencia: "<<endl;
				cin>>y;
				
				potenciacion(x,y);
				
				break;
			}
			case 6:{
				cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
				cout<<"Gracias por usar el programa - [Calculadora], Vuelva Pronto!"<<endl;
				break;
			}
		}
	}while(opcion!=6);
	return 0;
}
int sumar(int x, int y){
	
	int suma = 0;
	
	suma=x+y;
	
	return suma;
}
int restar(int x, int y){
	
	int resta = 0;
	
	resta=x-y;
	
	return resta;
}
int multiplicar(int x, int y){
	
	int multiplicacion=0;
	
	multiplicacion=x*y;
	
	return multiplicacion;
}
void dividir(float z, float k){
	
	float division=0;
	
	if(k==0){
		cout<<"\nOperacion Invalida! Error"<<endl;
	}
	else{
		division=z/k;
		cout<<"El resultado de su division es: "<<division<<endl;
	}
}
void potenciacion(int x, int y){
	
	int potencia=1;
	
	for(int i=0; i<y; i++){
		potencia = potencia*x;
	}
	cout<<"El resultado de su potenciacion es: "<<potencia<<endl;
	
}
