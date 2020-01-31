#include <iostream>

using namespace std;

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

				break;
			case 3: 
				break;

		}	
	}
}

