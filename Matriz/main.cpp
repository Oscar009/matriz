/*
AUTOR: Oscar Noe Ortiz Barba
CURSO: Diseño y análisis de algoritmos
PROGRAMA: 
FECHA: 
*/

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include "matriz.h"

int getMaxOfTwo(matriz*, matriz*);

using namespace std;

int main() {
	srand((unsigned)time(nullptr));

	matriz A(2, 2);
	matriz B(2, 2);

	A.fillRandom();
	B.fillRandom();

	cout << "Matriz A:" << endl;
	A.printMatriz();
	cout << "Matriz B:" << endl;
	B.printMatriz();

	int m = getMaxOfTwo(&A, &B);

	A.reSize(m);
	B.reSize(m);
	matriz C(m, m);

	cout << "Matriz A:" << endl;
	A.printMatriz();
	cout << "Matriz B:" << endl;
	B.printMatriz();
	
	/*C.add(&A, &B);

	cout << "Suma:" << endl;
	C.printMatriz();

	C.sub(&A, &B);

	cout << "Resta:" << endl;
	C.printMatriz();

	C.mult(&A, &B);

	cout << "Multiplicacion:" << endl;
	C.printMatriz();
	*/
	return 0;
}

//obtiene el valor de dimension mas grande entre dos matrices
//compara el maximo obtenido con la potencia de 2 más cercana igual o mayor
int getMaxOfTwo(matriz* A , matriz* B) {
	int max = 0;
	int a[] = { A->getColumnsLength(), A->getRowsLength(), B->getColumnsLength(), B->getRowsLength() };

	for (int i = 0; i < 4; i++) {
		if (a[i] > max) max = a[i];
	}

	int i = 0;
	int maxPow = 0;
	while (maxPow < max) {
		maxPow = pow(2, i);
		i++;
	}

	return maxPow;
}