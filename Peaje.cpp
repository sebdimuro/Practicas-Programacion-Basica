/*
Ejercicio: 

    Estás diseñando la lógica para una cabina de peaje automatizada en una autopista. 
    El sistema necesita calcular la tarifa que debe pagar cada vehículo que pasa 
    según sus características:

    Vehículos estándar:

    Motos: Pagan un valor fijo de 5 EUR/USD.

    Coches: Pagan 10 EUR/USD si viajan solas 1 o 2 personas, pero si van en viaje compartido 
    (3 o más personas), reciben un descuento y solo pagan 7 EUR/USD.

    Camiones: Pagan una tarifa base de 20 EUR/USD, más un adicional de 5 EUR/USD por cada eje que 
    tengan.

    Registro de paso:

    Cada vez que un vehículo paga y cruza la cabina, el sistema debe registrar el paso e 
    ir acumulando silenciosamente el total de dinero recaudado en esa cabina específica y 
    el número total de vehículos que han pasado desde que inició la jornada.

    Informativo final:

    Necesitas una forma de consultar en cualquier momento cuánto dinero hay en la caja de la cabina y 
    cuántos vehículos han transitado, sin necesidad de reiniciar la cuenta.
*/

#include <iostream>
using namespace std;

int calculartarifa(){

    return 5; // Devuelve el valor de 5EUR

}
int calculartarifa(int pasajeros){

    return (pasajeros >=3 ) ? 7 : 10; // Devuelve el valor de 7EUR, En caso de ser más de 2 pasajeros y 10 En caso de ser 1 o 2 pasajeros

}
int calculartarifa(double ejes, int tarifabase){

    int costo_total = tarifabase + (5*ejes); //Calcula la tarifa total del camión teniendo en cuenta los 20EUR iniciales + 5EUR Adicional por cada eje que tenga
    
    return costo_total; // Devuelve el costo total

}
void registro(int tarifa, int tipo){

    static int totaldinero = 0; // Contador estatico de dinero
    static int totalvehiculos = 0; // Contador estatico de vehiculos
    static int contadorMotos = 0; // Contador estatico de motos
    static int contadorCarros = 0; // Contador estatico de carros
    static int contadorCamiones = 0; // Contador estatico de camiones

    totaldinero += tarifa; // Suma las tarifas de todos los vehículos 

    if(tarifa > 0){
    totalvehiculos++; // Incrementa el contador de vehículos al tener una tarifa mayor de 0

    if(tipo == 1){
        // Incrementa el contador de motos al hacer el llamado a la funcion registro(tarifa,tipo)
        contadorMotos++;
        }
    else if(tipo == 2){
        // Incrementa el contador de carros al hacer el llamado a la funcion registro(tarifa,tipo)
         contadorCarros++;
        }
    else if(tipo == 3){
        // Incrementa el contador de camiones al hacer el llamado a la funcion registro(tarifa,tipo)
        contadorCamiones++;
        }
    
    cout << "\n>>> Vehiculo registrado exitosamente por $" << tarifa << " <<<" << endl; // Muestra la tarifa de cada registro de un vehículo indivualmente
    }
    
    else{
    // Muestra el reporte del día 
    cout << "\n-------------------------------------------" << endl;
    cout << "--- [REPORTES Y DESGLOSE DEL DIA] ---" << endl;
    cout << "Motos registradas: " << contadorMotos << endl;
    cout << "Carros registrados: " << contadorCarros << endl;
    cout << "Camiones registrados: " << contadorCamiones << endl;
    cout << "Total acumulado hoy: $" << totaldinero << endl;
    cout << "Total vehiculos procesados: " << totalvehiculos << endl;
    cout << "-------------------------------------------\n" << endl;
    }

}

int main(){

    int opcion;
    // Se hace llamado al menú en el int main
    do{
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~MENU - [PEAJE]~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~Ingrese El Tipo de Vehiculo~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"1. Registrar Moto"<<endl;
    cout<<"2. Registrar Carro"<<endl;
    cout<<"3. Registrar Camiones"<<endl;
    cout<<"4. Consultar Registro del Dia"<<endl;
    cout<<"5. Finalizar el programa"<<endl;
    cout<<"\nOpcion a Ingresar: "<<endl;
    cin>>opcion;

    
    // Se evalua un switch para hacer el registro respectivo del vehículo
    switch(opcion){
        case 1:{
            int tarifa = calculartarifa(); // Acumula la tarifa de la moto

            registro(tarifa,1); // Hace llamado al registro general con su tarifa y su tipo, en este caso 1 [Motos]

            cin.ignore();
            cin.get();

            system("CLS");

            
            break;
        }
        case 2:{
            int pasajeros;

            system("CLS");

            // Aquí se determina el numero de pasajeros con los que cuenta el vehículo y asi establecer el valor a cobrar

            cout<<"Ingrese el numero de pasajeros: ";
            cin>>pasajeros;

            int tarifa = calculartarifa(pasajeros); // Acumula la tarifa del carro

            registro(tarifa,2); // Hace llamado al registro general con su tarifa y su tipo, en este caso 2 [Vehículos]

            cin.ignore();
            cin.get();

            system("CLS");

            break;
        }
        case 3:{
            double ejes;


            system("CLS");

            // Aquí se determina el numeros de ejes que contiene el camion y así establecer el valor a cobrar del vehículo

            cout<<"Ingrese el numero de ejes que contiene el camion: ";
            cin>>ejes;

            int tarifa = calculartarifa(ejes,20); // Acumula la tarifa del carro

            registro(tarifa,3); // Hace llamado al registro general con su tarifa y su tipo, en este caso 3 [Camiones]

            cin.ignore();
            cin.get();

            system("CLS");

            break;
        }
        case 4:{
            // Hace llamado a la funcion registro y mostrar los reportes del día y su tipo, en este caso el reporte general [0]
            registro(0,0);

            cin.ignore();
            cin.get();

            system("CLS");
            break;
        }
        case 5:{
            system("CLS");

            cout << "\n-------------------------------------------" << endl;

            cout<<"\nGracias por usar el programa!"<<endl;
            cout<<"\nPresiona una tecla para salir!"<<endl;

            cout << "-------------------------------------------\n" << endl;

            cin.ignore();
            cin.get();

            break;
        }
    }
}while(opcion!=5);
    return 0;
}