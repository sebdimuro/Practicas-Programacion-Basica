/*
PARCIAL PRÁCTICO DE PROGRAMACIÓN – C++ (100 MINUTOS)Tema: Memoria Dinámica, Punteros, 
Aritmética de Punteros y Cadenas C-style (char*).
Instrucciones: Desarrolle el siguiente programa modular en C++ utilizando 
únicamente las librerías estándar <iostream> y <cctype>. 
Queda estrictamente prohibido el uso de la librería <string> o 
de la notación de corchetes [i] en las funciones que requieran aritmética de punteros.

Contexto del Problema: 

La oficina de registro académico requiere un sistema modular en C++ para procesar 
la información de un grupo de N estudiantes. De cada estudiante se debe procesar su nota final (valor entero de 0 a 100) 
y su código de registro asignado, 
el cual es una cadena de caracteres estilo C de máximo 100 caracteres (por ejemplo: "std-8492-act").

1. Función limpiarYContarCodigo
Diseñe una función con la siguiente firma:

C++
int limpiarYContarCodigo(char *codigo);
La función debe recibir el puntero al inicio de la cadena y recorrerla mediante un bucle while utilizando el carácter nulo ('\0') 
como condición de parada. Debe realizar las siguientes acciones en la misma dirección de memoria:

**Convertir todas las letras minúsculas a mayúsculas directamente en el arreglo original.

**Contar cuántos caracteres dentro del código corresponden a dígitos numéricos ('0' a '9') o al carácter guion ('-').

** Retorno: La función debe devolver la cantidad total de dígitos y guiones contabilizados.

2. Función evaluarEstudiantesDiseñe una función con la siguiente firma: 
C++
void evaluarEstudiantes(int *notas, int n, int *aprobados, int *reprobados, double *promedio);
La función debe procesar el arreglo dinámico de notas de tamaño N. 
Restricción obligatoria: El recorrido y acceso a los datos debe hacerse exclusivamente mediante aritmética de punteros 
(expresiones tipo *(notas + i)). 
No se permite el uso de corchetes.
Una nota se considera aprobada si es mayor o igual a 60; de lo contrario, se considera reprobada.
La función debe actualizar directamente en las direcciones de memoria recibidas la cantidad total de estudiantes aprobados 
(*aprobados) y reprobados (*reprobados).Debe calcular el promedio general de todas las notas del grupo y asignarlo a la 
variable apuntada por *promedio.

3. Función Principal (main)El flujo del programa principal debe ejecutar los siguientes pasos 
en orden estricto:Solicitar al usuario la cantidad N de estudiantes a registrar.
Reserva Dinámica: Reservar en el Heap un arreglo unidimensional de enteros de tamaño N para 
almacenar las notas finales. Mediante un ciclo, solicitar para cada estudiante:
Su nota final (almacenándola en el Heap usando aritmética de punteros).
Su código de registro, leyéndolo de forma segura mediante cin.getline (asegurando la gestión correcta del búfer de entrada).
Llamar inmediatamente a limpiarYContarCodigo para cada estudiante, imprimiendo en pantalla el código transformado a mayúsculas y 
el total de caracteres especiales/dígitos contados.
Una vez registrados todos los datos, invocar a la función evaluarEstudiantes pasando los argumentos por dirección (&).
Imprimir en consola el reporte general: total de aprobados, total de reprobados y el promedio del grupo.
Gestión de Memoria: Liberar la memoria dinámica reservada en el Heap usando el operador adecuado (delete[]) y 
anular el puntero asignándole nullptr.

Criterios de Evaluación:
Uso correcto de memoria dinámica (new / delete[] / nullptr): 25% 
Uso estricto de aritmética de punteros y pasaje de parámetros por dirección: 25% 
Manipulación correcta de cadenas estilo C (char*) y detección de '\0': 25% 
Control de búfer (cin.getline, cin.ignore) y modularidad limpia: 25%
*/

#include <iostream>
#include <cctype>
using namespace std;

int limpiarcodigo(char *codigo){

        int contador=0;

        while(*codigo != '\0'){

            if(islower(*codigo)){

            *codigo = toupper(*codigo);

            }
        

        if(*codigo == '0' || *codigo == '1' || *codigo == '2'  || *codigo == '3' || *codigo == '4' || *codigo == '5' || *codigo == '6' ||  *codigo == '7' ||  *codigo == '8' || *codigo == '9' || *codigo == '-' ){
            contador++;
            }
            codigo++;
        }

        return contador;
}

void evaluar(int* notas, int n, int *aprobados, int *reprobados, double* promedio){

    for(int i=0; i<n; i++){
        if(*(notas+i)>=60){
            (*aprobados)++;
        }
        else{
            (*reprobados)++;
        }
    }

        int notaactual; double sumatotal=0;

    for(int i=0; i<n; i++){

        notaactual = *(notas+i);

        sumatotal += notaactual;
    }
    *promedio = sumatotal / n;
    
}
void reporte(int *aprobados, int *reprobados, double *promedio){

    cout<<"\n~~~~~~~~~~~~~~REPORTE GENERAL - [ESTUDIANTIL]~~~~~~~~~~~~~~"<<endl;

    cout<<"\n**Estudiantes aprobados: "<<*aprobados<<endl;
    cout<<"\n**Estudiantes reprobados: "<<*reprobados<<endl;
    cout<<"\n**Promedio General del Curso: "<<*promedio<<endl;
}

int main(){

    int n; int aprobados=0; int reprobados=0; double promedio=0;

    cout<<"\n~~~~~~~~~~~~~~SISTEMA MODULAR - [REGISTRO ACADEMICO]~~~~~~~~~~~~~~"<<endl;

    cout<<"\n**Ingrese la cantidad de estudiantes: ";

    cin>>n;

    int *notas = new int[n]; 
    char codigo[100];

    for(int i=0; i<n; i++){

        cout<<"\n~~~~~~~~~~~~~~REGISTRO [NOTAS & CODIGO ESTUDIANTIL]~~~~~~~~~~~~~~"<<endl;
        cout<<"**RECUERDE QUE LA NOTA FINAL ES UN VALOR ENTERO ESTABLECIDO (0 A 100)"<<endl;
        cout<<"**RECUERDE QUE EL CODIGO ESTUDIANTIL ES ESTILO C DE MAXIMO 100 CARACTERES (EJEMPLO: std-8492-act)\n"<<endl;

        cout<<"**Ingrese la nota final del estudiante #"<<i+1<<":"<<endl;
        cin>>*(notas+i);

        cin.ignore();

        cout<<"**Ingrese el codigo del estudiante #"<<i+1<<":"<<endl;
        cin.getline(codigo,100);

        int caracteres = limpiarcodigo(codigo);

        cout<<"\nCodigo transformado a mayusculas: "<<codigo<<endl;

        cout<<"\nCantidades de caracteres numericos o diagonales: "<<caracteres<<endl;
    }
        evaluar(notas,n,&aprobados,&reprobados,&promedio);

        reporte(&aprobados,&reprobados,&promedio);

        delete[]notas;
        notas = nullptr;
    

    return 0;
}