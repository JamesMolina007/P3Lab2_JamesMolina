#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void imprimir(int* arreglo, int tamano){
	cout << endl;
	for( int i = 0; i < tamano; i++){
		cout << "[" << arreglo[i] << "]";
	}
	cout << endl;
}

void orden(int* arreglo, int tamano ){
	int menor;
	int aux, pos, inicio = 0;
	for ( int i = 0; i < tamano - 1; i++ ){
		menor = 100;
		for( int j = inicio; j < tamano; j++){
			if( arreglo[j] < menor ){
			       	menor = arreglo[j];
				pos = j;	
			}
		}
		if( menor < arreglo[i] ){
			aux = arreglo[i];
			arreglo[i] = menor;
			arreglo[pos] = aux;
			inicio++;
		}
		cout << endl  <<"PASO "<< i+1 << ":" <<  endl;
		imprimir( arreglo, tamano );
	}
}

int* llenar(int tamano){
	int* arreglo = new int[tamano];
	int numero;			
    	srand( time( NULL ) );
    	for(int i  = 0; i < tamano; i++){
        	numero = 0 + rand() % ( 99 );
        	cout<< "[" << numero << "]";
		arreglo[i] = numero;
    	}
	imprimir(arreglo, tamano);
	cout << endl << endl;
	return arreglo;
}

void arreglo(){
	int tamano;
	cout << "Ingrese el tamaño del arreglo: ";
	cin >> tamano;
	int* arreglo = llenar( tamano );
	orden( arreglo, tamano );
}

int calculoMCD( int num1, int num2 ){
	int residuo;
	cout << "mcd(" << num1 << "," << num2 << ")" << endl;
	residuo =  num1 % num2;
	num1 = num2;
	num2 = residuo;
	if( num2 == 0 ){
		cout << "mcd(" << num1 << "," << num2 << ")" << endl;	       
		return num1;
	}
	else calculoMCD( num1, num2 );
}

void MCD(){
	int numero1,numero2;
	cout << "Ingrese numero 1: ";
	cin >>  numero1;
	cout << "Ingrese numero 2: ";
	cin >> numero2;
	int mcd = calculoMCD( numero1, numero2 );
	cout << "El maximo comun divisor es: \n" << "mcd(" << numero1 << "," << numero2 << ") = " << mcd  << endl; 
}

int main(){
	int opcion;
	while(opcion){
		cout << endl << endl;
		cout << "0- Salir" << endl;
		cout << "1- Algoritmo de Euclides" << endl;
		cout << "2- Ordenar Arreglo" << endl;
		cout << "3- Constante de Kaprekar" << endl;
		cout << "Ingrese la opcion: ";
		cin >>  opcion;
		cout << endl << endl;
		switch( opcion ){
			case 1:
				MCD();
				break;
			case 2:
				arreglo();
				break;
			case 3: 
				break;

		}	
	}
}

