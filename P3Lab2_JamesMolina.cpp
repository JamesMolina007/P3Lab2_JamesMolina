//James Molina
//2020-31-01

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int unidades, decenas, centenas, millares;

int menor( int numero ){
	int* arreglo = new int[4];
	int aux;
	arreglo[0] = unidades;
	arreglo[1] = decenas;
	arreglo[2] = centenas;
	arreglo[3] = millares;
	for( int i = 0; i < 4; i++){
		for( int j = 0; j < 3 ; j++){
			if( arreglo[j] > arreglo[j+1] ){
				aux = arreglo[j+1];
				arreglo[j+1] = arreglo[j];
				arreglo[j] = aux;		
			}
		}
	}
	return  arreglo[0]*1000+arreglo[1]*100+arreglo[2]*10+arreglo[3];
}

int mayor( int numero ){
	int* arreglo = new int[4];
        int aux;
        arreglo[0] = unidades;
        arreglo[1] = decenas;
        arreglo[2] = centenas;
        arreglo[3] = millares;
	for( int i = 0; i < 4; i++){
                for( int j = 0; j < 3 ; j++){
                        if( arreglo[j] < arreglo[j+1] ){
                                aux = arreglo[j+1];
                                arreglo[j+1] = arreglo[j];
           			arreglo[j] = aux;
			}
		}
	}
        return  arreglo[0]*1000+arreglo[1]*100+arreglo[2]*10+arreglo[3];

}

void numeros( int numero ){
        unidades = ( numero % 10 );
        decenas  = ( numero % 100 ) / 10;
        centenas = ( numero % 1000 ) / 100;
        millares = ( numero % 10000 ) / 1000;
}


void constante(int numero ){
	int paso = 1;
	while( numero != 6174 ){
		int max = mayor( numero );
		int min = menor( numero );
		cout << paso << ". "  << max << " - " << min << " = " << max-min << endl;
		paso++;
		numero = max - min;
		numeros( numero );		
	}
}


bool validar( int numero ){
	numeros( numero );
	if( unidades == decenas || unidades == centenas || unidades == millares ) return false;
	if( decenas == centenas || decenas == millares ) return false;
	if( centenas == millares ) return false;
}

void kaprekar(){
	int numero;
	bool valido = true;
	cout << endl << endl << "Ingrese un numero de 4 cifras distintas: ";
	cin >> numero;
	valido = validar( numero );
	if( numero < 1000 || numero > 9999 ) valido = false;
	if( valido ){
		constante( numero );
	}
	else cout << "Solo se permiten numeros de 4 cifras y que todos sean distintos" << endl;
		
}

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
	for ( int i = 0; i < tamano  ; i++ ){
		menor = 100;
		for( int j = inicio; j < tamano; j++){
			if( arreglo[j] < menor ){
			       	menor = arreglo[j];
				pos = j;	
			}
		}
		aux = arreglo[i];
		arreglo[i] = menor;
		arreglo[pos] = aux;
		inicio++;
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
			case 0: 
				cout << "Gracias Por Probrarme" << endl;
				break;
			case 1:
				MCD();
				break;
			case 2:
				arreglo();
				break;
			case 3: 
				kaprekar();
				break;

			default: 
				cout<< "Ingrese alguna opcion disponible" << endl;	
				break;
		}	
	}
}

