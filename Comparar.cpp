#include <iostream>
using namespace std;

void comparar(int a, int b){
	if(a>b){
		cout<<"El primer numero entero es mayor: "<<a<<endl;
	}
	else if(a<b){
		cout<<"El segundo numero entero es mayor: "<<b<<endl;
	}
	else{
		cout<<"Los dos numeros enteros son iguales"<<endl;
	}
}
void comparar(float x, float y){
	
	if(x>y){
		cout<<"El primer numero float es mayor: "<<x<<endl;
	}
	else if(x<y){
		cout<<"El segundo numero float es mayor: "<<y<<endl;
	}
	else{
		cout<<"Los dos numeros enteros son iguales"<<endl;
	}
}
void comparar(double z, double w){
	if(z>w){
		cout<<"El primer numero float es mayor: "<<z<<endl;
	}
	else if(z<w){
		cout<<"El segundo numero float es mayor: "<<w<<endl;
	}
	else{
		cout<<"Los dos numeros enteros son iguales"<<endl;
	}
}
int main(){
	int opcion;
	cout<<"1. Comparar dos enteros entre si"<<endl;
	cout<<"2. Comparar dos flotantes entre si"<<endl;
	cout<<"3. Comparar dos doubles entre si"<<endl;
	cin>>opcion;
	
	switch(opcion){
		case 1:{
		int a; int b;
	
		cout<<"Ingrese el primer numero entero: ";
		cin>>a;
		cout<<"Ingrese el segundo numero entero: ";
		cin>>b;
		
		comparar(a,b);
		
		break;
		}
		case 2:{
			
		float x; float y;
		
		cout<<"Ingrese el primer numero float: ";
		cin>>x;
		
		cout<<"Ingrese el segundo numero float: ";
		cin>>y;
		
		comparar(x,y);
		break;
		}
		case 3:{
		double z; double w;
		
		cout<<"Ingrese el primer numero double: ";
		cin>>z;
		
		cout<<"Ingrese el segundo numero double: ";
		cin>>w;
		
		comparar(z,w);
		break;
		}
	}
	
	return 0;
}
