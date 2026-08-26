#include <iostream>
using namespace std;

//Uso plantillas de funciones para simplificar código

template <typename T>
void comparar(T a, T b){
	if(a==b){
		cout<<"Los dos numeros son iguales"<<endl;
	}
	else{
		cout << ((a > b) ? "El primer numero es mayor " : "El segundo numero es mayor ")<<"\n";
		cout << ((a>b) ? a : b)<<endl;
	}
}

int main(){

	double a,b;

	cout<<"Ingrese su primer numero:  ";
	cin>>a;
	cout<<"Ingrese su segundo numero:  ";
	cin>>b;

	comparar(a,b);
	
	return 0;
}
