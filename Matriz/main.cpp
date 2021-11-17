/*
AUTOR: Oscar Noe Ortiz Barba
CURSO: Diseño y análisis de algoritmos
PROGRAMA: El algoritmo de Strassen
FECHA: 19/11/2021
*/

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include "matriz.h"

int getMax(int, int, int);

using namespace std;

int main() {
	srand((unsigned)time(nullptr));

	int a, b, c;
	cout << "Entrada: ";
	cin >> a >> b >> c;

	cout << "Salida:" << endl;

	matriz A(a, b, (a * c));
	matriz B(b, c, (a * c));

	A.fillRandom();
	B.fillRandom();

	cout << "Matriz A:" << endl;
	A.printMatriz(1);
	cout << "Matriz B:" << endl;
	B.printMatriz(1);

	int m = getMax(a, b, c);

	A.reSize(m);
	B.reSize(m);

	cout << "Redimensionamiento de A:" << endl;
	A.printMatriz(0);
	cout << "Redimensionamiento de B:" << endl;
	B.printMatriz(0);

	matriz C(a, c, 0);

	cout << "Suma:" << endl;
	C.suma(&A, &B);
	C.printMatriz(1);

	cout << "Resta:" << endl;
	C.resta(&A, &B);
	C.printMatriz(1);
	

	//cout << "Producto:" << endl;
	//C.multiplica(&A, &B);
	//C.printMatriz(1);

	return 0;
}

//obtiene el valor mayor en el arreglo
//compara el maximo obtenido con la potencia de 2 más cercana igual o mayor
int getMax(int a, int b, int c) {
	int max = 0;
	int v[] = {a, b, c};

	for (int i = 0; i < 3; i++) {
		if (v[i] > max) max = v[i];
	}

	int i = 0;
	int maxPow = 0;
	while (maxPow < max) {
		maxPow = (int)pow(2, i);
		i++;
	}

	return maxPow;
}