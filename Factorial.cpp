/*
Crea un programa en C++ que:

** Le pida al usuario un número entero.
** Cree una función llamada factorial que reciba ese número.
** La función debe calcular el factorial sin utilizar ninguna función predeterminada.
** Debes utilizar un ciclo (for o while) para realizar las multiplicaciones.
** El resultado debe mostrarse en pantalla.
*/
#include <iostream>
using namespace std;
int factorial(int n);
int main(){
	
	int n; 
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"Calculadora [Factorial]"<<endl;
	cout<<"\nDigite un numero entero: "<<endl;
	cin>>n;
	
	cout<<"\nEl factorial de "<<n<<" es: "<<factorial(n)<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	return 0;
}
int factorial(int n){
		
		int factor=1;
			
			for(int i=1; i<n; n--){
				
				factor = factor * n;
			}
		return factor;
}
